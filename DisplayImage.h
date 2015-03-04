#ifndef DISPLAYIMAGE_H
#define DISPLAYIMAGE_H

#include "BaseApplication.h"







/*
*画像表示オブジェクトのクラス
*/


class DisplayImage
{
public:
	DisplayImage();

	Ogre::Rectangle2D* mRect;
	Ogre::TexturePtr texture;
	Ogre::MaterialPtr material;
	Ogre::Image img;
	Ogre::SceneNode* node;

};


#endif