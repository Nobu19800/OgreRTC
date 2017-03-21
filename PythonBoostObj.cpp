/*!
 * @file  PythonBoostObj.cpp
 * @brief Python関連の操作をするためのクラス
 *
 */

#include "PythonBoostObj.h"

namespace bpy = boost::python;



/**
*@brief RTCを実行するスレッドのクラスのコンストラクタ
* @param fn ファイル名
* @param p Python埋め込み管理クラス
*/
PBThread::PBThread(std::string fn, PyObj *p)
{
	fname = fn;
	po = p;
	fin = false;
}


/**
*@brief スレッド実行関数
* @return 
*/
int PBThread::svc()
{
	
	//PyGILState_STATE gilstate;

    
	

	bpy::object test2 = po->global_ns["RTCStart"];

	
	
	//gilstate = PyGILState_Ensure();
	try
	{
		test2(fname.c_str());
	}
	
	catch (const bpy::error_already_set&)
	{
		PyErr_Print();
	}
	catch (...)
	{

	}
	//PyGILState_Release(gilstate);

	fin = true;
		
	return 0;
}




/**
*@brief Python埋め込み管理クラスのコンストラクタ
*/
PyObj::PyObj()
{
  Exec = false;

  

  
  Py_Initialize();
  //PyEval_InitThreads();

  /*PyThreadState *py_tstate = NULL;
  PyEval_InitThreads();

  py_tstate = PyGILState_GetThisThreadState();
  PyEval_ReleaseThread(py_tstate);*/
 
 
  global_ns = bpy::import("__main__").attr("__dict__");

  bpy::exec
    (
      "from CppExport import *\n"
      , global_ns , global_ns
    );
	


}


/**
*@brief Python埋め込み管理クラスのデストラクタ
*/
PyObj::~PyObj()
{
	//PyGILState_Ensure();
	Py_Finalize();
}

/**
*@brief Pythonのファイル実行の関数
* @param fname ファイル名
*/
void PyObj::Script(const char *fname)
{
	try
	{
		obj = bpy::exec_file
			(
			fname, global_ns, global_ns
			);
	}
	catch (...)
	{

	}
	
}


/**
*@brief Pythonの関数オブジェクト取得の関数
* @param fname 関数名
*/
bpy::object PyObj::getFunc(const char *fname)
{
	return global_ns[fname];
}


/**
*@brief Pythonの関数実行の関数
* @param fname 関数名
*/
void PyObj::setFunc(const char *fname)
{
	PyGILState_STATE gilstate;
   
	gilstate = PyGILState_Ensure();
	bpy::object pfunc = getFunc(fname);
	try
	{
		


		
		pfunc();

		

		
	}
	catch(const bpy::error_already_set&)
	{
		PyErr_Print();
	}
	catch (...)
	{
		
	}
	PyGILState_Release(gilstate);
}