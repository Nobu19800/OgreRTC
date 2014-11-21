#include "OtherSet.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#include "MyQtMacro.h"



OtherSetWidget::OtherSetWidget(QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
{
	

	QTextCodec* tc = QTextCodec::codecForLocale();
	
	QVBoxLayout *layout = new QVBoxLayout;

	QVBoxLayout *SkyBoxLayout =  new QVBoxLayout();
	SkyBoxButton = new QPushButton(tc->toUnicode("作成"));
	connect(SkyBoxButton, SIGNAL(clicked()), this, SLOT(SkyBoxSetSlot()));
	SkyBoxLayout->addWidget(SkyBoxButton);

	DelSkyBoxButton = new QPushButton(tc->toUnicode("削除"));
	connect(DelSkyBoxButton, SIGNAL(clicked()), this, SLOT(DelSkyBoxSetSlot()));
	SkyBoxLayout->addWidget(DelSkyBoxButton);

	SkyBoxEdit = new QComboBox();
	SkyBoxEdit->setLineEdit(new QLineEdit());
	SkyBoxEdit->addItem("Examples/TrippySkyBox");
	SkyBoxEdit->addItem("Examples/SpaceSkyBox");
	SkyBoxEdit->addItem("Examples/SceneSkyBox1");
	SkyBoxEdit->addItem("Examples/SceneCubeMap1");
	SkyBoxEdit->addItem("Examples/SceneSkyBox2");
	SkyBoxEdit->addItem("Examples/SceneCubeMap2");
	SkyBoxEdit->addItem("Examples/CloudyNoonSkyBox");
	SkyBoxEdit->addItem("Examples/StormySkyBox");
	SkyBoxEdit->addItem("Examples/EarlyMorningSkyBox");
	SkyBoxEdit->addItem("Examples/MorningSkyBox");
	SkyBoxEdit->addItem("Examples/MorningCubeMap");
	SkyBoxEdit->addItem("Examples/EveningSkyBox");
	SkyBoxEdit->addItem("Examples/DynamicCubeMap");
	SkyBoxEdit->addItem("Examples/CloudySky");
	SkyBoxEdit->addItem("Examples/RustySteel");
	SkyBoxEdit->addItem("Examples/Chrome");
	SkyBoxEdit->addItem("Examples/SpaceSkyPlane");
	
	SkyBoxLayout->addWidget(SkyBoxEdit);

	SkyBoxspinBox = SetSpinBox(tc->toUnicode("サイズ"), 10000, 1, SkyBoxLayout);
	SkyBoxspinBox->setValue(1000);
	connect(SkyBoxspinBox, SIGNAL(valueChanged(int)), this, SLOT(SkyBoxSizeSlot(int)));

	QGroupBox *SkyBoxGroup = new QGroupBox(tc->toUnicode("スカイボックス"));
	SkyBoxGroup->setLayout(SkyBoxLayout);
	layout->addWidget(SkyBoxGroup);


	QVBoxLayout *FloorLayout =  new QVBoxLayout();
	FloorButton = new QPushButton(tc->toUnicode("作成"));
	connect(FloorButton, SIGNAL(clicked()), this, SLOT(FloorSetSlot()));
	FloorLayout->addWidget(FloorButton);

	DelFloorButton = new QPushButton(tc->toUnicode("削除"));
	connect(DelFloorButton, SIGNAL(clicked()), this, SLOT(DelFloorSetSlot()));
	FloorLayout->addWidget(DelFloorButton);

	FloorEdit = new QComboBox();
	FloorEdit->setLineEdit(new QLineEdit());
	FloorEdit->addItem("Examples/GrassFloor");
	FloorEdit->addItem("Examples/Rockwall");
	FloorEdit->addItem("Examples/Aureola");
	FloorEdit->addItem("RustyBarrel");
	FloorEdit->addItem("WoodPallet");
	FloorEdit->addItem("Examples/LightRibbonTrail");
	FloorEdit->addItem("Examples/TudorHouse");
	FloorEdit->addItem("Examples/BumpyMetal");
	FloorEdit->addItem("OceanCg");
	FloorLayout->addWidget(FloorEdit);

	FloorSizespinBox = SetSpinBox(tc->toUnicode("サイズ"), 10000, 1, FloorLayout);
	FloorSizespinBox->setValue(1000);
	connect(FloorSizespinBox, SIGNAL(valueChanged(int)), this, SLOT(FloorSizeSlot(int)));

	FloorDircombpBox = new QComboBox();
	FloorDircombpBox->addItem("X");
	FloorDircombpBox->addItem("Y");
	FloorDircombpBox->addItem("Z");
	
	connect(FloorDircombpBox, SIGNAL(currentIndexChanged(int)), this, SLOT(FloorDirSlot(int)));

	FloorLayout->addWidget(FloorDircombpBox);

	QGroupBox *FloorGroup = new QGroupBox(tc->toUnicode("平面"));
	FloorGroup->setLayout(FloorLayout);
	layout->addWidget(FloorGroup);

	TimespinBox = SetSpinBox(tc->toUnicode("待ち時間"), 10000, 0, layout);
	connect(TimespinBox, SIGNAL(valueChanged(int)), this, SLOT(TimeSlot(int)));



	layout->addStretch();

	setLayout(layout);
	
}

//----------------------------------------------------------------------------------------

OtherSetWidget::~OtherSetWidget(void)
{

}



void OtherSetWidget::SkyBoxSetSlot()
{
	if(EC)
	{
		std::string fn = (const char*)SkyBoxEdit->currentText().toLocal8Bit();
		int s = SkyBoxspinBox->value();

		EC->SetQtSkyBox(fn.c_str(), s);
	}
}
void OtherSetWidget::SkyBoxSizeSlot(int value)
{
	
}
void OtherSetWidget::DelSkyBoxSetSlot()
{
	/*if(EC)
	{
		EC->RemoveSkyBox();
	}*/
}
void OtherSetWidget::FloorSetSlot()
{
	
	std::string fn = (const char*)FloorEdit->currentText().toLocal8Bit();
	int s = FloorSizespinBox->value();
	std::string d = (const char*)FloorDircombpBox->currentText().toLocal8Bit();
	
	if(EC)
	{
		std::string name1 = "Floor";
		std::string name2 = "floor";

		

		if(d == "X")
		{
			
			EC->SetQtFloor(name1.c_str(), name2.c_str(), fn.c_str(), s, 0);
		}
		else if(d == "Y")
		{
			EC->SetQtFloor(name1.c_str(), name2.c_str(), fn.c_str(), s, 1);
		}
		else if(d == "Z")
		{
			EC->SetQtFloor(name1.c_str(), name2.c_str(), fn.c_str(), s, 2);
		}
	}

	
}

void OtherSetWidget::FloorSizeSlot(int value)
{
	
	
}
void OtherSetWidget::FloorDirSlot(int value)
{
	if(value == 0)
	{

	}
	else if(value == 1)
	{

	}
	else if(value == 2)
	{

	}
	
}

void OtherSetWidget::DelFloorSetSlot()
{
	if(EC)
	{
		EC->DestroyQtFloor();
	}
	
}

void OtherSetWidget::UpdateList()
{
	if(EC)
	{
		if(EC->qtFloor)
		{
			FloorEdit->lineEdit()->setText(EC->qtFloor->name.c_str());
			FloorSizespinBox->setValue(EC->qtFloor->size);
			
			FloorDircombpBox->setCurrentIndex(EC->qtFloor->dir);
			
		}
		SkyBoxEdit->lineEdit()->setText(EC->QtskyBoxName.c_str());
		SkyBoxspinBox->setValue(EC->QtskyBoxSize);
	}
}

void OtherSetWidget::TimeSlot(int value)
{
	if(EC)
	{
		int t = TimespinBox->value();
		EC->SetSleepTime(t);
	}
}