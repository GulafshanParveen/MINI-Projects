#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <jsoncpp/json/json.h>
#define EXAMPLE_HOST "localhost";
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "password"
#define EXAMPLE_DB "test"

using namespace std;
using namespace sql;

int main(int argc,char *argv[]){
        const string url=EXAMPLE_HOST;
        const string user=EXAMPLE_USER;
        const string pass=EXAMPLE_PASS;
        const string database=EXAMPLE_DB;
        try{
        Driver& driver = *get_driver_instance();
        Connection& con = *driver.connect(url,user,pass);
        con.setSchema(database);
        Statement& stmt=*con.createStatement();
        ifstream ifs("data.json");
        Json::Reader reader;
        Json::Value obj;
        reader.parse(ifs,obj);
	stmt.execute("insert into project_table(firstname,lastname,ss) values ('"+ob<('"+obj["firstname"].asString()+"','"+obj["lastname"].asString()+"','"+obj["ss"].as>
        }catch(SQLException &e){
                cout<<"Error:"<<e.what()<<endl;
        }
        return 0;
}

