#include <QtGui/QApplication>
#include <QtGui/QPainter>

#include "MyQtMacro.h"

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

