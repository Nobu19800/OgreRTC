/*!
 * @file  LinkObj.cpp
 * @brief ボディ関連のクラス
 *
 */

#include "LinkObj.h"
#include "OgreMacro.h"


/**
*@brief 3Dモデルのクラスのコンストラクタ
*/
LinkObj::LinkObj(std::string n)
{
	name = n;
	type = 0;

	red = 0;
	green = 0;
	blue = 0;
	color_visi = false;
	shadow_visi = true;
	

	anim_start = false;
	anim_speed = 1;

	alpha = 1;

	

	anim_name = "";
	material_name = "";

	mat_visi = false;

	std::string nn = n + "Link";
	mNode = new NodeObj(nn);
}






/**
*@brief アニメーション設定の関数
* @param name 名前
*/
void LinkObj::SetAnimation(const char* name)
{
	mAnimationState = mEntity->getAnimationState(name);
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
	anim_name = name;

}

/**
*@brief アニメーション初期化の関数
* @param name 名前
*/
void LinkObj::ResetAnimation(const char* name)
{
	
	mAnimationState = mEntity->getAnimationState(name);
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);

	mAnimationState->setTimePosition(mAnimationState->getLength());

}

/**
*@brief アニメーション更新の関数
* @param name 名前
* @param time 時間
*/
void LinkObj::UpdateAnimation(const char* name,float time)
{
	mAnimationState = mEntity->getAnimationState(name);
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);

	mAnimationState->addTime(time);
}


/**
*@brief 影の表示、非表示設定の関数
* @param v trueで表示、falseで非表示
*/
void LinkObj::SetShadows(bool v)
{
	mEntity->setCastShadows(v);
	shadow_visi = v;
}



/**
*@brief バウンディングボックスの大きさ取得の関数
* @param num 0でX軸、1でY軸、2でZ軸方向のサイズを取得
* @return サイズ
*/
float LinkObj::GetBoundingBoxSize(int num)
{
	if(num == 0)
	{
		return mEntity->getBoundingBox().getSize().x;
	}
	else if(num == 1)
	{
		return mEntity->getBoundingBox().getSize().y;
	}
	else
	{
		return mEntity->getBoundingBox().getSize().z;
	}
	
}

/**
*@brief マテリアル設定の関数
* @param name 名前
*/
void LinkObj::SetMaterial(const char* name)
{
	mEntity->setMaterialName(name);
	material_name = name;
	mat_visi = true;

}

/**
*@brief ボーンの位置設定の関数
* @param name 名前
* @param x 位置(X)
* @param y 位置(Y)
* @param z 位置(Z)
*/
void LinkObj::SetBornPosition( const char* name, float x, float y, float z)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->setPosition(x,y,z);
	}
	
}

/**
*@brief ボーンのクオータニオン設定の関数
* @param name 名前
* @param x クオータニオン(W)
* @param x クオータニオン(X)
* @param y クオータニオン(Y)
* @param z クオータニオン(Z)
*/
void LinkObj::SetBornOrientation( const char*name, float w, float x, float y, float z)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->setOrientation(w,x,y,z);
	}
}


/**
*@brief ボーンの拡大率設定の関数
* @param name 名前
* @param sx 拡大率(X)
* @param sy 拡大率(Y)
* @param sz 拡大率(Z)
*/
void LinkObj::SetBornScale( const char*name, float sx, float sy, float sz)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->setScale(sx,sy,sz);
	}
}


/**
*@brief ボーンのロール角設定の関数
* @param name 名前
* @param ang ロール角
*/
void LinkObj::SetBornRoll( const char*name, float ang)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->roll(Ogre::Degree(ang));
	}
}

/**
*@brief ボーンのピッチ角設定の関数
* @param name 名前
* @param ang ピッチ角
*/
void LinkObj::SetBornPitch( const char*name, float ang)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->pitch(Ogre::Degree(ang));
	}
}

/**
*@brief ボーンのヨー角設定の関数
* @param name 番号
* @param ang ヨー角
*/
void LinkObj::SetBornYaw( const char*name, float ang)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->yaw(Ogre::Degree(ang));
	}
}

/**
*@brief ボーンの姿勢設定の関数
* @param name 名前
* @param r ロール
* @param p ピッチ
* @param y ヨー
*/
void LinkObj::SetBornRotation(const char* name, float r, float p, float y)
{
	SetBornOrientation(name,1,0,0,0);
	SetBornRoll(name,r);
	SetBornPitch(name,p);
	SetBornYaw(name,y);
}

/**
*@brief ボーンの位置設定の関数
* @param name 番号
* @param w 位置(X)
* @param y 位置(Y)
* @param z 位置(Z)
*/
void LinkObj::SetBornPosition( int name, float x, float y, float z)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->setPosition(x,y,z);
	
}

/**
*@brief ボーンのクオータニオン設定の関数
* @param name 番号
* @param w クオータニオン(W)
* @param x クオータニオン(X)
* @param y クオータニオン(Y)
* @param z クオータニオン(Z)
*/
void LinkObj::SetBornOrientation( int name, float w, float x, float y, float z)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->setOrientation(w,x,y,z);
}

/**
*@brief ボーンの拡大率設定の関数
* @param name 番号
* @param sx 拡大率(X)
* @param sy 拡大率(Y)
* @param sz 拡大率(Z)
*/
void LinkObj::SetBornScale( int name, float sx, float sy, float sz)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->setScale(sx,sy,sz);
}

/**
*@brief ボーンのロール角設定の関数
* @param name 番号
* @param ang ロール角
*/
void LinkObj::SetBornRoll( int name, float ang)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->roll(Ogre::Degree(ang));
}

/**
*@brief ボーンのピッチ角設定の関数
* @param name 番号
* @param ang ピッチ角
*/
void LinkObj::SetBornPitch( int name, float ang)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->pitch(Ogre::Degree(ang));
}

/**
*@brief ボーンのヨー角設定の関数
* @param name 番号
* @param ang ヨー角
*/
void LinkObj::SetBornYaw( int name, float ang)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->yaw(Ogre::Degree(ang));
}

/**
*@brief ボーンの姿勢設定の関数
* @param name 番号
* @param r ロール
* @param p ピッチ
* @param y ヨー
*/
void LinkObj::SetBornRotation(int name, float r, float p, float y)
{
	SetBornOrientation(name,1,0,0,0);
	SetBornRoll(name,r);
	SetBornPitch(name,p);
	SetBornYaw(name,y);
}

/**
*@brief ボーンの数取得の関数
* @return ボーンの数
*/
int LinkObj::GetBornNum()
{
	Ogre::Skeleton *tmp = mEntity->getSkeleton();
	if(tmp)
	{
		return tmp->getNumBones();
	}
	return 0;
	
}

/**
*@brief ボーンの初期化の関数
*/
void LinkObj::ResetBorn()
{
	mEntity->getSkeleton()->reset(true);
}


/**
*@brief 設定のファイル読み込みの関数
* @param ifs ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool LinkObj::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	filename = ReadString(ifs);

	int NodeNum;
	ifs.read( (char*)&NodeNum, sizeof(NodeNum) );

	for(int i=0;i < NodeNum;i++)
	{
		std::string nn = ReadString(ifs);
		NodeObj *mn = new NodeObj(nn);
		NodeList.push_back(mn);
	}

	mNode->name = ReadString(ifs);

	ifs.read( (char*)&red, sizeof(red) );
	ifs.read( (char*)&green, sizeof(green) );
	ifs.read( (char*)&blue, sizeof(blue) );
	ifs.read( (char*)&alpha, sizeof(alpha) );

	ifs.read( (char*)&color_visi, sizeof(color_visi) );
	ifs.read( (char*)&shadow_visi, sizeof(shadow_visi) );

	//ifs.read( (char*)&visi, sizeof(visi) );
	ifs.read( (char*)&anim_speed, sizeof(anim_speed) );

	anim_name = ReadString(ifs);

	ifs.read( (char*)&anim_start, sizeof(anim_start) );
	//ifs.read( (char*)&bound_visi, sizeof(bound_visi) );

	material_name = ReadString(ifs);
	ifs.read( (char*)&mat_visi, sizeof(mat_visi) );

	return true;
}

/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void LinkObj::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(filename , ofs2 );

	int NodeNum = NodeList.size();
	ofs2.write( (char*)&NodeNum, sizeof(NodeNum) );

	for(int i=0;i < NodeNum;i++)
	{
		WriteString(NodeList[i]->name , ofs2 );
	}

	WriteString(mNode->name , ofs2 );

	ofs2.write( (char*)&red, sizeof(red) );
	ofs2.write( (char*)&green, sizeof(green) );
	ofs2.write( (char*)&blue, sizeof(blue) );
	ofs2.write( (char*)&alpha, sizeof(alpha) );

	ofs2.write( (char*)&color_visi, sizeof(color_visi) );
	ofs2.write( (char*)&shadow_visi, sizeof(shadow_visi) );

	//ofs2.write( (char*)&visi, sizeof(visi) );
	ofs2.write( (char*)&anim_speed, sizeof(anim_speed) );
	WriteString(anim_name , ofs2 );
	
	ofs2.write( (char*)&anim_start, sizeof(anim_start) );
	
	//ofs2.write( (char*)&bound_visi, sizeof(bound_visi) );


	WriteString(material_name , ofs2 );
	ofs2.write( (char*)&mat_visi, sizeof(mat_visi) );

}



