#include "SubWindow.h"
#include "MyOgreMacro.h"



SubWindow::SubWindow()
{

	pos_x = 0;
	pos_y = 0;
	size_x = 1;
	size_y = 1;
	campos_x = 0;
	campos_y = 0;
	campos_z = 0;
	cam_roll = 0;
	cam_pitch = 0;
	cam_yaw = 0;
	cam_len = 0;
	visi = true;
}

void SubWindow::SetPosition( float x, float y)
{
	label->setPosition(CEGUI::UVector2(CEGUI::UDim(x, 0),CEGUI::UDim(y, 0)));
	pos_x = x;
	pos_y = y;
}
void SubWindow::SetSize( float sx, float sy)
{
	label->setSize(CEGUI::USize(CEGUI::UDim(sx, 0), CEGUI::UDim(sy, 0)));
	size_x = sx;
	size_y = sy;
}
void SubWindow::SetCameraRoll( float ang)
{
	cam->roll(Ogre::Degree(ang));
	cam_roll = ang;
}
void SubWindow::SetCameraPitch( float ang)
{
	cam->pitch(Ogre::Degree(ang));
	cam_pitch = ang;
}
void SubWindow::SetCameraYaw( float ang)
{
	cam->yaw(Ogre::Degree(ang));
	cam_yaw = ang;
}

void SubWindow::SetCameraRotation(float r, float p, float y)
{
	SetCameraQuaternion(1,0,0,0);
	SetCameraRoll(r);
	SetCameraPitch(p);
	SetCameraYaw(y);
}


void SubWindow::SetCameraPosition( float x, float y, float z)
{
	cam->setPosition(x, y, z);
	campos_x = x;
	campos_y = y;
	campos_z = z;
}
void SubWindow::SetCameraQuaternion(float w, float x, float y, float z)
{
	cam->setOrientation(Ogre::Quaternion(w,x,y,z));

}

void SubWindow::SetVisible(bool v)
{
	label->setVisible(v);
	visi = v;
}

void SubWindow::UpdateCameraPQ(float px, float py, float pz, float roll, float pitch, float yaw, float len)
{


	Ogre::Quaternion tRot = GetRotQuat(roll, pitch, yaw);

	Ogre::Vector3 tLen(0,0,len);
	tLen = tRot * tLen;

	SetCameraPosition(px+tLen.x, py+tLen.y, pz+tLen.z);
	SetCameraQuaternion(tRot.w,tRot.x,tRot.y,tRot.z);

	campos_x = px;
	campos_y = py;
	campos_z = pz;

	cam_roll = roll;
	cam_pitch = pitch;
	cam_yaw = yaw;

	cam_len = len;
}


bool SubWindow::openb(std::ifstream &ifs)
{
	Iname = ReadString(ifs);
	Cname = ReadString(ifs);
	Wname = ReadString(ifs);
	ISname = ReadString(ifs);
	Tname = ReadString(ifs);

	ifs.read( (char*)&pos_x, sizeof(pos_x) );
	ifs.read( (char*)&pos_y, sizeof(pos_y) );

	ifs.read( (char*)&size_x, sizeof(size_x) );
	ifs.read( (char*)&size_y, sizeof(size_y) );

	ifs.read( (char*)&campos_x, sizeof(campos_x) );
	ifs.read( (char*)&campos_y, sizeof(campos_y) );
	ifs.read( (char*)&campos_z, sizeof(campos_z) );


	ifs.read( (char*)&cam_roll, sizeof(cam_roll) );
	ifs.read( (char*)&cam_pitch, sizeof(cam_pitch) );
	ifs.read( (char*)&cam_yaw, sizeof(cam_yaw) );

	ifs.read( (char*)&visi, sizeof(visi) );



	return true;
}

void SubWindow::save(std::ofstream &ofs2)
{
	WriteString(Iname , ofs2 );
	WriteString(Cname , ofs2 );
	WriteString(Wname , ofs2 );
	WriteString(ISname , ofs2 );
	WriteString(Tname , ofs2 );

	ofs2.write( (char*)&pos_x, sizeof(pos_x) );
	ofs2.write( (char*)&pos_y, sizeof(pos_y) );

	ofs2.write( (char*)&size_x, sizeof(size_x) );
	ofs2.write( (char*)&size_y, sizeof(size_y) );

	ofs2.write( (char*)&campos_x, sizeof(campos_x) );
	ofs2.write( (char*)&campos_y, sizeof(campos_y) );
	ofs2.write( (char*)&campos_z, sizeof(campos_z) );

	ofs2.write( (char*)&cam_roll, sizeof(cam_roll) );
	ofs2.write( (char*)&cam_pitch, sizeof(cam_pitch) );
	ofs2.write( (char*)&cam_yaw, sizeof(cam_yaw) );

	ofs2.write( (char*)&visi, sizeof(visi) );

	
}