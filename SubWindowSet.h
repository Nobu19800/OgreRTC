#ifndef SUBWINDOWSET_H
#define SUBWINDOWSET_H

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
* ��ʕ����ݒ�p�E�B�W�F�b�g
*/

class SubWindowSetWidget : public QWidget
{
	Q_OBJECT

public:
	SubWindowSetWidget(QWidget *parent = 0);
	~SubWindowSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/*
	*�T�u�E�C���h�E�̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
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
	*�傫���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	/*
	*�\���A��\���ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void VisibleSlot();
	void unVisibleSlot();
	/*
	*�폜�{�^�����������Ƃ��̃X���b�g
	*/
	void DestroySlot();

	/*
	*�J�����̈ʒu�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void CameraPosXSlot(double value);
	void CameraPosYSlot(double value);
	void CameraPosZSlot(double value);
	/*
	*�J�����̎p���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void CameraRollSlot(double value);
	void CameraPitchSlot(double value);
	void CameraYawSlot(double value);
	/*
	*�J�����̋����ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void CameraLenSlot(double value);
	/*
	*���Z�b�g�{�^�����������Ƃ��̃X���b�g
	*/
	void RestartSlot();
	
	void StopSlot();

	/*
	*���O�R���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
	*/
	void NameSlot(int value);
	



private:
	bool up_flag;
	/*
	* �ʒu�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdatePos();
	/*
	* �傫���ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateSize();
	void UpdateCameraPos();
	void UpdateCameraRot();
	/*
	* �J�����̈ʒu�A�p���A�����ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateCameraPQ();
	/*
	* �\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateVisi(bool visi);

	QTextCodec* tc;
	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *CameraPosXspinBox;
	QDoubleSpinBox *CameraPosYspinBox;
	QDoubleSpinBox *CameraPosZspinBox;
	QDoubleSpinBox *CameraRollspinBox;
	QDoubleSpinBox *CameraPitchspinBox;
	QDoubleSpinBox *CameraYawspinBox;
	QDoubleSpinBox *CameraLenspinBox;
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QPushButton *DestroyButton;
	QPushButton *RestartButton;
	QPushButton *StopButton;
	
	




	



protected:
	




};

#endif