/*!
 * @file  FileStreamFunc.h
 * @brief ファイル入出力関連の関数
 *
 */

#ifndef FileStreamFunc_H
#define FileStreamFunc_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>



/**
*@brief バイナリ形式の文字列保存の関数
* @param a 書き込む文字列
* @param ofs ファイルストリーム
*/
void WriteString(std::string a, std::ofstream &ofs);

/**
*@brief バイナリ形式の文字列読み込みの関数
 @param ifs ファイルストリーム
* @return 読み込んだ文字列
*/
std::string ReadString(std::ifstream &ifs);


#endif
