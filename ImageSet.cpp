/*!
 * @file  ImageSet.cpp
 * @brief イメージセットの設定用ウインドウ
 *
 */

#include "ImageSet.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#include "QtMacro.h"




/**
*@brief GUIの画像作成、設定用ウィジェットのコンストラクタ
*@param parent 親ウィジェット
*/
ImageSetWidget::ImageSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
{
	

	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;

	NameEdit = new QComboBox();
	NameEdit->setLineEdit(new QLineEdit());
	connect(NameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NameSlot(int)));
	layout->addWidget(NameEdit);


	

	QVBoxLayout *FileNameLayout = new QVBoxLayout();
	QLabel *FileNamelabel = new QLabel(tc->toUnicode("ファイル名"));
	FileNameLayout->addWidget(FileNamelabel);
	FileNameEdit = new QComboBox();
	FileNameEdit->setLineEdit(new QLineEdit());
	FileNameEdit->addItem("OgreTrayImages.png");
	FileNameEdit->addItem("OgreTray.imageset");
	FileNameEdit->addItem("logo.png");
	FileNameEdit->addItem("FairChar.tga");
	FileNameEdit->addItem("FairChar.imageset");
	FileNameEdit->addItem("vanilla.tga");
	FileNameEdit->addItem("Vanilla.imageset");
	FileNameEdit->addItem("WindowsLook.tga");
	FileNameEdit->addItem("WindowsLook.imageset");
	FileNameEdit->addItem("cursor.png");
	FileNameEdit->addItem("DriveIcons.png");
	FileNameEdit->addItem("DriveIcons.imageset");
	FileNameLayout->addWidget(FileNameEdit);
	layout->addLayout(FileNameLayout);


	
	SetButton = new QPushButton(tc->toUnicode("作成"));
	connect(SetButton, SIGNAL(clicked()), this, SLOT(SetSlot()));
	layout->addWidget(SetButton);


	DestroyButton = new QPushButton(tc->toUnicode("削除"));
	connect(DestroyButton, SIGNAL(clicked()), this, SLOT(DestroySlot()));
	layout->addWidget(DestroyButton);

	QVBoxLayout *guiLayout = new QVBoxLayout();
	GUIBox = new QComboBox();
	guiLayout->addWidget(GUIBox);
	INameEdit = new QComboBox();
	INameEdit->setLineEdit(new QLineEdit());
	INameEdit->addItem("full_image");
	guiLayout->addWidget(INameEdit);
	SetGUIButton = new QPushButton(tc->toUnicode("画像貼り付け"));
	connect(SetGUIButton, SIGNAL(clicked()), this, SLOT(SetGUISlot()));
	guiLayout->addWidget(SetGUIButton);
	QGroupBox *guiGroup = new QGroupBox(tc->toUnicode("CEGUI"));
	guiGroup->setLayout(guiLayout);
	layout->addWidget(guiGroup);


	layout->addStretch();

	setLayout(layout);
}


/**
*@brief GUIの画像作成、設定用ウィジェットのデストラクタ
*/
ImageSetWidget::~ImageSetWidget(void)
{

}

/**
*@brief 作成ボタンを押したときのスロット
*/
void ImageSetWidget::SetSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	std::string fn = (const char*)FileNameEdit->currentText().toLocal8Bit();
	

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else if(EC->getImageSetByName(n.c_str()))
		{
			return;
		}
		else
		{
			ImageSetObj *mi = EC->CreateQtGuiImageSet(n.c_str(), fn.c_str());
			UpdateList();
			NameEdit->setCurrentIndex(NameEdit->count()-1);
			
			
		}
	}
}

/**
*@brief 削除ボタンを押したときのスロット
*/
void ImageSetWidget::DestroySlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		ImageSetObj *mi = EC->getImageSetByName(n.c_str());
		if(mi)
		{
			EC->DestroyQtImage(mi);
			UpdateList();
		}
		
	}
}

/**
*@brief GUIの名前コンボボックスの番号が変わったときのスロット
*@param value 番号
*/
void ImageSetWidget::NameSlot(int value)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
}


/**
*@brief 画像の設定をウィジェットに反映させるときのスロット
*/
void ImageSetWidget::UpdateList()
{
	UpdateGUI();
	if(EC)
	{
		NameEdit->clear();
		for(int i=0;i < EC->QtImageSets.size();i++)
		{
			NameEdit->addItem(EC->QtImageSets[i]->name.c_str());
		}
		
	}
}

/**
*@brief GUIが追加、削除された時のスロット
*/
void ImageSetWidget::UpdateGUI()
{
	GUIBox->clear();
	if(EC)
	{
		for(int i=0;i < EC->QtGUIs.size();i++)
		{
			GUIBox->addItem(EC->QtGUIs[i]->name.c_str());
		}

		std::string n = (const char*)GUIBox->currentText().toLocal8Bit();

		if(n == "")
		{
			return;
		}
		else
		{
			GUIObj *mg = EC->getGUIByName(n.c_str());
			if(mg)
			{
				if(mg->type == "TaharezLook/StaticImage")
				{
					ImageSetObj *mi = EC->getImageSetByName(mg->image_name.c_str());
					if(mi)
					{
						NameEdit->setCurrentIndex(NameEdit->findText(mg->image_name.c_str()));
					}
				}
				
				
			}
		}
	}

	
	

			
}


/**
*@brief GUIの画像設定ボタンを押したときのスロット
*/
void ImageSetWidget::SetGUISlot(){
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	std::string gn = (const char*)GUIBox->currentText().toLocal8Bit();
	std::string in = (const char*)INameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			GUIObj *mg = EC->getGUIByName(gn.c_str());
			if(mg)
			{
				if(mg->type == "TaharezLook/StaticImage")
				{
					ImageSetObj *mi = EC->getImageSetByName(n.c_str());
					if(mi)
					{
						mg->SetImage(mi, in.c_str());
					}
				}
				
			}
		}

	}
}