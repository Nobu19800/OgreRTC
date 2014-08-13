#ifndef MYOGREMACRO_H
#define MYOGREMACRO_H

#include "BaseApplication.h"
#include <string>


/*
*拡張子を取得する関数
*/
std::string GetExtension(std::string &path);

/*
*角度からクオータニオンを取得する関数
*/
Ogre::Quaternion GetRotQuat(float roll, float pitch, float yaw);

#endif