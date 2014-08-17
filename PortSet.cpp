#include "PortSet.h"
#include "MyQtMacro.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include "OgreRTC.h"


extern OgreRTC *m_rtc;


PortSetWidget::PortSetWidget(QWidget *parent) : 
QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))
{


	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;

	NameEdit = new QComboBox();
	NameEdit->setLineEdit(new QLineEdit());
	connect(NameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NameSlot(int)));
	layout->addWidget(NameEdit);

	TypeBox = new QComboBox();
	TypeBox->addItem("RTC/TimedDouble");
	TypeBox->addItem("RTC/TimedLong");
	TypeBox->addItem("RTC/TimedFloat");
	TypeBox->addItem("RTC/TimedShort");
	TypeBox->addItem("RTC/TimedULong");
	TypeBox->addItem("RTC/TimedUShort");
	TypeBox->addItem("RTC/TimedChar");
	TypeBox->addItem("RTC/TimedBoolean");
	TypeBox->addItem("RTC/TimedOctet");
	TypeBox->addItem("RTC/TimedString");
	TypeBox->addItem("RTC/TimedDoubleSeq");
	TypeBox->addItem("RTC/TimedLongSeq");
	TypeBox->addItem("RTC/TimedFloatSeq");
	TypeBox->addItem("RTC/TimedShortSeq");
	TypeBox->addItem("RTC/TimedULongSeq");
	TypeBox->addItem("RTC/TimedUShortSeq");
	TypeBox->addItem("RTC/TimedCharSeq");
	TypeBox->addItem("RTC/TimedBooleanSeq");
	TypeBox->addItem("RTC/TimedOctetSeq");
	TypeBox->addItem("RTC/TimedStringSeq");
	layout->addWidget(TypeBox);

	SetButton = new QPushButton(tc->toUnicode("ì¬"));
	connect(SetButton, SIGNAL(clicked()), this, SLOT(SetSlot()));
	layout->addWidget(SetButton);

	DestroyButton = new QPushButton(tc->toUnicode("íœ"));
	connect(DestroyButton, SIGNAL(clicked()), this, SLOT(DestroySlot()));
	layout->addWidget(DestroyButton);




	

	



	layout->addStretch();
	
	

	setLayout(layout);
	
}

//----------------------------------------------------------------------------------------

PortSetWidget::~PortSetWidget(void)
{

}


void PortSetWidget::SetSlot()
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	std::string dn = TypeBox->currentText().toLocal8Bit();
	
	if(m_rtc)
	{
		if(n == "")
		{
			return;
		}
		else if(m_rtc->GetPortByName(n.c_str()))
		{
			return;
		}
		else
		{
			m_rtc->QtAddInPort(n, dn);
			NameEdit->clear();
			for(int i=0;i < m_rtc->QtInPorts.size();i++)
			{
				NameEdit->addItem(m_rtc->QtInPorts[i]->name.c_str());
			}
			NameEdit->setCurrentIndex(NameEdit->count()-1);
		}
	}

	
	
}

void PortSetWidget::NameSlot(int value)
{
	std::string n = NameEdit->currentText().toLocal8Bit();
	if(m_rtc)
	{
		MyPortBase *tmp = m_rtc->GetPortByName(n.c_str());
		if(tmp)
		{
			TypeBox->setCurrentIndex(TypeBox->findText(tmp->data_type.c_str()));
		}
		
	}
}

void PortSetWidget::DestroySlot()
{
	std::string n = NameEdit->currentText().toLocal8Bit();

	if(m_rtc)
	{
		MyPortBase *tmp = m_rtc->GetPortByName(n.c_str());
		if(tmp)
		{
			m_rtc->QtRemoveInPort(tmp);
			NameEdit->clear();
			for(int i=0;i < m_rtc->QtInPorts.size();i++)
			{
				NameEdit->addItem(m_rtc->QtInPorts[i]->name.c_str());
			}
		}
		
	}
}

void PortSetWidget::UpdateList()
{
	if(m_rtc)
	{
		NameEdit->clear();
		for(int i=0;i < m_rtc->QtInPorts.size();i++)
		{
			NameEdit->addItem(m_rtc->QtInPorts[i]->name.c_str());
		}
	}
}