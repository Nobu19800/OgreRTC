#include "OgreRTCApplication.h"

#include "UnicodeF.h"







#include <iostream>

#include <fstream>



using namespace std;
namespace bpy = boost::python;








#ifdef _MSC_VER
#pragma warning(disable:4244 4305)  // for VC++, no precision loss complaints
#endif








int str_size;










CEGUI::utf32 keycodeToUTF32( unsigned int scanCode)
 {
 	CEGUI::utf32 utf = 0;
 
 	BYTE keyboardState[256];
 	unsigned char ucBuffer[3];
 	static WCHAR deadKey = '\0';
 
 	
 	HKL hklKeyboardLayout = GetKeyboardLayout(0);
 	
 	if (GetKeyboardState(keyboardState) == FALSE)
 		return utf;
 
 	
 	UINT virtualKey = MapVirtualKeyEx(scanCode, 3, hklKeyboardLayout);
 	if (virtualKey == 0)
 		return utf;
 

 	int ascii = ToAsciiEx(virtualKey, scanCode, keyboardState, (LPWORD) ucBuffer, 0, hklKeyboardLayout);
 	if(deadKey != '\0' && ascii == 1)
 	{
 		
 		WCHAR wcBuffer[3];
 		WCHAR out[3];
 		wcBuffer[0] = ucBuffer[0];
 		wcBuffer[1] = deadKey;
 		wcBuffer[2] = '\0';
 		if( FoldStringW(MAP_PRECOMPOSED, (LPWSTR) wcBuffer, 3, (LPWSTR) out, 3) )
 			utf = out[0];
 		else
 		{
 			
 			DWORD dw = GetLastError();
 			switch(dw)
 			{
 			case ERROR_INSUFFICIENT_BUFFER:
 			case ERROR_INVALID_FLAGS:
 			case ERROR_INVALID_PARAMETER:
 				break;
 			}
 		}
 		deadKey = '\0';
 	}
 	else if (ascii == 1)
 	{
 		
 		utf = ucBuffer[0];
 		deadKey = '\0';
 	}
 	else
 	{
 		
 		switch(ucBuffer[0])
 		{
 		case 0x5E:
 			deadKey = 0x302;
 			break;
 		case 0x60:
 			deadKey = 0x300;
 			break;
 		case 0xA8:
 			deadKey = 0x308;
 			break;
 		case 0xB4:
 			deadKey = 0x301;
 			break;
 		case 0xB8:
 			deadKey = 0x327;
 			break;
 		default:
 			deadKey = ucBuffer[0];
 		}
 	}
 
 	return utf;
 }











void OgreRTCApplication::setEColor(MyLink *ml, float r, float g, float b, float a){
	Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().create("BoxColor", "General", true );
	Ogre::Technique* tech = mat->getTechnique(0);
	Ogre::Pass* pass = tech->getPass(0);
	pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
	//pass->setDepthWriteEnabled(false);
	Ogre::TextureUnitState* tex = pass->createTextureUnitState();

	tex->setColourOperationEx(Ogre::LBX_MODULATE, Ogre::LBS_MANUAL, Ogre::LBS_CURRENT, Ogre::ColourValue(r, g, b));
	tex->setAlphaOperation(Ogre::LBX_MODULATE, Ogre::LBS_MANUAL, Ogre::LBS_CURRENT, a);
		
	ml->mEntity->setMaterial(mat);

	ml->red = r;
	ml->green = g;
	ml->blue = b;
	ml->alpha = a;
	ml->color_visi = true;
}








//-------------------------------------------------------------------------------------


BOOST_PYTHON_MODULE(CppExport)
{
			bpy::class_<OgreRTCApplication>("OgreRTCApplication")
			.def("CreateBody", &OgreRTCApplication::SetBody , bpy::return_internal_reference<>())
			.def("DestroyBody", &OgreRTCApplication::DestroyBody)
			.def("setEColor",&OgreRTCApplication::setEColor)
			.def("CameraRoll",&OgreRTCApplication::CameraRoll)
			.def("CameraYaw",&OgreRTCApplication::CameraYaw)
			.def("CameraPitch",&OgreRTCApplication::CameraPitch)
			.def("SetCameraPosition",&OgreRTCApplication::SetCameraPosition)
			.def("SetCameraQuaternion",&OgreRTCApplication::SetCameraQuaternion)
			.def("DestroyGui",&OgreRTCApplication::DestroyGui)
			.def("CreateGuiImageSet",&OgreRTCApplication::CreateGuiImageSet, bpy::return_internal_reference<>())
			.def("DestroyImage",&OgreRTCApplication::DestroyImage)
			.def("CreateStaticImage",&OgreRTCApplication::CreateStaticImage, bpy::return_internal_reference<>())
			.def("CreateStaticText",&OgreRTCApplication::CreateStaticText, bpy::return_internal_reference<>())
			.def("CreateButton",&OgreRTCApplication::CreateButton, bpy::return_internal_reference<>())
			.def("CreateEditBox",&OgreRTCApplication::CreateEditBox, bpy::return_internal_reference<>())
			.def("CreateSlider",&OgreRTCApplication::CreateSlider, bpy::return_internal_reference<>())
			.def("CreateParticle",&OgreRTCApplication::CreateParticle, bpy::return_internal_reference<>())
			.def("DestroyParticle",&OgreRTCApplication::DestroyParticle)
			.def("SetSkyBox",&OgreRTCApplication::SetSkyBox)
			.def("SetFloor",&OgreRTCApplication::SetFloor, bpy::return_internal_reference<>())
			.def("SetShadowColour",&OgreRTCApplication::SetShadowColour)
			.def("SetSubWindow",&OgreRTCApplication::SetSubWindow, bpy::return_internal_reference<>())
			.def("DestroySubWindow",&OgreRTCApplication::DestroySubWindow)
			.def("restartSubWindow",&OgreRTCApplication::restartSubWindow)
			.def("StopSubWindow",&OgreRTCApplication::StopSubWindow, bpy::return_internal_reference<>())
			.def("SetSleepTime",&OgreRTCApplication::SetSleepTime)
			.def("GetBodyName",&OgreRTCApplication::GetBodyName)
			.def("GetQueryScene",&OgreRTCApplication::GetQueryScene, bpy::return_internal_reference<>())
			.def("CreateComboBox",&OgreRTCApplication::CreateComboBox, bpy::return_internal_reference<>())
			.def("CreateTitlebar",&OgreRTCApplication::CreateTitlebar, bpy::return_internal_reference<>())
			.def("CreateFrameWindow",&OgreRTCApplication::CreateFrameWindow, bpy::return_internal_reference<>())
			.def("CreateVerticalScrollbar",&OgreRTCApplication::CreateVerticalScrollbar, bpy::return_internal_reference<>())
			.def("CreateHorizontalScrollbar",&OgreRTCApplication::CreateHorizontalScrollbar, bpy::return_internal_reference<>())
			.def("CreateProgressBar",&OgreRTCApplication::CreateProgressBar, bpy::return_internal_reference<>())
			.def("CreateMultiLineEditbox",&OgreRTCApplication::CreateMultiLineEditbox, bpy::return_internal_reference<>())
			.def("CreateListbox",&OgreRTCApplication::CreateListbox, bpy::return_internal_reference<>())
			.def("CreateComboDropList",&OgreRTCApplication::CreateComboDropList, bpy::return_internal_reference<>())
			.def("CreateCheckbox",&OgreRTCApplication::CreateCheckbox, bpy::return_internal_reference<>())
			.def("CreateRadioButton",&OgreRTCApplication::CreateRadioButton, bpy::return_internal_reference<>())
			.def("CreateTooltip",&OgreRTCApplication::CreateTooltip, bpy::return_internal_reference<>())
			.def("CreateItemListbox",&OgreRTCApplication::CreateItemListbox, bpy::return_internal_reference<>())
			.def("CreateListboxItem",&OgreRTCApplication::CreateListboxItem, bpy::return_internal_reference<>())
			.def("CreateSpinner",&OgreRTCApplication::CreateSpinner, bpy::return_internal_reference<>())
			.def("CreateScrollablePane",&OgreRTCApplication::CreateScrollablePane, bpy::return_internal_reference<>())
			.def("CreateListHeaderSegment",&OgreRTCApplication::CreateListHeaderSegment, bpy::return_internal_reference<>())
			.def("CreateListHeader",&OgreRTCApplication::CreateListHeader, bpy::return_internal_reference<>())
			.def("CreateMultiColumnList",&OgreRTCApplication::CreateMultiColumnList, bpy::return_internal_reference<>())
			.def("CreateMenuItem",&OgreRTCApplication::CreateMenuItem, bpy::return_internal_reference<>())
			.def("CreateMenubar",&OgreRTCApplication::CreateMenubar, bpy::return_internal_reference<>())
			.def("CreatePopupMenu",&OgreRTCApplication::CreatePopupMenu, bpy::return_internal_reference<>())
			.def("CreateTabButtonPane",&OgreRTCApplication::CreateTabButtonPane, bpy::return_internal_reference<>())
			.def("CreateTabContentPane",&OgreRTCApplication::CreateTabContentPane, bpy::return_internal_reference<>())
			.def("CreateTabControl",&OgreRTCApplication::CreateTabControl, bpy::return_internal_reference<>())
			.def("getBodyByName",&OgreRTCApplication::getBodyByName, bpy::return_internal_reference<>())
			.def("getGUIByName",&OgreRTCApplication::getGUIByName, bpy::return_internal_reference<>())
			.def("getParticleByName",&OgreRTCApplication::getParticleByName, bpy::return_internal_reference<>())
			.def("getSubWindowByName",&OgreRTCApplication::getSubWindowByName, bpy::return_internal_reference<>())
			.def("getImageSetByName",&OgreRTCApplication::getImageSetByName, bpy::return_internal_reference<>())
			.def("SetCameraRotation",&OgreRTCApplication::SetCameraRotation, bpy::return_internal_reference<>())
			.def("AddFileSystem",&OgreRTCApplication::AddFileSystem)
			.def("CreateAnimation",&OgreRTCApplication::CreateAnimation, bpy::return_internal_reference<>())
			.def("DestroyAnimation",&OgreRTCApplication::DestroyAnimation)
			.def("CreateLight",&OgreRTCApplication::CreateLight, bpy::return_internal_reference<>())
			.def("DestroyLight",&OgreRTCApplication::DestroyLight)
			.def("getLightByName",&OgreRTCApplication::getLightByName, bpy::return_internal_reference<>())
			.def("getAnimationByName",&OgreRTCApplication::getAnimationByName, bpy::return_internal_reference<>())
			.def("getNodeByName",&OgreRTCApplication::getNodeByName, bpy::return_internal_reference<>())
			.def("DeatachObj",(void(OgreRTCApplication:: *)(MyLink *))&OgreRTCApplication::DeatachObj)
			.def("DeatachObj",(void(OgreRTCApplication:: *)(myParticle *))&OgreRTCApplication::DeatachObj)
			.def("DeatachObj",(void(OgreRTCApplication:: *)(MyLight *))&OgreRTCApplication::DeatachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(MyLink *, myParticle *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(MyLink *, MyLight *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(myParticle *, MyLight *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(MyLink *, MyLink *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(myParticle *, myParticle *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(MyLight *, MyLight *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(MyAnimation *, MyLink *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(MyAnimation *, MyLight *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(MyAnimation *, myParticle *))&OgreRTCApplication::AttachObj)
			.def("save",&OgreRTCApplication::save)
			.def("openb",&OgreRTCApplication::openb)
			.def("newfile",&OgreRTCApplication::newfile)
			.def("reset",&OgreRTCApplication::reset)
			.def("SetRTC",&OgreRTCApplication::SetRTC)
			;
			
			
			bpy::class_<MyObject>("MyObject")
			.def("SetPosition",&MyObject::SetPosition)
			.def("SetScale",&MyObject::SetScale)
			.def("Roll",&MyObject::Roll)
			.def("Pitch",&MyObject::Pitch)
			.def("Yaw",&MyObject::Yaw)
			.def("SetQuaternion",&MyObject::SetQuaternion)
			.def("SetVisible",&MyObject::SetVisible)
			.def("BoundingBoxVisible",&MyObject::BoundingBoxVisible)
			;

			

			bpy::class_<MyLink>("MyLink",bpy::init<std::string>())
			.def("SetAnimation",&MyLink::SetAnimation)
			.def("ResetAnimation",&MyLink::ResetAnimation)
			.def("UpdateAnimation",&MyLink::UpdateAnimation)
			.def("SetShadows",&MyLink::SetShadows)
			.def("SetBornPosition",(void(MyLink:: *)(const char *, float, float, float))&MyLink::SetBornPosition)
			.def("SetBornOrientation",(void(MyLink:: *)(const char *, float, float, float, float))&MyLink::SetBornOrientation)
			.def("SetBornRotation",(void(MyLink:: *)(const char *, float, float, float))&MyLink::SetBornRotation)
			.def("SetBornScale",(void(MyLink:: *)(const char *, float, float, float))&MyLink::SetBornScale)
			.def("SetBornRoll",(void(MyLink:: *)(const char *, float))&MyLink::SetBornRoll)
			.def("SetBornPitch",(void(MyLink:: *)(const char *, float))&MyLink::SetBornPitch)
			.def("SetBornYaw",(void(MyLink:: *)(const char *, float))&MyLink::SetBornYaw)
			.def("GetBornNum",&MyLink::GetBornNum)
			.def("ResetBorn",&MyLink::ResetBorn)
			.def("SetBornPosition",(void(MyLink:: *)(int, float, float, float))&MyLink::SetBornPosition)
			.def("SetBornOrientation",(void(MyLink:: *)(int, float, float, float, float))&MyLink::SetBornOrientation)
			.def("SetBornRotation",(void(MyLink:: *)(int, float, float, float))&MyLink::SetBornRotation)
			.def("SetBornScale",(void(MyLink:: *)(int, float, float, float))&MyLink::SetBornScale)
			.def("SetBornRoll",(void(MyLink:: *)(int , float))&MyLink::SetBornRoll)
			.def("SetBornPitch",(void(MyLink:: *)(int , float))&MyLink::SetBornPitch)
			.def("SetBornYaw",(void(MyLink:: *)(int , float))&MyLink::SetBornYaw)
			//.def("BoundingBoxVisible",&MyLink::BoundingBoxVisible)
			.def("GetBoundingBoxSize",&MyLink::GetBoundingBoxSize)
			.def("SetPosition",&MyLink::SetPosition)
			.def("SetScale",&MyLink::SetScale)
			.def("Roll",&MyLink::Roll)
			.def("Pitch",&MyLink::Pitch)
			.def("Yaw",&MyLink::Yaw)
			.def("SetQuaternion",&MyLink::SetQuaternion)
			.def("SetRotation",&MyLink::SetRotation)
			.def("SetVisible",&MyLink::SetVisible)
			.def("BoundingBoxVisible",&MyLink::BoundingBoxVisible)

			;

			bpy::class_<MyGUI>("CEGUIWindow")
			.def("SetPosition",&MyGUI::SetPosition)
			.def("SetSize",&MyGUI::SetSize)
			.def("SetText",&MyGUI::SetText)
			.def("SetVisible",&MyGUI::SetVisible)
			.def("SetFrameEnable",&MyGUI::SetFrameEnable)
			.def("SetBackGroundEnable",&MyGUI::SetBackGroundEnable)
			.def("SetFontSize",&MyGUI::SetFontSize)
			.def("GetText",&MyGUI::GetText)
			.def("GetComboBoxItem",&MyGUI::GetComboBoxItem)
			.def("GetSliderValue",&MyGUI::GetSliderValue)
			.def("SetTextColor",&MyGUI::SetTextColor)
			.def("SetAlpha",&MyGUI::SetAlpha)
			.def("SetImage",&MyGUI::SetImage)
			.def("SetTextTopAligned",&MyGUI::SetTextTopAligned)
			.def("SetTextBottomAligned",&MyGUI::SetTextBottomAligned)
			.def("SetTextVertCentred",&MyGUI::SetTextVertCentred)
			.def("SetTextWordWrapLeftAligned",&MyGUI::SetTextWordWrapLeftAligned)
			.def("SetTextWordWrapRightAligned",&MyGUI::SetTextWordWrapRightAligned)
			.def("SetTextWordWrapCentred",&MyGUI::SetTextWordWrapCentred)
			.def("SetTextLeftAligned",&MyGUI::SetTextLeftAligned)
			.def("SetTextRightAligned",&MyGUI::SetTextRightAligned)
			.def("SetTextHorzCentred",&MyGUI::SetTextHorzCentred)
			.def("ClearProperties",&MyGUI::ClearProperties)
			.def("SetRotatin",&MyGUI::SetRotatin)
			.def("moveToFront",&MyGUI::moveToFront)
			.def("moveToBack",&MyGUI::moveToBack)
			.def("moveInFront",&MyGUI::moveInFront)
			.def("moveBehind",&MyGUI::moveBehind)
			.def("setColor",&MyGUI::setColor)
			.def("SetWindow",&MyGUI::SetWindow)
			.def("RemoveComboBoxItem",&MyGUI::RemoveComboBoxItem)
			.def("AddListBoxItem",&MyGUI::AddListBoxItem)
			.def("RemoveListBoxItem",&MyGUI::RemoveListBoxItem)
			.def("AddMultiColumnRow",&MyGUI::AddMultiColumnRow)
			.def("RemoveMultiColumnRow",&MyGUI::RemoveMultiColumnRow)
			.def("RemoveMultiColumnCol",&MyGUI::RemoveMultiColumnCol)
			.def("AddMultiColumnItem",&MyGUI::AddMultiColumnItem)
			.def("SetProgressBarValue",&MyGUI::SetProgressBarValue)
			.def("GetScrollValue",&MyGUI::GetScrollValue)
			.def("SetCheckBox",&MyGUI::SetCheckBox)
			.def("GetCheckBox",&MyGUI::SetCheckBox)
			
			

			
			

			;
			bpy::class_<myParticle>("myParticle",bpy::init<std::string>())
			.def("SetPosition",&myParticle::SetPosition)
			.def("SetScale",&myParticle::SetScale)
			.def("Roll",&myParticle::Roll)
			.def("Pitch",&myParticle::Pitch)
			.def("Yaw",&myParticle::Yaw)
			.def("SetQuaternion",&myParticle::SetQuaternion)
			.def("SetRotation",&myParticle::SetRotation)
			.def("SetVisible",&myParticle::SetVisible)
			.def("BoundingBoxVisible",&myParticle::BoundingBoxVisible)

			;
			bpy::class_<SubWindow>("SubWindow")
			.def("SetPosition",&SubWindow::SetPosition)
			.def("SetSize",&SubWindow::SetSize)
			.def("SetCameraRoll",&SubWindow::SetCameraRoll)
			.def("SetCameraPitch",&SubWindow::SetCameraPitch)
			.def("SetCameraYaw",&SubWindow::SetCameraYaw)
			.def("SetCameraPosition",&SubWindow::SetCameraPosition)
			.def("SetCameraQuaternion",&SubWindow::SetCameraQuaternion)
			.def("SetVisible",&SubWindow::SetVisible)
			.def("SetCameraRotation",&SubWindow::SetCameraRotation)
			;


			bpy::class_<MyAnimation>("MyAnimation",bpy::init<std::string>())
			.def("AddKeyFrame",&MyAnimation::AddKeyFrame, bpy::return_internal_reference<>())
			.def("RemoveKeyFrame",&MyAnimation::RemoveKeyFrame)
			.def("SetAnimationState",&MyAnimation::SetAnimationState)
			.def("SetLength",&MyAnimation::SetLength)
			;
			bpy::class_<MyAnimationList>("MyAnimationList")
			.def("setTranslate",&MyAnimationList::setTranslate)
			.def("setRotation",&MyAnimationList::setRotation)

			;
			bpy::class_<MyLight>("MyLight",bpy::init<std::string>())
			.def("setColor",&MyLight::setColor)
			.def("SetPosition",&MyLight::SetPosition)
			.def("SetScale",&MyLight::SetScale)
			.def("Roll",&MyLight::Roll)
			.def("Pitch",&MyLight::Pitch)
			.def("Yaw",&MyLight::Yaw)
			.def("SetQuaternion",&MyLight::SetQuaternion)
			.def("SetRotation",&MyLight::SetRotation)
			.def("SetVisible",&MyLight::SetVisible)
			.def("BoundingBoxVisible",&MyLight::BoundingBoxVisible)

			;
			bpy::class_<MyODEBody>("MyODEBody",bpy::init<std::string, MySimulation*>())
			.def("SetBodyPosition",&MyODEBody::SetBodyPosition)
			.def("SetBodyRotation",&MyODEBody::SetBodyRotation)
			.def("SetODEScale",&MyODEBody::SetODEScale)
			.def("SetODEOffset",&MyODEBody::SetODEOffset)
			.def("GetPosition",&MyODEBody::GetPosition)

			;
			bpy::class_<MyODEJoint>("MyODEJoint",bpy::init<std::string, MySimulation*>())
			.def("SetJointPosition",&MyODEJoint::SetJointPosition)
			.def("SetJointRotation",&MyODEJoint::SetJointRotation)
			.def("ControlJointAng",&MyODEJoint::ControlJointAng)
			.def("ControlJointVel",&MyODEJoint::ControlJointVel)
			.def("ControlJointToq",&MyODEJoint::ControlJointToq)
			.def("SetODEScale",&MyODEJoint::SetODEScale)
			.def("SetODEOffset",&MyODEJoint::SetODEOffset)
			.def("GetJointPosition",&MyODEJoint::GetJointPosition)
			;
			bpy::class_<MyContactList>("MyContactList",bpy::init<std::string>())
			.def("SetERP",&MyContactList::SetERP)
			.def("SetCFM",&MyContactList::SetCFM)
			.def("SetMu",&MyContactList::SetMu)
			.def("SetContact",&MyContactList::SetContact)
			;
			bpy::class_<MySimulation>("MySimulation",bpy::init<OgreRTCApplication*>())
			.def("SetSphere",&MySimulation::SetSphere, bpy::return_internal_reference<>())
			.def("SetBox",&MySimulation::SetBox, bpy::return_internal_reference<>())
			.def("SetSylinder",&MySimulation::SetSylinder, bpy::return_internal_reference<>())
			.def("SetCapsule",&MySimulation::SetCapsule, bpy::return_internal_reference<>())
			.def("SetSliderJoint",(MyODEJoint *(MySimulation:: *)(const char *, MyODEBody *, MyODEBody *, double, double, double))&MySimulation::SetSliderJoint, bpy::return_internal_reference<>())
			.def("SetSliderJoint",(MyODEJoint *(MySimulation:: *)(const char *, MyODEBody *, double, double, double))&MySimulation::SetSliderJoint, bpy::return_internal_reference<>())
			.def("SetFixJoint",(MyODEJoint *(MySimulation:: *)(const char *, MyODEBody *, MyODEBody *))&MySimulation::SetFixJoint, bpy::return_internal_reference<>())
			.def("SetFixJoint",(MyODEJoint *(MySimulation:: *)(const char *, MyODEBody *))&MySimulation::SetFixJoint, bpy::return_internal_reference<>())
			.def("SetHingeJoint",(MyODEJoint *(MySimulation:: *)(const char *, MyODEBody *, MyODEBody *, double, double, double, double, double, double))&MySimulation::SetHingeJoint, bpy::return_internal_reference<>())
			.def("SetHingeJoint",(MyODEJoint *(MySimulation:: *)(const char *, MyODEBody *, double, double, double, double, double, double))&MySimulation::SetHingeJoint, bpy::return_internal_reference<>())
			.def("DestroyBody",&MySimulation::DestroyBody)
			.def("DestroyJoint",&MySimulation::DestroyJoint)
			.def("DestroyAll",&MySimulation::DestroyAll)
			.def("startSim",&MySimulation::startSim)
			.def("restartSim",&MySimulation::restartSim)
			.def("stopSim",&MySimulation::stopSim)
			.def("SetGravity",&MySimulation::SetGravity)
			.def("SetCFM",&MySimulation::SetCFM)
			.def("SetERP",&MySimulation::SetERP)
			.def("SetSamplingTime",&MySimulation::SetSamplingTime)
			.def("SetSleepTime",&MySimulation::SetSleepTime)
			.def("SetGroundCFM",&MySimulation::SetGroundCFM)
			.def("SetGroundERP",&MySimulation::SetGroundERP)
			.def("SetQuiq",&MySimulation::SetQuiq)
			.def("SetGroundMu",&MySimulation::SetGroundMu)
			.def("getBodyByName",&MySimulation::getBodyByName, bpy::return_internal_reference<>())
			.def("getJointByName",&MySimulation::getJointByName, bpy::return_internal_reference<>())
			.def("SetScale",&MySimulation::SetScale)
			.def("SetContactList",&MySimulation::SetContactList, bpy::return_internal_reference<>())
			.def("DestroyContactList",&MySimulation::DestroyContactList)
			.def("getContactListByName",&MySimulation::getContactListByName, bpy::return_internal_reference<>())

			
			
			;
			bpy::class_<MyImageSet>("MyImageSet")

			;
			
			bpy::enum_<Qt::MouseButton>("MouseButton")
			.value("MB_Left",Qt::LeftButton)
			.value("MB_Right",Qt::RightButton)
			.value("MB_Middle",Qt::MidButton)
			

			

			;
			bpy::enum_<Qt::Key>("KeyCode")
			.value("KC_ESCAPE",Qt::Key_Escape)
			.value("KC_1",Qt::Key_1)
			.value("KC_2",Qt::Key_2)
			.value("KC_3",Qt::Key_3)
			.value("KC_4",Qt::Key_4)
			.value("KC_5",Qt::Key_5)
			.value("KC_6",Qt::Key_6)
			.value("KC_7",Qt::Key_7)
			.value("KC_8",Qt::Key_8)
			.value("KC_9",Qt::Key_9)
			.value("KC_0",Qt::Key_0)
			.value("KC_MINUS",Qt::Key_Minus)
			.value("KC_EQUALS",Qt::Key_Equal)
			.value("KC_BACK",Qt::Key_Backspace)
			.value("KC_TAB",Qt::Key_Tab)
			.value("KC_Q",Qt::Key_Q)
			.value("KC_W",Qt::Key_W)
			.value("KC_E",Qt::Key_E)
			.value("KC_R",Qt::Key_R)
			.value("KC_T",Qt::Key_T)
			.value("KC_Y",Qt::Key_Y)
			.value("KC_U",Qt::Key_U)
			.value("KC_I",Qt::Key_I)
			.value("KC_O",Qt::Key_O)
			.value("KC_P",Qt::Key_P)
			.value("KC_RETURN",Qt::Key_Return)
			.value("KC_A",Qt::Key_A)
			.value("KC_S",Qt::Key_S)
			.value("KC_D",Qt::Key_D)
			.value("KC_F",Qt::Key_F)
			.value("KC_G",Qt::Key_G)
			.value("KC_H",Qt::Key_H)
			.value("KC_J",Qt::Key_J)
			.value("KC_K",Qt::Key_K)
			.value("KC_L",Qt::Key_L)
			.value("KC_BACKSLASH",Qt::Key_Backslash)
			.value("KC_Z",Qt::Key_Z)
			.value("KC_X",Qt::Key_X)
			.value("KC_C",Qt::Key_C)
			.value("KC_V",Qt::Key_V)
			.value("KC_B",Qt::Key_B)
			.value("KC_N",Qt::Key_N)
			.value("KC_M",Qt::Key_M)
			.value("KC_SPACE",Qt::Key_Space)
			.value("KC_F1",Qt::Key_F1)
			.value("KC_F2",Qt::Key_F2)
			.value("KC_F3",Qt::Key_F3)
			.value("KC_F4",Qt::Key_F4)
			.value("KC_F5",Qt::Key_F5)
			.value("KC_F6",Qt::Key_F6)
			.value("KC_F7",Qt::Key_F7)
			.value("KC_F8",Qt::Key_F8)
			.value("KC_F9",Qt::Key_F9)
			.value("KC_F10",Qt::Key_F10)
			.value("KC_F11",Qt::Key_F11)
			.value("KC_F12",Qt::Key_F12)
			.value("KC_F13",Qt::Key_F13)
			.value("KC_F14",Qt::Key_F14)
			.value("KC_F15",Qt::Key_F15)
			.value("KC_UP",Qt::Key_Up)
			.value("KC_RIGHT",Qt::Key_Right)
			.value("KC_LEFT",Qt::Key_Left)
			.value("KC_DOWN",Qt::Key_Down)
			;


}


OgreRTCApplication::OgreRTCApplication(void)
{
	
	SleepTime = 0;


	PreeditStr = QString();

	
	RTCFlag = false;
	
	

	
	


	skyBoxName = "";
	QtskyBoxName = "";


	mSim = new MySimulation(this);

	mSim->activate();
	
	if( PyImport_AppendInittab( "CppExport" , initCppExport ) == -1 )
   {
		std::cout << "Failed" << std::endl;
		return;
   }
	po = new PyObj();
	po->global_ns["OgreObj"] = boost::ref(this);
	po->global_ns["SimulationObj"] = boost::ref(mSim);

	po->Script("OgreRTC.py");

	

	po->setFunc("ManagerStart");
   
	
	
}
//-------------------------------------------------------------------------------------


void OgreRTCApplication::UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len)
{
	CamX = px;
	CamY = py;
	CamZ = pz;
	CamRoll = roll;
	CamPitch = pitch;
	CamYaw = yaw;
	CamLen = len;


	Ogre::Quaternion tRot = GetRotQuat(roll, pitch, yaw);

	Ogre::Vector3 tLen(0,0,len);
	tLen = tRot * tLen;

	SetCameraPosition(px+tLen.x, py+tLen.y, pz+tLen.z);
	SetCameraQuaternion(tRot.w,tRot.x,tRot.y,tRot.z);


}

void OgreRTCApplication::MoveCameraPos(float dx, float dy)
{

	Ogre::Quaternion tRot = GetRotQuat(CamRoll, CamPitch, CamYaw);

	Ogre::Vector3 tLen(0,0,CamLen);
	tLen = tRot * tLen;
	
	Ogre::Vector3 dp(dx,dy,0);
	dp = tRot * dp;

	CamX = CamX + dp.x;
	CamY = CamY + dp.y;
	CamZ = CamZ + dp.z;


	SetCameraPosition(CamX+tLen.x, CamY+tLen.y, CamZ+tLen.z);
	SetCameraQuaternion(tRot.w,tRot.x,tRot.y,tRot.z);



}

void OgreRTCApplication::MoveCameraRot(float dx, float dy)
{
	

	Ogre::Quaternion tRot = GetRotQuat(CamRoll, CamPitch, CamYaw);
	
	Ogre::Vector3 dx_Axis = tRot * Ogre::Vector3(0,1,0);
	Ogre::Vector3 dy_Axis = tRot * Ogre::Vector3(1,0,0);
	Ogre::Quaternion tdxRot;
	tdxRot.FromAngleAxis(Ogre::Degree(dx),dx_Axis);
	Ogre::Quaternion tdyRot;
	tdyRot.FromAngleAxis(Ogre::Degree(dy),dy_Axis);
	
	tdxRot = tdyRot* tdxRot;
	
	CamRoll = CamRoll + tdxRot.getRoll().valueDegrees();
	if(CamRoll < 0)
	{
		CamRoll = 360 + CamRoll;
	}
	CamPitch = CamPitch + tdxRot.getPitch().valueDegrees();
	if(CamPitch < 0)
	{
		CamPitch = 360 + CamPitch;
	}
	CamYaw = CamYaw + tdxRot.getYaw().valueDegrees();
	if(CamYaw < 0)
	{
		CamYaw = 360 + CamYaw;
	}

	

	tRot = GetRotQuat(CamRoll, CamPitch, CamYaw);


	Ogre::Vector3 tLen(0,0,CamLen);
	tLen = tRot * tLen;
	

	

	


	SetCameraPosition(CamX+tLen.x, CamY+tLen.y, CamZ+tLen.z);
	SetCameraQuaternion(tRot.w,tRot.x,tRot.y,tRot.z);
}

void OgreRTCApplication::StopFile()
{
	if(po->Exec)
	{
		po->mThread->wait();
		po->setFunc("RTCStop");
		
		po->Exec = false;
	}
}
void OgreRTCApplication::CloseFile()
{
	StopFile();

	DestroyAllBody();
	DestroyAllGUI();

	
	
	DestroyAllParticle();
	DestroyAllSubWindow();
	DestroyAllImage();

	

	
}

void OgreRTCApplication::OpenFile(const char *fname)
{
	if(po->Exec)
	{
		po->Exec = false;
		po->setFunc("RTCStop");
		//CreatePyFunc(po, "RTCStop");
		po->mThread->wait();
		po->mThread->close();
		delete po->mThread;
		
			
	}

	po->mThread = new PBThread(fname, po);
	po->mThread->activate();
	

	while(!RTCFlag){
		Sleep(10);
		if(po->mThread->fin)
		{
			po->mThread->wait();
			po->mThread->close();
			delete po->mThread;
			RTCFlag = false;
			return;
		}
	};
	po->setFunc("ogre_init");
	RTCFlag = false;
	//CreatePyFunc(po, "ogre_init");

	po->Exec = true;

	
}

MyLink* OgreRTCApplication::getBodyByName(const char* name)
{
	
	for(int i=0;i < MyLinks.size();i++)
	{
		if(MyLinks[i]->name == name)
		{
			return MyLinks[i];
		}
	}
	return NULL;
}

MyGUI* OgreRTCApplication::getGUIByName(const char* name)
{
	for(int i=0;i < MyGUIs.size();i++)
	{
		if(MyGUIs[i]->name == name)
		{
			return MyGUIs[i];
		}
	}
	return NULL;
}

myParticle* OgreRTCApplication::getParticleByName(const char* name)
{
	for(int i=0;i < myParticles.size();i++)
	{
		if(myParticles[i]->name == name)
		{
			return myParticles[i];
		}
	}
	return NULL;
}

SubWindow* OgreRTCApplication::getSubWindowByName(const char* name)
{
	for(int i=0;i < SubWindows.size();i++)
	{
		if(SubWindows[i]->Wname == name)
		{
			return SubWindows[i];
		}
	}
	return NULL;
}

MyImageSet* OgreRTCApplication::getImageSetByName(const char* name)
{
	for(int i=0;i < MyImageSets.size();i++)
	{
		if(MyImageSets[i]->name == name)
		{
			return MyImageSets[i];
		}
	}
	return NULL;
}

OgreRTCApplication::~OgreRTCApplication(void)
{
	/*if (hTh != NULL) {
        CloseHandle(hTh);
        printf("ハンドルクローズしました\n");
    }

	dJointGroupEmpty (contactgroup);
    dJointGroupDestroy (contactgroup);
	dSpaceDestroy(space);
	dWorldDestroy(world);
	dCloseODE();//*/

	
	//delete contact_flag;

	mSceneMgr->destroyQuery(mRayQuery);
}


CEGUI::Key::Scan convertKey(int key)
{
	switch (key)
	{
		case Qt::Key_A:
			return CEGUI::Key::A;
			break;
		case Qt::Key_B:
			return CEGUI::Key::B;
			break;
		case Qt::Key_C:
			return CEGUI::Key::C;
			break;
		case Qt::Key_D:
			return CEGUI::Key::D;
			break;
		case Qt::Key_E:
			return CEGUI::Key::E;
			break;
		case Qt::Key_F:
			return CEGUI::Key::F;
			break;
		case Qt::Key_G:
			return CEGUI::Key::G;
			break;
		case Qt::Key_H:
			return CEGUI::Key::H;
			break;
		case Qt::Key_I:
			return CEGUI::Key::I;
			break;
		case Qt::Key_J:
			return CEGUI::Key::A;
			break;
		case Qt::Key_K:
			return CEGUI::Key::K;
			break;
		case Qt::Key_L:
			return CEGUI::Key::L;
			break;
		case Qt::Key_M:
			return CEGUI::Key::M;
			break;
		case Qt::Key_N:
			return CEGUI::Key::N;
			break;
		case Qt::Key_O:
			return CEGUI::Key::O;
			break;
		case Qt::Key_P:
			return CEGUI::Key::P;
			break;
		case Qt::Key_Q:
			return CEGUI::Key::Q;
			break;
		case Qt::Key_R:
			return CEGUI::Key::R;
			break;
		case Qt::Key_S:
			return CEGUI::Key::S;
			break;
		case Qt::Key_T:
			return CEGUI::Key::T;
			break;
		case Qt::Key_U:
			return CEGUI::Key::U;
			break;
		case Qt::Key_V:
			return CEGUI::Key::V;
			break;
		case Qt::Key_W:
			return CEGUI::Key::W;
			break;
		case Qt::Key_X:
			return CEGUI::Key::X;
			break;
		case Qt::Key_Y:
			return CEGUI::Key::Y;
			break;
		case Qt::Key_Z:
			return CEGUI::Key::Z;
			break;
		case Qt::Key_0:
			return CEGUI::Key::Zero;
			break;
		case Qt::Key_1:
			return CEGUI::Key::One;
			break;
		case Qt::Key_2:
			return CEGUI::Key::Two;
			break;
		case Qt::Key_3:
			return CEGUI::Key::Three;
			break;
		case Qt::Key_4:
			return CEGUI::Key::Four;
			break;
		case Qt::Key_5:
			return CEGUI::Key::Five;
			break;
		case Qt::Key_6:
			return CEGUI::Key::Six;
			break;
		case Qt::Key_7:
			return CEGUI::Key::Seven;
			break;
		case Qt::Key_8:
			return CEGUI::Key::Eight;
			break;
		case Qt::Key_9:
			return CEGUI::Key::Nine;
			break;
		case Qt::Key_Space:
			return CEGUI::Key::Space;
			break;
		case Qt::Key_Enter:
			return CEGUI::Key::Return;
			break;
		case Qt::Key_Backspace:
			return CEGUI::Key::Backspace;
			break;
		case Qt::Key_Up:
			return CEGUI::Key::ArrowUp;
			break;
		case Qt::Key_Left:
			return CEGUI::Key::ArrowLeft;
			break;
		case Qt::Key_Right:
			return CEGUI::Key::ArrowRight;
			break;
		case Qt::Key_Down:
			return CEGUI::Key::ArrowDown;
			break;
		default:
			return CEGUI::Key::Space;
			break;
	}
}

bool OgreRTCApplication::inputMethodEvent(QInputMethodEvent *arg)
{
	const QString tmp = arg->commitString();

	CEGUI::System &sys = CEGUI::System::getSingleton();

	if(!PreeditStr.isEmpty())
	{
		QVector<uint> t_text = PreeditStr.toUcs4();
		for(int i=0;i < t_text.size();i++)
		{
			sys.injectKeyDown(CEGUI::Key::Backspace);
		}
	}

	if(!tmp.isEmpty())
	{
		QVector<uint> t_text = tmp.toUcs4();

		for(int i=0;i < t_text.size();i++)
		{
			sys.injectChar(t_text[i]);
		}
	}

	PreeditStr = arg->preeditString();

	if(!PreeditStr.isEmpty())
	{
		QVector<uint> t_text = PreeditStr.toUcs4();

		for(int i=0;i < t_text.size();i++)
		{
			sys.injectChar(t_text[i]);
		}
	}

	return true;

}

bool OgreRTCApplication::keyPressed( QKeyEvent *arg )
{

	CEGUI::System &sys = CEGUI::System::getSingleton();
    sys.injectKeyDown(convertKey(arg->key()));

	
	CEGUI::utf32 utf = keycodeToUTF32(convertKey(arg->key()));
	if(utf)
      sys.injectChar(utf);

	if(po->Exec)
	{
		PyGILState_STATE gilstate;
   
		gilstate = PyGILState_Ensure();


		bpy::object pfunc = po->getFunc("keyPressed");
		try
		{
			
			pfunc(arg->key());

			

			
		}
		catch(const bpy::error_already_set&)
		{
			PyErr_Print();
		}
		PyGILState_Release(gilstate);
	}

	
	
	return BaseApplication::keyPressed(arg);
}

bool OgreRTCApplication::keyReleased( QKeyEvent *arg )
{
    if(CEGUI::System::getSingleton().injectKeyUp(convertKey(arg->key()))) return true;
    

	if(po->Exec)
	{
		PyGILState_STATE gilstate;
   
		gilstate = PyGILState_Ensure();


		bpy::object pfunc = po->getFunc("keyReleased");
		try
		{
			
			pfunc(arg->key());

			

			
		}
		catch(const bpy::error_already_set&)
		{
			PyErr_Print();
		}

		PyGILState_Release(gilstate);
	}


	

    return true;
}



CEGUI::MouseButton convertButton(Qt::MouseButton buttonID)
{

    switch (buttonID)
    {
    case Qt::LeftButton:
        return CEGUI::LeftButton;
        break;
 
    case Qt::RightButton:
        return CEGUI::RightButton;
        break;
 
    case Qt::MidButton:
        return CEGUI::MiddleButton;
        break;
 
    default:
        return CEGUI::LeftButton;
        break;
    }
}


bool OgreRTCApplication::mouseMoved( QMouseEvent*  evt )
{
	
	
	
	
	CEGUI::Point mousePos = CEGUI::MouseCursor::getSingleton().getPosition();

	static int mx = evt->pos().x();
	static int my = evt->pos().y();

	int mdx = evt->pos().x() - mx;
	int mdy = evt->pos().y() - my;

	mx = evt->pos().x();
	my = evt->pos().y();


	if(po->Exec)
	{
		PyGILState_STATE gilstate;
   
		gilstate = PyGILState_Ensure();


		bpy::object pfunc = po->getFunc("mouseMoved");
		try
		{
			
			pfunc(mx, my, mdx, mdy);

			

			
		}
		catch(const bpy::error_already_set&)
		{
			PyErr_Print();
		}

		PyGILState_Release(gilstate);
	}

	
	

    if(CEGUI::System::getSingleton().injectMousePosition(mx, my)) return true;
   

	

	

    return true;
}
 
bool OgreRTCApplication::mousePressed( QMouseEvent*  evt )
{

	if(po->Exec)
	{
		PyGILState_STATE gilstate;
   
		gilstate = PyGILState_Ensure();


		bpy::object pfunc = po->getFunc("mousePressed");
		try
		{
			
			pfunc(evt->button());

			

			
		}
		catch(const bpy::error_already_set&)
		{
			PyErr_Print();
		}

		PyGILState_Release(gilstate);
	}

	

    if(CEGUI::System::getSingleton().injectMouseButtonDown(convertButton(evt->button()))) return true;
    

	

    return true;
}
 
bool OgreRTCApplication::mouseReleased( QMouseEvent*  evt )
{

	if(po->Exec)
	{
		PyGILState_STATE gilstate;
   
		gilstate = PyGILState_Ensure();


		bpy::object pfunc = po->getFunc("mouseReleased");
		try
		{
			
			pfunc(evt->button());

			

			
		}
		catch(const bpy::error_already_set&)
		{
			PyErr_Print();
		}

		PyGILState_Release(gilstate);
	}

	

    if(CEGUI::System::getSingleton().injectMouseButtonUp(convertButton(evt->button()))) return true;
   

	

    return true;
}

void CreateML(MyLink *ml,double scx,double scy,double scz)
{
	ml->mEntity->setCastShadows(true);
	ml->mNode->mNode->attachObject(ml->mEntity);
	Ogre::Vector3 scale = Ogre::Vector3::ZERO;
	scale.x = scx;
	scale.y = scy;
	scale.z = scz;
	ml->mNode->mNode->scale(scale);
	
}
 
//-------------------------------------------------------------------------------------
void OgreRTCApplication::createScene(void)
{
    // Set the default lighting.
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.3f, 0.3f, 0.3f));
	//mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
    // Create the entity
	
	//ball.mEntity = mSceneMgr->createEntity( Ogre::SceneManager::PT_SPHERE);
	//mEntity->_getBuffersMarkedForAnimation
	

    // Create the scene node

	

	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_TEXTURE_MODULATIVE);
	SetShadowColour(0.5, 0.5, 0.5);
	mSceneMgr->setShadowTextureSize(1024);
	mSceneMgr->setShadowTextureCount(1);

	

	light = mSceneMgr->createLight();
	light->setType(Ogre::Light::LT_POINT);
	SetLightPosition(0, -10000, 10000);
	light->setSpecularColour(Ogre::ColourValue::White);

	

	/*Ogre::Light *light2 = mSceneMgr->createLight();
	light2->setType(Ogre::Light::LT_POINT);
	light2->setPosition(-10000, 0, 10000);
	light2->setSpecularColour(Ogre::ColourValue::White);
	*/
	

 
    // Set the camera to look at our handiwork
    //mCamera->setPosition(0.0f, -3000.0f, 300.0f);
    //mCamera->yaw(Ogre::Degree(-90.0f));
	//mCamera->pitch(Ogre::Degree(90.0f));
    //mCamera->pitch(Ogre::Degree(-0.0f));

	UpdateCameraPQ(0,0,0,45,0,0,1500);

	
	//stadium.mNode->setVisible(false);
	
	mRenderer = &CEGUI::OgreRenderer::bootstrapSystem(*mWindow);
 

	

    CEGUI::Imageset::setDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
 
	CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");

	CEGUI::FontManager::getSingleton().createFreeTypeFont("DefaultFont", 30/*pt*/, true, "sazanami-mincho.ttf");
	CEGUI::System::getSingleton().setDefaultFont("DefaultFont");

    //CEGUI::System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");


	



	//CEGUI::FontManager::getSingleton().createFreeTypeFont("DefaultFont", 10/*pt*/, true, "DejaVuSans.ttf");
	//CEGUI::System::getSingleton().setDefaultFont("DefaultFont");
	//CEGUI::FontManager::getSingleton().createAll("*.font", "fonts");

	

	//CEGUI::Window *sheet2;
	//sheet2 = wmgr.loadWindowLayout("Demo7Windows.layout");
    CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
    sheet = wmgr.createWindow("DefaultWindow", "CEGUIDemo/Sheet");
	

	


	CEGUI::FontManager::getSingleton().isDefined("sazanami-mincho");


	CEGUI::System::getSingleton().setGUISheet(sheet);

	

	
	
}


bool OgreRTCApplication::quit(const CEGUI::EventArgs &e)
{
    mShutDown = true;
    return true;
}





void OgreRTCApplication::update(float t)
{
	if(mWindow) {
		
		
		mRoot->renderOneFrame();
		
		



		static clock_t Tm = clock();
		clock_t tTm = clock();

		float t = (float)(tTm - Tm)/CLOCKS_PER_SEC;

		Tm = tTm;

		//std::cout << t << std::endl;
		//std::cout << MyNodes.size() << std::endl;
		
		int ttW = SleepTime - (int)(1000. * t); 
		if(ttW > 0)Sleep(ttW);
		

		if(po->Exec)
		{
			po->setFunc("ogre_loop");
			//CreatePyFunc(po, "ogre_loop");
			
		}


		
	}
	
	
}
 


void OgreRTCApplication::SetCameraPosition(float x, float y, float z)
{
	mCamera->setPosition(x, y, z);

    
}

void OgreRTCApplication::CameraYaw(float ang)
{
	mCamera->yaw(Ogre::Degree(ang));

	
	
}

void OgreRTCApplication::CameraRoll(float ang)
{
	mCamera->roll(Ogre::Degree(ang));

	
	
}

void OgreRTCApplication::CameraPitch(float ang)
{
	mCamera->pitch(Ogre::Degree(ang));

	
}

void OgreRTCApplication::SetCameraRotation(float r, float p, float y)
{
	SetCameraQuaternion(1,0,0,0);
	CameraRoll(r);
	CameraPitch(p);
	CameraYaw(y);
	
}

void OgreRTCApplication::SetCameraQuaternion(float w, float x, float y, float z)
{
	mCamera->setOrientation(Ogre::Quaternion(w,x,y,z));
}


MyGUI *OgreRTCApplication::CreateStaticText(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/StaticText", name);
	
	return label;
}

MyGUI *OgreRTCApplication::CreateQtStaticText(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/StaticText", name);
	return label;
}

bool OgreRTCApplication::BottonClickedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	
	SetCallScript(evt->window->getName().c_str(), "Clicked");

	
	return true;
}

void OgreRTCApplication::SetCallScript(const char* name, const char* type)
{
	std::string t_st = name;


	t_st += type;

	
	if(po->Exec)
	{
		PyGILState_STATE gilstate;
   
		gilstate = PyGILState_Ensure();


		bpy::object pfunc = po->getFunc("CEGUICallback");
		try
		{
			
			pfunc(t_st.c_str());

			

			
		}
		catch(const bpy::error_already_set&)
		{
			PyErr_Print();
		}
		PyGILState_Release(gilstate);
		//CreatePyFunc(po, t_st);
	}

	
}


MyGUI *OgreRTCApplication::CreateButton(const char* name)
{
	
	MyGUI *label = CreateGUI("TaharezLook/Button", name);
	label->window->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&OgreRTCApplication::BottonClickedHandler, this));
	return label;
}

MyGUI *OgreRTCApplication::CreateQtButton(const char* name)
{
	
	MyGUI *label = CreateQtGUI("TaharezLook/Button", name);
	label->window->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&OgreRTCApplication::BottonClickedHandler, this));
	return label;
}



MyGUI *OgreRTCApplication::CreateEditBox(const char* name)
{
	
	MyGUI *label = CreateGUI("TaharezLook/Editbox", name);
	//label->subscribeEvent(CEGUI::Window::EventKeyDown, CEGUI::Event::Subscriber(&OgreRTCApplication::GUIKeyDownHandler, this));
	//label->subscribeEvent(CEGUI::Window::EventKeyUp, CEGUI::Event::Subscriber(&OgreRTCApplication::GUIKeyUpHandler, this));
	return label;
}


MyGUI *OgreRTCApplication::CreateQtEditBox(const char* name)
{
	
	MyGUI *label = CreateQtGUI("TaharezLook/Editbox", name);
	
	return label;
}



MyGUI *OgreRTCApplication::CreateComboBox(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/Combobox", name);
	label->window->subscribeEvent(CEGUI::Combobox::EventListSelectionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ComboBoxChangedHandler, this));
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtComboBox(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/Combobox", name);
	label->window->subscribeEvent(CEGUI::Combobox::EventListSelectionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ComboBoxChangedHandler, this));

	return label;
	
}







MyGUI *OgreRTCApplication::CreateSlider(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/Slider", name);
	label->window->subscribeEvent(CEGUI::Slider::EventValueChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::SliderChangedHandler, this));
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtSlider(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/Slider", name);
	label->window->subscribeEvent(CEGUI::Slider::EventValueChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::SliderChangedHandler, this));
	return label;
	
}

MyGUI *OgreRTCApplication::CreateTitlebar(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/Titlebar", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtTitlebar(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/Titlebar", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateFrameWindow(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/FrameWindow", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtFrameWindow(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/FrameWindow", name);
	return label;
	
}



MyGUI *OgreRTCApplication::CreateVerticalScrollbar(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/VerticalScrollbar", name);
	label->window->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ScrollPosChangedHandler, this));
	
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtVerticalScrollbar(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/VerticalScrollbar", name);
	label->window->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ScrollPosChangedHandler, this));
	return label;
	
}

MyGUI *OgreRTCApplication::CreateHorizontalScrollbar(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/HorizontalScrollbar", name);
	label->window->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ScrollPosChangedHandler, this));
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtHorizontalScrollbar(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/HorizontalScrollbar", name);
	label->window->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ScrollPosChangedHandler, this));
	return label;
	
}




MyGUI *OgreRTCApplication::CreateProgressBar(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/ProgressBar", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtProgressBar(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/ProgressBar", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateMultiLineEditbox(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/MultiLineEditbox", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtMultiLineEditbox(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/MultiLineEditbox", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateListbox(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/Listbox", name);
	label->window->subscribeEvent(CEGUI::Listbox::EventSelectionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ListBoxChangedHandler, this));
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtListbox(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/Listbox", name);
	label->window->subscribeEvent(CEGUI::Listbox::EventSelectionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ListBoxChangedHandler, this));
	return label;
	
}

MyGUI *OgreRTCApplication::CreateComboDropList(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/ComboDropList", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtComboDropList(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/ComboDropList", name);
	return label;
	
}





MyGUI *OgreRTCApplication::CreateCheckbox(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/Checkbox", name);
	label->window->subscribeEvent(CEGUI::Checkbox::EventCheckStateChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::CheckedHandler, this));

	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtCheckbox(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/Checkbox", name);
	label->window->subscribeEvent(CEGUI::Checkbox::EventCheckStateChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::CheckedHandler, this));

	return label;
	
}

MyGUI *OgreRTCApplication::CreateRadioButton(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/RadioButton", name);
	label->window->subscribeEvent(CEGUI::RadioButton::EventSelectStateChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::RadioHandler, this));
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtRadioButton(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/RadioButton", name);
	label->window->subscribeEvent(CEGUI::RadioButton::EventSelectStateChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::RadioHandler, this));
	return label;
	
}



MyGUI *OgreRTCApplication::CreateTooltip(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/Tooltip", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtTooltip(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/Tooltip", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateItemListbox(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/ItemListbox", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtItemListbox(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/ItemListbox", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateListboxItem(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/ListboxItem", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtListboxItem(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/ListboxItem", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateSpinner(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/Spinner", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtSpinner(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/Spinner", name);
	return label;
	
}


MyGUI *OgreRTCApplication::CreateScrollablePane(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/ScrollablePane", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtScrollablePane(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/ScrollablePane", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateListHeaderSegment(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/ListHeaderSegment", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtListHeaderSegment(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/ListHeaderSegment", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateListHeader(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/ListHeader", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtListHeader(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/ListHeader", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateMultiColumnList(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/MultiColumnList", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtMultiColumnList(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/MultiColumnList", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateMenuItem(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/MenuItem", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtMenuItem(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/MenuItem", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateMenubar(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/Menubar", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtMenubar(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/Menubar", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreatePopupMenu(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/PopupMenu", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtPopupMenu(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/PopupMenu", name);
	return label;
	
}



MyGUI *OgreRTCApplication::CreateTabButtonPane(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/TabButtonPane", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtTabButtonPane(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/TabButtonPane", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateTabContentPane(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/TabContentPane", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtTabContentPane(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/TabContentPane", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateTabControl(const char* name)
{
	MyGUI *label = CreateGUI("TaharezLook/TabControl", name);
	return label;
	
}

MyGUI *OgreRTCApplication::CreateQtTabControl(const char* name)
{
	MyGUI *label = CreateQtGUI("TaharezLook/TabControl", name);
	return label;
	
}





bool OgreRTCApplication::SliderChangedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "SliderChanged");

	return true;
}


bool OgreRTCApplication::CheckedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "Checked");

	return true;
}
	
bool OgreRTCApplication::RadioHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "SelectionChanged");

	return true;
}

bool OgreRTCApplication::ListBoxChangedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
	SetCallScript(evt->window->getName().c_str(), "SelectionChanged");

	return true;
}

bool OgreRTCApplication::ComboBoxChangedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "SelectionChanged");

	return true;
}

bool OgreRTCApplication::ScrollPosChangedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "ScrollPosChanged");

	return true;
}

MyGUI *OgreRTCApplication::CreateGUI(const char* type, const char* name)
{
	MyGUI *label = new MyGUI();
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();


	label->window = wmgr.createWindow(type, name);
	label->window->setPosition(CEGUI::UVector2(CEGUI::UDim(0., 0),CEGUI::UDim(0.0, 0)));
	label->window->setSize(CEGUI::UVector2(CEGUI::UDim(1., 0), CEGUI::UDim(1., 0)));
	
	sheet->addChildWindow(label->window);

	label->type = type;
	label->name = name;

	MyGUIs.push_back(label);
	

	return label;
}

void OgreRTCApplication::CreateQtGUI(MyGUI *label)
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();

	Ogre::NodeAnimationTrack* track;
	label->window = wmgr.createWindow(label->type, label->name);
	label->window->setPosition(CEGUI::UVector2(CEGUI::UDim(0., 0),CEGUI::UDim(0.0, 0)));
	label->window->setSize(CEGUI::UVector2(CEGUI::UDim(1., 0), CEGUI::UDim(1., 0)));
	sheet->addChildWindow(label->window);

	label->SetPosition(label->pos_x, label->pos_y);
	label->SetRotatin(label->roll, label->pitch, label->yaw);
	label->SetSize(label->size_x, label->size_y);
	label->SetVisible(label->visi);
	if(label->type == "TaharezLook/StaticText" || label->type == "TaharezLook/Editbox")
	{
		label->SetText(label->text.c_str());
	}
	
	if(label->type == "TaharezLook/StaticImage")
	{
		
		if(label->image_set)
		{
			
			MyImageSet* ims = getImageSetByName(label->image_name.c_str());
			if(ims)
			{
				
				label->SetImage(ims,"full_image");
			}
		}
	}
	label->SetAlpha(label->alpha);

	if(label->type == "TaharezLook/StaticText")
	{
		if(label->text_type == 0)
		{
			label->SetTextTopAligned();
		}
		else if(label->text_type == 1)
		{
			label->SetTextBottomAligned();
		}
		else if(label->text_type == 2)
		{
			label->SetTextVertCentred();
		}
		else if(label->text_type == 3)
		{
			label->SetTextWordWrapLeftAligned();
		}
		else if(label->text_type == 4)
		{
			label->SetTextWordWrapRightAligned();
		}
		else if(label->text_type == 5)
		{
			label->SetTextWordWrapCentred();
		}
		else if(label->text_type == 6)
		{
			label->SetTextLeftAligned();
		}
		else if(label->text_type == 7)
		{
			label->SetTextRightAligned();
		}
		else if(label->text_type == 8)
		{
			label->SetTextHorzCentred();
		}
	}

	if(label->type == "TaharezLook/Button")
	{
		label->window->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&OgreRTCApplication::BottonClickedHandler, this));
	}
	else if(label->type == "TaharezLook/Slider")
	{
		label->window->subscribeEvent(CEGUI::Slider::EventValueChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::SliderChangedHandler, this));
	}


	MyGUIs.push_back(label);
}

MyGUI *OgreRTCApplication::CreateQtGUI(const char* type, const char* name)
{
	MyGUI *label = CreateGUI(type, name);
	QtGUIs.push_back(label);

	return label;
}




bool OgreRTCApplication::GUIKeyUpHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::KeyEventArgs* evt = static_cast<const CEGUI::KeyEventArgs*>(&event);
	//CEGUI::System &sys = CEGUI::System::getSingleton();
	//sys.injectKeyUp(evt->scancode);

	

	return true;
}
bool OgreRTCApplication::GUIKeyDownHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::KeyEventArgs* evt = static_cast<const CEGUI::KeyEventArgs*>(&event);

	CEGUI::System &sys = CEGUI::System::getSingleton();
	//sys.injectKeyDown(evt->scancode);
	sys.injectChar(evt->codepoint);
	//std::cout << evt->scancode << "\t" << evt->codepoint << std::endl;

	return true;
}

MyGUI *OgreRTCApplication::CreateStaticImage(const char* name)
{
	

	MyGUI *label = CreateGUI("TaharezLook/StaticImage", name);
	

	return label;

	
}

MyGUI *OgreRTCApplication::CreateQtStaticImage(const char* name)
{
	

	MyGUI *label = CreateQtGUI("TaharezLook/StaticImage", name);
	

	return label;

	
}

void OgreRTCApplication::Destroycegui(CEGUI::Window *label)
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	
	label->getParent()->removeChildWindow(label);
	wmgr.destroyWindow(label);
	
	
	
}

void OgreRTCApplication::DestroyGui(MyGUI *label)
{
	
	
		
	for(int j=0;j < MyGUIs.size();j++)
	{
		if(label->window->isChild(MyGUIs[j]->window->getName()))
		{
			DestroyGui(MyGUIs[j]);
			
			j = j - 1;
		}
	}
	
	Destroycegui(label->window);
	std::vector<MyGUI*>::iterator end_it = remove( MyGUIs.begin(), MyGUIs.end(), label );
	MyGUIs.erase( end_it, MyGUIs.end() );

	
}

void OgreRTCApplication::DestroyQtGui(MyGUI *label)
{
	for(int j=0;j < QtGUIs.size();j++)
	{
		if(label->window->isChild(QtGUIs[j]->window->getName()))
		{
			DestroyQtGui(QtGUIs[j]);
			j -= 1;
		}
	}
	
		
	

	DestroyGui(label);
	std::vector<MyGUI*>::iterator end_it = remove( QtGUIs.begin(), QtGUIs.end(), label );
	QtGUIs.erase( end_it, QtGUIs.end() );

	
}

void OgreRTCApplication::DestroyAllGUI()
{
	
	//for(int i=0;i < MyGUIs.size();i++)
	while(MyGUIs.size() > 0)
	{
		
		DestroyGui(MyGUIs[0]);
		//Destroycegui(MyGUIs[i]->window);
	}
	MyGUIs.clear();
}









myParticle *OgreRTCApplication::CreateParticle(const char* name, const char* file_name)
{
	myParticle *ml = new myParticle(name);
	ml->particleSystem = mSceneMgr->createParticleSystem(name, file_name);
	ml->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ml->mNode->mNode->attachObject(ml->particleSystem);
	ml->mNode->mNode->setPosition(Ogre::Vector3(0,0,0));

	MyNodes.push_back(ml->mNode);
	ml->mNode->AddObj(ml);
	myParticles.push_back(ml);


	
	ml->filename = file_name;

	return ml;


}

void OgreRTCApplication::CreateQtParticle(myParticle *ml)
{
	ml->particleSystem = mSceneMgr->createParticleSystem(ml->name, ml->filename);
	
	MyNode *mn = getNodeByName(ml->mNode->name.c_str());
	if(mn)
	{
		ml->mNode = mn;
	}
	else
	{
		ml->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	}
	ml->mNode->mNode->attachObject(ml->particleSystem);
	ml->mNode->AddObj(ml);
	
	ml->SetPosition(ml->mNode->pos_x, ml->mNode->pos_y, ml->mNode->pos_z);
	ml->SetScale(ml->mNode->scale_x, ml->mNode->scale_y, ml->mNode->scale_z);
	ml->SetRotation(ml->mNode->roll, ml->mNode->pitch, ml->mNode->yaw);
	ml->SetVisible(ml->mNode->visi);

	myParticles.push_back(ml);
}

myParticle *OgreRTCApplication::CreateQtParticle(const char* name, const char* file_name)
{
	myParticle *ml = CreateParticle(name, file_name);

	QtNodes.push_back(ml->mNode);
	QtParticles.push_back(ml);

	return ml;


}




void OgreRTCApplication::DestroyParticle(myParticle *ml)
{
	ml->mNode->mNode->detachObject(ml->particleSystem);
	mSceneMgr->destroyParticleSystem(ml->particleSystem);
	
	ml->mNode->RemoveObj(ml);
	DestroyNode(ml->mNode);

	std::vector<myParticle*>::iterator end_it = remove( myParticles.begin(), myParticles.end(), ml );
	myParticles.erase( end_it, myParticles.end() );

	
}

void OgreRTCApplication::DestroyQtParticle(myParticle *ml)
{
	DestroyParticle(ml);

	DestroyQtNode(ml->mNode);

	std::vector<myParticle*>::iterator end_it = remove( QtParticles.begin(), QtParticles.end(), ml );
	QtParticles.erase( end_it, QtParticles.end() );
}

void OgreRTCApplication::DestroyAllParticle()
{
	for(int i=0;i < myParticles.size();i++)
	{
		myParticles[i]->mNode->mNode->detachObject(myParticles[i]->particleSystem);
		mSceneMgr->destroyParticleSystem(myParticles[i]->particleSystem);
		myParticles[i]->mNode->RemoveObj(myParticles[i]);
		DestroyNode(myParticles[i]->mNode);
	}
	myParticles.clear();
}

MyLink *OgreRTCApplication::SetFloor(const char* name, const char* name2, const char* filename, int Size, int direction)
{
	if(Floor)
	{
		DestroyFloor();
	}
	
	Ogre::Vector3 DIR;
	if(direction == 0)
	{
		DIR = Ogre::Vector3::UNIT_X;
	}
	else if(direction == 1)
	{
		DIR = Ogre::Vector3::UNIT_Y;
	}
	else if(direction == 2)
	{
		DIR = Ogre::Vector3::UNIT_Z;
	}
	
	MyLink *link = new MyLink(name);

	link->mp = Ogre::MeshManager::getSingleton().createPlane(name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::Plane(DIR, 0), Size, Size, 10, 10, true, 1, 10, 10, Ogre::Vector3::UNIT_Y);

	
	
		

	link->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	

	
    link->mEntity = mSceneMgr->createEntity(name2, name);
    link->mEntity->setMaterialName(filename);
    link->mEntity->setCastShadows(false);
	link->mNode->mNode->attachObject(link->mEntity);

	
	link->filename = filename;
	link->dir = direction;
	link->size = Size;

	Floor = link;

	return link;
}

MyLink *OgreRTCApplication::SetQtFloor(const char* name, const char* name2, const char* filename, int Size, int direction)
{

	qtFloor = SetFloor(name, name2, filename, Size, direction);

	return qtFloor;
}

void OgreRTCApplication::RemoveSkyBox()
{
	mSceneMgr->destroySceneNode(mSceneMgr->getSkyBoxNode());
}


void OgreRTCApplication::SetSkyBox(const char* filename, int Size)
{
	mSceneMgr->setSkyBox(true, filename, Size);
	skyBoxName = filename;
	skyBoxSize = Size;

}

void OgreRTCApplication::SetQtSkyBox(const char* filename, int Size)
{
	SetSkyBox(filename, Size);
	QtskyBoxName = filename;
	QtskyBoxSize = Size;
}

MyImageSet *OgreRTCApplication::CreateGuiImageSet(const char* name, const char* filename)
{
	MyImageSet *MIS = new MyImageSet();
	//MIS->texture = &mRenderer->createTexture(filename,"Imagesets");
	//MIS->imageSet = &CEGUI::ImagesetManager::getSingleton().create(name,*MIS->texture);
	//MIS->imageSet->defineImage("Base",CEGUI::Point(0.0f,0.0f),CEGUI::Size(MIS->texture->getSize().d_width,MIS->texture->getSize().d_height),CEGUI::Point(0.0f,0.0f));
	std::string ext = filename;
	ext = GetExtension(ext);
	
	if(ext == "imageset")
	{
		MIS->imageSet = &CEGUI::ImagesetManager::getSingleton().create(filename);
	}
	else
	{
		MIS->imageSet = &CEGUI::ImagesetManager::getSingleton().createFromImageFile(name, filename);
	}
	MIS->name = name;
	MIS->filename = filename;
	MyImageSets.push_back(MIS);
	
	return MIS;
}


void OgreRTCApplication::CreateQtImage(MyImageSet *MIS)
{
	//MIS->texture = &mRenderer->createTexture(MIS->filename,"Imagesets");
	
	//MIS->imageSet = &CEGUI::ImagesetManager::getSingleton().create(MIS->name,*MIS->texture);
	//MIS->imageSet->defineImage("Base",CEGUI::Point(0.0f,0.0f),CEGUI::Size(MIS->texture->getSize().d_width,MIS->texture->getSize().d_height),CEGUI::Point(0.0f,0.0f));
	std::string ext = MIS->filename;
	ext = GetExtension(ext);
	if(ext == "imageset")
	{
		MIS->imageSet = &CEGUI::ImagesetManager::getSingleton().create(MIS->filename);
	}
	else
	{
		MIS->imageSet = &CEGUI::ImagesetManager::getSingleton().createFromImageFile(MIS->name, MIS->filename);
	}
	

	MyImageSets.push_back(MIS);
}


MyImageSet *OgreRTCApplication::CreateQtGuiImageSet(const char* name, const char* filename)
{
	MyImageSet *MIS = CreateGuiImageSet(name, filename);
	QtImageSets.push_back(MIS);
	
	return MIS;
}






void OgreRTCApplication::DestroyImage(MyImageSet *MIS)
{
	CEGUI::ImagesetManager::getSingleton().destroy(MIS->imageSet->getName());

	//mRenderer->destroyTexture(*MIS->texture);

	std::vector<MyImageSet*>::iterator end_it = remove( MyImageSets.begin(), MyImageSets.end(), MIS );
	MyImageSets.erase( end_it, MyImageSets.end() );
}

void OgreRTCApplication::DestroyQtImage(MyImageSet *MIS)
{
	DestroyImage(MIS);

	std::vector<MyImageSet*>::iterator end_it = remove( QtImageSets.begin(), QtImageSets.end(), MIS );
	QtImageSets.erase( end_it, QtImageSets.end() );
}

void OgreRTCApplication::DestroyAllImage()
{
	for(int i=0;i < MyImageSets.size();i++)
	{
		CEGUI::ImagesetManager::getSingleton().destroy(MyImageSets[i]->imageSet->getName());

		//mRenderer->destroyTexture(*MyImageSets[i]->texture);
	}

	MyImageSets.clear();

}


MyLink *OgreRTCApplication::SetBody(const char* n, const char* s)
{
	MyLink *link = new MyLink(n);
	{
		
		link->mEntity = mSceneMgr->createEntity(s);
		link->mEntity->setQueryFlags(1<<0);
		link->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		link->mEntity->setCastShadows(true);
		link->mNode->mNode->attachObject(link->mEntity);
		link->mNode->mNode->scale(Ogre::Vector3(1,1,1));
		link->mNode->mNode->setPosition(Ogre::Vector3(0,0,0));
	}
	
	
	link->filename = s;
	MyNodes.push_back(link->mNode);
	link->mNode->AddObj(link);
	MyLinks.push_back(link);

	return link;
}

void OgreRTCApplication::CreateQtBody(MyLink *link)
{
	link->mEntity = mSceneMgr->createEntity(link->filename);
	link->mEntity->setQueryFlags(1<<0);
	MyNode *mn = getNodeByName(link->mNode->name.c_str());
	if(mn)
	{
		link->mNode = mn;
	}
	else
	{
		link->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	}

	for(int i=0;i < link->NodeList.size();i++)
	{
		MyNode *mnl = getNodeByName(link->NodeList[i]->name.c_str());
		if(mnl)
		{
			link->NodeList[i] = mnl;
		}
		
	}
	
	link->mEntity->setCastShadows(true);
	link->mNode->mNode->attachObject(link->mEntity);
	link->mNode->AddObj(link);
	link->SetScale(link->mNode->scale_x,link->mNode->scale_y,link->mNode->scale_z);
	link->SetPosition(link->mNode->pos_x,link->mNode->pos_y,link->mNode->pos_z);
	link->SetRotation(link->mNode->roll,link->mNode->pitch,link->mNode->yaw);
	if(link->color_visi)
	{
		setEColor(link,link->red,link->green,link->blue,link->alpha);
	}
	link->SetVisible(link->mNode->visi);
	link->SetShadows(link->shadow_visi);

	if(link->mat_visi)
	{
		link->SetMaterial(link->material_name.c_str());
	}

	MyLinks.push_back(link);

	//link->name =link->mEntity->getName().c_str();
}


MyLink *OgreRTCApplication::SetQtBody(const char* n, const char* s)
{
	MyLink *link = SetBody(n,s);
	QtNodes.push_back(link->mNode);
	QtLinks.push_back(link);

	return link;
}

void OgreRTCApplication::DestroyFloor()
{
	Floor->mNode->mNode->detachObject(Floor->mEntity);
	mSceneMgr->destroyEntity(Floor->mEntity);

	mSceneMgr->destroySceneNode(Floor->mNode->mNode);

	Ogre::MeshManager::getSingleton().remove(Floor->mp.get()->getHandle());

	Floor = NULL;
}

void OgreRTCApplication::DestroyQtFloor()
{
	if(qtFloor)
	{
		DestroyFloor();

		qtFloor = NULL;
	}
}


void OgreRTCApplication::DestroyBody(MyLink *link)
{
	link->mNode->mNode->detachObject(link->mEntity);
	mSceneMgr->destroyEntity(link->mEntity);

	link->mNode->RemoveObj(link);
	DestroyNode(link->mNode);

	std::vector<MyLink*>::iterator end_it = remove( MyLinks.begin(), MyLinks.end(), link );
	MyLinks.erase( end_it, MyLinks.end() );

	
}


void OgreRTCApplication::DestroyQtBody(MyLink *link)
{
	DestroyBody(link);

	DestroyQtNode(link->mNode);

	std::vector<MyLink*>::iterator end_it = remove( QtLinks.begin(), QtLinks.end(), link );
	QtLinks.erase( end_it, QtLinks.end() );
}

void OgreRTCApplication::DestroyAllBody()
{
	for(int i=0;i < MyLinks.size();i++)
	{
		MyLinks[i]->mNode->mNode->detachObject(MyLinks[i]->mEntity);
		mSceneMgr->destroyEntity(MyLinks[i]->mEntity);

		MyLinks[i]->mNode->RemoveObj(MyLinks[i]);
		DestroyNode(MyLinks[i]->mNode);
	}

	MyLinks.clear();
}





void OgreRTCApplication::SetLightPosition(float x, float y, float z)
{
	light->setPosition(x, y, z);
	LightX = x;
	LightY = y;
	LightZ = z;
}

void OgreRTCApplication::SetShadowColour(float r, float g, float b)
{
	mSceneMgr->setShadowColour(Ogre::ColourValue(r, g, b));
	ShadowR = r;
	ShadowG = g;
	ShadowB = b;
}

void OgreRTCApplication::SetLightColor(float r, float g, float b)
{
	light->setDiffuseColour(r,g,b);
	LightR = r;
	LightG = g;
	LightB = b;
	//light->setSpecularColour(r,g,b);
}

SubWindow *OgreRTCApplication::SetSubWindow(const char* wName, const char* texName, const char* camName, const char* ImageSetName, const char* ImageName)
{
	
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();


	SubWindow *sw = new SubWindow();
	sw->Iname = ImageName;
	sw->Wname = wName;
	sw->ISname = ImageSetName;
	sw->Cname = camName;
	sw->Tname = texName;


	sw->label = wmgr.createWindow("TaharezLook/StaticImage", wName);
	
	sw->tex = mRoot->getTextureManager()->createManual(
		texName,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::TEX_TYPE_2D,
		512,
		512,
		0,
		Ogre::PF_R8G8B8,
		Ogre::TU_RENDERTARGET);
	sw->rtex = sw->tex->getBuffer()->getRenderTarget();


	

	sw->cam = mSceneMgr->createCamera(camName);
	sw->v = sw->rtex->addViewport(sw->cam);
	sw->v->setOverlaysEnabled(false);
	sw->v->setClearEveryFrame(true);
	sw->v->setBackgroundColour(Ogre::ColourValue::Black);



	sw->guiTex = &mRenderer->createTexture(sw->tex);

	sw->imageSet =
	&CEGUI::ImagesetManager::getSingleton().create(ImageSetName, *sw->guiTex);
	sw->imageSet->defineImage(ImageName,
		CEGUI::Point(0.0f, 0.0f),
		CEGUI::Size(sw->guiTex->getSize().d_width,
		sw->guiTex->getSize().d_height),
		CEGUI::Point(0.0f, 0.0f));

	sw->label->setProperty("Image", CEGUI::PropertyHelper::imageToString(&sw->imageSet->getImage(ImageName)));


	sheet->addChildWindow(sw->label);

	SubWindows.push_back(sw);

	return sw;
}

void OgreRTCApplication::CreateQtSubWindow(SubWindow *sw)
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();


	
	


	sw->label = wmgr.createWindow("TaharezLook/StaticImage", sw->Wname);
	
	sw->tex = mRoot->getTextureManager()->createManual(
		sw->Tname,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::TEX_TYPE_2D,
		512,
		512,
		0,
		Ogre::PF_R8G8B8,
		Ogre::TU_RENDERTARGET);
	sw->rtex = sw->tex->getBuffer()->getRenderTarget();


	

	sw->cam = mSceneMgr->createCamera(sw->Cname);
	sw->v = sw->rtex->addViewport(sw->cam);
	sw->v->setOverlaysEnabled(false);
	sw->v->setClearEveryFrame(true);
	sw->v->setBackgroundColour(Ogre::ColourValue::Black);



	sw->guiTex = &mRenderer->createTexture(sw->tex);

	sw->imageSet =
	&CEGUI::ImagesetManager::getSingleton().create(sw->ISname, *sw->guiTex);
	sw->imageSet->defineImage(sw->Iname,
		CEGUI::Point(0.0f, 0.0f),
		CEGUI::Size(sw->guiTex->getSize().d_width,
		sw->guiTex->getSize().d_height),
		CEGUI::Point(0.0f, 0.0f));

	sw->label->setProperty("Image", CEGUI::PropertyHelper::imageToString(&sw->imageSet->getImage(sw->Iname)));


	sheet->addChildWindow(sw->label);

	sw->SetPosition(sw->pos_x, sw->pos_y);
	sw->SetSize(sw->size_x, sw->size_y);
	sw->SetVisible(sw->visi);
	sw->UpdateCameraPQ(sw->campos_x,sw->campos_y,sw->campos_z,sw->cam_roll,sw->cam_pitch,sw->cam_yaw,sw->cam_len);

	SubWindows.push_back(sw);
}

SubWindow *OgreRTCApplication::SetQtSubWindow(const char* wName, const char* texName, const char* camName, const char* ImageSetName, const char* ImageName)
{
	SubWindow* sw = SetSubWindow(wName,texName,camName,ImageSetName,ImageName);
	QtSubWindows.push_back(sw);

	return sw;
}


void OgreRTCApplication::DestroySubWindow(SubWindow *sw)
{
	Destroycegui(sw->label);
	sw->imageSet->undefineImage(sw->Iname.c_str());
	mRenderer->destroyTexture(*sw->guiTex);
	
	mSceneMgr->destroyCamera(sw->cam->getName());

	CEGUI::ImagesetManager::getSingleton().destroy(sw->imageSet->getName());

	mRenderer->destroyTexture(*sw->guiTex);

	std::vector<SubWindow*>::iterator end_it = remove( SubWindows.begin(), SubWindows.end(), sw );
	SubWindows.erase( end_it, SubWindows.end() );
}

void OgreRTCApplication::DestroyQtSubWindow(SubWindow *sw)
{
	DestroySubWindow(sw);

	std::vector<SubWindow*>::iterator end_it = remove( QtSubWindows.begin(), QtSubWindows.end(), sw );
	QtSubWindows.erase( end_it, QtSubWindows.end() );

}

void OgreRTCApplication::DestroyAllSubWindow()
{
	for(int i=0;i < SubWindows.size();i++)
	{
		Destroycegui(SubWindows[i]->label);
		SubWindows[i]->imageSet->undefineImage(SubWindows[i]->Iname);
		mRenderer->destroyTexture(*SubWindows[i]->guiTex);
		
		mSceneMgr->destroyCamera(SubWindows[i]->cam->getName());

		CEGUI::ImagesetManager::getSingleton().destroy(SubWindows[i]->imageSet->getName());

		mRenderer->destroyTexture(*SubWindows[i]->guiTex);
	}
	SubWindows.clear();
}
void OgreRTCApplication::StopSubWindow(SubWindow *sw)
{
	sw->label->clearProperties();

	sw->imageSet->undefineImage(sw->Iname);
	mRenderer->destroyTexture(*sw->guiTex);
	
	mSceneMgr->destroyCamera(sw->Cname);

	CEGUI::ImagesetManager::getSingleton().destroy(sw->imageSet->getName());

	mRenderer->destroyTexture(*sw->guiTex);
}




void OgreRTCApplication::restartSubWindow(SubWindow *sw)
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();




	//sw.label = wmgr.createWindow("TaharezLook/StaticImage", sw.Wname);
	
	sw->tex = mRoot->getTextureManager()->createManual(
		sw->Tname,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::TEX_TYPE_2D,
		512,
		512,
		0,
		Ogre::PF_R8G8B8,
		Ogre::TU_RENDERTARGET);
	sw->rtex = sw->tex->getBuffer()->getRenderTarget();




	sw->cam = mSceneMgr->createCamera(sw->Cname);
	sw->v = sw->rtex->addViewport(sw->cam);
	sw->v->setOverlaysEnabled(false);
	sw->v->setClearEveryFrame(true);
	sw->v->setBackgroundColour(Ogre::ColourValue::Black);



	sw->guiTex = &mRenderer->createTexture(sw->tex);

	
	sw->imageSet =
	&CEGUI::ImagesetManager::getSingleton().create(sw->ISname, *sw->guiTex);
	sw->imageSet->defineImage(sw->Iname,
		CEGUI::Point(0.0f, 0.0f),
		CEGUI::Size(sw->guiTex->getSize().d_width,
		sw->guiTex->getSize().d_height),
		CEGUI::Point(0.0f, 0.0f));

	sw->label->setProperty("Image", CEGUI::PropertyHelper::imageToString(&sw->imageSet->getImage(sw->Iname)));


	//sheet->addChildWindow(sw.label);
}





void OgreRTCApplication::SetSleepTime(int st)
{
	SleepTime = st;
}








Ogre::Vector2 OgreRTCApplication::getRenderWindowSize()
{
	return Ogre::Vector2(mWindow->getWidth(), mWindow->getHeight());
}

MyLink* OgreRTCApplication::GetQueryScene(float screenX, float screenY)
{
	//static Ogre::Camera *cam = mSceneMgr->getCameraIterator().getNext();

	Ogre::Vector2 windowSize = getRenderWindowSize();
	Ogre::Ray mouseRay = mCamera->getCameraToViewportRay(
		screenX / windowSize.x, screenY / windowSize.y);

	mRayQuery->setRay(mouseRay);
	mRayQuery->setQueryMask(1<<0);

	Ogre::RaySceneQueryResult &result = mRayQuery->execute();
	Ogre::RaySceneQueryResult::iterator itr = result.begin();

	if (itr != result.end() && itr->movable) {
		Ogre::MovableObject *obj = itr->movable;
		
		for(int i=0;i < MyLinks.size();i++)
		{
			if(MyLinks[i]->mEntity->getName() == obj->getName())
			{
				return MyLinks[i];
			}
		}
		
	}

	return NULL;


}


std::string OgreRTCApplication::GetBodyName(MyLink *link)
{
	//return link.mNode->getName().c_str();
	return link->mEntity->getName().c_str();
}

void OgreRTCApplication::AddFileSystem(const char *name)
{
	std::stringstream ss;
	ss << "MyFile" << FileSystems.size();
	Ogre::ResourceGroupManager::getSingleton().createResourceGroup(ss.str().c_str());
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, "FileSystem",ss.str().c_str());
	Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup(ss.str().c_str());
	FileSystems.push_back(name);
}


MyAnimation *OgreRTCApplication::CreateAnimation(const char* name, float t)
{
	MyAnimation *man = new MyAnimation(name);
	man->anim = mSceneMgr->createAnimation(name, t);
	man->anim->setInterpolationMode(Ogre::Animation::IM_SPLINE);

	man->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	man->track = man->anim->createNodeTrack(1, man->mNode->mNode);

	man->mstate = mSceneMgr->createAnimationState(name);
	man->mstate->setEnabled(true);

	MyNodes.push_back(man->mNode);
	man->mNode->AddObj(man);
	MyAnimations.push_back(man);


	
	man->Time = t;

	return man;
}
MyAnimation *OgreRTCApplication::CreateQtAnimation(const char* name, float t)
{
	MyAnimation *man = CreateAnimation(name, t);
	QtNodes.push_back(man->mNode);
	QtAnimations.push_back(man);

	return man;
}
void OgreRTCApplication::CreateQtAnimation(MyAnimation *man)
{
	man->anim = mSceneMgr->createAnimation(man->name, man->Time);
	man->anim->setInterpolationMode(Ogre::Animation::IM_SPLINE);

	MyNode *mn = getNodeByName(man->mNode->name.c_str());
	if(mn)
	{
		man->mNode = mn;
	}
	else
	{
		man->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	}
	man->track = man->anim->createNodeTrack(1, man->mNode->mNode);
	man->mNode->AddObj(man);

	man->mstate = mSceneMgr->createAnimationState(man->name);
	man->mstate->setEnabled(true);

	for(int i=0;i < man->animList.size();i++)
	{
		man->animList[i]->kf = man->track->createNodeKeyFrame(man->animList[i]->mtime);
		
		if(man->animList[i]->trans_flag)
		{
			man->animList[i]->setTranslate(man->animList[i]->px,man->animList[i]->py,man->animList[i]->pz);
			
		}
		if(man->animList[i]->rot_flag)
		{
			
			man->animList[i]->setRotation(man->animList[i]->roll,man->animList[i]->pitch,man->animList[i]->yaw);
		}
	}

	MyAnimations.push_back(man);
}
void OgreRTCApplication::DestroyAnimation(MyAnimation *man)
{
	mSceneMgr->destroyAnimation(man->anim->getName());
	
	
	man->mNode->RemoveObj(man);
	DestroyNode(man->mNode);

	std::vector<MyAnimation*>::iterator end_it = remove( MyAnimations.begin(), MyAnimations.end(), man );
	MyAnimations.erase( end_it, MyAnimations.end() );
}
void OgreRTCApplication::DestroyQtAnimation(MyAnimation *man)
{
	DestroyAnimation(man);
	DestroyQtNode(man->mNode);

	std::vector<MyAnimation*>::iterator end_it = remove( QtAnimations.begin(), QtAnimations.end(), man );
	QtAnimations.erase( end_it, QtAnimations.end() );
}
void OgreRTCApplication::DestroyAllAnimation()
{
	for(int i=0;i < MyAnimations.size();i++)
	{
		mSceneMgr->destroyAnimation(MyAnimations[i]->anim->getName());
		
		MyAnimations[i]->mNode->RemoveObj(MyAnimations[i]);
		DestroyNode(MyAnimations[i]->mNode);
	}
	MyAnimations.clear();
}


MyLight *OgreRTCApplication::CreateLight(const char* name)
{
	MyLight *ml = new MyLight(name);
	
	ml->light = mSceneMgr->createLight();
	ml->light->setType(Ogre::Light::LT_POINT);
	ml->light->setSpecularColour(Ogre::ColourValue::White);

	ml->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ml->mNode->mNode->setPosition(Ogre::Vector3(0,0,0));
	ml->mNode->mNode->attachObject(ml->light);

	MyNodes.push_back(ml->mNode);
	ml->mNode->AddObj(ml);
	MyLights.push_back(ml);

	

	return ml;
}
MyLight *OgreRTCApplication::CreateQtLight(const char* name)
{
	MyLight *ml = CreateLight(name);

	QtNodes.push_back(ml->mNode);
	QtLights.push_back(ml);
	return ml;
}
void OgreRTCApplication::CreateQtLight(MyLight *ml)
{
	ml->light = mSceneMgr->createLight();
	ml->light->setType(Ogre::Light::LT_POINT);

	MyNode *mn = getNodeByName(ml->mNode->name.c_str());
	if(mn)
	{
		ml->mNode = mn;
	}
	else
	{
		ml->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	}
	ml->mNode->mNode->attachObject(ml->light);
	ml->mNode->AddObj(ml);

	ml->SetPosition(ml->mNode->pos_x, ml->mNode->pos_y, ml->mNode->pos_z);
	ml->setColor(ml->red, ml->green, ml->blue);
	ml->SetVisible(ml->mNode->visi);

	MyLights.push_back(ml);

}
void OgreRTCApplication::DestroyLight(MyLight *ml)
{
	ml->mNode->mNode->detachObject(ml->light);
	mSceneMgr->destroyLight(ml->light);
	
	ml->mNode->RemoveObj(ml);
	DestroyNode(ml->mNode);


	
	std::vector<MyLight*>::iterator end_it = remove( MyLights.begin(), MyLights.end(), ml );
	MyLights.erase( end_it, MyLights.end() );
}
void OgreRTCApplication::DestroyQtLight(MyLight *ml)
{
	DestroyLight(ml);
	DestroyQtNode(ml->mNode);
	std::vector<MyLight*>::iterator end_it = remove( QtLights.begin(), QtLights.end(), ml );
	QtLights.erase( end_it, QtLights.end() );
}
void OgreRTCApplication::DestroyAllLight()
{
	for(int i=0;i < MyLights.size();i++)
	{
		MyLights[i]->mNode->mNode->detachObject(MyLights[i]->light);
		mSceneMgr->destroyLight(MyLights[i]->light);
		MyLights[i]->mNode->RemoveObj(MyLights[i]);
		DestroyNode(MyLights[i]->mNode);
	}
	MyLights.clear();
}

MyLight* OgreRTCApplication::getLightByName(const char* name)
{
	for(int i=0;i < MyLights.size();i++)
	{
		if(MyLights[i]->name == name)
		{
			return MyLights[i];
		}
	}
	return NULL;
}
MyAnimation* OgreRTCApplication::getAnimationByName(const char* name)
{
	for(int i=0;i < MyAnimations.size();i++)
	{
		if(MyAnimations[i]->name == name)
		{
			return MyAnimations[i];
		}
	}
	return NULL;
}


void OgreRTCApplication::AttachObj(MyLink *obj1, myParticle *obj2)
{
	AttachObj(obj2, obj2->particleSystem, obj1);
}
void OgreRTCApplication::AttachObj(MyLink *obj1, MyLight *obj2)
{
	AttachObj(obj2, obj2->light, obj1);
}
void OgreRTCApplication::AttachObj(myParticle *obj1, MyLight *obj2)
{
	AttachObj(obj2, obj2->light, obj1);
}
void OgreRTCApplication::AttachObj(MyLink *obj1, MyLink *obj2)
{
	AttachObj(obj2, obj2->mEntity, obj1);
}
void OgreRTCApplication::AttachObj(myParticle *obj1, myParticle *obj2)
{
	AttachObj(obj2, obj2->particleSystem, obj1);
}
void OgreRTCApplication::AttachObj(MyLight *obj1, MyLight *obj2)
{
	AttachObj(obj2, obj2->light, obj1);
}
void OgreRTCApplication::AttachObj(MyAnimation *obj1, MyLink *obj2)
{
	AttachObj(obj2, obj2->mEntity, obj1);
}
void OgreRTCApplication::AttachObj(MyAnimation *obj1, MyLight *obj2)
{
	AttachObj(obj2, obj2->light, obj1);
}
void OgreRTCApplication::AttachObj(MyAnimation *obj1, myParticle *obj2)
{
	AttachObj(obj2, obj2->particleSystem, obj1);
}


void OgreRTCApplication::AttachObj(MyObject *n1, Ogre::MovableObject *o1,MyObject *n2)
{
	if(n1->mNode != n2->mNode)
	{
		n1->mNode->mNode->detachObject(o1);
		n1->mNode->RemoveObj(n1);
		DestroyNode(n1->mNode);
		DestroyQtNode(n1->mNode);
		
		n2->mNode->mNode->attachObject(o1);
		n2->mNode->AddObj(n1);
		n1->mNode = n2->mNode;
	}
}



void OgreRTCApplication::DeatachObj(MyLink *obj1)
{
	DeatachObj(obj1, obj1->mEntity);
}
void OgreRTCApplication::DeatachObj(myParticle *obj1)
{
	DeatachObj(obj1, obj1->particleSystem);
}
void OgreRTCApplication::DeatachObj(MyLight *obj1)
{
	DeatachObj(obj1, obj1->light);
}
void OgreRTCApplication::DeatachObj(MyObject *n1, Ogre::MovableObject *o1)
{
	static int Dn = 0;
	if(n1->mNode->mobj.size() > 1)
	{
		n1->mNode->mNode->detachObject(o1);
		n1->mNode->RemoveObj(n1);
		std::stringstream ss;
		ss << "DeatachObj" << Dn;
		n1->mNode = new MyNode(ss.str());

		n1->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		n1->mNode->mNode->attachObject(o1);
		n1->mNode->AddObj(n1);

		MyNodes.push_back(n1->mNode);
		QtNodes.push_back(n1->mNode);
	}
}

MyNode* OgreRTCApplication::getNodeByName(const char* name)
{
	for(int i=0;i < MyNodes.size();i++)
	{
		if(MyNodes[i]->name == name)
		{
			return MyNodes[i];
		}
	}
	return NULL;
}

void OgreRTCApplication::CreateQtNode(MyNode *mn)
{
	mn->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	
}

void OgreRTCApplication::DestroyNode(MyNode *mn)
{
	
	if(mn->mobj.size() == 0)
	{
		mSceneMgr->destroySceneNode(mn->mNode);
		std::vector<MyNode*>::iterator end_it = remove( MyNodes.begin(), MyNodes.end(), mn );
		MyNodes.erase( end_it, MyNodes.end() );
	}
	
}

void OgreRTCApplication::DestroyQtNode(MyNode *mn)
{
	if(mn->mobj.size() == 0)
	{
		std::vector<MyNode*>::iterator end_it = remove( QtNodes.begin(), QtNodes.end(), mn );
		QtNodes.erase( end_it, QtNodes.end() );
	}
	
}


void OgreRTCApplication::DestroyAllNode()
{
	for(int i=0;i < MyNodes.size();i++)
	{
		MyNodes[i]->mNode->detachAllObjects();
		mSceneMgr->destroySceneNode(MyNodes[i]->mNode);
	}
	MyNodes.clear();
}


void OgreRTCApplication::CreateODEObj(MyLink *obj)
{
	obj->mEntity = mSceneMgr->createEntity(obj->filename);
	obj->mEntity->setQueryFlags(1<<0);
	MyNode *mn = getNodeByName(obj->mNode->name.c_str());
	if(mn)
	{
		obj->mNode = mn;
	}
	else
	{
		obj->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	}
	for(int i=0;i < obj->NodeList.size();i++)
	{
		MyNode *mnl = getNodeByName(obj->NodeList[i]->name.c_str());
		if(mnl)
		{
			obj->NodeList[i] = mnl;
		}
		
	}
	obj->mEntity->setCastShadows(true);
	obj->mNode->mNode->attachObject(obj->mEntity);
	obj->mNode->mNode->scale(Ogre::Vector3(1,1,1));
	obj->mNode->mNode->setPosition(Ogre::Vector3(0,0,0));
	
	
	
	MyNodes.push_back(obj->mNode);
	obj->mNode->AddObj(obj);
}



void OgreRTCApplication::DestroyODEObj(MyLink *obj)
{
	obj->mNode->mNode->detachObject(obj->mEntity);
	mSceneMgr->destroyEntity(obj->mEntity);

	obj->mNode->RemoveObj(obj);
	DestroyNode(obj->mNode);

}


void OgreRTCApplication::save(std::string s)
{
	std::ofstream ofs2(s.c_str(), ios_base::out | ios_base::trunc | ios_base::binary );
	if(!ofs2)return;

	int NodeNum = QtNodes.size();
	ofs2.write( (char*)&NodeNum, sizeof(NodeNum) );
	for(int i=0;i < NodeNum;i++)
	{
		QtNodes[i]->save(ofs2);
	}

	mSim->save(ofs2);

	int BodyNum = QtLinks.size();
	ofs2.write( (char*)&BodyNum, sizeof(BodyNum) );
	for(int i=0;i < BodyNum;i++)
	{
		QtLinks[i]->save(ofs2);
	}

	int ParticleNum = QtParticles.size();
	ofs2.write( (char*)&ParticleNum, sizeof(ParticleNum) );
	for(int i=0;i < ParticleNum;i++)
	{
		QtParticles[i]->save(ofs2);
	}

	int ImageNum = QtImageSets.size();
	ofs2.write( (char*)&ImageNum, sizeof(ImageNum) );
	for(int i=0;i < ImageNum;i++)
	{
		QtImageSets[i]->save(ofs2);
	}

	int GUINum = QtGUIs.size();
	ofs2.write( (char*)&GUINum, sizeof(GUINum) );
	for(int i=0;i < GUINum;i++)
	{
		QtGUIs[i]->save(ofs2);
	}


	int SubWindowNum = QtSubWindows.size();
	ofs2.write( (char*)&SubWindowNum, sizeof(SubWindowNum) );
	for(int i=0;i < SubWindowNum;i++)
	{
		QtSubWindows[i]->save(ofs2);
	}

	int AnimNum = QtAnimations.size();
	ofs2.write( (char*)&AnimNum, sizeof(AnimNum) );
	for(int i=0;i < AnimNum;i++)
	{
		QtAnimations[i]->save(ofs2);
	}

	int LightNum = QtLights.size();
	ofs2.write( (char*)&LightNum, sizeof(LightNum) );
	for(int i=0;i < LightNum;i++)
	{
		QtLights[i]->save(ofs2);
	}


	ofs2.write( (char*)&CamX, sizeof(CamX) );
	ofs2.write( (char*)&CamY, sizeof(CamY) );
	ofs2.write( (char*)&CamZ, sizeof(CamZ) );

	ofs2.write( (char*)&CamRoll, sizeof(CamRoll) );
	ofs2.write( (char*)&CamPitch, sizeof(CamPitch) );
	ofs2.write( (char*)&CamYaw, sizeof(CamYaw) );

	ofs2.write( (char*)&CamLen, sizeof(CamLen) );

	ofs2.write( (char*)&LightX, sizeof(LightX) );
	ofs2.write( (char*)&LightY, sizeof(LightY) );
	ofs2.write( (char*)&LightZ, sizeof(LightZ) );

	ofs2.write( (char*)&ShadowR, sizeof(ShadowR) );
	ofs2.write( (char*)&ShadowG, sizeof(ShadowG) );
	ofs2.write( (char*)&ShadowB, sizeof(ShadowB) );

	if(qtFloor)
	{
		bool tmp = true;
		ofs2.write( (char*)&tmp, sizeof(tmp) );
		WriteString(qtFloor->filename , ofs2 );
		ofs2.write( (char*)&qtFloor->size, sizeof(qtFloor->size) );
		ofs2.write( (char*)&qtFloor->dir, sizeof(qtFloor->dir) );
	}
	else
	{
		bool tmp = false;
		ofs2.write( (char*)&tmp, sizeof(tmp) );
	}

	if(QtskyBoxName == "")
	{
		bool tmp = false;
		ofs2.write( (char*)&tmp, sizeof(tmp) );
	}
	else
	{
		bool tmp = true;
		ofs2.write( (char*)&tmp, sizeof(tmp) );
		WriteString(QtskyBoxName , ofs2 );
		ofs2.write( (char*)&QtskyBoxSize, sizeof(QtskyBoxSize) );

	}
}
bool OgreRTCApplication::openb(std::string s)
{
	std::ifstream ifs( s.c_str() , ios::in | ios::binary );
	if(!ifs)return false;
	
	newfile();

	int NodeNum;
	ifs.read( (char*)&NodeNum, sizeof(NodeNum) );
	for(int i=0;i < NodeNum;i++)
	{
		MyNode *mn = new MyNode("");
		mn->openb(ifs);
		CreateQtNode(mn);
		QtNodes.push_back(mn);
		MyNodes.push_back(mn);
	}

	mSim->openb(ifs);
	

	int BodyNum;
	ifs.read( (char*)&BodyNum, sizeof(BodyNum) );
	for(int i=0;i < BodyNum;i++)
	{
		MyLink *ml = new MyLink("");
		ml->openb(ifs);
		CreateQtBody(ml);
		QtLinks.push_back(ml);
		MyLinks.push_back(ml);
	}

	int ParticleNum;
	ifs.read( (char*)&ParticleNum, sizeof(ParticleNum) );
	for(int i=0;i < ParticleNum;i++)
	{
		myParticle *mp = new myParticle("");
		mp->openb(ifs);
		CreateQtParticle(mp);
		QtParticles.push_back(mp);
		myParticles.push_back(mp);
	}

	int ImageNum;
	ifs.read( (char*)&ImageNum, sizeof(ImageNum) );
	for(int i=0;i < ImageNum;i++)
	{
		MyImageSet *mi = new MyImageSet();
		mi->openb(ifs);
		CreateQtImage(mi);
		QtImageSets.push_back(mi);
		MyImageSets.push_back(mi);
	}
	
	int GUINum;
	ifs.read( (char*)&GUINum, sizeof(GUINum) );
	for(int i=0;i < GUINum;i++)
	{
		MyGUI *mg = new MyGUI();
		mg->openb(ifs);
		CreateQtGUI(mg);
		QtGUIs.push_back(mg);
		MyGUIs.push_back(mg);
	}

	

	int SubWindowNum;
	ifs.read( (char*)&SubWindowNum, sizeof(SubWindowNum) );
	for(int i=0;i < SubWindowNum;i++)
	{
		SubWindow *sw = new SubWindow();
		sw->openb(ifs);
		CreateQtSubWindow(sw);
		QtSubWindows.push_back(sw);
		SubWindows.push_back(sw);
	}

	int AnimNum;
	ifs.read( (char*)&AnimNum, sizeof(AnimNum) );
	for(int i=0;i < AnimNum;i++)
	{
		MyAnimation *man = new MyAnimation("");
		man->openb(ifs);
		CreateQtAnimation(man);
		QtAnimations.push_back(man);
		MyAnimations.push_back(man);
	}


	int LightNum;
	ifs.read( (char*)&LightNum, sizeof(LightNum) );
	for(int i=0;i < LightNum;i++)
	{
		MyLight *ml = new MyLight("");
		ml->openb(ifs);
		CreateQtLight(ml);
		QtLights.push_back(ml);
		MyLights.push_back(ml);
	}


	

	float cx, cy, cz;
	float croll, cpitch, cyaw;
	float len;
	float lx, ly, lz;
	float sr, sg, sb;
	
	ifs.read( (char*)&cx, sizeof(cx) );
	ifs.read( (char*)&cy, sizeof(cy) );
	ifs.read( (char*)&cz, sizeof(cz) );

	ifs.read( (char*)&croll, sizeof(croll) );
	ifs.read( (char*)&cpitch, sizeof(cpitch) );
	ifs.read( (char*)&cyaw, sizeof(cyaw) );

	ifs.read( (char*)&len, sizeof(len) );

	UpdateCameraPQ(cx,cy,cz,croll,cpitch,cyaw,len);

	ifs.read( (char*)&lx, sizeof(lx) );
	ifs.read( (char*)&ly, sizeof(ly) );
	ifs.read( (char*)&lz, sizeof(lz) );

	SetLightPosition(lx, ly, lz);

	ifs.read( (char*)&sr, sizeof(sr) );
	ifs.read( (char*)&sg, sizeof(sg) );
	ifs.read( (char*)&sb, sizeof(sb) );

	SetShadowColour(sr, sg, sb);

	bool f_flag;

	ifs.read( (char*)&f_flag, sizeof(f_flag) );

	

	if(f_flag)
	{
		std::string f_name = ReadString(ifs);
		//std::cout << f_name << std::endl;
		int f_size;
		ifs.read( (char*)&f_size, sizeof(f_size) );
		//std::cout << f_size << std::endl;
		int f_dir;
		ifs.read( (char*)&f_dir, sizeof(f_dir) );
		//std::cout << f_dir << std::endl;

		std::string name1 = "Floor";
		std::string name2 = "floor";

		

		
		SetQtFloor(name1.c_str(), name2.c_str(), f_name.c_str(), f_size, f_dir);

		
	}

	bool s_flag;

	ifs.read( (char*)&s_flag, sizeof(s_flag) );

	if(s_flag)
	{
		std::string s_name = ReadString(ifs);
		int s_size;
		ifs.read( (char*)&s_size, sizeof(s_size) );

		SetQtSkyBox(s_name.c_str(), s_size);
	}

	return true;
}
bool OgreRTCApplication::newfile()
{
	mSim->DestroyAll();
	DestroyAllBody();
	DestroyAllGUI();
	
	DestroyAllParticle();
	DestroyAllSubWindow();
	DestroyAllLight();
	DestroyAllAnimation();
	DestroyAllNode();
	DestroyAllImage();

	DestroyQtFloor();

	mSim->QtJoints.clear();
	mSim->QtLinks.clear();
	QtLinks.clear();
	QtGUIs.clear();
	QtParticles.clear();
	QtSubWindows.clear();
	QtImageSets.clear();
	QtLights.clear();
	QtAnimations.clear();
	QtNodes.clear();

	return true;
}
void OgreRTCApplication::reset()
{
	mSim->DestroyAll();
	DestroyAllBody();
	DestroyAllGUI();
	DestroyAllParticle();
	DestroyAllSubWindow();
	DestroyAllImage();
	DestroyAllLight();
	DestroyAllAnimation();
	DestroyAllNode();

	
	for(int i=0;i < QtNodes.size();i++)
	{
		CreateQtNode(QtNodes[i]);
	}
	for(int i=0;i < mSim->QtLinks.size();i++)
	{
		
		if(mSim->QtLinks[i]->BodyType == 0)
		{
			mSim->SetQtSphere(mSim->QtLinks[i]);
		}
		else if(mSim->QtLinks[i]->BodyType == 1)
		{
			mSim->SetQtBox(mSim->QtLinks[i]);
		}
		else if(mSim->QtLinks[i]->BodyType == 2)
		{
			mSim->SetQtSylinder(mSim->QtLinks[i]);
		}
		else if(mSim->QtLinks[i]->BodyType == 3)
		{
			mSim->SetQtCapsule(mSim->QtLinks[i]);
		}
		
	}

	for(int i=0;i < mSim->QtJoints.size();i++)
	{
		if(mSim->QtJoints[i]->JointType == 0)
		{
			mSim->SetQtSliderJoint(mSim->QtJoints[i]);
		}
		else if(mSim->QtJoints[i]->JointType == 1)
		{
			mSim->SetQtFixJoint(mSim->QtJoints[i]);
		}
		else if(mSim->QtJoints[i]->JointType == 2)
		{
			mSim->SetQtHingeJoint(mSim->QtJoints[i]);
		}
		
		
		
	}
	for(int i=0;i < QtAnimations.size();i++)
	{
		CreateQtAnimation(QtAnimations[i]);
	}
	for(int i=0;i < QtLinks.size();i++)
	{
		CreateQtBody(QtLinks[i]);
	}
	for(int i=0;i < QtParticles.size();i++)
	{
		CreateQtParticle(QtParticles[i]);
	}
	for(int i=0;i < QtImageSets.size();i++)
	{
		CreateQtImage(QtImageSets[i]);
	}
	for(int i=0;i < QtGUIs.size();i++)
	{
		CreateQtGUI(QtGUIs[i]);
	}
	for(int i=0;i < QtSubWindows.size();i++)
	{
		CreateQtSubWindow(QtSubWindows[i]);
	}
	for(int i=0;i < QtLights.size();i++)
	{
		CreateQtLight(QtLights[i]);
	}
	if(qtFloor)
	{
		std::string name1 = "Floor";
		std::string name2 = "floor";

		SetQtFloor(name1.c_str(), name2.c_str(), qtFloor->filename.c_str(), qtFloor->size, qtFloor->dir);
	
	}
	if(QtskyBoxName != "")
	{
		SetQtSkyBox(QtskyBoxName.c_str(), QtskyBoxSize);
	}
}

void OgreRTCApplication::SetRTC()
{
	RTCFlag = true;
}