#ifndef MYNODE_H
#define MYNODE_H

#include "BaseApplication.h"
#include "MyFileStream.h"

class MyNode;
class MyObject;


/*
*3D���f���̃x�[�X�ƂȂ�N���X
*/

class MyObject
{
public:
	MyObject();
	int type;
	std::string name;
	MyNode *mNode;
	std::vector<MyNode*> NodeList;

	/*
	*�ʒu�ݒ�̊֐�
	*/
	void SetPosition(float sx,float sy,float sz);
	/*
	*�g�嗦�ݒ�̊֐�
	*/
	void SetScale(float x,float y,float z);
	/*
	*�p���ݒ�̊֐�
	*/
	void Roll(float ang);
	void Pitch(float ang);
	void Yaw(float ang);
	void SetRotation(float r, float p, float y);
	void SetQuaternion(float w, float x, float y, float z);
	
	/*
	*�\���A��\���ݒ�̊֐�
	*/
	void SetVisible(bool v);

	/*
	*�}�E�X�̈ʒu�ɑ΂���ʒu�X�V�̊֐�
	*/
	void UpdatePos(float dx, float dy, float dz, float CamRoll, float CamPitch, float CamYaw);
	/*
	*�}�E�X�̈ʒu�ɑ΂���p���X�V�̊֐�
	*/
	void UpdateRot(float dx, float dy, float CamRoll, float CamPitch, float CamYaw);
	/*
	*�o�E���f�B���O�{�b�N�X�̕\���A��\���ݒ�̊֐�
	*/
	void BoundingBoxVisible(bool v);
};

/*
*�m�[�h�̃N���X
*/

class MyNode
{
public:
	MyNode(std::string n);
	float pos_x, pos_y, pos_z;
	float scale_x, scale_y, scale_z;
	float roll, pitch, yaw;

	std::string name;

	Ogre::SceneNode *mNode;

	bool visi;
	bool bound_visi;

	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	bool openb(std::ifstream &ifs);

	std::vector<MyObject*> mobj;

	/*
	*�I�u�W�F�N�g�ǉ��̊֐�
	*/
	void AddObj(MyObject *mo);
	/*
	*�I�u�W�F�N�g�폜�̊֐�
	*/
	void RemoveObj(MyObject *mo);

	
};

#endif