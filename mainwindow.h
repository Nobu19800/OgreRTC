#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QModelIndex>
#include <QDialog>
#ifdef Q_OS_WIN
#include <windows.h>
#else
#endif

#include <vector>
#include <iostream>

#include "OgreWidget.h"
#include "BodySet.h"
#include "BornSet.h"
#include "CameraSet.h"
#include "GUISet.h"
#include "GUITextSet.h"
#include "OtherSet.h"
#include "ParticleSet.h"
#include "SubWindowSet.h"
#include "ImageSet.h"
#include "MyFileStream.h"
#include "AnimationSet.h"
#include "LightSet.h"
#include "SimBodySet.h"
#include "SimJointSet.h"
#include "SimulationSet.h"
#include "NodeSet.h"



using namespace std;






class TreeModelCompleter;

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
class QTextEdit;
class QLineEdit;
class QTreeView;
class QLabel;
class QStandardItemModel;
class QCheckBox;
class QGridLayout;
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpinBox;
class QVBoxLayout;
class Compiler;
class QTextCursor;
class QTreeWidget;
QT_END_NAMESPACE

/*
*メインウインドウのクラス
*/

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget *parent = 0);
	

protected:

signals:
	/*
	*ファイル読み込み時のシグナル
	*/
	void UpdateList();
	
private slots:
    

private:
	QTextCodec* tc;
	OgreWidget *mOgreWidget;
	QTabWidget *tabWidget;
	BodySetWidget * mBodySetWidget;
	BornSetWidget * mBornSetWidget;
	CameraSetWidget * mCameraSetWidget;
	GUISetWidget * mGUISetWidget;
	GUITextSetWidget * mGUITextSetWidget;
	OtherSetWidget * mOtherSetWidget;
	ParticleSetWidget * mParticleSetWidget;
	SubWindowSetWidget * mSubWindowSetWidget;
	ImageSetWidget * mImageSetWidget;
	AnimationSetWidget * mAnimationSetWidget;
	LightSetWidget * mLightSetWidget;
	SimBodySetWidget * mSimBodySetWidget;
	SimJointSetWidget * mSimJointSetWidget;
	SimulationSetWidget * mSimulationSetWidget;
	NodeSetWidget * mNodeSetWidget;

private slots:
	/*
	*RTC読み込み時のスロット
	*/
	void pyOpen();
	/*
	*ファイル保存時のスロット
	*/
	bool save();
	/*
	*ファイル読み込み時のスロット
	*/
	void open();
	/*
	*初期化時のスロット
	*/
	void newFile();
	/*
	*ファイルシステム追加のスロット
	*/
	void addFileSystem();

private:
	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *pyAct;
	QAction *addFileSystemAct;
	/*
	*メニュー作成の関数
	*/
	void createMenus();
	/*
	*アクション作成の関数
	*/
	void createAction();
	QMenu *fileMenu;

	OgreRTCApplication *EC;

   
	
	
};
//! [0]








#endif