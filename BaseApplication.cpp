/*
-----------------------------------------------------------------------------
Filename:    BaseApplication.cpp
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
#include "BaseApplication.h"

//-------------------------------------------------------------------------------------
BaseApplication::BaseApplication(void)
    : mRoot(0),
    mSceneMgr(0),
    mWindow(0),
    mResourcesCfg(Ogre::StringUtil::BLANK),
    mPluginsCfg(Ogre::StringUtil::BLANK),
    mShutDown(false)
    
{
#ifdef _DEBUG
    mResourcesCfg = "resources_d.cfg";
    mPluginsCfg = "plugins_d.cfg";
#else
    mResourcesCfg = "resources.cfg";
    mPluginsCfg = "plugins.cfg";
#endif
	if (!setup())
        return;

	//mRoot->startRendering();


}

//-------------------------------------------------------------------------------------
BaseApplication::~BaseApplication(void)
{
    
    
    windowClosed(mWindow);
    delete mRoot;
}

WId BaseApplication::initRenderWindow(Ogre::String hwnd, int width, int heigth)
{
	if(!mWindow) {
		Ogre::NameValuePairList parms;
		parms["externalWindowHandle"] = hwnd;
		
		
		mRoot->initialise(false);
		mWindow = mRoot->createRenderWindow("Editor", width, heigth, false, &parms);
		//mWindow = mRoot->initialise(true, "TutorialApplication Render Window");
		
		mWindow->setActive(true);

		WId ogreWinId = 0x0;
		mWindow->getCustomAttribute("WINDOW", &ogreWinId);

		mWindow->update();

		

		
		

		chooseSceneManager();

		


		createCamera();

		

		createViewports();

		

		// Set default mipmap level (NB some APIs ignore this)
		Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

		

		// Create any resource listeners (for loading screens)
	    
		// Load resources
		loadResources();

		
		

		// Create the scene
		createScene();

		

		mRayQuery = mSceneMgr->createRayQuery(Ogre::Ray());

		


		

		mWindow->setActive(true);
		mWindow->setVisible(true);
		mWindow->update();

		return ogreWinId;

		//mRoot->startRendering();

	}
	return 0;
}

//-------------------------------------------------------------------------------------
bool BaseApplication::configure(void)
{
    // Show the configuration dialog and initialise the system
    // You can skip this and use root.restoreConfig() to load configuration
    // settings if you were sure there are valid ones saved in ogre.cfg
    if(mRoot->restoreConfig() || mRoot->showConfigDialog())
    {
        // If returned true, user clicked OK so initialise
        // Here we choose to let the system create a default rendering window by passing 'true'
        //mWindow = mRoot->initialise(true, "TutorialApplication Render Window");
		

        return true;
    }
    else
    {
        return false;
    }
}
//-------------------------------------------------------------------------------------
void BaseApplication::chooseSceneManager(void)
{
    // Get the SceneManager, in this case a generic one
    mSceneMgr = mRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE);
}
//-------------------------------------------------------------------------------------
void BaseApplication::createCamera(void)
{
    // Create the camera
    mCamera = mSceneMgr->createCamera("PlayerCam");

    // Position it at 500 in Z direction
    //mCamera->setPosition(Ogre::Vector3(0,0,80));
    // Look back along -Z
    //mCamera->lookAt(Ogre::Vector3(0,0,-300));
    //mCamera->setNearClipDistance(5);

    
}

//-------------------------------------------------------------------------------------
void BaseApplication::destroyScene(void)
{
}
//-------------------------------------------------------------------------------------
void BaseApplication::createViewports(void)
{
    // Create one viewport, entire window
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(
        Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}
//-------------------------------------------------------------------------------------
void BaseApplication::setupResources(void)
{
    // Load resource paths from config file
    Ogre::ConfigFile cf;
    cf.load(mResourcesCfg);

    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);

        }
    }
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
void BaseApplication::loadResources(void)
{
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
bool BaseApplication::setup(void)
{
    mRoot = new Ogre::Root(mPluginsCfg);

    setupResources();

    bool carryOn = configure();
    if (!carryOn) return false;

	//mRoot->initialise(false);

    

    return true;
};

//-------------------------------------------------------------------------------------
bool BaseApplication::keyPressed( QKeyEvent *arg )
{
    

    if(arg->key() == Qt::Key_F5)   // refresh all textures
    {
        Ogre::TextureManager::getSingleton().reloadAll();
    }
	else if (arg->key() == Qt::Key_Escape)
    {
        mShutDown = true;
    }

    //mCameraMan->injectKeyDown(arg);
    return true;
}

bool BaseApplication::keyReleased( QKeyEvent *arg )
{
    //mCameraMan->injectKeyUp(arg);
    return true;
}

bool BaseApplication::mouseMoved( QMouseEvent*  evt )
{
    //if (mTrayMgr->injectMouseMove(arg)) return true;
    //mCameraMan->injectMouseMove(arg);
    return true;
}

bool BaseApplication::mousePressed(  QMouseEvent*  evt )
{
    //if (mTrayMgr->injectMouseDown(arg, id)) return true;
    //mCameraMan->injectMouseDown(arg, id);
    return true;
}

bool BaseApplication::mouseReleased(  QMouseEvent*  evt )
{
    //if (mTrayMgr->injectMouseUp(arg, id)) return true;
    //mCameraMan->injectMouseUp(arg, id);
    return true;
}

//Adjust mouse clipping area
void BaseApplication::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);
}

void BaseApplication::resize(int width, int height)
{
	mWindow->resize(width, height);
	mWindow->windowMovedOrResized();
}

//Unattach OIS before window shutdown (very important under Linux)
void BaseApplication::windowClosed(Ogre::RenderWindow* rw)
{
    //Only close for window that created OIS (the main window in these demos)
    if( rw == mWindow )
    {
        
    }
}
