#ifndef SOUNDSET_H
#define SOUNDSET_H

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
* �T�E���h�ݒ�p�E�B�W�F�b�g
*/

class SoundSetWidget : public QWidget
{
	Q_OBJECT

public:
	SoundSetWidget(QWidget *parent = 0);
	~SoundSetWidget(void);

	OgreRTCApplication *EC;

private slots:
	/*
	*�Đ��{�^�����������Ƃ��̃X���b�g
	*/
	void SetSlot();
	/*
	*�S�̂̉��ʐݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void EngineVolumeSlot(double value);
	/*
	*���x�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void SpeedSlot(double value);
	/*
	*���ʐݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void VolumeSlot(double value);
	void VolumePauseSlot();
	void VolumeunPauseSlot();
	/*
	*�ʒu�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void PositionSlot(double value);
	/*
	*��~�{�^�����������Ƃ��̃X���b�g
	*/
	void StopSlot();
	/*
	*���Z�b�g�{�^�����������Ƃ��̃X���b�g
	*/
	void ResetSlot();
	

private:

	QTextCodec* tc;
	QComboBox *NameEdit;
	QDoubleSpinBox *EngineVolumespinBox;
	QDoubleSpinBox *SpeedspinBox;
	QDoubleSpinBox *VolumespinBox;
	QPushButton *VolumePauseButton;
	QPushButton *VolumeunPauseButton;
	QDoubleSpinBox *PositionspinBox;
	QPushButton *StopButton;
	QPushButton *ResetButton;

	

	

	



protected:
	




};

#endif