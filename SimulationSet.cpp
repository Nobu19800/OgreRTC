#include "SimulationSet.h"



#include "MyQtMacro.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>






SimulationSetWidget::SimulationSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))
{
	up_flag = true;
	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;

	StartButton = new QPushButton(tc->toUnicode("ŠJŽn"));
	connect(StartButton, SIGNAL(clicked()), this, SLOT(StartSlot()));
	layout->addWidget(StartButton);

	StopButton = new QPushButton(tc->toUnicode("’âŽ~"));
	connect(StopButton, SIGNAL(clicked()), this, SLOT(StopSlot()));
	layout->addWidget(StopButton);

	RestartButton = new QPushButton(tc->toUnicode("ÄŠJ"));
	connect(RestartButton, SIGNAL(clicked()), this, SLOT(RestartSlot()));
	layout->addWidget(RestartButton);

	ResetButton = new QPushButton(tc->toUnicode("‰Šú‰»"));
	connect(ResetButton, SIGNAL(clicked()), this, SLOT(ResetSlot()));
	layout->addWidget(ResetButton);


	GravityspinBox = SetDoubleSpinBox(tc->toUnicode("d—Í"), 10000.0, -10000.0, layout);
	GravityspinBox->setValue(-9.8);
	connect(GravityspinBox, SIGNAL(valueChanged(double)), this, SLOT(GravitySlot(double)));


	CFMspinBox = SetDoubleSpinBox(tc->toUnicode("CFM(x1e-10)"), 100000000.0, 0.0, layout);
	CFMspinBox->setValue(10000);
	connect(CFMspinBox, SIGNAL(valueChanged(double)), this, SLOT(CFMSlot(double)));


	ERPspinBox = SetDoubleSpinBox(tc->toUnicode("ERP"), 100000000.0, 0.0, layout);
	ERPspinBox->setValue(0.2);
	connect(ERPspinBox, SIGNAL(valueChanged(double)), this, SLOT(ERPSlot(double)));

	gCFMspinBox = SetDoubleSpinBox(tc->toUnicode("ÚG‚ÌCFM(x1e-10)"), 100000000.0, 0.0, layout);
	gCFMspinBox->setValue(1);
	connect(gCFMspinBox, SIGNAL(valueChanged(double)), this, SLOT(gCFMSlot(double)));

	gERPspinBox = SetDoubleSpinBox(tc->toUnicode("ÚG‚ÌERP"), 100000000.0, 0.0, layout);
	gERPspinBox->setValue(0.8);
	connect(gERPspinBox, SIGNAL(valueChanged(double)), this, SLOT(gERPSlot(double)));

	gMuspinBox = SetDoubleSpinBox(tc->toUnicode("–€ŽC"), 1000000.0, 0.0, layout);
	gMuspinBox->setValue(0);
	connect(gMuspinBox, SIGNAL(valueChanged(double)), this, SLOT(gMuSlot(double)));

	STimespinBox = SetDoubleSpinBox(tc->toUnicode("ƒTƒ“ƒvƒŠƒ“ƒOƒ^ƒCƒ€[ms]"), 1000.0, 0.0, layout);
	STimespinBox->setValue(10);
	connect(STimespinBox, SIGNAL(valueChanged(double)), this, SLOT(STimeSlot(double)));

	SleepTimespinBox = SetDoubleSpinBox(tc->toUnicode("‘Ò‚¿ŽžŠÔ[ms]"), 1000.0, 0.0, layout);
	SleepTimespinBox->setValue(0);
	connect(SleepTimespinBox, SIGNAL(valueChanged(double)), this, SLOT(SleepTimeSlot(double)));

	QVBoxLayout *scaleLayout =  new QVBoxLayout();
	ScaleXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 10000.0, 0.01, scaleLayout);
	ScaleXspinBox->setValue(1);
	connect(ScaleXspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleXSlot(double)));
	ScaleYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 10000.0, 0.01, scaleLayout);
	ScaleYspinBox->setValue(1);
	connect(ScaleYspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleYSlot(double)));
	ScaleZspinBox = SetDoubleSpinBox(tc->toUnicode("Z"), 10000.0, 0.01, scaleLayout);
	ScaleZspinBox->setValue(1);
	connect(ScaleZspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleZSlot(double)));
	QGroupBox *scaleGroup = new QGroupBox(tc->toUnicode("Šg‘å—¦"));
	scaleGroup->setLayout(scaleLayout);
	layout->addWidget(scaleGroup);


	layout->addStretch();
	
	

	setLayout(layout);
	
}

//----------------------------------------------------------------------------------------

SimulationSetWidget::~SimulationSetWidget(void)
{

}

void SimulationSetWidget::UpdateList()
{
	if(EC)
	{
		up_flag = false;
		GravityspinBox->setValue(EC->mSim->GRABITY);
		CFMspinBox->setValue(EC->mSim->CFM / (1e-10));
		ERPspinBox->setValue(EC->mSim->ERP);

		gCFMspinBox->setValue(EC->mSim->gCFM / (1e-10));
		gERPspinBox->setValue(EC->mSim->gERP);
		gMuspinBox->setValue(EC->mSim->gMu);

		
		STimespinBox->setValue(EC->mSim->sTime*1000.);
		SleepTimespinBox->setValue(EC->mSim->SleepTime*1000.);

		ScaleXspinBox->setValue(EC->mSim->scale_x);
		ScaleYspinBox->setValue(EC->mSim->scale_y);
		ScaleZspinBox->setValue(EC->mSim->scale_z);

		
		up_flag = true;
	}
}

void SimulationSetWidget::ResetSlot()
{
	EC->mSim->Reset();
}
	
void SimulationSetWidget::GravitySlot(double value)
{
	double g = GravityspinBox->value();
	if(EC)
	{
		EC->mSim->SetGravity(g);
	}
}
void SimulationSetWidget::CFMSlot(double value)
{
	double c = CFMspinBox->value() * (1e-10);
	if(EC)
	{
		EC->mSim->SetCFM(c);
	}
}
void SimulationSetWidget::ERPSlot(double value)
{
	double e = ERPspinBox->value();
	if(EC)
	{
		EC->mSim->SetERP(e);
	}
}
void SimulationSetWidget::gCFMSlot(double value)
{
	double gc = gCFMspinBox->value() * (1e-10);
	if(EC)
	{
		EC->mSim->SetGroundCFM(gc);
	}
}
void SimulationSetWidget::gERPSlot(double value)
{
	double ge = gERPspinBox->value();
	if(EC)
	{
		EC->mSim->SetGroundERP(ge);
	}
}
void SimulationSetWidget::QuiqSlot()
{
	if(EC)
	{
		EC->mSim->SetQuiq(true);
	}
}

void SimulationSetWidget::unQuiqSlot()
{
	if(EC)
	{
		EC->mSim->SetQuiq(false);
	}
}

void SimulationSetWidget::StartSlot()
{
	if(EC)
	{
		EC->mSim->startSim();
	}
}
void SimulationSetWidget::RestartSlot()
{
	if(EC)
	{
		EC->mSim->restartSim();
	}
}

void SimulationSetWidget::gMuSlot(double value)
{
	double gm = gMuspinBox->value();
	if(EC)
	{
		EC->mSim->SetGroundMu(gm);
	}
}
void SimulationSetWidget::STimeSlot(double value)
{
	double st = STimespinBox->value()/ 1000.;
	if(EC)
	{
		EC->mSim->SetSamplingTime(st);
	}

}
void SimulationSetWidget::SleepTimeSlot(double value)
{
	double t = SleepTimespinBox->value() / 1000.;
	if(EC)
	{
		EC->mSim->SetSleepTime(t);
	}
}
void SimulationSetWidget::SetScale()
{
	float sx = ScaleXspinBox->value();
	float sy = ScaleYspinBox->value();
	float sz = ScaleZspinBox->value();


	if(EC)
	{
		EC->mSim->SetScale(sx, sy, sz);
	}

}
void SimulationSetWidget::ScaleXSlot(double value)
{
	SetScale();
}
void SimulationSetWidget::ScaleYSlot(double value)
{
	SetScale();
}
void SimulationSetWidget::ScaleZSlot(double value)
{
	SetScale();
}

void SimulationSetWidget::StopSlot()
{
	if(EC)
	{
		EC->mSim->stopSim();
	}
}