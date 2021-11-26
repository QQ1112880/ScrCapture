#include "Lock.h"

namespace MyLock
{

//����һ�������������
CMutex::CMutex()
{
	InitializeCriticalSection(&m_crs);
}

//���ٻ�������ͷ���Դ
CMutex::~CMutex()
{
	DeleteCriticalSection(&m_crs);
}

//ȷ��ӵ�л��������̶߳Ա�������Դ�Ķ��Է���
void CMutex::Lock()
{
	EnterCriticalSection(&m_crs);
}

//�ͷŵ�ǰ�߳�ӵ�еĻ��������ʹ�����߳̿���ӵ�л�����󣬶Ա�������Դ���з���
void CMutex::Unlock()
{
	LeaveCriticalSection(&m_crs);
}

//����C++���ԣ������Զ�����
CMutexLocker::CMutexLocker(CMutex* pMutex) : m_pMutex(pMutex)
{
	m_pMutex->Lock();
}

//����C++���ԣ������Զ�����
CMutexLocker::~CMutexLocker()
{
	m_pMutex->Unlock();
}

}