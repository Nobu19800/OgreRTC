// -*- C++ -*-
/*!
 * @file RTCmain.cpp
 * @brief メイン関数
 */


#include <iostream>
#include <string>
#include <stdlib.h>

#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>




/**
*@brief メイン関数
* @param argc コマンドライン引数の数
* @param argv コマンドライン引数
*/
int main (int argc, char** argv)
{
  Q_INIT_RESOURCE(OgreRTC);
  int _argc = 1;
  QApplication app(_argc, argv);


  QPixmap pxmSplash(":/images/splashscreen.png");
  QSplashScreen wndSplash(pxmSplash);
  wndSplash.setMask(pxmSplash.mask());
  wndSplash.show();

  
  
  app.processEvents();


  MainWindow mainWindow(argc, argv);
  mainWindow.show();

  wndSplash.finish(&mainWindow);

  app.exec();



  return 0;
}
