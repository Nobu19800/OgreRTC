#include "MyOgreMacro.h"
using namespace std;


Ogre::Quaternion GetRotQuat(float roll, float pitch, float yaw)
{
	Ogre::Quaternion tRoll; 
	tRoll.FromAngleAxis(Ogre::Degree(roll),Ogre::Vector3(1,0,0));
	Ogre::Quaternion tPitch;
	tPitch.FromAngleAxis(Ogre::Degree(pitch),Ogre::Vector3(0,1,0));
	Ogre::Quaternion tYaw;
	tYaw.FromAngleAxis(Ogre::Degree(yaw),Ogre::Vector3(0,0,1));
	tRoll = tRoll * tPitch;
	tRoll = tRoll * tYaw;

	return tRoll;
}

string GetExtension(string &path)
{
	string ext;
    size_t pos1 = path.rfind('.');
	if(pos1 != string::npos){
        ext = path.substr(pos1+1, path.size()-pos1);
        string::iterator itr = ext.begin();
        while(itr != ext.end()){
            *itr = tolower(*itr);
            itr++;
        }
        itr = ext.end()-1;
        while(itr != ext.begin()){
            if(*itr == 0 || *itr == 32){
                ext.erase(itr--);
            }
            else{
                itr--;
            }
        }
    }
 
    return ext;
}