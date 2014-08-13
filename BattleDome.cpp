#include "BattleDome.h"
#include "MyArray.h"








const double W_os = 0.2;

const double Fri_Dis = 0.7;
const double Case_Width = 0.3;
const double Case_1Length = 0.15;
const double Fri_Angle = 0.3;

const double Fri_Length = 0.25;
const double Fri_Width = 0.03;

const double Wall_Height = 0.1;

const double Ball_Radius = 0.03;

const double R_Offset = 0.1;












BattleDome::BattleDome()
{
	CF = new contact_flag(BALL_NUM);
	VisiSim = false;
	CF_set = true;
	CF_set2 = true;

	GRABITY = 9.8;	//重力加速度
	T = 0.002;	//サンプリングタイム

	Ball_Force = 0.3;
	QuiqFlag = false;
	
}

BattleDome::~BattleDome()
{

}



void BattleDome::makeParam()
{
	Base.m = 5;
	Base.r = 0.75;
	Base.lz = 1;
	Base.x = 0;
	Base.y = 0;
	Base.z = 0.6;
	Base.axisx = 0;
	Base.axisy = 0;
	Base.axisz = 1;
	Base.red = 0.;
	Base.green = 0.2;
	Base.blue = 1.;
	Base.reset();


	Guard.m = 1;
	Guard.r = 3.0;
	Guard.lz = 1.0;
	Guard.x = 0;
	Guard.y = 0;
	Guard.z = Base.z + Base.lz/2. + Guard.lz/2 + Ball_Radius*3;
	Guard.red = 1.;
	Guard.green = 0.2;
	Guard.blue = 1.;
	Guard.reset();

	CB.m = 0.01;
	CB.r = 0.2;
	CB.lz = 0.3;
	CB.x = 0;
	CB.y = 0;
	CB.z = Base.z + Base.lz/2. + CB.lz/2.;
	CB.jx = 0;
	CB.jy = 0;
	CB.jz = Base.z + Base.lz/2.;
	CB.axisx = 0;
	CB.axisy = 0;
	CB.axisz = 1;
	CB.red = 0.5;
	CB.green = 0.5;
	CB.blue = 0.5;

	CB.the = 0.;

	CB.reset();




	for(int i=0;i < 4;i++)
	{
		Take[i].m = 0.01;
		Take[i].r = 0.02;
		Take[i].lz = 0.12;
		Take[i].x = 0.6*cos(i*M_PI/2 + M_PI/4);
		Take[i].y = 0.6*sin(i*M_PI/2 + M_PI/4);
		Take[i].z = Base.z + Base.lz/2. + 0.02 + Take[i].r/2.;
		Take[i].jx = Take[i].x;
		Take[i].jy = Take[i].y;
		Take[i].jz = Base.z + Base.lz/2.;
		Take[i].axisx = 0;
		Take[i].axisy = 0;
		Take[i].axisz = 1;
		Take[i].red = 1.0;
		Take[i].green = 1.0;
		Take[i].blue = 0.0;

		Take[i].reset();
	}

	

	for(int i=0;i < 8;i++)
	{
		Fripper[i].m = 0.001;
		if(i == 0 || i == 1 || i == 4 || i == 5)
		{
			Fripper[i].lx = Fri_Width*2;
			Fripper[i].ly = Fri_Length;
		}
		else
		{
			Fripper[i].lx = Fri_Length;
			Fripper[i].ly = Fri_Width*2;
		}
		Fripper[i].lz = Wall_Height;
		if(i == 0)
		{
			Fripper[i].x = Fri_Dis;
			Fripper[i].y = -Case_Width + Fripper[i].ly/2.;

			Fripper[i].jx = Fri_Dis;
			Fripper[i].jy = -Case_Width;
		}
		else if(i == 1)
		{
			Fripper[i].x = Fri_Dis;
			Fripper[i].y = Case_Width - Fripper[i].ly/2.;

			Fripper[i].jx = Fri_Dis;
			Fripper[i].jy = Case_Width;
		}
		else if(i == 2)
		{
			Fripper[i].x = -Case_Width + Fripper[i].lx/2.;
			Fripper[i].y = Fri_Dis;

			Fripper[i].jx = -Case_Width;
			Fripper[i].jy = Fri_Dis;
		}
		else if(i == 3)
		{
			Fripper[i].x = Case_Width - Fripper[i].lx/2.;
			Fripper[i].y = Fri_Dis;

			Fripper[i].jx = Case_Width;
			Fripper[i].jy = Fri_Dis;
		}
		else if(i == 4)
		{
			Fripper[i].x = -Fri_Dis;
			Fripper[i].y = Fripper[0].y;

			Fripper[i].jx = -Fri_Dis;
			Fripper[i].jy = Fripper[0].jy;
		}
		else if(i == 5)
		{
			Fripper[i].x = -Fri_Dis;
			Fripper[i].y = Fripper[1].y;

			Fripper[i].jx = -Fri_Dis;
			Fripper[i].jy = Fripper[1].jy;
		}
		else if(i == 6)
		{
			Fripper[i].x = Fripper[2].x;
			Fripper[i].y = -Fri_Dis;

			Fripper[i].jx = Fripper[2].jx;
			Fripper[i].jy = -Fri_Dis;
		}
		else if(i == 7)
		{
			Fripper[i].x = Fripper[3].x;
			Fripper[i].y = -Fri_Dis;

			Fripper[i].jx = Fripper[3].jx;
			Fripper[i].jy = -Fri_Dis;
		}
		Fripper[i].z = Base.z + Base.lz/2. + Fripper[i].lz/2.;
		Fripper[i].jz = Base.z + Base.lz/2.;
		Fripper[i].axisx = 0;
		Fripper[i].axisy = 0;
		if(i == 0 || i == 3 || i == 5 || i == 6)
		{
			Fripper[i].axisz = 1;
		}
		else
		{
			Fripper[i].axisz = -1;
		}
		Fripper[i].red = 1.;
		Fripper[i].green = 0.2;
		Fripper[i].blue = 0.2;

		Fripper[i].the = -Fri_Angle;

		Fripper[i].reset();
	}

	double corAng = M_PI*2/(8.) *1/2. + M_PI*2/(Wall_NUM*2) *1/2.;
	int count = 0;
	for(int i=0;i < Wall_NUM*2;i++)
	{
		corAng = M_PI*2/(8.) *1/2. + M_PI*2/(Wall_NUM*2) *1/2. + M_PI*2/(Wall_NUM*2)*i;

		Wall[count].m = 0.1;
		Wall[count].lx = 2*M_PI*Base.r/(Wall_NUM*2)*1.5;
		Wall[count].ly = 0.01 + W_os;
		Wall[count].lz = Wall_Height*3;
		Wall[count].x = (Base.r + W_os/2.)*cos(corAng);
		Wall[count].y = (Base.r + W_os/2.)*sin(corAng);
		Wall[count].z = Base.z + Base.lz/2. + Wall[count].lz/2. - Wall[count].lz/3;

		Wall[count].dwx = (Base.r)*cos(corAng);
		Wall[count].dwy = (Base.r)*sin(corAng);
		Wall[count].dwz = Base.z + Base.lz/2. + Wall[count].lz/2. - Wall[count].lz/3;


		Wall[count].axisx = 0;
		Wall[count].axisy = 0;
		Wall[count].axisz = 1;
		Wall[count].red = 0.;
		Wall[count].green = 0.2;
		Wall[count].blue = 1.;
		Wall[count].Ang = corAng + M_PI/2.;

		//if(count == 0)Wall[count].z = 0.6;
		//if(count == 1)Wall[count].red = 0;

		
		count += 1;
		if(i == Wall_NUM/4-1 || i == Wall_NUM/4+Wall_NUM/2-1 || i == Wall_NUM/4+Wall_NUM-1 || i == Wall_NUM/4+Wall_NUM*3/2-1)i += Wall_NUM/4;

		Wall[count].reset();
	}


	for(int i=0;i < 4;i++)
	{
		Stick[i].m = 0.01;
		Stick[i].r = 0.04;
		Stick[i].lz = 0.15*2;
		Stick[i].x = (CB.r+Stick[i].lz/2 - 0.15)*cos(i*M_PI/2);
		Stick[i].y = (CB.r+Stick[i].lz/2 - 0.15)*sin(i*M_PI/2);
		Stick[i].z = Base.z + Base.lz/2. + Stick[i].r*1.2;
		Stick[i].axisx = 0;
		Stick[i].axisy = 0;
		Stick[i].axisz = 1;
		Stick[i].red = 0.5;
		Stick[i].green = 0.5;
		Stick[i].blue = 0.5;
		Stick[i].Ang = M_PI/2*i;

		Stick[i].reset();
	}

	for(int i=0;i < 4;i++)
	{
		Block[i].m = 0.001;
		Block[i].r = 0.05;
		Block[i].lz = 0.15;
		Block[i].x = (0.55)*cos(i*M_PI/2);
		Block[i].y = (0.55)*sin(i*M_PI/2);
		Block[i].z = Base.z + Base.lz/2. + Block[i].lz/2.;
		Block[i].axisx = 0;
		Block[i].axisy = 0;
		Block[i].axisz = 1;
		Block[i].red = 1.;
		Block[i].green = 1.;
		Block[i].blue = 1.;

		Block[i].the = Block[i].lz/2.;

		Block[i].reset();
	}

	for(int i=0;i < 4;i++)
	{
		Case[i] = new MyLink[5];

		for(int j=0;j < 2;j++)
		{
			Case[i][j].m = 1;
			if(i == 0 || i == 2)
			{
				Case[i][j].lx = Case_1Length;
				Case[i][j].ly = Wall[0].ly;
			}
			else
			{
				Case[i][j].lx = Wall[0].ly;
				Case[i][j].ly = Case_1Length;
			}
			Case[i][j].lz = 1.0;
			if(i == 0 && j == 0)
			{
				Case[i][j].x = Fri_Dis + Case[i][j].lx/2.;
				Case[i][j].y = -Case_Width - W_os/2.;
			}
			else if(i == 0 && j == 1)
			{
				Case[i][j].x = Fri_Dis + Case[i][j].lx/2.;
				Case[i][j].y = Case_Width + W_os/2.;
			}
			else if(i == 1 && j == 0)
			{
				Case[i][j].x = Case_Width + W_os/2.;
				Case[i][j].y = Fri_Dis + Case[i][j].ly/2.;
			}
			else if(i == 1 && j == 1)
			{
				Case[i][j].x = -Case_Width - W_os/2.;
				Case[i][j].y = Fri_Dis + Case[i][j].ly/2.;
			}
			else if(i == 2 && j == 0)
			{
				Case[i][j].x = -Fri_Dis - Case[i][j].lx/2.;
				Case[i][j].y = -Case_Width - W_os/2.;
			}
			else if(i == 2 && j == 1)
			{
				Case[i][j].x = -Fri_Dis - Case[i][j].lx/2.;
				Case[i][j].y = Case_Width + W_os/2.;
			}
			else if(i == 3 && j == 0)
			{
				Case[i][j].x = Case_Width + W_os/2.;
				Case[i][j].y = -Fri_Dis - Case[i][j].ly/2.;
			}
			else if(i == 3 && j == 1)
			{
				Case[i][j].x = -Case_Width - W_os/2.;
				Case[i][j].y = -Fri_Dis - Case[i][j].ly/2.;
			}
			Case[i][j].z = Wall[0].z + Wall[0].lz/2 - Case[i][j].lz/2;
			Case[i][j].axisx = 0;
			Case[i][j].axisy = 0;
			Case[i][j].axisz = 1;
			Case[i][j].red = 1.;
			Case[i][j].green = 1.;
			Case[i][j].blue = 1.;
			Case[i][j].reset();


			if(i == 0 || i == 2)
			{
				Case[i][j].lx = Case[i][j].lx*1.2;
			}
			else
			{
				Case[i][j].ly = Case[i][j].ly*1.2;
			}
		}

		for(int j=2;j < 4;j++)
		{
			Case[i][j].m = 1;
			
			
			if(i == 0 || i == 2)
			{
				Case[i][j].lx = Case_Width*sqrt(2.);
				Case[i][j].ly = Wall[0].ly;
			}
			else
			{
				Case[i][j].lx = Wall[0].ly;
				Case[i][j].ly = Case_Width*sqrt(2.);
			}
			
			Case[i][j].lz = 1.0;
			if(i == 0 && j == 2)
			{
				

				Case[i][j].x = Fri_Dis + Case[0][0].lx + Case[i][j].lx/2*sqrt(2.)/2;
				Case[i][j].y = -Case_Width + Case[i][j].lx/2*sqrt(2.)/2 - W_os/2.;
				Case[i][j].Ang = M_PI/4;
			}
			else if(i == 0 && j == 3)
			{
				Case[i][j].x = Fri_Dis + Case[0][0].lx + Case[i][j].lx/2*sqrt(2.)/2;
				Case[i][j].y = Case_Width - Case[i][j].lx/2*sqrt(2.)/2 + W_os/2.;
				Case[i][j].Ang = -M_PI/4;
			}
			else if(i == 1 && j == 2)
			{
				Case[i][j].x = Case_Width - Case[i][j].ly/2*sqrt(2.)/2 + W_os/2.;
				Case[i][j].y = Fri_Dis + Case[0][0].lx + Case[i][j].ly/2*sqrt(2.)/2;
				Case[i][j].Ang = M_PI/4;
			}
			else if(i == 1 && j == 3)
			{
				Case[i][j].x = -Case_Width + Case[i][j].ly/2*sqrt(2.)/2 - W_os/2.;
				Case[i][j].y = Fri_Dis + Case[0][0].lx + Case[i][j].ly/2*sqrt(2.)/2;
				Case[i][j].Ang = -M_PI/4;
			}
			else if(i == 2 && j == 2)
			{
				Case[i][j].x = -Fri_Dis - Case[0][0].lx - Case[i][j].lx/2*sqrt(2.)/2;
				Case[i][j].y = -Case_Width + Case[i][j].lx/2*sqrt(2.)/2 - W_os/2.;
				Case[i][j].Ang = -M_PI/4;
			}
			else if(i == 2 && j == 3)
			{
				Case[i][j].x = -Fri_Dis - Case[0][0].lx - Case[i][j].lx/2*sqrt(2.)/2;
				Case[i][j].y = Case_Width - Case[i][j].lx/2*sqrt(2.)/2 + W_os/2.;
				Case[i][j].Ang = M_PI/4;
			}
			else if(i == 3 && j == 2)
			{
				Case[i][j].x = Case_Width - Case[i][j].ly/2*sqrt(2.)/2 + W_os/2.;
				Case[i][j].y = -Fri_Dis - Case[0][0].lx - Case[i][j].ly/2*sqrt(2.)/2;
				Case[i][j].Ang = -M_PI/4;
			}
			else if(i == 3 && j == 3)
			{
				Case[i][j].x = -Case_Width + Case[i][j].ly/2*sqrt(2.)/2 - W_os/2.;
				Case[i][j].y = -Fri_Dis - Case[0][0].lx - Case[i][j].ly/2*sqrt(2.)/2;
				Case[i][j].Ang = M_PI/4;
			}
			Case[i][j].z = Wall[0].z + Wall[0].lz/2 - Case[i][j].lz/2;
			Case[i][j].axisx = 0;
			Case[i][j].axisy = 0;
			Case[i][j].axisz = 1;
			Case[i][j].red = 1.;
			Case[i][j].green = 1.;
			Case[i][j].blue = 1.;
			Case[i][j].reset();


			if(i == 0 || i == 2)
			{
				Case[i][j].lx = Case[i][j].lx*1.5;
			}
			else
			{
				Case[i][j].ly = Case[i][j].ly*1.5;
			}
		}

		{
			Case[i][4].m = 1;
			Case[i][4].Ang = M_PI/6.;
			
			
			if(i == 0 || i == 2)
			{
				Case[i][4].lx = 0.6;
				Case[i][4].ly = 0.6;
			}
			else
			{
				Case[i][4].lx = 0.6;
				Case[i][4].ly = 0.6;
			}
			Case[i][4].lz = Wall[0].ly;
			
			if(i == 0)
			{
				Case[i][4].x = Fri_Dis + R_Offset*0.5 + Case[i][4].lx/2*cos(Case[i][4].Ang);
				Case[i][4].y = 0;
			}
			else if(i == 1)
			{
				Case[i][4].x = 0;
				Case[i][4].y = Fri_Dis + R_Offset*0.5 + Case[i][4].ly/2*cos(Case[i][4].Ang);
			}
			else if(i == 2)
			{
				Case[i][4].x = -Fri_Dis - R_Offset*0.5 - Case[i][4].lx/2*cos(Case[i][4].Ang);
				Case[i][4].y = 0;
			}
			else if(i == 3)
			{
				Case[i][4].x = 0;
				Case[i][4].y = -Fri_Dis - R_Offset*0.5 - Case[i][4].ly/2*cos(Case[i][4].Ang);
			}
			if(i == 0 || i == 2)Case[i][4].z = Base.z + Base.lz/2. - Case[i][4].lz/2.  - Case[i][4].lx/2*sin(Case[i][4].Ang);
			else Case[i][4].z = Base.z + Base.lz/2. - Case[i][4].lz/2.  - Case[i][4].ly/2*sin(Case[i][4].Ang);
			Case[i][4].axisx = 0;
			Case[i][4].axisy = 0;
			Case[i][4].axisz = 1;
			Case[i][4].red = 1.;
			Case[i][4].green = 1.;
			Case[i][4].blue = 1.;
			Case[i][4].reset();
		}

		

	}

	int bcount = 0;
	while(bcount < BALL_NUM)
	{
		double r = ((double)rand() / ((double)RAND_MAX + 1)) * Base.r/4;
		double the = ((double)rand() / ((double)RAND_MAX + 1)) * 2*M_PI;

		double x = (r + CB.r + Ball_Radius)*cos(the);
		double y = (r + CB.r + Ball_Radius)*sin(the);
		bool bf = true;
		for(int i=0;i < bcount;i++)
		{
			double len = sqrt((x-ball[i].x)*(x-ball[i].x) + (y-ball[i].y)*(y-ball[i].y));
			if(len < Ball_Radius*2)bf = false;

			
		}
		if(sqrt(x*x) < Ball_Radius + Stick[0].r)bf = false;
		if(sqrt(y*y) < Ball_Radius + Stick[0].r)bf = false;
		
		if(bf)
		{
			ball[bcount].m = 0.005;
			ball[bcount].r = Ball_Radius;
			ball[bcount].x = x;
			ball[bcount].y = y;
			ball[bcount].z = Base.z + Base.lz/2. + ball[bcount].r;
			ball[bcount].red = ((double)rand() / ((double)RAND_MAX + 1)) * 2;
			ball[bcount].green = ((double)rand() / ((double)RAND_MAX + 1)) * 2;
			ball[bcount].blue = ((double)rand() / ((double)RAND_MAX + 1)) * 2;
			ball[bcount].reset();

			bcount += 1;
		}
	}
}


void BattleDome::makeRobot()
{
	{
		dMatrix3 R;                          
		dRFromAxisAndAngle(R,0,1,0,M_PI/2);  
		dMass mass;
		Base.body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetCylinderTotal(&mass, Base.m, 1, Base.r+R_Offset, Base.lz);
		dBodySetMass(Base.body,&mass);
		Base.geom = dCreateCylinder(space,Base.r+R_Offset, Base.lz);
		dGeomSetBody(Base.geom, Base.body);
		//dBodySetRotation(Base.body, R); 
		dBodySetPosition(Base.body, Base.x, Base.y, Base.z);
	}



	
	


	{
		Base.joint = dJointCreateFixed(world, 0);
		dJointAttach(Base.joint, Base.body, 0);
		dJointSetFixed(Base.joint);
	}


	{ 
		dMass mass;
		Guard.body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetCylinderTotal(&mass, Guard.m, 1, Guard.r, Guard.lz);
		dBodySetMass(Guard.body,&mass);
		Guard.geom = dCreateCylinder(space,Guard.r, Guard.lz);
		dGeomSetBody(Guard.geom, Guard.body);
		dBodySetPosition(Guard.body, Guard.x, Guard.y, Guard.z);
	}


	{
		Guard.joint = dJointCreateFixed(world, 0);
		dJointAttach(Guard.joint, Base.body, Guard.body);
		dJointSetFixed(Guard.joint);
	}


	{
		dMatrix3 R;                          
		dRFromAxisAndAngle(R,0,1,0,M_PI/2);  
		dMass mass;
		CB.body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetCylinderTotal(&mass, CB.m, 1, CB.r, CB.lz);
		dBodySetMass(CB.body,&mass);
		CB.geom = dCreateCylinder(space,CB.r, CB.lz);
		dGeomSetBody(CB.geom, CB.body);
		//dBodySetRotation(CB.body, R); 
		dBodySetPosition(CB.body, CB.x, CB.y, CB.z);
	}

	{
		CB.joint = dJointCreateHinge(world, 0);
		dJointAttach(CB.joint,CB.body, Base.body);
		dJointSetHingeAnchor(CB.joint, CB.jx, CB.jy, CB.jz);
		dJointSetHingeAxis(CB.joint, CB.axisx, CB.axisy,CB.axisz);
	}


	for(int i=0;i < 4;i++){
		dMatrix3 R;                          
		dRFromAxisAndAngle(R,0,1,0,M_PI/2);
		dMass mass;
		Take[i].body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetCylinderTotal(&mass, Take[i].m, 1, Take[i].r, Take[i].lz);
		dBodySetMass(Take[i].body,&mass);
		Take[i].geom = dCreateCylinder(space,Take[i].r, Take[i].lz);
		dGeomSetBody(Take[i].geom, Take[i].body);
		dBodySetRotation(Take[i].body, R);
		dBodySetPosition(Take[i].body, Take[i].x, Take[i].y, Take[i].z);

		{
			Take[i].joint = dJointCreateHinge(world, 0);
			dJointAttach(Take[i].joint,Take[i].body, Base.body);
			dJointSetHingeAnchor(Take[i].joint, Take[i].jx, Take[i].jy, Take[i].jz);
			dJointSetHingeAxis(Take[i].joint, Take[i].axisx, Take[i].axisy,Take[i].axisz);
		}
	}



	for(int i=0;i < 4;i++){
		dMatrix3 R;                          
		if(i%2==0)dRFromAxisAndAngle(R,0,1,0,M_PI/2);
		else dRFromAxisAndAngle(R,1,0,0,M_PI/2);
		dMass mass;
		Stick[i].body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetCylinderTotal(&mass, Stick[i].m, 1, Stick[i].r, Stick[i].lz);
		dBodySetMass(Stick[i].body,&mass);
		Stick[i].geom = dCreateCylinder(space,Stick[i].r, Stick[i].lz);
		dGeomSetBody(Stick[i].geom, Stick[i].body);
		dBodySetRotation(Stick[i].body, R);
		dBodySetPosition(Stick[i].body, Stick[i].x, Stick[i].y, Stick[i].z);
	
		{
			Stick[i].joint = dJointCreateFixed(world, 0);
			dJointAttach(Stick[i].joint, Stick[i].body, CB.body);
			dJointSetFixed(Stick[i].joint);
		}
	}


	for(int i=0;i < 4;i++){
		dMass mass;
		Block[i].body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetCylinderTotal(&mass, Block[i].m, 1, Block[i].r, Block[i].lz);
		dBodySetMass(Block[i].body,&mass);
		Block[i].geom = dCreateCylinder(space,Block[i].r, Block[i].lz);
		dGeomSetBody(Block[i].geom, Block[i].body);
		dBodySetPosition(Block[i].body, Block[i].x, Block[i].y, Block[i].z);

		{
			Block[i].joint = dJointCreateSlider( world, 0 );
			dJointAttach( Block[i].joint, Block[i].body, Base.body );
			dJointSetSliderAxis( Block[i].joint, Block[i].axisx, Block[i].axisy, Block[i].axisz );
		}
	}


	for(int i=0;i < 4;i++)
	{
		for(int j=0;j < 5;j++)
		{
			dMass mass;
			Case[i][j].body  = dBodyCreate(world);
			dMassSetZero(&mass);
			dMassSetBoxTotal(&mass, Case[i][j].m, Case[i][j].lx, Case[i][j].ly, Case[i][j].lz);
			dBodySetMass(Case[i][j].body,&mass);
			Case[i][j].geom = dCreateBox(space,Case[i][j].lx,  Case[i][j].ly, Case[i][j].lz);
			dGeomSetBody(Case[i][j].geom, Case[i][j].body);
			if(j == 2 || j == 3)
			{
				dMatrix3 R;                          
				dRFromAxisAndAngle(R,0,0,1,Case[i][j].Ang);
				dBodySetRotation(Case[i][j].body, R);
			}
			if(j == 4)
			{
				dMatrix3 R;                          
				if(i == 0)dRFromAxisAndAngle(R,0,1,0,Case[i][j].Ang);
				else if(i == 1)dRFromAxisAndAngle(R,1,0,0,-Case[i][j].Ang);
				else if(i == 2)dRFromAxisAndAngle(R,0,1,0,-Case[i][j].Ang);
				else if(i == 3)dRFromAxisAndAngle(R,1,0,0,Case[i][j].Ang);
				dBodySetRotation(Case[i][j].body, R);
			}
			dBodySetPosition(Case[i][j].body, Case[i][j].x, Case[i][j].y, Case[i][j].z);
			
			{
				Case[i][j].joint = dJointCreateFixed(world, 0);
				dJointAttach(Case[i][j].joint, Case[i][j].body, Base.body);
				dJointSetFixed(Case[i][j].joint);
			}
		}
	}
	for(int i=0;i < Wall_NUM;i++){
		dMatrix3 R;                          
		dRFromAxisAndAngle(R,0,0,1,Wall[i].Ang);  
		dMass mass;
		Wall[i].body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetBoxTotal(&mass, Wall[i].m, Wall[i].lx, Wall[i].ly, Wall[i].lz);
		dBodySetMass(Wall[i].body,&mass);
		Wall[i].geom = dCreateBox(space,Wall[i].lx, Wall[i].ly, Wall[i].lz);
		dGeomSetBody(Wall[i].geom, Wall[i].body);
		dBodySetRotation(Wall[i].body, R); 
		dBodySetPosition(Wall[i].body, Wall[i].x, Wall[i].y, Wall[i].z);

		{
			Wall[i].joint = dJointCreateFixed(world, 0);
			dJointAttach(Wall[i].joint, Wall[i].body, Base.body);
			dJointSetFixed(Wall[i].joint);
		}
	}


	for(int i=0;i < 8;i++){
		dMass mass;
		Fripper[i].body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetBoxTotal(&mass, Fripper[i].m, Fripper[i].lx, Fripper[i].ly, Fripper[i].lz);
		dBodySetMass(Fripper[i].body,&mass);
		Fripper[i].geom = dCreateBox(space,Fripper[i].lx, Fripper[i].ly, Fripper[i].lz);
		dGeomSetBody(Fripper[i].geom, Fripper[i].body);
		dBodySetPosition(Fripper[i].body, Fripper[i].x, Fripper[i].y, Fripper[i].z);

		{
			Fripper[i].joint = dJointCreateHinge(world, 0);
			dJointAttach(Fripper[i].joint,Fripper[i].body, Base.body);
			dJointSetHingeAnchor(Fripper[i].joint, Fripper[i].jx, Fripper[i].jy, Fripper[i].jz);
			dJointSetHingeAxis(Fripper[i].joint, Fripper[i].axisx, Fripper[i].axisy,Fripper[i].axisz);
		}
	}

	for(int i=0;i < BALL_NUM;i++){
		dMass mass;
		ball[i].body  = dBodyCreate(world);
		dMassSetZero(&mass);
		dMassSetSphereTotal(&mass, ball[i].m, ball[i].r);
		dBodySetMass(ball[i].body,&mass);
		ball[i].geom = dCreateSphere(space,ball[i].r);
		dGeomSetBody(ball[i].geom, ball[i].body);
		dBodySetPosition(ball[i].body, ball[i].x, ball[i].y, ball[i].z);

		
	}
}




void BattleDome::Pcontrol()
{
	for(int i=0;i < 8;i++){
		dReal tmp = dJointGetHingeAngle(Fripper[i].joint);
		dReal kp = 300;
		dReal u = kp*(Fripper[i].the - tmp);
		dJointSetHingeParam(Fripper[i].joint,dParamVel, u);  // 角速度の設定
		dJointSetHingeParam(Fripper[i].joint,dParamFMax,500.); // トルクの設定*/
	}

	{
		dJointSetHingeParam(CB.joint,dParamVel, CB.the);  // 角速度の設定
		dJointSetHingeParam(CB.joint,dParamFMax,5000.); // トルクの設定*/
	}

	for(int i=0;i < 4;i++){
		dReal tmp = dJointGetSliderPosition(Block[i].joint);
		dReal kp = 10;
		dReal u = kp*(Block[i].the - tmp);
		dJointSetSliderParam(Block[i].joint,dParamVel, u);  // 角速度の設定
		dJointSetSliderParam(Block[i].joint,dParamFMax,5000.); // トルクの設定*/
	}
}

void BattleDome::walk()
{

	Pcontrol();
	static int count_w = 0;
	count_w += 1;
	if(count_w%10 == 0)
	{
		for(int i=0;i < 4;i++)
		{
			if(Fripper[i*2].Auto)
			{
				Fripper[i*2].F = rand()%2;
				Fripper[i*2+1].F = rand()%2;

				
			}
		}
	}

	for(int i=0;i < 4;i++)
	{
		if(Fripper[i*2].F == 0)
		{
			Fripper[i*2].the = -Fri_Angle;
		}
		else
		{
			Fripper[i*2].the = Fri_Angle;
		}
		if(Fripper[i*2+1].F == 0)
		{
			Fripper[i*2+1].the = -Fri_Angle;
		}
		else
		{
			Fripper[i*2+1].the = Fri_Angle;
		}
		if(Fripper[i*2].F == 0)
		{
			Block[i].the = 0;
		}
		else
		{
			Block[i].the = -CB.lz;
		}
	}


	for(int i=0;i < BALL_NUM;i++)
	{
		if(ball[i].BFlag)
		{
			/*ball[i].red = 0;
			ball[i].blue = 0;
			ball[i].green = 0;*/
			const dReal *P = dBodyGetPosition(ball[i].body);
			if(sqrt(P[0]*P[0]+P[1]*P[1]) < Base.r)
			{
				/*ball[i].red = 1;
				ball[i].blue = 1;
				ball[i].green = 1;*/
				dReal De = sqrt((0 - P[0])*(0 - P[0]) + (0 - P[1])*(0 - P[1]));
				dReal Fx = Ball_Force*(0 - P[0])/De;
				dReal Fy = Ball_Force*(0 - P[1])/De;
				dBodyAddForce(ball[i].body,Fx,Fy,0);
			}
		}
	}

	for(int i=0;i < BALL_NUM;i++)
	{
		const dReal *P = dBodyGetPosition(ball[i].body);
		
		if(sqrt(P[0]*P[0]+P[1]*P[1]) > Base.r*1.0)
		{
			const dReal dP[3] = {(P[0]-ball[i].tx)/T,(P[1]-ball[i].ty)/T,(P[2]-ball[i].tz)/T};
			if(ball[i].BFlag)
			{
				double minS = 0.01;
				if(QuiqFlag)minS = 0.1;
				if(sqrt(dP[0]*dP[0]+dP[1]*dP[1]+dP[2]*dP[2]) < minS)
				{
					ball[i].dcount += 1;
					if(ball[i].dcount > 10)
					{
						ball[i].BFlag = false;
						ball[i].joint = dJointCreateFixed(world, 0);
						dJointAttach(ball[i].joint, ball[i].body, 0);
						dJointSetFixed(ball[i].joint);

					}
				}
				else
				{
					ball[i].dcount = 0;
				}

			}
			else
			{
				ball[i].dcount = 0;
			}
		}

		ball[i].tx = P[0];
		ball[i].ty = P[1];
		ball[i].tz = P[2];

		//if((sqrt(ball[i].tx*ball[i].tx) > Base.r*2) || (sqrt(ball[i].ty*ball[i].ty) > Base.r*2))ofs2 << i << "\t";
	}
	//ofs2 << std::endl;

}

void BattleDome::NearCallBack(dGeomID o1, dGeomID o2) {
	//return;

	dBodyID b1 = dGeomGetBody(o1), b2 = dGeomGetBody(o2);
	if (b1 && b2 && dAreConnectedExcluding(b1,b2,dJointTypeContact)) return;
	if (b1 && b2 && dAreConnected(b1,b2)) return;
	//if ((o1 != ground) && (o2 != ground)) return;

	bool nflag = false;
	for(int i=0;i < BALL_NUM;i++)
	{
	  if(b1 == ball[i].body || b2 == ball[i].body)
	  {
		  if(ball[i].BFlag)nflag = true;
	  }
	}
	if(!nflag)return;


	if(CF_set)
	{
	  for(int i=0;i < BALL_NUM;i++)
	  {
		  if(b1 == ball[i].body || b2 == ball[i].body)
		  {
				for(int j=0;j < Wall_NUM;j++)
				{
					if(b1 == Wall[j].body || b2 == Wall[j].body)
					{
						CF->flag[i] = true;
					}
					
				}
				for(int j=0;j < 4;j++)
				{
					if(b1 == Stick[j].body || b2 == Stick[j].body)
					{
						CF->flag[i] = true;
					}
					
				}
				for(int j=0;j < 8;j++)
				{
					if(b1 == Fripper[j].body || b2 == Fripper[j].body)
					{
						CF->flag[i] = true;
					}
					
				}
				if(b1 == CB.body || b2 == CB.body)
				{
					CF->flag[i] = true;
				}
				if(b1 == Guard.body || b2 == Guard.body)
				{
					CF->flag[i] = true;
				}
		  }
	  }
	}

	static const int N = 20;
	dContact contact[N];
	int n = dCollide(o1,o2,N,&contact[0].geom,sizeof(dContact));

	if (n > 0) {
		for (int i=0; i<n; i++) {
			//contact[i].surface.mode = dContactApprox1|dContactSoftERP|dContactSoftCFM;
			contact[i].surface.mode = dContactBounce; 

			double GKP = 100000000;
			double GKD = 1000000;


			contact[i].surface.mu   = 0;
			contact[i].surface.bounce = 0.0;
			for(int j=0;j < Wall_NUM;j++)
			{
				if(b1 == Wall[j].body || b2 == Wall[j].body)
				{
					contact[i].surface.bounce = 0.8;
				}
				
			}
			for(int j=0;j < 4;j++)
			{
				if(b1 == Stick[j].body || b2 == Stick[j].body)
				{
					contact[i].surface.bounce = 0.0;
				}
				
			}
			for(int j=0;j < 8;j++)
			{
				if(b1 == Fripper[j].body || b2 == Fripper[j].body)
				{
					contact[i].surface.bounce = 0.0;
				}
				
			}
			if(b1 == Base.body || b2 == Base.body)
			{
				contact[i].surface.bounce = 0.0;
			}
			if(b1 == Guard.body || b2 == Guard.body)
			{
				contact[i].surface.bounce = 0.0;
			}
			for(int j=0;j < 4;j++)
			{
				for(int k=0;k < 5;k++)
				{
					if(b1 == Case[j][k].body || b2 == Case[j][k].body)
					{
						contact[i].surface.bounce = 0.0;
					}
				}
				
			}


			contact[i].surface.bounce_vel = 0.0;
			//contact[i].surface.soft_erp = T*GKP/(T*GKP+GKD);
			//contact[i].surface.soft_cfm = 1/(T*GKP+GKD);
			dJointID c = dJointCreateContact(world,contactgroup,&contact[i]);
			dJointAttach(c,b1,b2);
		}
	}
}






void BattleDome::SetFripper(int num, int f1, int f2)
{
	Fripper[num*2].F = f1;
	Fripper[num*2+1].F = f2;
}

void BattleDome::SetFripperManual(bool f1, bool f2, bool f3, bool f4)
{
	Fripper[0].Auto = f1;
	Fripper[1].Auto = f1;

	Fripper[2].Auto = f2;
	Fripper[3].Auto = f2;

	Fripper[4].Auto = f3;
	Fripper[5].Auto = f3;

	Fripper[6].Auto = f4;
	Fripper[7].Auto = f4;
}

double BattleDome::GetFripperInput(int num)
{
	dReal tmp = dJointGetHingeAngle(Fripper[num].joint);

	double ang = tmp;

	return ang;
}



void BattleDome::SetBallPQ(MyLink ml,int num, double offx, double offy, double offz, double scalex, double scaley, double scalez)
{
	SetPQ(ball[num],ml,offx,offy,offz,scalex,scaley,scalez);
}


void BattleDome::SetCBPQ(MyLink ml, double offx, double offy, double offz, double scalex, double scaley, double scalez)
{
	SetPQ(CB,ml,offx,offy,offz,scalex,scaley,scalez);
}

void BattleDome::SetCBAngularVelocity(double vel)
{
	CB.the = vel;

}

void BattleDome::SetBlockPQ(MyLink ml,int num, double offx, double offy, double offz, double scalex, double scaley, double scalez)
{
	SetPQ(Block[num],ml,offx,offy,offz,scalex,scaley,scalez);
}

void BattleDome::SetFripperPQ(MyLink ml,int num, double offx, double offy, double offz, double scalex, double scaley, double scalez)
{
	SetPQ(Fripper[num],ml,offx,offy,offz,scalex,scaley,scalez);
}

void BattleDome::SetBasePQ(MyLink ml, double offx, double offy, double offz, double scalex, double scaley, double scalez)
{
	SetPQ(Base,ml,offx,offy,offz,scalex,scaley,scalez);
}

void BattleDome::SetTakePQ(MyLink ml,int num, double offx, double offy, double offz, double scalex, double scaley, double scalez)
{
	SetPQ(Take[num],ml,offx,offy,offz,scalex,scaley,scalez);
}

int BattleDome::getBallNum()
{
	int bnum = 0;
	for(int i=0;i < 4;i++)
	{
		Bnum[i] = 0;
	}
	for(int i=0;i < BALL_NUM;i++)
	{
		if(ball[i].BFlag)
		{
			const dReal *P = dBodyGetPosition(ball[i].body);
			//if(P[0] < Fri_Dis*3 || P[0] > -Fri_Dis*3 || P[1] < Fri_Dis*3 || P[1] > -Fri_Dis*3)
			if(P[2] > Base.z && P[2] < Guard.z)
			{
				bnum += 1;
			}
		}
		else
		{
			const dReal *P = dBodyGetPosition(ball[i].body);
			if(P[0] >= Fri_Dis)
			{
				Bnum[0] += 1;
			}
			if(P[1] >= Fri_Dis)
			{
				Bnum[1] += 1;
			}
			if(P[0] <= -Fri_Dis)
			{
				Bnum[2] += 1;
			}
			if(P[1] <= -Fri_Dis)
			{
				Bnum[3] += 1;
			}
		}
	}
	return bnum;
}

int BattleDome::getBallNumCase(int num)
{
	return Bnum[num];
}

void BattleDome::SetSleepTime(int st)
{
	SleepTime = st;
}


void BattleDome::SetSamplingTime(double t)
{
	T = t;
}
void BattleDome::SetQF(bool qf)
{
	QuiqFlag = qf;
}
void BattleDome::SetBF(double bf)
{
	Ball_Force = bf;
}