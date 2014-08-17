// -*- C++ -*-
/*!
 * @file  Test1.h
 * @brief ModuleDescription
 * @date  $Date$
 *
 * $Id$
 */

#ifndef OGRERTC_H
#define OGRERTC_H

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

#include <sstream>
#include <vector>

#include "MyFileStream.h"

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

using namespace RTC;

/*!
 * @class Test1
 * @brief ModuleDescription
 *
 */

class MyPortBase
{
public:
	virtual ~MyPortBase()
	{

	}
	std::string name;
	std::string data_type;
	PortBase *inIn;
	

	std::vector<std::string> data;

	coil::Mutex mu;

	void startGetData()
	{
		mu.lock();
	}

	void FinishGetData()
	{
		mu.unlock();
	}
	

	const char *getDataType()
	{
		return data_type.c_str();
	}

	int length()
	{
		return data.size();
	}
	template <typename T>T GetData(int num)
	{
		T ans;
		std::stringstream ss(data[num]);
		ss.read((char *)&ans,sizeof(ans));

		return ans;
	}
	char GetData_char(int num)
	{
		return GetData<char>(num);
	}
	char* GetData_str(int num)
	{
		return const_cast<char*>(data[num].c_str());
	}
	float GetData_float(int num)
	{
		return GetData<float>(num);
	}
	
	double GetData_double(int num)
	{
		return GetData<double>(num);
	}
	
	long GetData_long(int num)
	{
		return GetData<long>(num);
	}
	unsigned long GetData_Ulong(int num)
	{
		return GetData<unsigned long>(num);
	}
	short GetData_short(int num)
	{
		return GetData<short>(num);
	}
	unsigned short GetData_Ushort(int num)
	{
		return GetData<unsigned short>(num);
	}
	bool GetData_bool(int num)
	{
		return GetData<bool>(num);
	}

	template <typename T, typename X>void SetDataSeq()
	{
		mu.lock();
		MyInPort<T> *p = dynamic_cast<MyInPort<T>*>( this );
		if(p != NULL)
		{
			InPort<T>* s = dynamic_cast<InPort<T>*>(p->inIn);
			if(s != NULL)
			{
				if(s->isNew())
				{
					s->read();
					p->data.clear();
					
					
					for(int j=0;j < p->In->data.length();j++)
					{
						X tmp = p->In->data[j];
						std::stringstream ss("");
						ss.write((char *)&tmp,sizeof(tmp));
						p->data.push_back(ss.str());
					}
					
				}
			}
		}
		mu.unlock();
	 }


	 template <typename T, typename X>void SetData()
	 {
		mu.lock();
		MyInPort<T> *p = dynamic_cast<MyInPort<T>*>( this );
		if(p != NULL)
		{
			InPort<T>* s = dynamic_cast<InPort<T>*>(p->inIn);
			if(s != NULL)
			{
				if(s->isNew())
				{
					s->read();
					p->data.clear();
					
					X tmp = p->In->data;
					std::stringstream ss("");
					ss.write((char *)&tmp,sizeof(tmp));
					p->data.push_back(ss.str());
					
					
				}
				
				//p->data.push_back((char *)&tmp);
			}
		}
		mu.unlock();
	 }
	
};

template <class T>
class MyInPort : public MyPortBase
{
public:
	MyInPort(T *id, RTC::InPort<T> *ip, std::string n, std::string dt){
		In = id;
		inIn = ip;
		name = n;
		data_type = dt;
		
	}
	T *In;
	
	
};

class OgreRTC
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  OgreRTC(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~OgreRTC();

  std::vector<MyPortBase*> MyInPorts;
  std::vector<MyPortBase*> QtInPorts;


  

  template <typename T>MyPortBase* t_AddPort(std::string n, std::string dt)
 {
	 T *in = new T;
	 InPort<T> *inIn = new InPort<T>(n.c_str(),*(in));
	 addInPort(n.c_str(), *(inIn));
	MyInPort<T> *port = new MyInPort<T>(in, inIn, n, dt);
	MyInPorts.push_back(port);

	return port;
 }
  MyPortBase* GetPortByName(const char* name);

 
  
 MyPortBase* MyAddInPort(std::string n, std::string t);
 MyPortBase* QtAddInPort(std::string n, std::string t);
 void QtAddInPort(MyPortBase *port);
 void MyRemoveInPort(MyPortBase *port);
 void QtRemoveInPort(MyPortBase *port);
 void RemoveAllPort();

 void save(std::string s);
 bool openb(std::string s);
 bool newfile();
 void reset();

 

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
 
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
 

  
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};




extern "C"
{
  DLL_EXPORT void OgreRTCInit(RTC::Manager* manager);
};

#endif // TEST1_H
