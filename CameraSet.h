/*!
 * @file  CameraSet.h
 * @brief カメラの設定用ウインドウ
 *
 */

#ifndef CAMERASET_H
#define CAMERASET_H

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
 * @class CameraSetWidget
*@brief カメラ設定用ウィジェット
*/

class CameraSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	*@param parent 親ウィジェット
	*/
	CameraSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~CameraSetWidget(void);

	OgreRTCApplication *EC;
public slots:
	/**
	*@brief カメラ設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	/**
	*@brief マウスが動いた時のスロット
	* @param evt マウスイベント
	* @param dx 移動量(X)
	* @param dy 移動量(Y)
	*/
	void mouseMoveSlot(QMouseEvent*  evt, int dx, int dy);
	/**
	*@brief マウスのボタンを押したときのスロット
	* @param evt マウスイベント
	*/
	void mousePressSlot(QMouseEvent*  evt);
	/**
	*@brief マウスのボタンを離したときのスロット
	* @param evt マウスイベント
	*/
	void mouseReleaseSlot(QMouseEvent*  evt);

private slots:
	/**
	*@brief 光源の位置設定スピンボックスの値(X)を変更したときのスロット
	* @param value 位置(X)
	*/
	void LightXSlot(double value);
	/**
	*@brief 光源の位置設定スピンボックスの値(Y)を変更したときのスロット
	* @param value 位置(Y)
	*/
	void LightYSlot(double value);
	/**
	*@brief 光源の位置設定スピンボックスの値(Z)を変更したときのスロット
	* @param value 位置(Z)
	*/
	void LightZSlot(double value);

	/**
	*@brief 影の色設定スピンボックスの値(赤)を変更したときのスロット
	* @param value 輝度(赤)
	*/
	void ShadowRSlot(double value);
	/**
	*@brief 影の色設定スピンボックスの値(緑)を変更したときのスロット
	* @param value 輝度(緑)
	*/
	void ShadowGSlot(double value);
	/**
	*@brief 影の色設定スピンボックスの値(青)を変更したときのスロット
	* @param value 輝度(青)
	*/
	void ShadowBSlot(double value);

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
	*@brief 位置設定スピンボックスの値(Z座標)を変更したときのスロット
	* @param value 位置(Z)
	*/
	void PosZSlot(double value);

	/**
	*@brief 姿勢設定スピンボックスの値(ロール角)を変更したときのスロット
	* @param value 角度(ロール)
	*/
	void RollSlot(double value);
	/**
	*@brief 姿勢設定スピンボックスの値(ピッチ角)を変更したときのスロット
	* @param value 角度(ピッチ)
	*/
	void PitchSlot(double value);
	/**
	*@brief 姿勢設定スピンボックスの値(ヨー角)を変更したときのスロット
	* @param value 角度(ヨー)
	*/
	void YawSlot(double value);
	/**
	*@brief 距離設定スピンボックスの値を変更したときのスロット
	* @param value 距離
	*/
	void LenSlot(double value);

private:
	bool up_flag;

	/**
	*@brief 位置設定スピンボックスの値を反映する関数
	*/
	void UpdatePos();
	/**
	*@brief 姿勢設定スピンボックスの値を反映する関数
	*/
	void UpdateRot();

	/**
	*@brief 影の色設定スピンボックスの値を反映する関数
	*/
	void UpdateColor();
	
	/**
	*@brief 光源の位置設定スピンボックスの値を反映する関数
	*/
	void UpdateLightPos();
	
	/**
	*@brief 位置、姿勢、距離設定スピンボックスの値を反映する関数
	*/
	void UpdatePQ();

	QDoubleSpinBox *LightXspinBox;
	QDoubleSpinBox *LightYspinBox;
	QDoubleSpinBox *LightZspinBox;

	QDoubleSpinBox *ShadowRspinBox;
	QDoubleSpinBox *ShadowGspinBox;
	QDoubleSpinBox *ShadowBspinBox;

	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;

	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;

	QDoubleSpinBox *LenspinBox;
	

	QTextCodec* tc;

	

	



protected:
	




};

#endif