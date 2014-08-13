import re
import time
import RTC
import OpenRTM_aist
import OgreRTS








consolein_spec = ["implementation_id", "testOgre",
                  "type_name",         "testOgre",
                  "description",       "test Ogre Component",
                  "version",           "0.0.1",
                  "vendor",            "Miyamoto Nobuhiko",
                  "category",          "example",
                  "activity_type",     "DataFlowComponent",
                  "max_instance",      "10",
                  "language",          "Python",
                  "lang_type",         "script",
                  ""]

class testOgre(OpenRTM_aist.DataFlowComponentBase):
  def __init__(self, manager):
    OpenRTM_aist.DataFlowComponentBase.__init__(self, manager)
    self.p = 100
    self.link = None


  def onInitialize(self):
    self._data = RTC.TimedFloatSeq(RTC.Time(0,0), [])
    self._In = OpenRTM_aist.InPort("pos", self._data)
    self.addInPort("pos", self._In)
    
    return RTC.RTC_OK

  def onActivated(self, ec_id):
    
    return RTC.RTC_OK
  
  def onDeactivated(self, ec_id):
    return RTC.RTC_OK
        
  def onExecute(self, ec_id):
    if self._In.isNew():
        indata = self._In.read()
        pos = indata.data
        print pos
        if len(pos) > 2:
            link = OgreRTS.OgreObj.getBodyByName("test2")
            if link != None:
              link.SetPosition(pos[0], pos[1], pos[2])
    
    return RTC.RTC_OK

  def on_shutdown(self, ec_id):
      return RTC.RTC_OK

  def keyPressed(self, k):
      pass
    
  def keyReleased(self, k):
      pass

  def mouseMoved(self, mx, my, mdx, mdy):
      print mx, my, mdx, mdy
      
      

  def mousePressed(self, b):
      pass

  def mouseReleased(self, b):
      pass

  def ogre_init(self):
      pass
      
      

  def ogre_loop(self):
      pass

  def Simloop(self):
      pass

  def Contacthandler(self, b1, b2):
      pass

  def testClicked(self):
      print 334
      
def testOgreInit(manager):
  
  profile = OpenRTM_aist.Properties(defaults_str=consolein_spec)
  manager.registerFactory(profile,
                          testOgre,
                          OpenRTM_aist.Delete)

def MyModuleInit(manager):
  manager._factory.unregisterObject("testOgre")
  testOgreInit(manager)
  return manager.createComponent("testOgre")






    
    
    

        
    
    
