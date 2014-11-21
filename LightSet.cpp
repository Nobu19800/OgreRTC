#include "LightSet.h"


#include "MyQtMacro.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>

#include "MyLight.h"




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

//----------------------------------------------------------------------------------------

LightSetWidget::~LightSetWidget(void)
{

}

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
				MyLight *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					ml->SetPosition(px, py, pz);
				}
			}

		}
	}
}
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
				MyLight *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					ml->setColor(red, green, blue);
				}
			}

		}
	}
}
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
				MyLight *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					ml->SetVisible(visi);
				}
			}

		}
	}
}

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
			
			MyLight *ml = EC->CreateQtLight(n.c_str());
			ml->SetPosition(px, py, pz);
			ml->setColor(red, green, blue);
			
			

			
			UpdateList();
			emit UpdateLight();
			NameEdit->setCurrentIndex(NameEdit->count()-1);
			
		}
	}
}
void LightSetWidget::NameSlot(int value)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		MyLight *ml = EC->getLightByName(n.c_str());
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
void LightSetWidget::PosXSlot(double value)
{
	UpdatePos();
}
void LightSetWidget::PosYSlot(double value)
{
	UpdatePos();
}
void LightSetWidget::PosZSlot(double value)
{
	UpdatePos();
}

void LightSetWidget::RedSlot(double value)
{
	UpdateColor();
}
void LightSetWidget::GreenSlot(double value)
{
	UpdateColor();
}
void LightSetWidget::BlueSlot(double value)
{
	UpdateColor();
}
void LightSetWidget::VisibleSlot()
{
	UpdateVisi(true);
}
void LightSetWidget::unVisibleSlot()
{
	UpdateVisi(false);
}


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
				MyLight *ml = EC->getLightByName(n.c_str());
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

