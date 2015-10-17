/*!
 * @file  AnimationObj.h
 * @brief アニメーション関連のクラス
 *
 */

#ifndef AnimationObj_H
#define AnimationObj_H


#include "BaseApplication.h"


#include <deque>
#include <ode/ode.h>

#include "FileStreamFunc.h"

#include "NodeObj.h"


/**
 * @class AnimationObjList
*@brief アニメーションのキーのクラス
*/

class AnimationObjList
{
public:
	/**
	*@brief コンストラクタ
	*/
	AnimationObjList();
	float px, py, pz;
	float roll, pitch, yaw;
	float mtime;
	Ogre::TransformKeyFrame *kf;
	bool trans_flag;
	bool rot_flag;
	/**
	*@brief 平行移動のキーを設定
	* @param x X座標
	* @param y Y座標
	* @param z Z座標
	*/
	void setTranslate(float x, float y, float z);
	/**
	*@brief 回転移動のキーを設定
	* @param r ロール
	* @param p ピッチ
	* @param y ヨー
	*/
	void setRotation(float r, float p, float y);
};


/**
 * @class AnimationObj
*@brief アニメーションの各種設定を行うクラス
*/

class AnimationObj : public ObjectBase
{
public:
	/**
	*@brief コンストラクタ
	* @param n 名前
	*/
	AnimationObj(std::string n);
	
	
	Ogre::Animation* anim;
	Ogre::NodeAnimationTrack* track;
	Ogre::AnimationState *mstate;
	
	std::vector<AnimationObjList*> animList;

	/**
	*@brief キーフレームの追加の関数
	* @param t 時間
	* @return 追加したキーフレーム
	*/
	AnimationObjList *AddKeyFrame(float t);

	/**
	*@brief キーフレームの削除の関数
	* @param mal 削除するキーフレーム
	*/
	void RemoveKeyFrame(AnimationObjList *mal);
	/**
	*@brief アニメーションの時間設定の関数
	* @param t 時間
	*/
	void SetAnimationState(float t);
	/**
	*@brief アニメーションの終了時間設定の関数
	* @param t 時間
	*/
	void SetLength(float t);
	/**
	*@brief 設定のファイル保存の関数
	* @param ofs2 ファイルストリーム
	*/
	void save(std::ofstream &ofs2);

	/**
	*@brief 設定のファイル読み込みの関数
	* @param ofs2 ファイルストリーム
	* @return trueで成功、falseで失敗
	*/
	bool openb(std::ifstream &ifs);

	

	float Time;
};




#endif