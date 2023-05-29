#include "DBConnection.h"

namespace
{
	void DisplayError(SQLHANDLE handle, SQLSMALLINT handleType, SQLRETURN retCode) {
		SQLCHAR sqlState[6];
		SQLINTEGER nativeError;
		SQLCHAR message[SQL_MAX_MESSAGE_LENGTH];
		SQLSMALLINT messageLength;

		//if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, sqlState, &nativeError, message, sizeof(message), &messageLength)) 
		//{
		//}
	}
}

CDBConnection::CDBConnection()
{
}

CDBConnection::~CDBConnection()
{
	DisConnect();
}

bool CDBConnection::Connect()
{
	SQLRETURN result = SQL_SUCCESS;

	do
	{
		result = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_EnvHandle);
		if (result != SQL_SUCCESS)
		{
			break;
		}

		result = SQLSetEnvAttr(m_EnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3);
		if (result != SQL_SUCCESS)
		{
			break;
		}
		// 데이터베이스 연결 핸들 초기화
		result = SQLAllocHandle(SQL_HANDLE_DBC, m_EnvHandle, &m_DBHandle);
		if (result != SQL_SUCCESS)
		{
			break;
		}

		result = SQLConnectA(m_DBHandle, serverName, SQL_NTS, userName, SQL_NTS, password, SQL_NTS);
		if (result != SQL_SUCCESS && result != SQL_SUCCESS_WITH_INFO) {
			DisplayError(m_DBHandle, SQL_HANDLE_DBC, result);
			return 1;
		}

	} while (false);

	return result == SQL_SUCCESS;
}

void CDBConnection::DisConnect()
{
	SQLDisconnect(m_DBHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, m_DBHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, m_EnvHandle);
}

bool CDBConnection::SendQuery(CQueryBuilder& query)
{
	return false;
}
