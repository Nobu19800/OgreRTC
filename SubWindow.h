#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include "BaseApplication.h"
#include <CEGUI.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>



#include "MyFileStream.h"


/*
*�T�u�E�C���h�E�̃N���X
*/


class SubWindow
{
public:
	SubWindow();
	/*
	*�ʒu�ݒ�̊֐�
	*/
	void SetPosition( float x, float y);
	/*
	*�傫���ݒ�̊֐�
	*/
	void SetSize( float sx, float sy);
	/*
	*�J�����̎p���ݒ�̊֐�
	*/
	void SetCameraRoll( float ang);
	void SetCameraPitch( float ang);
	void SetCameraYaw( float ang);
	void SetCameraQuaternion(float w, float x, float y, float z);
	void SetCameraRotation(float r, float p, float y);
	/*
	*�J�����̈ʒu�ݒ�̊֐�
	*/
	void SetCameraPosition( float x, float y, float z);
	/*
	*�J�����̈ʒu�A�p���A�����ݒ�̊֐�
	*/
	void UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len);
	/*
	*�\���A��\���ݒ�̊֐�
	*/
	void SetVisible( bool v);

	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	bool openb(std::ifstream &ifs);


	Ogre::Camera *cam;
	Ogre::Viewport *v;
	Ogre::RenderTexture *rtex;
	Ogre::TexturePtr tex;
	CEGUI::Window *label;
	CEGUI::Texture *guiTex;
	CEGUI::Imageset *imageSet;

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