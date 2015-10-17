/*!
 * @file  OgreRTCApplication.h
 * @brief Ogre3Dのレンダリング管理クラス
 *
 */

#ifndef __OgreRTCApplication_h_
#define __OgreRTCApplication_h_

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

#define windowSizeX 944
#define windowSizeY 708

#include "LinkObj.h"
#include "ParticleObj.h"
#include "GUIObj.h"
#include "SubWindow.h"
#include "ImageSetObj.h"
#include "AnimationObj.h"
#include "SimulationObj.h"
#include "LightObj.h"
#include "NodeObj.h"
#include "PythonBoostObj.h"
#include "OgreMacro.h"
#include "DisplayImage.h"
#include "CEGUIFunc.h"

#include <string>
#include <time.h>
#include <ode/ode.h>





#include <coil/Mutex.h>






class SimulationObj;










/**
 * @class OgreRTCApplication
*@brief Ogre3Dのレンダリング管理クラス
*/
 
class OgreRTCApplication : public BaseApplication, public SingletonT<OgreRTCApplication>
{
	SINGLETON_DEFINE(OgreRTCApplication)
	friend class OgreWidget;
public:
	/**
	*@brief コンストラクタ
	*/
    OgreRTCApplication(void);
	/**
	*@brief デストラクタ
	*/
    virtual ~OgreRTCApplication(void);
	static OgreRTCApplication* object(void)
	{
		static OgreRTCApplication OgreRTCApplication;
		return &OgreRTCApplication;
	}
	
	
	
	

	
	/**
	*@brief ファイルシステムの追加の関数
	* @param name ファイルパス
	*/
	void AddFileSystem(const char *name);
	std::vector<std::string> FileSystems;
	
	
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
	void UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len);

	/**
	*@brief カメラを移動する関数
	* @param dx 移動距離(X)
	* @param dy 移動距離(Y)
	*/
	void MoveCameraPos(float dx, float dy);
	/**
	*@brief カメラを回転する関数
	* @param dx 回転量(X)
	* @param dy 回転量(Y)
	*/
	void MoveCameraRot(float dx, float dy);

	
	/**
	*@brief 背景画像設定の関数
	* @param img 画像データ
	* @param w 幅
	* @param h 高さ
	*/
	void OgreRTCApplication::setDisplayImage(const char *img, int w, int h);
	

	
	/**
	*@brief 3Dモデルの作成の関数
	* @param n 名前
	* @param s ファイル名
	* @return ボディオブジェクト
	*/
	LinkObj *SetBody(const char* n,const char* s);
	
	
	
	/**
	*@brief 3Dモデルの色の設定の関数
	* @param ml ボディオブジェクト
	* @param r 輝度(赤)
	* @param g 輝度(緑)
	* @param b 輝度(青)
	* @param a 透明度
	*/
	void setEColor(LinkObj *ml, float r, float g, float b, float a);
	
	/**
	*@brief 3Dモデルの削除の関数
	* @param link ボディオブジェクト
	*/
	void DestroyBody(LinkObj *link);

	
	/**
	*@brief 全ての3Dモデルの削除の関数
	*/
	void DestroyAllBody();

	
	
	
	/**
	*@brief 3Dモデルの名前を取得の関数
	* @param link ボディオブジェクト
	* @return 名前
	*/
	std::string GetBodyName(LinkObj *link);

	
	/**
	*@brief 光源の位置設定の関数
	* @param x 位置(X)
	* @param y 位置(Y)
	* @param z 位置(Z)
	*/
	void SetLightPosition(float x, float y, float z);
	
	/**
	*@brief 影の色の設定の関数
	* @param r 輝度(赤)
	* @param g 輝度(緑)
	* @param b 輝度(青)
	*/
	void SetShadowColour(float r, float g, float b);
	
	/**
	*@brief 光源の色の設定の関数
	* @param r 輝度(赤)
	* @param g 輝度(緑)
	* @param b 輝度(青)
	*/
	void SetLightColor(float r, float g, float b);


	
	/**
	*@brief カメラの姿勢(ロール角)設定の関数
	* @param ang 角度(ロール)
	*/
	void CameraRoll(float ang);
	/**
	*@brief カメラの姿勢(ピッチ角)設定の関数
	* @param ang 角度(ピッチ)
	*/
	void CameraPitch(float ang);
	/**
	*@brief カメラの姿勢(ヨー角)設定の関数
	* @param ang 角度(ヨー)
	*/
	void CameraYaw(float ang);
	/**
	*@brief カメラの姿勢設定の関数
	* @param r 角度(ロール)
	* @param p 角度(ピッチ)
	* @param y 角度(ヨー)
	*/
	void SetCameraRotation(float r, float p, float y);
	/**
	*@brief カメラの姿勢(クォータニオン)設定の関数
	* @param w クォータニオン(W)
	* @param x クォータニオン(X)
	* @param y クォータニオン(Y)
	* @param z クォータニオン(Z)
	*/
	void SetCameraQuaternion(float w, float x, float y, float z);

	
	/**
	*@brief カメラの位置設定の関数
	* @param x 位置(X)
	* @param y 位置(Y)
	* @param z 位置(Z)
	*/
	void SetCameraPosition(float x, float y, float z);
	

	
	/**
	*@brief スタティックイメージ作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateStaticImage(const char* name);
	
	/**
	*@brief スタティックテキスト作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateStaticText(const char* name);
	
	/**
	*@brief GUIオブジェクト削除の関数
	* @param label GUIオブジェクト
	*/
	void DestroyGui(GUIObj *label);
	
	/**
	*@brief CEGUIのウインドウ削除の関数
	* @param label ウインドウオブジェクト
	*/
	void Destroycegui(CEGUI::Window *label);
	/**
	*@brief 全てのGUIオブジェクト削除の関数
	*/
	void DestroyAllGUI();

	
	

	
	/**
	*@brief ボタン作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateButton(const char* name);
	
	/**
	*@brief ボタンを押したときに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool BottonClickedHandler(const CEGUI::EventArgs &event);

	
	/**
	*@brief テキストエディタ作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateEditBox(const char* name);
	
	
	/**
	*@brief コンボボックス作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateComboBox(const char* name);
	

	
	

	
	/**
	*@brief スライダー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateSlider(const char* name);
	
	
	/**
	*@brief スライダーの値が変化したときに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool SliderChangedHandler(const CEGUI::EventArgs &event);

	
	/**
	*@brief タイトルバー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateTitlebar(const char* name);
	
	/**
	*@brief フレームウインドウ作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateFrameWindow(const char* name);
	
	/**
	*@brief 縦スクロールバー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateVerticalScrollbar(const char* name);
	
	/**
	*@brief 横スクロールバー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateHorizontalScrollbar(const char* name);
	
	/**
	*@brief プログレスバー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateProgressBar(const char* name);
	
	/**
	*@brief マルチラインエディット作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateMultiLineEditbox(const char* name);
	
	/**
	*@brief リストボックス作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateListbox(const char* name);
	
	/**
	*@brief コンボドロップリスト作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateComboDropList(const char* name);
	
	/**
	*@brief チェックボックス作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateCheckbox(const char* name);
	
	/**
	*@brief ラジオボタン作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateRadioButton(const char* name);
	
	/**
	*@brief ツールチップ作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateTooltip(const char* name);
	
	/**
	*@brief アイテムリストボックス作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateItemListbox(const char* name);
	
	/**
	*@brief リストボックスアイテム作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateListboxItem(const char* name);
	
	/**
	*@brief スピナー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateSpinner(const char* name);
	
	/**
	*@brief スクロールブルペーン作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateScrollablePane(const char* name);
	
	/**
	*@brief リストヘッダーセグメント作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateListHeaderSegment(const char* name);
	
	/**
	*@brief リストヘッダー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateListHeader(const char* name);
	
	/**
	*@brief マルチコロンリスト作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateMultiColumnList(const char* name);
	
	/**
	*@brief メニューアイテム作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateMenuItem(const char* name);
	
	/**
	*@brief メニューバー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateMenubar(const char* name);
	
	/**
	*@brief ポップアイテムメニュー作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreatePopupMenu(const char* name);
	
	/**
	*@brief タブボタンペーン作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateTabButtonPane(const char* name);
	
	/**
	*@brief タブコンテキストペーン作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateTabContentPane(const char* name);
	
	/**
	*@brief タブコントロール作成の関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateTabControl(const char* name);


	
	/**
	*@brief チェックボックスが変化したときに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool CheckedHandler(const CEGUI::EventArgs &event);
	
	/**
	*@brief ラジオボタンが変化したときに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool RadioHandler(const CEGUI::EventArgs &event);
	
	/**
	*@brief リストボックスの選択が変化したときに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool ListBoxChangedHandler(const CEGUI::EventArgs &event);
	
	/**
	*@brief コンボボックスの選択が変化したときに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool ComboBoxChangedHandler(const CEGUI::EventArgs &event);
	
	/**
	*@brief スクロールバーが変化したときに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool ScrollPosChangedHandler(const CEGUI::EventArgs &event);

	
	/**
	*@brief GUI作成の関数
	* @param type ウィジェットの種類
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateGUI(const char* type, const char* name);

	
	/**
	*@brief GUIのコールバックを設定する関数
	* @param name 名前
	* @param type ウィジェットの種類
	*/
	void SetCallScript(const char* name, const char* type);
	
	

	
	/**
	*@brief GUIをキーで押したときに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool GUIKeyUpHandler(const CEGUI::EventArgs &event);
	
	/**
	*@brief GUIからキーを離したに呼び出される関数
	* @param event イベント
	* @return true
	*/
	bool GUIKeyDownHandler(const CEGUI::EventArgs &event);


	
	
	/**
	*@brief 更新時に呼び出される関数
	* @param t フレーム時間
	*/
	void update(float t);

	

	
	/**
	*@brief パーティクル作成の関数
	* @param name 名前
	* @param file_name ファイル名
	* @return パーティクルオブジェクト
	*/
	ParticleObj *CreateParticle(const char* name, const char* file_name);
	
	
	/**
	*@brief パーティクル削除の関数
	* @param ml パーティクルオブジェクト
	*/
	void DestroyParticle(ParticleObj *ml);
	
	/**
	*@brief 全てパーティクル削除の関数
	*/
	void DestroyAllParticle();

	

	
	/**
	*@brief スカイボックス作成の関数
	* @param filename ファイル名
	* @param Size 大きさ
	*/
	void SetSkyBox(const char* filename, int Size);
	/**
	*@brief スカイボックス削除の関数
	*/
	void RemoveSkyBox();
	
	
	/**
	*@brief 地面作成の関数
	* @param name 名前
	* @param name2 ボディ名
	* @param filename マテリアル名
	* @param Size 大きさ
	* @param direction 方向
	* @return ボディオブジェクト
	*/
	LinkObj *SetFloor(const char* name, const char* name2, const char* filename, int Size, int direction);
	
	/**
	*@brief 地面削除の関数
	*/
	void DestroyFloor();
	
	
	
	
	/**
	*@brief 画像作成の関数
	* @param name 名前
	* @param filename ファイル名
	* @return イメージセットオブジェクト
	*/
	ImageSetObj *CreateGuiImageSet(const char* name, const char* filename);
	
	/**
	*@brief 画像削除の関数
	* @param MIS イメージセットオブジェクト
	*/
	void DestroyImage(ImageSetObj *MIS);
	
	/**
	*@brief 全画像削除の関数
	*/
	void DestroyAllImage();

	

	
	/**
	*@brief アニメーション作成の関数
	* @param name 名前
	* @param t 終了時間
	* @return アニメーションオブジェクト
	*/
	AnimationObj *CreateAnimation(const char* name, float t);
	
	
	/**
	*@brief アニメーション削除の関数
	* @param man アニメーションオブジェクト
	*/
	void DestroyAnimation(AnimationObj *man);
	
	
	/**
	*@brief アニメーション全削除の関数
	*/
	void DestroyAllAnimation();

	
	
	/**
	*@brief 光源作成の関数
	* @param name 名前
	* @return 光源オブジェクト
	*/
	LightObj *CreateLight(const char* name);
	
	
	/**
	*@brief 光源削除の関数
	* @param ml 光源オブジェクト
	*/
	void DestroyLight(LightObj *ml);
	
	
	/**
	*@brief 全光源削除の関数
	*/
	void DestroyAllLight();
	

	
	/**
	*@brief サブウインドウ作成の関数
	* @param wName 名前
	* @param texName テクスチャ名
	* @param camName カメラ名
	* @param ImageSetName イメージセット名
	* @param ImageName イメージ名
	* @return サブウインドウオブジェクト
	*/
	SubWindow *SetSubWindow(const char* wName, const char* texName, const char* camName, const char* ImageSetName, const char* ImageName);
	/**
	*@brief サブウインドウ削除の関数
	* @param sw サブウインドウオブジェクト
	*/
	void DestroySubWindow(SubWindow *sw);
	/**
	*@brief サブウインドウ全削除の関数
	*/
	void DestroyAllSubWindow();
	/**
	*@brief サブウインドウ動作再開の関数
	* @param sw サブウインドウオブジェクト
	*/
	void restartSubWindow(SubWindow *sw);
	/**
	*@brief サブウインドウ動停止の関数
	* @param sw サブウインドウオブジェクト
	*/
	void StopSubWindow(SubWindow *sw);

	



	
	/**
	*@brief ウインドウのサイズ取得の関数
	* @return サイズ
	*/
	Ogre::Vector2 getRenderWindowSize();
	
	/**
	*@brief カーソル位置の3Dモデルを取得の関数
	* @param screenX 位置(X)
	* @param screenY 位置(Y)
	* @return ボディオブジェクト
	*/
	LinkObj* GetQueryScene(float screenX, float screenY);

	
	/**
	*@brief FPS設定の関数
	* @param st FPS
	*/
	void SetSleepTime(int st);

	
	/**
	*@brief RTC読み込みの関数
	* @param fname ファイル名
	*/
	void OpenFile(const char *fname);
	
	/**
	*@brief RTC削除の関数
	*/
	void CloseFile();
	
	/**
	*@brief RTCの停止の関数
	*/
	void StopFile();

	
	/**
	*@brief ノードの接続の関数
	* @param obj1 ボディオブジェクト
	* @param obj2 パーティクルオブジェクト
	*/
	void AttachObj(LinkObj *obj1, ParticleObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param obj1 ボディオブジェクト
	* @param obj2 光源オブジェクト
	*/
	void AttachObj(LinkObj *obj1, LightObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param obj1 パーティクルオブジェクト
	* @param obj2 光源オブジェクト
	*/
	void AttachObj(ParticleObj *obj1, LightObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param obj1 ボディオブジェクト
	* @param obj2 ボディオブジェクト
	*/
	void AttachObj(LinkObj *obj1, LinkObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param obj1 パーティクルオブジェクト
	* @param obj2 パーティクルオブジェクト
	*/
	void AttachObj(ParticleObj *obj1, ParticleObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param obj1 光源オブジェクト
	* @param obj2 光源オブジェクト
	*/
	void AttachObj(LightObj *obj1, LightObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param obj1 アニメーションオブジェクト
	* @param obj2 ボディオブジェクト
	*/
	void AttachObj(AnimationObj *obj1, LinkObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param obj1 アニメーションオブジェクト
	* @param obj2 光源オブジェクト
	*/
	void AttachObj(AnimationObj *obj1, LightObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param obj1 アニメーションオブジェクト
	* @param obj2 パーティクルオブジェクト
	*/
	void AttachObj(AnimationObj *obj1, ParticleObj *obj2);
	/**
	*@brief ノードの接続の関数
	* @param n1 ベースオブジェクト
	* @param o1 可動オブジェクト1
	* @param o2 可動オブジェクト2
	*/
	void AttachObj(ObjectBase *n1, Ogre::MovableObject *o1,ObjectBase *n2);
	

	
	/**
	*@brief ノード分離の関数
	* @param obj1 ボディオブジェクト
	*/
	void DeatachObj(LinkObj *obj1);
	/**
	*@brief ノード分離の関数
	* @param obj1 パーティクルオブジェクト
	*/
	void DeatachObj(ParticleObj *obj1);
	/**
	*@brief ノード分離の関数
	* @param obj1 光源オブジェクト
	*/
	void DeatachObj(LightObj *obj1);
	/**
	*@brief ノード分離の関数
	* @param n1 ベースオブジェクト
	* @param o1 可動オブジェクト
	*/
	void DeatachObj(ObjectBase *n1, Ogre::MovableObject *o1);

	
	
	
	/**
	*@brief ノード削除の関数
	* @param mn ノードオブジェクト
	*/
	void DestroyNode(NodeObj *mn);
	
	
	/**
	*@brief 全ノードの削除の関数
	*/
	void DestroyAllNode();

	
	/**
	*@brief 名前からボディオブジェクトを取得
	* @param name 名前
	* @return ボディオブジェクト
	*/
	LinkObj* getBodyByName(const char* name);
	/**
	*@brief 名前からGUIオブジェクトを取得
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj* getGUIByName(const char* name);
	/**
	*@brief 名前からパーティクルオブジェクトを取得
	* @param name 名前
	* @return パーティクルオブジェクト
	*/
	ParticleObj* getParticleByName(const char* name);
	/**
	*@brief 名前からサブウインドウオブジェクトを取得
	* @param name 名前
	* @return サブウインドウオブジェクト
	*/
	SubWindow* getSubWindowByName(const char* name);
	/**
	*@brief 名前からイメージセットオブジェクトを取得
	* @param name 名前
	* @return イメージセットオブジェクト
	*/
	ImageSetObj* getImageSetByName(const char* name);
	/**
	*@brief 名前から光源オブジェクトを取得
	* @param name 名前
	* @return 光源オブジェクト
	*/
	LightObj* getLightByName(const char* name);
	/**
	*@brief 名前からアニメーションオブジェクトを取得
	* @param name 名前
	* @return アニメーションオブジェクト
	*/
	AnimationObj* getAnimationByName(const char* name);
	/**
	*@brief 名前からノードオブジェクトを取得
	* @param name 名前
	* @return ノードオブジェクト
	*/
	NodeObj* getNodeByName(const char* name);


	
	/**
	*@brief シミュレーションの3Dモデルの作成
	* @param obj ボディオブジェクト
	*/
	void CreateODEObj(LinkObj *obj);
	
	
	/**
	*@brief シミュレーションの3Dモデルの削除
	* @param obj ボディオブジェクト
	*/
	void DestroyODEObj(LinkObj *obj);

	
	/**
	*@brief ファイル読み込みの関数
	* @param s ファイル名
	*/
	void save(std::string s);
	
	/**
	*@brief ファイル書き込みの関数
	* @param s ファイル名
	* @return trueで成功、falseで失敗
	*/
	bool openb(std::string s);
	
	/**
	*@brief 初期化の関数
	* @return trueで成功、falseで失敗
	*/
	bool newfile();
	
	/**
	*@brief リセットの関数
	*/
	void reset();
	
	/**
	*@brief RTCが起動出来たときに呼び出す関数
	*/
	void SetRTC();

	
	/**
	*@brief GUIの操作でボディを作成する関数
	* @param n 名前
	* @param s ファイル名
	* @return ボディオブジェクト
	*/
	LinkObj *SetQtBody(const char* n,const char* s);
	/**
	*@brief GUIの操作でボディを削除する関数
	* @param link ボディオブジェクト
	*/
	void DestroyQtBody(LinkObj *link);
	/**
	*@brief GUIの操作でスタティックイメージを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtStaticImage(const char* name);
	/**
	*@brief GUIの操作でスタティックテキストを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtButton(const char* name);
	/**
	*@brief GUIの操作でボタンを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtStaticText(const char* name);
	/**
	*@brief GUIの操作でテキストエディタを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtEditBox(const char* name);
	/**
	*@brief GUIの操作でコンボボックスを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtComboBox(const char* name);
	/**
	*@brief GUIの操作でスライダーを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtSlider(const char* name);
	/**
	*@brief GUIの操作でGUIを作成する関数
	* @param type GUIの種類
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtGUI(const char* type, const char* name);
	/**
	*@brief GUIの操作でタイトルバーを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtTitlebar(const char* name);
	/**
	*@brief GUIの操作でフレームウインドウを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtFrameWindow(const char* name);
	/**
	*@brief GUIの操作でスクロールバーのつまみを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtThumb(const char* name);
	/**
	*@brief GUIの操作で縦スクロールバーを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtVerticalScrollbar(const char* name);
	/**
	*@brief GUIの操作で横スクロールバーを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtHorizontalScrollbar(const char* name);
	/**
	*@brief GUIの操作でプログレスバーを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtProgressBar(const char* name);
	/**
	*@brief GUIの操作でマルチラインエディットを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtMultiLineEditbox(const char* name);
	/**
	*@brief GUIの操作でリストボックスを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtListbox(const char* name);
	/**
	*@brief GUIの操作でコンボドロップリストを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtComboDropList(const char* name);
	/**
	*@brief GUIの操作でチェックボックスを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtCheckbox(const char* name);
	/**
	*@brief GUIの操作でラジオボタンを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtRadioButton(const char* name);
	/**
	*@brief GUIの操作でツールチップを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtTooltip(const char* name);
	/**
	*@brief GUIの操作でアイテムリストボックスを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtItemListbox(const char* name);
	/**
	*@brief GUIの操作でリストボックスアイテムを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtListboxItem(const char* name);
	/**
	*@brief GUIの操作でスピナーを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtSpinner(const char* name);
	/**
	*@brief GUIの操作でスクロールブルペーンを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtScrollablePane(const char* name);
	/**
	*@brief GUIの操作でリストヘッダーセグメントを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtListHeaderSegment(const char* name);
	/**
	*@brief GUIの操作でリストヘッダーを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtListHeader(const char* name);
	/**
	*@brief GUIの操作でマルチコロンリストを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtMultiColumnList(const char* name);
	/**
	*@brief GUIの操作でメニューアイテムを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtMenuItem(const char* name);
	/**
	*@brief GUIの操作でメニューバーを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtMenubar(const char* name);
	/**
	*@brief GUIの操作でポップアイテムメニューを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtPopupMenu(const char* name);
	/**
	*@brief GUIの操作でタブボタンペーンを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtTabButtonPane(const char* name);
	/**
	*@brief GUIの操作でタブコンテキストペーンを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtTabContentPane(const char* name);
	/**
	*@brief GUIの操作でタブコントロールを作成する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	GUIObj *CreateQtTabControl(const char* name);
	
	/**
	*@brief GUIの操作でGUIオブジェクトを削除する関数
	* @param name 名前
	* @return GUIオブジェクト
	*/
	void DestroyQtGui(GUIObj *label);
	/**
	*@brief GUIの操作でパーティクルオブジェクトを作成する関数
	* @param name 名前
	* @param file_name ファイル名
	* @return パーティクルオブジェクト
	*/
	ParticleObj *CreateQtParticle(const char* name, const char* file_name);
	/**
	*@brief GUIの操作でスカイボックスを作成する関数
	* @param filename ファイル名
	* @param Size 大きさ
	*/
	void SetQtSkyBox(const char* filename, int Size);
	/**
	*@brief GUIの操作で地面を作成する関数
	* @param name 名前
	* @param name2 ボディ名
	* @param filename マテリアル名
	* @param Size 大きさ
	* @param direction 方向
	* @return ボディオブジェクト
	*/
	LinkObj *SetQtFloor(const char* name, const char* name2, const char* filename, int Size, int direction);
	/**
	*@brief GUIの操作で地面を削除する関数
	*/
	void DestroyQtFloor();
	/**
	*@brief GUIの操作で画像を作成する関数
	* @param name 名前
	* @param filename ファイル名
	* @return イメージセットオブジェクト
	*/
	ImageSetObj *CreateQtGuiImageSet(const char* name, const char* filename);
	/**
	*@brief GUIの操作で画像を削除する関数
	* @param MIS イメージセットオブジェクト
	*/
	void DestroyQtImage(ImageSetObj *MIS);
	/**
	*@brief GUIの操作でアニメーションを作成する関数
	* @param name 名前
	* @param t 終了時間
	* @return アニメーションオブジェクト
	*/
	AnimationObj *CreateQtAnimation(const char* name, float t);
	/**
	*@brief GUIの操作でアニメーションを削除する関数
	* @param man アニメーションオブジェクト
	*/
	void DestroyQtAnimation(AnimationObj *man);
	/**
	*@brief GUIの操作で光源を作成する関数
	* @param name 名前
	* @return 光源オブジェクト
	*/
	LightObj *CreateQtLight(const char* name);
	/**
	*@brief GUIの操作で光源を削除する関数
	* @param ml 光源オブジェクト
	*/
	void DestroyQtLight(LightObj *ml);
	/**
	*@brief GUIの操作でサブウインドウを作成する関数
	* @param wName 名前
	* @param texName テクスチャ名
	* @param camName カメラ名
	* @param ImageSetName イメージセット名
	* @param ImageName イメージ名
	* @return サブウインドウオブジェクト
	*/
	SubWindow *SetQtSubWindow(const char* wName, const char* texName, const char* camName, const char* ImageSetName, const char* ImageName);
	/**
	*@brief GUIの操作でサブウインドウを削除する関数
	* @param sw サブウインドウオブジェクト
	*/
	void DestroyQtSubWindow(SubWindow *sw);
	/**
	*@brief GUIの操作でノードを削除する関数
	* @param mn ノードオブジェクト
	*/
	void DestroyQtNode(NodeObj *mn);
	/**
	*@brief GUIの操作でパーティクルオブジェクトの削除する関数
	* @param ml パーティクルオブジェクト
	*/
	void DestroyQtParticle(ParticleObj *ml);

	
	
	/**
	*@brief ボディオブジェクトの再生成の関数
	* @param link ボディオブジェクト
	*/
	void CreateQtBody(LinkObj *link);
	/**
	*@brief GUIオブジェクトの再生成の関数
	* @param label GUIオブジェクト
	*/
	void CreateQtGUI(GUIObj *label);
	/**
	*@brief パーティクルオブジェクトの再生成の関数
	* @param ml パーティクルオブジェクト
	*/
	void CreateQtParticle(ParticleObj *ml);
	/**
	*@brief イメージセットオブジェクトの再生成の関数
	* @param MIS イメージセットオブジェクト
	*/
	void CreateQtImage(ImageSetObj *MIS);
	/**
	*@brief サブウインドウオブジェクトの再生成の関数
	* @param sw サブウインドウオブジェクト
	*/
	void CreateQtSubWindow(SubWindow *sw);
	/**
	*@brief 光源オブジェクトの再生成の関数
	* @param ml 光源オブジェクト
	*/
	void CreateQtLight(LightObj *ml);
	/**
	*@brief アニメーションオブジェクトの再生成の関数
	* @param man アニメーションオブジェクト
	*/
	void CreateQtAnimation(AnimationObj *man);
	/**
	*@brief ノードオブジェクトの再生成の関数
	* @param mn ノードオブジェクト
	*/
	void CreateQtNode(NodeObj *mn);

	/**
	*@brief カメラをGUIで設定した位置に固定するか設定する関数
	* @param flag trueで固定、falseで固定解除
	*/
	void SetCameraAutoMoveFlag(bool flag);

	/**
	*@brief カーソルがGUI上に乗っているか判定する関数
	* @param px カーソルの位置(X)
	* @param py カーソルの位置(Y)
	*/
	bool JudgeMouseOnGUI(float px, float py);

	/**
	*@brief フォントを読み込む関数
	* @param font_name フォント名
	* @param point_size サイズ
	* @param anti_aliased trueでアンチエイリアス有効
	* @param font_filename ファイル名
	* @return 成功でtrue、失敗でfalse
	*/
	bool loadFont(const char *font_name, float point_size, bool anti_aliased, const char *font_filename);
	

	
	SimulationObj *mSim;

	std::vector<LinkObj*> LinkObjs;
	std::vector<GUIObj*> GUIObjs;
	std::vector<ParticleObj*> ParticleObjs;
	std::vector<SubWindow*> SubWindows;
	std::vector<ImageSetObj*> ImageSetObjs;
	std::vector<AnimationObj*> AnimationObjs;
	std::vector<LightObj*> LightObjs;
	std::vector<NodeObj*> NodeObjs;

	std::vector<LinkObj*> QtLinks;
	std::vector<GUIObj*> QtGUIs;
	std::vector<ParticleObj*> QtParticles;
	std::vector<SubWindow*> QtSubWindows;
	std::vector<ImageSetObj*> QtImageSets;
	std::vector<AnimationObj*> QtAnimations;
	std::vector<LightObj*> QtLights;
	std::vector<NodeObj*> QtNodes;

	DisplayImage *displayImg;



	float CamX, CamY, CamZ;
	float CamRoll, CamPitch, CamYaw;
	float CamLen;
	float LightX, LightY, LightZ;
	float ShadowR, ShadowG, ShadowB;
	float LightR, LightG, LightB;

	LinkObj *Floor;
	LinkObj *qtFloor;

	std::string skyBoxName;
	int skyBoxSize;

	std::string QtskyBoxName;
	int QtskyBoxSize;

	PyObj *po;
	bool RTCFlag;

	bool CameraFlag;

	

 
protected:
	/**
	*@brief 初期化の関数
	*/
    virtual void createScene(void);

	
	coil::Mutex *mu;
	
    
 
    
    

	
	

	Ogre::AnimationState *mAnimationState; // The current animation state of the object
 
	/**
	*@brief キーを押した時に終了する関数
	* @param e キーイベント
	* @return true
	*/
	bool quit(const CEGUI::EventArgs &e);

	CEGUI::OgreRenderer* mRenderer;

	CEGUI::Window *sheet;
	
	
	/**
	*@brief キーを押した時に呼ばれる関数
	* @param arg キーイベント
	* @return true
	*/
	virtual bool keyPressed(QKeyEvent *arg );
	
	/**
	*@brief キーを離した時に呼ばれる関数
	* @param arg キーイベント
	* @return true
	*/
    virtual bool keyReleased(QKeyEvent *arg );
	
	/**
	*@brief マウスを動かした時に呼ばれる関数
	* @param arg マウスイベント
	* @return true
	*/
    virtual bool mouseMoved(QMouseEvent *arg );
	
	/**
	*@brief マウスのボタン押した時に呼ばれる関数
	* @param arg マウスイベント
	* @return true
	*/
    virtual bool mousePressed(QMouseEvent *arg);
	
	/**
	*@brief マウスのボタン離した時に呼ばれる関数
	* @param arg マウスイベント
	* @return true
	*/
    virtual bool mouseReleased(QMouseEvent *arg);
	/**
	*@brief テキストを入力した場合等に呼び出される関数
	* @param arg インプットメソッドイベント
	* @return true
	*/
	bool inputMethodEvent(QInputMethodEvent *arg);

	

	

	
	Ogre::Light* light;

	int SleepTime;

	QString PreeditStr;
	std::vector<std::string> fontList;

    // The speed at which the object is moving
};
 
#endif // #ifndef __OgreRTCApplication_h_