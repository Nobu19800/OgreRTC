/*!
 * @file  NodeObj.h
 * @brief 3Dモデルのベースとなるクラス
 *
 */

#ifndef NodeObj_H
#define NodeObj_H

#include "BaseApplication.h"
#include "FileStreamFunc.h"

class NodeObj;
class ObjectBase;



/**
 * @class ObjectBase
*@brief 3Dモデルのベースとなるクラス
*/

class ObjectBase
{
public:
	/**
	*@brief コンストラクタ
	*/
	ObjectBase();
	int type;
	std::string name;
	NodeObj *mNode;
	std::vector<NodeObj*> NodeList;

	
	/**
	*@brief 位置設定の関数
	* @param x 位置(X)
	* @param y 位置(Y)
	* @param z 位置(Z)
	*/
	void SetPosition(float x,float y,float z);
	
	/**
	*@brief 拡大率設定の関数
	* @param sx 拡大率(X)
	* @param sy 拡大率(Y)
	* @param sz 拡大率(Z)
	*/
	void SetScale(float sx,float sy,float sz);
	
	/**
	*@brief ロール角設定の関数
	* @param ang ロール角
	*/
	void Roll(float ang);
	/**
	*@brief ピッチ角設定の関数
	* @param ang ピッチ角
	*/
	void Pitch(float ang);
	/**
	*@brief ヨー角設定の関数
	* @param ang ヨー角
	*/
	void Yaw(float ang);
	/**
	*@brief 姿勢設定の関数
	* @param r ロール
	* @param p ピッチ
	* @param y ヨー
	*/
	void SetRotation(float r, float p, float y);

	/**
	*@brief クオータニオン設定の関数
	* @param w クオータニオン(W)
	* @param x クオータニオン(X)
	* @param y クオータニオン(Y)
	* @param z クオータニオン(Z)
	*/
	void SetQuaternion(float w, float x, float y, float z);
	
	/**
	*@brief 表示、非表示設定の関数
	* @param v trueで表示、falseで非表示
	*/
	void SetVisible(bool v);

	
	/**
	*@brief マウスの位置に対する位置更新の関数
	* @param dx 移動量(X)
	* @param dy 移動量(Y)
	* @param dz 移動量(Z)
	* @param CamRoll 姿勢(ロール)
	* @param CamPitch 姿勢(ピッチ)
	* @param CamYaw 姿勢(ヨー)
	*/
	void UpdatePos(float dx, float dy, float dz, float CamRoll, float CamPitch, float CamYaw);
	
	/**
	*@brief マウスの位置に対する姿勢更新の関数
	* @param dx 移動量(X)
	* @param dy 移動量(Y)
	* @param dz 移動量(Z)
	* @param CamRoll 姿勢(ロール)
	* @param CamPitch 姿勢(ピッチ)
	* @param CamYaw 姿勢(ヨー)
	*/
	void UpdateRot(float dx, float dy, float CamRoll, float CamPitch, float CamYaw);
	
	/**
	*@brief バウンディングボックスの表示、非表示設定の関数
	* @param v trueで表示、falseで非表示
	*/
	void BoundingBoxVisible(bool v);
};


/**
 * @class NodeObj
*@brief ノードのクラス
*/

class NodeObj
{
public:
	/**
	*@brief コンストラクタ
	*/
	NodeObj(std::string n);
	float pos_x, pos_y, pos_z;
	float scale_x, scale_y, scale_z;
	float roll, pitch, yaw;

	std::string name;

	Ogre::SceneNode *mNode;

	bool visi;
	bool bound_visi;

	/**
	*@brief 設定のファイル保存の関数
	* @param ofs2 ファイルストリーム
	*/
	void save(std::ofstream &ofs2);
	/**
	*@brief 設定のファイル読み込みの関数
	* @param ifs ファイルストリーム
	* @return trueで成功、falseで失敗
	*/
	bool openb(std::ifstream &ifs);

	std::vector<ObjectBase*> mobj;

	/**
	*@brief オブジェクト追加の関数
	* @param mo オブジェクト
	*/
	void AddObj(ObjectBase *mo);
	
	/**
	*@brief オブジェクト削除の関数
	* @param mo オブジェクト
	*/
	void RemoveObj(ObjectBase *mo);

	
};

#endif