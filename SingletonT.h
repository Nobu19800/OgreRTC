#ifndef SINGLETONT_H
#define SINGLETONT_H

template<typename T>
class SingletonT
{
public:
	virtual ~SingletonT() { 
	}

	static T* getSingletonPtr()
	{
		static T instance;
		return &instance;
	}

	static T& getSingleton() { return *getSingletonPtr(); }

protected:
	SingletonT(){}
	SingletonT& operator=(const SingletonT&);
};


#define SINGLETON_DEFINE(classname) friend class SingletonT<classname>;

#endif //SINGLETONT_H