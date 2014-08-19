#ifndef OTHERSET_H
#define OTHERSET_H

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
* 背景、地面、FPS設定用ウィジェット
*/

class OtherSetWidget : public QWidget
{
	Q_OBJECT

public:
	OtherSetWidget(QWidget *parent = 0);
	~OtherSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/*
	*背景、地面の設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

private slots:
	/*
	*背景設定ボタンを押したときのスロット
	*/
	void SkyBoxSetSlot();
	void DelSkyBoxSetSlot();
	void SkyBoxSizeSlot(int value);
	/*
	*地面作成ボタンを押したときのスロット
	*/
	void FloorSetSlot();
	/*
	*地面削除ボタンを押したときのスロット
	*/
	void DelFloorSetSlot();
	void FloorSizeSlot(int value);
	void FloorDirSlot(int value);
	/*
	*FPSスピンボックスの値を変更したときのスロット
	*/
	void TimeSlot(int value);

private:
	
	QTextCodec* tc;
	QPushButton *SkyBoxButton;
	QPushButton *DelSkyBoxButton;
	QSpinBox *SkyBoxspinBox;
	QComboBox *SkyBoxEdit;

	QPushButton *FloorButton;
	QPushButton *DelFloorButton;
	QSpinBox *FloorSizespinBox;
	QComboBox *FloorDircombpBox;
	QComboBox *FloorEdit;
	QSpinBox *TimespinBox;

	

	



protected:
	




};

#endif