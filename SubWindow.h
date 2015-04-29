#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include "BaseApplication.h"
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>



#include "MyFileStream.h"


/*
*サブウインドウのクラス
*/


class SubWindow
{
public:
	SubWindow();
	/*
	*位置設定の関数
	*/
	void SetPosition( float x, float y);
	/*
	*大きさ設定の関数
	*/
	void SetSize( float sx, float sy);
	/*
	*カメラの姿勢設定の関数
	*/
	void SetCameraRoll( float ang);
	void SetCameraPitch( float ang);
	void SetCameraYaw( float ang);
	void SetCameraQuaternion(float w, float x, float y, float z);
	void SetCameraRotation(float r, float p, float y);
	/*
	*カメラの位置設定の関数
	*/
	void SetCameraPosition( float x, float y, float z);
	/*
	*カメラの位置、姿勢、距離設定の関数
	*/
	void UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len);
	/*
	*表示、非表示設定の関数
	*/
	void SetVisible( bool v);

	/*
	*設定のファイル保存の関数
	*/
	void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
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