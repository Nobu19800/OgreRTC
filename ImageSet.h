#ifndef IMAGESET_H
#define IMAGESET_H

#include <QtGui>
#include "OgreRTCApplication.h"


QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
class QTextEdit;
class QLineEdit;
class QTreeView;
class QLabel;
class QStandardItemModel;
class QCheckBox;
class QGridLayout;
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
class Compiler;
class QTextCursor;
class QTreeWidget;
class QComboBox;
QT_END_NAMESPACE


/*
* GUI�̉摜�쐬�A�ݒ�p�E�B�W�F�b�g
*/

class ImageSetWidget : public QWidget
{
	Q_OBJECT

public:
	ImageSetWidget(QWidget *parent = 0);
	~ImageSetWidget(void);

	OgreRTCApplication *EC;



public slots:
	/*
	*�摜�̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();
	/*
	*GUI���ǉ��A�폜���ꂽ���̃X���b�g
	*/
	void UpdateGUI();

private slots:
	/*
	*�쐬�{�^�����������Ƃ��̃X���b�g
	*/
	void SetSlot();
	/*
	*�폜�{�^�����������Ƃ��̃X���b�g
	*/
	void DestroySlot();
	/*
	*GUI�̖��O�R���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
	*/
	void NameSlot(int value);
	/*
	*GUI�̉摜�ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void SetGUISlot();


private:
	

	QTextCodec* tc;
	QComboBox *NameEdit;
	QComboBox *FileNameEdit;
	QPushButton *SetButton;
	QPushButton *DestroyButton;

	QComboBox *GUIBox;
	QComboBox *INameEdit;
	QPushButton *SetGUIButton;



	



protected:
	




};

#endif