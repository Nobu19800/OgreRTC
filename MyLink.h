#ifndef MYLINK_H
#define MYLINK_H

#include "BaseApplication.h"
#include <deque>
#include <ode/ode.h>

#include "MyFileStream.h"


#include "MyNode.h"




/*
* 3D���f���̃N���X
*/


class MyLink : public MyObject
{
public:
	MyLink(std::string n);

	/*
	*�A�j���[�V�����ݒ�̊֐�
	*/
	void SetAnimation(const char* name);
	/*
	*�A�j���[�V�����������̊֐�
	*/
	void ResetAnimation( const char* name);
	/*
	*�A�j���[�V�����X�V�̊֐�
	*/
	void UpdateAnimation(const char* name, float time);
	/*
	*�e�̕\���A��\���ݒ�̊֐�
	*/
	void SetShadows( bool v);

	/*
	*�{�[���̈ʒu�ݒ�̊֐�
	*/
	void SetBornPosition(const char*name, float x, float y, float z);
	void SetBornPosition(int name, float x, float y, float z);
	/*
	*�{�[���̃N�I�[�^�j�I���ݒ�̊֐�
	*/
	void SetBornOrientation(const char*name, float w, float x, float y, float z);
	void SetBornOrientation(int name, float w, float x, float y, float z);
	/*
	*�{�[���̊g�嗦�ݒ�̊֐�
	*/
	void SetBornScale(const char*name, float sx, float sy, float sz);
	void SetBornScale(int name, float sx, float sy, float sz);
	/*
	*�{�[���̃��[���p�ݒ�̊֐�
	*/
	void SetBornRoll(const char*name, float ang);
	void SetBornRoll(int name, float ang);
	/*
	*�{�[���̃s�b�`�p�ݒ�̊֐�
	*/
	void SetBornPitch(const char*name, float ang);
	void SetBornPitch(int name, float ang);
	/*
	*�{�[���̃��[�p�ݒ�̊֐�
	*/
	void SetBornYaw(const char*name, float ang);
	void SetBornYaw(int name, float ang);
	/*
	*�{�[���̎p���ݒ�̊֐�
	*/
	void SetBornRotation(const char*name, float r, float p, float y);
	void SetBornRotation(int name, float r, float p, float y);
	/*
	*�{�[���̐��擾�̊֐�
	*/
	int GetBornNum();
	/*
	*�{�[���̏������̊֐�
	*/
	void ResetBorn();
	
	
	
	
	
	
	/*
	*�}�e���A���ݒ�̊֐�
	*/
	void SetMaterial(const char *name);

		

	/*
	*�o�E���f�B���O�{�b�N�X�̑傫���擾�̊֐�
	*/
	float GetBoundingBoxSize(int num);

	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	virtual void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
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