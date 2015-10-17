/*!
 * @file  SimulationSet.h
 * @brief シミュレーション設定用ウィンドウ
 *
 */

#ifndef SIMULATIONSET_H
#define SIMULATIONSET_H

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


/**
 * @class SimJointSetWidget
*@brief シミュレーション設定用ウィジェット
*/

class SimulationSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	* @param parent 親ウィジェット
	*/
	SimulationSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~SimulationSetWidget(void);

	OgreRTCApplication *EC;


public slots:
	
	/**
	*@brief シミュレーションの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	

private slots:
	
	/**
	*@brief リセットボタンを押したときのスロット
	*/
	void ResetSlot();
	
	/**
	*@brief 重力加速度設定スピンボックスの値を変更したときのスロット
	* @param value 重力加速度
	*/
	void GravitySlot(double value);
	
	/**
	*@brief CFM設定スピンボックスの値を変更したときのスロット
	* @param value CFM
	*/
	void CFMSlot(double value);
	
	/**
	*@brief ERP設定スピンボックスの値を変更したときのスロット
	* @param value ERP
	*/
	void ERPSlot(double value);
	
	/**
	*@brief 接触時のCFM設定スピンボックスの値を変更したときのスロット
	* @param value CFM
	*/
	void gCFMSlot(double value);
	
	/**
	*@brief 接触時のERP設定スピンボックスの値を変更したときのスロット
	* @param value ERP
	*/
	void gERPSlot(double value);
	
	/**
	*@brief 精度重視ボタンを押したときのスロット
	*/
	void unQuiqSlot();
	/**
	*@brief 速度重視ボタンを押したときのスロット
	*/
	void QuiqSlot();

	
	/**
	*@brief 開始ボタンを押したときのスロット
	*/
	void StartSlot();
	/**
	*@brief 再開始ボタンを押したときのスロット
	*/
	void RestartSlot();
	
	/**
	*@brief 停止ボタンを押したときのスロット
	*/
	void StopSlot();
	
	
	/**
	*@brief 摩擦設定スピンボックスの値を変更したときのスロット
	* @param value 摩擦係数
	*/
	void gMuSlot(double value);
	
	/**
	*@brief サンプリングタイム設定スピンボックスの値を変更したときのスロット
	* @param value サンプリングタイム
	*/
	void STimeSlot(double value);
	
	/**
	*@brief 各フレームでの待ち時間設定スピンボックスの値を変更したときのスロット
	* @param value 待ち時間
	*/
	void SleepTimeSlot(double value);
	
	/**
	*@brief 3Dモデルとシミュレーションの拡大率(X軸)設定スピンボックスの値を変更したときのスロット
	* @param value 位置(X)
	*/
	void ScaleXSlot(double value);
	/**
	*@brief 3Dモデルとシミュレーションの拡大率(Y軸)設定スピンボックスの値を変更したときのスロット
	* @param value 位置(Y)
	*/
	void ScaleYSlot(double value);
	/**
	*@brief 3Dモデルとシミュレーションの拡大率(Z軸)設定スピンボックスの値を変更したときのスロット
	* @param value 位置(Z)
	*/
	void ScaleZSlot(double value);

	

	

private:
	
	/**
	*@brief 拡大率設定スピンボックスの値を反映する関数
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