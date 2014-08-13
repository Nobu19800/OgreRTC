#ifndef OTHERSET_H
#define OTHERSET_H

#include <QtGui>
#include "OgreRTCApplication.h"


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
class QComboBox;
QT_END_NAMESPACE


/*
* �w�i�A�n�ʁAFPS�ݒ�p�E�B�W�F�b�g
*/

class OtherSetWidget : public QWidget
{
	Q_OBJECT

public:
	OtherSetWidget(QWidget *parent = 0);
	~OtherSetWidget(void);

	OgreRTCApplication *EC;

public slots:
	/*
	*�w�i�A�n�ʂ̐ݒ���E�B�W�F�b�g�ɔ��f������Ƃ��̃X���b�g
	*/
	void UpdateList();

private slots:
	/*
	*�w�i�ݒ�{�^�����������Ƃ��̃X���b�g
	*/
	void SkyBoxSetSlot();
	void DelSkyBoxSetSlot();
	void SkyBoxSizeSlot(int value);
	/*
	*�n�ʍ쐬�{�^�����������Ƃ��̃X���b�g
	*/
	void FloorSetSlot();
	/*
	*�n�ʍ폜�{�^�����������Ƃ��̃X���b�g
	*/
	void DelFloorSetSlot();
	void FloorSizeSlot(int value);
	void FloorDirSlot(int value);
	/*
	*FPS�X�s���{�b�N�X�̒l��ύX�����Ƃ��̃X���b�g
	*/
	void TimeSlot(int value);

private:
	
	QTextCodec* tc;
	QPushButton *SkyBoxButton;
	QPushButton *DelSkyBoxButton;
	QSpinBox *SkyBoxspinBox;
	QComboBox *SkyBoxEdit;

	QPushButton *FloorButton;
	QPushButton *DelFloorButton;
	QSpinBox *FloorSizespinBox;
	QComboBox *FloorDircombpBox;
	QComboBox *FloorEdit;
	QSpinBox *TimespinBox;

	

	



protected:
	




};

#endif