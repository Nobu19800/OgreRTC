/*!
 * @file  SubWindow.h
 * @brief サブウインドウ設定用ウィンドウ
 *
 */

#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include "BaseApplication.h"
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>



#include "FileStreamFunc.h"



/**
 * @class SubWindow
*@brief サブウインドウのクラス
*/

class SubWindow
{
public:
	/**
	*@brief コンストラクタ
	*/
	SubWindow();
	
	/**
	*@brief 位置設定の関数
	* @param x 位置(X)
	* @param y 位置(Y)
	*/
	void SetPosition( float x, float y);
	/**
	*@brief 大きさ設定の関数
	* @param sx サイズ(X)
	* @param sy サイズ(Y)
	*/
	void SetSize( float sx, float sy);
	
	/**
	*@brief カメラの姿勢(ロール角)設定の関数
	* @param ang 角度(ロール)
	*/
	void SetCameraRoll( float ang);
	/**
	*@brief カメラの姿勢(ピッチ角)設定の関数
	* @param ang 角度(ピッチ)
	*/
	void SetCameraPitch( float ang);
	/**
	*@brief カメラの姿勢(ヨー角)設定の関数
	* @param ang 角度(ヨー)
	*/
	void SetCameraYaw( float ang);
	/**
	*@brief カメラの姿勢(クォータニオン)設定の関数
	* @param w クォータニオン(W)
	* @param x クォータニオン(X)
	* @param y クォータニオン(Y)
	* @param z クォータニオン(Z)
	*/
	void SetCameraQuaternion(float w, float x, float y, float z);
	/**
	*@brief カメラの姿勢設定の関数
	* @param r 角度(ロール)
	* @param p 角度(ピッチ)
	* @param y 角度(ヨー)
	*/
	void SetCameraRotation(float r, float p, float y);
	
	/**
	*@brief カメラの位置設定の関数
	* @param x 位置(X)
	* @param y 位置(Y)
	* @param z 位置(Z)
	*/
	void SetCameraPosition( float x, float y, float z);
	
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
	void UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len);
	
	/**
	*@brief 表示、非表示設定の関数
	* @param v trueで表示、falseで非表示
	*/
	void SetVisible( bool v);

	/**
	*@brief 設定のファイル保存の関数
	* @param ofs2 ファイルストリーム
	*/
	void save(std::ofstream &ofs2);
	/**
	*@brief 設定のファイル読み込みの関数
	* @param ifs ファイルストリーム
	* @return trueで成功、falseで失敗
	*/
	bool openb(std::ifstream &ifs);


	Ogre::Camera *cam;
	Ogre::Viewport *v;
	Ogre::RenderTexture *rtex;
	Ogre::TexturePtr tex;
	CEGUI::Window *label;
	CEGUI::Texture *guiTex;
	CEGUI::BasicImage *Image;

	std::string Iname;
	std::string Cname;
	std::string Wname;
	std::string ISname;
	std::string Tname;

	float pos_x, pos_y;
	float size_x, size_y;
	float campos_x, campos_y, campos_z;
	float cam_roll, cam_pitch, cam_yaw;
	float cam_len;
	bool visi;


};


#endif