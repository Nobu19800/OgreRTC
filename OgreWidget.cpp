#include "mainwindow.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QPainter>
#include <QtWidgets>
#ifdef Q_OS_WIN
#else
#include <QX11Info>
#endif

OgreWidget::OgreWidget(QWidget *parent) :
#ifdef Q_OS_WIN
QWidget(parent,Qt::WindowFlags(Qt::MSWindowsOwnDC))
#else
QWidget(parent)
#endif
{
	QTextCodec* tc = QTextCodec::codecForLocale();
	

	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_NoBackground);
	setAttribute(Qt::WA_InputMethodEnabled);

	setMouseTracking(true);

	setFocusPolicy(Qt::WheelFocus);

	//setAcceptDrops(true);
	setContextMenuPolicy( Qt::PreventContextMenu );

	setMaximumSize(944, 708);
	setMinimumSize(944, 708);

	//setSizeIncrement(1024, 768);

	//update();


}

//----------------------------------------------------------------------------------------

OgreWidget::~OgreWidget(void)
{

}


void OgreWidget::initOgre()
{
	
	{
		Ogre::String winHandle;
#ifdef Q_OS_WIN
		winHandle = Ogre::StringConverter::toString((long)((HWND)winId()));
#else
		QX11Info info = this->x11Info();
		winHandle  = Ogre::StringConverter::toString((unsigned long)(info.display()));
		winHandle += ":";
		winHandle += Ogre::StringConverter::toString((unsigned int)(info.screen()));
		winHandle += ":";
		winHandle += Ogre::StringConverter::toString((unsigned long)(window()->winId()));
#endif
		mOgreRTCApplication = OgreRTCApplication::getSingletonPtr();
		WId ogreWinId = mOgreRTCApplication->initRenderWindow(winHandle, 944, 708);

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

void OgreWidget::paintEvent (QPaintEvent *event)
{
	if (mOgreRTCApplication)
	{
		//if(this->isActiveWindow())
			mOgreRTCApplication->update(100);
	}
	
}


void OgreWidget::timerEvent (QTimerEvent *event)
{
	//mOgreApp->update();
	//mOgreRTCApplication->update(100);
	update();
}

//----------------------------------------------------------------------------------------

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


void  OgreWidget::mousePressEvent(QMouseEvent*  evt)
{
	if (mOgreRTCApplication)
	{
		mOgreRTCApplication->mousePressed(evt);
		emit mousePressSignal(evt);
		//QWidget::mousePressEvent(evt);
	}

	
}


void  OgreWidget::mouseReleaseEvent(QMouseEvent*  evt)
{
	if (mOgreRTCApplication)
	{
		mOgreRTCApplication->mouseReleased(evt);
		emit mouseReleaseSignal(evt);
		//QWidget::mouseReleaseEvent(evt);
	}

	
}

void  OgreWidget::keyPressEvent(QKeyEvent*  e)
{
	if (mOgreRTCApplication)
	{
		//std::cout << "key = " << e->key() << std::endl;
		
		mOgreRTCApplication->keyPressed(e);
		
		//QWidget::keyPressEvent(e);
	}
}

void  OgreWidget::keyReleaseEvent(QKeyEvent* e)
{
	if (mOgreRTCApplication)
	{
		//std::cout << "key = " << e->key() << std::endl;

		mOgreRTCApplication->keyReleased(e);

		//QWidget::keyReleaseEvent(e);
	}
}

void OgreWidget::inputMethodEvent(QInputMethodEvent *e)
{
	if (mOgreRTCApplication)
	{
		//std::cout << e->commitString().toStdString() << std::endl;
		mOgreRTCApplication->inputMethodEvent(e);

		//QWidget::inputMethodEvent(e);
	}
}