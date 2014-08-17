#include "MyNode.h"
#include "MyOgreMacro.h"

MyObject::MyObject()
{

}
void MyObject::SetPosition(float x,float y,float z)
{
	mNode->mNode->setPosition(Ogre::Vector3(x,y,z));
	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->setPosition(Ogre::Vector3(x,y,z));
	}
	mNode->pos_x = x;
	mNode->pos_y = y;
	mNode->pos_z = z;
}

void MyObject::SetScale(float sx,float sy,float sz)
{
	mNode->mNode->setScale(Ogre::Vector3(sx,sy,sz));
	mNode->scale_x = sx;
	mNode->scale_y = sy;
	mNode->scale_z = sz;
}

void MyObject::SetQuaternion(float w, float x, float y, float z)
{
	mNode->mNode->setOrientation(Ogre::Quaternion(w,x,y,z));
	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->setOrientation(Ogre::Quaternion(w,x,y,z));
	}
}

void MyObject::Yaw(float ang)
{
	mNode->mNode->yaw(Ogre::Degree(ang));
	mNode->yaw = ang;

	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->yaw(Ogre::Degree(ang));
	}
}

void MyObject::Roll(float ang)
{
	mNode->mNode->roll(Ogre::Degree(ang));
	mNode->roll = ang;

	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->roll(Ogre::Degree(ang));
	}
	
}

void MyObject::Pitch(float ang)
{
	mNode->mNode->pitch(Ogre::Degree(ang));
	mNode->pitch = ang;
	
	for(int i=0;i < NodeList.size();i++)
	{
		NodeList[i]->mNode->pitch(Ogre::Degree(ang));
	}
}

void MyObject::SetRotation(float r, float p, float y)
{
	SetQuaternion(1,0,0,0);
	Roll(r);
	Pitch(p);
	Yaw(y);

	
}
void MyObject::SetVisible(bool v)
{
	mNode->mNode->setVisible(v);
	mNode->visi = v;
}


void MyObject::BoundingBoxVisible(bool v)
{
	
	mNode->mNode->showBoundingBox(v);
	mNode->mNode->hideBoundingBox(!v);

	mNode->bound_visi = v;
	
}


void MyObject::UpdatePos(float dx, float dy, float dz, float CamRoll, float CamPitch, float CamYaw)
{
	Ogre::Quaternion tRot = GetRotQuat(CamRoll, CamPitch, CamYaw);

	
	
	Ogre::Vector3 dp(dx,dy,dz);
	dp = tRot * dp;

	mNode->pos_x = mNode->pos_x + dp.x;
	mNode->pos_y = mNode->pos_y + dp.y;
	mNode->pos_z = mNode->pos_z + dp.z;


	SetPosition(mNode->pos_x, mNode->pos_y, mNode->pos_z);
}
void MyObject::UpdateRot(float dx, float dy, float CamRoll, float CamPitch, float CamYaw)
{
	Ogre::Quaternion tRot = GetRotQuat(CamRoll, CamPitch, CamYaw);
	
	Ogre::Vector3 dx_Axis = tRot * Ogre::Vector3(0,1,0);
	Ogre::Vector3 dy_Axis = tRot * Ogre::Vector3(1,0,0);
	Ogre::Quaternion tdxRot;
	tdxRot.FromAngleAxis(Ogre::Degree(dx),dx_Axis);
	Ogre::Quaternion tdyRot;
	tdyRot.FromAngleAxis(Ogre::Degree(dy),dy_Axis);
	
	tdxRot = tdyRot* tdxRot;
	
	mNode->roll = mNode->roll + tdxRot.getRoll().valueDegrees();
	mNode->pitch = mNode->pitch + tdxRot.getPitch().valueDegrees();
	mNode->yaw = mNode->yaw + tdxRot.getYaw().valueDegrees();



	
	SetRotation(mNode->roll, mNode->pitch, mNode->yaw);
}


MyNode::MyNode(std::string n)
{
	name = n;
	

	pos_x = 0;
	pos_y = 0;
	pos_z = 0;
	
	scale_x = 1;
	scale_y = 1;
	scale_z = 1;

	roll = 0;
	pitch = 0;
	yaw = 0;

	

	visi = true;
	bound_visi = false;
	

}

void MyNode::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	//std::cout << name << std::endl;

	ofs2.write( (char*)&scale_x, sizeof(scale_x) );
	ofs2.write( (char*)&scale_y, sizeof(scale_y) );
	ofs2.write( (char*)&scale_z, sizeof(scale_z) );

	ofs2.write( (char*)&pos_x, sizeof(pos_x) );
	ofs2.write( (char*)&pos_y, sizeof(pos_y) );
	ofs2.write( (char*)&pos_z, sizeof(pos_z) );

	ofs2.write( (char*)&roll, sizeof(roll) );
	ofs2.write( (char*)&pitch, sizeof(pitch) );
	ofs2.write( (char*)&yaw, sizeof(yaw) );
}
bool MyNode::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	ifs.read( (char*)&scale_x, sizeof(scale_x) );
	ifs.read( (char*)&scale_y, sizeof(scale_y) );
	ifs.read( (char*)&scale_z, sizeof(scale_z) );

	ifs.read( (char*)&pos_x, sizeof(pos_x) );
	ifs.read( (char*)&pos_y, sizeof(pos_y) );
	ifs.read( (char*)&pos_z, sizeof(pos_z) );

	ifs.read( (char*)&roll, sizeof(roll) );
	ifs.read( (char*)&pitch, sizeof(pitch) );
	ifs.read( (char*)&yaw, sizeof(yaw) );

	return true;
}
void MyNode::AddObj(MyObject *mo)
{
	mobj.push_back(mo);
}
void MyNode::RemoveObj(MyObject *mo)
{
	
	std::vector<MyObject*>::iterator end_it = remove( mobj.begin(), mobj.end(), mo );
	mobj.erase( end_it, mobj.end() );
}