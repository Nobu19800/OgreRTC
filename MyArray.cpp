#include "MyArray.h"

double myabs(double a)
{


	if(a > 0)return a;
	else return -a;
}

Mat::Mat(int l, int w)
{
	len = l;
	wid = w;

	mat = new double*[len];
	for(int i = 0;i < len;i++)mat[i] = new double[wid];

	for(int i=0;i<len;i++)
	{
		for(int j=0;j<wid;j++)
		{
			mat[i][j] = 0;

		}

	}

	/*for(int i = 0;i < len;i++)delete(mat[i]);
	delete(mat);*/


}

Mat::~Mat()
{


	for(int i = 0;i < len;i++)delete[] mat[i];
	delete[] mat;


}

Mat *Mat::dot(Mat *M)
{

	
	Mat *Ans = new Mat(M->len, this->wid);

	for(int i=0;i < wid;i++)
	{
		for(int j=0;j < M->len;j++)

			
			for(int k=0;k < len;k++)
			{
				Ans->mat[j][i] += this->mat[k][i] * M->mat[j][k];	
			}
	}

	return Ans;




}






void Mat::CreateI()
{
	mat[0][0] = 1;
	mat[1][0] = 0;
	mat[2][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = 1;
	mat[2][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = 0;
	mat[2][2] = 1;


}

void Mat::Copy(Mat *m)
{
	
	
	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			this->mat[i][j] = m->mat[i][j];

		}

	}


}

void Mat::Copy2(Mat *m)
{
	
	
	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			this->mat[i][j] = m->mat[i][j];

		}

	}

	delete m;


}





void Mat::add(Mat *m)
{
	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			this->mat[i][j] += m->mat[i][j];
		}

	}


}




void Mat::sub(Mat *m)
{
	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			mat[i][j] -= m->mat[i][j];
		}

	}


}

void Mat::mult(double m)
{
	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			mat[i][j] *= m;
		}

	}


}



Mat *Mat::cross(Mat *m)
{
	Mat *Ans = new Mat(len, wid);

	
	Ans->mat[0][0] = mat[0][1] * m->mat[0][2] - mat[0][2] * m->mat[0][1];
	Ans->mat[0][1] = mat[0][2] * m->mat[0][0] - mat[0][0] * m->mat[0][2];
	Ans->mat[0][2] = mat[0][0] * m->mat[0][1] - mat[0][1] * m->mat[0][0];


	return Ans;


}



Mat *Mat::trans()
{
	Mat *Ans = new Mat(wid, len);

	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			Ans->mat[j][i] = mat[i][j]; 
		}
	}


	return Ans;


}

Mat *Mat::add2(Mat *m)
{
	Mat *Ans = new Mat(len, wid);
	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			Ans->mat[i][j] = mat[i][j] + m->mat[i][j];
		}

	}

	return Ans;


}

Mat *Mat::sub2(Mat *m)
{
	Mat *Ans = new Mat(len, wid);
	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			Ans->mat[i][j] = mat[i][j] - m->mat[i][j];
		}

	}

	return Ans;


}


Mat *Mat::mult2(double m)
{
	Mat *Ans = new Mat(len, wid);
	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			Ans->mat[i][j] = mat[i][j] * m;
		}

	}

	return Ans;


}


void Mat::Inertia()
{

	for(int i=0;i < len;i++)
	{
		for(int j=0;j < wid;j++)
		{
			if(i == j)mat[i][j] = 1; 
		}
	}

;


}

Mat *Mat::inv()
{
	Mat *Ans = new Mat(len, wid);
	Mat *a = new Mat(len, wid);
	a->Copy(this);
	double buf;
	Ans->Inertia();
	for(int i=0;i < len;i++)
	{
		if(sqrt(a->mat[i][i]*a->mat[i][i]) < 10E-10)
		{
			
			for(int j=i+1;j < len;j++)
			{
				if(sqrt(a->mat[i][j]*a->mat[i][j]) > 10E-10)
				{
					
					
					double *tmp = new double[len];
					for(int k=0;k < len;k++)
					{
						tmp[k] = a->mat[k][j];
						a->mat[k][j] = a->mat[k][i];
						a->mat[k][i] = tmp[k];
					}
					delete tmp;
					j = len;
				}
			}
		}
		buf = 1 / a->mat[i][i];
		for(int j=0;j < wid;j++)
		{
			a->mat[j][i] *= buf;
			Ans->mat[j][i] *= buf;
		}
		for(int j=0;j < wid;j++)
		{
			if(i!=j)
			{
				buf = a->mat[i][j];
				for(int k=0;k < len;k++){
					a->mat[k][j] -= a->mat[k][i]*buf;
					Ans->mat[k][j] -= Ans->mat[k][i]*buf;
				}
			}


		}

	}
	delete a;

	return Ans;


}

Mat *Mat::pinv()
{
	Mat *Ans = new Mat(wid, len);
	Mat *TransJ = new Mat(wid, len);

	TransJ->Copy2(trans());
	
	Mat *temp = new Mat(wid, wid);

	temp->Copy2(dot(TransJ));

	temp->Copy2(temp->inv());

	Ans->Copy2(TransJ->dot(temp));

	delete TransJ;
	delete temp;

	
	return Ans;


}