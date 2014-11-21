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


/*
* ボーン設定用ウィジェット
*/

class BornSetWidget : public QWidget
{
	Q_OBJECT

public:
	BornSetWidget(QWidget *parent = 0);
	~BornSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/*
	* 3Dモデルが追加、削除されたときのスロット
	*/
	void UpdateBody();

private slots:
	/*
	*作成ボタンを押したときのスロット
	*/
	void SetSlot();
/*
	*位置設定スピンボックスの値を変更したときのスロット
	*/
	void PosXSlot(double value);
	void PosYSlot(double value);
	void PosZSlot(double value);
	/*
	*拡大率設定スピンボックスの値を変更したときのスロット
	*/
	void ScaleXSlot(double value);
	void ScaleYSlot(double value);
	void ScaleZSlot(double value);
	/*
	*姿勢設定スピンボックスの値を変更したときのスロット
	*/
	void RollSlot(double value);
	void PitchSlot(double value);
	void YawSlot(double value);
	/*
	*リセットボタンを押したときのスロット
	*/
	void ResetSlot();
	/*
	*ボディの名前コンボボックスの番号が変わったときのスロット
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