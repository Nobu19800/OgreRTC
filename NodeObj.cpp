/*!
 * @file  NodeObj.cpp
 * @brief 3Dモデルのベースとなるクラス
 *
 */

#include "NodeObj.h"
#include "OgreMacro.h"


/**
*@brief 3Dモデルのベースとなるクラスのコンストラクタ
*/
ObjectBase::ObjectBase()
{

}

/**
*@brief 位置設定の関数
* @param x 位置(X)
* @param y 位置(Y)
* @param z 位置(Z)
*/
void ObjectBase::SetPosition(float x,float y,float z)
{
	mNode->mNode->setPosition(Ogre::Vector3(x,y,z));
	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->setPosition(Ogre::Vector3(x,y,z));
	}
	mNode->pos_x = x;
	mNode->pos_y = y;
	mNode->pos_z = z;
}

/**
*@brief 拡大率設定の関数
* @param sx 拡大率(X)
* @param sy 拡大率(Y)
* @param sz 拡大率(Z)
*/
void ObjectBase::SetScale(float sx,float sy,float sz)
{
	mNode->mNode->setScale(Ogre::Vector3(sx,sy,sz));
	mNode->scale_x = sx;
	mNode->scale_y = sy;
	mNode->scale_z = sz;
}

/**
*@brief クオータニオン設定の関数
* @param w クオータニオン(W)
* @param x クオータニオン(X)
* @param y クオータニオン(Y)
* @param z クオータニオン(Z)
*/
void ObjectBase::SetQuaternion(float w, float x, float y, float z)
{
	mNode->mNode->setOrientation(Ogre::Quaternion(w,x,y,z));
	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->setOrientation(Ogre::Quaternion(w,x,y,z));
	}
}



/**
*@brief ロール角設定の関数
* @param ang ロール角
*/
void ObjectBase::Roll(float ang)
{
	mNode->mNode->roll(Ogre::Degree(ang));
	mNode->roll = ang;

	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->roll(Ogre::Degree(ang));
	}
	
}

/**
*@brief ピッチ角設定の関数
* @param ang ピッチ角
*/
void ObjectBase::Pitch(float ang)
{
	mNode->mNode->pitch(Ogre::Degree(ang));
	mNode->pitch = ang;
	
	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->pitch(Ogre::Degree(ang));
	}
}

/**
*@brief ヨー角設定の関数
* @param ang ヨー角
*/
void ObjectBase::Yaw(float ang)
{
	mNode->mNode->yaw(Ogre::Degree(ang));
	mNode->yaw = ang;

	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->yaw(Ogre::Degree(ang));
	}
}

/**
*@brief 姿勢設定の関数
* @param r ロール
* @param p ピッチ
* @param y ヨー
*/
void ObjectBase::SetRotation(float r, float p, float y)
{
	SetQuaternion(1,0,0,0);
	Roll(r);
	Pitch(p);
	Yaw(y);

	
}

/**
*@brief 表示、非表示設定の関数
* @param v trueで表示、falseで非表示
*/
void ObjectBase::SetVisible(bool v)
{
	mNode->mNode->setVisible(v);
	mNode->visi = v;
}

/**
*@brief バウンディングボックスの表示、非表示設定の関数
* @param v trueで表示、falseで非表示
*/
void ObjectBase::BoundingBoxVisible(bool v)
{
	
	mNode->mNode->showBoundingBox(v);
	mNode->mNode->hideBoundingBox(!v);

	mNode->bound_visi = v;
	
}

/**
*@brief マウスの位置に対する位置更新の関数
* @param dx 移動量(X)
* @param dy 移動量(Y)
* @param dz 移動量(Z)
* @param CamRoll 姿勢(ロール)
* @param CamPitch 姿勢(ピッチ)
* @param CamYaw 姿勢(ヨー)
*/
void ObjectBase::UpdatePos(float dx, float dy, float dz, float CamRoll, float CamPitch, float CamYaw)
{
	Ogre::Quaternion tRot = GetRotQuat(CamRoll, CamPitch, CamYaw);

	
	
	Ogre::Vector3 dp(dx,dy,dz);
	dp = tRot * dp;

	mNode->pos_x = mNode->pos_x + dp.x;
	mNode->pos_y = mNode->pos_y + dp.y;
	mNode->pos_z = mNode->pos_z + dp.z;


	SetPosition(mNode->pos_x, mNode->pos_y, mNode->pos_z);
}

/**
*@brief マウスの位置に対する姿勢更新の関数
* @param dx 移動量(X)
* @param dy 移動量(Y)
* @param dz 移動量(Z)
* @param CamRoll 姿勢(ロール)
* @param CamPitch 姿勢(ピッチ)
* @param CamYaw 姿勢(ヨー)
*/
void ObjectBase::UpdateRot(float dx, float dy, float CamRoll, float CamPitch, float CamYaw)
{
	Ogre::Quaternion tRot = GetRotQuat(CamRoll, CamPitch, CamYaw);
	
	Ogre::Vector3 dx_Axis = tRot * Ogre::Vector3(0,1,0);
	Ogre::Vector3 dy_Axis = tRot * Ogre::Vector3(1,0,0);
	Ogre::Quaternion tdxRot;
	tdxRot.FromAngleAxis(Ogre::Degree(dx),dx_Axis);
	Ogre::Quaternion tdyRot;
	tdyRot.FromAngleAxis(Ogre::Degree(dy),dy_Axis);
	
	tdxRot = tdyRot* tdxRot;
	
	mNode->roll = mNode->roll + tdxRot.getRoll().valueDegrees();
	mNode->pitch = mNode->pitch + tdxRot.getPitch().valueDegrees();
	mNode->yaw = mNode->yaw + tdxRot.getYaw().valueDegrees();



	
	SetRotation(mNode->roll, mNode->pitch, mNode->yaw);
}



/**
*@brief ノードのクラスのコンストラクタ
*/
NodeObj::NodeObj(std::string n)
{
	name = n;
	

	pos_x = 0;
	pos_y = 0;
	pos_z = 0;
	
	scale_x = 1;
	scale_y = 1;
	scale_z = 1;

	roll = 0;
	pitch = 0;
	yaw = 0;

	

	visi = true;
	bound_visi = false;
	

}


/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void NodeObj::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	//std::cout << name << std::endl;

	ofs2.write( (char*)&scale_x, sizeof(scale_x) );
	ofs2.write( (char*)&scale_y, sizeof(scale_y) );
	ofs2.write( (char*)&scale_z, sizeof(scale_z) );

	ofs2.write( (char*)&pos_x, sizeof(pos_x) );
	ofs2.write( (char*)&pos_y, sizeof(pos_y) );
	ofs2.write( (char*)&pos_z, sizeof(pos_z) );

	ofs2.write( (char*)&roll, sizeof(roll) );
	ofs2.write( (char*)&pitch, sizeof(pitch) );
	ofs2.write( (char*)&yaw, sizeof(yaw) );
}

/**
*@brief 設定のファイル読み込みの関数
* @param ifs ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool NodeObj::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	ifs.read( (char*)&scale_x, sizeof(scale_x) );
	ifs.read( (char*)&scale_y, sizeof(scale_y) );
	ifs.read( (char*)&scale_z, sizeof(scale_z) );

	ifs.read( (char*)&pos_x, sizeof(pos_x) );
	ifs.read( (char*)&pos_y, sizeof(pos_y) );
	ifs.read( (char*)&pos_z, sizeof(pos_z) );

	ifs.read( (char*)&roll, sizeof(roll) );
	ifs.read( (char*)&pitch, sizeof(pitch) );
	ifs.read( (char*)&yaw, sizeof(yaw) );

	return true;
}

/**
*@brief オブジェクト追加の関数
* @param mo オブジェクト
*/
void NodeObj::AddObj(ObjectBase *mo)
{
	mobj.push_back(mo);
}

/**
*@brief オブジェクト削除の関数
* @param mo オブジェクト
*/
void NodeObj::RemoveObj(ObjectBase *mo)
{
	
	std::vector<ObjectBase*>::iterator end_it = remove( mobj.begin(), mobj.end(), mo );
	mobj.erase( end_it, mobj.end() );
}