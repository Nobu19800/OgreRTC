#include "GUITextSet.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#include "MyQtMacro.h"


#include "MyGUI.h"
#include "MyImageSet.h"


GUITextSetWidget::GUITextSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
{
	

	QTextCodec* tc = QTextCodec::codecForLocale();
	
	QVBoxLayout *layout = new QVBoxLayout;

	
	NameEdit = new QComboBox();
	NameEdit->setLineEdit(new QLineEdit());
	connect(NameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NameSlot(int)));
	layout->addWidget(NameEdit);


	SetButton = new QPushButton(tc->toUnicode("作成"));
	connect(SetButton, SIGNAL(clicked()), this, SLOT(SetSlot()));
	layout->addWidget(SetButton);

	QVBoxLayout *TextLayout = new QVBoxLayout();
	QLabel *Textlabel = new QLabel(tc->toUnicode("テキスト"));
	TextLayout->addWidget(Textlabel);
	TextEdit = new QTextEdit();
	TextLayout->addWidget(TextEdit);
	layout->addLayout(TextLayout);

	

	FontSizespinBox = SetSpinBox(tc->toUnicode("フォントサイズ"), 1000, 1, layout);
	FontSizespinBox->setValue(30);
	connect(FontSizespinBox, SIGNAL(valueChanged(int)), this, SLOT(FontSizeSlot(int)));
	

	TextTopAlignedButton = new QPushButton(tc->toUnicode("上"));
	connect(TextTopAlignedButton, SIGNAL(clicked()), this, SLOT(TextTopAlignedSlot()));
	layout->addWidget(TextTopAlignedButton);

	BottomAlignedButton = new QPushButton(tc->toUnicode("下"));
	connect(BottomAlignedButton, SIGNAL(clicked()), this, SLOT(BottomAlignedSlot()));
	layout->addWidget(BottomAlignedButton);

	VertCentredButton = new QPushButton(tc->toUnicode("中央"));
	connect(VertCentredButton, SIGNAL(clicked()), this, SLOT(VertCentredSlot()));
	layout->addWidget(VertCentredButton);

	WordWrapLeftAlignedButton = new QPushButton(tc->toUnicode("左"));
	connect(WordWrapLeftAlignedButton, SIGNAL(clicked()), this, SLOT(WordWrapLeftAlignedSlot()));
	layout->addWidget(WordWrapLeftAlignedButton);

	WordWrapRightAlignedButton = new QPushButton(tc->toUnicode("右"));
	connect(WordWrapRightAlignedButton, SIGNAL(clicked()), this, SLOT(WordWrapRightAlignedSlot()));
	layout->addWidget(WordWrapRightAlignedButton);

	WordWrapCentredButton = new QPushButton(tc->toUnicode("中央"));
	connect(WordWrapCentredButton, SIGNAL(clicked()), this, SLOT(WordWrapCentredSlot()));
	layout->addWidget(WordWrapCentredButton);

	LeftAlignedButton = new QPushButton(tc->toUnicode("左下"));
	connect(LeftAlignedButton, SIGNAL(clicked()), this, SLOT(LeftAlignedSlot()));
	layout->addWidget(LeftAlignedButton);

	RightAlignedButton = new QPushButton(tc->toUnicode("右下"));
	connect(RightAlignedButton, SIGNAL(clicked()), this, SLOT(RightAlignedSlot()));
	layout->addWidget(RightAlignedButton);

	HorzCentredButton = new QPushButton(tc->toUnicode("中央"));
	connect(HorzCentredButton, SIGNAL(clicked()), this, SLOT(HorzCentredSlot()));
	layout->addWidget(HorzCentredButton);

	ClearPropertiesButton = new QPushButton(tc->toUnicode("初期化"));
	connect(ClearPropertiesButton, SIGNAL(clicked()), this, SLOT(ClearPropertiesSlot()));
	layout->addWidget(ClearPropertiesButton);


	

	layout->addStretch();



	setLayout(layout);
	
}

//----------------------------------------------------------------------------------------

GUITextSetWidget::~GUITextSetWidget(void)
{

}



void GUITextSetWidget::SetSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	int fs = FontSizespinBox->value();
	std::string te = (const char*)TextEdit->toPlainText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText" || mg->type == "TaharezLook/Editbox")
				{
					mg->SetText(te.c_str());
					mg->SetFontSize(fs);
				}
				
			}
		}

	}

}

void GUITextSetWidget::FontSizeSlot(int)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	int fs = FontSizespinBox->value();

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
				if(mg->type == "TaharezLook/StaticText" || mg->type == "TaharezLook/Editbox")
				{
					mg->SetFontSize(fs);
				}
				
			}
		}

	}
}
void GUITextSetWidget::TextTopAlignedSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextTopAligned();
				}
				
			}
		}

	}
}
void GUITextSetWidget::BottomAlignedSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextBottomAligned();
				}
				
			}
		}

	}
}
void GUITextSetWidget::VertCentredSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextVertCentred();
				}
				
			}
		}

	}
}
void GUITextSetWidget::WordWrapLeftAlignedSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextWordWrapLeftAligned();
				}
				
			}
		}

	}
}
void GUITextSetWidget::WordWrapRightAlignedSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextWordWrapRightAligned();
				}
				
			}
		}

	}
}
void GUITextSetWidget::WordWrapCentredSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextWordWrapCentred();
				}
				
			}
		}

	}
}
void GUITextSetWidget::LeftAlignedSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextLeftAligned();
				}
				
			}
		}

	}
}
void GUITextSetWidget::RightAlignedSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextRightAligned();
				}
				
			}
		}

	}
}
void GUITextSetWidget::HorzCentredSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				if(mg->type == "TaharezLook/StaticText")
				{
					mg->SetTextHorzCentred();
				}
				
			}
		}

	}
}
void GUITextSetWidget::ClearPropertiesSlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				mg->ClearProperties();
				
			}
		}

	}
}


void GUITextSetWidget::NameSlot(int value)
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
			MyGUI *mg = EC->getGUIByName(n.c_str());
			if(mg)
			{
				if(mg->type == "TaharezLook/StaticText" || mg->type == "TaharezLook/Editbox")
				{
					FontSizespinBox->setValue(mg->font_size);
				}
				
			}
		}

	}
}

void GUITextSetWidget::UpdateList()
{
	UpdateGUI();
}

void GUITextSetWidget::UpdateGUI()
{
	NameEdit->clear();
	if(EC)
	{
		for(int i=0;i < EC->QtGUIs.size();i++)
		{
			NameEdit->addItem(EC->QtGUIs[i]->name.c_str());
		}
	}
}

