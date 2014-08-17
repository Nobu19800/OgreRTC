#include "MyODEJoint.h"
#include "MyOgreMacro.h"



MyODEJoint::MyODEJoint(std::string n, MySimulation *s) : MyLink(n)
{
	ms = s;
	name = n;
	type = 0;

	red = 0;
	green = 0;
	blue = 0;
	color_visi = false;
	shadow_visi = true;
	

	anim_start = false;
	anim_speed = 1;

	alpha = 1;

	bscale_x = 1;
	bscale_y = 1;
	bscale_z = 1;

	offx = 0;
	offy = 0;
	offz = 0;

	

	
	delete mNode;
	std::string nn = n + "OdeJoint";
	mNode = new MyNode(nn);
}

void MyODEJoint::SetODEScale(float sx, float sy, float sz)
{
	bscale_x = sx;
	bscale_y = sy;
	bscale_z = sz;
	SetScale(sx, sy, sz);
	SetPosition(bscale_x*jx + offx, bscale_y*jx + offy, bscale_z*jx + offz);
}
void MyODEJoint::SetODEOffset(float ox, float oy, float oz)
{
	offx = ox;
	offy = oy;
	offz = oz;
	SetPosition(bscale_x*jx + offx, bscale_y*jy + offy, bscale_z*jz + offz);
}

bool MyODEJoint::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	mNode->name = ReadString(ifs);

	b1 = ReadString(ifs);
	b2 = ReadString(ifs);

	int NodeNum;
	ifs.read( (char*)&NodeNum, sizeof(NodeNum) );

	for(int i=0;i < NodeNum;i++)
	{
		std::string nn = ReadString(ifs);
		MyNode *mn = new MyNode(nn);
		NodeList.push_back(mn);
	}

	ifs.read( (char*)&JointType, sizeof(JointType) );

	ifs.read( (char*)&bscale_x, sizeof(bscale_x) );
	ifs.read( (char*)&bscale_y, sizeof(bscale_y) );
	ifs.read( (char*)&bscale_z, sizeof(bscale_z) );

	

	ifs.read( (char*)&offx, sizeof(offx) );
	ifs.read( (char*)&offy, sizeof(offy) );
	ifs.read( (char*)&offz, sizeof(offz) );

	ifs.read( (char*)&axisx, sizeof(axisx) );
	ifs.read( (char*)&axisy, sizeof(axisy) );
	ifs.read( (char*)&axisz, sizeof(axisz) );

	ifs.read( (char*)&jx, sizeof(jx) );
	ifs.read( (char*)&jy, sizeof(jy) );
	ifs.read( (char*)&jz, sizeof(jz) );
	

	return true;
}

void MyODEJoint::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(mNode->name , ofs2 );

	WriteString(b1 , ofs2 );
	WriteString(b2 , ofs2 );

	int NodeNum = NodeList.size();
	ofs2.write( (char*)&NodeNum, sizeof(NodeNum) );

	for(int i=0;i < NodeNum;i++)
	{
		WriteString(NodeList[i]->name , ofs2 );
	}
	

	ofs2.write( (char*)&JointType, sizeof(JointType) );

	ofs2.write( (char*)&bscale_x, sizeof(bscale_x) );
	ofs2.write( (char*)&bscale_y, sizeof(bscale_y) );
	ofs2.write( (char*)&bscale_z, sizeof(bscale_z) );

	

	ofs2.write( (char*)&offx, sizeof(offx) );
	ofs2.write( (char*)&offy, sizeof(offy) );
	ofs2.write( (char*)&offz, sizeof(offz) );

	ofs2.write( (char*)&axisx, sizeof(axisx) );
	ofs2.write( (char*)&axisy, sizeof(axisy) );
	ofs2.write( (char*)&axisz, sizeof(axisz) );

	ofs2.write( (char*)&jx, sizeof(jx) );
	ofs2.write( (char*)&jy, sizeof(jy) );
	ofs2.write( (char*)&jz, sizeof(jz) );

}




void MyODEJoint::SetJointPosition(double px, double py, double pz)
{
	ms->mu->lock();
	if(JointType == 2)
	{
		dJointSetHingeAnchor(joint, px, py, pz);
		SetPosition(bscale_x*px + offx, bscale_y*py + offy, bscale_z*pz + offz);
		jx = px;
		jy = py;
		jz = pz;
	}
	ms->mu->unlock();
}
void MyODEJoint::SetJointRotation(double r, double p, double y)
{
	ms->mu->lock();
	if(JointType == 0)
	{
		dJointSetSliderAxis(joint, r, p, y);
		

	}
	else if(JointType == 2)
	{
		dJointSetHingeAxis(joint, r, p, y);
		//SetPosition(bscale_x*px + offx, bscale_y*py + offy, bscale_z*pz + offz);
	}
	axisx = r;
	axisy = p;
	axisz = y;
	ms->mu->unlock();
}
void MyODEJoint::ControlJointAng(double v)
{

}
void MyODEJoint::ControlJointVel(double v)
{
	ms->mu->lock();
	if(JointType == 0)
	{
		dJointSetSliderParam(joint, dParamVel, v);
		dJointSetSliderParam(joint, dParamFMax, 200);
	}
	else if(JointType == 2)
	{
		dJointSetHingeParam(joint,dParamVel, v);
		dJointSetHingeParam(joint,dParamFMax,50.);
	}
	ms->mu->unlock();
}
void MyODEJoint::ControlJointToq(double v)
{
	ms->mu->lock();
	if(JointType == 0)
	{
		dJointAddSliderForce(joint, v);
	}
	else if(JointType == 2)
	{
		dJointAddHingeTorque(joint, v);
	}
	ms->mu->unlock();
}

void MyODEJoint::UpdateJointPosition()
{
	ms->mu->lock();
	if(JointType == 0)
	{
		dVector3 P;
		dJointGetSliderAxis(joint, P);

	}
	else if(JointType == 2)
	{
		dVector3 P;
		dJointGetHingeAnchor(joint, P);
		SetPosition(bscale_x*P[0] + offx, bscale_y*P[1] + offy, bscale_z*P[2] + offz);
		dJointGetHingeAxis(joint, P);

	}
	ms->mu->unlock();
}

double MyODEJoint::GetJointPosition()
{
	if(JointType == 0)
	{
		double a = dJointGetSliderPosition(joint);
		return a;

	}
	else if(JointType == 2)
	{
		double a = dJointGetHingeAngle(joint);
		return a;

	}
	return 0;
}