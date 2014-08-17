#ifndef MYQTMACRO_H
#define MYQTMACRO_H

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
class QLabel;
class QPushButton;
class QSpinBox;
class QDoubleSpinBox;
class QBoxLayout;
class QVBoxLayout;
class Compiler;
class QTextCursor;
class QTreeWidget;
QT_END_NAMESPACE

/*
*�X�s���{�b�N�X�쐬�̊֐�
*/
QSpinBox *SetSpinBox(QString name, int Max, int Min, QBoxLayout *layout);
/*
*�X�s���{�b�N�X(Double�^)�쐬�̊֐�
*/
QDoubleSpinBox *SetDoubleSpinBox(QString name, double Max, double Min, QBoxLayout *layout);

#endif