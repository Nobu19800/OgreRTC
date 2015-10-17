/*!
 * @file  AnimationObj.cpp
 * @brief アニメーション関連のクラス
 *
 */

#include "AnimationObj.h"
#include "OgreMacro.h"


/**
*@brief アニメーションのキーのクラスのコンストラクタ
*/
AnimationObjList::AnimationObjList()
{
	mtime = 0;

	trans_flag = false;
	rot_flag = false;
}


/**
*@brief 平行移動のキーを設定
* @param x X座標
* @param y Y座標
* @param z Z座標
*/
void AnimationObjList::setTranslate(float x, float y, float z)
{
	
	kf->setTranslate(Ogre::Vector3(x,y,z));
	px = x;
	py = y;
	pz = z;
	trans_flag = true;
	
}


/**
*@brief 回転移動のキーを設定
* @param r ロール
* @param p ピッチ
* @param y ヨー
*/
void AnimationObjList::setRotation(float r, float p, float y)
{
	Ogre::Quaternion q = GetRotQuat(r,p,y);
	kf->setRotation(q);
	roll = r;
	pitch = p;
	yaw = y;
	rot_flag = true;
	
}



/**
*@brief アニメーションの各種設定を行うクラスのコンストラクタ
* @param n 名前
*/
AnimationObj::AnimationObj(std::string n)
{
	std::string nn = n + "Animation";
	mNode = new NodeObj(nn);
	type = 3;
	name = n;
}

/**
*@brief キーフレームの追加の関数
* @param t 時間
* @return 追加したキーフレーム
*/
AnimationObjList *AnimationObj::AddKeyFrame(float t)
{
	
	AnimationObjList *mal = new AnimationObjList();
	mal->kf = track->createNodeKeyFrame(t);
	mal->mtime = t;

	animList.push_back(mal);

	return mal;
	
}

/**
*@brief キーフレームの削除の関数
* @param mal 削除するキーフレーム
*/
void AnimationObj::RemoveKeyFrame(AnimationObjList *mal)
{
	
	std::vector<AnimationObjList*>::iterator end_it = remove( animList.begin(), animList.end(), mal );
	animList.erase( end_it, animList.end() );
	track->removeAllKeyFrames();
	for(int i=0;i < animList.size();i++)
	{
		animList[i]->kf = track->createNodeKeyFrame(animList[i]->mtime);
		if(animList[i]->trans_flag)
		{
			animList[i]->setTranslate(animList[i]->px,animList[i]->py,animList[i]->pz);
		}
		if(animList[i]->rot_flag)
		{
			animList[i]->setTranslate(animList[i]->roll,animList[i]->pitch,animList[i]->yaw);
		}
	}
	
}


/**
*@brief アニメーションの時間設定の関数
* @param t 時間
*/
void AnimationObj::SetAnimationState(float t)
{
	mstate->setTimePosition(t);
}



/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void AnimationObj::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(mNode->name , ofs2 );

	ofs2.write( (char*)&Time, sizeof(Time) );

	int anl = animList.size();
	ofs2.write( (char*)&anl, sizeof(anl) );

	for(int i=0;i < anl;i++)
	{
		ofs2.write( (char*)&animList[i]->mtime, sizeof(animList[i]->mtime) );
		ofs2.write( (char*)&animList[i]->trans_flag, sizeof(animList[i]->trans_flag) );
		ofs2.write( (char*)&animList[i]->px, sizeof(animList[i]->px) );
		ofs2.write( (char*)&animList[i]->py, sizeof(animList[i]->py) );
		ofs2.write( (char*)&animList[i]->pz, sizeof(animList[i]->pz) );
		ofs2.write( (char*)&animList[i]->rot_flag, sizeof(animList[i]->rot_flag) );
		ofs2.write( (char*)&animList[i]->roll, sizeof(animList[i]->roll) );
		ofs2.write( (char*)&animList[i]->pitch, sizeof(animList[i]->pitch) );
		ofs2.write( (char*)&animList[i]->yaw, sizeof(animList[i]->yaw) );
	}
}


/**
*@brief 設定のファイル読み込みの関数
* @param ofs2 ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool AnimationObj::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	mNode->name = ReadString(ifs);


	ifs.read( (char*)&Time, sizeof(Time) );

	int anl;
	ifs.read( (char*)&anl, sizeof(anl) );

	for(int i=0;i < anl;i++)
	{
		AnimationObjList *mal = new AnimationObjList();
		ifs.read( (char*)&mal->mtime, sizeof(mal->mtime) );
		ifs.read( (char*)&mal->trans_flag, sizeof(mal->trans_flag) );
		ifs.read( (char*)&mal->px, sizeof(mal->px) );
		ifs.read( (char*)&mal->py, sizeof(mal->py) );
		ifs.read( (char*)&mal->pz, sizeof(mal->pz) );
		
		ifs.read( (char*)&mal->rot_flag, sizeof(mal->rot_flag) );
		ifs.read( (char*)&mal->roll, sizeof(mal->roll) );
		ifs.read( (char*)&mal->pitch, sizeof(mal->pitch) );
		ifs.read( (char*)&mal->yaw, sizeof(mal->yaw) );
		

		animList.push_back(mal);
	}

	return true;
}


/**
*@brief アニメーションの終了時間設定の関数
* @param t 時間
*/
void AnimationObj::SetLength(float t)
{
	anim->setLength(t);
	Time = t;
}