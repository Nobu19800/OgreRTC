#include "NodeSet.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include "MyQtMacro.h"



NodeSetWidget::NodeSetWidget(QWidget *parent) : 
QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))
{
	

	QTextCodec* tc = QTextCodec::codecForLocale();
	
	QVBoxLayout *layout = new QVBoxLayout;
	QLabel *NumLabel = new QLabel(tc->toUnicode("オブジェクトの種類"));
	layout->addWidget(NumLabel);
	NumEdit = new QComboBox();
	NumEdit->addItem("Body");
	NumEdit->addItem("Particle");
	NumEdit->addItem("Light");
	NumEdit->addItem("Animation");
	NumEdit->addItem("Simulation Body");
	NumEdit->addItem("Simulation Joint");
	connect(NumEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NumSlot(int)));
	layout->addWidget(NumEdit);

	QLabel *NameLabel = new QLabel(tc->toUnicode("オブジェクトの名前"));
	layout->addWidget(NameLabel);
	NameEdit = new QComboBox();
	connect(NameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NameSlot(int)));
	layout->addWidget(NameEdit);

	QLabel *TypeLabel = new QLabel(tc->toUnicode("アタッチの種類"));
	layout->addWidget(TypeLabel);
	TypeEdit= new QComboBox();
	TypeEdit->addItem("Node");
	TypeEdit->addItem("Position");
	layout->addWidget(TypeEdit);


	QLabel *AttachNumLabel = new QLabel(tc->toUnicode("アタッチするオブジェクトの種類"));
	layout->addWidget(AttachNumLabel);
	AttachNumBox = new QComboBox();
	AttachNumBox->addItem("Body");
	AttachNumBox->addItem("Particle");
	AttachNumBox->addItem("Light");
	
	connect(AttachNumBox, SIGNAL(currentIndexChanged(int)), this, SLOT(AttachNumSlot(int)));

	layout->addWidget(AttachNumBox);


	QLabel *AttachListLabel = new QLabel(tc->toUnicode("アタッチするオブジェクトの名前"));
	layout->addWidget(AttachListLabel);
	AttachListBox = new QComboBox();
	

	layout->addWidget(AttachListBox);



	AttachButton = new QPushButton(tc->toUnicode("アタッチ"));
	connect(AttachButton, SIGNAL(clicked()), this, SLOT(AttachSlot()));
	layout->addWidget(AttachButton);


	/*DettachNumBox = new QComboBox();
	DettachNumBox->addItem("Body");
	DettachNumBox->addItem("Particle");
	DettachNumBox->addItem("Light");
	connect(DettachNumBox, SIGNAL(currentIndexChanged(int)), this, SLOT(DettachNumSlot(int)));

	layout->addWidget(DettachNumBox);*/


	QLabel *DettachListLabel = new QLabel(tc->toUnicode("接続しているオブジェクトの名前"));
	layout->addWidget(DettachListLabel);
	DettachListBox = new QComboBox();

	layout->addWidget(DettachListBox);


	DettachButton = new QPushButton(tc->toUnicode("デタッチ"));
	connect(DettachButton, SIGNAL(clicked()), this, SLOT(DettachSlot()));
	layout->addWidget(DettachButton);



	
	layout->addStretch();

	setLayout(layout);
	
}

//----------------------------------------------------------------------------------------

NodeSetWidget::~NodeSetWidget(void)
{

}


void NodeSetWidget::NameSlot(int value)
{
	
}

void NodeSetWidget::AttachSlot()
{
	int num = NumEdit->currentIndex();
	std::string n = NameEdit->currentText().toLocal8Bit();
	int anum = AttachNumBox->currentIndex();
	std::string an = AttachListBox->currentText().toLocal8Bit();
	int type = TypeEdit->currentIndex();
	
	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			if(num == 0 || num == 4 || num == 5)
			{
				MyLink *ml;
				if(num == 0)
				{
					ml = EC->getBodyByName(n.c_str());
				}
				else if(num == 4)
				{
					ml = EC->mSim->getBodyByName(n.c_str());
				}
				else if(num == 5)
				{
					ml = EC->mSim->getJointByName(n.c_str());
				}
				if(ml)
				{
					if(anum == 0)
					{
						MyLink *aml = EC->getBodyByName(an.c_str());
						if(aml)
						{
							if(type == 0)
							{
								EC->AttachObj(ml, aml);
							}
							else
							{
								ml->NodeList.push_back(aml->mNode);
							}
							UpdateList();
						}
					}
					else if(anum == 1)
					{
						myParticle *amp = EC->getParticleByName(an.c_str());
						if(amp)
						{
							
							if(type == 0)
							{
								EC->AttachObj(ml, amp);
							}
							else
							{
								ml->NodeList.push_back(amp->mNode);
							}
							UpdateList();
						}
					}
					else if(anum == 2)
					{
						MyLight *aml = EC->getLightByName(an.c_str());
						if(aml)
						{
							
							if(type == 0)
							{
								EC->AttachObj(ml, aml);
							}
							else
							{
								ml->NodeList.push_back(aml->mNode);
							}
							UpdateList();
						}

					}
					
					
				}
				
			}
			else if(num == 1)
			{
				myParticle *mp = EC->getParticleByName(n.c_str());
				if(mp)
				{
					if(anum == 0)
					{
						MyLink *aml = EC->getBodyByName(an.c_str());
						if(aml)
						{
							EC->AttachObj(aml, mp);
							UpdateList();
						}
					}
					else if(anum == 1)
					{
						myParticle *amp = EC->getParticleByName(an.c_str());
						if(amp)
						{
							EC->AttachObj(mp, amp);
							UpdateList();
						}
					}
					else if(anum == 2)
					{
						MyLight *aml = EC->getLightByName(an.c_str());
						if(aml)
						{
							EC->AttachObj(mp, aml);
							UpdateList();
						}

					}
				}
			}
			else if(num == 2)
			{
				MyLight *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					if(anum == 0)
					{
						MyLink *aml = EC->getBodyByName(an.c_str());
						if(aml)
						{
							EC->AttachObj(aml, ml);
							UpdateList();
						}
					}
					else if(anum == 1)
					{
						myParticle *amp = EC->getParticleByName(an.c_str());
						if(amp)
						{
							EC->AttachObj(amp, ml);
							UpdateList();
						}
					}
					else if(anum == 2)
					{
						MyLight *aml = EC->getLightByName(an.c_str());
						if(aml)
						{
							EC->AttachObj(ml, aml);
							UpdateList();
						}

					}
				}
				
			}
			else if(num == 3)
			{
				MyAnimation *man = EC->getAnimationByName(n.c_str());
				if(man)
				{
					if(anum == 0)
					{
						MyLink *aml = EC->getBodyByName(an.c_str());
						if(aml)
						{
							EC->AttachObj(man, aml);
							UpdateList();
						}
					}
					else if(anum == 1)
					{
						myParticle *amp = EC->getParticleByName(an.c_str());
						if(amp)
						{
							EC->AttachObj(man, amp);
							UpdateList();
						}
					}
					else if(anum == 2)
					{
						MyLight *aml = EC->getLightByName(an.c_str());
						if(aml)
						{
							EC->AttachObj(man, aml);
							UpdateList();
						}

					}
				}
				
			}
		}
		
		
	}
}
void NodeSetWidget::DettachSlot()
{
	int num = NumEdit->currentIndex();
	std::string n = NameEdit->currentText().toLocal8Bit();
	int type = TypeEdit->currentIndex();
	
	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			if(num == 0)
			{
				MyLink *ml = EC->getBodyByName(n.c_str());
				if(ml)
				{
					if(type == 0)
					{
						EC->DeatachObj(ml);
					}
					else
					{
						ml->NodeList.clear();
					}
					
					UpdateList();
				}
				
			}
			else if(num == 1)
			{
				myParticle *mp = EC->getParticleByName(n.c_str());
				if(mp)
				{
					EC->DeatachObj(mp);

					UpdateList();
				}
			}
			else if(num == 2)
			{
				MyLight *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					EC->DeatachObj(ml);
					UpdateList();
				}
				
			}
			

		}
		
		
	}
}
void NodeSetWidget::AttachNumSlot(int value)
{
	int anum = AttachNumBox->currentIndex();
	
	
	if(EC)
	{
		if(anum == 0)
		{
			AttachListBox->clear();
			for(int i=0;i < EC->QtLinks.size();i++)
			{
				AttachListBox->addItem(EC->QtLinks[i]->name.c_str());
			}
		}
		else if(anum == 1)
		{
			AttachListBox->clear();
			for(int i=0;i < EC->QtParticles.size();i++)
			{
				AttachListBox->addItem(EC->QtParticles[i]->name.c_str());
			}
		}
		else if(anum == 2)
		{
			AttachListBox->clear();
			for(int i=0;i < EC->QtLights.size();i++)
			{
				AttachListBox->addItem(EC->QtLights[i]->name.c_str());
			}
			
		}

	}
}


void NodeSetWidget::UpdateList()
{
	NumSlot(0);
}

void NodeSetWidget::NumSlot(int value)
{
	int num = NumEdit->currentIndex();
	
	
	
	if(EC)
	{
		if(num == 0)
		{
			NameEdit->clear();
			for(int i=0;i < EC->QtLinks.size();i++)
			{
				NameEdit->addItem(EC->QtLinks[i]->name.c_str());
			}
			
		}
		else if(num == 1)
		{
			NameEdit->clear();
			for(int i=0;i < EC->QtParticles.size();i++)
			{
				NameEdit->addItem(EC->QtParticles[i]->name.c_str());
			}
		}
		else if(num == 2)
		{
			NameEdit->clear();
			for(int i=0;i < EC->QtLights.size();i++)
			{
				NameEdit->addItem(EC->QtLights[i]->name.c_str());
			}
		}
		else if(num == 3)
		{
			NameEdit->clear();
			for(int i=0;i < EC->QtAnimations.size();i++)
			{
				NameEdit->addItem(EC->QtAnimations[i]->name.c_str());
			}
		}
		else if(num == 4)
		{
			NameEdit->clear();
			for(int i=0;i < EC->mSim->QtLinks.size();i++)
			{
				NameEdit->addItem(EC->mSim->QtLinks[i]->name.c_str());
			}
			
		}
		else if(num == 5)
		{
			NameEdit->clear();
			for(int i=0;i < EC->mSim->QtJoints.size();i++)
			{
				NameEdit->addItem(EC->mSim->QtJoints[i]->name.c_str());
			}
			
		}

		
		
		
	}

	AttachNumSlot(10);
	DettachNumSlot(10);
}

void NodeSetWidget::DettachNumSlot(int value)
{
	int num = NumEdit->currentIndex();
	std::string n = NameEdit->currentText().toLocal8Bit();
	//int dnum = DettachNumBox->currentIndex();
	
	
	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			if(num == 0)
			{
				MyLink *ml = EC->getBodyByName(n.c_str());
				if(ml)
				{
					DettachListBox->clear();
					for(int i=0;i < ml->mNode->mobj.size();i++)
					{
						DettachListBox->addItem(ml->mNode->mobj[i]->name.c_str());
					}
				}
				
			}
			else if(num == 1)
			{
				myParticle *mp = EC->getParticleByName(n.c_str());
				if(mp)
				{
					DettachListBox->clear();
					for(int i=0;i < mp->mNode->mobj.size();i++)
					{
						DettachListBox->addItem(mp->mNode->mobj[i]->name.c_str());
					}
				}
			}
			else if(num == 2)
			{
				MyLight *ml = EC->getLightByName(n.c_str());
				if(ml)
				{
					DettachListBox->clear();
					for(int i=0;i < ml->mNode->mobj.size();i++)
					{
						DettachListBox->addItem(ml->mNode->mobj[i]->name.c_str());
					}
				}
				
			}
			else if(num == 3)
			{
				MyAnimation *man = EC->getAnimationByName(n.c_str());
				if(man)
				{
					DettachListBox->clear();
					for(int i=0;i < man->mNode->mobj.size();i++)
					{
						DettachListBox->addItem(man->mNode->mobj[i]->name.c_str());
					}
				}
				
			}
		}
		
		
	}
}