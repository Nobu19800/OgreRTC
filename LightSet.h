#ifndef LIGHTSET_H
#define LIGHTSET_H


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
* 光源の作成、設定用ウィジェット
*/

class LightSetWidget : public QWidget
{
	Q_OBJECT

public:
	LightSetWidget(QWidget *parent = 0);
	~LightSetWidget(void);

	OgreRTCApplication *EC;

signals:
	void UpdateLight();

public slots:
	/*
	*光源の設定をウィジェットに反映させるときのスロット
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
	*色設定スピンボックスの値を変更したときのスロット
	*/
	void RedSlot(double value);
	void GreenSlot(double value);
	void BlueSlot(double value);
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
	bool up_flag;
	/*
	* 位置設定スピンボックスの値を反映する関数
	*/
	void UpdatePos();
	/*
	* 色設定スピンボックスの値を反映する関数
	*/
	void UpdateColor();
	/*
	* 表示設定ボタンを反映する関数
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