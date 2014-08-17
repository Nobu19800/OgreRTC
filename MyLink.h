#ifndef MYLINK_H
#define MYLINK_H

#include "BaseApplication.h"
#include <deque>
#include <ode/ode.h>

#include "MyFileStream.h"


#include "MyNode.h"




/*
* 3Dモデルのクラス
*/


class MyLink : public MyObject
{
public:
	MyLink(std::string n);

	/*
	*アニメーション設定の関数
	*/
	void SetAnimation(const char* name);
	/*
	*アニメーション初期化の関数
	*/
	void ResetAnimation( const char* name);
	/*
	*アニメーション更新の関数
	*/
	void UpdateAnimation(const char* name, float time);
	/*
	*影の表示、非表示設定の関数
	*/
	void SetShadows( bool v);

	/*
	*ボーンの位置設定の関数
	*/
	void SetBornPosition(const char*name, float x, float y, float z);
	void SetBornPosition(int name, float x, float y, float z);
	/*
	*ボーンのクオータニオン設定の関数
	*/
	void SetBornOrientation(const char*name, float w, float x, float y, float z);
	void SetBornOrientation(int name, float w, float x, float y, float z);
	/*
	*ボーンの拡大率設定の関数
	*/
	void SetBornScale(const char*name, float sx, float sy, float sz);
	void SetBornScale(int name, float sx, float sy, float sz);
	/*
	*ボーンのロール角設定の関数
	*/
	void SetBornRoll(const char*name, float ang);
	void SetBornRoll(int name, float ang);
	/*
	*ボーンのピッチ角設定の関数
	*/
	void SetBornPitch(const char*name, float ang);
	void SetBornPitch(int name, float ang);
	/*
	*ボーンのヨー角設定の関数
	*/
	void SetBornYaw(const char*name, float ang);
	void SetBornYaw(int name, float ang);
	/*
	*ボーンの姿勢設定の関数
	*/
	void SetBornRotation(const char*name, float r, float p, float y);
	void SetBornRotation(int name, float r, float p, float y);
	/*
	*ボーンの数取得の関数
	*/
	int GetBornNum();
	/*
	*ボーンの初期化の関数
	*/
	void ResetBorn();
	
	
	
	
	
	
	/*
	*マテリアル設定の関数
	*/
	void SetMaterial(const char *name);

		

	/*
	*バウンディングボックスの大きさ取得の関数
	*/
	float GetBoundingBoxSize(int num);

	/*
	*設定のファイル保存の関数
	*/
	virtual void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
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




void SetPQ(MyLink *link);



#endif