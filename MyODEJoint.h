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
	void SetJointPosition(double px, double py, double pz);
	/*
	*�p���ݒ�̊֐�
	*/
	void SetJointRotation(double r, double p, double y);
	/*
	*�W���C���g�̊p�x�A�ʒu����̊֐�
	*/
	void ControlJointAng(double v);
	/*
	*�W���C���g�̑��x����̊֐�
	*/
	void ControlJointVel(double v);
	/*
	*�W���C���g�̗͐���̊֐�
	*/
	void ControlJointToq(double v);

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
	void UpdateJointPosition();

	/*
	*�W���C���g�̈ʒu�A�p�x�擾�̊֐�
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