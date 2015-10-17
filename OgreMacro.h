/*!
 * @file  OgreMacro.h
 * @brief 各種関数
 *
 */

#ifndef OgreMacro_H
#define OgreMacro_H

#include "BaseApplication.h"
#include <string>



/**
*@brief 拡張子を取得する関数
* @param path パス
* @return 拡張子
*/
std::string GetExtension(std::string &path);


/**
*@brief 角度からクオータニオンを取得する関数
* @param path 角度(ロール)
* @param path 角度(ピッチ)
* @param path 角度(ヨー)
* @return クォータニオン
*/
Ogre::Quaternion GetRotQuat(float roll, float pitch, float yaw);

#endif