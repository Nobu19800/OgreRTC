#ifndef MYARRAY_H
#define MYARRAY_H


#include <stdio.h>
#include <math.h>



double myabs(double a);



class Mat
{
private:

public:
	double **mat;
	int len, wid;
	Mat(int l, int w);
	~Mat();
	Mat *dot(Mat *M);
	void CreateI();
	void Copy(Mat *m);
	void Copy2(Mat *m);
	void add(Mat *m);
	void sub(Mat *m);
	void mult(double m);
	Mat *cross(Mat *m);
	Mat *trans();
	void Inertia();
	Mat *add2(Mat *m);
	Mat *sub2(Mat *m);
	Mat *mult2(double m);
	Mat *inv();
	Mat *pinv();



	

};




void GetP0Angle();

#endif