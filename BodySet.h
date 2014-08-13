#ifndef BODYSET_H
#define BODYSET_H

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
* 3D���f���쐬�A�ݒ�p�E�B�W�F�b�g
*/

class BodySetWidget : public QWidget
{
	Q_OBJECT

public:
	BodySetWidget(QWidget *parent = 0);
	~BodySetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	* 3D���f�����쐬�A�폜�����Ƃ��̃V�O�i��
	*/
	void UpdateBody();

public slots:
	/*
	*3D���f���̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();
	/*
	* �}�E�X�����������̃X���b�g
	*/
	void mouseMoveSlot(QMouseEvent*  evt, int dx, int dy);
	/*
	* �}�E�X�̃{�^�����������Ƃ��̃X���b�g
	*/
	void mousePressSlot(QMouseEvent*  evt);
	/*
	* �}�E�X�̃{�^���𗣂����Ƃ��̃X���b�g
	*/
	void mouseReleaseSlot(QMouseEvent*  evt);

	

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
	*�F�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void RedSlot(double value);
	void GreenSlot(double value);
	void BlueSlot(double value);
	/*
	*�����x�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void AlphaSlot(double value);
	/*
	*�A�j���[�V�������ԕύX�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void AnimationSlot(double value);
	/*
	*�\���A��\���ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void VisibleSlot();
	void unVisibleSlot();
	/*
	*�A�j���[�V�����ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void SetAnimationSlot();
	/*
	*�A�j���[�V�����̃��Z�b�g�{�^�����������Ƃ��̃X���b�g
	*/
	void ResetAnimationSlot();
	/*
	*�폜�{�^�����������Ƃ��̃X���b�g
	*/
	void DestroySlot();
	/*
	*�e�̕\���A��\���{�^�����������Ƃ��̃X���b�g
	*/
	void SetShadowSlot();
	void RemoveShadowSlot();
	/*
	*�o�E���f�B���O�{�b�N�X�̕\���A��\���{�^�����������Ƃ��̃X���b�g
	*/
	void SetBoundingBoxSlot();
	void RemoveBoundingBoxSlot();

	void MaterialSlot();

	/*
	*�}�e���A���ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void SetMaterialSlot();

	

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
	* �F�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateColor();
	/*
	* �\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateVisi(bool visi);
	/*
	* �e�̕\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateShadow(bool visi);
	/*
	* �o�E���f�B���O�{�b�N�X�̕\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateBound(bool visi);


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
	QDoubleSpinBox *RedspinBox;
	QDoubleSpinBox *GreenspinBox;
	QDoubleSpinBox *BluespinBox;
	QDoubleSpinBox *AlphaspinBox;
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QComboBox *AnimationEdit;
	QDoubleSpinBox *AnimationspinBox;
	QPushButton *SetAnimationButton;
	QPushButton *ResetAnimationButton;
	QPushButton *DestroyButton;
	QPushButton *SetShadowButton;
	QPushButton *RemoveShadowButton;
	QPushButton *SetBoundingBoxButton;
	QPushButton *RemoveBoundingBoxButton;
	QComboBox *MaterialEdit;
	QPushButton *SetMaterialButton;
	
	

	



protected:
	




};

#endif