/*!
 * @file  GUITextSet.h
 * @brief GUIのテキスト設定用ウインドウ
 *
 */

#ifndef GUITEXTSET_H
#define GUITEXTSET_H

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
 * @class GUITextSetWidget
*@brief GUIのテキスト設定用ウィジェット
*/
class GUITextSetWidget : public QWidget
{
	Q_OBJECT

public:
	/**
	*@brief コンストラクタ
	*@param parent 親ウィジェット
	*/
	GUITextSetWidget(QWidget *parent = 0);
	/**
	*@brief デストラクタ
	*/
	~GUITextSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/**
	*@brief GUIが追加、削除された時のスロット
	*/
	void UpdateGUI();
	
	/**
	*@brief GUIの設定をウィジェットに反映させるときのスロット
	*/
	void UpdateList();

private slots:
	
	/**
	*@brief テキスト設定ボタンを押したときのスロット
	*/
	void SetSlot();
	
	/**
	*@brief フォントサイズ設定スピンボックスの値を変更したときのスロット
	* @param fs フォントサイズ
	*/
	void FontSizeSlot(int fs);
	/**
	*@brief テキストの位置を上端に設定するスロット
	*/
	void TextTopAlignedSlot();
	/**
	*@brief テキストの位置を下端に設定するスロット
	*/
	void BottomAlignedSlot();
	/**
	*@brief テキストの位置を縦中央に設定するスロット
	*/
	void VertCentredSlot();
	/**
	*@brief テキストの位置を左端に設定するスロット
	*単語の途中で改行する
	*/
	void WordWrapLeftAlignedSlot();
	/**
	*@brief テキストの位置を右端に設定するスロット
	*単語の途中で改行する
	*/
	void WordWrapRightAlignedSlot();
	/**
	*@brief テキストの位置を中央に設定するスロット
	*単語の途中で改行する
	*/
	void WordWrapCentredSlot();
	/**
	*@brief テキストの位置を左端に設定するスロット
	*/
	void LeftAlignedSlot();
	/**
	*@brief テキストの位置を右端に設定するスロット
	*/
	void RightAlignedSlot();
	/**
	*@brief テキストの位置を横中央に設定するスロット
	*/
	void HorzCentredSlot();
	
	/**
	*@brief 設定初期化ボタンを押したときのスロット
	*/
	void ClearPropertiesSlot();
	
	/**
	*@brief GUIの名前コンボボックスの番号が変わったときのスロット
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