#ifndef SIMJOINTSET_H
#define SIMJOINTSET_H

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
* シミュレーションのジョイント作成、設定用ウィジェット
*/

class SimJointSetWidget : public QWidget
{
	Q_OBJECT

public:
	SimJointSetWidget(QWidget *parent = 0);
	~SimJointSetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	* ジョイントを作成、削除したときのシグナル
	*/
	void UpdateODEJoint();


public slots:
	/*
	*ジョイントの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	

private slots:
	/*
	*作成ボタンを押したときのスロット
	*/
	void SetSlot();
	/*
	*名前コンボボックスの番号が変わったときのスロット
	*/
	void NameSlot(int value);
	/*
	*位置設定スピンボックスの値を変更したときのスロット
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	void PosZSlot(double value);
	/*
	*3Dモデルとジョイントの拡大率設定スピンボックスの値を変更したときのスロット
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);
	/*
	*軸設定スピンボックスの値を変更したときのスロット
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*3Dモデルとジョイントのオフセット設定スピンボックスの値を変更したときのスロット
	*/
	void OffsetXSlot(double value);
	void OffsetYSlot(double value);
	void OffsetZSlot(double value);
	/*
	*表示、非表示設定ボタンを押したときのスロット
	*/
	void VisibleSlot();
	void unVisibleSlot();

	/*
	*削除ボタンを押したときのスロット
	*/
	void DestroySlot();

	

	

private:
	
	/*
	* 位置設定スピンボックスの値を反映する関数
	*/
	void SetPos();
	/*
	* 拡大率設定スピンボックスの値を反映する関数
	*/
	void SetScale();
	/*
	* 軸設定スピンボックスの値を反映する関数
	*/
	void SetRot();
	/*
	* オフセット設定スピンボックスの値を反映する関数
	*/
	void SetOffset();
	/*
	* 表示設定ボタンを反映する関数
	*/
	void SetVisi(bool visi);


	QTextCodec* tc;
	QComboBox *NameEdit;
	QComboBox *TypeEdit;
	QComboBox *Body1Edit;
	QComboBox *Body2Edit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;

	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *ScaleZspinBox;

	
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;

	QDoubleSpinBox *OffsetXspinBox;
	QDoubleSpinBox *OffsetYspinBox;
	QDoubleSpinBox *OffsetZspinBox;
	
	

	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;

	
	QPushButton *DestroyButton;
	
	bool up_flag;

	



protected:
	




};


#endif