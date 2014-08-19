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
	*設定のファイル保存の関数
	*/
	void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
	*/
	bool openb(std::ifstream &ifs);

	


	Ogre::ParticleSystem *particleSystem;
	
	
	std::string filename;
	
	

};


#endif