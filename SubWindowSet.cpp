/*!
 * @file  SubWindowSet.cpp
 * @brief サブウインドウの設定用ウインドウ
 *
 */

#include "SubWindowSet.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#include "QtMacro.h"


#include "SubWindow.h"


/**
*@brief 画面分割設定用ウィジェットのコンストラクタ
*@param parent 親ウィジェット
*/
SubWindowSetWidget::SubWindowSetWidget( QWidget *parent) : 
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
{
	up_flag = true;

	QTextCodec* tc = QTextCodec::codecForLocale();

	QVBoxLayout *layout = new QVBoxLayout;

	NameEdit = new QComboBox();
	NameEdit->setLineEdit(new QLineEdit());
	connect(NameEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(NameSlot(int)));
	layout->addWidget(NameEdit);



	
	SetButton = new QPushButton(tc->toUnicode("作成"));
	connect(SetButton, SIGNAL(clicked()), this, SLOT(SetSlot()));
	layout->addWidget(SetButton);

		
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


	QVBoxLayout *scaleLayout =  new QVBoxLayout();
	ScaleXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 1.0, 0.0, scaleLayout);
	ScaleXspinBox->setValue(0.1);
	ScaleXspinBox->setSingleStep(0.1);
	connect(ScaleXspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleXSlot(double)));
	ScaleYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 1.0, 0.0, scaleLayout);
	ScaleYspinBox->setValue(0.1);
	ScaleYspinBox->setSingleStep(0.1);
	connect(ScaleYspinBox, SIGNAL(valueChanged(double)), this, SLOT(ScaleYSlot(double)));
	QGroupBox *scaleGroup = new QGroupBox(tc->toUnicode("大きさ"));
	scaleGroup->setLayout(scaleLayout);
	layout->addWidget(scaleGroup);





	QVBoxLayout *cameraposLayout =  new QVBoxLayout();
	CameraPosXspinBox = SetDoubleSpinBox(tc->toUnicode("X"), 1000.0, -1000.0, cameraposLayout);
	connect(CameraPosXspinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraPosXSlot(double)));
	CameraPosYspinBox = SetDoubleSpinBox(tc->toUnicode("Y"), 1000.0, -1000.0, cameraposLayout);
	connect(CameraPosYspinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraPosYSlot(double)));
	CameraPosZspinBox = SetDoubleSpinBox(tc->toUnicode("Z"), 1000.0, -1000.0, cameraposLayout);
	connect(CameraPosZspinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraPosZSlot(double)));
	QGroupBox *cameraposGroup = new QGroupBox(tc->toUnicode("カメラの位置"));
	cameraposGroup->setLayout(cameraposLayout);
	layout->addWidget(cameraposGroup);


	QVBoxLayout *camreraangleLayout =  new QVBoxLayout();
	CameraRollspinBox = SetDoubleSpinBox(tc->toUnicode("Roll"), 360.0, 0.0, camreraangleLayout);
	connect(CameraRollspinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraRollSlot(double)));
	CameraPitchspinBox = SetDoubleSpinBox(tc->toUnicode("Pitch"), 360.0, 0.0, camreraangleLayout);
	connect(CameraPitchspinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraPitchSlot(double)));
	CameraYawspinBox = SetDoubleSpinBox(tc->toUnicode("Yaw"), 360.0, 0.0, camreraangleLayout);
	connect(CameraYawspinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraYawSlot(double)));
	QGroupBox *cameraangleGroup = new QGroupBox(tc->toUnicode("カメラの姿勢"));
	cameraangleGroup->setLayout(camreraangleLayout);
	layout->addWidget(cameraangleGroup);

	
	CameraLenspinBox = SetDoubleSpinBox(tc->toUnicode("距離"), 10000.0, 0.0, layout);
	CameraLenspinBox->setValue(100.0);
	connect(CameraLenspinBox, SIGNAL(valueChanged(double)), this, SLOT(CameraLenSlot(double)));



	VisibleButton = new QPushButton(tc->toUnicode("表示"));
	connect(VisibleButton, SIGNAL(clicked()), this, SLOT(VisibleSlot()));
	layout->addWidget(VisibleButton);

	unVisibleButton = new QPushButton(tc->toUnicode("非表示"));
	connect(unVisibleButton, SIGNAL(clicked()), this, SLOT(unVisibleSlot()));
	layout->addWidget(unVisibleButton);
	
	DestroyButton = new QPushButton(tc->toUnicode("削除"));
	connect(DestroyButton, SIGNAL(clicked()), this, SLOT(DestroySlot()));
	layout->addWidget(DestroyButton);

	RestartButton = new QPushButton(tc->toUnicode("再開"));
	connect(RestartButton, SIGNAL(clicked()), this, SLOT(RestartSlot()));
	layout->addWidget(RestartButton);

	StopButton = new QPushButton(tc->toUnicode("停止"));
	connect(StopButton, SIGNAL(clicked()), this, SLOT(StopSlot()));
	layout->addWidget(StopButton);

	
	
	
	layout->addStretch();

	setLayout(layout);
	
}

/**
*@brief 画面分割設定用ウィジェットのデストラクタ
*/
SubWindowSetWidget::~SubWindowSetWidget(void)
{

}

/**
*@brief 位置設定スピンボックスの値を反映する関数
*/
void SubWindowSetWidget::UpdatePos()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
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
				SubWindow *sw = EC->getSubWindowByName(n.c_str());
				if(sw)
				{
					sw->SetPosition(px, py);
				}
			}

		}
	}
}


/**
*@brief 大きさ設定スピンボックスの値を反映する関数
*/
void SubWindowSetWidget::UpdateSize()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
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
				SubWindow *sw = EC->getSubWindowByName(n.c_str());
				if(sw)
				{
					sw->SetSize(sx, sy);
				}
			}

		}
	}
}


/**
*@brief 表示設定ボタンを反映する関数
* @param visi trueで表示、falseで非表示
*/
void SubWindowSetWidget::UpdateVisi(bool visi)
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
			SubWindow *sw = EC->getSubWindowByName(n.c_str());
			if(sw)
			{
				sw->SetVisible(visi);
			}
		}

	}
}


/**
*@brief カメラの位置、姿勢、距離設定スピンボックスの値を反映する関数
*/
void SubWindowSetWidget::UpdateCameraPQ()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

		float cx = CameraPosXspinBox->value();
		float cy = CameraPosYspinBox->value();
		float cz = CameraPosZspinBox->value();

		float roll = CameraRollspinBox->value();
		float pitch = CameraPitchspinBox->value();
		float yaw = CameraYawspinBox->value();

		float len = CameraLenspinBox->value();

		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				SubWindow *sw = EC->getSubWindowByName(n.c_str());
				if(sw)
				{
					sw->UpdateCameraPQ(cx,cy,cz,roll,pitch,yaw,len);
				}
			}

		}
	}

}

/**
*@brief カメラの位置設定スピンボックスの値を反映する関数
*/
void SubWindowSetWidget::UpdateCameraPos()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
		float cx = CameraPosXspinBox->value();
		float cy = CameraPosYspinBox->value();
		float cz = CameraPosZspinBox->value();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				SubWindow *sw = EC->getSubWindowByName(n.c_str());
				if(sw)
				{
					sw->SetCameraPosition(cx, cy, cz);
				}
			}

		}
	}
}

/**
*@brief カメラの姿勢設定スピンボックスの値を反映する関数
*/
void SubWindowSetWidget::UpdateCameraRot()
{
	if(up_flag)
	{
		std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
		float roll = CameraRollspinBox->value();
		float pitch = CameraPitchspinBox->value();
		float yaw = CameraYawspinBox->value();


		if(EC)
		{
			if(n == "")
			{
				return;
			}
			else
			{
				SubWindow *sw = EC->getSubWindowByName(n.c_str());
				if(sw)
				{
					sw->SetCameraQuaternion(1, 0, 0, 0);
					sw->SetCameraRoll(roll);
					sw->SetCameraPitch(pitch);
					sw->SetCameraYaw(yaw);
				}
			}

		}
	}
}

/**
*@brief 作成ボタンを押したときのスロット
*/
void SubWindowSetWidget::SetSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
	float px = PosXspinBox->value();
	float py = PosYspinBox->value();

	float sx = ScaleXspinBox->value();
	float sy = ScaleYspinBox->value();

	float cx = CameraPosXspinBox->value();
	float cy = CameraPosYspinBox->value();
	float cz = CameraPosZspinBox->value();

	float roll = CameraRollspinBox->value();
	float pitch = CameraPitchspinBox->value();
	float yaw = CameraYawspinBox->value();


	std::string mn = n + "Tex";
	std::string wn = n + "Window";
	std::string cn = n + "Cam";
	std::string isn = n + "Image";
	std::string in = n + "Image";
	
	if(n == "")
	{
		return;
	}
	else if(EC->getSubWindowByName(n.c_str()))
	{
		return;
	}
	else
	{
		SubWindow *sw = EC->SetQtSubWindow(wn.c_str(), mn.c_str(), cn.c_str(), isn.c_str(), in.c_str());
		sw->SetPosition(px, py);
		sw->SetSize(sx, sy);
		sw->SetCameraPosition(cx, cy, cz);
		sw->SetCameraRotation(roll, pitch, yaw);

		UpdateList();
		NameEdit->setCurrentIndex(NameEdit->count()-1);
		
	}
	
	
}

/**
*@brief 位置設定スピンボックスの値(X座標)を変更したときのスロット
* @param value 位置(X)
*/
void SubWindowSetWidget::PosXSlot(double value)
{
	UpdatePos();
}

/**
*@brief 位置設定スピンボックスの値(Y座標)を変更したときのスロット
* @param value 位置(Y)
*/
void SubWindowSetWidget::PosYSlot(double value)
{
	UpdatePos();
}

/**
*@brief 大きさ設定スピンボックスの値(X軸方向)を変更したときのスロット
* @param value サイズ(X)
*/
void SubWindowSetWidget::ScaleXSlot(double value)
{
	UpdateSize();
}

/**
*@brief 大きさ設定スピンボックスの値(Y軸方向)を変更したときのスロット
* @param value サイズ(Y)
*/
void SubWindowSetWidget::ScaleYSlot(double value)
{
	UpdateSize();
}


/**
*@brief 表示設定ボタンを押したときのスロット
*/
void SubWindowSetWidget::VisibleSlot()
{
	UpdateVisi(true);
}

/**
*@brief 非表示設定ボタンを押したときのスロット
*/
void SubWindowSetWidget::unVisibleSlot()
{
	UpdateVisi(false);
}

/**
*@brief 削除ボタンを押したときのスロット
*/
void SubWindowSetWidget::DestroySlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		SubWindow *sw = EC->getSubWindowByName(n.c_str());

		if(sw)
		{
			EC->DestroyQtSubWindow(sw);
			UpdateList();
		}
		
	}
}

/**
*@brief カメラの位置設定スピンボックスの値(X座標)を変更したときのスロット
* @param value 位置(X)
*/
void SubWindowSetWidget::CameraPosXSlot(double value)
{
	UpdateCameraPQ();
}

/**
*@brief カメラの位置設定スピンボックスの値(Y座標)を変更したときのスロット
* @param value 位置(Y)
*/
void SubWindowSetWidget::CameraPosYSlot(double value)
{
	UpdateCameraPQ();
}

/**
*@brief カメラの位置設定スピンボックスの値(Z座標)を変更したときのスロット
* @param value 位置(Z)
*/
void SubWindowSetWidget::CameraPosZSlot(double value)
{
	UpdateCameraPQ();
}

/**
*@brief カメラの姿勢設定スピンボックスの値(ロール角)を変更したときのスロット
* @param value 角度(ロール)
*/
void SubWindowSetWidget::CameraRollSlot(double value)
{
	UpdateCameraPQ();
}

/**
*@brief カメラの姿勢設定スピンボックスの値(ピッチ角)を変更したときのスロット
* @param value 角度(ピッチ)
*/
void SubWindowSetWidget::CameraPitchSlot(double value)
{
	UpdateCameraPQ();
}

/**
*@brief カメラの姿勢設定スピンボックスの値(ヨー角)を変更したときのスロット
* @param value 角度(ヨー)
*/
void SubWindowSetWidget::CameraYawSlot(double value)
{
	UpdateCameraPQ();
}

/**
*@brief カメラの距離設定スピンボックスの値を変更したときのスロット
* @param value 距離
*/
void SubWindowSetWidget::CameraLenSlot(double value)
{
	UpdateCameraPQ();
}

/**
*@brief リセットボタンを押したときのスロット
*/
void SubWindowSetWidget::RestartSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
}

/**
*@brief 停止ボタンを押したときのスロット
*/
void SubWindowSetWidget::StopSlot()
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();
}

/**
*@brief 名前コンボボックスの番号が変わったときのスロット
* @param value 番号
*/
void SubWindowSetWidget::NameSlot(int value)
{
	std::string n = (const char*)NameEdit->currentText().toLocal8Bit();

	if(EC)
	{
		SubWindow *sw = EC->getSubWindowByName(n.c_str());

		if(sw)
		{
			up_flag = false;
			PosXspinBox->setValue(sw->pos_x);
			PosYspinBox->setValue(sw->pos_y);
			ScaleXspinBox->setValue(sw->size_x);
			ScaleYspinBox->setValue(sw->size_y);
			CameraPosXspinBox->setValue(sw->campos_x);
			CameraPosYspinBox->setValue(sw->campos_y);
			CameraPosZspinBox->setValue(sw->campos_z);
			CameraRollspinBox->setValue(sw->cam_roll);
			CameraPitchspinBox->setValue(sw->cam_pitch);
			CameraYawspinBox->setValue(sw->cam_yaw);
			CameraLenspinBox->setValue(sw->cam_len);
			up_flag = true;
		}
		
	}
}


/**
*@brief サブウインドウの設定をウィジェットに反映させるときのスロット
*/
void SubWindowSetWidget::UpdateList()
{
	if(EC)
	{
		NameEdit->clear();
		for(int i=0;i < EC->QtSubWindows.size();i++)
		{
			NameEdit->addItem(EC->QtSubWindows[i]->Wname.c_str());
		}
	}

}