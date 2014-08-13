#ifndef OGREWIDGET_H
#define OGREWIDGET_H

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
QT_END_NAMESPACE

/*
*Ogre3D�̃����_�����O�̕\���̃E�B�W�F�b�g
*/
class OgreWidget : public QWidget
{
	Q_OBJECT

public:
	OgreWidget(QWidget *parent = 0);
	~OgreWidget(void);

	/*
	*�����_�����O������
	*/
	void initOgre();

	OgreRTCApplication *mOgreRTCApplication;

signals:
	/*
	*�}�E�X�ړ����̃V�O�i��
	*/
	void  mouseMoveSignal(QMouseEvent*  evt, int dx, int dy);
	/*
	*�}�E�X�̃{�^�������������̃V�O�i��
	*/
	void  mousePressSignal(QMouseEvent*  evt);
	/*
	*�}�E�X�̃{�^���𗣂������̃V�O�i��
	*/
	void  mouseReleaseSignal(QMouseEvent*  evt);


private:
	/*
	*�����I�ɌĂяo�����֐�
	*/
	void timerEvent (QTimerEvent *event);
	/*
	*�`�掞�ɌĂяo�����֐�
	*/
	void paintEvent (QPaintEvent *event);
	
	QPaintEngine *paintEngine() const { return 0;}

	
	

	//QTextCodec* tc;

	



protected:
	/*
	*�}�E�X���������Ƃ��ɌĂяo�����֐�
	*/
	void  mouseMoveEvent(QMouseEvent*  evt);
	/*
	*�}�E�X�̃{�^�����������Ƃ��ɌĂяo�����֐�
	*/
	void  mousePressEvent(QMouseEvent*  evt);
	/*
	*�}�E�X�̃{�^���𗣂����Ƃ��ɌĂяo�����֐�
	*/
	void  mouseReleaseEvent(QMouseEvent*  evt);
	/*
	*�L�[�����������ɌĂяo�����֐�
	*/
	void  keyPressEvent(QKeyEvent*  event);
	/*
	*�L�[�𗣂������ɌĂяo�����֐�
	*/
	void  keyReleaseEvent(QKeyEvent*  event);
	/*
	*
	*/
	void inputMethodEvent(QInputMethodEvent *event);




};

#endif