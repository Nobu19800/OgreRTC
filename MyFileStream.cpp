#include "MyFileStream.h"




void WriteString(std::string a, std::ofstream &ofs)
{
	int s = a.size()+1;
	ofs.write( (char*)&s, sizeof(s) );
	ofs.write( a.c_str(), s );
}

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