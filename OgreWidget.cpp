/*!
 * @file  OgreWidget.cpp
 * @brief Ogre3Dのレンダリング表示ウィンドウ
 *
 */

#include "mainwindow.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#ifdef Q_OS_WIN
#else
#include <QX11Info>
#endif


/**
*@brief Ogre3Dのレンダリングの表示のウィジェットのコンストラクタ
* @param parent 親ウィジェット
*/
OgreWidget::OgreWidget(QWidget *parent) :
#ifdef Q_OS_WIN
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
#else
QWidget(parent)
#endif
{
	QTextCodec* tc = QTextCodec::codecForLocale();
	

	setAttribute(Qt::WA_PaintOnScreen);
	setAutoFillBackground(true);
	setAttribute(Qt::WA_NoBackground);
	setAttribute(Qt::WA_InputMethodEnabled);

	setMouseTracking(true);

	setFocusPolicy(Qt::WheelFocus);

	//setAcceptDrops(true);
	setContextMenuPolicy( Qt::PreventContextMenu );

	setMaximumSize(windowSizeX, windowSizeY);
	setMinimumSize(windowSizeX, windowSizeY);

	//setSizeIncrement(1024, 768);

	//update();


}


/**
*@brief Ogre3Dのレンダリングの表示のウィジェットのデストラクタ
*/
OgreWidget::~OgreWidget(void)
{

}


/**
*@brief レンダリング初期化
*/
void OgreWidget::initOgre()
{
	
	{
		Ogre::String winHandle;
#ifdef Q_OS_WIN

		winHandle = Ogre::StringConverter::toString((size_t)((HWND)winId()));
		

		//winHandle += Ogre::StringConverter::toString((unsigned long)(winId()));
#else
		QX11Info info = this->x11Info();
		winHandle  = Ogre::StringConverter::toString((unsigned long)(info.display()));
		winHandle += ":";
		winHandle += Ogre::StringConverter::toString((unsigned int)(info.screen()));
		winHandle += ":";
		winHandle += Ogre::StringConverter::toString((unsigned long)(window()->winId()));
#endif
		mOgreRTCApplication = OgreRTCApplication::getSingletonPtr();
		WId ogreWinId = mOgreRTCApplication->initRenderWindow(winHandle, windowSizeX, windowSizeY);

#ifdef Q_OS_WIN
#else
		QRect geo = this->frameGeometry();
		create(ogreWinId);
		setGeometry(geo);
#endif

		//mOgreApp->start();
		mOgreRTCApplication->update(100);
	}

	
	

	startTimer(1);
}

/**
*@brief 描画時に呼び出される関数
* @param evt ペイントイベント
*/
void OgreWidget::paintEvent (QPaintEvent *evt)
{
	if (mOgreRTCApplication)
	{
		//if(this->isActiveWindow())
			mOgreRTCApplication->update(100);
	}
	
}


/**
*@brief 周期的に呼び出される関数
* @param evt タイマーイベント
*/
void OgreWidget::timerEvent (QTimerEvent *evt)
{
	//mOgreApp->update();
	//mOgreRTCApplication->update(100);
	update();
}


/**
*@brief マウスが動いたときに呼び出される関数
* @param evt マウスイベント
*/
void  OgreWidget::mouseMoveEvent(QMouseEvent*  evt)
{
	if (mOgreRTCApplication)
	{
		//std::cout << "key = " << std::endl;
		//std::cout << evt->button() << std::endl;
		mOgreRTCApplication->mouseMoved(evt);
		

		static int last_x = evt->pos().x();
		static int last_y = evt->pos().y();
		
		int dx = evt->pos().x() - last_x;
		int dy = evt->pos().y() - last_y;

		emit mouseMoveSignal(evt, dx, dy);

		last_x = evt->pos().x();
		last_y = evt->pos().y();

		//QWidget::mouseMoveEvent(evt);
	}

}

/**
*@brief マウスのボタンを押したときに呼び出される関数
* @param evt マウスイベント
*/
void  OgreWidget::mousePressEvent(QMouseEvent*  evt)
{
	if (mOgreRTCApplication)
	{
		mOgreRTCApplication->mousePressed(evt);
		emit mousePressSignal(evt);
		//QWidget::mousePressEvent(evt);
	}

	
}

/**
*@brief マウスのボタンを離したときに呼び出される関数
* @param evt マウスイベント
*/
void  OgreWidget::mouseReleaseEvent(QMouseEvent*  evt)
{
	if (mOgreRTCApplication)
	{
		mOgreRTCApplication->mouseReleased(evt);
		emit mouseReleaseSignal(evt);
		//QWidget::mouseReleaseEvent(evt);
	}

	
}

/**
*@brief キーを押した時に呼び出される関数
* @param evt キーイベント
*/
void  OgreWidget::keyPressEvent(QKeyEvent*  evt)
{
	if (mOgreRTCApplication)
	{
		//std::cout << "key = " << e->key() << std::endl;
		
		mOgreRTCApplication->keyPressed(evt);
		
		//QWidget::keyPressEvent(e);
	}
}


/**
*@brief キーを離した時に呼び出される関数
* @param evt キーイベント
*/
void  OgreWidget::keyReleaseEvent(QKeyEvent* evt)
{
	if (mOgreRTCApplication)
	{
		//std::cout << "key = " << e->key() << std::endl;

		mOgreRTCApplication->keyReleased(evt);

		//QWidget::keyReleaseEvent(e);
	}
}

/**
*@brief テキストを入力した場合等に呼び出される関数
* @param evt インプットメソッドイベント
*/
void OgreWidget::inputMethodEvent(QInputMethodEvent *evt)
{
	if (mOgreRTCApplication)
	{
		//std::cout << e->commitString().toStdString() << std::endl;
		mOgreRTCApplication->inputMethodEvent(evt);

		//QWidget::inputMethodEvent(e);
	}
}