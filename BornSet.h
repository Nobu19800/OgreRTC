#ifndef BORNSET_H
#define BORNSET_H

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
* �{�[���ݒ�p�E�B�W�F�b�g
*/

class BornSetWidget : public QWidget
{
	Q_OBJECT

public:
	BornSetWidget(QWidget *parent = 0);
	~BornSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/*
	* 3D���f�����ǉ��A�폜���ꂽ�Ƃ��̃X���b�g
	*/
	void UpdateBody();

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
	*���Z�b�g�{�^�����������Ƃ��̃X���b�g
	*/
	void ResetSlot();
	/*
	*�{�f�B�̖��O�R���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
	*/
	void BodyNameSlot(int value);



private:
	QComboBox *BodyNameEdit;
	QSpinBox *NameEdit;
	QPushButton *SetButton;
	QPushButton *ResetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *ScaleZspinBox;
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;

	
	

	QTextCodec* tc;

	



protected:
	




};

#endif