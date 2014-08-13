#ifndef MYANIMATION_H
#define MYANIMATION_H


#include "BaseApplication.h"
#include <deque>
#include <ode/ode.h>

#include "MyFileStream.h"

#include "MyNode.h"

/*
* �A�j���[�V�����̃L�[�̃N���X
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
* �A�j���[�V�����̃N���X
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
	*�L�[�t���[���̍폜�̊֐�
	*/
	void RemoveKeyFrame(MyAnimationList *mal);
	/*
	*�A�j���[�V�����̎��Ԑݒ�̊֐�
	*/
	void SetAnimationState(float t);
	/*
	*�A�j���[�V�����̏I�����Ԑݒ�̊֐�
	*/
	void SetLength(float t);

	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	bool openb(std::ifstream &ifs);

	

	float Time;
};




#endif