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
using namespace Json;

int main(int argc,char *argv[]){
	if(argc!=2){
		cout<<"JSON file missing"<<endl;
		return 0;
	}
	ifstream ifs(argv[1]);

        Reader reader;
        Value obj;
        Reader creader;
        Value cobj;
	//ifstream ifs(argv[1]);
        reader.parse(ifs,obj);
        ifstream cifs("credentials.json");
        creader.parse(cifs,cobj);

        const string url=cobj["url"].asString();//=EXAMPLE_HOST;
        const string user=cobj["username"].asString();//=EXAMPLE_USER;
        const string pass=cobj["password"].asString();//=EXAMPLE_PASS;
        const string database=cobj["database"].asString();//=EXAMPLE_DB;

        try{
        Driver& driver = *get_driver_instance();
        Connection& con = *driver.connect(url,user,pass);
        con.setSchema(database);
        Statement& stmt=*con.createStatement();

	//ifstream ifs("data.json");

	Value::Members v=obj.getMemberNames();
	for(Value::Members::iterator iter1=v.begin(); iter1!=v.end(); iter1++){
	/*for(auto l1 : obj.getMemberNames()){
		string s1 = l1;
		for(auto l2 : obj[s1].getMemberNames()){
			string s2 = l2;
			string s3 = obj[s1][s2].asString();*/
		string s1 = *iter1;
		Value::Members v1=obj[s1].getMemberNames();
		for(Value::Members::iterator iter2=v1.begin(); iter2!=v1.end(); iter2++){
			string s2 = *iter2;
			string s3 = obj[s1][s2].asString();
	stmt.execute("INSERT INTO farelist VALUES( (SELECT city_id FROM city_master WHERE (city_name = '"+s1+"')),(SELECT city_id FROM city_master WHERE(city_name = '"+s2+"')),'"+s3+"' )");
			}
		}
        }catch(SQLException &e){
                cout<<"Error:"<<e.what()<<endl;
        }
	return 0;
}
