#ifndef __OgreRTCApplication_h_
#define __OgreRTCApplication_h_

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

#define windowSizeX 944
#define windowSizeY 708

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
#include "DisplayImage.h"

#include <string>
#include <time.h>
#include <ode/ode.h>





#include <coil/Mutex.h>






class MySimulation;









/*
*Ogre3Dのレンダリング管理クラス
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
	*ファイルシステムの追加の関数
	*/
	void AddFileSystem(const char *name);
	std::vector<std::string> FileSystems;
	
	/*
	*カメラの位置、姿勢、距離の設定の関数
	*/
	void UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len);
	void MoveCameraPos(float dx, float dy);
	void MoveCameraRot(float dx, float dy);

	/*
	*背景画像設定の関数
	*/
	void OgreRTCApplication::setDisplayImage(const char *img, int w, int h);
	

	/*
	*3Dモデルの作成の関数
	*/
	MyLink *SetBody(const char* n,const char* s);
	
	
	/*
	*3Dモデルの色の設定の関数
	*/
	void setEColor(MyLink *ml, float r, float g, float b, float a);
	/*
	*3Dモデルの削除の関数
	*/
	void DestroyBody(MyLink *link);

	/*
	*全ての3Dモデルの削除の関数
	*/
	void DestroyAllBody();

	
	
	/*
	*3Dモデルの名前を取得の関数
	*/
	std::string GetBodyName(MyLink *link);

	/*
	*光源の位置設定の関数
	*/
	void SetLightPosition(float x, float y, float z);
	/*
	*影の色の設定の関数
	*/
	void SetShadowColour(float r, float g, float b);
	/*
	*光源の色の設定の関数
	*/
	void SetLightColor(float r, float g, float b);


	/*
	*カメラの姿勢設定の関数
	*/
	void CameraRoll(float ang);
	void CameraPitch(float ang);
	void CameraYaw(float ang);
	void SetCameraRotation(float r, float p, float y);
	void SetCameraQuaternion(float w, float x, float y, float z);

	/*
	*カメラの位置設定の関数
	*/
	void SetCameraPosition(float x, float y, float z);
	

	/*
	*スタティックイメージ作成の関数
	*/
	MyGUI *CreateStaticImage(const char* name);
	/*
	*スタティックテキスト作成の関数
	*/
	MyGUI *CreateStaticText(const char* name);
	
	/*
	*GUI削除の関数
	*/
	void DestroyGui(MyGUI *label);
	

	void Destroycegui(CEGUI::Window *label);
	void DestroyAllGUI();

	
	

	/*
	*ボタン作成の関数
	*/
	MyGUI *CreateButton(const char* name);
	/*
	*ボタンを押したときに呼び出される関数
	*/
	bool BottonClickedHandler(const CEGUI::EventArgs &event);

	/*
	*テキストエディタ作成の関数
	*/
	MyGUI *CreateEditBox(const char* name);
	
	/*
	*コンボボックス作成の関数
	*/
	MyGUI *CreateComboBox(const char* name);
	

	
	

	/*
	*スライダー作成の関数
	*/
	MyGUI *CreateSlider(const char* name);
	
	/*
	*スライダーの値が変化したときに呼び出される関数
	*/
	bool SliderChangedHandler(const CEGUI::EventArgs &event);

	/*
	*タイトルバー作成の関数
	*/
	MyGUI *CreateTitlebar(const char* name);
	/*
	*フレームウインドウ作成の関数
	*/
	MyGUI *CreateFrameWindow(const char* name);
	/*
	*縦スクロールバー作成の関数
	*/
	MyGUI *CreateVerticalScrollbar(const char* name);
	/*
	*横スクロールバー作成の関数
	*/
	MyGUI *CreateHorizontalScrollbar(const char* name);
	/*
	*プログレスバー作成の関数
	*/
	MyGUI *CreateProgressBar(const char* name);
	/*
	*マルチラインエディット作成の関数
	*/
	MyGUI *CreateMultiLineEditbox(const char* name);
	/*
	*リストボックス作成の関数
	*/
	MyGUI *CreateListbox(const char* name);
	/*
	*コンボドロップリスト作成の関数
	*/
	MyGUI *CreateComboDropList(const char* name);
	/*
	*チェックボックス作成の関数
	*/
	MyGUI *CreateCheckbox(const char* name);
	/*
	*ラジオボタン作成の関数
	*/
	MyGUI *CreateRadioButton(const char* name);
	/*
	*ツールチップ作成の関数
	*/
	MyGUI *CreateTooltip(const char* name);
	/*
	*アイテムリストボックス作成の関数
	*/
	MyGUI *CreateItemListbox(const char* name);
	/*
	*リストボックスアイテム作成の関数
	*/
	MyGUI *CreateListboxItem(const char* name);
	/*
	*スピナー作成の関数
	*/
	MyGUI *CreateSpinner(const char* name);
	/*
	*スクロールブルペーン作成の関数
	*/
	MyGUI *CreateScrollablePane(const char* name);
	/*
	*リストヘッダーセグメント作成の関数
	*/
	MyGUI *CreateListHeaderSegment(const char* name);
	/*
	*リストヘッダー作成の関数
	*/
	MyGUI *CreateListHeader(const char* name);
	/*
	*マルチコロンリスト作成の関数
	*/
	MyGUI *CreateMultiColumnList(const char* name);
	/*
	*メニューアイテム作成の関数
	*/
	MyGUI *CreateMenuItem(const char* name);
	/*
	*メニューバー作成の関数
	*/
	MyGUI *CreateMenubar(const char* name);
	/*
	*ポップアイテムメニュー作成の関数
	*/
	MyGUI *CreatePopupMenu(const char* name);
	/*
	*タブボタンペーン作成の関数
	*/
	MyGUI *CreateTabButtonPane(const char* name);
	/*
	*タブコンテキストペーン作成の関数
	*/
	MyGUI *CreateTabContentPane(const char* name);
	/*
	*タブコントロール作成の関数
	*/
	MyGUI *CreateTabControl(const char* name);


	/*
	*チェックボックスが変化したときに呼び出される関数
	*/
	bool CheckedHandler(const CEGUI::EventArgs &event);
	/*
	*ラジオボタンが変化したときに呼び出される関数
	*/
	bool RadioHandler(const CEGUI::EventArgs &event);
	/*
	*リストボックスの選択が変化したときに呼び出される関数
	*/
	bool ListBoxChangedHandler(const CEGUI::EventArgs &event);
	/*
	*コンボボックスの選択が変化したときに呼び出される関数
	*/
	bool ComboBoxChangedHandler(const CEGUI::EventArgs &event);
	/*
	*スクロールバーが変化したときに呼び出される関数
	*/
	bool ScrollPosChangedHandler(const CEGUI::EventArgs &event);

	/*
	*GUI作成の関数
	*/
	MyGUI *CreateGUI(const char* type, const char* name);

	/*
	*GUIのコールバックを設定する関数
	*/
	void SetCallScript(const char* name, const char* type);
	
	

	/*
	*GUIをキーで押したときに呼び出される関数
	*/
	bool GUIKeyUpHandler(const CEGUI::EventArgs &event);
	/*
	*GUIからキーを離したに呼び出される関数
	*/
	bool GUIKeyDownHandler(const CEGUI::EventArgs &event);


	
	/*
	*更新時に呼び出される関数
	*/
	void update(float t);

	

	/*
	*パーティクル作成の関数
	*/
	myParticle *CreateParticle(const char* name, const char* file_name);
	
	/*
	*パーティクル削除の関数
	*/
	void DestroyParticle(myParticle *ml);
	/*
	*全てパーティクル削除の関数
	*/
	void DestroyAllParticle();

	

	/*
	*スカイボックス作成の関数
	*/
	void SetSkyBox(const char* filename, int Size);
	void RemoveSkyBox();
	
	/*
	*地面作成の関数
	*/
	MyLink *SetFloor(const char* name, const char* name2, const char* filename, int Size, int direction);
	/*
	*地面削除の関数
	*/
	void DestroyFloor();
	
	
	
	/*
	*画像作成の関数
	*/
	MyImageSet *CreateGuiImageSet(const char* name, const char* filename);
	/*
	*画像削除の関数
	*/
	void DestroyImage(MyImageSet *MIS);
	/*
	*全画像削除の関数
	*/
	void DestroyAllImage();

	

	/*
	*アニメーション作成の関数
	*/
	MyAnimation *CreateAnimation(const char* name, float t);
	
	/*
	*アニメーション削除の関数
	*/
	void DestroyAnimation(MyAnimation *man);
	
	/*
	*アニメーション全削除の関数
	*/
	void DestroyAllAnimation();

	
	/*
	*光源作成の関数
	*/
	MyLight *CreateLight(const char* name);
	
	/*
	*光源削除の関数
	*/
	void DestroyLight(MyLight *ml);
	
	/*
	*全光源削除の関数
	*/
	void DestroyAllLight();
	

	/*
	*サブウインドウ作成の関数
	*/
	SubWindow *SetSubWindow(const char* wName, const char* texName, const char* camName, const char* ImageSetName, const char* ImageName);
	void DestroySubWindow(SubWindow *sw);
	void DestroyAllSubWindow();
	void restartSubWindow(SubWindow *sw);
	void StopSubWindow(SubWindow *sw);

	



	/*
	*ウインドウのサイズ取得の関数
	*/
	Ogre::Vector2 getRenderWindowSize();
	/*
	*カーソル位置の3Dモデルを取得の関数
	*/
	MyLink* GetQueryScene(float screenX, float screenY);

	/*
	*FPS設定の関数
	*/
	void SetSleepTime(int st);

	/*
	*RTC読み込みの関数
	*/
	void OpenFile(const char *fname);
	/*
	*RTC削除の関数
	*/
	void CloseFile();
	/*
	*RTCの停止の関数
	*/
	void StopFile();

	/*
	*ノードの接続の関数
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
	*ノード分離の関数
	*/
	void DeatachObj(MyLink *obj1);
	void DeatachObj(myParticle *obj1);
	void DeatachObj(MyLight *obj1);
	void DeatachObj(MyObject *n1, Ogre::MovableObject *o1);

	
	
	/*
	*ノード削除の関数
	*/
	void DestroyNode(MyNode *mn);
	
	/*
	*全ノードの削除の関数
	*/
	void DestroyAllNode();

	/*
	*名前から各オブジェクトを取得
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
	*シミュレーションの3Dモデルの作成
	*/
	void CreateODEObj(MyLink *obj);
	
	/*
	*シミュレーションの3Dモデルの削除
	*/
	void DestroyODEObj(MyLink *obj);

	/*
	*ファイル読み込みの関数
	*/
	void save(std::string s);
	/*
	*ファイル書き込みの関数
	*/
	bool openb(std::string s);
	/*
	*初期化の関数
	*/
	bool newfile();
	/*
	*リセットの関数
	*/
	void reset();
	/*
	*RTCが起動出来たときに呼び出す関数
	*/
	void SetRTC();

	/*
	*GUIの操作のみで作成、削除のできるオブジェクトの作成、削除の関数
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
	*オブジェクトの再生成の関数
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

	void SetCameraAutoMoveFlag(bool flag);

	bool JudgeMouseOnGUI(float px, float py);

	
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

	DisplayImage *displayImg;



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

	bool CameraFlag;

	

 
protected:
    virtual void createScene(void);

	
	coil::Mutex *mu;
	
    
 
    
    

	
	

	Ogre::AnimationState *mAnimationState; // The current animation state of the object
 
	bool quit(const CEGUI::EventArgs &e);

	CEGUI::OgreRenderer* mRenderer;

	CEGUI::Window *sheet;
	
	/*
	*キーを押した時に呼ばれる関数
	*/
	virtual bool keyPressed(QKeyEvent *arg );
	/*
	*キーを離した時に呼ばれる関数
	*/
    virtual bool keyReleased(QKeyEvent *arg );
	/*
	*マウスを動かした時に呼ばれる関数
	*/
    virtual bool mouseMoved(QMouseEvent *arg );
	/*
	*マウスのボタン押した時に呼ばれる関数
	*/
    virtual bool mousePressed(QMouseEvent *arg);
	/*
	*マウスのボタン離した時に呼ばれる関数
	*/
    virtual bool mouseReleased(QMouseEvent *arg);
	bool inputMethodEvent(QInputMethodEvent *arg);

	
	

	

	
	Ogre::Light* light;

	int SleepTime;

	QString PreeditStr;

    // The speed at which the object is moving
};
 
#endif // #ifndef __OgreRTCApplication_h_