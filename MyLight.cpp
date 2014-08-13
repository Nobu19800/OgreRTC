#include "MyLight.h"

MyLight::MyLight(std::string n)
{
	name = n;
	std::string nn = n + "Light";
	mNode = new MyNode(nn);
	red = 1;
	green = 1;
	blue = 1;

	type = 2;

	
}



void MyLight::setColor(float r,float g,float b)
{
	light->setDiffuseColour(r, g, b);
	light->setSpecularColour(r, g, b);
	red = r;
	green = g;
	blue = b;
}




bool MyLight::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);

	

	mNode->name = ReadString(ifs);

	ifs.read( (char*)&red, sizeof(red) );
	ifs.read( (char*)&green, sizeof(green) );
	ifs.read( (char*)&blue, sizeof(blue) );

	

	return true;
}

void MyLight::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	

	WriteString(mNode->name , ofs2 );

	ofs2.write( (char*)&red, sizeof(red) );
	ofs2.write( (char*)&green, sizeof(green) );
	ofs2.write( (char*)&blue, sizeof(blue) );
	

}