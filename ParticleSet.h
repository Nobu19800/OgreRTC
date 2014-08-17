#ifndef PARTICLESET_H
#define PARTICLESET_H

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
* �p�[�e�B�N���쐬�A�ݒ�p�E�B�W�F�b�g
*/

class ParticleSetWidget : public QWidget
{
	Q_OBJECT

public:
	ParticleSetWidget(QWidget *parent = 0);
	~ParticleSetWidget(void);

	OgreRTCApplication *EC;

public slots:

	void UpdateList();
	

signals:
	/*
	* �p�[�e�B�N�����쐬�A�폜�����Ƃ��̃V�O�i��
	*/
	void UpdateParticle();

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
	void PosZSlot(double value);
	/*
	*�g�嗦�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);
	/*
	*�p���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
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
	* �g�嗦�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateScale();
	/*
	* �p���ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateRot();
	/*
	* �\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateVisi(bool visi);


	QTextCodec* tc;
	QComboBox *NameEdit;
	QComboBox *FileNameEdit;
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
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QPushButton *DestroyButton;

	

	

	



protected:
	




};

#endif