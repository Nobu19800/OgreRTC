#include "MyLink.h"
#include "MyOgreMacro.h"


MyLink::MyLink(std::string n)
{
	name = n;
	type = 0;

	red = 0;
	green = 0;
	blue = 0;
	color_visi = false;
	shadow_visi = true;
	

	anim_start = false;
	anim_speed = 1;

	alpha = 1;

	

	anim_name = "";
	material_name = "";

	mat_visi = false;

	std::string nn = n + "Link";
	mNode = new MyNode(nn);
}


void SetPQ(MyLink *ml)
{
	
}




void MyLink::SetAnimation(const char* name)
{
	mAnimationState = mEntity->getAnimationState(name);
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
	anim_name = name;

}

void MyLink::ResetAnimation(const char* name)
{
	
	mAnimationState = mEntity->getAnimationState(name);
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);

	mAnimationState->setTimePosition(mAnimationState->getLength());

}

void MyLink::UpdateAnimation(const char* name,float time)
{
	mAnimationState = mEntity->getAnimationState(name);
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);

	mAnimationState->addTime(time);
}


void MyLink::SetShadows(bool v)
{
	mEntity->setCastShadows(v);
	shadow_visi = v;
}




float MyLink::GetBoundingBoxSize(int num)
{
	if(num == 0)
	{
		return mEntity->getBoundingBox().getSize().x;
	}
	else if(num == 1)
	{
		return mEntity->getBoundingBox().getSize().y;
	}
	else
	{
		return mEntity->getBoundingBox().getSize().z;
	}
	
}

void MyLink::SetMaterial(const char* name)
{
	mEntity->setMaterialName(name);
	material_name = name;
	mat_visi = true;

}


void MyLink::SetBornPosition( const char* name, float x, float y, float z)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->setPosition(x,y,z);
	}
	
}

void MyLink::SetBornOrientation( const char*name, float w, float x, float y, float z)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->setOrientation(w,x,y,z);
	}
}

void MyLink::SetBornScale( const char*name, float sx, float sy, float sz)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->setScale(sx,sy,sz);
	}
}


void MyLink::SetBornRoll( const char*name, float ang)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->roll(Ogre::Degree(ang));
	}
}

void MyLink::SetBornPitch( const char*name, float ang)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->pitch(Ogre::Degree(ang));
	}
}

void MyLink::SetBornYaw( const char*name, float ang)
{
	if(mEntity->getSkeleton()->hasBone(name) == true)
	{
		Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
		bone->setManuallyControlled(true);
		bone->yaw(Ogre::Degree(ang));
	}
}

void MyLink::SetBornRotation(const char* name, float r, float p, float y)
{
	SetBornOrientation(name,1,0,0,0);
	SetBornRoll(name,r);
	SetBornPitch(name,p);
	SetBornYaw(name,y);
}

void MyLink::SetBornPosition( int name, float x, float y, float z)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->setPosition(x,y,z);
	
}

void MyLink::SetBornOrientation( int name, float w, float x, float y, float z)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->setOrientation(w,x,y,z);
}

void MyLink::SetBornScale( int name, float sx, float sy, float sz)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->setScale(sx,sy,sz);
}


void MyLink::SetBornRoll( int name, float ang)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->roll(Ogre::Degree(ang));
}

void MyLink::SetBornPitch( int name, float ang)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->pitch(Ogre::Degree(ang));
}

void MyLink::SetBornYaw( int name, float ang)
{
	Ogre::Bone *bone = mEntity->getSkeleton()->getBone(name);
	bone->setManuallyControlled(true);
	bone->yaw(Ogre::Degree(ang));
}

void MyLink::SetBornRotation(int name, float r, float p, float y)
{
	SetBornOrientation(name,1,0,0,0);
	SetBornRoll(name,r);
	SetBornPitch(name,p);
	SetBornYaw(name,y);
}

int MyLink::GetBornNum()
{
	Ogre::Skeleton *tmp = mEntity->getSkeleton();
	if(tmp)
	{
		return tmp->getNumBones();
	}
	return 0;
	
}

void MyLink::ResetBorn()
{
	mEntity->getSkeleton()->reset(true);
}



bool MyLink::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	filename = ReadString(ifs);

	int NodeNum;
	ifs.read( (char*)&NodeNum, sizeof(NodeNum) );

	for(int i=0;i < NodeNum;i++)
	{
		std::string nn = ReadString(ifs);
		MyNode *mn = new MyNode(nn);
		NodeList.push_back(mn);
	}

	mNode->name = ReadString(ifs);

	ifs.read( (char*)&red, sizeof(red) );
	ifs.read( (char*)&green, sizeof(green) );
	ifs.read( (char*)&blue, sizeof(blue) );
	ifs.read( (char*)&alpha, sizeof(alpha) );

	ifs.read( (char*)&color_visi, sizeof(color_visi) );
	ifs.read( (char*)&shadow_visi, sizeof(shadow_visi) );

	//ifs.read( (char*)&visi, sizeof(visi) );
	ifs.read( (char*)&anim_speed, sizeof(anim_speed) );

	anim_name = ReadString(ifs);

	ifs.read( (char*)&anim_start, sizeof(anim_start) );
	//ifs.read( (char*)&bound_visi, sizeof(bound_visi) );

	material_name = ReadString(ifs);
	ifs.read( (char*)&mat_visi, sizeof(mat_visi) );

	return true;
}

void MyLink::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(filename , ofs2 );

	int NodeNum = NodeList.size();
	ofs2.write( (char*)&NodeNum, sizeof(NodeNum) );

	for(int i=0;i < NodeNum;i++)
	{
		WriteString(NodeList[i]->name , ofs2 );
	}

	WriteString(mNode->name , ofs2 );

	ofs2.write( (char*)&red, sizeof(red) );
	ofs2.write( (char*)&green, sizeof(green) );
	ofs2.write( (char*)&blue, sizeof(blue) );
	ofs2.write( (char*)&alpha, sizeof(alpha) );

	ofs2.write( (char*)&color_visi, sizeof(color_visi) );
	ofs2.write( (char*)&shadow_visi, sizeof(shadow_visi) );

	//ofs2.write( (char*)&visi, sizeof(visi) );
	ofs2.write( (char*)&anim_speed, sizeof(anim_speed) );
	WriteString(anim_name , ofs2 );
	
	ofs2.write( (char*)&anim_start, sizeof(anim_start) );
	
	//ofs2.write( (char*)&bound_visi, sizeof(bound_visi) );


	WriteString(material_name , ofs2 );
	ofs2.write( (char*)&mat_visi, sizeof(mat_visi) );

}



