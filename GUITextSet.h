#ifndef GUITEXTSET_H
#define GUITEXTSET_H

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
* GUIのテキスト設定用ウィジェット
*/

class GUITextSetWidget : public QWidget
{
	Q_OBJECT

public:
	GUITextSetWidget(QWidget *parent = 0);
	~GUITextSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/*
	*GUIが追加、削除された時のスロット
	*/
	void UpdateGUI();
	/*
	*GUIの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

private slots:
	/*
	*テキスト設定ボタンを押したときのスロット
	*/
	void SetSlot();
	/*
	*フォントサイズ設定スピンボックスの値を変更したときのスロット
	*/
	void FontSizeSlot(int);
	/*
	*テキストの位置設定ボタンを押したときのスロット
	*/
	void TextTopAlignedSlot();
	void BottomAlignedSlot();
	void VertCentredSlot();
	void WordWrapLeftAlignedSlot();
	void WordWrapRightAlignedSlot();
	void WordWrapCentredSlot();
	void LeftAlignedSlot();
	void RightAlignedSlot();
	void HorzCentredSlot();
	/*
	*設定初期化ボタンを押したときのスロット
	*/
	void ClearPropertiesSlot();
	/*
	*GUIの名前コンボボックスの番号が変わったときのスロット
	*/
	void NameSlot(int value);





private:
	QComboBox *NameEdit;
	QPushButton *SetButton;
	QSpinBox *FontSizespinBox;
	QTextEdit *TextEdit;
	QPushButton *TextTopAlignedButton;
	QPushButton *BottomAlignedButton;
	QPushButton *VertCentredButton;
	QPushButton *WordWrapLeftAlignedButton;
	QPushButton *WordWrapRightAlignedButton;
	QPushButton *WordWrapCentredButton;
	QPushButton *LeftAlignedButton;
	QPushButton *RightAlignedButton;
	QPushButton *HorzCentredButton;
	QPushButton *ClearPropertiesButton;

	
	
	

	QTextCodec* tc;

	



protected:
	




};

#endif