/*!
 * @file  QtMacro.h
 * @brief Qt関連の関数
 *
 */

#ifndef QtMacro_H
#define QtMacro_H

#include <QtWidgets>


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


/**
*@brief スピンボックス作成の関数
* @param name 名前
* @param Max スピンボックスの最大値
* @param Min スピンボックスの最小値
* @param layout 追加するレイアウト
* @return スピンボックス
*/
QSpinBox *SetSpinBox(QString name, int Max, int Min, QBoxLayout *layout);

/**
*@brief スピンボックス(Double型)作成の関数
* @param name 名前
* @param Max スピンボックスの最大値
* @param Min スピンボックスの最小値
* @param layout 追加するレイアウト
* @return スピンボックス
*/
QDoubleSpinBox *SetDoubleSpinBox(QString name, double Max, double Min, QBoxLayout *layout);

#endif