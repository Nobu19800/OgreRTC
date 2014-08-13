#include "SoundSet.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include "MyQtMacro.h"



SoundSetWidget::SoundSetWidget(QWidget *parent) : 
QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))
{
	
	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;

	NameEdit = new QComboBox();
	NameEdit->setLineEdit(new QLineEdit());
	layout->addWidget(NameEdit);



	EngineVolumespinBox = SetDoubleSpinBox(tc->toUnicode("�S�̂̃{�����[��"),1000., 0, layout);
	connect(EngineVolumespinBox, SIGNAL(valueChanged(double)), this, SLOT(EngineVolumeSlot(double)));

	SpeedspinBox = SetDoubleSpinBox(tc->toUnicode("���x"),1000., 0, layout);
	connect(SpeedspinBox, SIGNAL(valueChanged(double)), this, SLOT(SpeedSlot(double)));

	VolumespinBox = SetDoubleSpinBox(tc->toUnicode("�{�����[��"),1000., 0, layout);
	connect(VolumespinBox, SIGNAL(valueChanged(double)), this, SLOT(VolumeSlot(double)));

	VolumePauseButton = new QPushButton(tc->toUnicode("�ꎞ��~"));
	connect(VolumePauseButton, SIGNAL(clicked()), this, SLOT(VolumePauseSlot()));
	layout->addWidget(VolumePauseButton);

	VolumeunPauseButton = new QPushButton(tc->toUnicode("�Đ�"));
	connect(VolumeunPauseButton, SIGNAL(clicked()), this, SLOT(VolumeunPauseSlot()));
	layout->addWidget(VolumeunPauseButton);

	PositionspinBox = SetDoubleSpinBox(tc->toUnicode("�ʒu"),1., 0, layout);
	connect(PositionspinBox, SIGNAL(valueChanged(double)), this, SLOT(PositionSlot(double)));

	StopButton = new QPushButton(tc->toUnicode("��~"));
	connect(StopButton, SIGNAL(clicked()), this, SLOT(StopSlot()));
	layout->addWidget(StopButton);

	ResetButton = new QPushButton(tc->toUnicode("���Z�b�g"));
	connect(ResetButton, SIGNAL(clicked()), this, SLOT(ResetSlot()));
	layout->addWidget(ResetButton);

	layout->addStretch();

	setLayout(layout);
	
}

//----------------------------------------------------------------------------------------

SoundSetWidget::~SoundSetWidget(void)
{

}


void SoundSetWidget::SetSlot()
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		EC->CreateSound(n.c_str(),false);
	}
}
void SoundSetWidget::EngineVolumeSlot(double value)
{

}
void SoundSetWidget::SpeedSlot(double value)
{

}
void SoundSetWidget::VolumeSlot(double value)
{

}
void SoundSetWidget::VolumePauseSlot()
{

}
void SoundSetWidget::VolumeunPauseSlot()
{

}
void SoundSetWidget::PositionSlot(double value)
{

}
void SoundSetWidget::StopSlot()
{

}
void SoundSetWidget::ResetSlot()
{

}
