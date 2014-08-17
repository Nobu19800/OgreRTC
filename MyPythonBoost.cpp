#include "MyPythonBoost.h"

namespace bpy = boost::python;

PBThread::PBThread(std::string fn, PyObj *p)
{
	fname = fn;
	po = p;
	fin = false;
}

int PBThread::svc()
{
	
	//PyGILState_STATE gilstate;

    
	

	bpy::object test2 = po->global_ns["RTCStart"];

	
	
	//gilstate = PyGILState_Ensure();
	
	test2(fname.c_str());
	

	//PyGILState_Release(gilstate);

	fin = true;
		
	return 0;
}


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

PyObj::~PyObj()
{
	//PyGILState_Ensure();
	Py_Finalize();
}


void PyObj::Script(const char *fname)
{
	
	obj = bpy::exec_file
		(
			fname, global_ns , global_ns
		);
	
}

bpy::object PyObj::getFunc(const char *fname)
{
	return global_ns[fname];
}

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
	PyGILState_Release(gilstate);
}