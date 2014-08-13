#include "ImageSet.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include "MyQtMacro.h"


#include "ImageSet.h"


ImageSetWidget::ImageSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))
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

//----------------------------------------------------------------------------------------

ImageSetWidget::~ImageSetWidget(void)
{

}


void ImageSetWidget::SetSlot()
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	std::string fn = FileNameEdit->currentText().toLocal8Bit();
	

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
			MyImageSet *mi = EC->CreateQtGuiImageSet(n.c_str(), fn.c_str());
			UpdateList();
			NameEdit->setCurrentIndex(NameEdit->count()-1);
			
			
		}
	}
}

void ImageSetWidget::DestroySlot()
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		MyImageSet *mi = EC->getImageSetByName(n.c_str());
		if(mi)
		{
			EC->DestroyQtImage(mi);
			UpdateList();
		}
		
	}
}

void ImageSetWidget::NameSlot(int value)
{
	std::string n = NameEdit->currentText().toLocal8Bit();
}

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

void ImageSetWidget::UpdateGUI()
{
	GUIBox->clear();
	if(EC)
	{
		for(int i=0;i < EC->QtGUIs.size();i++)
		{
			GUIBox->addItem(EC->QtGUIs[i]->name.c_str());
		}

		std::string n = GUIBox->currentText().toLocal8Bit();

		if(n == "")
		{
			return;
		}
		else
		{
			MyGUI *mg = EC->getGUIByName(n.c_str());
			if(mg)
			{
				if(mg->type == "TaharezLook/StaticImage")
				{
					MyImageSet *mi = EC->getImageSetByName(mg->image_name.c_str());
					if(mi)
					{
						NameEdit->setCurrentIndex(NameEdit->findText(mg->image_name.c_str()));
					}
				}
				
				
			}
		}
	}

	
	

			
}

void ImageSetWidget::SetGUISlot(){
	std::string n = NameEdit->currentText().toLocal8Bit();
	std::string gn = GUIBox->currentText().toLocal8Bit();
	std::string in = INameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyGUI *mg = EC->getGUIByName(gn.c_str());
			if(mg)
			{
				if(mg->type == "TaharezLook/StaticImage")
				{
					MyImageSet *mi = EC->getImageSetByName(n.c_str());
					if(mi)
					{
						mg->SetImage(mi, in.c_str());
					}
				}
				
			}
		}

	}
}