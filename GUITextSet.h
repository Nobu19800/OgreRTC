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
* GUI�̃e�L�X�g�ݒ�p�E�B�W�F�b�g
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
	*GUI���ǉ��A�폜���ꂽ���̃X���b�g
	*/
	void UpdateGUI();
	/*
	*GUI�̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();

private slots:
	/*
	*�e�L�X�g�ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void SetSlot();
	/*
	*�t�H���g�T�C�Y�ݒ�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void FontSizeSlot(int);
	/*
	*�e�L�X�g�̈ʒu�ݒ�{�^�����������Ƃ��̃X���b�g
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
	*�ݒ菉�����{�^�����������Ƃ��̃X���b�g
	*/
	void ClearPropertiesSlot();
	/*
	*GUI�̖��O�R���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
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