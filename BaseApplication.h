/*
-----------------------------------------------------------------------------
Filename:    BaseApplication.h
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/                              
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#ifndef __BaseApplication_h_
#define __BaseApplication_h_

#include <Ogre.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <QtGui>

#include "SingletonT.h"




class BaseApplication
{
	
public:
    BaseApplication(void);
    virtual ~BaseApplication(void);

    

	void initRenderWindow(Ogre::String hwnd, int width, int heigth);
	Ogre::RenderWindow* getRenderWindow() { return mWindow; }
	Ogre::SceneManager*  getSceneManager() { return mSceneMgr; }

protected:
    virtual bool setup();
    virtual bool configure(void);
    virtual void chooseSceneManager(void);
    virtual void createCamera(void);
    
    virtual void createScene(void) = 0; // Override me!
    virtual void destroyScene(void);
    virtual void createViewports(void);
    virtual void setupResources(void);
    
    virtual void loadResources(void);

    // Ogre::FrameListener
    
    virtual bool keyPressed(QKeyEvent *arg );
    virtual bool keyReleased(QKeyEvent *arg );
    virtual bool mouseMoved(QMouseEvent *arg );
    virtual bool mousePressed(QMouseEvent *arg);
    virtual bool mouseReleased(QMouseEvent *arg);

    // Ogre::WindowEventListener
    //Adjust mouse clipping area
    virtual void windowResized(Ogre::RenderWindow* rw);
    //Unattach OIS before window shutdown (very important under Linux)
    virtual void windowClosed(Ogre::RenderWindow* rw);

	void resize(int width, int height);

    Ogre::Root *mRoot;
    Ogre::Camera* mCamera;
    Ogre::SceneManager* mSceneMgr;
    Ogre::RenderWindow* mWindow;
    Ogre::String mResourcesCfg;
    Ogre::String mPluginsCfg;
	Ogre::RaySceneQuery   *mRayQuery;

    // OgreBites
    
    
    
    bool mShutDown;

    

	
};

#endif // #ifndef __BaseApplication_h_
