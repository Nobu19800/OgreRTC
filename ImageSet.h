#ifndef IMAGESET_H
#define IMAGESET_H

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
* GUIの画像作成、設定用ウィジェット
*/

class ImageSetWidget : public QWidget
{
	Q_OBJECT

public:
	ImageSetWidget(QWidget *parent = 0);
	~ImageSetWidget(void);

	OgreRTCApplication *EC;



public slots:
	/*
	*画像の設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();
	/*
	*GUIが追加、削除された時のスロット
	*/
	void UpdateGUI();

private slots:
	/*
	*作成ボタンを押したときのスロット
	*/
	void SetSlot();
	/*
	*削除ボタンを押したときのスロット
	*/
	void DestroySlot();
	/*
	*GUIの名前コンボボックスの番号が変わったときのスロット
	*/
	void NameSlot(int value);
	/*
	*GUIの画像設定ボタンを押したときのスロット
	*/
	void SetGUISlot();


private:
	

	QTextCodec* tc;
	QComboBox *NameEdit;
	QComboBox *FileNameEdit;
	QPushButton *SetButton;
	QPushButton *DestroyButton;

	QComboBox *GUIBox;
	QComboBox *INameEdit;
	QPushButton *SetGUIButton;



	



protected:
	




};

#endif