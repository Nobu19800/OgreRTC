#ifndef MYGUI_H
#define MYGUI_H

#include <CEGUI.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>

#include "MyImageSet.h"
#include "MyFileStream.h"


/*
* GUI�̃N���X
*/

class MyGUI
{
public:
	MyGUI();
	/*
	*�F�̕ύX
	*/
	void setColor(float r, float g, float b);
	/*
	*�擪�̃E�C���h�E�ɂ���֐�
	*/
	void moveToFront();
	/*
	*�Ō���̃E�C���h�E�ɂ���֐�
	*/
	void moveToBack();
	/*
	*�E�C���h�E��O�Ɉړ�����֐�
	*/
	void moveInFront(MyGUI *mg);
	/*
	*�E�C���h�E�����Ɉړ�����֐�
	*/
	void moveBehind(MyGUI *mg);
	/*
	*�ʒu�ݒ�̊֐�
	*/
	void SetPosition( float x, float y);
	/*
	*�傫���ݒ�̊֐�
	*/
	void SetSize( float sx, float sy);
	/*
	*�e�L�X�g�ݒ�̊֐�
	*/
	void SetText( const char* t);
	/*
	*�\���A��\���ݒ�̊֐�
	*/
	void SetVisible( bool v);
	/*
	*�t���[���̕\���A��\���ݒ�̊֐�
	*/
	void SetFrameEnable( bool v);
	/*
	*�w�i�̕\���A��\���ݒ�̊֐�
	*/
	void SetBackGroundEnable( bool v);
	/*
	*�t�H���g�T�C�Y�ݒ�̊֐�
	*/
	void SetFontSize( int Size);
	/*
	*�e�L�X�g�擾�̊֐�
	*/
	std::string GetText();
	/*
	*�R���{�{�b�N�X�̃A�C�e���擾�̊֐�
	*/
	std::string GetComboBoxItem();
	/*
	*�X���C�_�[�̒l�擾�̊֐�
	*/
	float GetSliderValue();
	/*
	*�X���C�_�[�̒l�ݒ�̊֐�
	*/
	void SetSliderValue( float val);
	/*
	*�R���{�{�b�N�X�̃A�C�e���ǉ��̊֐�
	*/
	void AddComboBoxItem(const char *t);
	/*
	*�e�L�X�g�̐F�ݒ�̊֐�
	*/
	void SetTextColor(float r, float g, float b);
	/*
	*�����x�ݒ�̊֐�
	*/
	void SetAlpha( float val);
	/*
	*�p���ݒ�̊֐�
	*/
	void SetRotatin( float r, float p, float y);
	/*
	*�摜�ݒ�̊֐�
	*/
	void SetImage(MyImageSet *MIS, const char *n);


	/*
	*�E�C���h�E�ݒ�̊֐�
	*/
	void SetWindow(MyGUI *mg);
	/*
	*�R���{�{�b�N�X�̃A�C�e���폜�̊֐�
	*/
	void RemoveComboBoxItem(int index);
	/*
	*���X�g�{�b�N�X�̃A�C�e���ǉ��̊֐�
	*/
	void AddListBoxItem(const char *t);
	/*
	*���X�g�{�b�N�X�̃A�C�e���폜�̊֐�
	*/
	void RemoveListBoxItem(int index);
	/*
	*�}���`�R�������X�g�̍s�ǉ��̊֐�
	*/
	void AddMultiColumnRow();
	/*
	*�}���`�R�������X�g�̍s�폜�̊֐�
	*/
	void RemoveMultiColumnRow(int index);
	/*
	*�}���`�R�������X�g�̗�폜�̊֐�
	*/
	void RemoveMultiColumnCol(int index);
	/*
	*�}���`�R�������X�g�̃A�C�e���ݒ�̊֐�
	*/
	void AddMultiColumnItem(const char *t, int row, int col);
	/*
	*�v���O���X�o�[�̒l�ݒ�̊֐�
	*/
	void SetProgressBarValue(float val);
	/*
	*�X�N���[���o�[�̒l�擾�̊֐�
	*/
	float GetScrollValue();
	/*
	*�X�N���[���o�[�̒l�ݒ�̊֐�
	*/
	void SetScrollValue( float val);
	/*
	*�`�F�b�N�{�b�N�X�̃`�F�b�N�ݒ�̊֐�
	*/
	void SetCheckBox(bool val);
	/*
	*�`�F�b�N�{�b�N�X�̃`�F�b�N�擾�̊֐�
	*/
	bool GetCheckBox();




	/*
	*�e�L�X�g�̈ʒu�ݒ�̊֐�
	*/
	void SetTextTopAligned();
	void SetTextBottomAligned();
	void SetTextVertCentred();
	void SetTextWordWrapLeftAligned();
	void SetTextWordWrapRightAligned();
	void SetTextWordWrapCentred();
	void SetTextLeftAligned();
	void SetTextRightAligned();
	void SetTextHorzCentred();
	/*
	*�ݒ菉�����̊֐�
	*/
	void ClearProperties();

	/*
	*�ݒ�̃t�@�C���ۑ��̊֐�
	*/
	void save(std::ofstream &ofs2);
	/*
	*�ݒ�̃t�@�C���ǂݍ��݂̊֐�
	*/
	bool openb(std::ifstream &ifs);

	CEGUI::Window *window;
	std::string name;
	float pos_x, pos_y;
	float size_x, size_y;
	float roll, pitch, yaw;
	std::string text;
	bool frame_visi;
	bool bg_visi;
	int font_size;
	std::string type;
	bool image_set;
	std::string image_name;
	float alpha;
	int text_type;
	bool visi;
	
	

};

#endif