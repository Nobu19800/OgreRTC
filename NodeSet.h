#ifndef NODESET_H
#define NODESET_H

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
* ノードの設定用ウィジェット
*/

class NodeSetWidget : public QWidget
{
	Q_OBJECT

public:
	NodeSetWidget(QWidget *parent = 0);
	~NodeSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/*
	*ノードの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

private slots:
	/*
	*オブジェクトの種類コンボボックスの番号が変わったときのスロット
	*/
	void NumSlot(int value);
	void NameSlot(int value);
	/*
	*接続ボタンを押したときのスロット
	*/
	void AttachSlot();
	/*
	*分離ボタンを押したときのスロット
	*/
	void DettachSlot();
	/*
	*接続したオブジェクトのコンボボックスの番号が変わったときのスロット
	*/
	void AttachNumSlot(int value);
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