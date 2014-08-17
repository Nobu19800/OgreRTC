#ifndef MYODEBODY_H
#define MYODEBODY_H

#include "BaseApplication.h"
#include <deque>
#include <ode/ode.h>

#include "MyFileStream.h"


#include "MyNode.h"
#include "MyLink.h"
#include "MySimulation.h"



class MySimulation;


/*
*シミュレーションのボディのクラス
*/

class MyODEBody : public MyLink
{
public:
	MyODEBody(std::string n, MySimulation *s);
	
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
	void SetBodyPosition(double px, double py, double pz);
	/*
	*姿勢設定の関数
	*/
	void SetBodyRotation(double r, double p, double y);
	/*
	*位置取得の関数
	*/
	double GetPosition(int num);

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
	void UpdateBodyPosition();
	
  
  
  dBodyID  body;
  dGeomID  geom;
  

  int BodyType;

  float bscale_x,bscale_y,bscale_z;
  
  dReal    roll, pitch, yaw, offx,offy,offz,m,rd,posx,posy,posz,lx,ly,lz; // 質量(weight)，半径(radius)，位置(positin:x,y,z)
  




};


#endif