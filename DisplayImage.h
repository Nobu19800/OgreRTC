/*!
 * @file  DisplayImage.h
 * @brief 画像表示オブジェクト
 *
 */

#ifndef DISPLAYIMAGE_H
#define DISPLAYIMAGE_H

#include "BaseApplication.h"








/**
 * @class DisplayImage
*@brief 画像表示オブジェクトのクラス
*/

class DisplayImage
{
public:
	/**
	*@brief コンストラクタ
	*/
	DisplayImage();

	Ogre::Rectangle2D* mRect;
	Ogre::TexturePtr texture;
	Ogre::MaterialPtr material;
	Ogre::Image img;
	Ogre::SceneNode* node;

};


#endif