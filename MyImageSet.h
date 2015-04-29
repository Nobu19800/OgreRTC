#ifndef MYIMAGESET_H
#define MYIMAGESET_H

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

#include "MyFileStream.h"

/*
* 画像のクラス
*/

class MyImageSet
{
public:
	MyImageSet();

	/*
	*設定のファイル保存の関数
	*/
	void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
	*/
	bool openb(std::ifstream &ifs);

	CEGUI::Texture *texture;
	CEGUI::Image *Image;

	std::string name;
	std::string filename;

};


#endif