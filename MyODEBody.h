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
*�V�~�����[�V�����̃{�f�B�̃N���X
*/

class MyODEBody : public MyLink
{
public:
	MyODEBody(std::string n, MySimulation *s);
	
	MySimulation *ms;
	
	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	virtual void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	virtual bool openb(std::ifstream &ifs);

	/*
	*�ʒu�ݒ�̊֐�
	*/
	void SetBodyPosition(double px, double py, double pz);
	/*
	*�p���ݒ�̊֐�
	*/
	void SetBodyRotation(double r, double p, double y);
	/*
	*�ʒu�擾�̊֐�
	*/
	double GetPosition(int num);

	/*
	*3D���f���ɑ΂���g�嗦�̊֐�
	*/
	void SetODEScale(float sx, float sy, float sz);
	/*
	*3D���f���ɑ΂���I�t�Z�b�g�̊֐�
	*/
	void SetODEOffset(float ox, float oy, float oz);
	/*
	*�ʒu�X�V�̊֐�
	*/
	void UpdateBodyPosition();
	
  
  
  dBodyID  body;
  dGeomID  geom;
  

  int BodyType;

  float bscale_x,bscale_y,bscale_z;
  
  dReal    roll, pitch, yaw, offx,offy,offz,m,rd,posx,posy,posz,lx,ly,lz; // ����(weight)�C���a(radius)�C�ʒu(positin:x,y,z)
  




};


#endif