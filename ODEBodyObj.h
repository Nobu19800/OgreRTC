/*!
 * @file  ODEBodyObj.h
 * @brief シミュレーションのボディ関連のクラス
 *
 */


#ifndef ODEBodyObj_H
#define ODEBodyObj_H

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
*@brief シミュレーションのボディのクラス
*/


class ODEBodyObj : public LinkObj
{
public:
	/**
	*@brief コンストラクタ
	* @param n 名前
	* @param s シミュレーションオブジェクト
	*/
	ODEBodyObj(std::string n, SimulationObj *s);
	
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
	void SetBodyPosition(double px, double py, double pz);
	/**
	*@brief 姿勢設定の関数
	* @param r ロール
	* @param p ピッチ
	* @param y ヨー
	*/
	void SetBodyRotation(double r, double p, double y);
	
	/**
	*@brief 位置取得の関数
	* @param num 0でX軸、1でY軸、2でZ軸
	* @return 位置
	*/
	double GetPosition(int num);

	
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
	void UpdateBodyPosition();
	
  
  
  dBodyID  body;
  dGeomID  geom;
  

  int BodyType;

  float bscale_x,bscale_y,bscale_z;
  
  dReal    roll, pitch, yaw, offx,offy,offz,m,rd,posx,posy,posz,lx,ly,lz; // 質量(weight)，半径(radius)，位置(positin:x,y,z)
  




};


#endif