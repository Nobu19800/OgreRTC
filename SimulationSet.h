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
* シミュレーション設定用ウィジェット
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
	*シミュレーションの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	

private slots:
	/*
	*リセットボタンを押したときのスロット
	*/
	void ResetSlot();
	/*
	*重力設定スピンボックスの値を変更したときのスロット
	*/
	void GravitySlot(double value);
	/*
	*CFM設定スピンボックスの値を変更したときのスロット
	*/
	void CFMSlot(double value);
	/*
	*ERP設定スピンボックスの値を変更したときのスロット
	*/
	void ERPSlot(double value);
	/*
	*接触時のCFM設定スピンボックスの値を変更したときのスロット
	*/
	void gCFMSlot(double value);
	/*
	*接触時のERP設定スピンボックスの値を変更したときのスロット
	*/
	void gERPSlot(double value);
	/*
	*精度、速度重視ボタンを押したときのスロット
	*/
	void unQuiqSlot();
	void QuiqSlot();

	/*
	*開始ボタンを押したときのスロット
	*/
	void StartSlot();
	void RestartSlot();
	/*
	*停止ボタンを押したときのスロット
	*/
	void StopSlot();
	
	/*
	*摩擦設定スピンボックスの値を変更したときのスロット
	*/
	void gMuSlot(double value);
	/*
	*サンプリングタイム設定スピンボックスの値を変更したときのスロット
	*/
	void STimeSlot(double value);
	/*
	*待ち時間設定スピンボックスの値を変更したときのスロット
	*/
	void SleepTimeSlot(double value);
	/*
	*3Dモデルとシミュレーションの拡大率設定スピンボックスの値を変更したときのスロット
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);

	

	

private:
	/*
	* 拡大率設定スピンボックスの値を反映する関数
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