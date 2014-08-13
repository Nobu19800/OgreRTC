#ifndef SIMBODYSET_H
#define SIMBODYSET_H

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
class QLayout;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
class Compiler;
class QTextCursor;
class QTreeWidget;
class QDoubleSpinBox;
class QComboBox;
QT_END_NAMESPACE

/*
* �V�~�����[�V�����̃{�f�B�쐬�A�ݒ�p�E�B�W�F�b�g
*/

class SimBodySetWidget : public QWidget
{
	Q_OBJECT

public:
	SimBodySetWidget(QWidget *parent = 0);
	~SimBodySetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	* �{�f�B���쐬�A�폜�����Ƃ��̃V�O�i��
	*/
	void UpdateODEBody();

public slots:
	/*
	*�{�f�B�̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();
	

private slots:
	/*
	*�쐬�{�^�����������Ƃ��̃X���b�g
	*/
	void SetSlot();
	/*
	*���O�R���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
	*/
	void NameSlot(int value);
	/*
	*�ʒu�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	void PosZSlot(double value);
	/*
	*�傫���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void SizeXSlot(double value);
	void SizeYSlot(double value);
	void SizeZSlot(double value);
	void SizeRSlot(double value);
	/*
	*3D���f���ƃ{�f�B�̊g�嗦�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);
	/*
	*3D���f���ƃ{�f�B�̃I�t�Z�b�g�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void OffsetXSlot(double value);
	void OffsetYSlot(double value);
	void OffsetZSlot(double value);
	/*
	*�p���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*���ʐݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void MassSlot(double value);
	/*
	*�\���A��\���ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void VisibleSlot();
	void unVisibleSlot();

	/*
	*�폜�{�^�����������Ƃ��̃X���b�g
	*/
	void DestroySlot();

	

	

private:
	
	
	/*
	* �ʒu�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void SetPos();
	/*
	* �傫���ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void SetSize();
	/*
	* �g�嗦�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void SetScale();
	/*
	* �p���ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void SetRot();
	/*
	* �I�t�Z�b�g�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void SetOffset();
	/*
	* �\���ݒ�{�^���𔽉f����֐�
	*/
	void SetVisi(bool visi);
	

	QTextCodec* tc;
	QComboBox *NameEdit;
	QComboBox *TypeEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;

	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *ScaleZspinBox;

	QDoubleSpinBox *SizeXspinBox;
	QDoubleSpinBox *SizeYspinBox;
	QDoubleSpinBox *SizeZspinBox;
	QDoubleSpinBox *SizeRspinBox;
	
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;

	QDoubleSpinBox *OffsetXspinBox;
	QDoubleSpinBox *OffsetYspinBox;
	QDoubleSpinBox *OffsetZspinBox;
	
	QDoubleSpinBox *MassspinBox;

	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;

	
	QPushButton *DestroyButton;
	
	
	bool up_flag;
	



protected:
	




};


#endif