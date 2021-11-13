#include "DataBaseConnect.h"
#include <fstream>

DataBaseConnect::DataBaseConnect()
{
    
}

bool DataBaseConnect::isUser(std::string username, std::string password)
{
    std::ifstream f("appconfig.txt");
    std::string connectionstring;
    std::getline(f, connectionstring);

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
    connectionobject.close();
}
void DataBaseConnect::newUSerRegisterCredentials(std::string username, std::string password)
{
    
        std::ifstream f("appconfig.txt");
        std::string connectionstring;
        std::getline(f, connectionstring);

        pqxx::connection connectionobject(connectionstring.c_str());

        pqxx::work worker(connectionobject);
                                                                                 
        std::string q3 = "INSERT INTO public.users(username, password) VALUES ('" + username + "','" + password + "');";
        worker.exec(q3);
        worker.commit();
        //connectionobject.close();

}

