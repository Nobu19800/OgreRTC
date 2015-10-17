/*!
 * @file  BornSet.h
 * @brief ボーンの設定用ウインドウ
 *
 */

#ifndef BORNSET_H
#define BORNSET_H

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
 * @class BornSetWidget
*@brief ボーンの設定用ウィジェット
*/
class BornSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	* @param parent 親ウィジェット
	*/
	BornSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~BornSetWidget(void);

	OgreRTCApplication *EC;

public slots:

	/**
	*@brief 3Dモデルが追加、削除されたときのスロット
	*/
	void UpdateBody();

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
	*@brief 位置設定スピンボックスの値(Z座標)を変更したときのスロット
	* @param value 位置(Z)
	*/
	void PosZSlot(double value);
	/**
	*@brief 拡大率設定スピンボックスの値(X軸方向)を変更したときのスロット
	* @param value 拡大率(X)
	*/
	void ScaleXSlot(double value);
	/**
	*@brief 拡大率設定スピンボックスの値(Y軸方向)を変更したときのスロット
	* @param value 拡大率(Y)
	*/
	void ScaleYSlot(double value);
	/**
	*@brief 拡大率設定スピンボックスの値(Z軸方向)を変更したときのスロット
	* @param value 拡大率(Z)
	*/
	void ScaleZSlot(double value);
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
	*@brief リセットボタンを押したときのスロット
	*/
	void ResetSlot();
	/**
	*@brief ボディの名前コンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void BodyNameSlot(int value);



private:
	QComboBox *BodyNameEdit;
	QSpinBox *NameEdit;
	QPushButton *SetButton;
	QPushButton *ResetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *ScaleZspinBox;
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;

	
	

	QTextCodec* tc;

	



protected:
	




};

#endif