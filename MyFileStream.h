
#ifndef MYFILESTREAM_H
#define MYFILESTREAM_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

/*
* �����̒u�������̊֐�
*/
std::string Replace( std::string String1, std::string String2, std::string String3 );
/*
* �o�C�i���`���̕�����ۑ��̊֐�
*/
void WriteString(std::string a, std::ofstream &ofs);
/*
* �o�C�i���`���̕�����ǂݍ��݂̊֐�
*/
std::string ReadString(std::ifstream &ifs);


#endif
