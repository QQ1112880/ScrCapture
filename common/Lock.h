#ifndef LOCK_H
#define LOCK_H

#include <windows.h>

namespace MyLock
{

//�����������
class CMutex
{
public:
	CMutex();
	~CMutex();

	virtual void Lock();
	virtual void Unlock();

private:
	CRITICAL_SECTION m_crs;
};

//��
class CMutexLocker
{
public:
	CMutexLocker(CMutex* m_pMutex);
	~CMutexLocker();

private:
	CMutex* m_pMutex;
};


}

#endif