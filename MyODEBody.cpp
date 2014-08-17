#include "MyODEBody.h"
#include "MyOgreMacro.h"


MyODEBody::MyODEBody(std::string n, MySimulation *s) : MyLink(n)
{
	ms = s;
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

	posx = 0;
	posy = 0;
	posz = 0;

	roll = 0;
	pitch = 0;
	yaw = 0;

	offx = 0;
	offy = 0;
	offz = 0;

	bscale_x = 1;
	bscale_y = 1;
	bscale_z = 1;

	BodyType = 0;

	
	delete mNode;
	std::string nn = n + "ODEBody";
	mNode = new MyNode(nn);
}


void MyODEBody::SetODEScale(float sx, float sy, float sz)
{
	bscale_x = sx;
	bscale_y = sy;
	bscale_z = sz;
	if(BodyType == 0)
	{
		SetScale(rd*sx, rd*sy, rd*sz);
	}
	else if(BodyType == 1)
	{
		SetScale(lx*sx, ly*sy, lz*sz);
	}
	else if(BodyType == 2)
	{
		SetScale(lx*sx, rd*sy, rd*sz);
	}
	else if(BodyType == 3)
	{
		SetScale(lx*sx, rd*sy, rd*sz);
	}
	SetPosition(sx*posx + offx, sy*posy + offy, sz*posz + offz);
}
void MyODEBody::SetODEOffset(float ox, float oy, float oz)
{
	offx = ox;
	offy = oy;
	offz = oz;
	SetPosition(bscale_x*posx + offx, bscale_y*posy + offy, bscale_z*posz + offz);
}

void MyODEBody::UpdateBodyPosition()
{
	const dReal *P = dBodyGetPosition(body);
	//std::cout << P[0] << "\t" << P[1] << "\t" << P[2] << std::endl;
	SetPosition(bscale_x*P[0] + offx, bscale_y*P[1] + offy, bscale_z*P[2] + offz);
}




bool MyODEBody::openb(std::ifstream &ifs)
{
	name = ReadString(ifs);
	mNode->name = ReadString(ifs);

	int NodeNum;
	ifs.read( (char*)&NodeNum, sizeof(NodeNum) );

	for(int i=0;i < NodeNum;i++)
	{
		std::string nn = ReadString(ifs);
		MyNode *mn = new MyNode(nn);
		NodeList.push_back(mn);
	}

	ifs.read( (char*)&BodyType, sizeof(BodyType) );
	ifs.read( (char*)&bscale_x, sizeof(bscale_x) );
	ifs.read( (char*)&bscale_y, sizeof(bscale_y) );
	ifs.read( (char*)&bscale_z, sizeof(bscale_z) );

	ifs.read( (char*)&roll, sizeof(roll) );
	ifs.read( (char*)&pitch, sizeof(pitch) );
	ifs.read( (char*)&yaw, sizeof(yaw) );

	ifs.read( (char*)&posx, sizeof(posx) );
	ifs.read( (char*)&posy, sizeof(posy) );
	ifs.read( (char*)&posz, sizeof(posz) );

	ifs.read( (char*)&offx, sizeof(offx) );
	ifs.read( (char*)&offy, sizeof(offy) );
	ifs.read( (char*)&offz, sizeof(offz) );

	ifs.read( (char*)&lx, sizeof(lx) );
	ifs.read( (char*)&ly, sizeof(ly) );
	ifs.read( (char*)&lz, sizeof(lz) );
	ifs.read( (char*)&rd, sizeof(rd) );

	ifs.read( (char*)&m, sizeof(m) );
	

	return true;
}

void MyODEBody::save(std::ofstream &ofs2)
{
	WriteString(name , ofs2 );
	WriteString(mNode->name , ofs2 );

	int NodeNum = NodeList.size();
	ofs2.write( (char*)&NodeNum, sizeof(NodeNum) );

	for(int i=0;i < NodeNum;i++)
	{
		WriteString(NodeList[i]->name , ofs2 );
	}
	
	ofs2.write( (char*)&BodyType, sizeof(BodyType) );
	ofs2.write( (char*)&bscale_x, sizeof(bscale_x) );
	ofs2.write( (char*)&bscale_y, sizeof(bscale_y) );
	ofs2.write( (char*)&bscale_z, sizeof(bscale_z) );

	ofs2.write( (char*)&roll, sizeof(roll) );
	ofs2.write( (char*)&pitch, sizeof(pitch) );
	ofs2.write( (char*)&yaw, sizeof(yaw) );

	ofs2.write( (char*)&posx, sizeof(posx) );
	ofs2.write( (char*)&posy, sizeof(posy) );
	ofs2.write( (char*)&posz, sizeof(posz) );

	ofs2.write( (char*)&offx, sizeof(offx) );
	ofs2.write( (char*)&offy, sizeof(offy) );
	ofs2.write( (char*)&offz, sizeof(offz) );

	ofs2.write( (char*)&lx, sizeof(lx) );
	ofs2.write( (char*)&ly, sizeof(ly) );
	ofs2.write( (char*)&lz, sizeof(lz) );
	ofs2.write( (char*)&rd, sizeof(rd) );

	ofs2.write( (char*)&m, sizeof(m) );

	

}





void MyODEBody::SetBodyPosition(double px, double py, double pz)
{
	ms->mu->lock();
	dBodySetPosition(body, px, py, pz);
	ms->mu->unlock();
	SetPosition(bscale_x*px + offx, bscale_y*py + offy, bscale_z*pz + offz);

	posx = px;
	posy = py;
	posz = pz;
}
void MyODEBody::SetBodyRotation(double r, double p, double y)
{
	Ogre::Quaternion q = GetRotQuat(r,p,y);
	dQuaternion dq;
	dq[0] = q.w;
	dq[1] = q.x;
	dq[2] = q.y;
	dq[3] = q.z;
	ms->mu->lock();
	dBodySetQuaternion(body, dq);
	ms->mu->unlock();
	SetQuaternion(q.w,q.x,q.y,q.z);

	roll = r;
	pitch = p;
	yaw = y;
}


double MyODEBody::GetPosition(int num)
{
	const dReal *P = dBodyGetPosition(body);
	return P[num];
}