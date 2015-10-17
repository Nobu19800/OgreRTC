/*!
 * @file  GUITextSet.cpp
 * @brief GUIのテキスト設定用ウインドウ
 *
 */

#include "GUITextSet.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#include "QtMacro.h"


#include "GUIObj.h"
#include "ImageSetObj.h"

/**
*@brief GUIのテキスト設定用ウィジェットのコンストラクタ
*@param parent 親ウィジェット
*/
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


/**
*@brief GUIのテキスト設定用ウィジェットのデストラクタ
*/
GUITextSetWidget::~GUITextSetWidget(void)
{

}


/**
*@brief テキスト設定ボタンを押したときのスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief フォントサイズ設定スピンボックスの値を変更したときのスロット
* @param fs フォントサイズ
*/
void GUITextSetWidget::FontSizeSlot(int fs)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	//int fs = FontSizespinBox->value();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を上端に設定するスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を下端に設定するスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を縦中央に設定するスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を左端に設定するスロット
*単語の途中で改行する
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を右端に設定するスロット
*単語の途中で改行する
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を中央に設定するスロット
*単語の途中で改行する
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を左端に設定するスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を右端に設定するスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief テキストの位置を横中央に設定するスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief 設定初期化ボタンを押したときのスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
			if(mg)
			{
				mg->ClearProperties();
				
			}
		}

	}
}


/**
*@brief GUIの名前コンボボックスの番号が変わったときのスロット
*/
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
			GUIObj *mg = EC->getGUIByName(n.c_str());
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

/**
*@brief GUIの設定をウィジェットに反映させるときのスロット
*/
void GUITextSetWidget::UpdateList()
{
	UpdateGUI();
}

/**
*@brief GUIが追加、削除された時のスロット
*/
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

