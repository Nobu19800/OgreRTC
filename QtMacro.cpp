/*!
 * @file  QtMacro.cpp
 * @brief Qt関連の関数
 *
 */

#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>

#include "QtMacro.h"


/**
*@brief スピンボックス作成の関数
* @param name 名前
* @param Max スピンボックスの最大値
* @param Min スピンボックスの最小値
* @param layout 追加するレイアウト
* @return スピンボックス
*/
QSpinBox *SetSpinBox(QString name, int Max, int Min, QBoxLayout *layout)
{
	QVBoxLayout *subLayout = new QVBoxLayout();
	QLabel *Label = new QLabel(name);
	subLayout->addWidget(Label);
	QSpinBox *sb = new QSpinBox();
	sb->setMaximum(Max);
	sb->setMinimum(Min);
	subLayout->addWidget(sb);
	layout->addLayout(subLayout);

	return sb;
}


/**
*@brief スピンボックス(Double型)作成の関数
* @param name 名前
* @param Max スピンボックスの最大値
* @param Min スピンボックスの最小値
* @param layout 追加するレイアウト
* @return スピンボックス
*/
QDoubleSpinBox *SetDoubleSpinBox(QString name, double Max, double Min, QBoxLayout *layout)
{
	QVBoxLayout *subLayout = new QVBoxLayout();
	QLabel *Label = new QLabel(name);
	subLayout->addWidget(Label);
	QDoubleSpinBox *sb = new QDoubleSpinBox();
	sb->setMaximum(Max);
	sb->setMinimum(Min);
	subLayout->addWidget(sb);
	layout->addLayout(subLayout);

	return sb;
	
}

