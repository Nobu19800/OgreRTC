/*!
 * @file  OgreMacro.cpp
 * @brief 各種関数
 *
 */

#include "OgreMacro.h"
using namespace std;

/**
*@brief 角度からクオータニオンを取得する関数
* @param path 角度(ロール)
* @param path 角度(ピッチ)
* @param path 角度(ヨー)
* @return クォータニオン
*/
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


/**
*@brief 拡張子を取得する関数
* @param path パス
* @return 拡張子
*/
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