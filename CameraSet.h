#ifndef CAMERASET_H
#define CAMERASET_H

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
* カメラ設定用ウィジェット
*/

class CameraSetWidget : public QWidget
{
	Q_OBJECT

public:
	CameraSetWidget(QWidget *parent = 0);
	~CameraSetWidget(void);

	OgreRTCApplication *EC;
public slots:
	/*
	*カメラ設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	/*
	* マウスが動いた時のスロット
	*/
	void mouseMoveSlot(QMouseEvent*  evt, int dx, int dy);
	/*
	* マウスのボタンを押したときのスロット
	*/
	void mousePressSlot(QMouseEvent*  evt);
	/*
	* マウスのボタンを離したときのスロット
	*/
	void mouseReleaseSlot(QMouseEvent*  evt);

private slots:
	/*
	*光源の位置設定スピンボックスの値を変更したときのスロット
	*/
	void LightXSlot(double value);
	void LightYSlot(double value);
	void LightZSlot(double value);
	/*
	*影の色設定スピンボックスの値を変更したときのスロット
	*/
	void ShadowRSlot(double value);
	void ShadowGSlot(double value);
	void ShadowBSlot(double value);
	/*
	*位置設定スピンボックスの値を変更したときのスロット
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	void PosZSlot(double value);
	/*
	*姿勢設定スピンボックスの値を変更したときのスロット
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*距離設定スピンボックスの値を変更したときのスロット
	*/
	void LenSlot(double value);

private:
	bool up_flag;

	void UpdatePos();
	void UpdateRot();
	/*
	* 影の色設定スピンボックスの値を反映する関数
	*/
	void UpdateColor();
	/*
	* 光源の位置設定スピンボックスの値を反映する関数
	*/
	void UpdateLightPos();
	/*
	* 位置、姿勢、距離設定スピンボックスの値を反映する関数
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