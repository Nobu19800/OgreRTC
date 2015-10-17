/*!
 * @file  SimBodySet.cpp
 * @brief シミュレーションのボディ作成、設定用ウィンドウ
 *
 */

#include "SimBodySet.h"

#include "QtMacro.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>

#include "ODEBodyObj.h"


/**
*@brief シミュレーションのボディ作成、設定用ウィジェットのコンストラクタ
* @param parent 親ウィジェット
*/
SimBodySetWidget::SimBodySetWidget( QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
{
	up_flag = true;
	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;

	NameEdit = new QComboBox();
	NameEdit->setLineEdit(new QLineEdit());
	connect(NameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NameSlot(int)));

	layout->addWidget(NameEdit);


	TypeEdit = new QComboBox();
	TypeEdit->addItem("Sphere");
	TypeEdit->addItem("Box");
	TypeEdit->addItem("Cylinder");
	TypeEdit->addItem("Capsule");
	layout->addWidget(TypeEdit);

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

	QVBoxLayout *sizeLayout =  new QVBoxLayout();
	SizeXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 10000.0, 0.01, sizeLayout);
	SizeXspinBox->setValue(1);
	connect(SizeXspinBox, SIGNAL(valueChanged(double)), this, SLOT(SizeXSlot(double)));
	SizeYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 10000.0, 0.01, sizeLayout);
	SizeYspinBox->setValue(1);
	connect(SizeYspinBox, SIGNAL(valueChanged(double)), this, SLOT(SizeYSlot(double)));
	SizeZspinBox = SetDoubleSpinBox(tc->toUnicode("Z"), 10000.0, 0.01, sizeLayout);
	SizeZspinBox->setValue(1);
	connect(SizeZspinBox, SIGNAL(valueChanged(double)), this, SLOT(SizeZSlot(double)));
	SizeRspinBox = SetDoubleSpinBox(tc->toUnicode("R"), 10000.0, 0.01, sizeLayout);
	SizeRspinBox->setValue(1);
	connect(SizeRspinBox, SIGNAL(valueChanged(double)), this, SLOT(SizeRSlot(double)));
	QGroupBox *sizeGroup = new QGroupBox(tc->toUnicode("サイズ"));
	sizeGroup->setLayout(sizeLayout);
	layout->addWidget(sizeGroup);


	MassspinBox = SetDoubleSpinBox(tc->toUnicode("質量"), 10000.0, 0.01, layout);
	MassspinBox->setValue(1);
	connect(MassspinBox, SIGNAL(valueChanged(double)), this, SLOT(MassSlot(double)));


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


	QVBoxLayout *offsetLayout =  new QVBoxLayout();
	OffsetXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 10000.0, 0.01, offsetLayout);
	OffsetXspinBox->setValue(1);
	connect(OffsetXspinBox, SIGNAL(valueChanged(double)), this, SLOT(OffsetXSlot(double)));
	OffsetYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 10000.0, 0.01, offsetLayout);
	OffsetYspinBox->setValue(1);
	connect(OffsetYspinBox, SIGNAL(valueChanged(double)), this, SLOT(OffsetYSlot(double)));
	OffsetZspinBox = SetDoubleSpinBox(tc->toUnicode("Z"), 10000.0, 0.01, offsetLayout);
	OffsetZspinBox->setValue(1);
	connect(OffsetZspinBox, SIGNAL(valueChanged(double)), this, SLOT(OffsetZSlot(double)));
	QGroupBox *offsetGroup = new QGroupBox(tc->toUnicode("オフセット"));
	offsetGroup->setLayout(offsetLayout);
	layout->addWidget(offsetGroup);


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
*@brief シミュレーションのボディ作成、設定用ウィジェットのデストラクタ
*/
SimBodySetWidget::~SimBodySetWidget(void)
{

}

/**
*@brief ボディの設定をウィジェットに反映させるときのスロット
*/
void SimBodySetWidget::UpdateList()
{
	if(EC)
	{
		NameEdit->clear();
		for(int i=0;i < EC->mSim->QtLinks.size();i++)
		{
			
			NameEdit->addItem(EC->mSim->QtLinks[i]->name.c_str());
		}
		
	}
}

/**
*@brief 作成ボタンを押したときのスロット
*/
void SimBodySetWidget::SetSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	int type = TypeEdit->currentIndex();
	double px = PosXspinBox->value();
	double py = PosYspinBox->value();
	double pz = PosZspinBox->value();

	double szx = SizeXspinBox->value();
	double szy = SizeYspinBox->value();
	double szz = SizeZspinBox->value();
	double szr = SizeRspinBox->value();

	double sx = ScaleXspinBox->value();
	double sy = ScaleYspinBox->value();
	double sz = ScaleZspinBox->value();

	double ox = OffsetXspinBox->value();
	double oy = OffsetYspinBox->value();
	double oz = OffsetZspinBox->value();

	double roll = RollspinBox->value();
	double pitch = PitchspinBox->value();
	double yaw = YawspinBox->value();

	double m = MassspinBox->value();

	if(EC)
	{
		if(n == "")
		{
			return;
		}
		else if(EC->mSim->getBodyByName(n.c_str()))
		{
			return;
		}
		else
		{
			ODEBodyObj *ml;
			if(type == 0)
			{
				ml = EC->mSim->SetQtSphere(n.c_str(), m, szr);
			}
			else if(type == 1)
			{
				ml = EC->mSim->SetQtBox(n.c_str(), m, szx, szy, szz);
			}
			else if(type == 2)
			{
				ml = EC->mSim->SetQtSylinder(n.c_str(), m, szx, szr);
			}
			else if(type == 3)
			{
				ml = EC->mSim->SetQtCapsule(n.c_str(), m, szx, szr);
			}
			
			if(ml)
			{
				ml->SetBodyPosition(px, py, pz);
				ml->SetBodyRotation(roll, pitch, yaw);
				ml->SetODEScale(sx, sy, sz);
				ml->SetODEOffset(ox, oy, oz);
			}
			

			
			UpdateList();
			emit UpdateODEBody();
			NameEdit->setCurrentIndex(NameEdit->count()-1);
			
		}
	}
}

/**
*@brief 名前コンボボックスの番号が変わったときのスロット
* @param value 番号
*/
void SimBodySetWidget::NameSlot(int value)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		ODEBodyObj *ml = EC->mSim->getBodyByName(n.c_str());
		if(ml)
		{
			up_flag = false;
			TypeEdit->setCurrentIndex(ml->BodyType);
			PosXspinBox->setValue(ml->posx);
			PosYspinBox->setValue(ml->posy);
			PosZspinBox->setValue(ml->posz);

			ScaleXspinBox->setValue(ml->bscale_x);
			ScaleYspinBox->setValue(ml->bscale_x);
			ScaleZspinBox->setValue(ml->bscale_x);

			RollspinBox->setValue(ml->roll);
			PitchspinBox->setValue(ml->pitch);
			YawspinBox->setValue(ml->yaw);

			SizeXspinBox->setValue(ml->lx);
			SizeYspinBox->setValue(ml->ly);
			SizeZspinBox->setValue(ml->lz);
			SizeRspinBox->setValue(ml->rd);

			OffsetXspinBox->setValue(ml->offx);
			OffsetYspinBox->setValue(ml->offy);
			OffsetZspinBox->setValue(ml->offz);


			MassspinBox->setValue(ml->m);

			

			up_flag = true;

		}
		
	}
}

/**
*@brief 位置設定スピンボックスの値(X座標)を変更したときのスロット
* @param value 位置(X)
*/
void SimBodySetWidget::PosXSlot(double value)
{
	SetPos();
}

/**
*@brief 位置設定スピンボックスの値(Y座標)を変更したときのスロット
* @param value 位置(Y)
*/
void SimBodySetWidget::PosYSlot(double value)
{
	SetPos();
}

/**
*@brief 位置設定スピンボックスの値(Z座標)を変更したときのスロット
* @param value 位置(Z)
*/
void SimBodySetWidget::PosZSlot(double value)
{
	SetPos();
}

/**
*@brief サイズ設定スピンボックスの値(X軸方向)を変更したときのスロット
* @param value サイズ(X)
*/
void SimBodySetWidget::SizeXSlot(double value)
{
	SetSize();
}

/**
*@brief サイズ設定スピンボックスの値(Y軸方向)を変更したときのスロット
* @param value サイズ(Y)
*/
void SimBodySetWidget::SizeYSlot(double value)
{
	SetSize();
}

/**
*@brief サイズ設定スピンボックスの値(Z軸方向)を変更したときのスロット
* @param value サイズ(Z)
*/
void SimBodySetWidget::SizeZSlot(double value)
{
	SetSize();
}

/**
*@brief サイズ設定スピンボックスの値(半径)を変更したときのスロット
* @param value サイズ(半径)
*/
void SimBodySetWidget::SizeRSlot(double value)
{
	SetSize();
}

/**
*@brief 拡大率設定スピンボックスの値(X軸方向)を変更したときのスロット
* @param value 拡大率(X)
*/
void SimBodySetWidget::ScaleXSlot(double value)
{
	SetScale();
}

/**
*@brief 拡大率設定スピンボックスの値(Y軸方向)を変更したときのスロット
* @param value 拡大率(Y)
*/
void SimBodySetWidget::ScaleYSlot(double value)
{
	SetScale();
}

/**
*@brief 拡大率設定スピンボックスの値(Z軸方向)を変更したときのスロット
* @param value 拡大率(Z)
*/
void SimBodySetWidget::ScaleZSlot(double value)
{
	SetScale();
}

/**
*@brief 姿勢設定スピンボックスの値(ロール角)を変更したときのスロット
* @param value 角度(ロール)
*/
void SimBodySetWidget::RollSlot(double value)
{
	SetRot();
}

/**
*@brief 姿勢設定スピンボックスの値(ピッチ角)を変更したときのスロット
* @param value 角度(ピッチ)
*/
void SimBodySetWidget::PitchSlot(double value)
{
	SetRot();
}

/**
*@brief 姿勢設定スピンボックスの値(ヨー角)を変更したときのスロット
* @param value 角度(ヨー)
*/
void SimBodySetWidget::YawSlot(double value)
{
	SetRot();
}

/**
*@brief 表示設定ボタンを押したときのスロット
*/
void SimBodySetWidget::VisibleSlot()
{
	SetVisi(true);
}

/**
*@brief 非表示設定ボタンを押したときのスロット
*/
void SimBodySetWidget::unVisibleSlot()
{
	SetVisi(false);
}

/**
*@brief 削除ボタンを押したときのスロット
*/
void SimBodySetWidget::DestroySlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

	

	if(EC)
	{
		ODEBodyObj *ml = EC->mSim->getBodyByName(n.c_str());
		if(ml)
		{
			EC->mSim->DestroyQtBody(ml);
			UpdateList();
			emit UpdateODEBody();
		}
		
	}
}


/**
*@brief 3Dモデルとボディのオフセット設定スピンボックスの値(X軸方向)を変更したときのスロット
* @param value オフセット(X)
*/
void SimBodySetWidget::OffsetXSlot(double value)
{
	SetOffset();
}

/**
*@brief 3Dモデルとボディのオフセット設定スピンボックスの値(Y軸方向)を変更したときのスロット
* @param value オフセット(Y)
*/
void SimBodySetWidget::OffsetYSlot(double value)
{
	SetOffset();
}

/**
*@brief 3Dモデルとボディのオフセット設定スピンボックスの値(Z軸方向)を変更したときのスロット
* @param value オフセット(Z)
*/
void SimBodySetWidget::OffsetZSlot(double value)
{
	SetOffset();
}


/**
*@brief 質量設定スピンボックスの値を変更したときのスロット
* @param value 質量
*/
void SimBodySetWidget::MassSlot(double value)
{

}


/**
*@brief 位置設定スピンボックスの値を反映する関数
*/
void SimBodySetWidget::SetPos()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

		double px = PosXspinBox->value();
		double py = PosYspinBox->value();
		double pz = PosZspinBox->value();

		if(EC)
		{
			ODEBodyObj *ml = EC->mSim->getBodyByName(n.c_str());
			if(ml)
			{
				ml->SetBodyPosition(px, py, pz);
			}
			
		}
	}
}

/**
*@brief 拡大率設定スピンボックスの値を反映する関数
*/
void SimBodySetWidget::SetScale()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

		double sx = ScaleXspinBox->value();
		double sy = ScaleYspinBox->value();
		double sz = ScaleZspinBox->value();

		if(EC)
		{
			ODEBodyObj *ml = EC->mSim->getBodyByName(n.c_str());
			if(ml)
			{
				ml->SetODEScale(sx, sy, sz);
			}
			
		}
	}
}

/**
*@brief 姿勢設定スピンボックスの値を反映する関数
*/
void SimBodySetWidget::SetRot()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

		double roll = RollspinBox->value();
		double pitch = PitchspinBox->value();
		double yaw = YawspinBox->value();

		if(EC)
		{
			ODEBodyObj *ml = EC->mSim->getBodyByName(n.c_str());
			if(ml)
			{
				ml->SetBodyRotation(roll, pitch, yaw);
			}
			
		}
	}
}

/**
*@brief オフセット設定スピンボックスの値を反映する関数
*/
void SimBodySetWidget::SetOffset()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

		double ox = OffsetXspinBox->value();
		double oy = OffsetYspinBox->value();
		double oz = OffsetZspinBox->value();

		if(EC)
		{
			ODEBodyObj *ml = EC->mSim->getBodyByName(n.c_str());
			if(ml)
			{
				ml->SetODEOffset(ox, oy, oz);
			}
			
		}
	}
}

/**
*@brief 表示設定ボタンを反映する関数
* @param visi trueで表示、falseで非表示
*/
void SimBodySetWidget::SetVisi(bool visi)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	if(EC)
	{
		ODEBodyObj *ml = EC->mSim->getBodyByName(n.c_str());
		if(ml)
		{
			ml->SetVisible(visi);
		}
		
	}
}

/**
*@brief 大きさ設定スピンボックスの値を反映する関数
*/
void SimBodySetWidget::SetSize()
{
	double szx = SizeXspinBox->value();
	double szy = SizeYspinBox->value();
	double szz = SizeZspinBox->value();
	double szr = SizeRspinBox->value();
}