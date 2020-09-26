#include <iostream>
#include <string>
using namespace std;

int main(){
	char inp,y,n,Y,N;
	string name,gtkey;
	string sentence;
	string question[6];
	int age;

	cout<<"\t\t WELCOME TO CHATBOT\n\n";
	cout<<"To continue the program type 'Y' and to end 'N' - \n";
	cout<<"-->";
	cin>>inp;

		if(inp == 'y' || inp == 'Y'){ 	//if yes
			cout<<"\n WELCOME..... \n";
		}else{
			cout<<"\n Thanks for coming\n";				//if no
			return 0;
		}
	system("clear");

	if(gtkey !="bi"){
		cout<<"\t HELLO USER \n ";
		cout<<"-->";
		cin>>gtkey;

		cout<<"\n What is your name...?\n";
		cout<<"-->";
		cin>>name;

		cout<<"\n";
		cout<<name<<" how are you..?\n";
		cout<<"-->";
		cin>>gtkey;

		cout<<"\n";
		cout<<name<<" what is your age...?\n";
		cout<<"-->";
		cin>>age;

			switch(age>=18 && age <=35){
				case 1: cout<<"\nYou are Young and Smart\n";
					break;
				case 0: cout<<"\nYou are Old but Sweet\n";
					break;
				default : cout<< "\nnothing say about your age\n";
			}
		}

		cout<<"\n How's your day "<<name<<"\n";
		cin>>gtkey;

		question[0] = "what is your name";
		question[1] = "do you like computer programming";
		question[2] = "how is the weather today";
		question[3] =  "tell me a joke";
		question[4] = "i am feeling tired";
		question[5] = "what you know about engineering";

		//string answer[5] ={"My name is talking chatbot","Ofcourse, am loving it!","It's rainy","Sorry dear, I am a chatbot , not a joker","You should better get some sleep","Engineering is the application of mathematics, science, and practical knowledge to invest and design machines"};

		do{
			cout<<"Ask me anything!!:"<<endl;
			getline(cin,sentence);

			if(sentence.find("how")!=string::npos || sentence.find("what")!=string::npos || sentence.find("do")!=string::npos){
				cout<<"----> ";
			}
			int len=sentence.size();
			if(len>25){
				cout<<"You asking lengthy question"<<endl;
			}
			if(sentence == question[0]){
				cout<<"My name is talking bot\n";
			}else if(sentence == question[1]){
				cout<<"Ofcourse, am loving it!\n";
			}else if(sentence == question[2]){
				cout<<"It's raining\n";
			}else if(sentence == question[3]){
				cout<<"Sorry dear, I am a chatbot , not a joker\n";			}else if(sentence == question[4]){
				cout<<"You should better get some sleep\n";
			}else if(sentence == question[5]){
				cout<<"Engineering is the application of mathematics, science, and practical knowledge to invest and design and machines\n";
			}else{
				cout<<"Invalid data\n";
			}

			cout<<"************************************************************\n";
			cout<<"Enter exit\n";
			cout<<"....................\n\n";
		}while(sentence!="exit");

		cout<< "\n bye bye..."<<name<<"\n";
		cout<<"-->";
		cin>>gtkey;

	system("clear");
	cout<<"\t\t\t CHAT END HERE.....\n";
	return 0;
}
