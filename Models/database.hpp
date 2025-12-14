#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <libpq-fe.h>
#include <memory>
#include <stdexcept>

// using Singleton design pattern
class Database
{
public:
	PGconn* getPtrToConnection() { return m_connection; }

	static Database& instance()
	{
		static Database db;
		return db;
	}

	Database (const Database&) = delete;
	Database& operator=(const Database&) = delete;

	~Database() { PQfinish(m_connection); }

private:
	PGconn* m_connection;

	Database()
	{
		m_connection = PQconnectdb("host=localhost dbname=e_prescription_app user=postgres password=");
		
		if (PQstatus(m_connection) != CONNECTION_OK)
			throw std::runtime_error(PQerrorMessage(m_connection));
	}
};

#endif // DATABASE_HPP