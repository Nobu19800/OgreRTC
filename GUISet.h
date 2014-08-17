#ifndef GUISET_H
#define GUISET_H

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
* GUI�쐬�A�ݒ�p�E�B�W�F�b�g
*/

class GUISetWidget : public QWidget
{
	Q_OBJECT

public:
	GUISetWidget(QWidget *parent = 0);
	~GUISetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	* GUI���쐬�A�폜�����Ƃ��̃V�O�i��
	*/
	void UpdateGUI();

public slots:
	/*
	*GUI�̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();

private slots:
	/*
	*�쐬�{�^�����������Ƃ��̃X���b�g
	*/
	void SetSlot();
	/*
	*�ʒu�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	/*
	*�p���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*�傫���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	/*
	*�����x�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void AlphaSlot(double value);
	/*
	*�\���A��\���ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void VisibleSlot();
	void unVisibleSlot();
	/*
	*�t���[���̕\���A��\���ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void FrameSlot();
	void unFrameSlot();
	/*
	*�w�i�̕\���A��\���ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void BackGroundSlot();
	void unBackGroundSlot();
	/*
	*�폜�{�^�����������Ƃ��̃X���b�g
	*/
	void DestroySlot();
	/*
	*���O�R���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
	*/
	void NameSlot(int value);
	/*
	*�E�B���h�E�ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void WindowSlot();


private:
	bool up_flag;
	/*
	* �ʒu�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdatePos();
	/*
	* �p���ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateRot();
	/*
	* �傫���ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateSize();
	/*
	* �\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateVisi(bool visi);
	/*
	* �t���[���̕\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateFrame(bool visi);
	/*
	* �w�i�̕\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateBackGround(bool visi);


	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *AlphaspinBox;
	
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QPushButton *FrameButton;
	QPushButton *unFrameButton;
	QPushButton *BackGroundButton;
	QPushButton *unBackGroundButton;
	
	QPushButton *DestroyButton;

	QComboBox *TypeBox;

	QComboBox *WindowBox;
	QPushButton *WindowButton;
	

	QTextCodec* tc;

	



protected:
	




};

#endif