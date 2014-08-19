#include "MyImageSet.h"


MyImageSet::MyImageSet()
{
	
}


bool MyImageSet::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	filename = ReadString(ifs);

	
	return true;
}

void MyImageSet::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(filename , ofs2 );

}