/*!
 * @file  ParticleObj.cpp
 * @brief パーティクル関連のクラス
 *
 */


#include "ParticleObj.h"



/**
*@brief パーティクルのクラスのコンストラクタ
* @param n 名前
*/
ParticleObj::ParticleObj(std::string n)
{
	type = 1;
	name = n;
	std::string nn = n + "particle";
	mNode = new NodeObj(nn);
}





/**
*@brief 設定のファイル読み込みの関数
* @param ifs ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool ParticleObj::openb(std::ifstream &ifs)
{

	name = ReadString(ifs);
	filename = ReadString(ifs);
	

	mNode->name = ReadString(ifs);

	return true;
}


/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void ParticleObj::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(filename , ofs2 );

	WriteString(mNode->name , ofs2 );

}

