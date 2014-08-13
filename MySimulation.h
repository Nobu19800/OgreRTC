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
*シミュレーションの接触設定の管理クラス
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
	*接触のERPの設定の関数
	*/
	void SetERP(double e);
	/*
	*接触のCFMの設定の関数
	*/
	void SetCFM(double c);
	/*
	*摩擦の設定の関数
	*/
	void SetMu(double m);
	/*
	*接触するかしないかの設定の関数
	*/
	void SetContact(bool f);

};

/*
*シミュレーションのクラス
*/

class MySimulation : public virtual coil::Task
{
public:
	MySimulation(OgreRTCApplication *ec);
	/*
	*スレッド実行関数
	*/
	virtual int svc();
	/*
	*シミュレーション開始の関数
	*/
	void startSim();
	void restartSim();
	/*
	*シミュレーション停止の関数
	*/
	void stopSim();
	/*
	*シミュレーション終了の関数
	*/
	void finishSim();
	/*
	*重力設定の関数
	*/
	void SetGravity(double g);
	/*
	*CFM設定の関数
	*/
	void SetCFM(double c);
	/*
	*ERP設定の関数
	*/
	void SetERP(double e);
	/*
	*サンプリングタイム設定の関数
	*/
	void SetSamplingTime(double t);
	/*
	*待ち時間設定の関数
	*/
	void SetSleepTime(double t);
	/*
	*接触のCFM設定の関数
	*/
	void SetGroundCFM(double c);
	/*
	*接触のERP設定の関数
	*/
	void SetGroundERP(double e);
	/*
	*精度、速度重視設定の関数
	*/
	void SetQuiq(bool q);
	/*
	*摩擦設定の関数
	*/
	void SetGroundMu(double m);
	/*
	*球作成の関数
	*/
	MyODEBody *SetSphere(const char *name, double m, double r);
	/*
	*直方体作成の関数
	*/
	MyODEBody *SetBox(const char *name, double m, double lx, double ly, double lz);
	/*
	*円柱作成の関数
	*/
	MyODEBody *SetSylinder(const char *name, double m, double l, double r);
	/*
	*カプセル作成の関数
	*/
	MyODEBody *SetCapsule(const char *name, double m, double l, double r);
	/*
	*スライダージョイント設定の関数
	*/
	void SetSliderJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2, double ax, double ay, double az);
	/*
	*スライダージョイント作成の関数
	*/
	MyODEJoint *SetSliderJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double ax, double ay, double az);
	MyODEJoint *SetSliderJoint(const char *name, MyODEBody *b1, double ax, double ay, double az);
	/*
	*固定ジョイント設定の関数
	*/
	void SetFixJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2);
	/*
	*固定ジョイント作成の関数
	*/
	MyODEJoint *SetFixJoint(const char *name, MyODEBody *b1, MyODEBody *b2);
	MyODEJoint *SetFixJoint(const char *name, MyODEBody *b1);
	/*
	*ヒンジジョイント設定の関数
	*/
	void SetHingeJoint(MyODEJoint *ml, MyODEBody *b1, MyODEBody *b2, double px, double py, double pz, double ax, double ay, double az);
	/*
	*ヒンジジョイント作成の関数
	*/
	MyODEJoint *SetHingeJoint(const char *name, MyODEBody *b1, MyODEBody *b2, double px, double py, double pz, double ax, double ay, double az);
	MyODEJoint *SetHingeJoint(const char *name, MyODEBody *b1, double px, double py, double pz, double ax, double ay, double az);
	/*
	*接触時のコールバックの関数
	*/
	void NearCallback(dGeomID o1, dGeomID o2);
	/*
	*ボディの削除の関数
	*/
	void DestroyBody(MyODEBody *ml);
	/*
	*ジョイントの削除の関数
	*/
	void DestroyJoint(MyODEJoint *ml);
	/*
	*ボディ、ジョイントの全削除の関数
	*/
	void DestroyAll();
	/*
	*シミュレーション初期化の関数
	*/
	void Reset();

	/*
	*GUIの操作でのみでボディ、ジョイントの作成、削除をする関数
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
	*ボディ、ジョイントの再生成の関数
	*/
	void SetQtSphere(MyODEBody *ml);
	void SetQtBox(MyODEBody *ml);
	void SetQtSylinder(MyODEBody *ml);
	void SetQtCapsule(MyODEBody *ml);
	void SetQtSliderJoint(MyODEJoint *ml);
	void SetQtFixJoint(MyODEJoint *ml);
	void SetQtHingeJoint(MyODEJoint *ml);

	
	/*
	*ボディの取得の関数
	*/
	MyODEBody *getBodyByName(const char* name);
	/*
	*ジョイントの取得の関数
	*/
	MyODEJoint *getJointByName(const char* name);

	/*
	*3Dモデルに対するボディ、ジョイントの拡大率設定の関数
	*/
	void SetScale(float sx, float sy, float sz);
	/*
	*設定のファイル保存の関数
	*/
	void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
	*/
	bool openb(std::ifstream &ifs);

	/*
	*接触の設定追加の関数
	*/
	MyContactList *SetContactList(const char* name, MyODEBody *b1, MyODEBody *b2);
	/*
	*接触の設定削除の関数
	*/
	void DestroyContactList(MyContactList *mcl);
	/*
	*接触の設定取得の関数
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