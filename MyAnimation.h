#ifndef MYANIMATION_H
#define MYANIMATION_H


#include "BaseApplication.h"
#include <deque>
#include <ode/ode.h>

#include "MyFileStream.h"

#include "MyNode.h"

/*
* アニメーションのキーのクラス
*/

class MyAnimationList
{
public:
	MyAnimationList();
	float px, py, pz;
	float roll, pitch, yaw;
	float mtime;
	Ogre::TransformKeyFrame *kf;
	bool trans_flag;
	bool rot_flag;
	void setTranslate(float x, float y, float z);
	void setRotation(float r, float p, float y);
};


/*
* アニメーションのクラス
*/

class MyAnimation : public MyObject
{
public:
	MyAnimation(std::string n);
	
	
	Ogre::Animation* anim;
	Ogre::NodeAnimationTrack* track;
	Ogre::AnimationState *mstate;
	
	std::vector<MyAnimationList*> animList;
	MyAnimationList *AddKeyFrame(float t);
	/*
	*キーフレームの削除の関数
	*/
	void RemoveKeyFrame(MyAnimationList *mal);
	/*
	*アニメーションの時間設定の関数
	*/
	void SetAnimationState(float t);
	/*
	*アニメーションの終了時間設定の関数
	*/
	void SetLength(float t);

	/*
	*設定のファイル保存の関数
	*/
	void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
	*/
	bool openb(std::ifstream &ifs);

	

	float Time;
};




#endif