#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
using namespace std;
int main(){
	ifstream ifs("data.json");
	json::Reader reader;
	json::Value obj;
	reader.parse(ifs,obj);
	cout<<"lastname: "<<obj["lastname"].asString()<<endl;
	cout<<"firstname: "<<obj["firstname"].asString()<<endl;
	return 0;
}
