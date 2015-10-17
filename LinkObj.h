/*!
 * @file  LinkObj.h
 * @brief ボディ関連のクラス
 *
 */

#ifndef LinkObj_H
#define LinkObj_H

#include "BaseApplication.h"
#include <deque>
#include <ode/ode.h>

#include "FileStreamFunc.h"


#include "NodeObj.h"





/**
 * @class LinkObj
*@brief 3Dモデルのクラス
*/

class LinkObj : public ObjectBase
{
public:
	/**
	*@brief コンストラクタ
	*/
	LinkObj(std::string n);

	
	/**
	*@brief アニメーション設定の関数
	* @param name 名前
	*/
	void SetAnimation(const char* name);
	
	/**
	*@brief アニメーション初期化の関数
	* @param name 名前
	*/
	void ResetAnimation( const char* name);
	
	/**
	*@brief アニメーション更新の関数
	* @param name 名前
	* @param time 時間
	*/
	void UpdateAnimation(const char* name, float time);
	
	/**
	*@brief 影の表示、非表示設定の関数
	* @param v trueで表示、falseで非表示
	*/
	void SetShadows( bool v);

	
	/**
	*@brief ボーンの位置設定の関数
	* @param name 名前
	* @param x 位置(X)
	* @param y 位置(Y)
	* @param z 位置(Z)
	*/
	void SetBornPosition(const char*name, float x, float y, float z);
	/**
	*@brief ボーンの位置設定の関数
	* @param name 番号
	* @param w 位置(X)
	* @param y 位置(Y)
	* @param z 位置(Z)
	*/
	void SetBornPosition(int name, float x, float y, float z);
	
	/**
	*@brief ボーンのクオータニオン設定の関数
	* @param name 名前
	* @param x クオータニオン(W)
	* @param x クオータニオン(X)
	* @param y クオータニオン(Y)
	* @param z クオータニオン(Z)
	*/
	void SetBornOrientation(const char*name, float w, float x, float y, float z);
	/**
	*@brief ボーンのクオータニオン設定の関数
	* @param name 番号
	* @param w クオータニオン(W)
	* @param x クオータニオン(X)
	* @param y クオータニオン(Y)
	* @param z クオータニオン(Z)
	*/
	void SetBornOrientation(int name, float w, float x, float y, float z);
	
	/**
	*@brief ボーンの拡大率設定の関数
	* @param name 名前
	* @param sx 拡大率(X)
	* @param sy 拡大率(Y)
	* @param sz 拡大率(Z)
	*/
	void SetBornScale(const char*name, float sx, float sy, float sz);
	/**
	*@brief ボーンの拡大率設定の関数
	* @param name 番号
	* @param sx 拡大率(X)
	* @param sy 拡大率(Y)
	* @param sz 拡大率(Z)
	*/
	void SetBornScale(int name, float sx, float sy, float sz);
	
	/**
	*@brief ボーンのロール角設定の関数
	* @param name 名前
	* @param ang ロール角
	*/
	void SetBornRoll(const char*name, float ang);
	/**
	*@brief ボーンのロール角設定の関数
	* @param name 番号
	* @param ang ロール角
	*/
	void SetBornRoll(int name, float ang);
	/**
	*@brief ボーンのピッチ角設定の関数
	* @param name 名前
	* @param ang ピッチ角
	*/
	void SetBornPitch(const char*name, float ang);
	/**
	*@brief ボーンのピッチ角設定の関数
	* @param name 番号
	* @param ang ピッチ角
	*/
	void SetBornPitch(int name, float ang);
	/**
	*@brief ボーンのヨー角設定の関数
	* @param name 名前
	* @param ang ヨー角
	*/
	void SetBornYaw(const char*name, float ang);
	/**
	*@brief ボーンのヨー角設定の関数
	* @param name 番号
	* @param ang ヨー角
	*/
	void SetBornYaw(int name, float ang);
	
	/**
	*@brief ボーンの姿勢設定の関数
	* @param name 名前
	* @param r ロール
	* @param p ピッチ
	* @param y ヨー
	*/
	void SetBornRotation(const char*name, float r, float p, float y);
	/**
	*@brief ボーンの姿勢設定の関数
	* @param name 番号
	* @param r ロール
	* @param p ピッチ
	* @param y ヨー
	*/
	void SetBornRotation(int name, float r, float p, float y);
	
	/**
	*@brief ボーンの数取得の関数
	* @return ボーンの数
	*/
	int GetBornNum();
	
	/**
	*@brief ボーンの初期化の関数
	*/
	void ResetBorn();
	
	
	
	
	
	
	
	/**
	*@brief マテリアル設定の関数
	* @param name 名前
	*/
	void SetMaterial(const char *name);

		

	
	/**
	*@brief バウンディングボックスの大きさ取得の関数
	* @param num 0でX軸、1でY軸、2でZ軸方向のサイズを取得
	* @return サイズ
	*/
	float GetBoundingBoxSize(int num);

	/**
	*@brief 設定のファイル保存の関数
	* @param ofs2 ファイルストリーム
	*/
	virtual void save(std::ofstream &ofs2);
	/**
	*@brief 設定のファイル読み込みの関数
	* @param ifs ファイルストリーム
	* @return trueで成功、falseで失敗
	*/
	virtual bool openb(std::ifstream &ifs);

	
	
	
  
  
 
  int  dir;

  

  
  bool flag_m;
  Ogre::Entity *mEntity;
  
  
  Ogre::AnimationState *mAnimationState;
  

  
  std::string filename;
  
  float red, green, blue;
  float alpha;
  bool color_visi;
  bool shadow_visi;
  
  float anim_speed;
  std::string anim_name;
  bool anim_start;
  
  
  int size;
  
  
  Ogre::MeshPtr mp;

  std::string material_name;
  bool mat_visi;




};






#endif