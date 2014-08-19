#ifndef MYLIGHT_H
#define MYLIGHT_H

#include "BaseApplication.h"
#include "MyFileStream.h"



#include "MyNode.h"


/*
* 光源のクラス
*/

class MyLight : public MyObject
{
public:
	MyLight(std::string n);
	Ogre::Light *light;
	

	
	float red, green, blue;
	
	
	/*
	*設定のファイル保存の関数
	*/
	void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
	*/
	bool openb(std::ifstream &ifs);

	/*
	*色設定の関数
	*/
	void setColor(float r,float g,float b);
	
	
};

#endif