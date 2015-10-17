/*!
 * @file  GUISet.h
 * @brief GUIの設定用ウインドウ
 *
 */

#ifndef GUISET_H
#define GUISET_H

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
 * @class GUISetWidget
*@brief GUI設定用ウィジェット
*/
class GUISetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	*@param parent 親ウィジェット
	*/
	GUISetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~GUISetWidget(void);

	OgreRTCApplication *EC;

signals:
	
	/**
	*@brief GUIを作成、削除したときのシグナル
	*/
	void UpdateGUI();

public slots:
	
	/**
	*@brief GUIの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

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
	*@brief 大きさ設定スピンボックスの値(X軸方向)を変更したときのスロット
	* @param value サイズ(X)
	*/
	void ScaleXSlot(double value);
	/**
	*@brief 大きさ設定スピンボックスの値(Y軸方向)を変更したときのスロット
	* @param value サイズ(Y)
	*/
	void ScaleYSlot(double value);
	
	/**
	*@brief 透明度設定スピンボックスの値を変更したときのスロット
	* @param value 透明度
	*/
	void AlphaSlot(double value);
	
	/**
	*@brief 表示設定ボタンを押したときのスロット
	*/
	void VisibleSlot();
	/**
	*@brief 非表示設定ボタンを押したときのスロット
	*/
	void unVisibleSlot();
	
	/**
	*@brief フレームの表示設定ボタンを押したときのスロット
	*/
	void FrameSlot();
	/**
	*@brief フレームの非表示設定ボタンを押したときのスロット
	*/
	void unFrameSlot();
	
	/**
	*@brief 背景の表示設定ボタンを押したときのスロット
	*/
	void BackGroundSlot();
	/**
	*@brief 背景の非表示設定ボタンを押したときのスロット
	*/
	void unBackGroundSlot();
	
	/**
	*@brief 削除ボタンを押したときのスロット
	*/
	void DestroySlot();
	
	/**
	*@brief 名前コンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void NameSlot(int value);
	
	/**
	*@brief ウィンドウ設定ボタンを押したときのスロット
	*/
	void WindowSlot();


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
	
	/**
	*@brief 大きさ設定スピンボックスの値を反映する関数
	*/
	void UpdateSize();
	
	/**
	*@brief 表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
	*/
	void UpdateVisi(bool visi);
	
	/**
	*@brief フレームの表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
	*/
	void UpdateFrame(bool visi);
	
	/**
	*@brief 背景の表示設定ボタンを反映する関数
	* @param visi trueで表示、falseで非表示
	*/
	void UpdateBackGround(bool visi);


	QComboBox *NameEdit;
	QPushButton *SetButton;
	QDoubleSpinBox *PosXspinBox;
	QDoubleSpinBox *PosYspinBox;
	QDoubleSpinBox *RollspinBox;
	QDoubleSpinBox *PitchspinBox;
	QDoubleSpinBox *YawspinBox;
	QDoubleSpinBox *ScaleXspinBox;
	QDoubleSpinBox *ScaleYspinBox;
	QDoubleSpinBox *AlphaspinBox;
	
	QPushButton *VisibleButton;
	QPushButton *unVisibleButton;
	QPushButton *FrameButton;
	QPushButton *unFrameButton;
	QPushButton *BackGroundButton;
	QPushButton *unBackGroundButton;
	
	QPushButton *DestroyButton;

	QComboBox *TypeBox;

	QComboBox *WindowBox;
	QPushButton *WindowButton;
	

	QTextCodec* tc;

	



protected:
	




};

#endif