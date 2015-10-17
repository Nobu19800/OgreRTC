/*!
 * @file  OgreRTCApplication.cpp
 * @brief Ogre3Dのレンダリング管理クラス
 *
 */

#include "OgreRTCApplication.h"

#ifdef _WIN32
#include "UnicodeF.h"
#else
#endif






#include <iostream>

#include <fstream>

#include <coil/Time.h>
#include <coil/stringutil.h>

using namespace std;
namespace bpy = boost::python;








#ifdef _MSC_VER
#pragma warning(disable:4244 4305)  // for VC++, no precision loss complaints
#endif








int str_size;













/**
*@brief 3Dモデルの色の設定の関数
* @param ml ボディオブジェクト
* @param r 輝度(赤)
* @param g 輝度(緑)
* @param b 輝度(青)
* @param a 透明度
*/
void OgreRTCApplication::setEColor(LinkObj *ml, float r, float g, float b, float a){
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
			.def("DeatachObj",(void(OgreRTCApplication:: *)(LinkObj *))&OgreRTCApplication::DeatachObj)
			.def("DeatachObj",(void(OgreRTCApplication:: *)(ParticleObj *))&OgreRTCApplication::DeatachObj)
			.def("DeatachObj",(void(OgreRTCApplication:: *)(LightObj *))&OgreRTCApplication::DeatachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(LinkObj *, ParticleObj *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(LinkObj *, LightObj *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(ParticleObj *, LightObj *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(LinkObj *, LinkObj *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(ParticleObj *, ParticleObj *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(LightObj *, LightObj *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(AnimationObj *, LinkObj *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(AnimationObj *, LightObj *))&OgreRTCApplication::AttachObj)
			.def("AttachObj",(void(OgreRTCApplication:: *)(AnimationObj *, ParticleObj *))&OgreRTCApplication::AttachObj)
			.def("save",&OgreRTCApplication::save)
			.def("openb",&OgreRTCApplication::openb)
			.def("newfile",&OgreRTCApplication::newfile)
			.def("reset",&OgreRTCApplication::reset)
			.def("SetRTC",&OgreRTCApplication::SetRTC)
			.def("setDisplayImage",&OgreRTCApplication::setDisplayImage)
			.def("SetCameraAutoMoveFlag",&OgreRTCApplication::SetCameraAutoMoveFlag)
			.def("SetLightPosition",&OgreRTCApplication::SetLightPosition)
			.def("loadFont",&OgreRTCApplication::loadFont)
			;
			
			
			bpy::class_<ObjectBase>("ObjectBase")
			.def("SetPosition",&ObjectBase::SetPosition)
			.def("SetScale",&ObjectBase::SetScale)
			.def("Roll",&ObjectBase::Roll)
			.def("Pitch",&ObjectBase::Pitch)
			.def("Yaw",&ObjectBase::Yaw)
			.def("SetQuaternion",&ObjectBase::SetQuaternion)
			.def("SetVisible",&ObjectBase::SetVisible)
			.def("BoundingBoxVisible",&ObjectBase::BoundingBoxVisible)
			;

			

			bpy::class_<LinkObj>("LinkObj",bpy::init<std::string>())
			.def("SetAnimation",&LinkObj::SetAnimation)
			.def("ResetAnimation",&LinkObj::ResetAnimation)
			.def("UpdateAnimation",&LinkObj::UpdateAnimation)
			.def("SetShadows",&LinkObj::SetShadows)
			.def("SetBornPosition",(void(LinkObj:: *)(const char *, float, float, float))&LinkObj::SetBornPosition)
			.def("SetBornOrientation",(void(LinkObj:: *)(const char *, float, float, float, float))&LinkObj::SetBornOrientation)
			.def("SetBornRotation",(void(LinkObj:: *)(const char *, float, float, float))&LinkObj::SetBornRotation)
			.def("SetBornScale",(void(LinkObj:: *)(const char *, float, float, float))&LinkObj::SetBornScale)
			.def("SetBornRoll",(void(LinkObj:: *)(const char *, float))&LinkObj::SetBornRoll)
			.def("SetBornPitch",(void(LinkObj:: *)(const char *, float))&LinkObj::SetBornPitch)
			.def("SetBornYaw",(void(LinkObj:: *)(const char *, float))&LinkObj::SetBornYaw)
			.def("GetBornNum",&LinkObj::GetBornNum)
			.def("ResetBorn",&LinkObj::ResetBorn)
			.def("SetBornPosition",(void(LinkObj:: *)(int, float, float, float))&LinkObj::SetBornPosition)
			.def("SetBornOrientation",(void(LinkObj:: *)(int, float, float, float, float))&LinkObj::SetBornOrientation)
			.def("SetBornRotation",(void(LinkObj:: *)(int, float, float, float))&LinkObj::SetBornRotation)
			.def("SetBornScale",(void(LinkObj:: *)(int, float, float, float))&LinkObj::SetBornScale)
			.def("SetBornRoll",(void(LinkObj:: *)(int , float))&LinkObj::SetBornRoll)
			.def("SetBornPitch",(void(LinkObj:: *)(int , float))&LinkObj::SetBornPitch)
			.def("SetBornYaw",(void(LinkObj:: *)(int , float))&LinkObj::SetBornYaw)
			//.def("BoundingBoxVisible",&LinkObj::BoundingBoxVisible)
			.def("GetBoundingBoxSize",&LinkObj::GetBoundingBoxSize)
			.def("SetPosition",&LinkObj::SetPosition)
			.def("SetScale",&LinkObj::SetScale)
			.def("Roll",&LinkObj::Roll)
			.def("Pitch",&LinkObj::Pitch)
			.def("Yaw",&LinkObj::Yaw)
			.def("SetQuaternion",&LinkObj::SetQuaternion)
			.def("SetRotation",&LinkObj::SetRotation)
			.def("SetVisible",&LinkObj::SetVisible)
			.def("BoundingBoxVisible",&LinkObj::BoundingBoxVisible)

			;

			bpy::class_<GUIObj>("CEGUIWindow")
			.def("SetPosition",&GUIObj::SetPosition)
			.def("SetSize",&GUIObj::SetSize)
			.def("SetText",&GUIObj::SetText)
			.def("SetVisible",&GUIObj::SetVisible)
			.def("SetFrameEnable",&GUIObj::SetFrameEnable)
			.def("SetBackGroundEnable",&GUIObj::SetBackGroundEnable)
			.def("SetFontSize",&GUIObj::SetFontSize)
			.def("GetText",&GUIObj::GetText)
			.def("GetComboBoxItem",&GUIObj::GetComboBoxItem)
			.def("GetSliderValue",&GUIObj::GetSliderValue)
			.def("SetTextColor",&GUIObj::SetTextColor)
			.def("SetAlpha",&GUIObj::SetAlpha)
			.def("SetImage",&GUIObj::SetImage)
			.def("SetTextTopAligned",&GUIObj::SetTextTopAligned)
			.def("SetTextBottomAligned",&GUIObj::SetTextBottomAligned)
			.def("SetTextVertCentred",&GUIObj::SetTextVertCentred)
			.def("SetTextWordWrapLeftAligned",&GUIObj::SetTextWordWrapLeftAligned)
			.def("SetTextWordWrapRightAligned",&GUIObj::SetTextWordWrapRightAligned)
			.def("SetTextWordWrapCentred",&GUIObj::SetTextWordWrapCentred)
			.def("SetTextLeftAligned",&GUIObj::SetTextLeftAligned)
			.def("SetTextRightAligned",&GUIObj::SetTextRightAligned)
			.def("SetTextHorzCentred",&GUIObj::SetTextHorzCentred)
			.def("ClearProperties",&GUIObj::ClearProperties)
			.def("SetRotatin",&GUIObj::SetRotatin)
			.def("moveToFront",&GUIObj::moveToFront)
			.def("moveToBack",&GUIObj::moveToBack)
			.def("moveInFront",&GUIObj::moveInFront)
			.def("moveBehind",&GUIObj::moveBehind)
			.def("setColor",&GUIObj::setColor)
			.def("SetWindow",&GUIObj::SetWindow)
			.def("RemoveComboBoxItem",&GUIObj::RemoveComboBoxItem)
			.def("AddListBoxItem",&GUIObj::AddListBoxItem)
			.def("RemoveListBoxItem",&GUIObj::RemoveListBoxItem)
			.def("AddMultiColumnRow",&GUIObj::AddMultiColumnRow)
			.def("RemoveMultiColumnRow",&GUIObj::RemoveMultiColumnRow)
			.def("RemoveMultiColumnCol",&GUIObj::RemoveMultiColumnCol)
			.def("AddMultiColumnItem",&GUIObj::AddMultiColumnItem)
			.def("SetProgressBarValue",&GUIObj::SetProgressBarValue)
			.def("GetScrollValue",&GUIObj::GetScrollValue)
			.def("SetCheckBox",&GUIObj::SetCheckBox)
			.def("GetCheckBox",&GUIObj::SetCheckBox)
			.def("SetSliderValue",&GUIObj::SetSliderValue)
			
			
			

			
			

			;
			bpy::class_<ParticleObj>("ParticleObj",bpy::init<std::string>())
			.def("SetPosition",&ParticleObj::SetPosition)
			.def("SetScale",&ParticleObj::SetScale)
			.def("Roll",&ParticleObj::Roll)
			.def("Pitch",&ParticleObj::Pitch)
			.def("Yaw",&ParticleObj::Yaw)
			.def("SetQuaternion",&ParticleObj::SetQuaternion)
			.def("SetRotation",&ParticleObj::SetRotation)
			.def("SetVisible",&ParticleObj::SetVisible)
			.def("BoundingBoxVisible",&ParticleObj::BoundingBoxVisible)

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


			bpy::class_<AnimationObj>("AnimationObj",bpy::init<std::string>())
			.def("AddKeyFrame",&AnimationObj::AddKeyFrame, bpy::return_internal_reference<>())
			.def("RemoveKeyFrame",&AnimationObj::RemoveKeyFrame)
			.def("SetAnimationState",&AnimationObj::SetAnimationState)
			.def("SetLength",&AnimationObj::SetLength)
			;
			bpy::class_<AnimationObjList>("AnimationObjList")
			.def("setTranslate",&AnimationObjList::setTranslate)
			.def("setRotation",&AnimationObjList::setRotation)

			;
			bpy::class_<LightObj>("LightObj",bpy::init<std::string>())
			.def("setColor",&LightObj::setColor)
			.def("SetPosition",&LightObj::SetPosition)
			.def("SetScale",&LightObj::SetScale)
			.def("Roll",&LightObj::Roll)
			.def("Pitch",&LightObj::Pitch)
			.def("Yaw",&LightObj::Yaw)
			.def("SetQuaternion",&LightObj::SetQuaternion)
			.def("SetRotation",&LightObj::SetRotation)
			.def("SetVisible",&LightObj::SetVisible)
			.def("BoundingBoxVisible",&LightObj::BoundingBoxVisible)

			;
			bpy::class_<ODEBodyObj>("ODEBodyObj",bpy::init<std::string, SimulationObj*>())
			.def("SetBodyPosition",&ODEBodyObj::SetBodyPosition)
			.def("SetBodyRotation",&ODEBodyObj::SetBodyRotation)
			.def("SetODEScale",&ODEBodyObj::SetODEScale)
			.def("SetODEOffset",&ODEBodyObj::SetODEOffset)
			.def("GetPosition",&ODEBodyObj::GetPosition)

			;
			bpy::class_<ODEJointObj>("ODEJointObj",bpy::init<std::string, SimulationObj*>())
			.def("SetJointPosition",&ODEJointObj::SetJointPosition)
			.def("SetJointRotation",&ODEJointObj::SetJointRotation)
			.def("ControlJointAng",&ODEJointObj::ControlJointAng)
			.def("ControlJointVel",&ODEJointObj::ControlJointVel)
			.def("ControlJointToq",&ODEJointObj::ControlJointToq)
			.def("SetODEScale",&ODEJointObj::SetODEScale)
			.def("SetODEOffset",&ODEJointObj::SetODEOffset)
			.def("GetJointPosition",&ODEJointObj::GetJointPosition)
			;
			bpy::class_<ContactListObj>("ContactListObj",bpy::init<std::string>())
			.def("SetERP",&ContactListObj::SetERP)
			.def("SetCFM",&ContactListObj::SetCFM)
			.def("SetMu",&ContactListObj::SetMu)
			.def("SetContact",&ContactListObj::SetContact)
			;
			bpy::class_<SimulationObj>("SimulationObj",bpy::init<OgreRTCApplication*>())
			.def("SetSphere",&SimulationObj::SetSphere, bpy::return_internal_reference<>())
			.def("SetBox",&SimulationObj::SetBox, bpy::return_internal_reference<>())
			.def("SetSylinder",&SimulationObj::SetSylinder, bpy::return_internal_reference<>())
			.def("SetCapsule",&SimulationObj::SetCapsule, bpy::return_internal_reference<>())
			.def("SetSliderJoint",(ODEJointObj *(SimulationObj:: *)(const char *, ODEBodyObj *, ODEBodyObj *, double, double, double))&SimulationObj::SetSliderJoint, bpy::return_internal_reference<>())
			.def("SetSliderJoint",(ODEJointObj *(SimulationObj:: *)(const char *, ODEBodyObj *, double, double, double))&SimulationObj::SetSliderJoint, bpy::return_internal_reference<>())
			.def("SetFixJoint",(ODEJointObj *(SimulationObj:: *)(const char *, ODEBodyObj *, ODEBodyObj *))&SimulationObj::SetFixJoint, bpy::return_internal_reference<>())
			.def("SetFixJoint",(ODEJointObj *(SimulationObj:: *)(const char *, ODEBodyObj *))&SimulationObj::SetFixJoint, bpy::return_internal_reference<>())
			.def("SetHingeJoint",(ODEJointObj *(SimulationObj:: *)(const char *, ODEBodyObj *, ODEBodyObj *, double, double, double, double, double, double))&SimulationObj::SetHingeJoint, bpy::return_internal_reference<>())
			.def("SetHingeJoint",(ODEJointObj *(SimulationObj:: *)(const char *, ODEBodyObj *, double, double, double, double, double, double))&SimulationObj::SetHingeJoint, bpy::return_internal_reference<>())
			.def("DestroyBody",&SimulationObj::DestroyBody)
			.def("DestroyJoint",&SimulationObj::DestroyJoint)
			.def("DestroyAll",&SimulationObj::DestroyAll)
			.def("startSim",&SimulationObj::startSim)
			.def("restartSim",&SimulationObj::restartSim)
			.def("stopSim",&SimulationObj::stopSim)
			.def("SetGravity",&SimulationObj::SetGravity)
			.def("SetCFM",&SimulationObj::SetCFM)
			.def("SetERP",&SimulationObj::SetERP)
			.def("SetSamplingTime",&SimulationObj::SetSamplingTime)
			.def("SetSleepTime",&SimulationObj::SetSleepTime)
			.def("SetGroundCFM",&SimulationObj::SetGroundCFM)
			.def("SetGroundERP",&SimulationObj::SetGroundERP)
			.def("SetQuiq",&SimulationObj::SetQuiq)
			.def("SetGroundMu",&SimulationObj::SetGroundMu)
			.def("getBodyByName",&SimulationObj::getBodyByName, bpy::return_internal_reference<>())
			.def("getJointByName",&SimulationObj::getJointByName, bpy::return_internal_reference<>())
			.def("SetScale",&SimulationObj::SetScale)
			.def("SetContactList",&SimulationObj::SetContactList, bpy::return_internal_reference<>())
			.def("DestroyContactList",&SimulationObj::DestroyContactList)
			.def("getContactListByName",&SimulationObj::getContactListByName, bpy::return_internal_reference<>())

			
			
			;
			bpy::class_<ImageSetObj>("ImageSetObj")

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

/**
*@brief Ogre3Dのレンダリング管理クラスのコンストラクタ
*/
OgreRTCApplication::OgreRTCApplication(void)
{
	
	SleepTime = 0;


	PreeditStr = QString();

	
	RTCFlag = false;

	CameraFlag = true;
	
	

	
	


	skyBoxName = "";
	QtskyBoxName = "";


	mSim = new SimulationObj(this);

	mSim->activate();
	
	if( PyImport_AppendInittab( "CppExport" , initCppExport ) == -1 )
   {
		std::cout << "Failed" << std::endl;
		return;
   }
	po = new PyObj();
	OgreRTCApplication *tmpoint = this;
	po->global_ns["OgreObj"] = boost::ref(tmpoint);
	po->global_ns["SimulationObj"] = boost::ref(mSim);

	po->Script("OgreRTC.py");

	

	po->setFunc("ManagerStart");
   
	
	
}


/**
*@brief カメラの位置、姿勢、距離の設定の関数
* @param px 位置(X)
* @param py 位置(X)
* @param pz 位置(X)
* @param roll 角度(ロール)
* @param pitch 角度(ピッチ)
* @param yaw 角度(ヨー)
* @param len 距離
*/
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

/**
*@brief カメラを移動する関数
* @param dx 移動距離(X)
* @param dy 移動距離(Y)
*/
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

/**
*@brief カメラを回転する関数
* @param dx 回転量(X)
* @param dy 回転量(Y)
*/
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

/**
*@brief RTCの停止の関数
*/
void OgreRTCApplication::StopFile()
{
	if(po->Exec)
	{
		po->mThread->wait();
		po->setFunc("RTCStop");
		
		po->Exec = false;
	}
}

/**
*@brief RTC削除の関数
*/
void OgreRTCApplication::CloseFile()
{
	StopFile();

	DestroyAllBody();
	DestroyAllGUI();

	
	
	DestroyAllParticle();
	DestroyAllSubWindow();
	DestroyAllImage();

	

	
}

/**
*@brief RTC読み込みの関数
* @param fname ファイル名
*/
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
		coil::usleep(10);
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

/**
*@brief 名前からボディオブジェクトを取得
* @param name 名前
* @return ボディオブジェクト
*/
LinkObj* OgreRTCApplication::getBodyByName(const char* name)
{
	
	for(int i=0;i < LinkObjs.size();i++)
	{
		if(LinkObjs[i]->name == name)
		{
			return LinkObjs[i];
		}
	}
	return NULL;
}


/**
*@brief 名前からGUIオブジェクトを取得
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj* OgreRTCApplication::getGUIByName(const char* name)
{
	for(int i=0;i < GUIObjs.size();i++)
	{
		if(GUIObjs[i]->name == name)
		{
			return GUIObjs[i];
		}
	}
	return NULL;
}

/**
*@brief 名前からパーティクルオブジェクトを取得
* @param name 名前
* @return パーティクルオブジェクト
*/
ParticleObj* OgreRTCApplication::getParticleByName(const char* name)
{
	for(int i=0;i < ParticleObjs.size();i++)
	{
		if(ParticleObjs[i]->name == name)
		{
			return ParticleObjs[i];
		}
	}
	return NULL;
}

/**
*@brief 名前からサブウインドウオブジェクトを取得
* @param name 名前
* @return サブウインドウオブジェクト
*/
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


/**
*@brief 名前からイメージセットオブジェクトを取得
* @param name 名前
* @return イメージセットオブジェクト
*/
ImageSetObj* OgreRTCApplication::getImageSetByName(const char* name)
{
	for(int i=0;i < ImageSetObjs.size();i++)
	{
		if(ImageSetObjs[i]->name == name)
		{
			return ImageSetObjs[i];
		}
	}
	return NULL;
}


/**
*@brief Ogre3Dのレンダリング管理クラスのデストラクタ
*/
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

/**
*@brief QtのキーコードをCEGUIのキーコードに変換
* @param key Qtのキーコード
* @return CEGUIのキーコード
*/
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

/**
*@brief テキストを入力した場合等に呼び出される関数
* @param arg インプットメソッドイベント
* @return true
*/
bool OgreRTCApplication::inputMethodEvent(QInputMethodEvent *arg)
{
	const QString tmp = arg->commitString();

	CEGUI::GUIContext &sys = CEGUI::System::getSingleton().getDefaultGUIContext();

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


/**
*@brief キーを押した時に呼ばれる関数
* @param arg キーイベント
* @return true
*/
bool OgreRTCApplication::keyPressed( QKeyEvent *arg )
{

	CEGUI::GUIContext &sys = CEGUI::System::getSingleton().getDefaultGUIContext();
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

/**
*@brief キーを離した時に呼ばれる関数
* @param arg キーイベント
* @return true
*/
bool OgreRTCApplication::keyReleased( QKeyEvent *arg )
{

    if(CEGUI::System::getSingleton().getDefaultGUIContext().injectKeyUp(convertKey(arg->key()))) return true;
    

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


/**
*@brief QtのマウスボタンIDをCEGUIのマウスボタンIDに変換
* @param buttonID QtのマウスボタンID
* @return CEGUIのマウスボタンID
*/
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


/**
*@brief 背景画像設定の関数
* @param img 画像データ
* @param w 幅
* @param h 高さ
*/
void OgreRTCApplication::setDisplayImage(const char *img, int w, int h)
{
	if(displayImg->texture->getWidth() != w)
	{
		std::cout << "width" << std::endl;
		displayImg->texture->setWidth(w);
	}

	if(displayImg->texture->getHeight() != h)
	{
		std::cout << "height" << std::endl;
		displayImg->texture->setHeight(h);
	}

	/*Ogre::HardwarePixelBufferSharedPtr buffer = displayImg->texture->getBuffer();
	buffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);

	const Ogre::PixelBox &pb = buffer->getCurrentLock();

	uint8* pDest = static_cast<uint8*>(pb.data);

	for (size_t i = 0; i < h; i++)
	{
		for(size_t j = 0; j < w; j++)
		{
			*pDest++ = img[(j+w*i)*3+2];
			*pDest++ = img[(j+w*i)*3+1];
			*pDest++ = img[(j+w*i)*3];
			*pDest++ = 127; // A
		}
		pDest += pb.getRowSkip() * Ogre::PixelUtil::getNumElemBytes(pb.format);
	}


	buffer->unlock();*/

	displayImg->img.loadDynamicImage((Ogre::uchar*) img, w, h, Ogre::PF_R8G8B8);

	displayImg->texture->unload();
	displayImg->texture->loadImage(displayImg->img);
}


/**
*@brief マウスを動かした時に呼ばれる関数
* @param arg マウスイベント
* @return true
*/
bool OgreRTCApplication::mouseMoved( QMouseEvent*  evt )
{
	
	
	
	
	CEGUI::Vector2f mousePos = CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().getPosition();

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

	
	

    if(CEGUI::System::getSingleton().getDefaultGUIContext().injectMousePosition(mx, my)) return true;
   

	

	

    return true;
}
 
/**
*@brief マウスのボタン押した時に呼ばれる関数
* @param arg マウスイベント
* @return true
*/
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

	

    if(CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(convertButton(evt->button()))) return true;
    

	

    return true;
}
 
/**
*@brief マウスのボタン離した時に呼ばれる関数
* @param arg マウスイベント
* @return true
*/
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

	

    if(CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(convertButton(evt->button()))) return true;
   

	

    return true;
}

/**
*@brief ボディオブジェクト初期化
* @param ml ボディオブジェクト
* @param scx 拡大率(X)
* @param scy 拡大率(Y)
* @param scz 拡大率(Z)
*/
void CreateML(LinkObj *ml,double scx,double scy,double scz)
{
	ml->mEntity->setCastShadows(true);
	ml->mNode->mNode->attachObject(ml->mEntity);
	Ogre::Vector3 scale = Ogre::Vector3::ZERO;
	scale.x = scx;
	scale.y = scy;
	scale.z = scz;
	ml->mNode->mNode->scale(scale);
	
}
 
/**
*@brief 初期化の関数
*/
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

	displayImg = new DisplayImage();
	displayImg->mRect = new Ogre::Rectangle2D(true);
	displayImg->mRect->setCorners(-1.0, 1.0, 1.0, -1.0);
	displayImg->mRect->setBoundingBox( Ogre::AxisAlignedBox::EXTENT_INFINITE );
	displayImg->texture = Ogre::TextureManager::getSingleton().createManual("DisplayImageTex", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, Ogre::TEX_TYPE_2D, 640, 480, 0, Ogre::PF_R8G8B8, Ogre::TU_RENDERTARGET);
	//displayImg->texture = Ogre::TextureManager::getSingleton().createManual("DisplayImageTex", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, Ogre::TEX_TYPE_2D, 640, 480, 0, Ogre::PF_BYTE_BGRA, Ogre::TU_DEFAULT);
	displayImg->material = Ogre::MaterialManager::getSingleton().create("DisplayImageMat", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	//displayImg->texture->setWidth(640);
	//displayImg->texture->setHeight(480);
	//displayImg->texture->getWidth();
	//displayImg->texture->setHeight();
	//stadium.mNode->setVisible(false);
	
	

	displayImg->material->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    displayImg->material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
    displayImg->material->getTechnique(0)->getPass(0)->setLightingEnabled(false);
	displayImg->material->getTechnique(0)->getPass(0)->createTextureUnitState("DisplayImageTex");
 
	displayImg->mRect->setMaterial("DisplayImageMat");
	displayImg->mRect->setRenderQueueGroup( Ogre::RENDER_QUEUE_BACKGROUND );

	displayImg->node = mSceneMgr->getRootSceneNode()->createChildSceneNode("DisplayImage");
	displayImg->node->attachObject(displayImg->mRect);


	mRenderer = &CEGUI::OgreRenderer::bootstrapSystem(*mWindow);
	

    //CEGUI::Image::setDefaultResourceGroup("Imagesets");
    CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
 
	CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");

	
	
	
	
	
	

    //CEGUI::System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");


	



	//CEGUI::FontManager::getSingleton().createFreeTypeFont("DefaultFont", 10/*pt*/, true, "DejaVuSans.ttf");
	//CEGUI::System::getSingleton().setDefaultFont("DefaultFont");
	//CEGUI::FontManager::getSingleton().createAll("*.font", "fonts");

	

	//CEGUI::Window *sheet2;
	//sheet2 = wmgr.loadWindowLayout("Demo7Windows.layout");
    CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
    sheet = wmgr.createWindow("DefaultWindow", "CEGUIDemo/Sheet");
	

	
	//CEGUI::FontManager::getSingleton().createFreeTypeFont("DefaultFont", 30/*pt*/, true, "DejaVuSans.ttf");
	//CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultFont("DefaultFont");
	//CEGUI::FontManager::getSingleton().isDefined("DejaVuSans");
	
	if(!loadFont("SazanamiFont",30,true,"sazanami-mincho"))
	{
		loadFont("DejaVuSansFont",30,true,"DejaVuSans");
	}


	CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);

	

	
	
}

/**
*@brief フォントを読み込む関数
* @param font_name フォント名
* @param point_size サイズ
* @param anti_aliased trueでアンチエイリアス有効
* @param font_filename ファイル名
* @return 成功でtrue、失敗でfalse
*/

bool OgreRTCApplication::loadFont(const char *font_name, float point_size, bool anti_aliased, const char *font_filename)
{
	for (std::vector<std::string>::iterator it = fontList.begin(); it != fontList.end();it++)
	{
		if((*it) == font_filename)
		{
			return true;
		}
	}

	std::string fontFileName = font_filename;
	fontFileName += ".ttf";
	try
	{
		CEGUI::FontManager::getSingleton().createFreeTypeFont(font_name, point_size/*pt*/, anti_aliased, fontFileName.c_str());
	}
	catch(...)
	{
		return false;
	}
	CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultFont(font_name);
	CEGUI::FontManager::getSingleton().isDefined(font_filename);

	fontList.push_back(font_filename);
	return true;
	
}

/**
*@brief キーを押した時に終了する関数
* @param e キーイベント
* @return true
*/
bool OgreRTCApplication::quit(const CEGUI::EventArgs &e)
{
    mShutDown = true;
    return true;
}




/**
*@brief 更新時に呼び出される関数
* @param t フレーム時間
*/
void OgreRTCApplication::update(float t)
{
	if(mWindow) {
		
		
		mRoot->renderOneFrame();
		
		



		static clock_t Tm = clock();
		clock_t tTm = clock();

		float t = (float)(tTm - Tm)/CLOCKS_PER_SEC;

		Tm = tTm;

		//std::cout << t << std::endl;
		//std::cout << NodeObjs.size() << std::endl;
		
		int ttW = SleepTime - (int)(1000. * t); 
		if(ttW > 0)coil::usleep(ttW);
		

		if(po->Exec)
		{
			po->setFunc("ogre_loop");
			//CreatePyFunc(po, "ogre_loop");
			
		}


		
	}
	
	
}
 

/**
*@brief カメラの位置設定の関数
* @param x 位置(X)
* @param y 位置(Y)
* @param z 位置(Z)
*/
void OgreRTCApplication::SetCameraPosition(float x, float y, float z)
{
	mCamera->setPosition(x, y, z);

    
}


/**
*@brief カメラの姿勢(ロール角)設定の関数
* @param ang 角度(ロール)
*/
void OgreRTCApplication::CameraRoll(float ang)
{
	mCamera->roll(Ogre::Degree(ang));

	
	
}

/**
*@brief カメラの姿勢(ピッチ角)設定の関数
* @param ang 角度(ピッチ)
*/
void OgreRTCApplication::CameraPitch(float ang)
{
	mCamera->pitch(Ogre::Degree(ang));

	
}

/**
*@brief カメラの姿勢(ヨー角)設定の関数
* @param ang 角度(ヨー)
*/
void OgreRTCApplication::CameraYaw(float ang)
{
	mCamera->yaw(Ogre::Degree(ang));

	
	
}


/**
*@brief カメラの姿勢設定の関数
* @param r 角度(ロール)
* @param p 角度(ピッチ)
* @param y 角度(ヨー)
*/
void OgreRTCApplication::SetCameraRotation(float r, float p, float y)
{
	SetCameraQuaternion(1,0,0,0);
	CameraRoll(r);
	CameraPitch(p);
	CameraYaw(y);
	
}


/**
*@brief カメラの姿勢(クォータニオン)設定の関数
* @param w クォータニオン(W)
* @param x クォータニオン(X)
* @param y クォータニオン(Y)
* @param z クォータニオン(Z)
*/
void OgreRTCApplication::SetCameraQuaternion(float w, float x, float y, float z)
{
	mCamera->setOrientation(Ogre::Quaternion(w,x,y,z));
}

/**
*@brief スタティックテキスト作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateStaticText(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/StaticText", name);
	
	return label;
}

/**
*@brief GUIの操作でボタンを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtStaticText(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/StaticText", name);
	return label;
}


/**
*@brief ボタンを押したときに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::BottonClickedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	
	SetCallScript(evt->window->getName().c_str(), "Clicked");

	
	return true;
}

/**
*@brief GUIのコールバックを設定する関数
* @param name 名前
* @param type ウィジェットの種類
*/
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

/**
*@brief ボタン作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateButton(const char* name)
{
	
	GUIObj *label = CreateGUI("TaharezLook/Button", name);
	label->window->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&OgreRTCApplication::BottonClickedHandler, this));
	return label;
}

/**
*@brief GUIの操作でスタティックテキストを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtButton(const char* name)
{
	
	GUIObj *label = CreateQtGUI("TaharezLook/Button", name);
	label->window->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&OgreRTCApplication::BottonClickedHandler, this));
	return label;
}


/**
*@brief テキストエディタ作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateEditBox(const char* name)
{
	
	GUIObj *label = CreateGUI("TaharezLook/Editbox", name);
	//label->subscribeEvent(CEGUI::Window::EventKeyDown, CEGUI::Event::Subscriber(&OgreRTCApplication::GUIKeyDownHandler, this));
	//label->subscribeEvent(CEGUI::Window::EventKeyUp, CEGUI::Event::Subscriber(&OgreRTCApplication::GUIKeyUpHandler, this));
	return label;
}

/**
*@brief GUIの操作でテキストエディタを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtEditBox(const char* name)
{
	
	GUIObj *label = CreateQtGUI("TaharezLook/Editbox", name);
	
	return label;
}


/**
*@brief コンボボックス作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateComboBox(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/Combobox", name);
	label->window->subscribeEvent(CEGUI::Combobox::EventListSelectionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ComboBoxChangedHandler, this));
	return label;
	
}

/**
*@brief GUIの操作でスタティックテキストを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtComboBox(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/Combobox", name);
	label->window->subscribeEvent(CEGUI::Combobox::EventListSelectionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ComboBoxChangedHandler, this));

	return label;
	
}






/**
*@brief スライダー作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateSlider(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/Slider", name);
	label->window->subscribeEvent(CEGUI::Slider::EventValueChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::SliderChangedHandler, this));
	return label;
	
}

/**
*@brief GUIの操作でコンボボックスを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtSlider(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/Slider", name);
	label->window->subscribeEvent(CEGUI::Slider::EventValueChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::SliderChangedHandler, this));
	return label;
	
}

/**
*@brief タイトルバー作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateTitlebar(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/Titlebar", name);
	return label;
	
}

/**
*@brief GUIの操作でタイトルバーを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtTitlebar(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/Titlebar", name);
	return label;
	
}

/**
*@brief フレームウインドウ作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateFrameWindow(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/FrameWindow", name);
	return label;
	
}

/**
*@brief GUIの操作でフレームウインドウを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtFrameWindow(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/FrameWindow", name);
	return label;
	
}


/**
*@brief 縦スクロールバー作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateVerticalScrollbar(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/VerticalScrollbar", name);
	label->window->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ScrollPosChangedHandler, this));
	
	return label;
	
}

/**
*@brief GUIの操作で縦スクロールバーを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtVerticalScrollbar(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/VerticalScrollbar", name);
	label->window->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ScrollPosChangedHandler, this));
	return label;
	
}


/**
*@brief 横スクロールバー作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateHorizontalScrollbar(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/HorizontalScrollbar", name);
	label->window->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ScrollPosChangedHandler, this));
	return label;
	
}


/**
*@brief GUIの操作で横スクロールバーを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtHorizontalScrollbar(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/HorizontalScrollbar", name);
	label->window->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ScrollPosChangedHandler, this));
	return label;
	
}



/**
*@brief プログレスバー作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateProgressBar(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/ProgressBar", name);
	return label;
	
}

/**
*@brief GUIの操作でプログレスバーを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtProgressBar(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/ProgressBar", name);
	return label;
	
}

/**
*@brief マルチラインエディット作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateMultiLineEditbox(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/MultiLineEditbox", name);
	return label;
	
}

/**
*@brief GUIの操作でマルチラインエディットを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtMultiLineEditbox(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/MultiLineEditbox", name);
	return label;
	
}


/**
*@brief リストボックス作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateListbox(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/Listbox", name);
	label->window->subscribeEvent(CEGUI::Listbox::EventSelectionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ListBoxChangedHandler, this));
	return label;
	
}


/**
*@brief GUIの操作でリストボックスを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtListbox(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/Listbox", name);
	label->window->subscribeEvent(CEGUI::Listbox::EventSelectionChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::ListBoxChangedHandler, this));
	return label;
	
}

/**
*@brief コンボドロップリスト作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateComboDropList(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/ComboDropList", name);
	return label;
	
}

/**
*@brief GUIの操作でコンボドロップリストを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtComboDropList(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/ComboDropList", name);
	return label;
	
}




/**
*@brief チェックボックス作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateCheckbox(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/Checkbox", name);
	label->window->subscribeEvent(CEGUI::ToggleButton::EventSelectStateChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::CheckedHandler, this));

	return label;
	
}

/**
*@brief GUIの操作でチェックボックスを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtCheckbox(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/Checkbox", name);
	label->window->subscribeEvent(CEGUI::ToggleButton::EventSelectStateChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::CheckedHandler, this));

	return label;
	
}


/**
*@brief ラジオボタン作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateRadioButton(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/RadioButton", name);
	label->window->subscribeEvent(CEGUI::RadioButton::EventSelectStateChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::RadioHandler, this));
	return label;
	
}

/**
*@brief GUIの操作でラジオボタンを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtRadioButton(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/RadioButton", name);
	label->window->subscribeEvent(CEGUI::RadioButton::EventSelectStateChanged,
			CEGUI::Event::Subscriber(&OgreRTCApplication::RadioHandler, this));
	return label;
	
}


/**
*@brief ツールチップ作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateTooltip(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/Tooltip", name);
	return label;
	
}

/**
*@brief GUIの操作でツールチップを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtTooltip(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/Tooltip", name);
	return label;
	
}

/**
*@brief アイテムリストボックス作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateItemListbox(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/ItemListbox", name);
	return label;
	
}

/**
*@brief GUIの操作でアイテムリストボックスを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtItemListbox(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/ItemListbox", name);
	return label;
	
}

/**
*@brief リストボックスアイテム作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateListboxItem(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/ListboxItem", name);
	return label;
	
}

/**
*@brief GUIの操作でリストボックスアイテムを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtListboxItem(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/ListboxItem", name);
	return label;
	
}

/**
*@brief スピナー作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateSpinner(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/Spinner", name);
	return label;
	
}

/**
*@brief GUIの操作でスピナーを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtSpinner(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/Spinner", name);
	return label;
	
}

/**
*@brief スクロールブルペーン作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateScrollablePane(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/ScrollablePane", name);
	return label;
	
}

/**
*@brief GUIの操作でスクロールブルペーンを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtScrollablePane(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/ScrollablePane", name);
	return label;
	
}

/**
*@brief リストヘッダーセグメント作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateListHeaderSegment(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/ListHeaderSegment", name);
	return label;
	
}

/**
*@brief GUIの操作でリストヘッダーセグメントを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtListHeaderSegment(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/ListHeaderSegment", name);
	return label;
	
}

/**
*@brief リストヘッダーセグメント作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateListHeader(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/ListHeader", name);
	return label;
	
}

/**
*@brief GUIの操作でリストヘッダーセグメントを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtListHeader(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/ListHeader", name);
	return label;
	
}

/**
*@brief マルチコロンリスト作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateMultiColumnList(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/MultiColumnList", name);
	return label;
	
}

/**
*@brief GUIの操作でマルチコロンリストを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtMultiColumnList(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/MultiColumnList", name);
	return label;
	
}

/**
*@brief メニューアイテム作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateMenuItem(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/MenuItem", name);
	return label;
	
}

/**
*@brief GUIの操作でメニューアイテムを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtMenuItem(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/MenuItem", name);
	return label;
	
}

/**
*@brief メニューバー作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateMenubar(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/Menubar", name);
	return label;
	
}


/**
*@brief GUIの操作でメニューバーを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtMenubar(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/Menubar", name);
	return label;
	
}


/**
*@brief ポップアイテムメニュー作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreatePopupMenu(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/PopupMenu", name);
	return label;
	
}

/**
*@brief GUIの操作でポップアイテムメニューを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtPopupMenu(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/PopupMenu", name);
	return label;
	
}


/**
*@brief タブボタンペーン作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateTabButtonPane(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/TabButtonPane", name);
	return label;
	
}

/**
*@brief GUIの操作でタブボタンペーンを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtTabButtonPane(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/TabButtonPane", name);
	return label;
	
}

/**
*@brief タブコンテキストペーン作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateTabContentPane(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/TabContentPane", name);
	return label;
	
}

/**
*@brief GUIの操作でタブコンテキストペーンを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtTabContentPane(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/TabContentPane", name);
	return label;
	
}

/**
*@brief タブコントロール作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateTabControl(const char* name)
{
	GUIObj *label = CreateGUI("TaharezLook/TabControl", name);
	return label;
	
}

/**
*@brief GUIの操作でタブコントロールを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtTabControl(const char* name)
{
	GUIObj *label = CreateQtGUI("TaharezLook/TabControl", name);
	return label;
	
}




/**
*@brief スライダーの値が変化したときに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::SliderChangedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "SliderChanged");

	return true;
}

/**
*@brief チェックボックスが変化したときに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::CheckedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "Checked");

	return true;
}

/**
*@brief ラジオボタンが変化したときに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::RadioHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "SelectionChanged");

	return true;
}

/**
*@brief リストボックスの選択が変化したときに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::ListBoxChangedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
	SetCallScript(evt->window->getName().c_str(), "SelectionChanged");

	return true;
}

/**
*@brief コンボボックスの選択が変化したときに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::ComboBoxChangedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "SelectionChanged");

	return true;
}

/**
*@brief スクロールバーが変化したときに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::ScrollPosChangedHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::WindowEventArgs* evt = static_cast<const CEGUI::WindowEventArgs*>(&event);
   
	SetCallScript(evt->window->getName().c_str(), "ScrollPosChanged");

	return true;
}


/**
*@brief GUI作成の関数
* @param type ウィジェットの種類
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateGUI(const char* type, const char* name)
{
	GUIObj *label = new GUIObj();
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();


	label->window = wmgr.createWindow(type, name);
	label->window->setPosition(CEGUI::UVector2(CEGUI::UDim(0., 0),CEGUI::UDim(0.0, 0)));
	label->window->setSize(CEGUI::USize(CEGUI::UDim(1., 0), CEGUI::UDim(1., 0)));
	
	sheet->addChild(label->window);

	label->type = type;
	label->name = name;

	GUIObjs.push_back(label);
	

	return label;
}


/**
*@brief GUIオブジェクトの再生成の関数
* @param label GUIオブジェクト
*/
void OgreRTCApplication::CreateQtGUI(GUIObj *label)
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();

	Ogre::NodeAnimationTrack* track;
	label->window = wmgr.createWindow(label->type, label->name);
	label->window->setPosition(CEGUI::UVector2(CEGUI::UDim(0., 0),CEGUI::UDim(0.0, 0)));
	label->window->setSize(CEGUI::USize(CEGUI::UDim(1., 0), CEGUI::UDim(1., 0)));
	sheet->addChild(label->window);

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
			
			ImageSetObj* ims = getImageSetByName(label->image_name.c_str());
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


	GUIObjs.push_back(label);
}


/**
*@brief GUIの操作でGUIを作成する関数
* @param type GUIの種類
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtGUI(const char* type, const char* name)
{
	GUIObj *label = CreateGUI(type, name);
	QtGUIs.push_back(label);

	return label;
}



/**
*@brief GUIをキーで押したときに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::GUIKeyUpHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::KeyEventArgs* evt = static_cast<const CEGUI::KeyEventArgs*>(&event);
	//CEGUI::System &sys = CEGUI::System::getSingleton();
	//sys.injectKeyUp(evt->scancode);

	

	return true;
}

/**
*@brief GUIからキーを離したに呼び出される関数
* @param event イベント
* @return true
*/
bool OgreRTCApplication::GUIKeyDownHandler(const CEGUI::EventArgs &event)
{
	const CEGUI::KeyEventArgs* evt = static_cast<const CEGUI::KeyEventArgs*>(&event);

	CEGUI::GUIContext &sys = CEGUI::System::getSingleton().getDefaultGUIContext();
	//sys.injectKeyDown(evt->scancode);
	sys.injectChar(evt->codepoint);
	//std::cout << evt->scancode << "\t" << evt->codepoint << std::endl;

	return true;
}


/**
*@brief スタティックイメージ作成の関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateStaticImage(const char* name)
{
	

	GUIObj *label = CreateGUI("TaharezLook/StaticImage", name);
	

	return label;

	
}


/**
*@brief GUIの操作でスタティックイメージを作成する関数
* @param name 名前
* @return GUIオブジェクト
*/
GUIObj *OgreRTCApplication::CreateQtStaticImage(const char* name)
{
	

	GUIObj *label = CreateQtGUI("TaharezLook/StaticImage", name);
	

	return label;

	
}

/**
*@brief CEGUIのウインドウ削除の関数
* @param label ウインドウオブジェクト
*/
void OgreRTCApplication::Destroycegui(CEGUI::Window *label)
{
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	
	label->getParent()->removeChild(label);
	wmgr.destroyWindow(label);
	
	
	
}

/**
*@brief GUIオブジェクト削除の関数
* @param label GUIオブジェクト
*/
void OgreRTCApplication::DestroyGui(GUIObj *label)
{
	
	
		
	for(int j=0;j < GUIObjs.size();j++)
	{
		if(label->window->isChild(GUIObjs[j]->window->getName()))
		{
			DestroyGui(GUIObjs[j]);
			
			j = j - 1;
		}
	}
	
	Destroycegui(label->window);
	std::vector<GUIObj*>::iterator end_it = remove( GUIObjs.begin(), GUIObjs.end(), label );
	GUIObjs.erase( end_it, GUIObjs.end() );

	
}


/**
*@brief GUIの操作でGUIオブジェクトを削除する関数
* @param name 名前
* @return GUIオブジェクト
*/
void OgreRTCApplication::DestroyQtGui(GUIObj *label)
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
	std::vector<GUIObj*>::iterator end_it = remove( QtGUIs.begin(), QtGUIs.end(), label );
	QtGUIs.erase( end_it, QtGUIs.end() );

	
}


/**
*@brief 全てのGUIオブジェクト削除の関数
*/
void OgreRTCApplication::DestroyAllGUI()
{
	
	//for(int i=0;i < GUIObjs.size();i++)
	while(GUIObjs.size() > 0)
	{
		
		DestroyGui(GUIObjs[0]);
		//Destroycegui(GUIObjs[i]->window);
	}
	GUIObjs.clear();
}








/**
*@brief パーティクル作成の関数
* @param name 名前
* @param file_name ファイル名
* @return パーティクルオブジェクト
*/
ParticleObj *OgreRTCApplication::CreateParticle(const char* name, const char* file_name)
{
	ParticleObj *ml = new ParticleObj(name);
	ml->particleSystem = mSceneMgr->createParticleSystem(name, file_name);
	ml->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ml->mNode->mNode->attachObject(ml->particleSystem);
	ml->mNode->mNode->setPosition(Ogre::Vector3(0,0,0));

	NodeObjs.push_back(ml->mNode);
	ml->mNode->AddObj(ml);
	ParticleObjs.push_back(ml);


	
	ml->filename = file_name;

	return ml;


}

/**
*@brief パーティクルオブジェクトの再生成の関数
* @param ml パーティクルオブジェクト
*/
void OgreRTCApplication::CreateQtParticle(ParticleObj *ml)
{
	ml->particleSystem = mSceneMgr->createParticleSystem(ml->name, ml->filename);
	
	NodeObj *mn = getNodeByName(ml->mNode->name.c_str());
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

	ParticleObjs.push_back(ml);
}

/**
*@brief GUIの操作でパーティクルオブジェクトを作成する関数
* @param name 名前
* @param file_name ファイル名
* @return パーティクルオブジェクト
*/
ParticleObj *OgreRTCApplication::CreateQtParticle(const char* name, const char* file_name)
{
	ParticleObj *ml = CreateParticle(name, file_name);

	QtNodes.push_back(ml->mNode);
	QtParticles.push_back(ml);

	return ml;


}



/**
*@brief パーティクル削除の関数
* @param ml パーティクルオブジェクト
*/
void OgreRTCApplication::DestroyParticle(ParticleObj *ml)
{
	ml->mNode->mNode->detachObject(ml->particleSystem);
	mSceneMgr->destroyParticleSystem(ml->particleSystem);
	
	ml->mNode->RemoveObj(ml);
	DestroyNode(ml->mNode);

	std::vector<ParticleObj*>::iterator end_it = remove( ParticleObjs.begin(), ParticleObjs.end(), ml );
	ParticleObjs.erase( end_it, ParticleObjs.end() );

	
}


/**
*@brief GUIの操作でパーティクルオブジェクトの削除する関数
* @param ml パーティクルオブジェクト
*/
void OgreRTCApplication::DestroyQtParticle(ParticleObj *ml)
{
	DestroyParticle(ml);

	DestroyQtNode(ml->mNode);

	std::vector<ParticleObj*>::iterator end_it = remove( QtParticles.begin(), QtParticles.end(), ml );
	QtParticles.erase( end_it, QtParticles.end() );
}

/**
*@brief 全てパーティクル削除の関数
*/
void OgreRTCApplication::DestroyAllParticle()
{
	for(int i=0;i < ParticleObjs.size();i++)
	{
		ParticleObjs[i]->mNode->mNode->detachObject(ParticleObjs[i]->particleSystem);
		mSceneMgr->destroyParticleSystem(ParticleObjs[i]->particleSystem);
		ParticleObjs[i]->mNode->RemoveObj(ParticleObjs[i]);
		DestroyNode(ParticleObjs[i]->mNode);
	}
	ParticleObjs.clear();
}

/**
*@brief 地面作成の関数
* @param name 名前
* @param name2 ボディ名
* @param filename マテリアル名
* @param Size 大きさ
* @param direction 方向
* @return ボディオブジェクト
*/
LinkObj *OgreRTCApplication::SetFloor(const char* name, const char* name2, const char* filename, int Size, int direction)
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
	
	LinkObj *link = new LinkObj(name);

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


/**
*@brief GUIの操作で地面を作成する関数
* @param name 名前
* @param name2 ボディ名
* @param filename マテリアル名
* @param Size 大きさ
* @param direction 方向
* @return ボディオブジェクト
*/
LinkObj *OgreRTCApplication::SetQtFloor(const char* name, const char* name2, const char* filename, int Size, int direction)
{

	qtFloor = SetFloor(name, name2, filename, Size, direction);

	return qtFloor;
}


/**
*@brief スカイボックス削除の関数
*/
void OgreRTCApplication::RemoveSkyBox()
{
	mSceneMgr->destroySceneNode(mSceneMgr->getSkyBoxNode());
}

/**
*@brief スカイボックス作成の関数
* @param filename ファイル名
* @param Size 大きさ
*/
void OgreRTCApplication::SetSkyBox(const char* filename, int Size)
{
	mSceneMgr->setSkyBox(true, filename, Size);
	skyBoxName = filename;
	skyBoxSize = Size;

}

/**
*@brief GUIの操作でスカイボックスを作成する関数
* @param filename ファイル名
* @param Size 大きさ
*/
void OgreRTCApplication::SetQtSkyBox(const char* filename, int Size)
{
	SetSkyBox(filename, Size);
	QtskyBoxName = filename;
	QtskyBoxSize = Size;
}

/**
*@brief 画像作成の関数
* @param name 名前
* @param filename ファイル名
* @return イメージセットオブジェクト
*/
ImageSetObj *OgreRTCApplication::CreateGuiImageSet(const char* name, const char* filename)
{
	ImageSetObj *MIS = new ImageSetObj();
	//MIS->texture = &mRenderer->createTexture(filename,"Imagesets");
	//MIS->Image = &CEGUI::ImageManager::getSingleton().create(name,*MIS->texture);
	//MIS->Image->defineImage("Base",CEGUI::Point(0.0f,0.0f),CEGUI::Size(MIS->texture->getSize().d_width,MIS->texture->getSize().d_height),CEGUI::Point(0.0f,0.0f));
	//std::string ext = filename;
	//ext = GetExtension(ext);

	//set: BackgroundImage2 image: full_image
	coil::vstring va = coil::split(filename, ".");

	if(va[1] == "imageset")
	{
		CEGUI::ImageManager::getSingleton().loadImageset(filename);
		//std::cout << va[0] << std::endl;
	}
	else
	{
		CEGUI::ImageManager::getSingleton().addFromImageFile(name, filename);
	}
	MIS->name = name;
	MIS->filename = filename;
	ImageSetObjs.push_back(MIS);
	
	return MIS;
}


/**
*@brief イメージセットオブジェクトの再生成の関数
* @param MIS イメージセットオブジェクト
*/
void OgreRTCApplication::CreateQtImage(ImageSetObj *MIS)
{
	//MIS->texture = &mRenderer->createTexture(MIS->filename,"Imagesets");
	
	//MIS->Image = &CEGUI::ImageManager::getSingleton().create(MIS->name,*MIS->texture);
	//MIS->Image->defineImage("Base",CEGUI::Point(0.0f,0.0f),CEGUI::Size(MIS->texture->getSize().d_width,MIS->texture->getSize().d_height),CEGUI::Point(0.0f,0.0f));
	//std::string ext = MIS->filename;
	//ext = GetExtension(ext);
	coil::vstring va = coil::split(MIS->filename, ".");
	if(va[1] == "imageset")
	{
		CEGUI::ImageManager::getSingleton().loadImageset(MIS->filename);
	}
	else
	{
		CEGUI::ImageManager::getSingleton().addFromImageFile(MIS->name, MIS->filename);
	}
	

	ImageSetObjs.push_back(MIS);
}

/**
*@brief GUIの操作で画像を作成する関数
* @param name 名前
* @param filename ファイル名
* @return イメージセットオブジェクト
*/
ImageSetObj *OgreRTCApplication::CreateQtGuiImageSet(const char* name, const char* filename)
{
	ImageSetObj *MIS = CreateGuiImageSet(name, filename);
	QtImageSets.push_back(MIS);
	
	return MIS;
}





/**
*@brief 画像削除の関数
* @param MIS イメージセットオブジェクト
*/
void OgreRTCApplication::DestroyImage(ImageSetObj *MIS)
{
	//CEGUI::ImageManager::getSingleton().destroy(MIS->Image->getName());

	//mRenderer->destroyTexture(*MIS->texture);

	std::vector<ImageSetObj*>::iterator end_it = remove( ImageSetObjs.begin(), ImageSetObjs.end(), MIS );
	ImageSetObjs.erase( end_it, ImageSetObjs.end() );
}


/**
*@brief GUIの操作で画像を削除する関数
* @param MIS イメージセットオブジェクト
*/
void OgreRTCApplication::DestroyQtImage(ImageSetObj *MIS)
{
	DestroyImage(MIS);

	std::vector<ImageSetObj*>::iterator end_it = remove( QtImageSets.begin(), QtImageSets.end(), MIS );
	QtImageSets.erase( end_it, QtImageSets.end() );
}

/**
*@brief 全画像削除の関数
*/
void OgreRTCApplication::DestroyAllImage()
{
	for(int i=0;i < ImageSetObjs.size();i++)
	{
		//CEGUI::ImageManager::getSingleton().destroy(ImageSetObjs[i]->Image->getName());

		//mRenderer->destroyTexture(*ImageSetObjs[i]->texture);
	}

	ImageSetObjs.clear();

}

/**
*@brief 3Dモデルの作成の関数
* @param n 名前
* @param s ファイル名
* @return ボディオブジェクト
*/
LinkObj *OgreRTCApplication::SetBody(const char* n, const char* s)
{
	LinkObj *link = new LinkObj(n);
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
	NodeObjs.push_back(link->mNode);
	link->mNode->AddObj(link);
	LinkObjs.push_back(link);

	return link;
}

/**
*@brief ボディオブジェクトの再生成の関数
* @param link ボディオブジェクト
*/
void OgreRTCApplication::CreateQtBody(LinkObj *link)
{
	link->mEntity = mSceneMgr->createEntity(link->filename);
	link->mEntity->setQueryFlags(1<<0);
	NodeObj *mn = getNodeByName(link->mNode->name.c_str());
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
		NodeObj *mnl = getNodeByName(link->NodeList[i]->name.c_str());
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

	LinkObjs.push_back(link);

	//link->name =link->mEntity->getName().c_str();
}


/**
*@brief GUIの操作でボディを作成する関数
* @param n 名前
* @param s ファイル名
* @return ボディオブジェクト
*/
LinkObj *OgreRTCApplication::SetQtBody(const char* n, const char* s)
{
	LinkObj *link = SetBody(n,s);
	QtNodes.push_back(link->mNode);
	QtLinks.push_back(link);

	return link;
}

/**
*@brief 地面削除の関数
*/
void OgreRTCApplication::DestroyFloor()
{
	Floor->mNode->mNode->detachObject(Floor->mEntity);
	mSceneMgr->destroyEntity(Floor->mEntity);

	mSceneMgr->destroySceneNode(Floor->mNode->mNode);

	Ogre::MeshManager::getSingleton().remove(Floor->mp.get()->getHandle());

	Floor = NULL;
}

/**
*@brief GUIの操作で地面を削除する関数
*/
void OgreRTCApplication::DestroyQtFloor()
{
	if(qtFloor)
	{
		DestroyFloor();

		qtFloor = NULL;
	}
}

/**
*@brief 3Dモデルの削除の関数
* @param link ボディオブジェクト
*/
void OgreRTCApplication::DestroyBody(LinkObj *link)
{
	link->mNode->mNode->detachObject(link->mEntity);
	mSceneMgr->destroyEntity(link->mEntity);

	link->mNode->RemoveObj(link);
	DestroyNode(link->mNode);

	std::vector<LinkObj*>::iterator end_it = remove( LinkObjs.begin(), LinkObjs.end(), link );
	LinkObjs.erase( end_it, LinkObjs.end() );

	
}

/**
*@brief GUIの操作でボディを削除する関数
* @param link ボディオブジェクト
*/
void OgreRTCApplication::DestroyQtBody(LinkObj *link)
{
	DestroyBody(link);

	DestroyQtNode(link->mNode);

	std::vector<LinkObj*>::iterator end_it = remove( QtLinks.begin(), QtLinks.end(), link );
	QtLinks.erase( end_it, QtLinks.end() );
}

/**
*@brief 全ての3Dモデルの削除の関数
*/
void OgreRTCApplication::DestroyAllBody()
{
	for(int i=0;i < LinkObjs.size();i++)
	{
		LinkObjs[i]->mNode->mNode->detachObject(LinkObjs[i]->mEntity);
		mSceneMgr->destroyEntity(LinkObjs[i]->mEntity);

		LinkObjs[i]->mNode->RemoveObj(LinkObjs[i]);
		DestroyNode(LinkObjs[i]->mNode);
	}

	LinkObjs.clear();
}




/**
*@brief 光源の位置設定の関数
* @param x 位置(X)
* @param y 位置(Y)
* @param z 位置(Z)
*/
void OgreRTCApplication::SetLightPosition(float x, float y, float z)
{
	light->setPosition(x, y, z);
	LightX = x;
	LightY = y;
	LightZ = z;
}

/**
*@brief 影の色の設定の関数
* @param r 輝度(赤)
* @param g 輝度(緑)
* @param b 輝度(青)
*/
void OgreRTCApplication::SetShadowColour(float r, float g, float b)
{
	mSceneMgr->setShadowColour(Ogre::ColourValue(r, g, b));
	ShadowR = r;
	ShadowG = g;
	ShadowB = b;
}

/**
*@brief 光源の色の設定の関数
* @param r 輝度(赤)
* @param g 輝度(緑)
* @param b 輝度(青)
*/
void OgreRTCApplication::SetLightColor(float r, float g, float b)
{
	light->setDiffuseColour(r,g,b);
	LightR = r;
	LightG = g;
	LightB = b;
	//light->setSpecularColour(r,g,b);
}

/**
*@brief サブウインドウ作成の関数
* @param wName 名前
* @param texName テクスチャ名
* @param camName カメラ名
* @param ImageSetName イメージセット名
* @param ImageName イメージ名
* @return サブウインドウオブジェクト
*/
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



	sw->guiTex = &mRenderer->createTexture(texName, sw->tex);

	/*sw->Image =
	&CEGUI::ImageManager::getSingleton().create(ImageSetName, *sw->guiTex);
	sw->Image->defineImage(ImageName,
		CEGUI::Vector2f(0.0f, 0.0f),
		CEGUI::Size<float>(sw->guiTex->getSize().d_width,
		sw->guiTex->getSize().d_height),
		CEGUI::Vector2f(0.0f, 0.0f));

	*/

	const CEGUI::Rectf rect(CEGUI::Vector2f(0.0f, 0.0f), sw->guiTex->getOriginalDataSize());
	CEGUI::ImageManager::getSingleton().addImageType<CEGUI::BasicImage>("RTTImageset");
	sw->Image = static_cast<CEGUI::BasicImage*>(&CEGUI::ImageManager::getSingleton().create("RTTImageset", ImageName));
	sw->Image->setTexture(sw->guiTex);
	sw->Image->setArea(rect);
	sw->Image->setAutoScaled(CEGUI::ASM_Both);

	//sw->label->setProperty("Image", CEGUI::PropertyHelper::imageToString(&sw->Image->getImage(ImageName)));
	sw->label->setProperty("Image", ImageName);


	sheet->addChild(sw->label);

	SubWindows.push_back(sw);

	return sw;
}

/**
*@brief サブウインドウオブジェクトの再生成の関数
* @param sw サブウインドウオブジェクト
*/
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



	sw->guiTex = &mRenderer->createTexture(sw->Tname, sw->tex);

	/*sw->Image =
	&CEGUI::ImageManager::getSingleton().create(sw->ISname, *sw->guiTex);
	sw->Image->defineImage(sw->Iname,
		CEGUI::Vector2f(0.0f, 0.0f),
		CEGUI::Size<float>(sw->guiTex->getSize().d_width,
		sw->guiTex->getSize().d_height),
		CEGUI::Vector2f(0.0f, 0.0f));*/

	const CEGUI::Rectf rect(CEGUI::Vector2f(0.0f, 0.0f), sw->guiTex->getOriginalDataSize());
	CEGUI::ImageManager::getSingleton().addImageType<CEGUI::BasicImage>("RTTImageset");
	sw->Image = static_cast<CEGUI::BasicImage*>(&CEGUI::ImageManager::getSingleton().create("RTTImageset", sw->Iname));
	sw->Image->setTexture(sw->guiTex);
	sw->Image->setArea(rect);
	sw->Image->setAutoScaled(CEGUI::ASM_Both);

	

	//sw->label->setProperty("Image", CEGUI::PropertyHelper::imageToString(&sw->Image->getImage(sw->Iname)));
	sw->label->setProperty("Image", sw->Iname);


	sheet->addChild(sw->label);

	sw->SetPosition(sw->pos_x, sw->pos_y);
	sw->SetSize(sw->size_x, sw->size_y);
	sw->SetVisible(sw->visi);
	sw->UpdateCameraPQ(sw->campos_x,sw->campos_y,sw->campos_z,sw->cam_roll,sw->cam_pitch,sw->cam_yaw,sw->cam_len);

	SubWindows.push_back(sw);
}

/**
*@brief GUIの操作でサブウインドウを作成する関数
* @param wName 名前
* @param texName テクスチャ名
* @param camName カメラ名
* @param ImageSetName イメージセット名
* @param ImageName イメージ名
* @return サブウインドウオブジェクト
*/
SubWindow *OgreRTCApplication::SetQtSubWindow(const char* wName, const char* texName, const char* camName, const char* ImageSetName, const char* ImageName)
{
	SubWindow* sw = SetSubWindow(wName,texName,camName,ImageSetName,ImageName);
	QtSubWindows.push_back(sw);

	return sw;
}

/**
*@brief サブウインドウ削除の関数
* @param sw サブウインドウオブジェクト
*/
void OgreRTCApplication::DestroySubWindow(SubWindow *sw)
{
	Destroycegui(sw->label);
	CEGUI::ImageManager::getSingleton().destroy(sw->Image->getName());
	//sw->Image->undefineImage(sw->Iname.c_str());
	mRenderer->destroyTexture(*sw->guiTex);
	
	mSceneMgr->destroyCamera(sw->cam->getName());

	

	//mRenderer->destroyTexture(*sw->guiTex);

	std::vector<SubWindow*>::iterator end_it = remove( SubWindows.begin(), SubWindows.end(), sw );
	SubWindows.erase( end_it, SubWindows.end() );
}

/**
*@brief GUIの操作でサブウインドウを削除する関数
* @param sw サブウインドウオブジェクト
*/
void OgreRTCApplication::DestroyQtSubWindow(SubWindow *sw)
{
	DestroySubWindow(sw);

	std::vector<SubWindow*>::iterator end_it = remove( QtSubWindows.begin(), QtSubWindows.end(), sw );
	QtSubWindows.erase( end_it, QtSubWindows.end() );

}

/**
*@brief サブウインドウ全削除の関数
*/
void OgreRTCApplication::DestroyAllSubWindow()
{
	for(int i=0;i < SubWindows.size();i++)
	{
		Destroycegui(SubWindows[i]->label);
		CEGUI::ImageManager::getSingleton().destroy(SubWindows[i]->Image->getName());
		//SubWindows[i]->Image->undefineImage(SubWindows[i]->Iname);
		mRenderer->destroyTexture(*SubWindows[i]->guiTex);
		
		mSceneMgr->destroyCamera(SubWindows[i]->cam->getName());

		

		//mRenderer->destroyTexture(*SubWindows[i]->guiTex);
	}
	SubWindows.clear();
}

/**
*@brief サブウインドウ動停止の関数
* @param sw サブウインドウオブジェクト
*/
void OgreRTCApplication::StopSubWindow(SubWindow *sw)
{
	sw->label->clearProperties();
	CEGUI::ImageManager::getSingleton().destroy(sw->Image->getName());
	//sw->Image->undefineImage(sw->Iname);
	//mRenderer->destroyTexture(*sw->guiTex);
	
	mSceneMgr->destroyCamera(sw->Cname);

	

	mRenderer->destroyTexture(*sw->guiTex);
}



/**
*@brief サブウインドウ動作再開の関数
* @param sw サブウインドウオブジェクト
*/
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



	

	
	

	sw->guiTex = &mRenderer->createTexture(sw->Tname, sw->tex);

	/*sw->Image =
	&CEGUI::ImageManager::getSingleton().create(sw->ISname, *sw->guiTex);
	sw->Image->defineImage(sw->Iname,
		CEGUI::Vector2f(0.0f, 0.0f),
		CEGUI::Size<float>(sw->guiTex->getSize().d_width,
		sw->guiTex->getSize().d_height),
		CEGUI::Vector2f(0.0f, 0.0f));*/

	const CEGUI::Rectf rect(CEGUI::Vector2f(0.0f, 0.0f), sw->guiTex->getOriginalDataSize());
	CEGUI::ImageManager::getSingleton().addImageType<CEGUI::BasicImage>("RTTImageset");
	sw->Image = static_cast<CEGUI::BasicImage*>(&CEGUI::ImageManager::getSingleton().create("RTTImageset", sw->Iname));
	sw->Image->setTexture(sw->guiTex);
	sw->Image->setArea(rect);
	sw->Image->setAutoScaled(CEGUI::ASM_Both);

	sw->label->setProperty("Image", sw->Iname);
	//sw->label->setProperty("Image", CEGUI::PropertyHelper::imageToString(&sw->Image->getImage(sw->Iname)));


	//sheet->addChild(sw.label);
}




/**
*@brief FPS設定の関数
* @param st FPS
*/
void OgreRTCApplication::SetSleepTime(int st)
{
	SleepTime = st;
}







/**
*@brief ウインドウのサイズ取得の関数
* @return サイズ
*/
Ogre::Vector2 OgreRTCApplication::getRenderWindowSize()
{
	return Ogre::Vector2(mWindow->getWidth(), mWindow->getHeight());
}

/**
*@brief カーソル位置の3Dモデルを取得の関数
* @param screenX 位置(X)
* @param screenY 位置(Y)
* @return ボディオブジェクト
*/
LinkObj* OgreRTCApplication::GetQueryScene(float screenX, float screenY)
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
		
		for(int i=0;i < LinkObjs.size();i++)
		{
			if(LinkObjs[i]->mEntity->getName() == obj->getName())
			{
				return LinkObjs[i];
			}
		}
		
	}

	return NULL;


}

/**
*@brief 3Dモデルの名前を取得の関数
* @param link ボディオブジェクト
* @return 名前
*/
std::string OgreRTCApplication::GetBodyName(LinkObj *link)
{
	//return link.mNode->getName().c_str();
	return link->mEntity->getName().c_str();
}

/**
*@brief ファイルシステムの追加の関数
* @param name ファイルパス
*/
void OgreRTCApplication::AddFileSystem(const char *name)
{
	std::stringstream ss;
	ss << "MyFile" << FileSystems.size();
	Ogre::ResourceGroupManager::getSingleton().createResourceGroup(ss.str().c_str());
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, "FileSystem",ss.str().c_str());
	Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup(ss.str().c_str());
	FileSystems.push_back(name);
}


/**
*@brief アニメーション作成の関数
* @param name 名前
* @param t 終了時間
* @return アニメーションオブジェクト
*/
AnimationObj *OgreRTCApplication::CreateAnimation(const char* name, float t)
{
	AnimationObj *man = new AnimationObj(name);
	man->anim = mSceneMgr->createAnimation(name, t);
	man->anim->setInterpolationMode(Ogre::Animation::IM_SPLINE);

	man->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	man->track = man->anim->createNodeTrack(1, man->mNode->mNode);

	man->mstate = mSceneMgr->createAnimationState(name);
	man->mstate->setEnabled(true);

	NodeObjs.push_back(man->mNode);
	man->mNode->AddObj(man);
	AnimationObjs.push_back(man);


	
	man->Time = t;

	return man;
}

/**
*@brief GUIの操作でアニメーションを作成する関数
* @param name 名前
* @param t 終了時間
* @return アニメーションオブジェクト
*/
AnimationObj *OgreRTCApplication::CreateQtAnimation(const char* name, float t)
{
	AnimationObj *man = CreateAnimation(name, t);
	QtNodes.push_back(man->mNode);
	QtAnimations.push_back(man);

	return man;
}

/**
*@brief アニメーションオブジェクトの再生成の関数
* @param man アニメーションオブジェクト
*/
void OgreRTCApplication::CreateQtAnimation(AnimationObj *man)
{
	man->anim = mSceneMgr->createAnimation(man->name, man->Time);
	man->anim->setInterpolationMode(Ogre::Animation::IM_SPLINE);

	NodeObj *mn = getNodeByName(man->mNode->name.c_str());
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

	AnimationObjs.push_back(man);
}

/**
*@brief アニメーション削除の関数
* @param man アニメーションオブジェクト
*/
void OgreRTCApplication::DestroyAnimation(AnimationObj *man)
{
	mSceneMgr->destroyAnimation(man->anim->getName());
	
	
	man->mNode->RemoveObj(man);
	DestroyNode(man->mNode);

	std::vector<AnimationObj*>::iterator end_it = remove( AnimationObjs.begin(), AnimationObjs.end(), man );
	AnimationObjs.erase( end_it, AnimationObjs.end() );
}

/**
*@brief GUIの操作でアニメーションを削除する関数
* @param man アニメーションオブジェクト
*/
void OgreRTCApplication::DestroyQtAnimation(AnimationObj *man)
{
	DestroyAnimation(man);
	DestroyQtNode(man->mNode);

	std::vector<AnimationObj*>::iterator end_it = remove( QtAnimations.begin(), QtAnimations.end(), man );
	QtAnimations.erase( end_it, QtAnimations.end() );
}

/**
*@brief アニメーション全削除の関数
*/
void OgreRTCApplication::DestroyAllAnimation()
{
	for(int i=0;i < AnimationObjs.size();i++)
	{
		mSceneMgr->destroyAnimation(AnimationObjs[i]->anim->getName());
		
		AnimationObjs[i]->mNode->RemoveObj(AnimationObjs[i]);
		DestroyNode(AnimationObjs[i]->mNode);
	}
	AnimationObjs.clear();
}


/**
*@brief 光源作成の関数
* @param name 名前
* @return 光源オブジェクト
*/
LightObj *OgreRTCApplication::CreateLight(const char* name)
{
	LightObj *ml = new LightObj(name);
	
	ml->light = mSceneMgr->createLight();
	ml->light->setType(Ogre::Light::LT_POINT);
	ml->light->setSpecularColour(Ogre::ColourValue::White);

	ml->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ml->mNode->mNode->setPosition(Ogre::Vector3(0,0,0));
	ml->mNode->mNode->attachObject(ml->light);

	NodeObjs.push_back(ml->mNode);
	ml->mNode->AddObj(ml);
	LightObjs.push_back(ml);

	

	return ml;
}

/**
*@brief GUIの操作で光源を作成する関数
* @param name 名前
* @return 光源オブジェクト
*/
LightObj *OgreRTCApplication::CreateQtLight(const char* name)
{
	LightObj *ml = CreateLight(name);

	QtNodes.push_back(ml->mNode);
	QtLights.push_back(ml);
	return ml;
}

/**
*@brief 光源オブジェクトの再生成の関数
* @param ml 光源オブジェクト
*/
void OgreRTCApplication::CreateQtLight(LightObj *ml)
{
	ml->light = mSceneMgr->createLight();
	ml->light->setType(Ogre::Light::LT_POINT);

	NodeObj *mn = getNodeByName(ml->mNode->name.c_str());
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

	LightObjs.push_back(ml);

}

/**
*@brief 光源削除の関数
* @param ml 光源オブジェクト
*/
void OgreRTCApplication::DestroyLight(LightObj *ml)
{
	ml->mNode->mNode->detachObject(ml->light);
	mSceneMgr->destroyLight(ml->light);
	
	ml->mNode->RemoveObj(ml);
	DestroyNode(ml->mNode);


	
	std::vector<LightObj*>::iterator end_it = remove( LightObjs.begin(), LightObjs.end(), ml );
	LightObjs.erase( end_it, LightObjs.end() );
}

/**
*@brief GUIの操作で光源を削除する関数
* @param ml 光源オブジェクト
*/
void OgreRTCApplication::DestroyQtLight(LightObj *ml)
{
	DestroyLight(ml);
	DestroyQtNode(ml->mNode);
	std::vector<LightObj*>::iterator end_it = remove( QtLights.begin(), QtLights.end(), ml );
	QtLights.erase( end_it, QtLights.end() );
}

/**
*@brief 全光源削除の関数
*/
void OgreRTCApplication::DestroyAllLight()
{
	for(int i=0;i < LightObjs.size();i++)
	{
		LightObjs[i]->mNode->mNode->detachObject(LightObjs[i]->light);
		mSceneMgr->destroyLight(LightObjs[i]->light);
		LightObjs[i]->mNode->RemoveObj(LightObjs[i]);
		DestroyNode(LightObjs[i]->mNode);
	}
	LightObjs.clear();
}

/**
*@brief 名前から光源オブジェクトを取得
* @param name 名前
* @return 光源オブジェクト
*/
LightObj* OgreRTCApplication::getLightByName(const char* name)
{
	for(int i=0;i < LightObjs.size();i++)
	{
		if(LightObjs[i]->name == name)
		{
			return LightObjs[i];
		}
	}
	return NULL;
}

/**
*@brief 名前からアニメーションオブジェクトを取得
* @param name 名前
* @return アニメーションオブジェクト
*/
AnimationObj* OgreRTCApplication::getAnimationByName(const char* name)
{
	for(int i=0;i < AnimationObjs.size();i++)
	{
		if(AnimationObjs[i]->name == name)
		{
			return AnimationObjs[i];
		}
	}
	return NULL;
}


/**
*@brief ノードの接続の関数
* @param obj1 ボディオブジェクト
* @param obj2 パーティクルオブジェクト
*/
void OgreRTCApplication::AttachObj(LinkObj *obj1, ParticleObj *obj2)
{
	AttachObj(obj2, obj2->particleSystem, obj1);
}

/**
*@brief ノードの接続の関数
* @param obj1 ボディオブジェクト
* @param obj2 光源オブジェクト
*/
void OgreRTCApplication::AttachObj(LinkObj *obj1, LightObj *obj2)
{
	AttachObj(obj2, obj2->light, obj1);
}

/**
*@brief ノードの接続の関数
* @param obj1 パーティクルオブジェクト
* @param obj2 光源オブジェクト
*/
void OgreRTCApplication::AttachObj(ParticleObj *obj1, LightObj *obj2)
{
	AttachObj(obj2, obj2->light, obj1);
}

/**
*@brief ノードの接続の関数
* @param obj1 ボディオブジェクト
* @param obj2 ボディオブジェクト
*/
void OgreRTCApplication::AttachObj(LinkObj *obj1, LinkObj *obj2)
{
	AttachObj(obj2, obj2->mEntity, obj1);
}

/**
*@brief ノードの接続の関数
* @param obj1 パーティクルオブジェクト
* @param obj2 パーティクルオブジェクト
*/
void OgreRTCApplication::AttachObj(ParticleObj *obj1, ParticleObj *obj2)
{
	AttachObj(obj2, obj2->particleSystem, obj1);
}

/**
*@brief ノードの接続の関数
* @param obj1 光源オブジェクト
* @param obj2 光源オブジェクト
*/
void OgreRTCApplication::AttachObj(LightObj *obj1, LightObj *obj2)
{
	AttachObj(obj2, obj2->light, obj1);
}

/**
*@brief ノードの接続の関数
* @param obj1 アニメーションオブジェクト
* @param obj2 ボディオブジェクト
*/
void OgreRTCApplication::AttachObj(AnimationObj *obj1, LinkObj *obj2)
{
	AttachObj(obj2, obj2->mEntity, obj1);
}

/**
*@brief ノードの接続の関数
* @param obj1 アニメーションオブジェクト
* @param obj2 光源オブジェクト
*/
void OgreRTCApplication::AttachObj(AnimationObj *obj1, LightObj *obj2)
{
	AttachObj(obj2, obj2->light, obj1);
}

/**
*@brief ノードの接続の関数
* @param obj1 アニメーションオブジェクト
* @param obj2 パーティクルオブジェクト
*/
void OgreRTCApplication::AttachObj(AnimationObj *obj1, ParticleObj *obj2)
{
	AttachObj(obj2, obj2->particleSystem, obj1);
}

/**
*@brief ノードの接続の関数
* @param n1 ベースオブジェクト
* @param o1 可動オブジェクト1
* @param o2 可動オブジェクト2
*/
void OgreRTCApplication::AttachObj(ObjectBase *n1, Ogre::MovableObject *o1,ObjectBase *n2)
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


/**
*@brief ノード分離の関数
* @param obj1 ボディオブジェクト
*/
void OgreRTCApplication::DeatachObj(LinkObj *obj1)
{
	DeatachObj(obj1, obj1->mEntity);
}

/**
*@brief ノード分離の関数
* @param obj1 パーティクルオブジェクト
*/
void OgreRTCApplication::DeatachObj(ParticleObj *obj1)
{
	DeatachObj(obj1, obj1->particleSystem);
}

/**
*@brief ノード分離の関数
* @param obj1 光源オブジェクト
*/
void OgreRTCApplication::DeatachObj(LightObj *obj1)
{
	DeatachObj(obj1, obj1->light);
}

/**
*@brief ノード分離の関数
* @param n1 ベースオブジェクト
* @param o1 可動オブジェクト
*/
void OgreRTCApplication::DeatachObj(ObjectBase *n1, Ogre::MovableObject *o1)
{
	static int Dn = 0;
	if(n1->mNode->mobj.size() > 1)
	{
		n1->mNode->mNode->detachObject(o1);
		n1->mNode->RemoveObj(n1);
		std::stringstream ss;
		ss << "DeatachObj" << Dn;
		n1->mNode = new NodeObj(ss.str());

		n1->mNode->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		n1->mNode->mNode->attachObject(o1);
		n1->mNode->AddObj(n1);

		NodeObjs.push_back(n1->mNode);
		QtNodes.push_back(n1->mNode);
	}
}

/**
*@brief 名前からノードオブジェクトを取得
* @param name 名前
* @return ノードオブジェクト
*/
NodeObj* OgreRTCApplication::getNodeByName(const char* name)
{
	for(int i=0;i < NodeObjs.size();i++)
	{
		if(NodeObjs[i]->name == name)
		{
			return NodeObjs[i];
		}
	}
	return NULL;
}

/**
*@brief ノードオブジェクトの再生成の関数
* @param mn ノードオブジェクト
*/
void OgreRTCApplication::CreateQtNode(NodeObj *mn)
{
	mn->mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	
}

/**
*@brief ノード削除の関数
* @param mn ノードオブジェクト
*/
void OgreRTCApplication::DestroyNode(NodeObj *mn)
{
	
	if(mn->mobj.size() == 0)
	{
		mSceneMgr->destroySceneNode(mn->mNode);
		std::vector<NodeObj*>::iterator end_it = remove( NodeObjs.begin(), NodeObjs.end(), mn );
		NodeObjs.erase( end_it, NodeObjs.end() );
	}
	
}

/**
*@brief GUIの操作でノードを削除する関数
* @param mn ノードオブジェクト
*/
void OgreRTCApplication::DestroyQtNode(NodeObj *mn)
{
	if(mn->mobj.size() == 0)
	{
		std::vector<NodeObj*>::iterator end_it = remove( QtNodes.begin(), QtNodes.end(), mn );
		QtNodes.erase( end_it, QtNodes.end() );
	}
	
}

/**
*@brief 全ノードの削除の関数
*/
void OgreRTCApplication::DestroyAllNode()
{
	for(int i=0;i < NodeObjs.size();i++)
	{
		NodeObjs[i]->mNode->detachAllObjects();
		mSceneMgr->destroySceneNode(NodeObjs[i]->mNode);
	}
	NodeObjs.clear();
}

/**
*@brief シミュレーションの3Dモデルの作成
* @param obj ボディオブジェクト
*/
void OgreRTCApplication::CreateODEObj(LinkObj *obj)
{
	obj->mEntity = mSceneMgr->createEntity(obj->filename);
	obj->mEntity->setQueryFlags(1<<0);
	NodeObj *mn = getNodeByName(obj->mNode->name.c_str());
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
		NodeObj *mnl = getNodeByName(obj->NodeList[i]->name.c_str());
		if(mnl)
		{
			obj->NodeList[i] = mnl;
		}
		
	}
	obj->mEntity->setCastShadows(true);
	obj->mNode->mNode->attachObject(obj->mEntity);
	obj->mNode->mNode->scale(Ogre::Vector3(1,1,1));
	obj->mNode->mNode->setPosition(Ogre::Vector3(0,0,0));
	
	
	
	NodeObjs.push_back(obj->mNode);
	obj->mNode->AddObj(obj);
}



/**
*@brief シミュレーションの3Dモデルの削除
* @param obj ボディオブジェクト
*/
void OgreRTCApplication::DestroyODEObj(LinkObj *obj)
{
	obj->mNode->mNode->detachObject(obj->mEntity);
	mSceneMgr->destroyEntity(obj->mEntity);

	obj->mNode->RemoveObj(obj);
	DestroyNode(obj->mNode);

}

/**
*@brief ファイル読み込みの関数
* @param s ファイル名
*/
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


/**
*@brief ファイル書き込みの関数
* @param s ファイル名
* @return trueで成功、falseで失敗
*/
bool OgreRTCApplication::openb(std::string s)
{
	std::ifstream ifs( s.c_str() , ios::in | ios::binary );
	if(!ifs)return false;
	
	newfile();

	int NodeNum;
	ifs.read( (char*)&NodeNum, sizeof(NodeNum) );
	for(int i=0;i < NodeNum;i++)
	{
		NodeObj *mn = new NodeObj("");
		mn->openb(ifs);
		CreateQtNode(mn);
		QtNodes.push_back(mn);
		NodeObjs.push_back(mn);
	}

	mSim->openb(ifs);
	

	int BodyNum;
	ifs.read( (char*)&BodyNum, sizeof(BodyNum) );
	for(int i=0;i < BodyNum;i++)
	{
		LinkObj *ml = new LinkObj("");
		ml->openb(ifs);
		CreateQtBody(ml);
		QtLinks.push_back(ml);
		LinkObjs.push_back(ml);
	}

	int ParticleNum;
	ifs.read( (char*)&ParticleNum, sizeof(ParticleNum) );
	for(int i=0;i < ParticleNum;i++)
	{
		ParticleObj *mp = new ParticleObj("");
		mp->openb(ifs);
		CreateQtParticle(mp);
		QtParticles.push_back(mp);
		ParticleObjs.push_back(mp);
	}

	int ImageNum;
	ifs.read( (char*)&ImageNum, sizeof(ImageNum) );
	for(int i=0;i < ImageNum;i++)
	{
		ImageSetObj *mi = new ImageSetObj();
		mi->openb(ifs);
		CreateQtImage(mi);
		QtImageSets.push_back(mi);
		ImageSetObjs.push_back(mi);
	}
	
	int GUINum;
	ifs.read( (char*)&GUINum, sizeof(GUINum) );
	for(int i=0;i < GUINum;i++)
	{
		GUIObj *mg = new GUIObj();
		mg->openb(ifs);
		CreateQtGUI(mg);
		QtGUIs.push_back(mg);
		GUIObjs.push_back(mg);
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
		AnimationObj *man = new AnimationObj("");
		man->openb(ifs);
		CreateQtAnimation(man);
		QtAnimations.push_back(man);
		AnimationObjs.push_back(man);
	}


	int LightNum;
	ifs.read( (char*)&LightNum, sizeof(LightNum) );
	for(int i=0;i < LightNum;i++)
	{
		LightObj *ml = new LightObj("");
		ml->openb(ifs);
		CreateQtLight(ml);
		QtLights.push_back(ml);
		LightObjs.push_back(ml);
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

/**
*@brief 初期化の関数
* @return trueで成功、falseで失敗
*/
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

/**
*@brief リセットの関数
*/
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

/**
*@brief RTCが起動出来たときに呼び出す関数
*/
void OgreRTCApplication::SetRTC()
{
	RTCFlag = true;
}

/**
*@brief カメラをGUIで設定した位置に固定するか設定する関数
* @param flag trueで固定、falseで固定解除
*/
void OgreRTCApplication::SetCameraAutoMoveFlag(bool flag)
{
	CameraFlag = flag;
}


/**
*@brief カーソルがGUI上に乗っているか判定する関数
* @param px カーソルの位置(X)
* @param py カーソルの位置(Y)
*/
bool OgreRTCApplication::JudgeMouseOnGUI(float px, float py)
{
	float ipx = px/windowSizeX;
	float ipy = py/windowSizeY;
	for(int i=0;i < GUIObjs.size();i++)
	{
		//std::cout << GUIObjs[i]->pos_x << "\t" << GUIObjs[i]->pos_y << std::endl;
		//std::cout << GUIObjs[i]->size_x << "\t" << GUIObjs[i]->size_y << std::endl;
		//std::cout << ipx << "\t" << ipy << std::endl;
		if(GUIObjs[i]->visi)
		{
			if(GUIObjs[i]->pos_x < ipx && GUIObjs[i]->pos_y < ipy)
			{
				if(GUIObjs[i]->size_x+GUIObjs[i]->pos_x > ipx && GUIObjs[i]->size_y+GUIObjs[i]->pos_y > ipy)
				{
					return true;
			}	}
		}
	}
	return false;
}