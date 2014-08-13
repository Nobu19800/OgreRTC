#ifndef MYSIMULATION_H
#define MYSIMULATION_H

#include <coil/Task.h>
#include <coil/Mutex.h>

#include <deque>
#include <ode/ode.h>




#include "OgreRTCApplication.h"
#include "MyODEBody.h"
#include "MyODEJoint.h"

class OgreRTCApplication;
class MyODEBody;
class MyODEJoint;

/*
*�V�~�����[�V�����̐ڐG�ݒ�̊Ǘ��N���X
*/

class MyContactList
{
public:
	MyContactList(std::string n);
	std::string name;
	MyODEBody *b1;
	MyODEBody *b2;
	double gCFM;
	double gERP;
	double gMu;
	bool contact;

	/*
	*�ڐG��ERP�̐ݒ�̊֐�
	*/
	void SetERP(double e);
	/*
	*�ڐG��CFM�̐ݒ�̊֐�
	*/
	void SetCFM(double c);
	/*
	*���C�̐ݒ�̊֐�
	*/
	void SetMu(double m);
	/*
	*�ڐG���邩���Ȃ����̐ݒ�̊֐�
	*/
	void SetContact(bool f);

};

/*
*�V�~�����[�V�����̃N���X
*/

class MySimulation : public virtual coil::Task
{
public:
	MySimulation(OgreRTCApplication *ec);
	/*
	*�X���b�h���s�֐�
	*/
	virtual int svc();
	/*
	*�V�~�����[�V�����J�n�̊֐�
	*/
	void startSim();
	void restartSim();
	/*
	*�V�~�����[�V������~�̊֐�
	*/
	void stopSim();
	/*
	*�V�~�����[�V�����I���̊֐�
	*/
	void finishSim();
	/*
	*�d�͐ݒ�̊֐�
	*/
	void SetGravity(double g);
	/*
	*CFM�ݒ�̊֐�
	*/
	void SetCFM(double c);
	/*
	*ERP�ݒ�̊֐�
	*/
	void SetERP(double e);
	/*
	*�T���v�����O�^�C���ݒ�̊֐�
	*/
	void SetSamplingTime(double t);
	/*
	*�҂����Ԑݒ�̊֐�
	*/
	void SetSleepTime(double t);
	/*
	*�ڐG��CFM�ݒ�̊֐�
	*/
	void SetGroundCFM(double c);
	/*
	*�ڐG��ERP�ݒ�̊֐�
	*/
	void SetGroundERP(double e);
	/*
	*���x�A���x�d���ݒ�̊֐�
	*/
	void SetQuiq(bool q);
	/*
	*���C�ݒ�̊֐�
	*/
	void SetGroundMu(double m);
	/*
	*���쐬�̊֐�
	*/
	MyODEBody *SetSphere(const char *name, double m, double r);
	/*
	*�����̍쐬�̊֐�
	*/
	MyODEBody *SetBox(const char *name, double m, double lx, double ly, double lz);
	/*
	*�~���쐬�̊֐�
	*/
	MyODEBody *SetSylinder(const char *name, double m, double l, double r);
	/*
	*�J�v�Z���쐬�̊֐�
	*/
	MyODEBody *SetCapsule(const char *name, double m, double l, double r);
	/*
	*�X���C�_�[�W���C���g�ݒ�̊֐�
	*/
	void SetSliderJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2, double ax, double ay, double az);
	/*
	*�X���C�_�[�W���C���g�쐬�̊֐�
	*/
	MyODEJoint *SetSliderJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double ax, double ay, double az);
	MyODEJoint *SetSliderJoint(const char *name, MyODEBody *b1, double ax, double ay, double az);
	/*
	*�Œ�W���C���g�ݒ�̊֐�
	*/
	void SetFixJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2);
	/*
	*�Œ�W���C���g�쐬�̊֐�
	*/
	MyODEJoint *SetFixJoint(const char *name, MyODEBody *b1, MyODEBody *b2);
	MyODEJoint *SetFixJoint(const char *name, MyODEBody *b1);
	/*
	*�q���W�W���C���g�ݒ�̊֐�
	*/
	void SetHingeJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2, double px, double py, double pz, double ax, double ay, double az);
	/*
	*�q���W�W���C���g�쐬�̊֐�
	*/
	MyODEJoint *SetHingeJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double px, double py, double pz, double ax, double ay, double az);
	MyODEJoint *SetHingeJoint(const char *name, MyODEBody *b1, double px, double py, double pz, double ax, double ay, double az);
	/*
	*�ڐG���̃R�[���o�b�N�̊֐�
	*/
	void NearCallback(dGeomID o1, dGeomID o2);
	/*
	*�{�f�B�̍폜�̊֐�
	*/
	void DestroyBody(MyODEBody *ml);
	/*
	*�W���C���g�̍폜�̊֐�
	*/
	void DestroyJoint(MyODEJoint *ml);
	/*
	*�{�f�B�A�W���C���g�̑S�폜�̊֐�
	*/
	void DestroyAll();
	/*
	*�V�~�����[�V�����������̊֐�
	*/
	void Reset();

	/*
	*GUI�̑���ł݂̂Ń{�f�B�A�W���C���g�̍쐬�A�폜������֐�
	*/
	MyODEBody *SetQtSphere(const char *name, double m, double r);
	MyODEBody *SetQtBox(const char *name, double m, double lx, double ly, double lz);
	MyODEBody *SetQtSylinder(const char *name, double m, double l, double r);
	MyODEBody *SetQtCapsule(const char *name, double m, double l, double r);
	MyODEJoint *SetQtSliderJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double ax, double ay, double az);
	MyODEJoint *SetQtSliderJoint(const char *name, MyODEBody *b1, double ax, double ay, double az);
	MyODEJoint *SetQtFixJoint(const char *name, MyODEBody *b1, MyODEBody *b2);
	MyODEJoint *SetQtFixJoint(const char *name, MyODEBody *b1);
	MyODEJoint *SetQtHingeJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double px, double py, double pz, double ax, double ay, double az);
	MyODEJoint *SetQtHingeJoint(const char *name, MyODEBody *b1, double px, double py, double pz, double ax, double ay, double az);
	void DestroyQtBody(MyODEBody *ml);
	void DestroyQtJoint(MyODEJoint *ml);

	/*
	*�{�f�B�A�W���C���g�̍Đ����̊֐�
	*/
	void SetQtSphere(MyODEBody *ml);
	void SetQtBox(MyODEBody *ml);
	void SetQtSylinder(MyODEBody *ml);
	void SetQtCapsule(MyODEBody *ml);
	void SetQtSliderJoint(MyODEJoint *ml);
	void SetQtFixJoint(MyODEJoint *ml);
	void SetQtHingeJoint(MyODEJoint *ml);

	
	/*
	*�{�f�B�̎擾�̊֐�
	*/
	MyODEBody *getBodyByName(const char* name);
	/*
	*�W���C���g�̎擾�̊֐�
	*/
	MyODEJoint *getJointByName(const char* name);

	/*
	*3D���f���ɑ΂���{�f�B�A�W���C���g�̊g�嗦�ݒ�̊֐�
	*/
	void SetScale(float sx, float sy, float sz);
	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	bool openb(std::ifstream &ifs);

	/*
	*�ڐG�̐ݒ�ǉ��̊֐�
	*/
	MyContactList *SetContactList(const char* name, MyODEBody *b1, MyODEBody *b2);
	/*
	*�ڐG�̐ݒ�폜�̊֐�
	*/
	void DestroyContactList(MyContactList *mcl);
	/*
	*�ڐG�̐ݒ�擾�̊֐�
	*/
	MyContactList *getContactListByName(const char* name);
	

	coil::Mutex *mu;
	coil::Mutex *smu;
	bool FinishFlag;

	int scale_x, scale_y, scale_z;

	dWorldID      world;
	dSpaceID      space;
	dGeomID       ground;
	dJointGroupID contactgroup;

	dReal GRABITY;
	double T;
	
	std::vector<MyODEBody *> MyLinks;
	std::vector<MyODEBody *> QtLinks;

	std::vector<MyODEJoint *> MyJoints;
	std::vector<MyODEJoint *> QtJoints;

	std::vector<MyContactList *> MyContacts;

	int SleepTime;
	double sTime;

	double CFM;
	double ERP;
	double gCFM;
	double gERP;
	double gMu;

	bool QuiqFlag;

	
	OgreRTCApplication *EC;
};


#endif