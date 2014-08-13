#ifndef MYLIGHT_H
#define MYLIGHT_H

#include "BaseApplication.h"
#include "MyFileStream.h"



#include "MyNode.h"


/*
* �����̃N���X
*/

class MyLight : public MyObject
{
public:
	MyLight(std::string n);
	Ogre::Light *light;
	

	
	float red, green, blue;
	
	
	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	bool openb(std::ifstream &ifs);

	/*
	*�F�ݒ�̊֐�
	*/
	void setColor(float r,float g,float b);
	
	
};

#endif