#ifndef ANIMATIONSET_H
#define ANIMATIONSET_H


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
* アニメーション設定用ウィジェット
*/

class AnimationSetWidget : public QWidget
{
	Q_OBJECT

public:
	AnimationSetWidget(QWidget *parent = 0);
	~AnimationSetWidget(void);

	OgreRTCApplication *EC;

signals:
	/*
	*アニメーションを追加、削除したときのシグナル
	*/
	void UpdateAnimation();

public slots:
	/*
	*アニメーションの設定をウィジェットに反映させるときのスロット
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
	*削除ボタンを押したときのスロット
	*/
	void DestroySlot();
	/*
	*リセットボタンを押したときのスロット
	*/
	void ResetSlot();

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
	* キー番号追加ボタンを押したときのスロット
	*/
	void KeySlot();
	/*
	* キー番号削除ボタンを押したときのスロット
	*/
	void RemoveKeySlot();
	/*
	* キー番号コンボボックスの番号が変わったときのスロット
	*/
	void KeyNumSlot(int value);

	/*
	* キーの位置設定ボタンが押されたときのスロット
	*/
	void TransSlot();
	/*
	* キーの姿勢設定ボタンが押されたときのスロット
	*/
	void RotSlot();

	/*
	* アニメーションの時間変更スピンボックスの値が変化したときのスロット
	*/
	void StateSlot(double value);
	/*
	* アニメーションの終了時間設定スピンボックスの値が変化したときのスロット
	*/
	void TimeSlot(double value);
	

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



	QTextCodec* tc;
	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *TimespinBox;
	QPushButton *KeyButton;
	QPushButton *RemoveKeyButton;
	QDoubleSpinBox *KeyTimespinBox;
	QSpinBox *KeyNumspinBox;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;
	QPushButton *TransButton;
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;
	QPushButton *RotButton;
	

	QPushButton *ResetButton;
	QPushButton *DestroyButton;
	
	QDoubleSpinBox *StatespinBox;

	



protected:
	




};

#endif