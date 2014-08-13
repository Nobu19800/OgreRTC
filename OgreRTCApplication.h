#ifndef __OgreRTCApplication_h_
#define __OgreRTCApplication_h_

#include <CEGUI.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>



#include "MyLink.h"
#include "MyParticle.h"
#include "MyGUI.h"
#include "SubWindow.h"
#include "MyImageSet.h"
#include "MyAnimation.h"
#include "MySimulation.h"
#include "MyLight.h"
#include "MyNode.h"
#include "MyPythonBoost.h"
#include "MyOgreMacro.h"

#include <string>
#include <time.h>
#include <ode/ode.h>





#include <coil/Mutex.h>






class MySimulation;









/*
*Ogre3D�̃����_�����O�Ǘ��N���X
*/
 
class OgreRTCApplication : public BaseApplication, public SingletonT<OgreRTCApplication>
{
	SINGLETON_DEFINE(OgreRTCApplication)
	friend class OgreWidget;
public:
    OgreRTCApplication(void);
    virtual ~OgreRTCApplication(void);
	static OgreRTCApplication* object(void)
	{
		static OgreRTCApplication OgreRTCApplication;
		return &OgreRTCApplication;
	}
	
	
	
	

	/*
	*�t�@�C���V�X�e���̒ǉ��̊֐�
	*/
	void AddFileSystem(const char *name);
	std::vector<std::string> FileSystems;
	
	/*
	*�J�����̈ʒu�A�p���A�����̐ݒ�̊֐�
	*/
	void UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len);
	void MoveCameraPos(float dx, float dy);
	void MoveCameraRot(float dx, float dy);

	

	/*
	*3D���f���̍쐬�̊֐�
	*/
	MyLink *SetBody(const char* n,const char* s);
	
	
	/*
	*3D���f���̐F�̐ݒ�̊֐�
	*/
	void setEColor(MyLink *ml, float r, float g, float b, float a);
	/*
	*3D���f���̍폜�̊֐�
	*/
	void DestroyBody(MyLink *link);

	/*
	*�S�Ă�3D���f���̍폜�̊֐�
	*/
	void DestroyAllBody();

	
	
	/*
	*3D���f���̖��O���擾�̊֐�
	*/
	std::string GetBodyName(MyLink *link);

	/*
	*�����̈ʒu�ݒ�̊֐�
	*/
	void SetLightPosition(float x, float y, float z);
	/*
	*�e�̐F�̐ݒ�̊֐�
	*/
	void SetShadowColour(float r, float g, float b);
	/*
	*�����̐F�̐ݒ�̊֐�
	*/
	void SetLightColor(float r, float g, float b);


	/*
	*�J�����̎p���ݒ�̊֐�
	*/
	void CameraRoll(float ang);
	void CameraPitch(float ang);
	void CameraYaw(float ang);
	void SetCameraRotation(float r, float p, float y);
	void SetCameraQuaternion(float w, float x, float y, float z);

	/*
	*�J�����̈ʒu�ݒ�̊֐�
	*/
	void SetCameraPosition(float x, float y, float z);
	

	/*
	*�X�^�e�B�b�N�C���[�W�쐬�̊֐�
	*/
	MyGUI *CreateStaticImage(const char* name);
	/*
	*�X�^�e�B�b�N�e�L�X�g�쐬�̊֐�
	*/
	MyGUI *CreateStaticText(const char* name);
	
	/*
	*GUI�폜�̊֐�
	*/
	void DestroyGui(MyGUI *label);
	

	void Destroycegui(CEGUI::Window *label);
	void DestroyAllGUI();

	
	

	/*
	*�{�^���쐬�̊֐�
	*/
	MyGUI *CreateButton(const char* name);
	/*
	*�{�^�����������Ƃ��ɌĂяo�����֐�
	*/
	bool BottonClickedHandler(const CEGUI::EventArgs &event);

	/*
	*�e�L�X�g�G�f�B�^�쐬�̊֐�
	*/
	MyGUI *CreateEditBox(const char* name);
	
	/*
	*�R���{�{�b�N�X�쐬�̊֐�
	*/
	MyGUI *CreateComboBox(const char* name);
	

	
	

	/*
	*�X���C�_�[�쐬�̊֐�
	*/
	MyGUI *CreateSlider(const char* name);
	
	/*
	*�X���C�_�[�̒l���ω������Ƃ��ɌĂяo�����֐�
	*/
	bool SliderChangedHandler(const CEGUI::EventArgs &event);

	/*
	*�^�C�g���o�[�쐬�̊֐�
	*/
	MyGUI *CreateTitlebar(const char* name);
	/*
	*�t���[���E�C���h�E�쐬�̊֐�
	*/
	MyGUI *CreateFrameWindow(const char* name);
	/*
	*�c�X�N���[���o�[�쐬�̊֐�
	*/
	MyGUI *CreateVerticalScrollbar(const char* name);
	/*
	*���X�N���[���o�[�쐬�̊֐�
	*/
	MyGUI *CreateHorizontalScrollbar(const char* name);
	/*
	*�v���O���X�o�[�쐬�̊֐�
	*/
	MyGUI *CreateProgressBar(const char* name);
	/*
	*�}���`���C���G�f�B�b�g�쐬�̊֐�
	*/
	MyGUI *CreateMultiLineEditbox(const char* name);
	/*
	*���X�g�{�b�N�X�쐬�̊֐�
	*/
	MyGUI *CreateListbox(const char* name);
	/*
	*�R���{�h���b�v���X�g�쐬�̊֐�
	*/
	MyGUI *CreateComboDropList(const char* name);
	/*
	*�`�F�b�N�{�b�N�X�쐬�̊֐�
	*/
	MyGUI *CreateCheckbox(const char* name);
	/*
	*���W�I�{�^���쐬�̊֐�
	*/
	MyGUI *CreateRadioButton(const char* name);
	/*
	*�c�[���`�b�v�쐬�̊֐�
	*/
	MyGUI *CreateTooltip(const char* name);
	/*
	*�A�C�e�����X�g�{�b�N�X�쐬�̊֐�
	*/
	MyGUI *CreateItemListbox(const char* name);
	/*
	*���X�g�{�b�N�X�A�C�e���쐬�̊֐�
	*/
	MyGUI *CreateListboxItem(const char* name);
	/*
	*�X�s�i�[�쐬�̊֐�
	*/
	MyGUI *CreateSpinner(const char* name);
	/*
	*�X�N���[���u���y�[���쐬�̊֐�
	*/
	MyGUI *CreateScrollablePane(const char* name);
	/*
	*���X�g�w�b�_�[�Z�O�����g�쐬�̊֐�
	*/
	MyGUI *CreateListHeaderSegment(const char* name);
	/*
	*���X�g�w�b�_�[�쐬�̊֐�
	*/
	MyGUI *CreateListHeader(const char* name);
	/*
	*�}���`�R�������X�g�쐬�̊֐�
	*/
	MyGUI *CreateMultiColumnList(const char* name);
	/*
	*���j���[�A�C�e���쐬�̊֐�
	*/
	MyGUI *CreateMenuItem(const char* name);
	/*
	*���j���[�o�[�쐬�̊֐�
	*/
	MyGUI *CreateMenubar(const char* name);
	/*
	*�|�b�v�A�C�e�����j���[�쐬�̊֐�
	*/
	MyGUI *CreatePopupMenu(const char* name);
	/*
	*�^�u�{�^���y�[���쐬�̊֐�
	*/
	MyGUI *CreateTabButtonPane(const char* name);
	/*
	*�^�u�R���e�L�X�g�y�[���쐬�̊֐�
	*/
	MyGUI *CreateTabContentPane(const char* name);
	/*
	*�^�u�R���g���[���쐬�̊֐�
	*/
	MyGUI *CreateTabControl(const char* name);


	/*
	*�`�F�b�N�{�b�N�X���ω������Ƃ��ɌĂяo�����֐�
	*/
	bool CheckedHandler(const CEGUI::EventArgs &event);
	/*
	*���W�I�{�^�����ω������Ƃ��ɌĂяo�����֐�
	*/
	bool RadioHandler(const CEGUI::EventArgs &event);
	/*
	*���X�g�{�b�N�X�̑I�����ω������Ƃ��ɌĂяo�����֐�
	*/
	bool ListBoxChangedHandler(const CEGUI::EventArgs &event);
	/*
	*�R���{�{�b�N�X�̑I�����ω������Ƃ��ɌĂяo�����֐�
	*/
	bool ComboBoxChangedHandler(const CEGUI::EventArgs &event);
	/*
	*�X�N���[���o�[���ω������Ƃ��ɌĂяo�����֐�
	*/
	bool ScrollPosChangedHandler(const CEGUI::EventArgs &event);

	/*
	*GUI�쐬�̊֐�
	*/
	MyGUI *CreateGUI(const char* type, const char* name);

	/*
	*GUI�̃R�[���o�b�N��ݒ肷��֐�
	*/
	void SetCallScript(const char* name, const char* type);
	
	

	/*
	*GUI���L�[�ŉ������Ƃ��ɌĂяo�����֐�
	*/
	bool GUIKeyUpHandler(const CEGUI::EventArgs &event);
	/*
	*GUI����L�[�𗣂����ɌĂяo�����֐�
	*/
	bool GUIKeyDownHandler(const CEGUI::EventArgs &event);


	
	/*
	*�X�V���ɌĂяo�����֐�
	*/
	void update(float t);

	

	/*
	*�p�[�e�B�N���쐬�̊֐�
	*/
	myParticle *CreateParticle(const char* name, const char* file_name);
	
	/*
	*�p�[�e�B�N���폜�̊֐�
	*/
	void DestroyParticle(myParticle *ml);
	/*
	*�S�ăp�[�e�B�N���폜�̊֐�
	*/
	void DestroyAllParticle();

	

	/*
	*�X�J�C�{�b�N�X�쐬�̊֐�
	*/
	void SetSkyBox(const char* filename, int Size);
	void RemoveSkyBox();
	
	/*
	*�n�ʍ쐬�̊֐�
	*/
	MyLink *SetFloor(const char* name, const char* name2, const char* filename, int Size, int direction);
	/*
	*�n�ʍ폜�̊֐�
	*/
	void DestroyFloor();
	
	
	
	/*
	*�摜�쐬�̊֐�
	*/
	MyImageSet *CreateGuiImageSet(const char* name, const char* filename);
	/*
	*�摜�폜�̊֐�
	*/
	void DestroyImage(MyImageSet *MIS);
	/*
	*�S�摜�폜�̊֐�
	*/
	void DestroyAllImage();

	

	/*
	*�A�j���[�V�����쐬�̊֐�
	*/
	MyAnimation *CreateAnimation(const char* name, float t);
	
	/*
	*�A�j���[�V�����폜�̊֐�
	*/
	void DestroyAnimation(MyAnimation *man);
	
	/*
	*�A�j���[�V�����S�폜�̊֐�
	*/
	void DestroyAllAnimation();

	
	/*
	*�����쐬�̊֐�
	*/
	MyLight *CreateLight(const char* name);
	
	/*
	*�����폜�̊֐�
	*/
	void DestroyLight(MyLight *ml);
	
	/*
	*�S�����폜�̊֐�
	*/
	void DestroyAllLight();
	

	/*
	*�T�u�E�C���h�E�쐬�̊֐�
	*/
	SubWindow *SetSubWindow(const char* wName, const char* texName, const char* camName, const char* ImageSetName, const char* ImageName);
	void DestroySubWindow(SubWindow *sw);
	void DestroyAllSubWindow();
	void restartSubWindow(SubWindow *sw);
	void StopSubWindow(SubWindow *sw);

	



	/*
	*�E�C���h�E�̃T�C�Y�擾�̊֐�
	*/
	Ogre::Vector2 getRenderWindowSize();
	/*
	*�J�[�\���ʒu��3D���f�����擾�̊֐�
	*/
	MyLink* GetQueryScene(float screenX, float screenY);

	/*
	*FPS�ݒ�̊֐�
	*/
	void SetSleepTime(int st);

	/*
	*RTC�ǂݍ��݂̊֐�
	*/
	void OpenFile(const char *fname);
	/*
	*RTC�폜�̊֐�
	*/
	void CloseFile();
	/*
	*RTC�̒�~�̊֐�
	*/
	void StopFile();

	/*
	*�m�[�h�̐ڑ��̊֐�
	*/
	void AttachObj(MyLink *obj1, myParticle *obj2);
	void AttachObj(MyLink *obj1, MyLight *obj2);
	void AttachObj(myParticle *obj1, MyLight *obj2);
	void AttachObj(MyLink *obj1, MyLink *obj2);
	void AttachObj(myParticle *obj1, myParticle *obj2);
	void AttachObj(MyLight *obj1, MyLight *obj2);
	void AttachObj(MyAnimation *obj1, MyLink *obj2);
	void AttachObj(MyAnimation *obj1, MyLight *obj2);
	void AttachObj(MyAnimation *obj1, myParticle *obj2);
	void AttachObj(MyObject *n1, Ogre::MovableObject *o1,MyObject *n2);

	/*
	*�m�[�h�����̊֐�
	*/
	void DeatachObj(MyLink *obj1);
	void DeatachObj(myParticle *obj1);
	void DeatachObj(MyLight *obj1);
	void DeatachObj(MyObject *n1, Ogre::MovableObject *o1);

	
	
	/*
	*�m�[�h�폜�̊֐�
	*/
	void DestroyNode(MyNode *mn);
	
	/*
	*�S�m�[�h�̍폜�̊֐�
	*/
	void DestroyAllNode();

	/*
	*���O����e�I�u�W�F�N�g���擾
	*/
	MyLink* getBodyByName(const char* name);
	MyGUI* getGUIByName(const char* name);
	myParticle* getParticleByName(const char* name);
	SubWindow* getSubWindowByName(const char* name);
	MyImageSet* getImageSetByName(const char* name);
	MyLight* getLightByName(const char* name);
	MyAnimation* getAnimationByName(const char* name);
	MyNode* getNodeByName(const char* name);

	/*
	*�V�~�����[�V������3D���f���̍쐬
	*/
	void CreateODEObj(MyLink *obj);
	
	/*
	*�V�~�����[�V������3D���f���̍폜
	*/
	void DestroyODEObj(MyLink *obj);

	/*
	*�t�@�C���ǂݍ��݂̊֐�
	*/
	void save(std::string s);
	/*
	*�t�@�C���������݂̊֐�
	*/
	bool openb(std::string s);
	/*
	*�������̊֐�
	*/
	bool newfile();
	/*
	*���Z�b�g�̊֐�
	*/
	void reset();
	/*
	*RTC���N���o�����Ƃ��ɌĂяo���֐�
	*/
	void SetRTC();

	/*
	*GUI�̑���݂̂ō쐬�A�폜�̂ł���I�u�W�F�N�g�̍쐬�A�폜�̊֐�
	*/
	MyLink *SetQtBody(const char* n,const char* s);
	void DestroyQtBody(MyLink *link);
	MyGUI *CreateQtStaticImage(const char* name);
	MyGUI *CreateQtButton(const char* name);
	MyGUI *CreateQtStaticText(const char* name);
	MyGUI *CreateQtEditBox(const char* name);
	MyGUI *CreateQtComboBox(const char* name);
	MyGUI *CreateQtSlider(const char* name);
	MyGUI *CreateQtGUI(const char* type, const char* name);
	MyGUI *CreateQtTitlebar(const char* name);
	MyGUI *CreateQtFrameWindow(const char* name);
	MyGUI *CreateQtThumb(const char* name);
	MyGUI *CreateQtVerticalScrollbar(const char* name);
	MyGUI *CreateQtHorizontalScrollbar(const char* name);
	MyGUI *CreateQtProgressBar(const char* name);
	MyGUI *CreateQtMultiLineEditbox(const char* name);
	MyGUI *CreateQtListbox(const char* name);
	MyGUI *CreateQtComboDropList(const char* name);
	MyGUI *CreateQtCheckbox(const char* name);
	MyGUI *CreateQtRadioButton(const char* name);
	MyGUI *CreateQtTooltip(const char* name);
	MyGUI *CreateQtItemListbox(const char* name);
	MyGUI *CreateQtListboxItem(const char* name);
	MyGUI *CreateQtSpinner(const char* name);
	MyGUI *CreateQtScrollablePane(const char* name);
	MyGUI *CreateQtListHeaderSegment(const char* name);
	MyGUI *CreateQtListHeader(const char* name);
	MyGUI *CreateQtMultiColumnList(const char* name);
	MyGUI *CreateQtMenuItem(const char* name);
	MyGUI *CreateQtMenubar(const char* name);
	MyGUI *CreateQtPopupMenu(const char* name);
	MyGUI *CreateQtTabButtonPane(const char* name);
	MyGUI *CreateQtTabContentPane(const char* name);
	MyGUI *CreateQtTabControl(const char* name);
	
	void DestroyQtGui(MyGUI *label);
	myParticle *CreateQtParticle(const char* name, const char* file_name);
	void SetQtSkyBox(const char* filename, int Size);
	MyLink *SetQtFloor(const char* name, const char* name2, const char* filename, int Size, int direction);
	void DestroyQtFloor();
	MyImageSet *CreateQtGuiImageSet(const char* name, const char* filename);
	void DestroyQtImage(MyImageSet *MIS);
	MyAnimation *CreateQtAnimation(const char* name, float t);
	void DestroyQtAnimation(MyAnimation *man);
	MyLight *CreateQtLight(const char* name);
	void DestroyQtLight(MyLight *ml);
	SubWindow *SetQtSubWindow(const char* wName, const char* texName, const char* camName, const char* ImageSetName, const char* ImageName);
	void DestroyQtSubWindow(SubWindow *sw);
	void DestroyQtNode(MyNode *mn);


	/*
	*�I�u�W�F�N�g�̍Đ����̊֐�
	*/
	void DestroyQtParticle(myParticle *ml);
	void CreateQtBody(MyLink *link);
	void CreateQtGUI(MyGUI *label);
	void CreateQtParticle(myParticle *ml);
	void CreateQtImage(MyImageSet *MIS);
	void CreateQtSubWindow(SubWindow *sw);
	void CreateQtLight(MyLight *ml);
	void CreateQtAnimation(MyAnimation *man);
	void CreateQtNode(MyNode *mn);

	
	MySimulation *mSim;

	std::vector<MyLink*> MyLinks;
	std::vector<MyGUI*> MyGUIs;
	std::vector<myParticle*> myParticles;
	std::vector<SubWindow*> SubWindows;
	std::vector<MyImageSet*> MyImageSets;
	std::vector<MyAnimation*> MyAnimations;
	std::vector<MyLight*> MyLights;
	std::vector<MyNode*> MyNodes;

	std::vector<MyLink*> QtLinks;
	std::vector<MyGUI*> QtGUIs;
	std::vector<myParticle*> QtParticles;
	std::vector<SubWindow*> QtSubWindows;
	std::vector<MyImageSet*> QtImageSets;
	std::vector<MyAnimation*> QtAnimations;
	std::vector<MyLight*> QtLights;
	std::vector<MyNode*> QtNodes;

	float CamX, CamY, CamZ;
	float CamRoll, CamPitch, CamYaw;
	float CamLen;
	float LightX, LightY, LightZ;
	float ShadowR, ShadowG, ShadowB;
	float LightR, LightG, LightB;

	MyLink *Floor;
	MyLink *qtFloor;

	std::string skyBoxName;
	int skyBoxSize;

	std::string QtskyBoxName;
	int QtskyBoxSize;

	PyObj *po;
	bool RTCFlag;

	

 
protected:
    virtual void createScene(void);

	
	coil::Mutex *mu;
	
    
 
    
    

	
	

	Ogre::AnimationState *mAnimationState; // The current animation state of the object
 
	bool quit(const CEGUI::EventArgs &e);

	CEGUI::OgreRenderer* mRenderer;

	CEGUI::Window *sheet;
	
	/*
	*�L�[�����������ɌĂ΂��֐�
	*/
	virtual bool keyPressed(QKeyEvent *arg );
	/*
	*�L�[�𗣂������ɌĂ΂��֐�
	*/
    virtual bool keyReleased(QKeyEvent *arg );
	/*
	*�}�E�X�𓮂��������ɌĂ΂��֐�
	*/
    virtual bool mouseMoved(QMouseEvent *arg );
	/*
	*�}�E�X�̃{�^�����������ɌĂ΂��֐�
	*/
    virtual bool mousePressed(QMouseEvent *arg);
	/*
	*�}�E�X�̃{�^�����������ɌĂ΂��֐�
	*/
    virtual bool mouseReleased(QMouseEvent *arg);
	bool inputMethodEvent(QInputMethodEvent *arg);

	
	

	

	
	Ogre::Light* light;

	int SleepTime;

	QString PreeditStr;

    // The speed at which the object is moving
};
 
#endif // #ifndef __OgreRTCApplication_h_