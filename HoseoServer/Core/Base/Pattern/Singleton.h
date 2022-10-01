#pragma once

template< typename T>
class CSingleton
{
protected:
	CSingleton() {};
	virtual ~CSingleton() {};

public:
	static T* GetInstance() // 동적할당할 필요는 없어보인다.
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
