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
* �m�[�h�̐ݒ�p�E�B�W�F�b�g
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
	*�m�[�h�̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();

private slots:
	/*
	*�I�u�W�F�N�g�̎�ރR���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
	*/
	void NumSlot(int value);
	void NameSlot(int value);
	/*
	*�ڑ��{�^�����������Ƃ��̃X���b�g
	*/
	void AttachSlot();
	/*
	*�����{�^�����������Ƃ��̃X���b�g
	*/
	void DettachSlot();
	/*
	*�ڑ������I�u�W�F�N�g�̃R���{�{�b�N�X�̔ԍ����ς�����Ƃ��̃X���b�g
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