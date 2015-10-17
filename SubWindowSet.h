/*!
 * @file  SubWindowSet.h
 * @brief サブウインドウの設定用ウインドウ
 *
 */

#ifndef SUBWINDOWSET_H
#define SUBWINDOWSET_H

#include <QtWidgets>
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



/**
 * @class SubWindowSetWidget
*@brief 画面分割設定用ウィジェット
*/

class SubWindowSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	*@param parent 親ウィジェット
	*/
	SubWindowSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~SubWindowSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	
	/**
	*@brief サブウインドウの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

private slots:
	
	/**
	*@brief 作成ボタンを押したときのスロット
	*/
	void SetSlot();

	/**
	*@brief 位置設定スピンボックスの値(X座標)を変更したときのスロット
	* @param value 位置(X)
	*/
	void PosXSlot(double value);
	/**
	*@brief 位置設定スピンボックスの値(Y座標)を変更したときのスロット
	* @param value 位置(Y)
	*/
	void PosYSlot(double value);
	/**
	*@brief 大きさ設定スピンボックスの値(X軸方向)を変更したときのスロット
	* @param value サイズ(X)
	*/
	void ScaleXSlot(double value);
	/**
	*@brief 大きさ設定スピンボックスの値(Y軸方向)を変更したときのスロット
	* @param value サイズ(Y)
	*/
	void ScaleYSlot(double value);
	/**
	*@brief 表示設定ボタンを押したときのスロット
	*/
	void VisibleSlot();
	/**
	*@brief 非表示設定ボタンを押したときのスロット
	*/
	void unVisibleSlot();
	
	/**
	*@brief 削除ボタンを押したときのスロット
	*/
	void DestroySlot();

	
	/**
	*@brief カメラの位置設定スピンボックスの値(X座標)を変更したときのスロット
	* @param value 位置(X)
	*/
	void CameraPosXSlot(double value);
	/**
	*@brief カメラの位置設定スピンボックスの値(Y座標)を変更したときのスロット
	* @param value 位置(Y)
	*/
	void CameraPosYSlot(double value);
	/**
	*@brief カメラの位置設定スピンボックスの値(Z座標)を変更したときのスロット
	* @param value 位置(Z)
	*/
	void CameraPosZSlot(double value);
	
	/**
	*@brief カメラの姿勢設定スピンボックスの値(ロール角)を変更したときのスロット
	* @param value 角度(ロール)
	*/
	void CameraRollSlot(double value);
	/**
	*@brief カメラの姿勢設定スピンボックスの値(ピッチ角)を変更したときのスロット
	* @param value 角度(ピッチ)
	*/
	void CameraPitchSlot(double value);
	/**
	*@brief カメラの姿勢設定スピンボックスの値(ヨー角)を変更したときのスロット
	* @param value 角度(ヨー)
	*/
	void CameraYawSlot(double value);
	
	/**
	*@brief カメラの距離設定スピンボックスの値を変更したときのスロット
	* @param value 距離
	*/
	void CameraLenSlot(double value);
	
	/**
	*@brief リセットボタンを押したときのスロット
	*/
	void RestartSlot();
	
	/**
	*@brief 停止ボタンを押したときのスロット
	*/
	void StopSlot();

	/**
	*@brief 名前コンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void NameSlot(int value);
	



private:
	bool up_flag;

	/**
	*@brief 位置設定スピンボックスの値を反映する関数
	*/
	void UpdatePos();
	
	/**
	*@brief 大きさ設定スピンボックスの値を反映する関数
	*/
	void UpdateSize();
	/**
	*@brief カメラの位置設定スピンボックスの値を反映する関数
	*/
	void UpdateCameraPos();
	/**
	*@brief カメラの姿勢設定スピンボックスの値を反映する関数
	*/
	void UpdateCameraRot();
	
	/**
	*@brief カメラの位置、姿勢、距離設定スピンボックスの値を反映する関数
	*/
	void UpdateCameraPQ();
	
	/**
	*@brief 表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
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