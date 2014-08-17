#ifndef ANIMATIONSET_H
#define ANIMATIONSET_H


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
* �A�j���[�V�����ݒ�p�E�B�W�F�b�g
*/

class AnimationSetWidget : public QWidget
{
	Q_OBJECT

public:
	AnimationSetWidget(QWidget *parent = 0);
	~AnimationSetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	*�A�j���[�V������ǉ��A�폜�����Ƃ��̃V�O�i��
	*/
	void UpdateAnimation();

public slots:
	/*
	*�A�j���[�V�����̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
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
	*�폜�{�^�����������Ƃ��̃X���b�g
	*/
	void DestroySlot();
	/*
	*���Z�b�g�{�^�����������Ƃ��̃X���b�g
	*/
	void ResetSlot();

	/*
	*�ʒu�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	void PosZSlot(double value);
	/*
	*�p���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	
	/*
	* �L�[�ԍ��ǉ��{�^�����������Ƃ��̃X���b�g
	*/
	void KeySlot();
	/*
	* �L�[�ԍ��폜�{�^�����������Ƃ��̃X���b�g
	*/
	void RemoveKeySlot();
	/*
	* �L�[�ԍ��R���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
	*/
	void KeyNumSlot(int value);

	/*
	* �L�[�̈ʒu�ݒ�{�^���������ꂽ�Ƃ��̃X���b�g
	*/
	void TransSlot();
	/*
	* �L�[�̎p���ݒ�{�^���������ꂽ�Ƃ��̃X���b�g
	*/
	void RotSlot();

	/*
	* �A�j���[�V�����̎��ԕύX�X�s���{�b�N�X�̒l���ω������Ƃ��̃X���b�g
	*/
	void StateSlot(double value);
	/*
	* �A�j���[�V�����̏I�����Ԑݒ�X�s���{�b�N�X�̒l���ω������Ƃ��̃X���b�g
	*/
	void TimeSlot(double value);
	

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



	QTextCodec* tc;
	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *TimespinBox;
	QPushButton *KeyButton;
	QPushButton *RemoveKeyButton;
	QDoubleSpinBox *KeyTimespinBox;
	QSpinBox *KeyNumspinBox;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;
	QPushButton *TransButton;
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;
	QPushButton *RotButton;
	

	QPushButton *ResetButton;
	QPushButton *DestroyButton;
	
	QDoubleSpinBox *StatespinBox;

	



protected:
	




};

#endif