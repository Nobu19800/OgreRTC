#include "myParticle.h"


myParticle::myParticle(std::string n)
{
	type = 1;
	name = n;
	std::string nn = n + "particle";
	mNode = new MyNode(nn);
}






bool myParticle::openb(std::ifstream &ifs)
{

	name = ReadString(ifs);
	filename = ReadString(ifs);
	

	mNode->name = ReadString(ifs);

	return true;
}

void myParticle::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(filename , ofs2 );

	WriteString(mNode->name , ofs2 );

}

