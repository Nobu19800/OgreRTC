#ifndef MYODEJOINT_H
#define MYODEJOINT_H

#include "BaseApplication.h"
#include <deque>
#include <ode/ode.h>

#include "MyFileStream.h"


#include "MyNode.h"
#include "MyLink.h"

#include "MySimulation.h"

class MySimulation;



class MyODEJoint : public MyLink
{
public:
	MyODEJoint(std::string n, MySimulation *s);

	
	MySimulation *ms;

	/*
	*設定のファイル保存の関数
	*/
	virtual void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
	*/
	virtual bool openb(std::ifstream &ifs);

	/*
	*位置設定の関数
	*/
	void SetJointPosition(double px, double py, double pz);
	/*
	*姿勢設定の関数
	*/
	void SetJointRotation(double r, double p, double y);
	/*
	*ジョイントの角度、位置制御の関数
	*/
	void ControlJointAng(double v);
	/*
	*ジョイントの速度制御の関数
	*/
	void ControlJointVel(double v);
	/*
	*ジョイントの力制御の関数
	*/
	void ControlJointToq(double v);

	/*
	*3Dモデルに対する拡大率の関数
	*/
	void SetODEScale(float sx, float sy, float sz);
	/*
	*3Dモデルに対するオフセットの関数
	*/
	void SetODEOffset(float ox, float oy, float oz);
	/*
	*位置更新の関数
	*/
	void UpdateJointPosition();

	/*
	*ジョイントの位置、角度取得の関数
	*/
	double GetJointPosition();

	std::string b1;
	std::string b2;
	
  
  
 
  dJointID joint;
  

  int JointType;

  float bscale_x,bscale_y,bscale_z;
  
  dReal    offx,offy,offz, axisx, axisy, axisz, jx,jy,jz; 

 
  




};





#endif