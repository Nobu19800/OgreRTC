#ifndef SUBWINDOWSET_H
#define SUBWINDOWSET_H

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
* 画面分割設定用ウィジェット
*/

class SubWindowSetWidget : public QWidget
{
	Q_OBJECT

public:
	SubWindowSetWidget(QWidget *parent = 0);
	~SubWindowSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/*
	*サブウインドウの設定をウィジェットに反映させるときのスロット
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
	*大きさ設定スピンボックスの値を変更したときのスロット
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	/*
	*表示、非表示設定ボタンを押したときのスロット
	*/
	void VisibleSlot();
	void unVisibleSlot();
	/*
	*削除ボタンを押したときのスロット
	*/
	void DestroySlot();

	/*
	*カメラの位置設定スピンボックスの値を変更したときのスロット
	*/
	void CameraPosXSlot(double value);
	void CameraPosYSlot(double value);
	void CameraPosZSlot(double value);
	/*
	*カメラの姿勢設定スピンボックスの値を変更したときのスロット
	*/
	void CameraRollSlot(double value);
	void CameraPitchSlot(double value);
	void CameraYawSlot(double value);
	/*
	*カメラの距離設定スピンボックスの値を変更したときのスロット
	*/
	void CameraLenSlot(double value);
	/*
	*リセットボタンを押したときのスロット
	*/
	void RestartSlot();
	
	void StopSlot();

	/*
	*名前コンボボックスの番号が変わったときのスロット
	*/
	void NameSlot(int value);
	



private:
	bool up_flag;
	/*
	* 位置設定スピンボックスの値を反映する関数
	*/
	void UpdatePos();
	/*
	* 大きさ設定スピンボックスの値を反映する関数
	*/
	void UpdateSize();
	void UpdateCameraPos();
	void UpdateCameraRot();
	/*
	* カメラの位置、姿勢、距離設定スピンボックスの値を反映する関数
	*/
	void UpdateCameraPQ();
	/*
	* 表示設定ボタンを反映する関数
	*/
	void UpdateVisi(bool visi);

	QTextCodec* tc;
	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *CameraPosXspinBox;
	QDoubleSpinBox *CameraPosYspinBox;
	QDoubleSpinBox *CameraPosZspinBox;
	QDoubleSpinBox *CameraRollspinBox;
	QDoubleSpinBox *CameraPitchspinBox;
	QDoubleSpinBox *CameraYawspinBox;
	QDoubleSpinBox *CameraLenspinBox;
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QPushButton *DestroyButton;
	QPushButton *RestartButton;
	QPushButton *StopButton;
	
	




	



protected:
	




};

#endif