#ifndef MYNODE_H
#define MYNODE_H

#include "BaseApplication.h"
#include "MyFileStream.h"

class MyNode;
class MyObject;


/*
*3Dモデルのベースとなるクラス
*/

class MyObject
{
public:
	MyObject();
	int type;
	std::string name;
	MyNode *mNode;
	std::vector<MyNode*> NodeList;

	/*
	*位置設定の関数
	*/
	void SetPosition(float sx,float sy,float sz);
	/*
	*拡大率設定の関数
	*/
	void SetScale(float x,float y,float z);
	/*
	*姿勢設定の関数
	*/
	void Roll(float ang);
	void Pitch(float ang);
	void Yaw(float ang);
	void SetRotation(float r, float p, float y);
	void SetQuaternion(float w, float x, float y, float z);
	
	/*
	*表示、非表示設定の関数
	*/
	void SetVisible(bool v);

	/*
	*マウスの位置に対する位置更新の関数
	*/
	void UpdatePos(float dx, float dy, float dz, float CamRoll, float CamPitch, float CamYaw);
	/*
	*マウスの位置に対する姿勢更新の関数
	*/
	void UpdateRot(float dx, float dy, float CamRoll, float CamPitch, float CamYaw);
	/*
	*バウンディングボックスの表示、非表示設定の関数
	*/
	void BoundingBoxVisible(bool v);
};

/*
*ノードのクラス
*/

class MyNode
{
public:
	MyNode(std::string n);
	float pos_x, pos_y, pos_z;
	float scale_x, scale_y, scale_z;
	float roll, pitch, yaw;

	std::string name;

	Ogre::SceneNode *mNode;

	bool visi;
	bool bound_visi;

	/*
	*設定のファイル保存の関数
	*/
	void save(std::ofstream &ofs2);
	/*
	*設定のファイル読み込みの関数
	*/
	bool openb(std::ifstream &ifs);

	std::vector<MyObject*> mobj;

	/*
	*オブジェクト追加の関数
	*/
	void AddObj(MyObject *mo);
	/*
	*オブジェクト削除の関数
	*/
	void RemoveObj(MyObject *mo);

	
};

#endif