/*!
 * @file  mainwindow.cpp
 * @brief メインウインドウ
 *
 */


#include <QtWidgets>
#include <QLabel>
#include <QTextEdit>
#include <qfont.h>
#include <QtWidgets>
#include <coil/stringutil.h>


#include "mainwindow.h"
#include "OgreWidget.h"















/**
*@brief メインウインドウのコンストラクタ
*@param argc コマンドライン引数の数
*@param argv コマンドライン引数
*@param parent 親ウィジェット
*/
MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
: QMainWindow(parent)
{
	
	tc = QTextCodec::codecForLocale();
	
	
	

	QHBoxLayout *layout = new QHBoxLayout;
	


	mOgreWidget = new OgreWidget() ;
	
	

	
	
	layout->addWidget(mOgreWidget);

	tabWidget = new QTabWidget;


	mBodySetWidget = new BodySetWidget();
	tabWidget->addTab(mBodySetWidget, tc->toUnicode("ボディ"));
	mBornSetWidget = new BornSetWidget();
	tabWidget->addTab(mBornSetWidget, tc->toUnicode("ボーン"));
	mCameraSetWidget = new CameraSetWidget();
	tabWidget->addTab(mCameraSetWidget, tc->toUnicode("カメラ"));
	mGUISetWidget = new GUISetWidget();
	tabWidget->addTab(mGUISetWidget, tc->toUnicode("CEGUI"));
	mGUITextSetWidget = new GUITextSetWidget();
	tabWidget->addTab(mGUITextSetWidget, tc->toUnicode("CEGUIのテキスト"));
	mImageSetWidget = new ImageSetWidget();
	tabWidget->addTab(mImageSetWidget, tc->toUnicode("CEGUIの画像"));
	mParticleSetWidget = new ParticleSetWidget();
	tabWidget->addTab(mParticleSetWidget, tc->toUnicode("パーティクル"));
	mSubWindowSetWidget = new SubWindowSetWidget();
	tabWidget->addTab(mSubWindowSetWidget, tc->toUnicode("画面分割"));
	mAnimationSetWidget = new AnimationSetWidget();
	tabWidget->addTab(mAnimationSetWidget, tc->toUnicode("アニメーション"));
	mLightSetWidget = new LightSetWidget();
	tabWidget->addTab(mLightSetWidget, tc->toUnicode("光源"));
	mNodeSetWidget = new NodeSetWidget();
	tabWidget->addTab(mNodeSetWidget, tc->toUnicode("ノード"));
	mSimulationSetWidget = new SimulationSetWidget();
	tabWidget->addTab(mSimulationSetWidget, tc->toUnicode("物理シミュレーション(設定)"));
	mSimBodySetWidget = new SimBodySetWidget();
	tabWidget->addTab(mSimBodySetWidget, tc->toUnicode("物理シミュレーション(ボディ)"));
	mSimJointSetWidget = new SimJointSetWidget();
	tabWidget->addTab(mSimJointSetWidget, tc->toUnicode("物理シミュレーション(ジョイント)"));
	mOtherSetWidget = new OtherSetWidget();
	tabWidget->addTab(mOtherSetWidget, tc->toUnicode("その他"));

	connect(mBodySetWidget, SIGNAL(UpdateBody()), mBornSetWidget, SLOT(UpdateBody()));
	connect(mGUISetWidget, SIGNAL(UpdateGUI()), mGUITextSetWidget, SLOT(UpdateGUI()));
	connect(mGUISetWidget, SIGNAL(UpdateGUI()), mImageSetWidget, SLOT(UpdateGUI()));


	connect(this, SIGNAL(UpdateList()), mBodySetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mCameraSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mGUISetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mGUITextSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mImageSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mParticleSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mSubWindowSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mAnimationSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mLightSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mNodeSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mSimulationSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mSimBodySetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mSimJointSetWidget, SLOT(UpdateList()));
	connect(this, SIGNAL(UpdateList()), mOtherSetWidget, SLOT(UpdateList()));

	connect(mBodySetWidget, SIGNAL(UpdateBody()), mNodeSetWidget, SLOT(UpdateList()));
	connect(mParticleSetWidget, SIGNAL(UpdateParticle()), mNodeSetWidget, SLOT(UpdateList()));
	connect(mAnimationSetWidget, SIGNAL(UpdateAnimation()), mNodeSetWidget, SLOT(UpdateList()));
	connect(mLightSetWidget, SIGNAL(UpdateLight()), mNodeSetWidget, SLOT(UpdateList()));
	connect(mSimBodySetWidget, SIGNAL(UpdateODEBody()), mNodeSetWidget, SLOT(UpdateList()));
	connect(mSimJointSetWidget, SIGNAL(UpdateODEJoint()), mNodeSetWidget, SLOT(UpdateList()));

	connect(mSimBodySetWidget, SIGNAL(UpdateODEBody()), mSimJointSetWidget, SLOT(UpdateList()));
	
	connect(mOgreWidget, SIGNAL(mouseMoveSignal(QMouseEvent*, int, int)), mCameraSetWidget, SLOT(mouseMoveSlot(QMouseEvent*, int, int)));
	connect(mOgreWidget, SIGNAL(mousePressSignal(QMouseEvent*)), mCameraSetWidget, SLOT(mousePressSlot(QMouseEvent*)));
	connect(mOgreWidget, SIGNAL(mouseReleaseSignal(QMouseEvent*)), mCameraSetWidget, SLOT(mouseReleaseSlot(QMouseEvent*)));

	connect(mOgreWidget, SIGNAL(mouseMoveSignal(QMouseEvent*, int, int)), mBodySetWidget, SLOT(mouseMoveSlot(QMouseEvent*, int, int)));
	connect(mOgreWidget, SIGNAL(mousePressSignal(QMouseEvent*)), mBodySetWidget, SLOT(mousePressSlot(QMouseEvent*)));
	connect(mOgreWidget, SIGNAL(mouseReleaseSignal(QMouseEvent*)), mBodySetWidget, SLOT(mouseReleaseSlot(QMouseEvent*)));


		
	QVBoxLayout *alayout = new QVBoxLayout;
	alayout->addWidget(tabWidget);
	QWidget *awidget = new QWidget;
	awidget->setLayout(alayout);

	tabWidget->setMinimumSize(250, 768);
	tabWidget->setMaximumWidth(250);

	QScrollArea *area = new QScrollArea();
	area->setWidget(awidget);
	area->setMaximumSize(300, 708);
	area->setMinimumSize(300, 708);
	
	layout->addWidget(area);
	

	

	
	QWidget *widget = new QWidget;
	
    widget->setLayout(layout);
	widget->setMinimumSize(1244, 708);

	setCentralWidget(widget);

	
	

	

	setWindowTitle(tr("OgreRTC"));
    setUnifiedTitleAndToolBarOnMac(true);

	mOgreWidget->initOgre();

	EC = mOgreWidget->mOgreRTCApplication;
	mBodySetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mBornSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mCameraSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mGUISetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mGUITextSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mImageSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mParticleSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mSubWindowSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mAnimationSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mLightSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mNodeSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mSimulationSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mSimBodySetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mSimJointSetWidget->EC = mOgreWidget->mOgreRTCApplication;
	mOtherSetWidget->EC = mOgreWidget->mOgreRTCApplication;


	

	createAction();
	createMenus();

	if(EC && argc > 1)
	{
		EC->reset();
		EC->OpenFile(argv[1]);
	}

}


/**
*@brief アクション作成の関数
*/
void MainWindow::createAction()
{
	newAct = new QAction(tr("&New..."),this);
	newAct->setShortcuts(QKeySequence::New);
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));


	openAct = new QAction(tr("&Open..."),this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

	pyAct = new QAction(tr("&Open Python..."),this);
    connect(pyAct, SIGNAL(triggered()), this, SLOT(pyOpen()));


    saveAct = new QAction(tr("&Save"),this);
    saveAct->setShortcuts(QKeySequence::Save);
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

	addFileSystemAct = new QAction(tr("&Add FileSystem"),this);
    connect(addFileSystemAct, SIGNAL(triggered()), this, SLOT(addFileSystem()));
}

/**
*@brief メニュー作成の関数
*/
void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newAct);
	fileMenu->addAction(pyAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
	fileMenu->addAction(addFileSystemAct);
	

}


void MainWindow::open()
{
	QString fileName = QFileDialog::getOpenFileName(this,
							tc->toUnicode("開く"), "",
							tr("Text File (*.txt);;All Files (*)"));
	if (fileName.isEmpty())
        return;

	


	
	

	std::string ba = (const char*)fileName.toLocal8Bit();
	
	if(EC)
	{
		EC->StopFile();
		EC->openb(ba);

		

		
		

		emit UpdateList();

	}


	

}

/**
*@brief RTC読み込み時のスロット
*/
void MainWindow::pyOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this,
							tc->toUnicode("スクリプトを開く"), "",
							tr("Python File (*.py);;All Files (*)"));

	if (fileName.isEmpty())
        return;

	
	

	std::string ba = (const char*)fileName.toLocal8Bit();

	std::string tmp = ba;
	
	coil::replaceString(tmp, "\\","/");

	if(EC)
	{
		EC->reset();
		

		

		EC->OpenFile(tmp.c_str());


	}

	


	

}

/**
*@brief ファイル保存時のスロット
* @return trueは成功、falseは失敗
*/
bool MainWindow::save()
{
	QString fileName = QFileDialog::getSaveFileName(this,
							tc->toUnicode("保存"), "",
							tr("Text File (*.txt);;All Files (*)"));
	if (fileName.isEmpty())
        return false;

	std::string ba = (const char*)fileName.toLocal8Bit();

	
	
	if(EC)
	{
		EC->save(ba);

		
		

		
		

		


	}

    return true;
}

/**
*@brief 初期化時のスロット
*/
void MainWindow::newFile()
{
	if(EC)
	{
		EC->newfile();

		

		


		emit UpdateList();
	}
}

/**
*@brief ファイルシステム追加のスロット
*/
void MainWindow::addFileSystem()
{
	QString fileName = QFileDialog::getExistingDirectory(this,
							tc->toUnicode("ファイルシステムの追加"));
	if (fileName.isEmpty())
        return;

	fileName = QFileInfo(fileName).canonicalFilePath();

	//std::cout << fileName.toStdString() << std::endl;

	std::string ba = (const char*)fileName.toLocal8Bit();

	if(EC)
	{
		EC->AddFileSystem(ba.c_str());
	}
}