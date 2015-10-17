/*!
 * @file  ImageSetObj.h
 * @brief イメージセット関連のクラス
 *
 */

#ifndef ImageSetObj_H
#define ImageSetObj_H

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

#include "FileStreamFunc.h"

/**
 * @class ImageSetObj
*@brief イメージセットの各種設定を行うクラス
*/

class ImageSetObj
{
public:
	/**
	*@brief コンストラクタ
	*/
	ImageSetObj();

	
	/**
	*@brief 設定のファイル保存の関数
	* @param ofs2 ファイルストリーム
	*/
	void save(std::ofstream &ofs2);
	
	/**
	*@brief 設定のファイル読み込みの関数
	* @param ifs ファイルストリーム
	* @return trueで成功、falseで失敗
	*/
	bool openb(std::ifstream &ifs);

	CEGUI::Texture *texture;
	CEGUI::Image *Image;

	std::string name;
	std::string filename;

};


#endif