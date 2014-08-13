#include "MySimulation.h"

MySimulation *ms;

namespace bpy = boost::python;


static void nearCallback(void *data, dGeomID o1, dGeomID o2) {
	if(ms)
	{
		ms->NearCallback(o1, o2);
	}
	
}

MyContactList::MyContactList(std::string n)
{
	name = n;
	contact = true;
	gCFM = 1e-10;
	gERP = 0.8;
	gMu = 0;

}

void MyContactList::SetERP(double e)
{
	gERP = e;
}
void MyContactList::SetCFM(double c)
{
	gCFM = c;
}
void MyContactList::SetMu(double m)
{
	gMu = m;
}
void MyContactList::SetContact(bool f)
{
	contact = f;
}

MySimulation::MySimulation(OgreRTCApplication *ec)
{
	EC = ec;
	mu = new coil::Mutex();
	smu = new coil::Mutex();
	dInitODE();
	world        = dWorldCreate();
	space        = dHashSpaceCreate(0);
	contactgroup = dJointGroupCreate(0);
	ground       = dCreatePlane(space,0,0,1,0);

	GRABITY = -9.8;
	dWorldSetGravity(world, 0, 0, GRABITY);
	CFM = 1e-5;
	dWorldSetCFM(world, CFM);
	ERP = 0.2;
	dWorldSetERP(world, ERP);

	FinishFlag = false;
	QuiqFlag = false;

	sTime = 0.01;

	scale_x = 1;
	scale_y = 1;
	scale_z = 1;

	ms = this;

	gCFM = 1e-10;
	gERP = 0.8;
	gMu = 0;

	SleepTime = 0;

	smu->lock();
}

int MySimulation::svc()
{
	
	while(!FinishFlag)
	{
		smu->lock();
		mu->lock();
		clock_t start,end;
		start = clock();

		if(EC->po->Exec)
		{
			EC->po->setFunc("Simloop");
			
		}

		

		dSpaceCollide(space,0,&nearCallback);
		if(!QuiqFlag)dWorldStep(world, sTime);
		else dWorldQuickStep(world, sTime);
		dJointGroupEmpty(contactgroup);
		for(int i=0;i < MyLinks.size();i++)
		{
			MyLinks[i]->UpdateBodyPosition();
		}

		end = clock();
		double time = (double)(end-start)/CLOCKS_PER_SEC;
		
		if(SleepTime > time*1000)
		{
			Sleep(SleepTime - (int)(time*1000.));
		}
		mu->unlock();
		smu->unlock();
	}

	dJointGroupEmpty (contactgroup);
    dJointGroupDestroy (contactgroup);
	dSpaceDestroy(space);
	dWorldDestroy(world);
	dCloseODE();

	

	return 0;
}

void MySimulation::startSim()
{
	smu->unlock();
}

void MySimulation::restartSim()
{
	mu->unlock();
}

void MySimulation::stopSim()
{
	smu->lock();
}

void MySimulation::finishSim()
{
	FinishFlag = true;
}


void MySimulation::SetGravity(double g)
{
	GRABITY = g;
	dWorldSetGravity(world, 0, 0, GRABITY);
}
void MySimulation::SetCFM(double c)
{
	CFM = c;
	dWorldSetCFM(world, CFM);
	
}
void MySimulation::SetERP(double e)
{
	ERP = e;
	dWorldSetERP(world, ERP);
}
void MySimulation::SetSamplingTime(double t)
{
	sTime = t;
}
void MySimulation::SetSleepTime(double t)
{
	SleepTime = t*1000;
}
void MySimulation::SetGroundCFM(double c)
{
	gCFM = c;
	
}
void MySimulation::SetGroundERP(double e)
{
	gERP = e;
	
}

void MySimulation::SetGroundMu(double m)
{
	gMu = m;
}
MyODEBody *MySimulation::SetSphere(const char *name, double m, double r)
{
	MyODEBody *ml = new MyODEBody(name, this);
	ml->filename = "ODESphere.mesh";
	mu->lock();
	dMass mass;
	ml->body  = dBodyCreate(world);
	dMassSetZero(&mass);
	dMassSetSphereTotal(&mass, m, r);
	dBodySetMass(ml->body,&mass);
	ml->geom = dCreateSphere(space,r);
	dGeomSetBody(ml->geom, ml->body);

	EC->CreateODEObj(ml);

	ml->rd = r;
	ml->m = m;
	ml->BodyType = 0;

	MyLinks.push_back(ml);

	mu->unlock();

	return ml;
}
MyODEBody *MySimulation::SetBox(const char *name, double m, double lx, double ly, double lz)
{
	MyODEBody *ml = new MyODEBody(name, this);
	ml->filename = "ODEBox.mesh";
	mu->lock();
	dMass mass;
	ml->body  = dBodyCreate(world);
	dMassSetZero(&mass);
	dMassSetBoxTotal(&mass, m, lx, ly, lz);
	dBodySetMass(ml->body,&mass);
	ml->geom = dCreateBox(space,lx, ly, lz);
	dGeomSetBody(ml->geom, ml->body);

	ml->lx = lx;
	ml->ly = ly;
	ml->lz = lz;
	ml->m = m;
	ml->BodyType = 1;

	EC->CreateODEObj(ml);

	MyLinks.push_back(ml);

	mu->unlock();


	return ml;
}
MyODEBody *MySimulation::SetSylinder(const char *name, double m, double l, double r)
{
	MyODEBody *ml = new MyODEBody(name, this);
	ml->filename = "ODESylinder.mesh";
	mu->lock();
	dMass mass;
	ml->body  = dBodyCreate(world);
	dMassSetZero(&mass);
	dMassSetCylinderTotal(&mass, m, 1, r, l);
	dBodySetMass(ml->body,&mass);
	ml->geom = dCreateCylinder(space,r, l);
	dGeomSetBody(ml->geom, ml->body);

	ml->rd = r;
	ml->lx = l;
	ml->m = m;
	ml->BodyType = 2;

	EC->CreateODEObj(ml);

	MyLinks.push_back(ml);

	mu->unlock();

	return ml;
}
MyODEBody *MySimulation::SetCapsule(const char *name, double m, double l, double r)
{
	MyODEBody *ml = new MyODEBody(name, this);
	ml->filename = "ODESylinder.mesh";
	mu->lock();
	dMass mass;
	ml->body  = dBodyCreate(world);
	dMassSetZero(&mass);
	dMassSetCapsuleTotal(&mass, m, 1, r, l);
	dBodySetMass(ml->body,&mass);
	ml->geom = dCreateCapsule(space,r, l);
	dGeomSetBody(ml->geom, ml->body);

	ml->rd = r;
	ml->lx = l;
	ml->m = m;
	ml->BodyType = 3;

	EC->CreateODEObj(ml);

	MyLinks.push_back(ml);

	mu->unlock();

	return ml;
}
void MySimulation::SetSliderJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2, double ax, double ay, double az)
{

	ml->joint = dJointCreateSlider( world, 0 );
	if(b1 && b2)
	{
		dJointAttach( ml->joint, b1->body, b2->body );
		ml->b1 = b1->name;
		ml->b2 = b2->name;
	}
	else if(b1)
	{
		dJointAttach( ml->joint, b1->body, 0 );
		ml->b1 = b1->name;
		ml->b2 = "Ground";
	}
	else
	{
		dJointAttach( ml->joint, b2->body, 0 );
		ml->b1 = "Ground";
		ml->b2 = b2->name;
	}
	dJointSetSliderAxis( ml->joint, ax, ay, az );
	EC->CreateODEObj(ml);
	ml->SetVisible(false);

	ml->JointType = 0;
	ml->axisx = ax;
	ml->axisy = ay;
	ml->axisz = az;
	

	MyJoints.push_back(ml);
}
MyODEJoint *MySimulation::SetSliderJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double ax, double ay, double az)
{
	if(b1 == b2)
	{
		return NULL;
	}
	MyODEJoint *ml = new MyODEJoint(name, this);
	ml->filename = "cube.mesh";
	mu->lock();
	

	SetSliderJoint(ml, b1, b2, ax, ay, az);

	mu->unlock();
	return ml;
}
MyODEJoint *MySimulation::SetSliderJoint(const char *name, MyODEBody *b1, double ax, double ay, double az)
{
	
	MyODEJoint *ml = new MyODEJoint(name, this);
	ml->filename = "cube.mesh";
	mu->lock();

	SetSliderJoint(ml, b1, NULL, ax, ay, az);

	mu->unlock();

	return ml;
}

void MySimulation::SetFixJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2)
{

	ml->joint = dJointCreateFixed( world, 0 );
	if(b1 && b2)
	{
		dJointAttach( ml->joint, b1->body, b2->body );
		ml->b1 = b1->name;
		ml->b2 = b2->name;
	}
	else if(b1)
	{
		dJointAttach( ml->joint, b1->body, 0 );
		ml->b1 = b1->name;
		ml->b2 = "Ground";
	}
	else
	{
		dJointAttach( ml->joint, b2->body, 0 );
		ml->b1 = "Ground";
		ml->b2 = b2->name;
	}
	dJointSetFixed(ml->joint);
	
	EC->CreateODEObj(ml);
	ml->SetVisible(false);

	ml->JointType = 1;
	

	MyJoints.push_back(ml);
}
MyODEJoint *MySimulation::SetFixJoint(const char *name, MyODEBody *b1, MyODEBody *b2)
{
	if(b1 == b2)
	{
		return NULL;
	}

	MyODEJoint *ml = new MyODEJoint(name, this);
	ml->filename = "cube.mesh";
	mu->lock();

	SetFixJoint(ml, b1, b2);

	mu->unlock();

	return ml;
}
MyODEJoint *MySimulation::SetFixJoint(const char *name, MyODEBody *b1)
{
	

	MyODEJoint *ml = new MyODEJoint(name, this);
	ml->filename = "cube.mesh";
	mu->lock();
	
	SetFixJoint(ml, b1, NULL);

	mu->unlock();

	return ml;
}
void MySimulation::SetHingeJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2, double px, double py, double pz, double ax, double ay, double az)
{
	
	ml->joint = dJointCreateHinge( world, 0 );
	if(b1 && b2)
	{
		dJointAttach( ml->joint, b1->body, b2->body );
		ml->b1 = b1->name;
		ml->b2 = b2->name;
	}
	else if(b1)
	{
		dJointAttach( ml->joint, b1->body, 0 );
		ml->b1 = b1->name;
		ml->b2 = "Ground";
	}
	else
	{
		dJointAttach( ml->joint, b2->body, 0 );
		ml->b1 = "Ground";
		ml->b2 = b2->name;
	}
	dJointSetHingeAnchor(ml->joint, px, py, pz);
	dJointSetHingeAxis(ml->joint, ax, ay, az);
	
	EC->CreateODEObj(ml);
	ml->SetVisible(false);

	ml->JointType = 2;
	ml->axisx = ax;
	ml->axisy = ay;
	ml->axisz = az;
	ml->jx = px;
	ml->jy = py;
	ml->jz = pz;
	

	MyJoints.push_back(ml);
}
MyODEJoint *MySimulation::SetHingeJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double px, double py, double pz, double ax, double ay, double az)
{
	if(b1 == b2)
	{
		return NULL;
	}

	MyODEJoint *ml = new MyODEJoint(name, this);
	ml->filename = "cube.mesh";
	mu->lock();

	SetHingeJoint(ml,b1,b2,px,py,pz,ax,ay,az);

	mu->unlock();
	return ml;
}
MyODEJoint *MySimulation::SetHingeJoint(const char *name, MyODEBody *b1, double px, double py, double pz, double ax, double ay, double az)
{
	

	MyODEJoint *ml = new MyODEJoint(name, this);
	ml->filename = "cube.mesh";
	mu->lock();

	SetHingeJoint(ml,b1,NULL,px,py,pz,ax,ay,az);

	mu->unlock();

	return ml;
}
void MySimulation::NearCallback(dGeomID o1, dGeomID o2)
{
	dBodyID b1 = dGeomGetBody(o1), b2 = dGeomGetBody(o2);
	if (b1 && b2 && dAreConnectedExcluding(b1,b2,dJointTypeContact)) return;
	if (b1 && b2 && dAreConnected(b1,b2)) return;

	

	for(int j=0;j < MyContacts.size();j++)
	{
		if ((o1 == MyContacts[j]->b1->geom) && (o2 == MyContacts[j]->b2->geom) || (o2 == MyContacts[j]->b1->geom) && (o1 == MyContacts[j]->b2->geom))
		{
			if(EC->po->Exec)
			{
				PyGILState_STATE gilstate;
   
				gilstate = PyGILState_Ensure();


				bpy::object pfunc = EC->po->getFunc("Contacthandler");
				try
				{
					
					pfunc(MyContacts[j]->b1, MyContacts[j]->b2);

					

					
				}
				catch(const bpy::error_already_set&)
				{
					PyErr_Print();
				}
				PyGILState_Release(gilstate);

			}
			if(!MyContacts[j]->contact)
			{
				return;
			}
			else
			{

				static const int N = 20;
				dContact contact[N];
				int n = dCollide(o1,o2,N,&contact[0].geom,sizeof(dContact));
				
				if (n > 0) {
					for (int i=0; i<n; i++) {
						contact[i].surface.mode = dContactApprox1|dContactSoftERP|dContactSoftCFM;
						contact[i].surface.soft_erp = MyContacts[j]->gERP;
						contact[i].surface.soft_cfm = MyContacts[j]->gCFM;
						contact[i].surface.mu   = MyContacts[j]->gMu;

						dJointID c = dJointCreateContact(world,contactgroup,&contact[i]);
						dJointAttach(c,b1,b2);
					}
				}
			}
			return;
		}

	}

	{
		static const int N = 20;
		dContact contact[N];
		int n = dCollide(o1,o2,N,&contact[0].geom,sizeof(dContact));
		
		if (n > 0) {
			for (int i=0; i<n; i++) {
				contact[i].surface.mode = dContactApprox1|dContactSoftERP|dContactSoftCFM;
				contact[i].surface.soft_erp = gERP;
				contact[i].surface.soft_cfm = gCFM;
				contact[i].surface.mu   = gMu;

				dJointID c = dJointCreateContact(world,contactgroup,&contact[i]);
				dJointAttach(c,b1,b2);
			}
		}
	}
}
void MySimulation::DestroyBody(MyODEBody *ml)
{
	for(int i=0;i < MyJoints.size();i++)
	{
		if(MyJoints[i]->b1 == ml->name)
		{
			return;
		}
		if(MyJoints[i]->b2 == ml->name)
		{
			return;
		}
	}
	mu->lock();
	dBodyDestroy(ml->body);
	dGeomDestroy(ml->geom);
	mu->unlock();
	EC->DestroyODEObj(ml);

	std::vector<MyODEBody*>::iterator end_it = remove( MyLinks.begin(), MyLinks.end(), ml );
	MyLinks.erase( end_it, MyLinks.end() );
}
void MySimulation::DestroyJoint(MyODEJoint *ml)
{
	mu->lock();
	dJointDestroy(ml->joint);
	mu->unlock();
	EC->DestroyODEObj(ml);

	std::vector<MyODEJoint*>::iterator end_it = remove( MyJoints.begin(), MyJoints.end(), ml );
	MyJoints.erase( end_it, MyJoints.end() );
}
void MySimulation::DestroyAll()
{
	smu->lock();

	for(int i=0;i < MyJoints.size();i++)
	{
		dJointDestroy(MyJoints[i]->joint);
		EC->DestroyODEObj(MyJoints[i]);
	}
	MyJoints.clear();

	for(int i=0;i < MyLinks.size();i++)
	{
		dBodyDestroy(MyLinks[i]->body);
		dGeomDestroy(MyLinks[i]->geom);
		EC->DestroyODEObj(MyLinks[i]);
	}
	MyLinks.clear();

	MyContacts.clear();
	
}
MyODEBody *MySimulation::SetQtSphere(const char *name, double m, double r)
{
	MyODEBody *ml = SetSphere(name, m, r);
	QtLinks.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEBody *MySimulation::SetQtBox(const char *name, double m, double lx, double ly, double lz)
{
	MyODEBody *ml = SetBox(name, m, lx, ly, lz);
	QtLinks.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEBody *MySimulation::SetQtSylinder(const char *name, double m, double l, double r)
{
	MyODEBody *ml = SetSylinder(name, m, l, r);
	QtLinks.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEBody *MySimulation::SetQtCapsule(const char *name, double m, double l, double r)
{
	MyODEBody *ml = SetCapsule(name, m, l, r);
	QtLinks.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEJoint *MySimulation::SetQtSliderJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double ax, double ay, double az)
{
	MyODEJoint *ml = SetSliderJoint(name, b1, b2, ax, ay, az);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEJoint *MySimulation::SetQtSliderJoint(const char *name, MyODEBody *b1, double ax, double ay, double az)
{
	MyODEJoint *ml = SetSliderJoint(name, b1, ax, ay, az);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEJoint *MySimulation::SetQtFixJoint(const char *name, MyODEBody *b1, MyODEBody *b2)
{
	MyODEJoint *ml = SetFixJoint(name, b1, b2);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEJoint *MySimulation::SetQtFixJoint(const char *name, MyODEBody *b1)
{
	MyODEJoint *ml = SetFixJoint(name, b1);
	
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEJoint *MySimulation::SetQtHingeJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double px, double py, double pz, double ax, double ay, double az)
{
	MyODEJoint *ml = SetHingeJoint(name, b1, b2, px, py, pz, ax, ay, az);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
MyODEJoint *MySimulation::SetQtHingeJoint(const char *name, MyODEBody *b1, double px, double py, double pz, double ax, double ay, double az)
{
	MyODEJoint *ml = SetHingeJoint(name, b1, px, py, pz, ax, ay, az);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}


void MySimulation::SetQtSphere(MyODEBody *ml)
{
	ml->filename = "ODESphere.mesh";
	mu->lock();
	dMass mass;
	ml->body  = dBodyCreate(world);
	dMassSetZero(&mass);
	dMassSetSphereTotal(&mass, ml->m, ml->rd);
	dBodySetMass(ml->body,&mass);
	ml->geom = dCreateSphere(space,ml->rd);
	dGeomSetBody(ml->geom, ml->body);

	EC->CreateODEObj(ml);

	

	MyLinks.push_back(ml);

	mu->unlock();

	ml->SetBodyPosition(ml->posx, ml->posy, ml->posz);
	ml->SetBodyRotation(ml->roll, ml->pitch, ml->yaw);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);

}
void MySimulation::SetQtBox(MyODEBody *ml)
{
	ml->filename = "ODEBox.mesh";
	mu->lock();
	dMass mass;
	ml->body  = dBodyCreate(world);
	dMassSetZero(&mass);
	dMassSetBoxTotal(&mass, ml->m, ml->lx, ml->ly, ml->lz);
	dBodySetMass(ml->body,&mass);
	ml->geom = dCreateBox(space,ml->lx, ml->ly, ml->lz);
	dGeomSetBody(ml->geom, ml->body);

	

	EC->CreateODEObj(ml);

	MyLinks.push_back(ml);

	mu->unlock();

	ml->SetBodyPosition(ml->posx, ml->posy, ml->posz);
	ml->SetBodyRotation(ml->roll, ml->pitch, ml->yaw);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);
}
void MySimulation::SetQtSylinder(MyODEBody *ml)
{
	ml->filename = "ODESylinder.mesh";
	mu->lock();
	dMass mass;
	ml->body  = dBodyCreate(world);
	dMassSetZero(&mass);
	dMassSetCylinderTotal(&mass, ml->m, 1, ml->rd, ml->lx);
	dBodySetMass(ml->body,&mass);
	ml->geom = dCreateCylinder(space,ml->rd, ml->lx);
	dGeomSetBody(ml->geom, ml->body);

	

	EC->CreateODEObj(ml);

	MyLinks.push_back(ml);

	mu->unlock();

	ml->SetBodyPosition(ml->posx, ml->posy, ml->posz);
	ml->SetBodyRotation(ml->roll, ml->pitch, ml->yaw);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);
}
void MySimulation::SetQtCapsule(MyODEBody *ml)
{
	ml->filename = "ODESylinder.mesh";
	mu->lock();
	dMass mass;
	ml->body  = dBodyCreate(world);
	dMassSetZero(&mass);
	dMassSetCapsuleTotal(&mass, ml->m, 1, ml->rd, ml->lx);
	dBodySetMass(ml->body,&mass);
	ml->geom = dCreateCapsule(space,ml->rd, ml->lx);
	dGeomSetBody(ml->geom, ml->body);

	

	EC->CreateODEObj(ml);

	MyLinks.push_back(ml);

	mu->unlock();

	ml->SetBodyPosition(ml->posx, ml->posy, ml->posz);
	ml->SetBodyRotation(ml->roll, ml->pitch, ml->yaw);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);
}
void MySimulation::SetQtSliderJoint(MyODEJoint *ml)
{
	MyODEBody *b1 = getBodyByName(ml->b1.c_str());
	MyODEBody *b2 = getBodyByName(ml->b2.c_str());
	if(b1 == b2)
	{
		return;
	}
	
	ml->filename = "cube.mesh";
	mu->lock();
	

	SetSliderJoint(ml, b1, b2, ml->axisx, ml->axisy, ml->axisz);

	mu->unlock();
	//ml->SetJointPosition(ml->jx, ml->jy, ml->jz);
	ml->SetJointRotation(ml->axisx, ml->axisy, ml->axisz);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);
}
void MySimulation::SetQtFixJoint(MyODEJoint *ml)
{
	MyODEBody *b1 = getBodyByName(ml->b1.c_str());
	MyODEBody *b2 = getBodyByName(ml->b2.c_str());
	if(b1 == b2)
	{
		return;
	}

	
	ml->filename = "cube.mesh";
	mu->lock();

	SetFixJoint(ml, b1, b2);

	mu->unlock();

	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);

	
}
void MySimulation::SetQtHingeJoint(MyODEJoint *ml)
{
	MyODEBody *b1 = getBodyByName(ml->b1.c_str());
	MyODEBody *b2 = getBodyByName(ml->b2.c_str());
	if(b1 == b2)
	{
		return;
	}

	
	ml->filename = "cube.mesh";
	mu->lock();

	SetHingeJoint(ml,b1,b2,ml->jx,ml->jy,ml->jz,ml->axisx,ml->axisy,ml->axisz);

	mu->unlock();
}

void MySimulation::SetQuiq(bool q)
{
	QuiqFlag = q;
}

void MySimulation::DestroyQtBody(MyODEBody *ml)
{
	DestroyBody(ml);
	std::vector<MyODEBody*>::iterator end_it = remove( QtLinks.begin(), QtLinks.end(), ml );
	QtLinks.erase( end_it, QtLinks.end() );

	EC->DestroyQtNode(ml->mNode);
}
void MySimulation::DestroyQtJoint(MyODEJoint *ml)
{
	DestroyJoint(ml);
	std::vector<MyODEJoint*>::iterator end_it = remove( QtJoints.begin(), QtJoints.end(), ml );
	QtJoints.erase( end_it, QtJoints.end() );

	EC->DestroyQtNode(ml->mNode);
}

MyODEBody *MySimulation::getBodyByName(const char* name)
{
	for(int i=0;i < MyLinks.size();i++)
	{
		if(MyLinks[i]->name == name)
		{
			return MyLinks[i];
		}
	}
	return NULL;
	
}
MyODEJoint *MySimulation::getJointByName(const char* name)
{
	for(int i=0;i < MyJoints.size();i++)
	{
		if(MyJoints[i]->name == name)
		{
			return MyJoints[i];
		}
	}
	return NULL;
}

void MySimulation::SetScale(float sx, float sy, float sz)
{
	for(int i=0;i < MyJoints.size();i++)
	{
		MyJoints[i]->SetODEScale(sx,sy,sz);
	}
	

	for(int i=0;i < MyLinks.size();i++)
	{
		MyLinks[i]->SetODEScale(sx,sy,sz);
	}
	scale_x = sx;
	scale_y = sy;
	scale_z = sz;
}

void MySimulation::save(std::ofstream &ofs2)
{
	ofs2.write( (char*)&scale_x, sizeof(scale_x) );
	ofs2.write( (char*)&scale_y, sizeof(scale_y) );
	ofs2.write( (char*)&scale_y, sizeof(scale_y) );
	ofs2.write( (char*)&GRABITY, sizeof(GRABITY) );
	ofs2.write( (char*)&SleepTime, sizeof(SleepTime) );
	ofs2.write( (char*)&sTime, sizeof(sTime) );
	ofs2.write( (char*)&CFM, sizeof(CFM) );
	ofs2.write( (char*)&ERP, sizeof(ERP) );
	ofs2.write( (char*)&gCFM, sizeof(gCFM) );
	ofs2.write( (char*)&gERP, sizeof(gERP) );
	ofs2.write( (char*)&gMu, sizeof(gMu) );
	ofs2.write( (char*)&QuiqFlag, sizeof(QuiqFlag) );

	int BNum = QtLinks.size();
	ofs2.write( (char*)&BNum, sizeof(BNum) );
	for(int i=0;i < BNum;i++)
	{
		QtLinks[i]->save(ofs2);
	}

	int JNum = QtJoints.size();
	ofs2.write( (char*)&JNum, sizeof(JNum) );
	for(int i=0;i < JNum;i++)
	{
		QtJoints[i]->save(ofs2);
	}
}
bool MySimulation::openb(std::ifstream &ifs)
{
	ifs.read( (char*)&scale_x, sizeof(scale_x) );
	ifs.read( (char*)&scale_y, sizeof(scale_y) );
	ifs.read( (char*)&scale_y, sizeof(scale_y) );
	ifs.read( (char*)&GRABITY, sizeof(GRABITY) );
	ifs.read( (char*)&SleepTime, sizeof(SleepTime) );
	ifs.read( (char*)&sTime, sizeof(sTime) );
	ifs.read( (char*)&CFM, sizeof(CFM) );
	ifs.read( (char*)&ERP, sizeof(ERP) );
	ifs.read( (char*)&gCFM, sizeof(gCFM) );
	ifs.read( (char*)&gERP, sizeof(gERP) );
	ifs.read( (char*)&gMu, sizeof(gMu) );
	ifs.read( (char*)&QuiqFlag, sizeof(QuiqFlag) );

	int BNum;
	ifs.read( (char*)&BNum, sizeof(BNum) );

	for(int i=0;i < BNum;i++)
	{
		MyODEBody *mob = new MyODEBody("", this);
		mob->openb(ifs);
		if(mob->BodyType == 0)
		{
			SetQtSphere(mob);
		}
		else if(mob->BodyType == 1)
		{
			SetQtBox(mob);
		}
		else if(mob->BodyType == 2)
		{
			SetQtSylinder(mob);
		}
		else if(mob->BodyType == 3)
		{
			SetQtCapsule(mob);
		}
		
		QtLinks.push_back(mob);
	}


	int JNum;
	ifs.read( (char*)&JNum, sizeof(JNum) );

	for(int i=0;i < JNum;i++)
	{
		MyODEJoint *mob = new MyODEJoint("", this);
		mob->openb(ifs);
		if(mob->JointType == 0)
		{
			SetQtSliderJoint(mob);
		}
		else if(mob->JointType == 1)
		{
			SetQtFixJoint(mob);
		}
		else if(mob->JointType == 2)
		{
			SetQtHingeJoint(mob);
		}
		
		
		QtJoints.push_back(mob);
	}

	return true;
}

MyContactList *MySimulation::SetContactList(const char* name, MyODEBody *b1, MyODEBody *b2)
{
	MyContactList *mcl = new MyContactList(name);
	mcl->b1 = b1;
	mcl->b2 = b2;

	MyContacts.push_back(mcl);

	return mcl;

}
void MySimulation::DestroyContactList(MyContactList *mcl)
{
	std::vector<MyContactList*>::iterator end_it = remove( MyContacts.begin(), MyContacts.end(), mcl );
	MyContacts.erase( end_it, MyContacts.end() );
}
MyContactList *MySimulation::getContactListByName(const char* name)
{
	for(int i=0;i < MyContacts.size();i++)
	{
		if(MyContacts[i]->name == name)
		{
			return MyContacts[i];
		}
	}
	return NULL;
}

void MySimulation::Reset()
{
	MyContacts.clear();
	DestroyAll();

	for(int i=0;i < QtLinks.size();i++)
	{
		
		if(QtLinks[i]->BodyType == 0)
		{
			SetQtSphere(QtLinks[i]);
		}
		else if(QtLinks[i]->BodyType == 1)
		{
			SetQtBox(QtLinks[i]);
		}
		else if(QtLinks[i]->BodyType == 2)
		{
			SetQtSylinder(QtLinks[i]);
		}
		else if(QtLinks[i]->BodyType == 3)
		{
			SetQtCapsule(QtLinks[i]);
		}
		
	}

	for(int i=0;i < QtJoints.size();i++)
	{
		if(QtJoints[i]->JointType == 0)
		{
			SetQtSliderJoint(QtJoints[i]);
		}
		else if(QtJoints[i]->JointType == 1)
		{
			SetQtFixJoint(QtJoints[i]);
		}
		else if(QtJoints[i]->JointType == 2)
		{
			SetQtHingeJoint(QtJoints[i]);
		}
		
		
		
	}
}