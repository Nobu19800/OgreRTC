// -*- C++ -*-
/*!
 * @file Test1Comp.cpp
 * @brief Standalone component
 * @date $Date$
 *
 * $Id$
 */


#include <iostream>
#include <string>
#include <stdlib.h>

#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixMap>




int main (int argc, char** argv)
{
  

  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.show();
  app.exec();


  // If you want to run the manager in non-blocking mode, do like this
  // manager->runManager(true);

  return 0;
}
