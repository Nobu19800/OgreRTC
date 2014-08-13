#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QDialog>
#include <windows.h>
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
*���C���E�C���h�E�̃N���X
*/

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
	

protected:

signals:
	/*
	*�t�@�C���ǂݍ��ݎ��̃V�O�i��
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
	*RTC�ǂݍ��ݎ��̃X���b�g
	*/
	void pyOpen();
	/*
	*�t�@�C���ۑ����̃X���b�g
	*/
	bool save();
	/*
	*�t�@�C���ǂݍ��ݎ��̃X���b�g
	*/
	void open();
	/*
	*���������̃X���b�g
	*/
	void newFile();
	/*
	*�t�@�C���V�X�e���ǉ��̃X���b�g
	*/
	void addFileSystem();

private:
	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *pyAct;
	QAction *addFileSystemAct;
	/*
	*���j���[�쐬�̊֐�
	*/
	void createMenus();
	/*
	*�A�N�V�����쐬�̊֐�
	*/
	void createAction();
	QMenu *fileMenu;

	OgreRTCApplication *EC;

   
	
	
};
//! [0]








#endif