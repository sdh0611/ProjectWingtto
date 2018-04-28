#pragma once
#include "../pch.h"


//Singleton ���� ��ũ��. Singleton Template�� 
//��ӹ��� class�� friend�� ��������.
#define DECLARE_SINGLETON(CLASS) \
		friend class Singleton<CLASS>;\
		private:\
			CLASS();\
			CLASS(const CLASS&);\
			~CLASS();


//Singleton Ŭ�������� �����ϱ� ���� Singleton Template
template <class T>
class Singleton {
public:
	static T* GetInstance() {
		if (mInstance == nullptr)
			mInstance = new T;

		return mInstance;
	}
	static void Destroy() {
		if (mInstance != nullptr) {
			delete mInstance;
			mInstance = nullptr;
		}
	}


protected:
	Singleton() { };
	virtual ~Singleton() { };


private:
	static T* mInstance;
	
};

template <class T> T* Singleton<T>::mInstance = nullptr;