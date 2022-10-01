#pragma once

template< typename T>
class CSingleton
{
protected:
	CSingleton() {};
	virtual ~CSingleton() {};

public:
	static T* GetInstance() // �����Ҵ��� �ʿ�� ����δ�.
	{
		static T instance;

		if (nullptr == m_pInstance)
		{
			//m_pInstance = new T;
		}

		return m_pInstance;
	}
private:
	static T* m_pInstance;
};

template <typename T> T* CSingleton<T>::m_pInstance = 0;
