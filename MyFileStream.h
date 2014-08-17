
#ifndef MYFILESTREAM_H
#define MYFILESTREAM_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

/*
* 文字の置き換えの関数
*/
std::string Replace( std::string String1, std::string String2, std::string String3 );
/*
* バイナリ形式の文字列保存の関数
*/
void WriteString(std::string a, std::ofstream &ofs);
/*
* バイナリ形式の文字列読み込みの関数
*/
std::string ReadString(std::ifstream &ifs);


#endif
