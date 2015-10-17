cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


set(thirdparty thirdparty)


set(ODE_PATH C:/OgreCEGUILIB/ode-0.12)
set(CEGUI_PATH C:/OgreCEGUILIB/cegui-0.8.4)
set(srcs AnimationSet.cpp ${thirdparty}/BaseApplication.cpp BodySet.cpp BornSet.cpp CameraSet.cpp DisplayImage.cpp ${thirdparty}/CEGUIFunc.cpp GUISet.cpp GUITextSet.cpp ImageSet.cpp LightSet.cpp mainwindow.cpp AnimationObj.cpp FileStreamFunc.cpp GUIObj.cpp ImageSetObj.cpp LightObj.cpp LinkObj.cpp NodeObj.cpp ODEBodyObj.cpp ODEJointObj.cpp OgreMacro.cpp ParticleObj.cpp PythonBoostObj.cpp QtMacro.cpp SimulationObj.cpp NodeSet.cpp OgreRTCApplication.cpp OgreWidget.cpp OtherSet.cpp ParticleSet.cpp RTCmain.cpp SimBodySet.cpp SimJointSet.cpp SimulationSet.cpp SubWindow.cpp SubWindowSet.cpp ${thirdparty}/UnicodeF.cpp )



project(OgreRTC)

set(CMAKE_AUTOMOC ON)


set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/OgreCEGUILIB/OgreSDK_vc10_v1-9-0/CMake" )


include_directories(${thirdparty})


find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

find_package(OGRE REQUIRED)
include_directories(${OGRE_INCLUDE_DIRS})




find_package(Qt5Widgets REQUIRED)


find_package(OpenRTM REQUIRED)
include_directories(${OPENRTM_INCLUDE_DIRS})
add_definitions(${OPENRTM_CFLAGS})
link_directories(${OPENRTM_LIBRARY_DIRS})


find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})


if (DEFINED OPENRTM_INCLUDE_DIRS)
  string(REGEX REPLACE "-I" ";"
    OPENRTM_INCLUDE_DIRS "${OPENRTM_INCLUDE_DIRS}")
  string(REGEX REPLACE " ;" ";"
    OPENRTM_INCLUDE_DIRS "${OPENRTM_INCLUDE_DIRS}")
endif (DEFINED OPENRTM_INCLUDE_DIRS)

if (DEFINED OPENRTM_LIBRARY_DIRS)
  string(REGEX REPLACE "-L" ";"
    OPENRTM_LIBRARY_DIRS "${OPENRTM_LIBRARY_DIRS}")
  string(REGEX REPLACE " ;" ";"
    OPENRTM_LIBRARY_DIRS "${OPENRTM_LIBRARY_DIRS}")
endif (DEFINED OPENRTM_LIBRARY_DIRS)

if (DEFINED OPENRTM_LIBRARIES)
  string(REGEX REPLACE "-l" ";"
    OPENRTM_LIBRARIES "${OPENRTM_LIBRARIES}")
  string(REGEX REPLACE " ;" ";"
    OPENRTM_LIBRARIES "${OPENRTM_LIBRARIES}")
endif (DEFINED OPENRTM_LIBRARIES)






include_directories(${ODE_PATH}/include)
include_directories(${CEGUI_PATH}/dependencies/include)
include_directories(${CEGUI_PATH}/cegui/include)


add_definitions(-DNOMINMAX)
add_definitions(-DdIDEDOUBLE)





link_directories(${ODE_PATH}/lib/Release)
link_directories(${CEGUI_PATH}/lib)
link_directories(${CEGUI_PATH}/dependencies/lib/static)



qt5_wrap_cpp(moc_AnimationSet.cpp AnimationSet.h)
qt5_wrap_cpp(moc_BodySet.cpp BodySet.h)
qt5_wrap_cpp(moc_BornSet.cpp BornSet.h)
qt5_wrap_cpp(moc_CameraSet.cpp CameraSet.h)
qt5_wrap_cpp(moc_GUISet.cpp GUISet.h)
qt5_wrap_cpp(moc_GUITextSet.cpp GUITextSet.h)
qt5_wrap_cpp(moc_ImageSet.cpp ImageSet.h)
qt5_wrap_cpp(moc_LightSet.cpp LightSet.h)
qt5_wrap_cpp(moc_mainwindow.cpp mainwindow.h)
qt5_wrap_cpp(moc_NodeSet.cpp NodeSet.h)
qt5_wrap_cpp(moc_OgreWidget.cpp OgreWidget.h)
qt5_wrap_cpp(moc_OtherSet.cpp OtherSet.h)
qt5_wrap_cpp(moc_ParticleSet.cpp ParticleSet.h)
qt5_wrap_cpp(moc_SimBodySet.cpp SimBodySet.h)
qt5_wrap_cpp(moc_SimJointSet.cpp SimJointSet.h)
qt5_wrap_cpp(moc_SimulationSet.cpp SimulationSet.h)
qt5_wrap_cpp(moc_SubWindowSet.cpp SubWindowSet.h)

qt5_add_resources(QRC OgreRTC.qrc)

add_executable(OgreRTC ${srcs} ${QRC})



QT5_USE_MODULES(OgreRTC Widgets)

target_link_libraries(OgreRTC ${OPENRTM_LIBRARIES} ${PYTHON_LIBRARIES} ${OGRE_LIBRARIES} ode CEGUIBase-0 CEGUIOgreRenderer-0 opengl32 glu32 )




