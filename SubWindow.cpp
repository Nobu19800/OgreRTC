/*!
 * @file  SubWindow.cpp
 * @brief サブウインドウ設定用ウィンドウ
 *
 */

#include "SubWindow.h"
#include "OgreMacro.h"



/**
*@brief サブウインドウのクラスのコンストラクタ
*/
SubWindow::SubWindow()
{

	pos_x = 0;
	pos_y = 0;
	size_x = 1;
	size_y = 1;
	campos_x = 0;
	campos_y = 0;
	campos_z = 0;
	cam_roll = 0;
	cam_pitch = 0;
	cam_yaw = 0;
	cam_len = 0;
	visi = true;
}


/**
*@brief 位置設定の関数
* @param x 位置(X)
* @param y 位置(Y)
*/
void SubWindow::SetPosition( float x, float y)
{
	label->setPosition(CEGUI::UVector2(CEGUI::UDim(x, 0),CEGUI::UDim(y, 0)));
	pos_x = x;
	pos_y = y;
}

/**
*@brief 大きさ設定の関数
* @param sx サイズ(X)
* @param sy サイズ(Y)
*/
void SubWindow::SetSize( float sx, float sy)
{
	label->setSize(CEGUI::USize(CEGUI::UDim(sx, 0), CEGUI::UDim(sy, 0)));
	size_x = sx;
	size_y = sy;
}

/**
*@brief カメラの姿勢(ロール角)設定の関数
* @param ang 角度(ロール)
*/
void SubWindow::SetCameraRoll( float ang)
{
	cam->roll(Ogre::Degree(ang));
	cam_roll = ang;
}

/**
*@brief カメラの姿勢(ピッチ角)設定の関数
* @param ang 角度(ピッチ)
*/
void SubWindow::SetCameraPitch( float ang)
{
	cam->pitch(Ogre::Degree(ang));
	cam_pitch = ang;
}

/**
*@brief カメラの姿勢(ヨー角)設定の関数
* @param ang 角度(ヨー)
*/
void SubWindow::SetCameraYaw( float ang)
{
	cam->yaw(Ogre::Degree(ang));
	cam_yaw = ang;
}

/**
*@brief カメラの姿勢設定の関数
* @param r 角度(ロール)
* @param p 角度(ピッチ)
* @param y 角度(ヨー)
*/
void SubWindow::SetCameraRotation(float r, float p, float y)
{
	SetCameraQuaternion(1,0,0,0);
	SetCameraRoll(r);
	SetCameraPitch(p);
	SetCameraYaw(y);
}

/**
*@brief カメラの位置設定の関数
* @param x 位置(X)
* @param y 位置(Y)
* @param z 位置(Z)
*/
void SubWindow::SetCameraPosition( float x, float y, float z)
{
	cam->setPosition(x, y, z);
	campos_x = x;
	campos_y = y;
	campos_z = z;
}

/**
*@brief カメラの姿勢(クォータニオン)設定の関数
* @param w クォータニオン(W)
* @param x クォータニオン(X)
* @param y クォータニオン(Y)
* @param z クォータニオン(Z)
*/
void SubWindow::SetCameraQuaternion(float w, float x, float y, float z)
{
	cam->setOrientation(Ogre::Quaternion(w,x,y,z));

}

/**
*@brief 表示、非表示設定の関数
* @param v trueで表示、falseで非表示
*/
void SubWindow::SetVisible(bool v)
{
	label->setVisible(v);
	visi = v;
}


/**
*@brief カメラの位置、姿勢、距離設定の関数
* @param px 位置(X)
* @param py 位置(Y)
* @param pz 位置(Z)
* @param roll 角度(ロール)
* @param pitch 角度(ピッチ)
* @param yaw 角度(ヨー)
* @param len 距離
*/
void SubWindow::UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len)
{


	Ogre::Quaternion tRot = GetRotQuat(roll, pitch, yaw);

	Ogre::Vector3 tLen(0,0,len);
	tLen = tRot * tLen;

	SetCameraPosition(px+tLen.x, py+tLen.y, pz+tLen.z);
	SetCameraQuaternion(tRot.w,tRot.x,tRot.y,tRot.z);

	campos_x = px;
	campos_y = py;
	campos_z = pz;

	cam_roll = roll;
	cam_pitch = pitch;
	cam_yaw = yaw;

	cam_len = len;
}


/**
*@brief 設定のファイル読み込みの関数
* @param ifs ファイルストリーム
* @return trueで成功、falseで失敗
*/
bool SubWindow::openb(std::ifstream &ifs)
{
	Iname = ReadString(ifs);
	Cname = ReadString(ifs);
	Wname = ReadString(ifs);
	ISname = ReadString(ifs);
	Tname = ReadString(ifs);

	ifs.read( (char*)&pos_x, sizeof(pos_x) );
	ifs.read( (char*)&pos_y, sizeof(pos_y) );

	ifs.read( (char*)&size_x, sizeof(size_x) );
	ifs.read( (char*)&size_y, sizeof(size_y) );

	ifs.read( (char*)&campos_x, sizeof(campos_x) );
	ifs.read( (char*)&campos_y, sizeof(campos_y) );
	ifs.read( (char*)&campos_z, sizeof(campos_z) );


	ifs.read( (char*)&cam_roll, sizeof(cam_roll) );
	ifs.read( (char*)&cam_pitch, sizeof(cam_pitch) );
	ifs.read( (char*)&cam_yaw, sizeof(cam_yaw) );

	ifs.read( (char*)&visi, sizeof(visi) );



	return true;
}

/**
*@brief 設定のファイル保存の関数
* @param ofs2 ファイルストリーム
*/
void SubWindow::save(std::ofstream &ofs2)
{
	WriteString(Iname , ofs2 );
	WriteString(Cname , ofs2 );
	WriteString(Wname , ofs2 );
	WriteString(ISname , ofs2 );
	WriteString(Tname , ofs2 );

	ofs2.write( (char*)&pos_x, sizeof(pos_x) );
	ofs2.write( (char*)&pos_y, sizeof(pos_y) );

	ofs2.write( (char*)&size_x, sizeof(size_x) );
	ofs2.write( (char*)&size_y, sizeof(size_y) );

	ofs2.write( (char*)&campos_x, sizeof(campos_x) );
	ofs2.write( (char*)&campos_y, sizeof(campos_y) );
	ofs2.write( (char*)&campos_z, sizeof(campos_z) );

	ofs2.write( (char*)&cam_roll, sizeof(cam_roll) );
	ofs2.write( (char*)&cam_pitch, sizeof(cam_pitch) );
	ofs2.write( (char*)&cam_yaw, sizeof(cam_yaw) );

	ofs2.write( (char*)&visi, sizeof(visi) );

	
}