#ifndef SIMULATIONSET_H
#define SIMULATIONSET_H

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
* �V�~�����[�V�����ݒ�p�E�B�W�F�b�g
*/


class SimulationSetWidget : public QWidget
{
	Q_OBJECT

public:
	SimulationSetWidget(QWidget *parent = 0);
	~SimulationSetWidget(void);

	OgreRTCApplication *EC;


public slots:
	/*
	*�V�~�����[�V�����̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();
	

private slots:
	/*
	*���Z�b�g�{�^�����������Ƃ��̃X���b�g
	*/
	void ResetSlot();
	/*
	*�d�͐ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void GravitySlot(double value);
	/*
	*CFM�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void CFMSlot(double value);
	/*
	*ERP�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void ERPSlot(double value);
	/*
	*�ڐG����CFM�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void gCFMSlot(double value);
	/*
	*�ڐG����ERP�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void gERPSlot(double value);
	/*
	*���x�A���x�d���{�^�����������Ƃ��̃X���b�g
	*/
	void unQuiqSlot();
	void QuiqSlot();

	/*
	*�J�n�{�^�����������Ƃ��̃X���b�g
	*/
	void StartSlot();
	void RestartSlot();
	/*
	*��~�{�^�����������Ƃ��̃X���b�g
	*/
	void StopSlot();
	
	/*
	*���C�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void gMuSlot(double value);
	/*
	*�T���v�����O�^�C���ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void STimeSlot(double value);
	/*
	*�҂����Ԑݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void SleepTimeSlot(double value);
	/*
	*3D���f���ƃV�~�����[�V�����̊g�嗦�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);

	

	

private:
	/*
	* �g�嗦�ݒ�X�s���{�b�N�X�̒l�𔽉f����֐�
	*/
	void SetScale();
	QPushButton *StartButton;
	QPushButton *StopButton;
	QPushButton *RestartButton;

	QPushButton *ResetButton;
	QDoubleSpinBox *GravityspinBox;
	QDoubleSpinBox *CFMspinBox;
	QDoubleSpinBox *ERPspinBox;
	QDoubleSpinBox *gCFMspinBox;
	QDoubleSpinBox *gERPspinBox;

	QDoubleSpinBox *gMuspinBox;
	QDoubleSpinBox *STimespinBox;
	QDoubleSpinBox *SleepTimespinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *ScaleZspinBox;

	QPushButton *QuiqButton;

	QPushButton *unQuiqButton;



	QTextCodec* tc;
	
	
	bool up_flag;

	



protected:
	




};


#endif