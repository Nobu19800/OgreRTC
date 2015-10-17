/*!
 * @file  ParticleObj.h
 * @brief パーティクル関連のクラス
 *
 */

#ifndef ParticleObj_H
#define ParticleObj_H

#include "BaseApplication.h"
#include "FileStreamFunc.h"

#include "NodeObj.h"


/**
 * @class ParticleObj
*@brief パーティクルのクラス
*/
class ParticleObj : public ObjectBase
{
public:
	/**
	*@brief コンストラクタ
	* @param n 名前
	*/
	ParticleObj(std::string n);


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

	


	Ogre::ParticleSystem *particleSystem;
	
	
	std::string filename;
	
	

};


#endif