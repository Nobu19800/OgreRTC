#ifndef MYPARTICLE_H
#define MYPARTICLE_H

#include "BaseApplication.h"
#include "MyFileStream.h"

#include "MyNode.h"


class myParticle : public MyObject
{
public:
	myParticle(std::string n);


	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	bool openb(std::ifstream &ifs);

	


	Ogre::ParticleSystem *particleSystem;
	
	
	std::string filename;
	
	

};


#endif