// -*- C++ -*-
/*!
 * @file  OgreRTC.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "OgreRTC.h"
#include <fstream>
#include <windows.h>

OgreRTC *m_rtc;
using namespace std;

// Module specification
// <rtc-template block="module_spec">
static const char* OgreRTC_spec[] =
  {
    "implementation_id", "OgreRTC",
    "type_name",         "OgreRTC",
    "description",       "Ogre3D Component",
    "version",           "1.0.0",
    "vendor",            "Miyamoto Nobuhiko",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
OgreRTC::OgreRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager)

    // </rtc-template>
{
	
}

/*!
 * @brief destructor
 */
OgreRTC::~OgreRTC()
{
}



MyPortBase* OgreRTC::MyAddInPort(std::string n, std::string t)
{
	if(t == "RTC/TimedDouble")
	{
		return t_AddPort<TimedDouble>(n,t);
	}
	else if(t == "RTC/TimedLong")
	{
		return t_AddPort<TimedLong>(n,t);
	}
	else if(t == "RTC/TimedFloat")
	{
		return t_AddPort<TimedFloat>(n,t);
	}
	
	else if(t == "RTC/TimedShort")
	{
		return t_AddPort<TimedShort>(n,t);
	}
	
	else if(t == "RTC/TimedULong")
	{
		return t_AddPort<TimedULong>(n,t);
	}
	
	else if(t == "RTC/TimedUShort")
	{
		return t_AddPort<TimedUShort>(n,t);
	}
	else if(t == "RTC/TimedChar")
	{
		return t_AddPort<TimedChar>(n,t);
	}
	else if(t == "RTC/TimedBoolean")
	{
		return t_AddPort<TimedBoolean>(n,t);
	}
	else if(t == "RTC/TimedOctet")
	{
		return t_AddPort<TimedOctet>(n,t);
	}
	else if(t == "RTC/TimedString")
	{
		return t_AddPort<TimedString>(n,t);
	}
	
	else if(t == "RTC/TimedDoubleSeq")
	{
		return t_AddPort<TimedDoubleSeq>(n,t);
	}
	else if(t == "RTC/TimedLongSeq")
	{
		return t_AddPort<TimedLongSeq>(n,t);
	}
	else if(t == "RTC/TimedFloatSeq")
	{
		return t_AddPort<TimedFloatSeq>(n,t);
	}
	
	else if(t == "RTC/TimedShortSeq")
	{
		return t_AddPort<TimedShortSeq>(n,t);
	}
	
	else if(t == "RTC/TimedULongSeq")
	{
		return t_AddPort<TimedULongSeq>(n,t);
	}
	
	else if(t == "RTC/TimedUShortSeq")
	{
		return t_AddPort<TimedUShortSeq>(n,t);
	}
	else if(t == "RTC/TimedCharSeq")
	{
		return t_AddPort<TimedCharSeq>(n,t);
	}
	
	else if(t == "RTC/TimedBooleanSeq")
	{
		return t_AddPort<TimedBooleanSeq>(n,t);
	}
	else if(t == "RTC/TimedOctetSeq")
	{
		return t_AddPort<TimedOctetSeq>(n,t);
	}
	else if(t == "RTC/TimedStringSeq")
	{
		return t_AddPort<TimedStringSeq>(n,t);
	}
	return NULL;
	
}

MyPortBase* OgreRTC::QtAddInPort(std::string n, std::string t)
{
	MyPortBase* port = MyAddInPort(n, t);
	QtInPorts.push_back(port);

	return port;
}

void OgreRTC::QtAddInPort(MyPortBase *port)
{
	MyAddInPort(port->name, port->data_type);
}

MyPortBase* OgreRTC::GetPortByName(const char* name)
{
	for(int i=0;i < MyInPorts.size();i++)
	{
		if(MyInPorts[i]->name == name)
		{
			return MyInPorts[i];
		}
	}
	return NULL;
}

void OgreRTC::MyRemoveInPort(MyPortBase *port)
{
	port->inIn->disconnect_all();
	removePort(*(port->inIn));
	std::vector<MyPortBase*>::iterator end_it = remove( MyInPorts.begin(), MyInPorts.end(), port );
	MyInPorts.erase( end_it, MyInPorts.end() );

	

}

void OgreRTC::QtRemoveInPort(MyPortBase *port)
{
	

	MyRemoveInPort(port);

	std::vector<MyPortBase*>::iterator end_it = remove( QtInPorts.begin(), QtInPorts.end(), port );
	QtInPorts.erase( end_it, QtInPorts.end() );

	

}

void OgreRTC::RemoveAllPort()
{
	for(int i=0;i < MyInPorts.size();i++)
	{
		MyInPorts[i]->inIn->disconnect_all();
		removePort(*(MyInPorts[i]->inIn));
	}
	MyInPorts.clear();
}


RTC::ReturnCode_t OgreRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
	

	m_rtc = this;
  
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t OgreRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t OgreRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t OgreRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t OgreRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t OgreRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t OgreRTC::onExecute(RTC::UniqueId ec_id)
{
	for(int i = 0;i < MyInPorts.size();i++)
	{
		if(MyInPorts[i]->data_type == "RTC/TimedDouble")
		{
			MyInPorts[i]->SetData<TimedDouble, double>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedLong")
		{
			MyInPorts[i]->SetData<TimedLong, long>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedFloat")
		{
			MyInPorts[i]->SetData<TimedFloat, float>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedShort")
		{
			MyInPorts[i]->SetData<TimedShort, short>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedULong")
		{
			MyInPorts[i]->SetData<TimedULong, unsigned long>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedUShort")
		{
			MyInPorts[i]->SetData<TimedUShort, unsigned short>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedChar")
		{
			MyInPorts[i]->SetData<TimedChar, char>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedBoolean")
		{
			MyInPorts[i]->SetData<TimedBoolean, bool>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedOctet")
		{
			MyInPorts[i]->SetData<TimedOctet, char>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedString")
		{
			MyInPorts[i]->SetData<TimedString, char*>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedDoubleSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedDoubleSeq, double>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedLongSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedLongSeq, long>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedFloatSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedFloatSeq, float>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedShortSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedShortSeq, short>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedULongSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedULongSeq, unsigned long>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedUShortSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedUShortSeq, unsigned short>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedCharSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedCharSeq, char>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedBooleanSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedBooleanSeq, bool>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedOctetSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedOctetSeq, char>();
		}
		else if(MyInPorts[i]->data_type == "RTC/TimedStringSeq")
		{
			MyInPorts[i]->SetDataSeq<TimedStringSeq, char*>();
		}
		
		
		
		
		
		
	}


  return RTC::RTC_OK;
}

void OgreRTC::save(std::string s)
{
	std::ofstream ofs2(s.c_str(), ios_base::out | ios_base::trunc | ios_base::binary );
	if(!ofs2)return;

	int PortNum = QtInPorts.size();
	ofs2.write( (char*)&PortNum, sizeof(PortNum) );
	for(int i=0;i < PortNum;i++)
	{

		WriteString(QtInPorts[i]->name , ofs2 );
		WriteString(QtInPorts[i]->data_type , ofs2 );
		

	}
}
bool OgreRTC::openb(std::string s)
{
	std::ifstream ifs( s.c_str() , ios::in | ios::binary );
	if(!ifs)return false;

	newfile();

	int PortNum;
	ifs.read( (char*)&PortNum, sizeof(PortNum) );
	for(int i=0;i < PortNum;i++)
	{
		std::string p_name = ReadString(ifs);
		std::string data_type = ReadString(ifs);


		QtAddInPort(p_name, data_type);

			

		
	}

}
bool OgreRTC::newfile()
{
	RemoveAllPort();
	QtInPorts.clear();

	return true;
}
void OgreRTC::reset()
{
	RemoveAllPort();
	for(int i=0;i < QtInPorts.size();i++)
	{
		QtAddInPort(QtInPorts[i]);
	}
}

/*
RTC::ReturnCode_t OgreRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t OgreRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t OgreRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t OgreRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t OgreRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void OgreRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(OgreRTC_spec);
    manager->registerFactory(profile,
                             RTC::Create<OgreRTC>,
                             RTC::Delete<OgreRTC>);
  }
  
};


