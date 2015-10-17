/*!
 * @file  LightSet.cpp
 * @brief 光源の設定用ウインドウ
 *
 */

#include "LightSet.h"


#include "QtMacro.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>

#include "LightObj.h"



/**
*@brief 光源の作成、設定用ウィジェットのコンストラクタ
* @param parent 親ウィジェット
*/
LightSetWidget::LightSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
{
	up_flag = true;
	
	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;

	NameEdit = new QComboBox();
	NameEdit->setLineEdit(new QLineEdit());
	connect(NameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NameSlot(int)));

	layout->addWidget(NameEdit);

	SetButton = new QPushButton(tc->toUnicode("作成"));
	connect(SetButton, SIGNAL(clicked()), this, SLOT(SetSlot()));
	layout->addWidget(SetButton);

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


	QVBoxLayout *ColorLayout =  new QVBoxLayout();
	RedspinBox = SetDoubleSpinBox(tc->toUnicode("赤"), 1, 0, ColorLayout);
	RedspinBox->setSingleStep(0.1);
	connect(RedspinBox, SIGNAL(valueChanged(double)), this, SLOT(RedSlot(double)));
	GreenspinBox = SetDoubleSpinBox(tc->toUnicode("緑"), 1, 0, ColorLayout);
	GreenspinBox->setSingleStep(0.1);
	connect(GreenspinBox, SIGNAL(valueChanged(double)), this, SLOT(GreenSlot(double)));
	BluespinBox = SetDoubleSpinBox(tc->toUnicode("青"),1, 0, ColorLayout);
	BluespinBox->setSingleStep(0.1);
	connect(BluespinBox, SIGNAL(valueChanged(double)), this, SLOT(BlueSlot(double)));
	QGroupBox *colorGroup = new QGroupBox(tc->toUnicode("色"));
	colorGroup->setLayout(ColorLayout);
	layout->addWidget(colorGroup);


	

	VisibleButton = new QPushButton(tc->toUnicode("表示"));
	connect(VisibleButton, SIGNAL(clicked()), this, SLOT(VisibleSlot()));
	layout->addWidget(VisibleButton);

	unVisibleButton = new QPushButton(tc->toUnicode("非表示"));
	connect(unVisibleButton, SIGNAL(clicked()), this, SLOT(unVisibleSlot()));
	layout->addWidget(unVisibleButton);

	DestroyButton = new QPushButton(tc->toUnicode("削除"));
	connect(DestroyButton, SIGNAL(clicked()), this, SLOT(DestroySlot()));
	layout->addWidget(DestroyButton);



	layout->addStretch();
	
	

	setLayout(layout);
	
}


/**
*@brief 光源の作成、設定用ウィジェットのデストラクタ
*/
LightSetWidget::~LightSetWidget(void)
{

}


/**
*@brief 位置設定スピンボックスの値を反映する関数
*/
void LightSetWidget::UpdatePos()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
		float px = PosXspinBox->value();
		float py = PosYspinBox->value();
		float pz = PosZspinBox->value();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				LightObj *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					ml->SetPosition(px, py, pz);
				}
			}

		}
	}
}

/**
*@brief 色設定スピンボックスの値を反映する関数
*/
void LightSetWidget::UpdateColor()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
		float red = RedspinBox->value();
		float green = GreenspinBox->value();
		float blue = BluespinBox->value();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				LightObj *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					ml->setColor(red, green, blue);
				}
			}

		}
	}
}

/**
*@brief 表示設定ボタンを反映する関数
* @param visi trueで表示、falseで非表示
*/
void LightSetWidget::UpdateVisi(bool visi)
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				LightObj *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					ml->SetVisible(visi);
				}
			}

		}
	}
}


/**
*@brief 作成ボタンを押したときのスロット
*/
void LightSetWidget::SetSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	float px = PosXspinBox->value();
	float py = PosYspinBox->value();
	float pz = PosZspinBox->value();

	float red = RedspinBox->value();
	float green = GreenspinBox->value();
	float blue = BluespinBox->value();


	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else if(EC->getLightByName(n.c_str()))
		{
			return;
		}
		else
		{
			
			LightObj *ml = EC->CreateQtLight(n.c_str());
			ml->SetPosition(px, py, pz);
			ml->setColor(red, green, blue);
			
			

			
			UpdateList();
			emit UpdateLight();
			NameEdit->setCurrentIndex(NameEdit->count()-1);
			
		}
	}
}

/**
*@brief 名前コンボボックスの番号が変わったときのスロット
* @param value 番号
*/
void LightSetWidget::NameSlot(int value)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		LightObj *ml = EC->getLightByName(n.c_str());
		if(ml)
		{
			up_flag = false;
			PosXspinBox->setValue(ml->mNode->pos_x);
			PosYspinBox->setValue(ml->mNode->pos_y);
			PosZspinBox->setValue(ml->mNode->pos_z);


			RedspinBox->setValue(ml->red);
			GreenspinBox->setValue(ml->green);
			BluespinBox->setValue(ml->blue);
			

			

			up_flag = true;

		}
		
	}
}

/**
*@brief 位置設定スピンボックスの値(X座標)を変更したときのスロット
* @param value 位置(X)
*/
void LightSetWidget::PosXSlot(double value)
{
	UpdatePos();
}

/**
*@brief 位置設定スピンボックスの値(Y座標)を変更したときのスロット
* @param value 位置(Y)
*/
void LightSetWidget::PosYSlot(double value)
{
	UpdatePos();
}

/**
*@brief 位置設定スピンボックスの値(Z座標)を変更したときのスロット
* @param value 位置(Z)
*/
void LightSetWidget::PosZSlot(double value)
{
	UpdatePos();
}

/**
*@brief 色設定スピンボックスの値(赤)を変更したときのスロット
* @param value 輝度(赤)
*/
void LightSetWidget::RedSlot(double value)
{
	UpdateColor();
}

/**
*@brief 色設定スピンボックスの値(緑)を変更したときのスロット
* @param value 輝度(緑)
*/
void LightSetWidget::GreenSlot(double value)
{
	UpdateColor();
}

/**
*@brief 色設定スピンボックスの値(青)を変更したときのスロット
* @param value 輝度(青)
*/
void LightSetWidget::BlueSlot(double value)
{
	UpdateColor();
}

/**
*@brief 表示設定ボタンを押したときのスロット
*/
void LightSetWidget::VisibleSlot()
{
	UpdateVisi(true);
}

/**
*@brief 非表示設定ボタンを押したときのスロット
*/
void LightSetWidget::unVisibleSlot()
{
	UpdateVisi(false);
}

/**
*@brief 削除ボタンを押したときのスロット
*/
void LightSetWidget::DestroySlot()
{
	
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				LightObj *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					EC->DestroyQtLight(ml);
					UpdateList();
					emit UpdateLight();
				}
			}

		}
	}
}


/**
*@brief 光源の設定をウィジェットに反映させるときのスロット
*/
void LightSetWidget::UpdateList()
{
	if(EC)
	{
		NameEdit->clear();
		for(int i=0;i < EC->QtLights.size();i++)
		{
			NameEdit->addItem(EC->QtLights[i]->name.c_str());
		}
		
	}
	
}

