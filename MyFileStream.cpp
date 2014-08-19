#include "MyFileStream.h"

std::string Replace( std::string String1, std::string String2, std::string String3 )
{
    std::string::size_type  Pos( String1.find( String2 ) );

    while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }

    return String1;
}


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