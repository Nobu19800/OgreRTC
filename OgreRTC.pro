TEMPLATE = vcapp
TARGET = OgreRTC

CONFIG += assistant

QT += network
QT += testlib

HEADERS	    =   mainwindow.h \
		OgreWidget.h \
		BaseApplication.h \
		OgreRTCApplication.h \
		MyArray.h \
		MyLink.h \
		SingletonT.h \
		UnicodeF.h \
		MyQtMacro.h \
		BodySet.h \
		CameraSet.h \
		GUISet.h \
		ParticleSet.h \
		SubWindowSet.h \
		GUITextSet.h \
		BornSet.h \
		OtherSet.h \
		ImageSet.h \
		MyParticle.h \
		MyGUI.h \
		SubWindow.h \
		MyImageSet.h \
		MyFileStream.h \
		AnimationSet.h \
		LightSet.h \
		MyAnimation.h \
		MyLight.h \
		MySimulation.h \
		SimulationSet.h \
		SimJointSet.h \
		SimBodySet.h \
		MyNode.h \
		NodeSet.h \
		MyODEBody.h \
		MyODEJoint.h \
		MyOgreMacro.h \
		MyPythonBoost.h
SOURCES	    =   mainwindow.cpp \
		OgreWidget.cpp \
		BaseApplication.cpp \
		OgreRTCApplication.cpp \
		MyArray.cpp \
		MyLink.cpp \
		UnicodeF.cpp \
		MyQtMacro.cpp \
		BodySet.cpp \
		CameraSet.cpp \
		GUISet.cpp \
		ParticleSet.cpp \
		SubWindowSet.cpp \
		GUITextSet.cpp \
		BornSet.cpp \
		OtherSet.cpp \
		ImageSet.cpp \
		MyParticle.cpp \
		MyGUI.cpp \
		SubWindow.cpp \
		MyImageSet.cpp \
		MyFileStream.cpp \
		AnimationSet.cpp \
		LightSet.cpp \
		MyAnimation.cpp \
		MyLight.cpp \
		MySimulation.cpp \
		SimulationSet.cpp \
		SimJointSet.cpp \
		SimBodySet.cpp \
		MyNode.cpp \
		NodeSet.cpp \
		MyODEBody.cpp \
		MyODEJoint.cpp \
		MyOgreMacro.cpp \
		MyPythonBoost.cpp \
		RTCmain.cpp



# install
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS diagramscene.pro images
INSTALLS += target sources


