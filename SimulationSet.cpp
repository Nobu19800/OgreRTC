/*!
 * @file  SimulationSet.cpp
 * @brief シミュレーション設定用ウィンドウ
 *
 */

#include "SimulationSet.h"



#include "QtMacro.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>





/**
*@brief シミュレーション設定用ウィジェットのコンストラクタ
* @param parent 親ウィジェット
*/
SimulationSetWidget::SimulationSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
{
	up_flag = true;
	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;

	StartButton = new QPushButton(tc->toUnicode("開始"));
	connect(StartButton, SIGNAL(clicked()), this, SLOT(StartSlot()));
	layout->addWidget(StartButton);

	StopButton = new QPushButton(tc->toUnicode("停止"));
	connect(StopButton, SIGNAL(clicked()), this, SLOT(StopSlot()));
	layout->addWidget(StopButton);

	RestartButton = new QPushButton(tc->toUnicode("再開"));
	connect(RestartButton, SIGNAL(clicked()), this, SLOT(RestartSlot()));
	layout->addWidget(RestartButton);

	ResetButton = new QPushButton(tc->toUnicode("初期化"));
	connect(ResetButton, SIGNAL(clicked()), this, SLOT(ResetSlot()));
	layout->addWidget(ResetButton);


	GravityspinBox = SetDoubleSpinBox(tc->toUnicode("重力"), 10000.0, -10000.0, layout);
	GravityspinBox->setValue(-9.8);
	connect(GravityspinBox, SIGNAL(valueChanged(double)), this, SLOT(GravitySlot(double)));


	CFMspinBox = SetDoubleSpinBox(tc->toUnicode("CFM(x1e-10)"), 100000000.0, 0.0, layout);
	CFMspinBox->setValue(10000);
	connect(CFMspinBox, SIGNAL(valueChanged(double)), this, SLOT(CFMSlot(double)));


	ERPspinBox = SetDoubleSpinBox(tc->toUnicode("ERP"), 100000000.0, 0.0, layout);
	ERPspinBox->setValue(0.2);
	connect(ERPspinBox, SIGNAL(valueChanged(double)), this, SLOT(ERPSlot(double)));

	gCFMspinBox = SetDoubleSpinBox(tc->toUnicode("接触のCFM(x1e-10)"), 100000000.0, 0.0, layout);
	gCFMspinBox->setValue(1);
	connect(gCFMspinBox, SIGNAL(valueChanged(double)), this, SLOT(gCFMSlot(double)));

	gERPspinBox = SetDoubleSpinBox(tc->toUnicode("接触のERP"), 100000000.0, 0.0, layout);
	gERPspinBox->setValue(0.8);
	connect(gERPspinBox, SIGNAL(valueChanged(double)), this, SLOT(gERPSlot(double)));

	gMuspinBox = SetDoubleSpinBox(tc->toUnicode("摩擦"), 1000000.0, 0.0, layout);
	gMuspinBox->setValue(0);
	connect(gMuspinBox, SIGNAL(valueChanged(double)), this, SLOT(gMuSlot(double)));

	STimespinBox = SetDoubleSpinBox(tc->toUnicode("サンプリングタイム[ms]"), 1000.0, 0.0, layout);
	STimespinBox->setValue(10);
	connect(STimespinBox, SIGNAL(valueChanged(double)), this, SLOT(STimeSlot(double)));

	SleepTimespinBox = SetDoubleSpinBox(tc->toUnicode("待ち時間[ms]"), 1000.0, 0.0, layout);
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
	QGroupBox *scaleGroup = new QGroupBox(tc->toUnicode("拡大率"));
	scaleGroup->setLayout(scaleLayout);
	layout->addWidget(scaleGroup);


	layout->addStretch();
	
	

	setLayout(layout);
	
}

/**
*@brief シミュレーション設定用ウィジェットのデストラクタ
*/
SimulationSetWidget::~SimulationSetWidget(void)
{

}

/**
*@brief シミュレーションの設定をウィジェットに反映させるときのスロット
*/
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


/**
*@brief リセットボタンを押したときのスロット
*/
void SimulationSetWidget::ResetSlot()
{
	EC->mSim->Reset();
}


/**
*@brief 重力加速度設定スピンボックスの値を変更したときのスロット
* @param value 重力加速度
*/
void SimulationSetWidget::GravitySlot(double value)
{
	double g = GravityspinBox->value();
	if(EC)
	{
		EC->mSim->SetGravity(g);
	}
}

/**
*@brief CFM設定スピンボックスの値を変更したときのスロット
* @param value CFM
*/
void SimulationSetWidget::CFMSlot(double value)
{
	double c = CFMspinBox->value() * (1e-10);
	if(EC)
	{
		EC->mSim->SetCFM(c);
	}
}

/**
*@brief ERP設定スピンボックスの値を変更したときのスロット
* @param value ERP
*/
void SimulationSetWidget::ERPSlot(double value)
{
	double e = ERPspinBox->value();
	if(EC)
	{
		EC->mSim->SetERP(e);
	}
}

/**
*@brief 接触時のCFM設定スピンボックスの値を変更したときのスロット
* @param value CFM
*/
void SimulationSetWidget::gCFMSlot(double value)
{
	double gc = gCFMspinBox->value() * (1e-10);
	if(EC)
	{
		EC->mSim->SetGroundCFM(gc);
	}
}

/**
*@brief 接触時のERP設定スピンボックスの値を変更したときのスロット
* @param value ERP
*/
void SimulationSetWidget::gERPSlot(double value)
{
	double ge = gERPspinBox->value();
	if(EC)
	{
		EC->mSim->SetGroundERP(ge);
	}
}

/**
*@brief 速度重視ボタンを押したときのスロット
*/
void SimulationSetWidget::QuiqSlot()
{
	if(EC)
	{
		EC->mSim->SetQuiq(true);
	}
}

/**
*@brief 精度重視ボタンを押したときのスロット
*/
void SimulationSetWidget::unQuiqSlot()
{
	if(EC)
	{
		EC->mSim->SetQuiq(false);
	}
}

/**
*@brief 開始ボタンを押したときのスロット
*/
void SimulationSetWidget::StartSlot()
{
	if(EC)
	{
		EC->mSim->startSim();
	}
}

/**
*@brief 再開始ボタンを押したときのスロット
*/
void SimulationSetWidget::RestartSlot()
{
	if(EC)
	{
		EC->mSim->restartSim();
	}
}

/**
*@brief 摩擦設定スピンボックスの値を変更したときのスロット
* @param value 摩擦係数
*/
void SimulationSetWidget::gMuSlot(double value)
{
	double gm = gMuspinBox->value();
	if(EC)
	{
		EC->mSim->SetGroundMu(gm);
	}
}

/**
*@brief サンプリングタイム設定スピンボックスの値を変更したときのスロット
* @param value サンプリングタイム
*/
void SimulationSetWidget::STimeSlot(double value)
{
	double st = STimespinBox->value()/ 1000.;
	if(EC)
	{
		EC->mSim->SetSamplingTime(st);
	}

}

/**
*@brief 各フレームでの待ち時間設定スピンボックスの値を変更したときのスロット
* @param value 待ち時間
*/
void SimulationSetWidget::SleepTimeSlot(double value)
{
	double t = SleepTimespinBox->value() / 1000.;
	if(EC)
	{
		EC->mSim->SetSleepTime(t);
	}
}

/**
*@brief 拡大率設定スピンボックスの値を反映する関数
*/
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

/**
*@brief 3Dモデルとシミュレーションの拡大率(X軸)設定スピンボックスの値を変更したときのスロット
* @param value 位置(X)
*/
void SimulationSetWidget::ScaleXSlot(double value)
{
	SetScale();
}

/**
*@brief 3Dモデルとシミュレーションの拡大率(Y軸)設定スピンボックスの値を変更したときのスロット
* @param value 位置(Y)
*/
void SimulationSetWidget::ScaleYSlot(double value)
{
	SetScale();
}

/**
*@brief 3Dモデルとシミュレーションの拡大率(Z軸)設定スピンボックスの値を変更したときのスロット
* @param value 位置(Z)
*/
void SimulationSetWidget::ScaleZSlot(double value)
{
	SetScale();
}

/**
*@brief 停止ボタンを押したときのスロット
*/
void SimulationSetWidget::StopSlot()
{
	if(EC)
	{
		EC->mSim->stopSim();
	}
}