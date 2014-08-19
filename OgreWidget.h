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
*Ogre3Dのレンダリングの表示のウィジェット
*/
class OgreWidget : public QWidget
{
	Q_OBJECT

public:
	OgreWidget(QWidget *parent = 0);
	~OgreWidget(void);

	/*
	*レンダリング初期化
	*/
	void initOgre();

	OgreRTCApplication *mOgreRTCApplication;

signals:
	/*
	*マウス移動時のシグナル
	*/
	void  mouseMoveSignal(QMouseEvent*  evt, int dx, int dy);
	/*
	*マウスのボタンを押した時のシグナル
	*/
	void  mousePressSignal(QMouseEvent*  evt);
	/*
	*マウスのボタンを離した時のシグナル
	*/
	void  mouseReleaseSignal(QMouseEvent*  evt);


private:
	/*
	*周期的に呼び出される関数
	*/
	void timerEvent (QTimerEvent *event);
	/*
	*描画時に呼び出される関数
	*/
	void paintEvent (QPaintEvent *event);
	
	QPaintEngine *paintEngine() const { return 0;}

	
	

	//QTextCodec* tc;

	



protected:
	/*
	*マウスが動いたときに呼び出される関数
	*/
	void  mouseMoveEvent(QMouseEvent*  evt);
	/*
	*マウスのボタンを押したときに呼び出される関数
	*/
	void  mousePressEvent(QMouseEvent*  evt);
	/*
	*マウスのボタンを離したときに呼び出される関数
	*/
	void  mouseReleaseEvent(QMouseEvent*  evt);
	/*
	*キーを押した時に呼び出される関数
	*/
	void  keyPressEvent(QKeyEvent*  event);
	/*
	*キーを離した時に呼び出される関数
	*/
	void  keyReleaseEvent(QKeyEvent*  event);
	/*
	*
	*/
	void inputMethodEvent(QInputMethodEvent *event);




};

#endif