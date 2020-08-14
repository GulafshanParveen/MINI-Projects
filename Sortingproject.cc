#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdexcept>
#include <vector>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#define EXAMPLE_HOST "localhost";
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "password"
#define EXAMPLE_DB "test"

using namespace std;
using namespace sql;

void display(vector<vector<int>>);
void display(vector<vector<int>>graph){
        for(int i=0;i<graph.size();i++){
                for(int j=0;j<graph[i].size();j++){
                        cout<<graph[i][j]<<"\t";
                }
                cout<<endl;
        }
}

void SourceDes(int s,int d){
	const string url=EXAMPLE_HOST;
        const string user=EXAMPLE_USER;
        const string pass=EXAMPLE_PASS;
        const string database=EXAMPLE_DB;
	string s1,s2;
//	cin>>s1>>s2;
	getline(cin,s1);
	getline(cin,s2);
        Driver& driver = *get_driver_instance();
        Connection& con = *driver.connect(url,user,pass);
        con.setSchema(database);
        Statement& stmt=*con.createStatement();
	ResultSet& name=*stmt.executeQuery("select city_id from city_master where city_name='"+s1+"' ");
	ResultSet& id=*stmt.executeQuery("select city_id from city_master where city_name='"+s2+"' ");
	while(name.next()){
		s=name.getInt(1);
	}
	while(id.next()){
		d=id.getInt(1);
	}
		cout<<"city_id of "<<s1<<"="<<s<<endl;
		cout<<"city_id of "<<s2<<"="<<d<<endl;
}

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
	int s,d;
	SourceDes(s,d);
	ResultSet& rs=*stmt.executeQuery("select count(*)from city_master");
	ResultSet& graph=*stmt.executeQuery("select *from farelist");
	//ResultSet& cost=*stmt.executeQuery("select a.city_name,b.fare from city_master a left join farelist b on (a.city_id=b.city_id)");

	int l;
	if(rs.next()){
		l=rs.getInt(1);
		l++;
	}
	//cout<<"length="<<l<<endl;
	vector <vector<int>> g1(l,vector<int>(l,-1));
	for(int i=1;i<g1.size();i++)
		g1[i][i]=0;
		int r,c,value;
		while(graph.next()){
			r=graph.getInt(1);
			c=graph.getInt(2);
			value=graph.getInt(3);
			g1[r][c]=value;
		}
		display(g1);
	cout<<endl;
	cout<<endl;
	}catch(SQLException &e){
		cout<<"Error:"<<e.what()<<endl;
	}
	return 0;
}

