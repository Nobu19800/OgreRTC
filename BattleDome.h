#ifndef BATTLEDOME_H
#define BATTLEDOME_H

#include "MyLink.h"
#include <time.h>
#include <windows.h>
#include <process.h>













class BattleDome
{
public:
	BattleDome();
	~BattleDome();
	static BattleDome *object(void)
	{
		static BattleDome BattleDome;
		return &BattleDome;
	}
	void makeParam();
	void makeRobot();

	void Pcontrol();
	void walk();
	
	
	
	void SetFripper(int num, int f1, int f2);
	void SetFripperManual(bool f1, bool f2, bool f3, bool f4);
	double GetFripperInput(int num);
	void SetBallPQ(MyLink ml,int num, double offx, double offy, double offz, double scalex, double scaley, double scalez);
	void SetCBPQ(MyLink ml, double offx, double offy, double offz, double scalex, double scaley, double scalez);
	void SetCBAngularVelocity(double vel);
	void SetBlockPQ(MyLink ml,int num, double offx, double offy, double offz, double scalex, double scaley, double scalez);
	void SetFripperPQ(MyLink ml,int num, double offx, double offy, double offz, double scalex, double scaley, double scalez);
	void SetBasePQ(MyLink ml, double offx, double offy, double offz, double scalex, double scaley, double scalez);
	void SetTakePQ(MyLink ml,int num, double offx, double offy, double offz, double scalex, double scaley, double scalez);
	int getBallNum();
	int getBallNumCase(int num);
	void NearCallBack(dGeomID o1, dGeomID o2);

	int Bnum[4];


	
	bool VisiSim;

	contact_flag *CF;

	static const int Wall_NUM = 16;
	static const int BALL_NUM = 48;

	MyLink ball[BALL_NUM],Base,CB,Stick[4],Wall[Wall_NUM],*Case[4], Block[4], Fripper[8], Guard, Take[4];
	

	dWorldID      world;
	dSpaceID      space;
	dGeomID       ground;
	dJointGroupID contactgroup;

	dReal GRABITY;	//重力加速度
	double T;	//サンプリングタイム

	bool CF_set;
	bool CF_set2;

	int SleepTime;

	void SetSleepTime(int st);
	void SetSamplingTime(double t);
	void SetQF(bool qf);
	void SetBF(double bf);

	double Ball_Force;
	bool QuiqFlag;



	

};


#endif