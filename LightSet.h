#ifndef LIGHTSET_H
#define LIGHTSET_H


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
* �����̍쐬�A�ݒ�p�E�B�W�F�b�g
*/

class LightSetWidget : public QWidget
{
	Q_OBJECT

public:
	LightSetWidget(QWidget *parent = 0);
	~LightSetWidget(void);

	OgreRTCApplication *EC;

signals:
	void UpdateLight();

public slots:
	/*
	*�����̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
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
	*�F�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void RedSlot(double value);
	void GreenSlot(double value);
	void BlueSlot(double value);
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
	bool up_flag;
	/*
	* �ʒu�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdatePos();
	/*
	* �F�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void UpdateColor();
	/*
	* �\���ݒ�{�^���𔽉f����֐�
	*/
	void UpdateVisi(bool visi);


	QTextCodec* tc;
	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;
	
	
	
	QDoubleSpinBox *RedspinBox;
	QDoubleSpinBox *GreenspinBox;
	QDoubleSpinBox *BluespinBox;

	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;

	
	QPushButton *DestroyButton;
	
	
	



protected:
	




};

#endif