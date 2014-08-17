#ifndef MYPYTHONBOOST_H
#define MYPYTHONBOOST_H

#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <boost/ref.hpp>
#include <iostream>
#include <coil/Task.h>
#include <coil/Mutex.h>

class PyObj;
class PBThread;

/*
*RTC�����s����X���b�h�̃N���X
*/

class PBThread : public virtual coil::Task
{
public:
	PBThread(std::string fn, PyObj *p);
	/*
	*�X���b�h���s�֐�
	*/
	virtual int svc();
	std::string fname;
	PyObj *po;
	bool fin;
};


/*
*Python���ߍ��݊Ǘ��N���X
*/

class PyObj
{
public:
	PyObj();
	~PyObj();
	/*
	*Python�̊֐����s�̊֐�
	*/
	void setFunc(const char *fname);
	/*
	*Python�̃t�@�C�����s�̊֐�
	*/
	void Script(const char *fname);
	/*
	*Python�̊֐��擾�̊֐�
	*/
	boost::python::object getFunc(const char *fname);
	boost::python::object global_ns;
	boost::python::object obj;
	PBThread *mThread;
	bool Exec;
};





#endif
