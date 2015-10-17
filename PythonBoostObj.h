/*!
 * @file  PythonBoostObj.h
 * @brief Python関連の操作をするためのクラス
 *
 */

#ifndef PythonBoostObj_H
#define PythonBoostObj_H

#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <boost/ref.hpp>
#include <iostream>
#include <coil/Task.h>
#include <coil/Mutex.h>

class PyObj;
class PBThread;


/**
 * @class PBThread
*@brief RTCを実行するスレッドのクラス
*/

class PBThread : public virtual coil::Task
{
public:
	/**
	*@brief コンストラクタ
	* @param fn ファイル名
	* @param p Python埋め込み管理クラス
	*/
	PBThread(std::string fn, PyObj *p);
	
	/**
	*@brief スレッド実行関数
	* @return 
	*/
	virtual int svc();
	std::string fname;
	PyObj *po;
	bool fin;
};



/**
 * @class PyObj
*@brief Python埋め込み管理クラス
*/

class PyObj
{
public:
	/**
	*@brief コンストラクタ
	*/
	PyObj();
	/**
	*@brief デストラクタ
	*/
	~PyObj();
	
	/**
	*@brief Pythonの関数実行の関数
	* @param fname 関数名
	*/
	void setFunc(const char *fname);
	
	/**
	*@brief Pythonのファイル実行の関数
	* @param fname ファイル名
	*/
	void Script(const char *fname);
	
	/**
	*@brief Pythonの関数オブジェクト取得の関数
	* @param fname 関数名
	*/
	boost::python::object getFunc(const char *fname);
	boost::python::object global_ns;
	boost::python::object obj;
	PBThread *mThread;
	bool Exec;
};





#endif
