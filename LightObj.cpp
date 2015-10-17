/*!
 * @file  LightObj.cpp
 * @brief 光源関連のクラス
 *
 */

#include "LightObj.h"


/**
*@brief 光源の各種設定を行うクラスのコンストラクタ
*/
LightObj::LightObj(std::string n)
{
	name = n;
	std::string nn = n + "Light";
	mNode = new NodeObj(nn);
	red = 1;
	green = 1;
	blue = 1;

	type = 2;

	
}


/**
*@brief 色設定の関数
* @param r 赤
* @param g 緑
* @param b 青
*/
void LightObj::setColor(float r,float g,float b)
{
	light->setDiffuseColour(r, g, b);
	light->setSpecularColour(r, g, b);
	red = r;
	green = g;
	blue = b;
}



/**
*@brief 設定のファイル読み込みの関数
* @param ifs ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool LightObj::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);

	

	mNode->name = ReadString(ifs);

	ifs.read( (char*)&red, sizeof(red) );
	ifs.read( (char*)&green, sizeof(green) );
	ifs.read( (char*)&blue, sizeof(blue) );

	

	return true;
}


/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void LightObj::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	

	WriteString(mNode->name , ofs2 );

	ofs2.write( (char*)&red, sizeof(red) );
	ofs2.write( (char*)&green, sizeof(green) );
	ofs2.write( (char*)&blue, sizeof(blue) );
	

}