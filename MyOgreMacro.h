#ifndef MYOGREMACRO_H
#define MYOGREMACRO_H

#include "BaseApplication.h"
#include <string>


/*
*�g���q���擾����֐�
*/
std::string GetExtension(std::string &path);

/*
*�p�x����N�I�[�^�j�I�����擾����֐�
*/
Ogre::Quaternion GetRotQuat(float roll, float pitch, float yaw);

#endif