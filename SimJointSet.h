#ifndef SIMJOINTSET_H
#define SIMJOINTSET_H

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
* �V�~�����[�V�����̃W���C���g�쐬�A�ݒ�p�E�B�W�F�b�g
*/

class SimJointSetWidget : public QWidget
{
	Q_OBJECT

public:
	SimJointSetWidget(QWidget *parent = 0);
	~SimJointSetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	* �W���C���g���쐬�A�폜�����Ƃ��̃V�O�i��
	*/
	void UpdateODEJoint();


public slots:
	/*
	*�W���C���g�̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
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
	*3D���f���ƃW���C���g�̊g�嗦�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);
	/*
	*���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*3D���f���ƃW���C���g�̃I�t�Z�b�g�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void OffsetXSlot(double value);
	void OffsetYSlot(double value);
	void OffsetZSlot(double value);
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
	* �g�嗦�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void SetScale();
	/*
	* ���ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
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
	QComboBox *Body1Edit;
	QComboBox *Body2Edit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;

	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *ScaleZspinBox;

	
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;

	QDoubleSpinBox *OffsetXspinBox;
	QDoubleSpinBox *OffsetYspinBox;
	QDoubleSpinBox *OffsetZspinBox;
	
	

	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;

	
	QPushButton *DestroyButton;
	
	bool up_flag;

	



protected:
	




};


#endif