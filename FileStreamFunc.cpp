/*!
 * @file  FileStreamFunc.cpp
 * @brief ファイル入出力関連の関数
 *
 */

#include "FileStreamFunc.h"



/**
*@brief バイナリ形式の文字列保存の関数
* @param a 書き込む文字列
* @param ofs ファイルストリーム
*/
void WriteString(std::string a, std::ofstream &ofs)
{
	int s = a.size()+1;
	ofs.write( (char*)&s, sizeof(s) );
	ofs.write( a.c_str(), s );
}


/**
*@brief バイナリ形式の文字列読み込みの関数
 @param ifs ファイルストリーム
* @return ofs 読み込んだ文字列
*/
std::string ReadString(std::ifstream &ifs)
{
	std::string a;
	int s;
	ifs.read( (char*)&s, sizeof(s) );

	char *st = new char[s];
	ifs.read( st, s );

	a = st;

	delete st;

	return a;
}