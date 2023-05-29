#pragma once
#include <sql.h>
#include <sqlext.h>

class CQueryBuilder;
class CDBConnection
{
public:
	CDBConnection();
	~CDBConnection();

public:
	bool Connect();
	void DisConnect();

public:
	bool SendQuery(CQueryBuilder& query);

private:
	SQLHENV m_EnvHandle;
	SQLHDBC m_DBHandle;

};

