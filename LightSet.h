/*!
 * @file  LightSet.h
 * @brief 光源の設定用ウインドウ
 *
 */

#ifndef LIGHTSET_H
#define LIGHTSET_H


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
 * @class LightObj
*@brief 光源の作成、設定用ウィジェット
*/

class LightSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	* @param parent 親ウィジェット
	*/
	LightSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~LightSetWidget(void);

	OgreRTCApplication *EC;

signals:
	/**
	*@brief 光源のパラメータ変更時に呼び出すシグナル
	*/
	void UpdateLight();

public slots:
	
	/**
	*@brief 光源の設定をウィジェットに反映させるときのスロット
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
	*@brief 色設定スピンボックスの値(赤)を変更したときのスロット
	* @param value 輝度(赤)
	*/
	void RedSlot(double value);
	/**
	*@brief 色設定スピンボックスの値(緑)を変更したときのスロット
	* @param value 輝度(緑)
	*/
	void GreenSlot(double value);
	/**
	*@brief 色設定スピンボックスの値(青)を変更したときのスロット
	* @param value 輝度(青)
	*/
	void BlueSlot(double value);

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
	bool up_flag;
	
	/**
	*@brief 位置設定スピンボックスの値を反映する関数
	*/
	void UpdatePos();
	
	/**
	*@brief 色設定スピンボックスの値を反映する関数
	*/
	void UpdateColor();
	
	/**
	*@brief 表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
	*/
	void UpdateVisi(bool visi);


	QTextCodec* tc;
	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *PosZspinBox;
	
	
	
	QDoubleSpinBox *RedspinBox;
	QDoubleSpinBox *GreenspinBox;
	QDoubleSpinBox *BluespinBox;

	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;

	
	QPushButton *DestroyButton;
	
	
	



protected:
	




};

#endif