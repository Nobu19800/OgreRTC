#include "BornSet.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include "MyQtMacro.h"


#include "MyLink.h"



BornSetWidget::BornSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))
{
	
	QTextCodec* tc = QTextCodec::codecForLocale();
	
	QVBoxLayout *layout = new QVBoxLayout;

	BodyNameEdit = new QComboBox();
	connect(BodyNameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(BodyNameSlot(int)));
	layout->addWidget(BodyNameEdit);


	NameEdit = SetSpinBox(tc->toUnicode("番号"), 1, 0, layout);
	

	
	SetButton = new QPushButton(tc->toUnicode("作成"));
	connect(SetButton, SIGNAL(clicked()), this, SLOT(SetSlot()));
	layout->addWidget(SetButton);

	ResetButton = new QPushButton(tc->toUnicode("リセット"));
	connect(ResetButton, SIGNAL(clicked()), this, SLOT(ResetSlot()));
	layout->addWidget(ResetButton);

		
	QVBoxLayout *posLayout =  new QVBoxLayout();
	PosXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 1000.0, -1000.0, posLayout);
	connect(PosXspinBox, SIGNAL(valueChanged(double)), this, SLOT(PosXSlot(double)));
	PosYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 1000.0, -1000.0, posLayout);
	connect(PosYspinBox, SIGNAL(valueChanged(double)), this, SLOT(PosYSlot(double)));
	PosZspinBox = SetDoubleSpinBox(tc->toUnicode("Z"), 1000.0, -1000.0, posLayout);
	connect(PosZspinBox, SIGNAL(valueChanged(double)), this, SLOT(PosZSlot(double)));
	QGroupBox *posGroup = new QGroupBox(tc->toUnicode("位置"));
	posGroup->setLayout(posLayout);
	layout->addWidget(posGroup);


	QVBoxLayout *scaleLayout =  new QVBoxLayout();
	ScaleXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 10000.0, 0.01, scaleLayout);
	ScaleXspinBox->setValue(100.);
	connect(ScaleXspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleXSlot(double)));
	ScaleYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 10000.0, 0.01, scaleLayout);
	ScaleYspinBox->setValue(100.);
	connect(ScaleYspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleYSlot(double)));
	ScaleZspinBox = SetDoubleSpinBox(tc->toUnicode("Z"), 10000.0, 0.01, scaleLayout);
	ScaleZspinBox->setValue(100.);
	connect(ScaleZspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleZSlot(double)));
	QGroupBox *scaleGroup = new QGroupBox(tc->toUnicode("拡大率"));
	scaleGroup->setLayout(scaleLayout);
	layout->addWidget(scaleGroup);


	QVBoxLayout *angleLayout =  new QVBoxLayout();
	RollspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 360.0, 0.0, angleLayout);
	connect(RollspinBox, SIGNAL(valueChanged(double)), this, SLOT(RollSlot(double)));
	PitchspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 360.0, 0.0, angleLayout);
	connect(PitchspinBox, SIGNAL(valueChanged(double)), this, SLOT(PitchSlot(double)));
	YawspinBox = SetDoubleSpinBox(tc->toUnicode("Z"), 360.0, 0.0, angleLayout);
	connect(YawspinBox, SIGNAL(valueChanged(double)), this, SLOT(YawSlot(double)));
	QGroupBox *angleGroup = new QGroupBox(tc->toUnicode("姿勢"));
	angleGroup->setLayout(angleLayout);
	layout->addWidget(angleGroup);

	layout->addStretch();

	setLayout(layout);
	
}

//----------------------------------------------------------------------------------------

BornSetWidget::~BornSetWidget(void)
{

}

void BornSetWidget::SetSlot()
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float px = PosXspinBox->value();
	float py = PosYspinBox->value();
	float pz = PosZspinBox->value();

	float sx = ScaleXspinBox->value();
	float sy = ScaleYspinBox->value();
	float sz = ScaleZspinBox->value();

	float roll = RollspinBox->value();
	float pitch = PitchspinBox->value();
	float yaw = YawspinBox->value();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyLink *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				if(num < ml->GetBornNum())
				{
					ml->SetBornPosition(num, px, py, pz);
					ml->SetBornScale(num, sx, sy, sz);
					ml->SetBornOrientation(num, 1, 0, 0, 0);
					ml->SetBornRoll(num, roll);
					ml->SetBornPitch(num, pitch);
					ml->SetBornYaw(num, yaw);
				}
			}
		}
		
	}


	
}

void BornSetWidget::PosXSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float py = PosYspinBox->value();
	float pz = PosZspinBox->value();
}
void BornSetWidget::PosYSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float px = PosXspinBox->value();
	float pz = PosZspinBox->value();
}
void BornSetWidget::PosZSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float px = PosXspinBox->value();
	float py = PosYspinBox->value();
	
}
void BornSetWidget::ScaleXSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float sy = ScaleYspinBox->value();
	float sz = ScaleZspinBox->value();
}
void BornSetWidget::ScaleYSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float sx = ScaleXspinBox->value();
	float sz = ScaleZspinBox->value();
}
void BornSetWidget::ScaleZSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float sx = ScaleXspinBox->value();
	float sy = ScaleYspinBox->value();
}
void BornSetWidget::RollSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float pitch = PitchspinBox->value();
	float yaw = YawspinBox->value();
}
void BornSetWidget::PitchSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float roll = RollspinBox->value();
	float yaw = YawspinBox->value();
}
void BornSetWidget::YawSlot(double value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float roll = RollspinBox->value();
	float pitch = PitchspinBox->value();
}

void BornSetWidget::ResetSlot()
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();
	
	

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyLink *ml = EC->getBodyByName(n.c_str());
			
			if(ml)
			{
				if(ml->GetBornNum() != 0)
				{
					ml->ResetBorn();
				}
			}
		}
		
	}
}


void BornSetWidget::BodyNameSlot(int value)
{
	std::string n = BodyNameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyLink *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				NameEdit->setMaximum(ml->GetBornNum());
			}
		}
		
	}
}

void BornSetWidget::UpdateBody()
{
	if(EC)
	{
	
		BodyNameEdit->clear();
		for(int i=0;i < EC->QtLinks.size();i++)
		{
			BodyNameEdit->addItem(EC->QtLinks[i]->name.c_str());
		}
	}
}