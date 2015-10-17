/*!
 * @file  ParticleSet.cpp
 * @brief パーティクル設定用ウィンドウ
 *
 */

#include "ParticleSet.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#include "QtMacro.h"

#include "ParticleSet.h"



/**
*@brief パーティクル作成、設定用ウィジェットのコンストラクタ
* @param parent 親ウィジェット
*/
ParticleSetWidget::ParticleSetWidget(QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
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
	FileNameEdit->addItem("Examples/GreenyNimbus");
	FileNameEdit->addItem("Examples/PurpleFountain");
	FileNameEdit->addItem("Examples/Rain");
	FileNameEdit->addItem("Examples/JetEngine1");
	FileNameEdit->addItem("Examples/JetEngine2");
	FileNameEdit->addItem("Examples/Aureola");
	FileNameEdit->addItem("Examples/Swarm");
	FileNameEdit->addItem("Examples/Snow");
	FileNameEdit->addItem("Examples/Water/Rain");
	FileNameEdit->addItem("Examples/Fireworks");
	FileNameEdit->addItem("Examples/Smoke");
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


/**
*@brief パーティクル作成、設定用ウィジェットのデストラクタ
*/
ParticleSetWidget::~ParticleSetWidget(void)
{

}


void ParticleSetWidget::UpdatePos()
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
				ParticleObj *pc = EC->getParticleByName(n.c_str());
				if(pc)
				{
					pc->SetPosition(px, py, pz);
				}
			}

		}
	}
}

/**
*@brief 拡大率設定スピンボックスの値を反映する関数
*/
void ParticleSetWidget::UpdateScale()
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
				ParticleObj *pc = EC->getParticleByName(n.c_str());
				if(pc)
				{
					pc->SetScale(sx, sy, sz);
				}
			}

		}
	}
}



/**
*@brief 姿勢設定スピンボックスの値を反映する関数
*/
void ParticleSetWidget::UpdateRot()
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
				ParticleObj *pc = EC->getParticleByName(n.c_str());
				if(pc)
				{
					pc->SetRotation(roll,pitch,yaw);
				}
			}

		}
	}
}


/**
*@brief 表示設定ボタンを反映する関数
* @param visi trueで表示、falseで非表示
*/
void ParticleSetWidget::UpdateVisi(bool visi)
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
			ParticleObj *pc = EC->getParticleByName(n.c_str());
			if(pc)
			{
				pc->SetVisible(visi);
			}
		}
		
	}
}


/**
*@brief 作成ボタンを押したときのスロット
*/
void ParticleSetWidget::SetSlot()
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
		else if(EC->getParticleByName(n.c_str()))
		{
			return;
		}
		else
		{
			ParticleObj *pc = EC->CreateQtParticle(n.c_str(), fn.c_str());
			pc->SetPosition(px, py, pz);
			pc->SetScale(sx, sy, sz);
			pc->SetRotation(roll, pitch, yaw);
			

			
			UpdateList();
			emit UpdateParticle();
			NameEdit->setCurrentIndex(NameEdit->count()-1);
		}
	}

}

/**
*@brief 表示設定ボタンを押したときのスロット
*/
void ParticleSetWidget::VisibleSlot()
{
	UpdateVisi(true);
}

/**
*@brief 非表示設定ボタンを押したときのスロット
*/
void ParticleSetWidget::unVisibleSlot()
{
	UpdateVisi(false);
}


/**
*@brief 削除ボタンを押したときのスロット
*/
void ParticleSetWidget::DestroySlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		ParticleObj *pc = EC->getParticleByName(n.c_str());
		if(pc)
		{
			EC->DestroyQtParticle(pc);
			UpdateList();
			emit UpdateParticle();
		}
		
	}
}

/**
*@brief 位置設定スピンボックスの値(X座標)を変更したときのスロット
* @param value 位置(X)
*/
void ParticleSetWidget::PosXSlot(double value)
{
	UpdatePos();
}

/**
*@brief 位置設定スピンボックスの値(Y座標)を変更したときのスロット
* @param value 位置(Y)
*/
void ParticleSetWidget::PosYSlot(double value)
{
	UpdatePos();
}

/**
*@brief 位置設定スピンボックスの値(Z座標)を変更したときのスロット
* @param value 位置(Z)
*/
void ParticleSetWidget::PosZSlot(double value)
{
	UpdatePos();
}

/**
*@brief 拡大率設定スピンボックスの値(X軸方向)を変更したときのスロット
* @param value 拡大率(X)
*/
void ParticleSetWidget::ScaleXSlot(double value)
{
	UpdateScale();
}

/**
*@brief 拡大率設定スピンボックスの値(Y軸方向)を変更したときのスロット
* @param value 拡大率(Y)
*/
void ParticleSetWidget::ScaleYSlot(double value)
{
	UpdateScale();
}

/**
*@brief 拡大率設定スピンボックスの値(Z軸方向)を変更したときのスロット
* @param value 拡大率(Z)
*/
void ParticleSetWidget::ScaleZSlot(double value)
{
	UpdateScale();
}

/**
*@brief 姿勢設定スピンボックスの値(ロール角)を変更したときのスロット
* @param value 角度(ロール)
*/
void ParticleSetWidget::RollSlot(double value)
{
	UpdateRot();
}

/**
*@brief 姿勢設定スピンボックスの値(ピッチ角)を変更したときのスロット
* @param value 角度(ピッチ)
*/
void ParticleSetWidget::PitchSlot(double value)
{
	UpdateRot();
}

/**
*@brief 姿勢設定スピンボックスの値(ヨー角)を変更したときのスロット
* @param value 角度(ヨー)
*/
void ParticleSetWidget::YawSlot(double value)
{
	UpdateRot();
}

/**
*@brief 名前コンボボックスの番号が変わったときのスロット
* @param value 番号
*/
void ParticleSetWidget::NameSlot(int value)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		ParticleObj *pc = EC->getParticleByName(n.c_str());
		if(pc)
		{
			up_flag = false;
			PosXspinBox->setValue(pc->mNode->pos_x);
			PosYspinBox->setValue(pc->mNode->pos_y);
			PosZspinBox->setValue(pc->mNode->pos_z);

			ScaleXspinBox->setValue(pc->mNode->scale_x);
			ScaleYspinBox->setValue(pc->mNode->scale_y);
			ScaleZspinBox->setValue(pc->mNode->scale_z);

			RollspinBox->setValue(pc->mNode->roll);
			PitchspinBox->setValue(pc->mNode->pitch);
			YawspinBox->setValue(pc->mNode->yaw);

			

			FileNameEdit->lineEdit()->setText(pc->filename.c_str());

			up_flag = true;
			

		}
		
	}
}


/**
*@brief パーティクルを作成、削除したときのスロット
*/
void ParticleSetWidget::UpdateList()
{
	if(EC)
	{
		NameEdit->clear();
		for(int i=0;i < EC->QtParticles.size();i++)
		{
			NameEdit->addItem(EC->QtParticles[i]->name.c_str());
		}
	}

}

