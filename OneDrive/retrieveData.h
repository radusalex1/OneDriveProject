#pragma once
#include <pqxx/pqxx>

class retrieveData
{
public: 
	retrieveData()
	{

	}
	void getData()
	{
		std::string connectionString = "host=localhost port=5432 dbname=test user=postgres password =as";
		try
		{
			pqxx::connection connectionObject(connectionString.c_str());

			pqxx::work worker(connectionObject);

			pqxx::result response = worker.exec("SELECT * FROM users");

			for (size_t i = 0; i < response.size(); i++)
			{
				//std::cout << " id: " << response[i][0] << " name: " << response[i][1] << " surname: " << response[i][2] << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			//std::cerr << e.what() << std::endl;
		}
	}
};

