#include "BodySet.h"
#include "MyQtMacro.h"
#include <QtGui/QApplication>
#include <QtGui/QPainter>

#include "MyLink.h"




BodySetWidget::BodySetWidget( QWidget *parent) : 
QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))
{
	up_flag = true;
	
	

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
	FileNameEdit->addItem("athene.mesh");
	FileNameEdit->addItem("Barrel.mesh");
	FileNameEdit->addItem("column.mesh");
	FileNameEdit->addItem("cornell.mesh");
	FileNameEdit->addItem("cube.mesh");
	FileNameEdit->addItem("facial.mesh");
	FileNameEdit->addItem("fish.mesh");
	FileNameEdit->addItem("geosphere4500.mesh");
	FileNameEdit->addItem("geosphere8000.mesh");
	FileNameEdit->addItem("jaiqua.mesh");
	FileNameEdit->addItem("knot.mesh");
	FileNameEdit->addItem("ninja.mesh");
	FileNameEdit->addItem("ogrehead.mesh");
	FileNameEdit->addItem("penguin.mesh");
	FileNameEdit->addItem("razor.mesh");
	FileNameEdit->addItem("robot.mesh");
	FileNameEdit->addItem("RZR-002.mesh");
	FileNameEdit->addItem("ShaderSystem.mesh");
	FileNameEdit->addItem("sibenik.mesh");
	FileNameEdit->addItem("sphere.mesh");
	FileNameEdit->addItem("spine.mesh");
	FileNameEdit->addItem("tudorhouse.mesh");
	FileNameEdit->addItem("WoodPallet.mesh");
	FileNameLayout->addWidget(FileNameEdit);
	layout->addLayout(FileNameLayout);


	
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


	QVBoxLayout *scaleLayout =  new QVBoxLayout();
	ScaleXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 10000.0, 0.01, scaleLayout);
	ScaleXspinBox->setValue(1);
	connect(ScaleXspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleXSlot(double)));
	ScaleYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 10000.0, 0.01, scaleLayout);
	ScaleYspinBox->setValue(1);
	connect(ScaleYspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleYSlot(double)));
	ScaleZspinBox = SetDoubleSpinBox(tc->toUnicode("Z"), 10000.0, 0.01, scaleLayout);
	ScaleZspinBox->setValue(1);
	connect(ScaleZspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleZSlot(double)));
	QGroupBox *scaleGroup = new QGroupBox(tc->toUnicode("拡大率"));
	scaleGroup->setLayout(scaleLayout);
	layout->addWidget(scaleGroup);


	QVBoxLayout *angleLayout =  new QVBoxLayout();
	RollspinBox = SetDoubleSpinBox(tc->toUnicode("Roll"), 360.0, 0.0, angleLayout);
	connect(RollspinBox, SIGNAL(valueChanged(double)), this, SLOT(RollSlot(double)));
	PitchspinBox = SetDoubleSpinBox(tc->toUnicode("Pitch"), 360.0, 0.0, angleLayout);
	connect(PitchspinBox, SIGNAL(valueChanged(double)), this, SLOT(PitchSlot(double)));
	YawspinBox = SetDoubleSpinBox(tc->toUnicode("Yaw"), 360.0, 0.0, angleLayout);
	connect(YawspinBox, SIGNAL(valueChanged(double)), this, SLOT(YawSlot(double)));
	QGroupBox *angleGroup = new QGroupBox(tc->toUnicode("姿勢"));
	angleGroup->setLayout(angleLayout);
	layout->addWidget(angleGroup);

	
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
	AlphaspinBox = SetDoubleSpinBox(tc->toUnicode("透明度"), 1, 0, ColorLayout);
	AlphaspinBox->setSingleStep(0.1);
	AlphaspinBox->setValue(1.0);
	connect(AlphaspinBox, SIGNAL(valueChanged(double)), this, SLOT(AlphaSlot(double)));
	QGroupBox *colorGroup = new QGroupBox(tc->toUnicode("色"));
	colorGroup->setLayout(ColorLayout);
	layout->addWidget(colorGroup);
	





	

	QVBoxLayout *AnimationLayout =  new QVBoxLayout();
	AnimationEdit = new QComboBox();
	AnimationEdit->setLineEdit(new QLineEdit());
	AnimationLayout->addWidget(AnimationEdit);
	SetAnimationButton = new QPushButton(tc->toUnicode("アニメーション設定"));
	connect(SetAnimationButton, SIGNAL(clicked()), this, SLOT(SetAnimationSlot()));
	AnimationLayout->addWidget(SetAnimationButton);
	ResetAnimationButton = new QPushButton(tc->toUnicode("アニメーションリセット"));
	connect(ResetAnimationButton, SIGNAL(clicked()), this, SLOT(ResetAnimationSlot()));
	AnimationLayout->addWidget(ResetAnimationButton);
	QGroupBox *animationGroup = new QGroupBox(tc->toUnicode("アニメーション"));
	animationGroup->setLayout(AnimationLayout);
	AnimationspinBox = SetDoubleSpinBox(tc->toUnicode("時間"), 0.0, 0.0, AnimationLayout);
	connect(AnimationspinBox, SIGNAL(valueChanged(double)), this, SLOT(AnimationSlot(double)));
	layout->addWidget(animationGroup);

	QVBoxLayout *MaterialLayout =  new QVBoxLayout();
	MaterialEdit = new QComboBox();
	MaterialEdit->setLineEdit(new QLineEdit());
	MaterialEdit->addItem("Examples/SphereMappedRustySteel");
	MaterialEdit->addItem("Examples/OgreLogo");
	MaterialEdit->addItem("Examples/BeachStones");
	MaterialEdit->addItem("Examples/RustySteel");
	MaterialEdit->addItem("Examples/Chrome");
	MaterialEdit->addItem("Examples/SpaceSkyPlane");
	MaterialEdit->addItem("Examples/OgreDance");
	MaterialEdit->addItem("Examples/OgreParade");
	MaterialEdit->addItem("Examples/OgreSpin");
	MaterialEdit->addItem("Examples/OgreWobble");
	MaterialEdit->addItem("Examples/BumpyMetal");
	MaterialEdit->addItem("Examples/WaterStream");
	MaterialEdit->addItem("Examples/Flare");
	MaterialEdit->addItem("Examples/Flare2");
	MaterialEdit->addItem("Examples/Flare3");
	MaterialEdit->addItem("Examples/FlarePointSprite");
	MaterialEdit->addItem("Examples/Droplet");
	MaterialEdit->addItem("Examples/Hilite/Yellow");
	MaterialEdit->addItem("Examples/Rocky");
	MaterialEdit->addItem("Examples/10PointBlock");
	MaterialEdit->addItem("Examples/Fish");
	MaterialEdit->addItem("Examples/Ninja");
	MaterialEdit->addItem("Examples/Robot");
	MaterialEdit->addItem("Examples/GrassFloor");
	MaterialEdit->addItem("Examples/GrassWaverVpCg");
	MaterialEdit->addItem("Examples/GrassWaverTexVpCg");
	MaterialEdit->addItem("Examples/GrassWaverAmbientVpCg");
	MaterialEdit->addItem("Examples/GrassWaverAmbientFpCg");
	MaterialEdit->addItem("Examples/GrassWaverFpCg");
	MaterialEdit->addItem("Examples/GrassWaverCasterVpCg");
	MaterialEdit->addItem("Examples/GrassWaverCasterFpCg");
	MaterialEdit->addItem("Examples/GrassWaverReceiverVpCg");
	MaterialEdit->addItem("Examples/GrassWaverReceiverFpCg");
	MaterialEdit->addItem("Examples/GrassWaverVpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverTexVpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverAmbientVpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverAmbientFpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverCasterVpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverCasterFpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverReceiverVpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverReceiverFpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverFpGLSLES");
	MaterialEdit->addItem("Examples/GrassWaverReceiverVp");
	MaterialEdit->addItem("Examples/GrassWaverReceiverFp");
	MaterialEdit->addItem("Examples/GrassWaverCasterVp");
	MaterialEdit->addItem("Examples/GrassWaverCasterFp");
	MaterialEdit->addItem("Examples/GrassWaverAmbientVp");
	MaterialEdit->addItem("Examples/GrassWaverAmbientFp");
	MaterialEdit->addItem("Examples/GrassWaverTexVp");
	MaterialEdit->addItem("Examples/GrassWaverFp");
	MaterialEdit->addItem("Examples/GrassWaverVp");
	MaterialEdit->addItem("Examples/GrassBladesShadowCaster");
	MaterialEdit->addItem("Examples/GrassBladesShadowReceiver");
	MaterialEdit->addItem("Examples/GrassBladesAdditiveFloatTransparentBest");
	MaterialEdit->addItem("Examples/GrassBladesAdditiveFloatTransparent");
	MaterialEdit->addItem("Examples/GrassBladesAdditiveFloat");
	MaterialEdit->addItem("Examples/GrassBladesAdditive");
	MaterialEdit->addItem("Examples/GrassBlades");
	MaterialEdit->addItem("Examples/Rockwall");
	MaterialEdit->addItem("Examples/Aureola");
	MaterialEdit->addItem("Examples/HardwareMorphAnimation");
	MaterialEdit->addItem("Examples/HardwarePoseAnimation");
	MaterialEdit->addItem("Examples/HardwareMorphAnimationWithNormals");
	MaterialEdit->addItem("Examples/HardwarePoseAnimationWithNormals");
	MaterialEdit->addItem("RustyBarrel");
	MaterialEdit->addItem("WoodPallet");
	MaterialEdit->addItem("Examples/LightRibbonTrail");
	MaterialEdit->addItem("Examples/TudorHouse");
	MaterialEdit->addItem("jaiqua");
	MaterialEdit->addItem("Examples/Plane/IntegratedShadows");
	MaterialEdit->addItem("Examples/ShowUV_pCg");
	MaterialEdit->addItem("Examples/ShowUV_pGLSLES");
	MaterialEdit->addItem("Examples/ShowUV_p");
	MaterialEdit->addItem("Examples/ShowUVdir3D_pCg");
	MaterialEdit->addItem("Examples/ShowUVdir3D_pGLSLES");
	MaterialEdit->addItem("Examples/ShowUVdir3D_p");
	MaterialEdit->addItem("Examples/ShowTangents_vCg");
	MaterialEdit->addItem("Examples/ShowTangents_vGLSLES");
	MaterialEdit->addItem("Examples/ShowTangents_v");
	MaterialEdit->addItem("Examples/ShowNormals_vCg");
	MaterialEdit->addItem("Examples/ShowNormals_v");
	MaterialEdit->addItem("Examples/ShowUV");
	MaterialEdit->addItem("Examples/ShowTangents");
	MaterialEdit->addItem("Examples/ShowNormals");
	MaterialLayout->addWidget(MaterialEdit);
	SetMaterialButton = new QPushButton(tc->toUnicode("マテリアル設定"));
	connect(SetMaterialButton, SIGNAL(clicked()), this, SLOT(SetMaterialSlot()));
	MaterialLayout->addWidget(SetMaterialButton);
	QGroupBox *MaterialGroup = new QGroupBox(tc->toUnicode("マテリアル"));
	MaterialGroup->setLayout(MaterialLayout);
	layout->addWidget(MaterialGroup);


	

	VisibleButton = new QPushButton(tc->toUnicode("表示"));
	connect(VisibleButton, SIGNAL(clicked()), this, SLOT(VisibleSlot()));
	layout->addWidget(VisibleButton);

	unVisibleButton = new QPushButton(tc->toUnicode("非表示"));
	connect(unVisibleButton, SIGNAL(clicked()), this, SLOT(unVisibleSlot()));
	layout->addWidget(unVisibleButton);
	
	DestroyButton = new QPushButton(tc->toUnicode("削除"));
	connect(DestroyButton, SIGNAL(clicked()), this, SLOT(DestroySlot()));
	layout->addWidget(DestroyButton);

	SetShadowButton = new QPushButton(tc->toUnicode("影表示"));
	connect(SetShadowButton, SIGNAL(clicked()), this, SLOT(SetShadowSlot()));
	layout->addWidget(SetShadowButton);

	RemoveShadowButton = new QPushButton(tc->toUnicode("影非表示"));
	connect(RemoveShadowButton, SIGNAL(clicked()), this, SLOT(RemoveShadowSlot()));
	layout->addWidget(RemoveShadowButton);

	SetBoundingBoxButton = new QPushButton(tc->toUnicode("ボックス表示"));
	connect(SetBoundingBoxButton, SIGNAL(clicked()), this, SLOT(SetBoundingBoxSlot()));
	layout->addWidget(SetBoundingBoxButton);

	RemoveBoundingBoxButton = new QPushButton(tc->toUnicode("ボックス非表示"));
	connect(RemoveBoundingBoxButton, SIGNAL(clicked()), this, SLOT(RemoveBoundingBoxSlot()));
	layout->addWidget(RemoveBoundingBoxButton);



	layout->addStretch();
	
	

	setLayout(layout);
	
}

//----------------------------------------------------------------------------------------

BodySetWidget::~BodySetWidget(void)
{

}


void BodySetWidget::UpdatePos()
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
				MyLink *ml = EC->getBodyByName(n.c_str());
				if(ml)
				{
					ml->SetPosition(px, py, pz);
				}
			}

		}
	}
}
void BodySetWidget::UpdateScale()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

		float sx = ScaleXspinBox->value();
		float sy = ScaleYspinBox->value();
		float sz = ScaleZspinBox->value();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				MyLink *ml = EC->getBodyByName(n.c_str());
				if(ml)
				{
					ml->SetScale(sx, sy, sz);
				}
			}

		}
	}
}
void BodySetWidget::UpdateRot()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

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
				MyLink *ml = EC->getBodyByName(n.c_str());
				if(ml)
				{
					ml->SetRotation(roll, pitch, yaw);
					
				}
			}

		}
	}
}
void BodySetWidget::UpdateColor()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();


		float red = RedspinBox->value();
		float green = GreenspinBox->value();
		float blue = BluespinBox->value();
		float alpha = AlphaspinBox->value();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				MyLink *ml = EC->getBodyByName(n.c_str());
				if(ml)
				{
					EC->setEColor(ml,red,green,blue,alpha);
				}
			}

		}
	}
}

void BodySetWidget::UpdateShadow(bool visi)
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
			MyLink *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				ml->SetShadows(visi);
			}
		}
		
	}
}
void BodySetWidget::UpdateVisi(bool visi)
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
			MyLink *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				ml->SetVisible(visi);
			}
		}
		
	}
}
void BodySetWidget::UpdateBound(bool visi)
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
			MyLink *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				ml->BoundingBoxVisible(visi);
			}
		}
		
	}
}

void BodySetWidget::SetSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	std::string fn = (const char*)FileNameEdit->currentText().toLocal8Bit();
	float px = PosXspinBox->value();
	float py = PosYspinBox->value();
	float pz = PosZspinBox->value();

	float sx = ScaleXspinBox->value();
	float sy = ScaleYspinBox->value();
	float sz = ScaleZspinBox->value();

	float roll = RollspinBox->value();
	float pitch = PitchspinBox->value();
	float yaw = YawspinBox->value();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else if(EC->getBodyByName(n.c_str()))
		{
			return;
		}
		else
		{
			MyLink *ml = EC->SetQtBody(n.c_str(), fn.c_str());
			ml->SetScale(sx, sy, sz);
			ml->SetPosition(px, py, pz);
			ml->SetRotation(roll, pitch, yaw);
			

			
			UpdateList();
			NameEdit->setCurrentIndex(NameEdit->count()-1);
			
		}
	}


}

void BodySetWidget::VisibleSlot()
{
	UpdateVisi(true);
}

void BodySetWidget::unVisibleSlot()
{
	UpdateVisi(false);
}



void BodySetWidget::SetAnimationSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	std::string c = (const char*)AnimationEdit->currentText().toLocal8Bit();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyLink *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				ml->SetAnimation(c.c_str());
				AnimationspinBox->setMaximum(ml->mAnimationState->getLength());
			}
		}
		
	}
}

void BodySetWidget::ResetAnimationSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

	std::string c = (const char*)AnimationEdit->currentText().toLocal8Bit();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyLink *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				ml->ResetAnimation(c.c_str());
			}
		}
		
	}
}

void BodySetWidget::DestroySlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		MyLink *ml = EC->getBodyByName(n.c_str());
		if(ml)
		{
			EC->DestroyQtBody(ml);
			UpdateList();
		}
		
	}
	
}

void BodySetWidget::SetShadowSlot()
{

	UpdateShadow(true);
	
}

void BodySetWidget::RemoveShadowSlot()
{
	UpdateShadow(false);
	
	
}

void BodySetWidget::PosXSlot(double value)
{
	UpdatePos();
}
void BodySetWidget::PosYSlot(double value)
{
	UpdatePos();
}
void BodySetWidget::PosZSlot(double value)
{
	UpdatePos();
}
void BodySetWidget::ScaleXSlot(double value)
{
	UpdateScale();
}
void BodySetWidget::ScaleYSlot(double value)
{
	UpdateScale();

}
void BodySetWidget::ScaleZSlot(double value)
{
	UpdateScale();
}
void BodySetWidget::RollSlot(double value)
{
	UpdateRot();
}
void BodySetWidget::PitchSlot(double value)
{
	UpdateRot();
}
void BodySetWidget::YawSlot(double value)
{
	UpdateRot();
}
void BodySetWidget::RedSlot(double value)
{
	UpdateColor();
}
void BodySetWidget::GreenSlot(double value)
{
	UpdateColor();
}
void BodySetWidget::BlueSlot(double value)
{
	UpdateColor();
}
void BodySetWidget::AlphaSlot(double value)
{
	UpdateColor();
}

void BodySetWidget::AnimationSlot(double value)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	std::string c = (const char*)AnimationEdit->currentText().toLocal8Bit();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else
		{
			MyLink *ml = EC->getBodyByName(n.c_str());
			if(ml)
			{
				if(ml->mAnimationState)
				{
					ml->ResetAnimation(c.c_str());
					ml->mAnimationState->setTimePosition(value);
				}
				//ml->anim_speed = value;
			}
		}
		
	}
}

void BodySetWidget::SetBoundingBoxSlot()
{
	UpdateBound(true);
}

void BodySetWidget::RemoveBoundingBoxSlot()
{
	UpdateBound(false);
}

void BodySetWidget::NameSlot(int value)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		MyLink *ml = EC->getBodyByName(n.c_str());
		if(ml)
		{
			up_flag = false;
			PosXspinBox->setValue(ml->mNode->pos_x);
			PosYspinBox->setValue(ml->mNode->pos_y);
			PosZspinBox->setValue(ml->mNode->pos_z);

			ScaleXspinBox->setValue(ml->mNode->scale_x);
			ScaleYspinBox->setValue(ml->mNode->scale_y);
			ScaleZspinBox->setValue(ml->mNode->scale_z);

			RollspinBox->setValue(ml->mNode->roll);
			PitchspinBox->setValue(ml->mNode->pitch);
			YawspinBox->setValue(ml->mNode->yaw);

			if(ml->color_visi)
			{
				RedspinBox->setValue(ml->red);
				GreenspinBox->setValue(ml->green);
				BluespinBox->setValue(ml->blue);
				AlphaspinBox->setValue(ml->alpha);
			}

			if(ml->mat_visi)
			{
				MaterialEdit->lineEdit()->setText(ml->material_name.c_str());
			}

			AnimationEdit->lineEdit()->setText(ml->anim_name.c_str());
			AnimationspinBox->setValue(ml->anim_speed);

			up_flag = true;

		}
		
	}
}


void BodySetWidget::UpdateList()
{
	if(EC)
	{
		NameEdit->clear();
		for(int i=0;i < EC->QtLinks.size();i++)
		{
			//std::cout << EC->QtLinks[i]->name << std::endl;
			NameEdit->addItem(EC->QtLinks[i]->name.c_str());
		}
		emit UpdateBody();
	}
}

void BodySetWidget::mouseMoveSlot(QMouseEvent*  evt, int dx, int dy)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		
		MyLink *ml = EC->getBodyByName(n.c_str());
		if(ml)
		{
			if(ml->mNode->bound_visi)
			{
				if((evt->buttons() & Qt::LeftButton) && (evt->buttons() & Qt::RightButton))
				{
					up_flag = false;
					float pz = EC->CamLen * dy/200.;
					ml->UpdatePos(0, 0, pz, EC->CamRoll, EC->CamPitch, EC->CamYaw);
					up_flag = true;
					
				}
				else if(evt->buttons() & Qt::LeftButton)
				{
					
					up_flag = false;
					float px = EC->CamLen * (float)dx / 2000.;
					float py = -EC->CamLen * (float)dy / 2000.;
					ml->UpdatePos(px, py, 0, EC->CamRoll, EC->CamPitch, EC->CamYaw);
					up_flag = true;
					
				}
				else if(evt->buttons() & Qt::RightButton)
				{
					up_flag = false;
					float px = (float)dx/4;
					float py = (float)dy/4;
					ml->UpdateRot(px,py,EC->CamRoll, EC->CamPitch, EC->CamYaw);
					up_flag = true;
				}
				
				
				NameSlot(0);
			}
		}
	}
}

void BodySetWidget::mousePressSlot(QMouseEvent*  evt)
{
	if(EC)
	{
	
		MyLink *ml = EC->GetQueryScene(evt->pos().x(), evt->pos().y());
		if(ml)
		{
			ml->BoundingBoxVisible(true);
			for(int i=0;i < EC->QtLinks.size();i++)
			{
				if(EC->QtLinks[i] == ml)
				{
					NameEdit->lineEdit()->setText(EC->QtLinks[i]->name.c_str());
				}
			}
			
		}
		else
		{
			for(int i=0;i < EC->MyLinks.size();i++)
			{
				EC->MyLinks[i]->BoundingBoxVisible(false);
			}
		}
	}
}

void BodySetWidget::mouseReleaseSlot(QMouseEvent*  evt)
{
	if(EC)
	{
		up_flag = false;

		up_flag = true;
	}
}

void BodySetWidget::MaterialSlot()
{
	

}
void BodySetWidget::SetMaterialSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	std::string en = (const char*)MaterialEdit->currentText().toLocal8Bit();
	if(EC)
	{
		MyLink *ml = EC->getBodyByName(n.c_str());
		if(ml)
		{
			ml->SetMaterial(en.c_str());
		}
		
	}
}



