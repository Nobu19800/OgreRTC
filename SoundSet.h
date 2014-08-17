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
* サウンド設定用ウィジェット
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
	*再生ボタンを押したときのスロット
	*/
	void SetSlot();
	/*
	*全体の音量設定スピンボックスの値を変更したときのスロット
	*/
	void EngineVolumeSlot(double value);
	/*
	*速度設定スピンボックスの値を変更したときのスロット
	*/
	void SpeedSlot(double value);
	/*
	*音量設定スピンボックスの値を変更したときのスロット
	*/
	void VolumeSlot(double value);
	void VolumePauseSlot();
	void VolumeunPauseSlot();
	/*
	*位置設定スピンボックスの値を変更したときのスロット
	*/
	void PositionSlot(double value);
	/*
	*停止ボタンを押したときのスロット
	*/
	void StopSlot();
	/*
	*リセットボタンを押したときのスロット
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