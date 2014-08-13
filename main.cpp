#include <iostream>
#include <string>
#include <stdlib.h>
#include "mainwindow.h"

#include <QApplication>
#include <QtOpenGL>
#include <QSplashScreen>
#include <QPixMap>

int main (int argc, char** argv)
{



	Q_INIT_RESOURCE(TestOgre15);

	

	

    QApplication app(argc, argv);


	//QSplashScreen splash(QPixmap(":/images/eka2.png"));
	//splash.show();

	
	
    
	MainWindow mainWindow;



	//Sleep(2000);


    mainWindow.show();


	//splash.finish(&mainWindow);




    return app.exec();

}
