# -*- coding: cp932 -*-

import OpenRTM_aist
import RTC
import os.path
import sys
import imp
import time
import OgreRTS


EndFlag = True


    
##
#�}�l�[�W���𗧂��グ��֐�
##
def ManagerStart():
    OgreRTS.OgreObj = OgreObj
    OgreRTS.SimObj = SimulationObj
    
    
    
    OgreRTS.mgr = OpenRTM_aist.Manager.init(['test7.py'])
    
    OgreRTS.mgr.activateManager()
    OgreRTS.mgr.runManager(True)

##
#RTC�𗧂��グ��֐�
##
def RTCStart(fName): 
    
    OgreRTS.m_comp = RTCInit(fName)

    global EndFlag

    EndFlag = True

    OgreRTS.OgreObj.SetRTC()
    while(EndFlag):
        time.sleep(1)
    
    
    
    time.sleep(3)
    
##
#RTC���~����֐�
##
def RTCStop():
    
    global EndFlag
    
    
    #OgreRTS.mgr.unregisterComponent(OgreRTS.m_comp)
    OgreRTS.m_comp.exit()
    OgreRTS.mgr.unloadAll()
    
    
    OgreRTS.m_comp = None
    EndFlag = False
    

    
    
    #time.sleep(3)

##
#�t�@�C�����RTC��ǂݍ��ފ֐�
##

def RTCInit(fName):
    
    root, ext = os.path.splitext(fName)

    pathName = os.path.dirname(fName)
    fileName = os.path.basename(root)

    print pathName, fileName

    (file, pathname, description) = imp.find_module(fileName,[pathName])
    print file, pathname, description
    MyCallBack = imp.load_module(fileName, file, pathname, description)
    

    if OgreRTS.mgr:
        return MyCallBack.MyModuleInit(OgreRTS.mgr)


##
#�L�[���������Ƃ��ɌĂяo�����R�[���o�b�N�֐�
##
def keyPressed(k):
    
    if OgreRTS.m_comp:
        OgreRTS.m_comp.keyPressed(k)
##
#�L�[�𗣂����Ƃ��ɌĂяo�����R�[���o�b�N�֐�
##
def keyReleased(k):
    
    if OgreRTS.m_comp:
        OgreRTS.m_comp.keyReleased(k)

##
#�}�E�X�𓮂������Ƃ��ɌĂяo�����R�[���o�b�N�֐�
##
def mouseMoved(mx, my, mdx, mdy):
    
    if OgreRTS.m_comp:
        OgreRTS.m_comp.mouseMoved(mx, my, mdx, mdy)


##
#�}�E�X�̃{�^�����������Ƃ��ɌĂяo�����R�[���o�b�N�֐�
##
def mousePressed(b):
    
    if OgreRTS.m_comp:
        OgreRTS.m_comp.mousePressed(b)


##
#�}�E�X�̃{�^���𗣂����Ƃ��ɌĂяo�����R�[���o�b�N�֐�
##
def mouseReleased(b):
    
    if OgreRTS.m_comp:
        OgreRTS.m_comp.mouseReleased(b)


##
#�t�@�C���ǂݍ��ݎ��ɌĂяo�����R�[���o�b�N�֐�
##
def ogre_init():
    if OgreRTS.m_comp:
        OgreRTS.m_comp.ogre_init()
            
##
#�`��X�V���ɌĂяo�����R�[���o�b�N�֐�
##
def ogre_loop():
    
    if OgreRTS.m_comp:
        OgreRTS.m_comp.ogre_loop()


##
#�V�~�����[�V�����X�V���ɌĂяo�����R�[���o�b�N�֐�
##
def Simloop():
    
    if OgreRTS.m_comp:
        OgreRTS.m_comp.Simloop()


##
#�V�~�����[�V�����ŐڐG�������������ɌĂяo�����R�[���o�b�N�֐�
##
def Contacthandler(b1, b2):
    
    if OgreRTS.m_comp:
        OgreRTS.m_comp.Contacthandler(b1, b2)

def CEGUICallback(fname):
    if OgreRTS.m_comp:
        OgreRTS.m_comp.CEGUICallback(fname)
        try:
            method = getattr(OgreRTS.m_comp, fname)
        except AttributeError:
            return
        method()


    
