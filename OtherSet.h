/*!
 * @file  OtherSet.h
 * @brief その他各種設定用ウインドウ
 *
 */


#ifndef OTHERSET_H
#define OTHERSET_H

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
 * @class OtherSetWidget
*@brief 背景、地面、FPS設定用ウィジェット
*/


class OtherSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	* @param parent 親ウィジェット
	*/
	OtherSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~OtherSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	
	/**
	*@brief 背景、地面の設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

private slots:
	
	/**
	*@brief スカイボックス設定ボタンを押したときのスロット
	*/
	void SkyBoxSetSlot();
	/**
	*@brief スカイボックス削除ボタンを押したときのスロット
	*/
	void DelSkyBoxSetSlot();
	/**
	*@brief スカイボックスのサイズ変更ボタンを押したときのスロット
	* @param value サイズ
	*/
	void SkyBoxSizeSlot(int value);
	
	/**
	*@brief 地面作成ボタンを押したときのスロット
	*/
	void FloorSetSlot();
	
	/**
	*@brief 地面削除ボタンを押したときのスロット
	*/
	void DelFloorSetSlot();
	/**
	*@brief 地面のサイズ変更ボタンを押したときのスロット
	* @param value サイズ
	*/
	void FloorSizeSlot(int value);
	/**
	*@brief 地面の法線方向変更ボタンを押したときのスロット
	* @param value 0でX軸、1でY軸、2でZ軸
	*/
	void FloorDirSlot(int value);
	
	/**
	*@brief FPSスピンボックスの値を変更したときのスロット
	* @param value FPS
	*/
	void TimeSlot(int value);

private:
	
	QTextCodec* tc;
	QPushButton *SkyBoxButton;
	QPushButton *DelSkyBoxButton;
	QSpinBox *SkyBoxspinBox;
	QComboBox *SkyBoxEdit;

	QPushButton *FloorButton;
	QPushButton *DelFloorButton;
	QSpinBox *FloorSizespinBox;
	QComboBox *FloorDircombpBox;
	QComboBox *FloorEdit;
	QSpinBox *TimespinBox;

	

	



protected:
	




};

#endif