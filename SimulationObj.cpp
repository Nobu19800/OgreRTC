/*!
 * @file  SimulationObj.cpp
 * @brief シミュレーション関連のクラス
 *
 */

#include "SimulationObj.h"

#include <coil/Time.h>

SimulationObj *ms;

namespace bpy = boost::python;



/**
*@brief 接触のコールバック関数
* @param data データ
* @param o1 ジオメトリ1
* @param o2 ジオメトリ2
*/
static void nearCallback(void *data, dGeomID o1, dGeomID o2) {
	if(ms)
	{
		ms->NearCallback(o1, o2);
	}
	
}


/**
*@brief シミュレーションの接触設定の管理クラスのコンストラクタ
* @param n 名前
*/
ContactListObj::ContactListObj(std::string n)
{
	name = n;
	contact = true;
	gCFM = 1e-10;
	gERP = 0.8;
	gMu = 0;

}


/**
*@brief 接触のERPの設定の関数
* @param e ERP
*/
void ContactListObj::SetERP(double e)
{
	gERP = e;
}

/**
*@brief 接触のCFMの設定の関数
* @param c CFM
*/
void ContactListObj::SetCFM(double c)
{
	gCFM = c;
}


/**
*@brief 摩擦の設定の関数
* @param m 摩擦係数
*/
void ContactListObj::SetMu(double m)
{
	gMu = m;
}

/**
*@brief 接触するかしないかの設定の関数
* @param m trueで接触、falseで非接触
*/
void ContactListObj::SetContact(bool f)
{
	contact = f;
}


/**
*@brief シミュレーションのクラスのコンストラクタ
* @param ec Ogre3Dのレンダリング管理オブジェクト
*/
SimulationObj::SimulationObj(OgreRTCApplication *ec)
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
	mState = S_Stop;
}


/**
*@brief スレッド実行関数
* @return 
*/
int SimulationObj::svc()
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
		for(int i=0;i < LinkObjs.size();i++)
		{
			LinkObjs[i]->UpdateBodyPosition();
		}

		end = clock();
		double time = (double)(end-start)/CLOCKS_PER_SEC;
		
		if(SleepTime > time*1000)
		{
			coil::usleep(SleepTime - (int)(time*1000.));
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


/**
*@brief シミュレーション開始の関数
*/
void SimulationObj::startSim()
{
	if(mState == S_Stop)
	{
		smu->unlock();
		mState = S_Start;
	}
}


/**
*@brief シミュレーション再開始の関数 
*/
void SimulationObj::restartSim()
{
	
	mu->unlock();
		
}

/**
*@brief シミュレーション停止の関数
*/
void SimulationObj::stopSim()
{
	if(mState == S_Start)
	{
		smu->lock();
		mState = S_Stop;
	}
}


/**
*@brief シミュレーション終了の関数
*/
void SimulationObj::finishSim()
{
	FinishFlag = true;
}


/**
*@brief 重力加速度設定の関数
* @param g 重力加速度
*/
void SimulationObj::SetGravity(double g)
{
	GRABITY = g;
	dWorldSetGravity(world, 0, 0, GRABITY);
}

/**
*@brief CFM設定の関数
* @param c CFM
*/
void SimulationObj::SetCFM(double c)
{
	CFM = c;
	dWorldSetCFM(world, CFM);
	
}

/**
*@brief ERP設定の関数
* @param e ERP
*/
void SimulationObj::SetERP(double e)
{
	ERP = e;
	dWorldSetERP(world, ERP);
}

/**
*@brief サンプリングタイム設定の関数
* @param t サンプリングタイム
*/
void SimulationObj::SetSamplingTime(double t)
{
	sTime = t;
}

/**
*@brief 毎ステップの待ち時間設定の関数
* @param t 待ち時間
*/
void SimulationObj::SetSleepTime(double t)
{
	SleepTime = t*1000;
}

/**
*@brief 接触のCFM設定の関数
* @param c CFM
*/
void SimulationObj::SetGroundCFM(double c)
{
	gCFM = c;
	
}

/**
*@brief 接触のERP設定の関数
* @param e ERP
*/
void SimulationObj::SetGroundERP(double e)
{
	gERP = e;
	
}

/**
*@brief 摩擦設定の関数
* @param m 摩擦係数
*/
void SimulationObj::SetGroundMu(double m)
{
	gMu = m;
}

/**
*@brief 球作成の関数
* @param name 名前
* @param m 質量
* @param r 半径
*/
ODEBodyObj *SimulationObj::SetSphere(const char *name, double m, double r)
{
	ODEBodyObj *ml = new ODEBodyObj(name, this);
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

	LinkObjs.push_back(ml);

	mu->unlock();

	return ml;
}

/**
*@brief 直方体作成の関数
* @param name 名前
* @param m 質量
* @param lx サイズ(X)
* @param ly サイズ(Y)
* @param lz サイズ(Z)
*/
ODEBodyObj *SimulationObj::SetBox(const char *name, double m, double lx, double ly, double lz)
{
	ODEBodyObj *ml = new ODEBodyObj(name, this);
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

	LinkObjs.push_back(ml);

	mu->unlock();


	return ml;
}

/**
*@brief 円柱作成の関数
* @param name 名前
* @param m 質量
* @param l 高さ
* @param r 半径
*/
ODEBodyObj *SimulationObj::SetSylinder(const char *name, double m, double l, double r)
{
	ODEBodyObj *ml = new ODEBodyObj(name, this);
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

	LinkObjs.push_back(ml);

	mu->unlock();

	return ml;
}

/**
*@brief カプセル作成の関数
* @param name 名前
* @param m 質量
* @param l 高さ
* @param r 半径
*/
ODEBodyObj *SimulationObj::SetCapsule(const char *name, double m, double l, double r)
{
	ODEBodyObj *ml = new ODEBodyObj(name, this);
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

	LinkObjs.push_back(ml);

	mu->unlock();

	return ml;
}

/**
*@brief スライダージョイント設定の関数
* @param m1 ジョイントオブジェクト
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
*/
void SimulationObj::SetSliderJoint(ODEJointObj *ml, ODEBodyObj *b1, ODEBodyObj *b2, double ax, double ay, double az)
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

/**
*@brief スライダージョイント作成の関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
*/
ODEJointObj *SimulationObj::SetSliderJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2, double ax, double ay, double az)
{
	if(b1 == b2)
	{
		return NULL;
	}
	ODEJointObj *ml = new ODEJointObj(name, this);
	ml->filename = "cube.mesh";
	mu->lock();
	

	SetSliderJoint(ml, b1, b2, ax, ay, az);

	mu->unlock();
	return ml;
}

/**
*@brief スライダージョイント作成の関数(地面と接続)
* @param name 名前
* @param b1 ボディオブジェクト
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
*/
ODEJointObj *SimulationObj::SetSliderJoint(const char *name, ODEBodyObj *b1, double ax, double ay, double az)
{
	
	ODEJointObj *ml = new ODEJointObj(name, this);
	ml->filename = "cube.mesh";
	mu->lock();

	SetSliderJoint(ml, b1, NULL, ax, ay, az);

	mu->unlock();

	return ml;
}


/**
*@brief 固定ジョイント設定の関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
*/
void SimulationObj::SetFixJoint(ODEJointObj *ml, ODEBodyObj *b1, ODEBodyObj *b2)
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

/**
*@brief 固定ジョイント作成の関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
*/
ODEJointObj *SimulationObj::SetFixJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2)
{
	if(b1 == b2)
	{
		return NULL;
	}

	ODEJointObj *ml = new ODEJointObj(name, this);
	ml->filename = "cube.mesh";
	mu->lock();

	SetFixJoint(ml, b1, b2);

	mu->unlock();

	return ml;
}

/**
*@brief 固定ジョイント作成の関数(地面と接続)
* @param name 名前
* @param b1 ボディオブジェクト1
*/
ODEJointObj *SimulationObj::SetFixJoint(const char *name, ODEBodyObj *b1)
{
	

	ODEJointObj *ml = new ODEJointObj(name, this);
	ml->filename = "cube.mesh";
	mu->lock();
	
	SetFixJoint(ml, b1, NULL);

	mu->unlock();

	return ml;
}

/**
*@brief ヒンジジョイント設定の関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
* @param px 中心点(X)
* @param py 中心点(Y)
* @param pz 中心点(Z)
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
*/
void SimulationObj::SetHingeJoint(ODEJointObj *ml, ODEBodyObj *b1, ODEBodyObj *b2, double px, double py, double pz, double ax, double ay, double az)
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

/**
*@brief ヒンジジョイント作成の関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
* @param px 中心点(X)
* @param py 中心点(Y)
* @param pz 中心点(Z)
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
*/
ODEJointObj *SimulationObj::SetHingeJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2, double px, double py, double pz, double ax, double ay, double az)
{
	if(b1 == b2)
	{
		return NULL;
	}

	ODEJointObj *ml = new ODEJointObj(name, this);
	ml->filename = "cube.mesh";
	mu->lock();

	SetHingeJoint(ml,b1,b2,px,py,pz,ax,ay,az);

	mu->unlock();
	return ml;
}

/**
*@brief ヒンジジョイント作成の関数(地面と接続)
* @param name 名前
* @param b1 ボディオブジェクト1
* @param px 中心点(X)
* @param py 中心点(Y)
* @param pz 中心点(Z)
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
*/
ODEJointObj *SimulationObj::SetHingeJoint(const char *name, ODEBodyObj *b1, double px, double py, double pz, double ax, double ay, double az)
{
	

	ODEJointObj *ml = new ODEJointObj(name, this);
	ml->filename = "cube.mesh";
	mu->lock();

	SetHingeJoint(ml,b1,NULL,px,py,pz,ax,ay,az);

	mu->unlock();

	return ml;
}

/**
*@brief 接触時のコールバックの関数
* @param name 名前
* @param o1 ジオメトリ1
* @param o2 ジオメトリ2
*/
void SimulationObj::NearCallback(dGeomID o1, dGeomID o2)
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

/**
*@brief ボディの削除の関数
* @param ml ボディオブジェクト
*/
void SimulationObj::DestroyBody(ODEBodyObj *ml)
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

	std::vector<ODEBodyObj*>::iterator end_it = remove( LinkObjs.begin(), LinkObjs.end(), ml );
	LinkObjs.erase( end_it, LinkObjs.end() );
}

/**
*@brief ジョイントの削除の関数
* @param ml ジョイントオブジェクト
*/
void SimulationObj::DestroyJoint(ODEJointObj *ml)
{
	mu->lock();
	dJointDestroy(ml->joint);
	mu->unlock();
	EC->DestroyODEObj(ml);

	std::vector<ODEJointObj*>::iterator end_it = remove( MyJoints.begin(), MyJoints.end(), ml );
	MyJoints.erase( end_it, MyJoints.end() );
}


/**
*@brief ボディ、ジョイントの全削除の関数
*/
void SimulationObj::DestroyAll()
{
	if(mState == S_Start)
	{
		smu->lock();
		mState = S_Stop;
	}
	

	for(int i=0;i < MyJoints.size();i++)
	{
		dJointDestroy(MyJoints[i]->joint);
		EC->DestroyODEObj(MyJoints[i]);
	}
	MyJoints.clear();

	for(int i=0;i < LinkObjs.size();i++)
	{
		dBodyDestroy(LinkObjs[i]->body);
		dGeomDestroy(LinkObjs[i]->geom);
		EC->DestroyODEObj(LinkObjs[i]);
	}
	LinkObjs.clear();

	MyContacts.clear();
	
}

/**
*@brief GUIの操作で球を作成する関数
* @param name 名前
* @param m 質量
* @param r 半径
* @return ボディオブジェクト
*/
ODEBodyObj *SimulationObj::SetQtSphere(const char *name, double m, double r)
{
	ODEBodyObj *ml = SetSphere(name, m, r);
	QtLinks.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}

/**
*@brief GUIの操作で直方体を作成する関数
* @param name 名前
* @param m 質量
* @param lx サイズ(X)
* @param ly サイズ(Y)
* @param lz サイズ(Z)
* @return ボディオブジェクト
*/
ODEBodyObj *SimulationObj::SetQtBox(const char *name, double m, double lx, double ly, double lz)
{
	ODEBodyObj *ml = SetBox(name, m, lx, ly, lz);
	QtLinks.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}

/**
*@brief GUIの操作で円柱を作成する関数
* @param name 名前
* @param m 質量
* @param r 半径
* @param l 高さ
* @return ボディオブジェクト
*/
ODEBodyObj *SimulationObj::SetQtSylinder(const char *name, double m, double l, double r)
{
	ODEBodyObj *ml = SetSylinder(name, m, l, r);
	QtLinks.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}

/**
*@brief GUIの操作でカプセルを作成する関数
* @param name 名前
* @param m 質量
* @param r 半径
* @param l 高さ
* @return ボディオブジェクト
*/
ODEBodyObj *SimulationObj::SetQtCapsule(const char *name, double m, double l, double r)
{
	ODEBodyObj *ml = SetCapsule(name, m, l, r);
	QtLinks.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
/**
*@brief GUIの操作でスライダージョイントを作成する関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
* @return ジョイントオブジェクト
*/
ODEJointObj *SimulationObj::SetQtSliderJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2, double ax, double ay, double az)
{
	ODEJointObj *ml = SetSliderJoint(name, b1, b2, ax, ay, az);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
/**
*@brief GUIの操作でスライダージョイントを作成する関数(地面と接続)
* @param name 名前
* @param b1 ボディオブジェクト1
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
* @return ジョイントオブジェクト
*/
ODEJointObj *SimulationObj::SetQtSliderJoint(const char *name, ODEBodyObj *b1, double ax, double ay, double az)
{
	ODEJointObj *ml = SetSliderJoint(name, b1, ax, ay, az);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
/**
*@brief GUIの操作で固定ジョイントを作成する関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
* @return ジョイントオブジェクト
*/
ODEJointObj *SimulationObj::SetQtFixJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2)
{
	ODEJointObj *ml = SetFixJoint(name, b1, b2);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
/**
*@brief GUIの操作で固定ジョイントを作成する関数(地面と接続)
* @param name 名前
* @param b1 ボディオブジェクト1
* @return ジョイントオブジェクト
*/
ODEJointObj *SimulationObj::SetQtFixJoint(const char *name, ODEBodyObj *b1)
{
	ODEJointObj *ml = SetFixJoint(name, b1);
	
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
/**
*@brief GUIの操作でヒンジジョイントを作成する関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
* @param px 中心点(X)
* @param py 中心点(Y)
* @param pz 中心点(Z)
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
* @return ジョイントオブジェクト
*/
ODEJointObj *SimulationObj::SetQtHingeJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2, double px, double py, double pz, double ax, double ay, double az)
{
	ODEJointObj *ml = SetHingeJoint(name, b1, b2, px, py, pz, ax, ay, az);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}
/**
*@brief GUIの操作でヒンジジョイントを作成する関数(地面と接続)
* @param name 名前
* @param b1 ボディオブジェクト1
* @param px 中心点(X)
* @param py 中心点(Y)
* @param pz 中心点(Z)
* @param ax 軸ベクトル(X)
* @param ay 軸ベクトル(Y)
* @param az 軸ベクトル(Z)
* @return ジョイントオブジェクト
*/
ODEJointObj *SimulationObj::SetQtHingeJoint(const char *name, ODEBodyObj *b1, double px, double py, double pz, double ax, double ay, double az)
{
	ODEJointObj *ml = SetHingeJoint(name, b1, px, py, pz, ax, ay, az);
	QtJoints.push_back(ml);
	EC->QtNodes.push_back(ml->mNode);
	return ml;
}

/**
*@brief 球を再生成する関数
* @param ml ボディオブジェクト
*/
void SimulationObj::SetQtSphere(ODEBodyObj *ml)
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

	

	LinkObjs.push_back(ml);

	mu->unlock();

	ml->SetBodyPosition(ml->posx, ml->posy, ml->posz);
	ml->SetBodyRotation(ml->roll, ml->pitch, ml->yaw);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);

}

/**
*@brief 直方体を再生成する関数
* @param ml ボディオブジェクト
*/
void SimulationObj::SetQtBox(ODEBodyObj *ml)
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

	LinkObjs.push_back(ml);

	mu->unlock();

	ml->SetBodyPosition(ml->posx, ml->posy, ml->posz);
	ml->SetBodyRotation(ml->roll, ml->pitch, ml->yaw);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);
}

/**
*@brief 円柱を再生成する関数
* @param ml ボディオブジェクト
*/
void SimulationObj::SetQtSylinder(ODEBodyObj *ml)
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

	LinkObjs.push_back(ml);

	mu->unlock();

	ml->SetBodyPosition(ml->posx, ml->posy, ml->posz);
	ml->SetBodyRotation(ml->roll, ml->pitch, ml->yaw);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);
}

/**
*@brief カプセルを再生成する関数
* @param ml ボディオブジェクト
*/
void SimulationObj::SetQtCapsule(ODEBodyObj *ml)
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

	LinkObjs.push_back(ml);

	mu->unlock();

	ml->SetBodyPosition(ml->posx, ml->posy, ml->posz);
	ml->SetBodyRotation(ml->roll, ml->pitch, ml->yaw);
	ml->SetODEScale(ml->bscale_x, ml->bscale_y, ml->bscale_z);
	ml->SetODEOffset(ml->offx, ml->offy, ml->offz);
}

/**
*@brief スライダージョイントを再生成する関数
* @param ml ジョイントオブジェクト
*/
void SimulationObj::SetQtSliderJoint(ODEJointObj *ml)
{
	ODEBodyObj *b1 = getBodyByName(ml->b1.c_str());
	ODEBodyObj *b2 = getBodyByName(ml->b2.c_str());
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

/**
*@brief 固定ジョイントを再生成する関数
* @param ml ジョイントオブジェクト
*/
void SimulationObj::SetQtFixJoint(ODEJointObj *ml)
{
	ODEBodyObj *b1 = getBodyByName(ml->b1.c_str());
	ODEBodyObj *b2 = getBodyByName(ml->b2.c_str());
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

/**
*@brief ヒンジジョイントを再生成する関数
* @param ml ジョイントオブジェクト
*/
void SimulationObj::SetQtHingeJoint(ODEJointObj *ml)
{
	ODEBodyObj *b1 = getBodyByName(ml->b1.c_str());
	ODEBodyObj *b2 = getBodyByName(ml->b2.c_str());
	if(b1 == b2)
	{
		return;
	}

	
	ml->filename = "cube.mesh";
	mu->lock();

	SetHingeJoint(ml,b1,b2,ml->jx,ml->jy,ml->jz,ml->axisx,ml->axisy,ml->axisz);

	mu->unlock();
}


/**
*@brief 精度、速度重視設定の関数
* @param q trueで速度重視、falseで制度重視
*/
void SimulationObj::SetQuiq(bool q)
{
	QuiqFlag = q;
}

/**
*@brief GUIの操作でボディオブジェクトを削除する関数
* @param ml ボディオブジェクト
*/
void SimulationObj::DestroyQtBody(ODEBodyObj *ml)
{
	DestroyBody(ml);
	std::vector<ODEBodyObj*>::iterator end_it = remove( QtLinks.begin(), QtLinks.end(), ml );
	QtLinks.erase( end_it, QtLinks.end() );

	EC->DestroyQtNode(ml->mNode);
}

/**
*@brief GUIの操作でジョイントオブジェクトを削除する関数
* @param ml ジョイントオブジェクト
*/
void SimulationObj::DestroyQtJoint(ODEJointObj *ml)
{
	DestroyJoint(ml);
	std::vector<ODEJointObj*>::iterator end_it = remove( QtJoints.begin(), QtJoints.end(), ml );
	QtJoints.erase( end_it, QtJoints.end() );

	EC->DestroyQtNode(ml->mNode);
}

/**
*@brief ボディを名前から取得する関数
* @param name 名前
* @return ボディオブジェクト
*/
ODEBodyObj *SimulationObj::getBodyByName(const char* name)
{
	for(int i=0;i < LinkObjs.size();i++)
	{
		if(LinkObjs[i]->name == name)
		{
			return LinkObjs[i];
		}
	}
	return NULL;
	
}

/**
*@brief ジョイントを名前から取得する関数
* @param name 名前
* @return ジョイントオブジェクト
*/
ODEJointObj *SimulationObj::getJointByName(const char* name)
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


/**
*@brief 3Dモデルに対するボディ、ジョイントの拡大率設定の関数
* @param sx 拡大率(X)
* @param sy 拡大率(Y)
* @param sz 拡大率(Z)
*/
void SimulationObj::SetScale(float sx, float sy, float sz)
{
	for(int i=0;i < MyJoints.size();i++)
	{
		MyJoints[i]->SetODEScale(sx,sy,sz);
	}
	

	for(int i=0;i < LinkObjs.size();i++)
	{
		LinkObjs[i]->SetODEScale(sx,sy,sz);
	}
	scale_x = sx;
	scale_y = sy;
	scale_z = sz;
}


/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void SimulationObj::save(std::ofstream &ofs2)
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

/**
*@brief 設定のファイル読み込みの関数
* @param ifs ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool SimulationObj::openb(std::ifstream &ifs)
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
		ODEBodyObj *mob = new ODEBodyObj("", this);
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
		ODEJointObj *mob = new ODEJointObj("", this);
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

/**
*@brief 接触の設定追加の関数
* @param name 名前
* @param b1 ボディオブジェクト1
* @param b2 ボディオブジェクト2
* @return シミュレーションの接触設定の管理オブジェクト
*/
ContactListObj *SimulationObj::SetContactList(const char* name, ODEBodyObj *b1, ODEBodyObj *b2)
{
	ContactListObj *mcl = new ContactListObj(name);
	mcl->b1 = b1;
	mcl->b2 = b2;

	MyContacts.push_back(mcl);

	return mcl;

}

/**
*@brief 接触の設定削除の関数
* @param mcl シミュレーションの接触設定の管理オブジェクト
*/
void SimulationObj::DestroyContactList(ContactListObj *mcl)
{
	std::vector<ContactListObj*>::iterator end_it = remove( MyContacts.begin(), MyContacts.end(), mcl );
	MyContacts.erase( end_it, MyContacts.end() );
}

/**
*@brief 接触の設定を名前から取得する関数
* @param name 名前
* @return シミュレーションの接触設定の管理オブジェクト
*/
ContactListObj *SimulationObj::getContactListByName(const char* name)
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


/**
*@brief シミュレーション初期化の関数
*/
void SimulationObj::Reset()
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