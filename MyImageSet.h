#ifndef MYIMAGESET_H
#define MYIMAGESET_H

#include <CEGUI.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>

#include "MyFileStream.h"

/*
* �摜�̃N���X
*/

class MyImageSet
{
public:
	MyImageSet();

	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	bool openb(std::ifstream &ifs);

	CEGUI::Texture *texture;
	CEGUI::Imageset *imageSet;

	std::string name;
	std::string filename;

};


#endif