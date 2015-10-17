/*!
 * @file  ImageSetObj.cpp
 * @brief イメージセット関連のクラス
 *
 */

#include "ImageSetObj.h"

/**
*@brief イメージセットの各種設定を行うクラスのコンストラクタ
*/
ImageSetObj::ImageSetObj()
{
	
}

/**
*@brief 設定のファイル読み込みの関数
* @param ifs ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool ImageSetObj::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	filename = ReadString(ifs);

	
	return true;
}

/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void ImageSetObj::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(filename , ofs2 );

}