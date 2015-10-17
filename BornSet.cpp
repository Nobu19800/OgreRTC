/*!
 * @file  BornSet.cpp
 * @brief ボーンの設定用ウインドウ
 *
 */

#include "BornSet.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#include "QtMacro.h"


#include "LinkObj.h"


/**
*@brief ボーンの設定用ウィジェットのコンストラクタ
* @param parent 親ウィジェット
*/
BornSetWidget::BornSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
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

/**
*@brief ボーンの設定用ウィジェットのデストラクタ
*/
BornSetWidget::~BornSetWidget(void)
{

}

/**
*@brief 作成ボタンを押したときのスロット
*/
void BornSetWidget::SetSlot()
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
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
			LinkObj *ml = EC->getBodyByName(n.c_str());
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

/**
*@brief 位置設定スピンボックスの値(X座標)を変更したときのスロット
* @param value 位置(X)
*/
void BornSetWidget::PosXSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float py = PosYspinBox->value();
	float pz = PosZspinBox->value();
}

/**
*@brief 位置設定スピンボックスの値(Y座標)を変更したときのスロット
* @param value 位置(Y)
*/
void BornSetWidget::PosYSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float px = PosXspinBox->value();
	float pz = PosZspinBox->value();
}


/**
*@brief 位置設定スピンボックスの値(Z座標)を変更したときのスロット
* @param value 位置(Z)
*/
void BornSetWidget::PosZSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float px = PosXspinBox->value();
	float py = PosYspinBox->value();
	
}

/**
*@brief 拡大率設定スピンボックスの値(X軸方向)を変更したときのスロット
* @param value 拡大率(X)
*/
void BornSetWidget::ScaleXSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float sy = ScaleYspinBox->value();
	float sz = ScaleZspinBox->value();
}

/**
*@brief 拡大率設定スピンボックスの値(Y軸方向)を変更したときのスロット
* @param value 拡大率(Y)
*/
void BornSetWidget::ScaleYSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float sx = ScaleXspinBox->value();
	float sz = ScaleZspinBox->value();
}

/**
*@brief 拡大率設定スピンボックスの値(Z軸方向)を変更したときのスロット
* @param value 拡大率(Z)
*/
void BornSetWidget::ScaleZSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float sx = ScaleXspinBox->value();
	float sy = ScaleYspinBox->value();
}

/**
*@brief 姿勢設定スピンボックスの値(ロール角)を変更したときのスロット
* @param value 角度(ロール)
*/
void BornSetWidget::RollSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float pitch = PitchspinBox->value();
	float yaw = YawspinBox->value();
}

/**
*@brief 姿勢設定スピンボックスの値(ピッチ角)を変更したときのスロット
* @param value 角度(ピッチ)
*/
void BornSetWidget::PitchSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float roll = RollspinBox->value();
	float yaw = YawspinBox->value();
}

/**
*@brief 姿勢設定スピンボックスの値(ヨー角)を変更したときのスロット
* @param value 角度(ヨー)
*/
void BornSetWidget::YawSlot(double value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	int num = NameEdit->value();
	float roll = RollspinBox->value();
	float pitch = PitchspinBox->value();
}

/**
*@brief リセットボタンを押したときのスロット
*/
void BornSetWidget::ResetSlot()
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();
	
	

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			LinkObj *ml = EC->getBodyByName(n.c_str());
			
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


/**
*@brief ボディの名前コンボボックスの番号が変わったときのスロット
* @param value 番号
*/
void BornSetWidget::BodyNameSlot(int value)
{
	std::string n = (const char*)BodyNameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			LinkObj *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				NameEdit->setMaximum(ml->GetBornNum());
			}
		}
		
	}
}


/**
*@brief 3Dモデルが追加、削除されたときのスロット
*/
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