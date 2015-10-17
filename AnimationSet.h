/*!
 * @file  AnimationSet.h
 * @brief アニメーション設定ウインドウ
 *
 */

#ifndef ANIMATIONSET_H
#define ANIMATIONSET_H


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
 * @class AnimationSetWidget
*@brief アニメーション設定用ウィジェット
*/

class AnimationSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	*@param parent 親ウィジェット
	*/
	AnimationSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~AnimationSetWidget(void);

	OgreRTCApplication *EC;

signals:
	/**
	*@brief アニメーションを追加、削除したときのシグナル
	*/
	void UpdateAnimation();

public slots:
	/**
	*@brief アニメーションの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	

private slots:
	/**
	*@brief 作成ボタンを押したときのスロット
	*/
	void SetSlot();
	/**
	*@brief 名前コンボボックスの番号が変わったときのスロット
	*@param value 番号
	*/
	void NameSlot(int value);
	/**
	*@brief 削除ボタンを押したときのスロット
	*/
	void DestroySlot();
	/**
	*@brief リセットボタンを押したときのスロット
	*/
	void ResetSlot();
	/**
	*@brief 位置設定スピンボックスの値(X座標)を変更したときのスロット
	*@param value 位置(X)
	*/
	void PosXSlot(double value);
	/**
	*@brief 位置設定スピンボックスの値(Y座標)を変更したときのスロット
	*@param value 位置(Y)
	*/
	void PosYSlot(double value);
	/**
	*@brief 位置設定スピンボックスの値(Z座標)を変更したときのスロット
	*@param value 位置(Z)
	*/
	void PosZSlot(double value);
	/**
	*@brief 姿勢設定スピンボックスの値(ロール角)を変更したときのスロット
	*@param value 角度(ロール)
	*/
	void RollSlot(double value);
	/**
	*@brief 姿勢設定スピンボックスの値(ピッチ角)を変更したときのスロット
	*@param value 角度(ピッチ)
	*/
	void PitchSlot(double value);
	/**
	*@brief 姿勢設定スピンボックスの値(ヨー角)を変更したときのスロット
	*@param value 角度(ヨー)
	*/
	void YawSlot(double value);
	

	/**
	*@brief キー番号追加ボタンを押したときのスロット
	*/
	void KeySlot();
	/**
	*@brief キー番号削除ボタンを押したときのスロット
	*/
	void RemoveKeySlot();
	/**
	*@brief キー番号コンボボックスの番号が変わったときのスロット
	*@param value 番号
	*/
	void KeyNumSlot(int value);


	/**
	*@brief キーの位置設定ボタンが押されたときのスロット
	*/
	void TransSlot();

	/**
	*@brief キーの姿勢設定ボタンが押されたときのスロット
	*/
	void RotSlot();


	/**
	*@brief アニメーションの時間変更スピンボックスの値が変化したときのスロット
	*@param value 時間
	*/
	void StateSlot(double value);

	/**
	*@brief アニメーションの終了時間設定スピンボックスの値が変化したときのスロット
	*@param value 時間
	*/
	void TimeSlot(double value);
	

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