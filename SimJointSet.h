/*!
 * @file  SimJointSet.h
 * @brief シミュレーションのジョイント作成、設定用ウィンドウ
 *
 */

#ifndef SIMJOINTSET_H
#define SIMJOINTSET_H

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
*@brief シミュレーションのジョイント作成、設定用ウィジェット
*/

class SimJointSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	* @param parent 親ウィジェット
	*/
	SimJointSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~SimJointSetWidget(void);

	OgreRTCApplication *EC;

signals:
	
	/**
	*@brief ジョイントを作成、削除したときのシグナル
	*/
	void UpdateODEJoint();


public slots:
	
	/**
	*@brief ジョイントの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	

private slots:
	
	/**
	*@brief 作成ボタンを押したときのスロット
	*/
	void SetSlot();
	/**
	*@brief 名前コンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void NameSlot(int value);
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
	*@brief 3Dモデルの拡大率設定スピンボックスの値(X軸方向)を変更したときのスロット
	* @param value 拡大率(X)
	*/
	void ScaleXSlot(double value);
	/**
	*@brief 3Dモデルの拡大率設定スピンボックスの値(Y軸方向)を変更したときのスロット
	* @param value 拡大率(Y)
	*/
	void ScaleYSlot(double value);
	/**
	*@brief 3Dモデルの拡大率設定スピンボックスの値(Z軸方向)を変更したときのスロット
	* @param value 拡大率(Z)
	*/
	void ScaleZSlot(double value);
	
	/**
	*@brief 軸設定スピンボックスの値(ロール角)を変更したときのスロット
	* @param value ロール
	*/
	void RollSlot(double value);
	/**
	*@brief 軸設定スピンボックスの値(ピッチ角)を変更したときのスロット
	* @param value ピッチ
	*/
	void PitchSlot(double value);
	/**
	*@brief 軸設定スピンボックスの値(ヨー角)を変更したときのスロット
	* @param value ヨー
	*/
	void YawSlot(double value);
	/**
	*@brief 3Dモデルとボディのオフセット設定スピンボックスの値(X軸方向)を変更したときのスロット
	* @param value オフセット(X)
	*/
	void OffsetXSlot(double value);
	/**
	*@brief 3Dモデルとボディのオフセット設定スピンボックスの値(Y軸方向)を変更したときのスロット
	* @param value オフセット(Y)
	*/
	void OffsetYSlot(double value);
	/**
	*@brief 3Dモデルとボディのオフセット設定スピンボックスの値(Z軸方向)を変更したときのスロット
	* @param value オフセット(Z)
	*/
	void OffsetZSlot(double value);
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

	

	

private:
	
	
	/**
	*@brief 位置設定スピンボックスの値を反映する関数
	*/
	void SetPos();
	
	/**
	*@brief 拡大率設定スピンボックスの値を反映する関数
	*/
	void SetScale();
	
	/**
	*@brief 軸設定スピンボックスの値を反映する関数
	*/
	void SetRot();
	
	/**
	*@brief オフセット設定スピンボックスの値を反映する関数
	*/
	void SetOffset();
	
	/**
	*@brief 表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
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