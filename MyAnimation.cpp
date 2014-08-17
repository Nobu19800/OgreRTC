#include "MyAnimation.h"
#include "MyOgreMacro.h"


MyAnimation::MyAnimation(std::string n)
{
	std::string nn = n + "Animation";
	mNode = new MyNode(nn);
	type = 3;
	name = n;
}


MyAnimationList *MyAnimation::AddKeyFrame(float t)
{
	
	MyAnimationList *mal = new MyAnimationList();
	mal->kf = track->createNodeKeyFrame(t);
	mal->mtime = t;

	animList.push_back(mal);

	return mal;
	
}

void MyAnimation::RemoveKeyFrame(MyAnimationList *mal)
{
	
	std::vector<MyAnimationList*>::iterator end_it = remove( animList.begin(), animList.end(), mal );
	animList.erase( end_it, animList.end() );
	track->removeAllKeyFrames();
	for(int i=0;i < animList.size();i++)
	{
		animList[i]->kf = track->createNodeKeyFrame(animList[i]->mtime);
		if(animList[i]->trans_flag)
		{
			animList[i]->setTranslate(animList[i]->px,animList[i]->py,animList[i]->pz);
		}
		if(animList[i]->rot_flag)
		{
			animList[i]->setTranslate(animList[i]->roll,animList[i]->pitch,animList[i]->yaw);
		}
	}
	
}


void MyAnimation::SetAnimationState(float t)
{
	mstate->setTimePosition(t);
}

MyAnimationList::MyAnimationList()
{
	mtime = 0;

	trans_flag = false;
	rot_flag = false;
}

void MyAnimationList::setTranslate(float x, float y, float z)
{
	
	kf->setTranslate(Ogre::Vector3(x,y,z));
	px = x;
	py = y;
	pz = z;
	trans_flag = true;
	
}

void MyAnimationList::setRotation(float r, float p, float y)
{
	Ogre::Quaternion q = GetRotQuat(r,p,y);
	kf->setRotation(q);
	roll = r;
	pitch = p;
	yaw = y;
	rot_flag = true;
	
}

void MyAnimation::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(mNode->name , ofs2 );

	ofs2.write( (char*)&Time, sizeof(Time) );

	int anl = animList.size();
	ofs2.write( (char*)&anl, sizeof(anl) );

	for(int i=0;i < anl;i++)
	{
		ofs2.write( (char*)&animList[i]->mtime, sizeof(animList[i]->mtime) );
		ofs2.write( (char*)&animList[i]->trans_flag, sizeof(animList[i]->trans_flag) );
		ofs2.write( (char*)&animList[i]->px, sizeof(animList[i]->px) );
		ofs2.write( (char*)&animList[i]->py, sizeof(animList[i]->py) );
		ofs2.write( (char*)&animList[i]->pz, sizeof(animList[i]->pz) );
		ofs2.write( (char*)&animList[i]->rot_flag, sizeof(animList[i]->rot_flag) );
		ofs2.write( (char*)&animList[i]->roll, sizeof(animList[i]->roll) );
		ofs2.write( (char*)&animList[i]->pitch, sizeof(animList[i]->pitch) );
		ofs2.write( (char*)&animList[i]->yaw, sizeof(animList[i]->yaw) );
	}
}
bool MyAnimation::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	mNode->name = ReadString(ifs);


	ifs.read( (char*)&Time, sizeof(Time) );

	int anl;
	ifs.read( (char*)&anl, sizeof(anl) );

	for(int i=0;i < anl;i++)
	{
		MyAnimationList *mal = new MyAnimationList();
		ifs.read( (char*)&mal->mtime, sizeof(mal->mtime) );
		ifs.read( (char*)&mal->trans_flag, sizeof(mal->trans_flag) );
		ifs.read( (char*)&mal->px, sizeof(mal->px) );
		ifs.read( (char*)&mal->py, sizeof(mal->py) );
		ifs.read( (char*)&mal->pz, sizeof(mal->pz) );
		
		ifs.read( (char*)&mal->rot_flag, sizeof(mal->rot_flag) );
		ifs.read( (char*)&mal->roll, sizeof(mal->roll) );
		ifs.read( (char*)&mal->pitch, sizeof(mal->pitch) );
		ifs.read( (char*)&mal->yaw, sizeof(mal->yaw) );
		

		animList.push_back(mal);
	}

	return true;
}

void MyAnimation::SetLength(float t)
{
	anim->setLength(t);
	Time = t;
}