/*!
 * @file  ODEJointObj.h
 * @brief シミュレーションのジョイント関連のクラス
 *
 */

#ifndef ODEJointObj_H
#define ODEJointObj_H

#include "BaseApplication.h"
#include <deque>
#include <ode/ode.h>

#include "FileStreamFunc.h"


#include "NodeObj.h"
#include "LinkObj.h"

#include "SimulationObj.h"

class SimulationObj;


/**
 * @class ODEBodyObj
*@brief シミュレーションのジョイントのクラス
*/
class ODEJointObj : public LinkObj
{
public:
	/**
	*@brief コンストラクタ
	* @param n 名前
	* @param s シミュレーションオブジェクト
	*/
	ODEJointObj(std::string n, SimulationObj *s);

	
	SimulationObj *ms;

	/**
	*@brief 設定のファイル保存の関数
	* @param ofs2 ファイルストリーム
	*/
	virtual void save(std::ofstream &ofs2);
	/**
	*@brief 設定のファイル読み込みの関数
	* @param ofs2 ファイルストリーム
	* @return trueで成功、falseで失敗
	*/
	virtual bool openb(std::ifstream &ifs);

	/**
	*@brief 位置設定の関数
	* @param x 位置(X)
	* @param y 位置(Y)
	* @param z 位置(Z)
	*/
	void SetJointPosition(double px, double py, double pz);
	/**
	*@brief 姿勢設定の関数
	* @param r ロール
	* @param p ピッチ
	* @param y ヨー
	*/
	void SetJointRotation(double r, double p, double y);
	
	/**
	*@brief ジョイントの角度、位置制御の関数
	* @param v 目標角度、目標位置
	*/
	void ControlJointAng(double v);
	
	/**
	*@brief ジョイントの速度制御の関数
	* @param v 目標速度
	*/
	void ControlJointVel(double v);
	
	/**
	*@brief ジョイントの力制御の関数
	* @param v トルク、力
	*/
	void ControlJointToq(double v);

	/**
	*@brief 3Dモデルに対する拡大率の関数
	* @param sx 拡大率(X)
	* @param sy 拡大率(Y)
	* @param sz 拡大率(Z)
	*/
	void SetODEScale(float sx, float sy, float sz);
	/**
	*@brief 3Dモデルに対するオフセットの関数
	* @param sx オフセット(X)
	* @param sy オフセット(Y)
	* @param sz オフセット(Z)
	*/
	void SetODEOffset(float ox, float oy, float oz);
	/**
	*@brief 位置更新の関数
	*/
	void UpdateJointPosition();

	
	/**
	*@brief ジョイントの位置、角度取得の関数
	* @return ジョイントの位置、角度
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