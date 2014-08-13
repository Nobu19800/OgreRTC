#ifndef PORTSET_H
#define PORTSET_H

#include <QtGui>


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
class QLayout;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
class Compiler;
class QTextCursor;
class QTreeWidget;
class QDoubleSpinBox;
QT_END_NAMESPACE


class PortSetWidget : public QWidget
{
	Q_OBJECT

public:
	PortSetWidget(QWidget *parent = 0);
	~PortSetWidget(void);

private slots:
	void SetSlot();
	void NameSlot(int value);
	void DestroySlot();
	void UpdateList();


private:
	
	
	

	QTextCodec* tc;
	QComboBox *NameEdit;
	QComboBox *TypeBox;
	QPushButton *SetButton;
	QPushButton *DestroyButton;
	
	

	



protected:
	




};

#endif