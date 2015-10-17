/*!
 * @file  NodeSet.h
 * @brief ノードの設定用ウインドウ
 *
 */

#ifndef NODESET_H
#define NODESET_H

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
 * @class NodeSetWidget
*@brief ノードの設定用ウィジェット
*/
class NodeSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	*@param parent 親ウィジェット
	*/
	NodeSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~NodeSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	
	/**
	*@brief ノードの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

private slots:
	
	/**
	*@brief オブジェクトの種類コンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void NumSlot(int value);
	/**
	*@brief オブジェクトの名前コンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void NameSlot(int value);
	
	/**
	*@brief 接続ボタンを押したときのスロット
	*/
	void AttachSlot();
	
	/**
	*@brief 分離ボタンを押したときのスロット
	*/
	void DettachSlot();
	
	/**
	*@brief 接続するオブジェクトのコンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void AttachNumSlot(int value);
	/**
	*@brief 分離するオブジェクトのコンボボックスの番号が変わったときのスロット
	* @param value 番号
	*/
	void DettachNumSlot(int value);
	

private:
	
	QTextCodec* tc;
	QComboBox *NumEdit;
	QComboBox *NameEdit;
	QComboBox *TypeEdit;
	QPushButton *AttachButton;
	QComboBox *AttachNumBox;
	QComboBox *AttachListBox;
	QPushButton *DettachButton;
	QComboBox *DettachNumBox;
	QComboBox *DettachListBox;
	

	

	

	



protected:
	




};

#endif