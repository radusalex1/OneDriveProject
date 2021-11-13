#include "DataBaseConnect.h"

DataBaseConnect::DataBaseConnect()
{
    
}

bool DataBaseConnect::isUser(std::string username, std::string password)
{
    std::string connectionstring = "host=localhost port=5432 dbname=test user=postgres password =as";

    pqxx::connection connectionobject(connectionstring.c_str());

    pqxx::work worker(connectionobject);

    std::string q = "select * from users where username='" + username + "'" + "and password='" + password + "';"; /// nu am gasit alta metoda mai ok de a forma querryul

    pqxx::result result = worker.exec(q);
   
    if (result[0][0].is_null())
    {
        return false;
    }
    else
    {
        return true;
    }

}
