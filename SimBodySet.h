#ifndef SIMBODYSET_H
#define SIMBODYSET_H

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
* シミュレーションのボディ作成、設定用ウィジェット
*/

class SimBodySetWidget : public QWidget
{
	Q_OBJECT

public:
	SimBodySetWidget(QWidget *parent = 0);
	~SimBodySetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	* ボディを作成、削除したときのシグナル
	*/
	void UpdateODEBody();

public slots:
	/*
	*ボディの設定をウィジェットに反映させるときのスロット
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
	*大きさ設定スピンボックスの値を変更したときのスロット
	*/
	void SizeXSlot(double value);
	void SizeYSlot(double value);
	void SizeZSlot(double value);
	void SizeRSlot(double value);
	/*
	*3Dモデルとボディの拡大率設定スピンボックスの値を変更したときのスロット
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);
	/*
	*3Dモデルとボディのオフセット設定スピンボックスの値を変更したときのスロット
	*/
	void OffsetXSlot(double value);
	void OffsetYSlot(double value);
	void OffsetZSlot(double value);
	/*
	*姿勢設定スピンボックスの値を変更したときのスロット
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*質量設定スピンボックスの値を変更したときのスロット
	*/
	void MassSlot(double value);
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
	* 大きさ設定スピンボックスの値を反映する関数
	*/
	void SetSize();
	/*
	* 拡大率設定スピンボックスの値を反映する関数
	*/
	void SetScale();
	/*
	* 姿勢設定スピンボックスの値を反映する関数
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
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;

	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *ScaleZspinBox;

	QDoubleSpinBox *SizeXspinBox;
	QDoubleSpinBox *SizeYspinBox;
	QDoubleSpinBox *SizeZspinBox;
	QDoubleSpinBox *SizeRspinBox;
	
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;

	QDoubleSpinBox *OffsetXspinBox;
	QDoubleSpinBox *OffsetYspinBox;
	QDoubleSpinBox *OffsetZspinBox;
	
	QDoubleSpinBox *MassspinBox;

	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;

	
	QPushButton *DestroyButton;
	
	
	bool up_flag;
	



protected:
	




};


#endif