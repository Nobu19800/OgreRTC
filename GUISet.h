#ifndef GUISET_H
#define GUISET_H

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
* GUI作成、設定用ウィジェット
*/

class GUISetWidget : public QWidget
{
	Q_OBJECT

public:
	GUISetWidget(QWidget *parent = 0);
	~GUISetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	* GUIを作成、削除したときのシグナル
	*/
	void UpdateGUI();

public slots:
	/*
	*GUIの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

private slots:
	/*
	*作成ボタンを押したときのスロット
	*/
	void SetSlot();
	/*
	*位置設定スピンボックスの値を変更したときのスロット
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	/*
	*姿勢設定スピンボックスの値を変更したときのスロット
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*大きさ設定スピンボックスの値を変更したときのスロット
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	/*
	*透明度設定スピンボックスの値を変更したときのスロット
	*/
	void AlphaSlot(double value);
	/*
	*表示、非表示設定ボタンを押したときのスロット
	*/
	void VisibleSlot();
	void unVisibleSlot();
	/*
	*フレームの表示、非表示設定ボタンを押したときのスロット
	*/
	void FrameSlot();
	void unFrameSlot();
	/*
	*背景の表示、非表示設定ボタンを押したときのスロット
	*/
	void BackGroundSlot();
	void unBackGroundSlot();
	/*
	*削除ボタンを押したときのスロット
	*/
	void DestroySlot();
	/*
	*名前コンボボックスの番号が変わったときのスロット
	*/
	void NameSlot(int value);
	/*
	*ウィンドウ設定ボタンを押したときのスロット
	*/
	void WindowSlot();


private:
	bool up_flag;
	/*
	* 位置設定スピンボックスの値を反映する関数
	*/
	void UpdatePos();
	/*
	* 姿勢設定スピンボックスの値を反映する関数
	*/
	void UpdateRot();
	/*
	* 大きさ設定スピンボックスの値を反映する関数
	*/
	void UpdateSize();
	/*
	* 表示設定ボタンを反映する関数
	*/
	void UpdateVisi(bool visi);
	/*
	* フレームの表示設定ボタンを反映する関数
	*/
	void UpdateFrame(bool visi);
	/*
	* 背景の表示設定ボタンを反映する関数
	*/
	void UpdateBackGround(bool visi);


	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *AlphaspinBox;
	
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QPushButton *FrameButton;
	QPushButton *unFrameButton;
	QPushButton *BackGroundButton;
	QPushButton *unBackGroundButton;
	
	QPushButton *DestroyButton;

	QComboBox *TypeBox;

	QComboBox *WindowBox;
	QPushButton *WindowButton;
	

	QTextCodec* tc;

	



protected:
	




};

#endif