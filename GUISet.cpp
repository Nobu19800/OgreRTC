#include "GUISet.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include "MyQtMacro.h"


#include "MyGUI.h"


GUISetWidget::GUISetWidget(QWidget *parent) : 
QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))
{
	up_flag = true;

	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;
	
	NameEdit = new QComboBox();
	NameEdit->setLineEdit(new QLineEdit());
	connect(NameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NameSlot(int)));
	layout->addWidget(NameEdit);

	TypeBox = new QComboBox();
	TypeBox->addItem("TaharezLook/StaticImage");
	TypeBox->addItem("TaharezLook/StaticText");
	TypeBox->addItem("TaharezLook/Button");
	TypeBox->addItem("TaharezLook/Editbox");
	TypeBox->addItem("TaharezLook/Combobox");
	TypeBox->addItem("TaharezLook/Slider");
	TypeBox->addItem("TaharezLook/Titlebar");
	TypeBox->addItem("TaharezLook/FrameWindow");
	TypeBox->addItem("TaharezLook/VerticalScrollbar");
	TypeBox->addItem("TaharezLook/HorizontalScrollbar");
	TypeBox->addItem("TaharezLook/CaptionedStaticText");
	TypeBox->addItem("TaharezLook/ProgressBar");
	TypeBox->addItem("TaharezLook/MultiLineEditbox");
	TypeBox->addItem("TaharezLook/Listbox");
	TypeBox->addItem("TaharezLook/ComboDropList");
	TypeBox->addItem("TaharezLook/Group");
	TypeBox->addItem("TaharezLook/Checkbox");
	TypeBox->addItem("TaharezLook/RadioButton");
	TypeBox->addItem("TaharezLook/Tooltip");
	TypeBox->addItem("TaharezLook/ItemListbox");
	TypeBox->addItem("TaharezLook/ListboxItem");
	TypeBox->addItem("TaharezLook/ScrollablePane");
	TypeBox->addItem("TaharezLook/ListHeaderSegment");
	TypeBox->addItem("TaharezLook/ListHeader");
	TypeBox->addItem("TaharezLook/MultiColumnList");
	TypeBox->addItem("TaharezLook/MenuItem");
	TypeBox->addItem("TaharezLook/Menubar");
	TypeBox->addItem("TaharezLook/PopupMenu");
	TypeBox->addItem("TaharezLook/TabButtonPane");
	TypeBox->addItem("TaharezLook/TabContentPane");
	TypeBox->addItem("TaharezLook/TabControl");

	layout->addWidget(TypeBox);

	SetButton = new QPushButton(tc->toUnicode("作成"));
	connect(SetButton, SIGNAL(clicked()), this, SLOT(SetSlot()));
	layout->addWidget(SetButton);

	QVBoxLayout *windowLayout =  new QVBoxLayout();

	WindowBox = new QComboBox();
	windowLayout->addWidget(WindowBox);

	WindowButton = new QPushButton(tc->toUnicode("設定"));
	connect(WindowButton, SIGNAL(clicked()), this, SLOT(WindowSlot()));
	windowLayout->addWidget(WindowButton);
	QGroupBox *windowGroup = new QGroupBox(tc->toUnicode("親ウインドウ設定"));
	windowGroup->setLayout(windowLayout);
	layout->addWidget(windowGroup);



	QVBoxLayout *posLayout =  new QVBoxLayout();
	PosXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 1.0, 0.0, posLayout);
	PosXspinBox->setSingleStep(0.1);
	connect(PosXspinBox, SIGNAL(valueChanged(double)), this, SLOT(PosXSlot(double)));
	PosYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 1.0, 0.0, posLayout);
	PosYspinBox->setSingleStep(0.1);
	connect(PosYspinBox, SIGNAL(valueChanged(double)), this, SLOT(PosYSlot(double)));
	QGroupBox *posGroup = new QGroupBox(tc->toUnicode("位置"));
	posGroup->setLayout(posLayout);
	layout->addWidget(posGroup);

	QVBoxLayout *rotLayout =  new QVBoxLayout();
	RollspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 360.0, 0.0, rotLayout);
	connect(RollspinBox, SIGNAL(valueChanged(double)), this, SLOT(RollSlot(double)));
	PitchspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 360.0, 0.0, rotLayout);
	connect(PitchspinBox, SIGNAL(valueChanged(double)), this, SLOT(PitchSlot(double)));
	YawspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 360.0, 0.0, rotLayout);
	connect(YawspinBox, SIGNAL(valueChanged(double)), this, SLOT(YawSlot(double)));
	QGroupBox *rotGroup = new QGroupBox(tc->toUnicode("姿勢"));
	rotGroup->setLayout(rotLayout);
	layout->addWidget(rotGroup);

	QVBoxLayout *scaleLayout =  new QVBoxLayout();
	ScaleXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 1.0, 0.0, scaleLayout);
	ScaleXspinBox->setValue(0.1);
	ScaleXspinBox->setSingleStep(0.1);
	connect(ScaleXspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleXSlot(double)));
	ScaleYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 1.0, 0.01, scaleLayout);
	ScaleYspinBox->setValue(0.1);
	ScaleYspinBox->setSingleStep(0.1);
	connect(ScaleYspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleYSlot(double)));
	QGroupBox *scaleGroup = new QGroupBox(tc->toUnicode("大きさ"));
	scaleGroup->setLayout(scaleLayout);
	layout->addWidget(scaleGroup);

	
	AlphaspinBox = SetDoubleSpinBox(tc->toUnicode("透明度"), 1.0, 0.0, layout);
	AlphaspinBox->setSingleStep(0.1);
	AlphaspinBox->setValue(1.0);
	connect(AlphaspinBox, SIGNAL(valueChanged(double)), this, SLOT(AlphaSlot(double)));
	

	VisibleButton = new QPushButton(tc->toUnicode("表示"));
	connect(VisibleButton, SIGNAL(clicked()), this, SLOT(VisibleSlot()));
	layout->addWidget(VisibleButton);

	unVisibleButton = new QPushButton(tc->toUnicode("非表示"));
	connect(unVisibleButton, SIGNAL(clicked()), this, SLOT(unVisibleSlot()));
	layout->addWidget(unVisibleButton);

	FrameButton = new QPushButton(tc->toUnicode("フレーム表示"));
	connect(FrameButton, SIGNAL(clicked()), this, SLOT(FrameSlot()));
	layout->addWidget(FrameButton);

	unFrameButton = new QPushButton(tc->toUnicode("フレーム非表示"));
	connect(unFrameButton, SIGNAL(clicked()), this, SLOT(unFrameSlot()));
	layout->addWidget(unFrameButton);

	BackGroundButton = new QPushButton(tc->toUnicode("背景表示"));
	connect(BackGroundButton, SIGNAL(clicked()), this, SLOT(BackGroundSlot()));
	layout->addWidget(BackGroundButton);

	unBackGroundButton = new QPushButton(tc->toUnicode("背景非表示"));
	connect(unBackGroundButton, SIGNAL(clicked()), this, SLOT(unBackGroundSlot()));
	layout->addWidget(unBackGroundButton);

	


	DestroyButton = new QPushButton(tc->toUnicode("削除"));
	connect(DestroyButton, SIGNAL(clicked()), this, SLOT(DestroySlot()));
	layout->addWidget(DestroyButton);

	layout->addStretch();


	setLayout(layout);
}

//----------------------------------------------------------------------------------------

GUISetWidget::~GUISetWidget(void)
{

}

void GUISetWidget::UpdatePos()
{
	if(up_flag)
	{
		std::string n = NameEdit->currentText().toLocal8Bit();
		float px = PosXspinBox->value();
		float py = PosYspinBox->value();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				MyGUI *mg = EC->getGUIByName(n.c_str());
				if(mg)
				{
					mg->SetPosition(px, py);
				}
			}

		}
	}
}

void GUISetWidget::UpdateRot()
{
	if(up_flag)
	{
		std::string n = NameEdit->currentText().toLocal8Bit();
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
				MyGUI *mg = EC->getGUIByName(n.c_str());
				if(mg)
				{
					mg->SetRotatin(roll, pitch, yaw);
				}
			}

		}
	}
}

void GUISetWidget::UpdateSize()
{
	if(up_flag)
	{
		std::string n = NameEdit->currentText().toLocal8Bit();
		float sx = ScaleXspinBox->value();
		float sy = ScaleYspinBox->value();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				MyGUI *mg = EC->getGUIByName(n.c_str());
				if(mg)
				{
					mg->SetSize(sx, sy);
				}
			}

		}
	}
}

void GUISetWidget::UpdateVisi(bool visi)
{
	std::string n = NameEdit->currentText().toLocal8Bit();


	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyGUI *mg = EC->getGUIByName(n.c_str());
			if(mg)
			{
				mg->SetVisible(visi);
			}
		}

	}
}



void GUISetWidget::UpdateFrame(bool visi)
{
	std::string n = NameEdit->currentText().toLocal8Bit();


	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyGUI *mg = EC->getGUIByName(n.c_str());
			if(mg)
			{
				mg->SetFrameEnable(visi);
			}
		}

	}
}

void GUISetWidget::UpdateBackGround(bool visi)
{
	std::string n = NameEdit->currentText().toLocal8Bit();


	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyGUI *mg = EC->getGUIByName(n.c_str());
			if(mg)
			{
				mg->SetBackGroundEnable(visi);
			}
		}

	}
}

void GUISetWidget::SetSlot()
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	std::string t = TypeBox->currentText().toLocal8Bit();
	float px = PosXspinBox->value();
	float py = PosYspinBox->value();

	float sx = ScaleXspinBox->value();
	float sy = ScaleYspinBox->value();

	float a = AlphaspinBox->value();
	
	MyGUI *mg;
	if(n == "")
	{
		return;
	}
	else if(EC->getGUIByName(n.c_str()))
	{

	}
	else
	{
	
		if(t == "TaharezLook/StaticImage")
		{
			mg = EC->CreateQtStaticImage(n.c_str());
		}
		else if(t == "TaharezLook/StaticText")
		{
			mg = EC->CreateQtStaticText(n.c_str());
		}
		else if(t == "TaharezLook/Button")
		{
			mg = EC->CreateQtButton(n.c_str());
		}
		else if(t == "TaharezLook/Editbox")
		{
			mg = EC->CreateQtEditBox(n.c_str());
		}
		else if(t == "TaharezLook/Combobox")
		{
			mg = EC->CreateQtComboBox(n.c_str());
		}
		else if(t == "TaharezLook/Slider")
		{
			mg = EC->CreateQtSlider(n.c_str());
		}
		else if(t == "TaharezLook/Titlebar")
		{
			mg = EC->CreateQtTitlebar(n.c_str());
		}
		else if(t == "TaharezLook/FrameWindow")
		{
			mg = EC->CreateQtFrameWindow(n.c_str());
		}

		else if(t == "TaharezLook/VerticalScrollbar")
		{
			mg = EC->CreateQtVerticalScrollbar(n.c_str());
		}
		else if(t == "TaharezLook/HorizontalScrollbar")
		{
			mg = EC->CreateQtHorizontalScrollbar(n.c_str());
		}
		else if(t == "TaharezLook/ProgressBar")
		{
			mg = EC->CreateQtProgressBar(n.c_str());
		}
		else if(t == "TaharezLook/MultiLineEditbox")
		{
			mg = EC->CreateQtMultiLineEditbox(n.c_str());
		}
		else if(t == "TaharezLook/Listbox")
		{
			mg = EC->CreateQtListbox(n.c_str());
		}
		else if(t == "TaharezLook/ComboDropList")
		{
			mg = EC->CreateQtComboDropList(n.c_str());
		}
		
		else if(t == "TaharezLook/Checkbox")
		{
			mg = EC->CreateQtCheckbox(n.c_str());
		}
		else if(t == "TaharezLook/RadioButton")
		{
			mg = EC->CreateQtRadioButton(n.c_str());
		}
		else if(t == "TaharezLook/Tooltip")
		{
			mg = EC->CreateQtTooltip(n.c_str());
		}
		else if(t == "TaharezLook/ItemListbox")
		{
			mg = EC->CreateQtItemListbox(n.c_str());
		}
		else if(t == "TaharezLook/ListboxItem")
		{
			mg = EC->CreateQtListboxItem(n.c_str());
		}
		else if(t == "TaharezLook/Spinner")
		{
			mg = EC->CreateQtSpinner(n.c_str());
		}
		else if(t == "TaharezLook/ScrollablePane")
		{
			mg = EC->CreateQtScrollablePane(n.c_str());
		}
		else if(t == "TaharezLook/ListHeaderSegment")
		{
			mg = EC->CreateQtListHeaderSegment(n.c_str());
		}
		else if(t == "TaharezLook/ListHeader")
		{
			mg = EC->CreateQtListHeader(n.c_str());
		}
		else if(t == "TaharezLook/MultiColumnList")
		{
			mg = EC->CreateQtMultiColumnList(n.c_str());
		}
		else if(t == "TaharezLook/MenuItem")
		{
			mg = EC->CreateQtMenuItem(n.c_str());
		}
		else if(t == "TaharezLook/Menubar")
		{
			mg = EC->CreateQtMenubar(n.c_str());
		}
		else if(t == "TaharezLook/PopupMenu")
		{
			mg = EC->CreateQtPopupMenu(n.c_str());
		}
		else if(t == "TaharezLook/TabButtonPane")
		{
			mg = EC->CreateQtTabButtonPane(n.c_str());
		}
		else if(t == "TaharezLook/TabContentPane")
		{
			mg = EC->CreateQtTabContentPane(n.c_str());
		}
		else if(t == "TaharezLook/TabControl")
		{
			mg = EC->CreateQtTabControl(n.c_str());
		}
		else
		{
			return;
		}

		mg->SetPosition(px, py);
		mg->SetSize(sx, sy);
		mg->SetAlpha(a);

		UpdateList();
		NameEdit->setCurrentIndex(NameEdit->count()-1);
		
	}

	
	
	
}
void GUISetWidget::PosXSlot(double value)
{
	UpdatePos();
	
}
void GUISetWidget::PosYSlot(double value)
{
	UpdatePos();
	
}
void GUISetWidget::RollSlot(double value)
{
	UpdateRot();
}
void GUISetWidget::PitchSlot(double value)
{
	UpdateRot();
}
void GUISetWidget::YawSlot(double value)
{
	UpdateRot();
}
void GUISetWidget::ScaleXSlot(double value)
{
	UpdateSize();
	
}
void GUISetWidget::ScaleYSlot(double value)
{
	UpdateSize();
	
}
void GUISetWidget::AlphaSlot(double value)
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	float a = AlphaspinBox->value();


	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyGUI *mg = EC->getGUIByName(n.c_str());
			if(mg)
			{
				mg->SetAlpha(a);
			}
		}

	}
}
void GUISetWidget::VisibleSlot()
{
	UpdateVisi(true);
}
void GUISetWidget::unVisibleSlot()
{
	UpdateVisi(false);
}
void GUISetWidget::FrameSlot()
{
	UpdateFrame(true);
}
void GUISetWidget::unFrameSlot()
{
	UpdateFrame(false);
}
void GUISetWidget::BackGroundSlot()
{
	UpdateBackGround(true);
}
void GUISetWidget::unBackGroundSlot()
{
	UpdateBackGround(true);
}

void GUISetWidget::DestroySlot()
{
	std::string n = NameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		MyGUI *mg = EC->getGUIByName(n.c_str());
		if(mg)
		{
			EC->DestroyQtGui(mg);
			UpdateList();
		}
		
	}
}

void GUISetWidget::NameSlot(int value)
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		MyGUI *mg = EC->getGUIByName(n.c_str());
		if(mg)
		{
			up_flag = false;
			PosXspinBox->setValue(mg->pos_x);
			PosYspinBox->setValue(mg->pos_y);

			ScaleXspinBox->setValue(mg->size_x);
			ScaleYspinBox->setValue(mg->size_y);

			AlphaspinBox->setValue(mg->alpha);

			
			TypeBox->setCurrentIndex(TypeBox->findText(mg->type.c_str()));

			up_flag = true;
		}
	}
}

void GUISetWidget::UpdateList()
{
	if(EC)
	{
		NameEdit->clear();
		WindowBox->clear();
		for(int i=0;i < EC->QtGUIs.size();i++)
		{
			NameEdit->addItem(EC->QtGUIs[i]->name.c_str());
			WindowBox->addItem(EC->QtGUIs[i]->name.c_str());
		}
		emit UpdateGUI();
	}
}

void GUISetWidget::WindowSlot()
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	std::string wn = WindowBox->currentText().toLocal8Bit();
	if(EC)
	{
		MyGUI *mg = EC->getGUIByName(n.c_str());
		if(mg)
		{
			MyGUI *wmg = EC->getGUIByName(wn.c_str());
			if(wmg)
			{
				if(mg != wmg)
				{
					if(wmg->type == "TaharezLook/FrameWindow")
					{
						mg->SetWindow(wmg);
					}
				}
			}
		}
	}
}