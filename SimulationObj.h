/*!
 * @file  SimulationObj.h
 * @brief シミュレーション関連のクラス
 *
 */

#ifndef SimulationObj_H
#define SimulationObj_H

#include <coil/Task.h>
#include <coil/Mutex.h>

#include <deque>
#include <ode/ode.h>




#include "OgreRTCApplication.h"
#include "ODEBodyObj.h"
#include "ODEJointObj.h"

class OgreRTCApplication;
class ODEBodyObj;
class ODEJointObj;

enum SimState { S_Start = 0, S_Stop = 1, };


/**
 * @class ContactListObj
*@brief シミュレーションの接触設定の管理クラス
*/
class ContactListObj
{
public:
	/**
	*@brief コンストラクタ
	* @param n 名前
	*/
	ContactListObj(std::string n);
	std::string name;
	ODEBodyObj *b1;
	ODEBodyObj *b2;
	double gCFM;
	double gERP;
	double gMu;
	bool contact;


	/**
	*@brief 接触のERPの設定の関数
	* @param e ERP
	*/
	void SetERP(double e);
	
	/**
	*@brief 接触のCFMの設定の関数
	* @param c CFM
	*/
	void SetCFM(double c);
	
	/**
	*@brief 摩擦の設定の関数
	* @param m 摩擦係数
	*/
	void SetMu(double m);
	
	/**
	*@brief 接触するかしないかの設定の関数
	* @param m trueで接触、falseで非接触
	*/
	void SetContact(bool f);

};


/**
 * @class SimulationObj
*@brief シミュレーションの管理クラス
*/
class SimulationObj : public virtual coil::Task
{
public:
	/**
	*@brief コンストラクタ
	* @param ec Ogre3Dのレンダリング管理オブジェクト
	*/
	SimulationObj(OgreRTCApplication *ec);
	
	/**
	*@brief スレッド実行関数
	* @return 
	*/
	virtual int svc();
	
	/**
	*@brief シミュレーション開始の関数
	*/
	void startSim();
	/**
	*@brief シミュレーション再開始の関数 
	*/
	void restartSim();
	
	/**
	*@brief シミュレーション停止の関数
	*/
	void stopSim();
	/**
	*@brief シミュレーション終了の関数
	*/
	void finishSim();
	
	/**
	*@brief 重力加速度設定の関数
	* @param g 重力加速度
	*/
	void SetGravity(double g);
	
	/**
	*@brief CFM設定の関数
	* @param c CFM
	*/
	void SetCFM(double c);
	
	/**
	*@brief ERP設定の関数
	* @param e ERP
	*/
	void SetERP(double e);
	
	/**
	*@brief サンプリングタイム設定の関数
	* @param t サンプリングタイム
	*/
	void SetSamplingTime(double t);
	
	/**
	*@brief 毎ステップの待ち時間設定の関数
	* @param t 待ち時間
	*/
	void SetSleepTime(double t);
	
	/**
	*@brief 接触のCFM設定の関数
	* @param c CFM
	*/
	void SetGroundCFM(double c);
	
	/**
	*@brief 接触のERP設定の関数
	* @param e ERP
	*/
	void SetGroundERP(double e);
	
	/**
	*@brief 精度、速度重視設定の関数
	* @param q trueで速度重視、falseで制度重視
	*/
	void SetQuiq(bool q);
	
	/**
	*@brief 摩擦設定の関数
	* @param m 摩擦係数
	*/
	void SetGroundMu(double m);
	
	/**
	*@brief 球作成の関数
	* @param name 名前
	* @param m 質量
	* @param r 半径
	*/
	ODEBodyObj *SetSphere(const char *name, double m, double r);
	
	/**
	*@brief 直方体作成の関数
	* @param name 名前
	* @param m 質量
	* @param lx サイズ(X)
	* @param ly サイズ(Y)
	* @param lz サイズ(Z)
	*/
	ODEBodyObj *SetBox(const char *name, double m, double lx, double ly, double lz);
	
	/**
	*@brief 円柱作成の関数
	* @param name 名前
	* @param m 質量
	* @param l 高さ
	* @param r 半径
	*/
	ODEBodyObj *SetSylinder(const char *name, double m, double l, double r);
	
	/**
	*@brief カプセル作成の関数
	* @param name 名前
	* @param m 質量
	* @param l 高さ
	* @param r 半径
	*/
	ODEBodyObj *SetCapsule(const char *name, double m, double l, double r);
	
	/**
	*@brief スライダージョイント設定の関数
	* @param m1 ジョイントオブジェクト
	* @param b1 ボディオブジェクト1
	* @param b2 ボディオブジェクト2
	* @param ax 軸ベクトル(X)
	* @param ay 軸ベクトル(Y)
	* @param az 軸ベクトル(Z)
	*/
	void SetSliderJoint(ODEJointObj *ml, ODEBodyObj *b1, ODEBodyObj *b2, double ax, double ay, double az);
	
	/**
	*@brief スライダージョイント作成の関数
	* @param name 名前
	* @param b1 ボディオブジェクト1
	* @param b2 ボディオブジェクト2
	* @param ax 軸ベクトル(X)
	* @param ay 軸ベクトル(Y)
	* @param az 軸ベクトル(Z)
	*/
	ODEJointObj *SetSliderJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2, double ax, double ay, double az);

	/**
	*@brief スライダージョイント作成の関数(地面と接続)
	* @param name 名前
	* @param b1 ボディオブジェクト
	* @param ax 軸ベクトル(X)
	* @param ay 軸ベクトル(Y)
	* @param az 軸ベクトル(Z)
	*/
	ODEJointObj *SetSliderJoint(const char *name, ODEBodyObj *b1, double ax, double ay, double az);
	
	/**
	*@brief 固定ジョイント設定の関数
	* @param name 名前
	* @param b1 ボディオブジェクト1
	* @param b2 ボディオブジェクト2
	*/
	void SetFixJoint(ODEJointObj *ml, ODEBodyObj *b1, ODEBodyObj *b2);
	
	/**
	*@brief 固定ジョイント作成の関数
	* @param name 名前
	* @param b1 ボディオブジェクト1
	* @param b2 ボディオブジェクト2
	*/
	ODEJointObj *SetFixJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2);
	/**
	*@brief 固定ジョイント作成の関数(地面と接続)
	* @param name 名前
	* @param b1 ボディオブジェクト1
	*/
	ODEJointObj *SetFixJoint(const char *name, ODEBodyObj *b1);
	
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
	void SetHingeJoint(ODEJointObj *ml, ODEBodyObj *b1, ODEBodyObj *b2, double px, double py, double pz, double ax, double ay, double az);
	
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
	ODEJointObj *SetHingeJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2, double px, double py, double pz, double ax, double ay, double az);

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
	ODEJointObj *SetHingeJoint(const char *name, ODEBodyObj *b1, double px, double py, double pz, double ax, double ay, double az);
	
	/**
	*@brief 接触時のコールバックの関数
	* @param name 名前
	* @param o1 ジオメトリ1
	* @param o2 ジオメトリ2
	*/
	void NearCallback(dGeomID o1, dGeomID o2);
	
	/**
	*@brief ボディの削除の関数
	* @param ml ボディオブジェクト
	*/
	void DestroyBody(ODEBodyObj *ml);
	
	/**
	*@brief ジョイントの削除の関数
	* @param ml ジョイントオブジェクト
	*/
	void DestroyJoint(ODEJointObj *ml);
	
	/**
	*@brief ボディ、ジョイントの全削除の関数
	*/
	void DestroyAll();
	
	/**
	*@brief シミュレーション初期化の関数
	*/
	void Reset();

	
	/**
	*@brief GUIの操作で球を作成する関数
	* @param name 名前
	* @param m 質量
	* @param r 半径
	* @return ボディオブジェクト
	*/
	ODEBodyObj *SetQtSphere(const char *name, double m, double r);
	/**
	*@brief GUIの操作で直方体を作成する関数
	* @param name 名前
	* @param m 質量
	* @param lx サイズ(X)
	* @param ly サイズ(Y)
	* @param lz サイズ(Z)
	* @return ボディオブジェクト
	*/
	ODEBodyObj *SetQtBox(const char *name, double m, double lx, double ly, double lz);
	/**
	*@brief GUIの操作で円柱を作成する関数
	* @param name 名前
	* @param m 質量
	* @param r 半径
	* @param l 高さ
	* @return ボディオブジェクト
	*/
	ODEBodyObj *SetQtSylinder(const char *name, double m, double l, double r);
	/**
	*@brief GUIの操作でカプセルを作成する関数
	* @param name 名前
	* @param m 質量
	* @param r 半径
	* @param l 高さ
	* @return ボディオブジェクト
	*/
	ODEBodyObj *SetQtCapsule(const char *name, double m, double l, double r);
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
	ODEJointObj *SetQtSliderJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2, double ax, double ay, double az);
	/**
	*@brief GUIの操作でスライダージョイントを作成する関数(地面と接続)
	* @param name 名前
	* @param b1 ボディオブジェクト1
	* @param ax 軸ベクトル(X)
	* @param ay 軸ベクトル(Y)
	* @param az 軸ベクトル(Z)
	* @return ジョイントオブジェクト
	*/
	ODEJointObj *SetQtSliderJoint(const char *name, ODEBodyObj *b1, double ax, double ay, double az);
	
	/**
	*@brief GUIの操作で固定ジョイントを作成する関数
	* @param name 名前
	* @param b1 ボディオブジェクト1
	* @param b2 ボディオブジェクト2
	* @return ジョイントオブジェクト
	*/
	ODEJointObj *SetQtFixJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2);
	/**
	*@brief GUIの操作で固定ジョイントを作成する関数(地面と接続)
	* @param name 名前
	* @param b1 ボディオブジェクト1
	* @return ジョイントオブジェクト
	*/
	ODEJointObj *SetQtFixJoint(const char *name, ODEBodyObj *b1);
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
	ODEJointObj *SetQtHingeJoint(const char *name, ODEBodyObj *b1, ODEBodyObj *b2, double px, double py, double pz, double ax, double ay, double az);
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
	ODEJointObj *SetQtHingeJoint(const char *name, ODEBodyObj *b1, double px, double py, double pz, double ax, double ay, double az);
	/**
	*@brief GUIの操作でボディオブジェクトを削除する関数
	* @param ml ボディオブジェクト
	*/
	void DestroyQtBody(ODEBodyObj *ml);
	
	/**
	*@brief GUIの操作でジョイントオブジェクトを削除する関数
	* @param ml ジョイントオブジェクト
	*/
	void DestroyQtJoint(ODEJointObj *ml);

	
	/**
	*@brief 球を再生成する関数
	* @param ml ボディオブジェクト
	*/
	void SetQtSphere(ODEBodyObj *ml);
	/**
	*@brief 直方体を再生成する関数
	* @param ml ボディオブジェクト
	*/
	void SetQtBox(ODEBodyObj *ml);
	/**
	*@brief 円柱を再生成する関数
	* @param ml ボディオブジェクト
	*/
	void SetQtSylinder(ODEBodyObj *ml);
	/**
	*@brief カプセルを再生成する関数
	* @param ml ボディオブジェクト
	*/
	void SetQtCapsule(ODEBodyObj *ml);
	/**
	*@brief スライダージョイントを再生成する関数
	* @param ml ジョイントオブジェクト
	*/
	void SetQtSliderJoint(ODEJointObj *ml);
	/**
	*@brief 固定ジョイントを再生成する関数
	* @param ml ジョイントオブジェクト
	*/
	void SetQtFixJoint(ODEJointObj *ml);
	/**
	*@brief ヒンジジョイントを再生成する関数
	* @param ml ジョイントオブジェクト
	*/
	void SetQtHingeJoint(ODEJointObj *ml);

	
	
	/**
	*@brief ボディを名前から取得する関数
	* @param name 名前
	* @return ボディオブジェクト
	*/
	ODEBodyObj *getBodyByName(const char* name);
	
	/**
	*@brief ジョイントを名前から取得する関数
	* @param name 名前
	* @return ジョイントオブジェクト
	*/
	ODEJointObj *getJointByName(const char* name);


	/**
	*@brief 3Dモデルに対するボディ、ジョイントの拡大率設定の関数
	* @param sx 拡大率(X)
	* @param sy 拡大率(Y)
	* @param sz 拡大率(Z)
	*/
	void SetScale(float sx, float sy, float sz);
	
	/**
	*@brief 設定のファイル保存の関数
	* @param ofs2 ファイルストリーム
	*/
	void save(std::ofstream &ofs2);
	
	/**
	*@brief 設定のファイル読み込みの関数
	* @param ifs ファイルストリーム
	* @return trueで成功、falseで失敗
	*/
	bool openb(std::ifstream &ifs);

	
	/**
	*@brief 接触の設定追加の関数
	* @param name 名前
	* @param b1 ボディオブジェクト1
	* @param b2 ボディオブジェクト2
	* @return シミュレーションの接触設定の管理オブジェクト
	*/
	ContactListObj *SetContactList(const char* name, ODEBodyObj *b1, ODEBodyObj *b2);
	
	/**
	*@brief 接触の設定削除の関数
	* @param mcl シミュレーションの接触設定の管理オブジェクト
	*/
	void DestroyContactList(ContactListObj *mcl);
	
	/**
	*@brief 接触の設定を名前から取得する関数
	* @param name 名前
	* @return シミュレーションの接触設定の管理オブジェクト
	*/
	ContactListObj *getContactListByName(const char* name);
	

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
	
	std::vector<ODEBodyObj *> LinkObjs;
	std::vector<ODEBodyObj *> QtLinks;

	std::vector<ODEJointObj *> MyJoints;
	std::vector<ODEJointObj *> QtJoints;

	std::vector<ContactListObj *> MyContacts;

	int SleepTime;
	double sTime;

	double CFM;
	double ERP;
	double gCFM;
	double gERP;
	double gMu;

	bool QuiqFlag;

	SimState mState;

	
	OgreRTCApplication *EC;
};


#endif