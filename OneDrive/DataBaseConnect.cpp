#include "DataBaseConnect.h"
#include <fstream>

DataBaseConnect::DataBaseConnect()
{
    
}

bool DataBaseConnect::isUser(const std::string & username, const std::string & password)
{
    std::ifstream f("appconfig.txt");
    std::string connectionstring;
    std::getline(f, connectionstring);

    pqxx::connection connectionobject(connectionstring.c_str());

    pqxx::work worker(connectionobject);

    std::string q = "select * from users where username='" + username + "';";

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
void DataBaseConnect::newUSerRegisterCredentials(const std::string & username, const std::string & password, const std::string & path)
{
    
        std::ifstream f("appconfig.txt");
        std::string connectionstring;
        std::getline(f, connectionstring);

        pqxx::connection connectionobject(connectionstring.c_str());

        pqxx::work worker(connectionobject);
                                                                                 
        std::string q3 = "INSERT INTO public.users(username, password, path) VALUES ('" + username + "','" + password + "','" + path + "');";
        worker.exec(q3);
        worker.commit();

}

std::string DataBaseConnect::GetUserPath(const std::string &username)
{
    std::ifstream f("appconfig.txt");
    std::string connectionstring;
    std::getline(f, connectionstring);

    pqxx::connection connectionobject(connectionstring.c_str());

    pqxx::work worker(connectionobject);

    std::string q = "select * from users where username='" + username + "';"; /// nu am gasit alta metoda mai ok de a forma querryul

    pqxx::result result = worker.exec(q);

    return result[0][3].c_str();
}

