/*!
 * @file  LightObj.h
 * @brief 光源関連のクラス
 *
 */

#ifndef LightObj_H
#define LightObj_H

#include "BaseApplication.h"
#include "FileStreamFunc.h"



#include "NodeObj.h"



/**
 * @class LightObj
*@brief 光源の各種設定を行うクラス
*/

class LightObj : public ObjectBase
{
public:
	/**
	*@brief コンストラクタ
	*/
	LightObj(std::string n);
	Ogre::Light *light;
	

	
	float red, green, blue;
	
	
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

	
	/**
	*@brief 色設定の関数
	* @param r 赤
	* @param g 緑
	* @param b 青
	*/
	void setColor(float r,float g,float b);
	
	
};

#endif