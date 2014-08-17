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
*RTCを実行するスレッドのクラス
*/

class PBThread : public virtual coil::Task
{
public:
	PBThread(std::string fn, PyObj *p);
	/*
	*スレッド実行関数
	*/
	virtual int svc();
	std::string fname;
	PyObj *po;
	bool fin;
};


/*
*Python埋め込み管理クラス
*/

class PyObj
{
public:
	PyObj();
	~PyObj();
	/*
	*Pythonの関数実行の関数
	*/
	void setFunc(const char *fname);
	/*
	*Pythonのファイル実行の関数
	*/
	void Script(const char *fname);
	/*
	*Pythonの関数取得の関数
	*/
	boost::python::object getFunc(const char *fname);
	boost::python::object global_ns;
	boost::python::object obj;
	PBThread *mThread;
	bool Exec;
};





#endif
