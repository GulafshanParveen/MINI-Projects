#include <iostream>
using namespace std;
int graph[8][8]={{-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,0,-1,-1,-1,-1,-1,-1},
		{-1,-1,0,-1,300,800,150,-1},
		{-1,-1,-1,0,500,-1,-1,250},
		{-1,240,300,500,0,-1,150,-1},
		{-1,-1,-1,-1,-1,0,-1,-1},
		{-1,-1,-1,-1,-1,-1,0,-1},
		{-1,200,700,250,-1,-1,-1,0}};

int getMin(int a,int b){
	return a<b?a:b;
}

int minFare(int graph[8][8],int source,int destination){
	if(source==destination)return graph[source][source];
	if(source==1)return minFare(graph,source,destination-1)+graph[1][destination];
	if(destination==1)return minFare(graph,destination-1,source)+graph[destination][1];
	int x,y;
	if(graph[source][destination-1]!=1){
		x=minFare(graph,source+1,destination-1);
	}
	if(graph[source+1])
}


/*int minfare(int graph[8][8],int source,int destination,int row,int col){
	int cost[8];
	cost[source]=0;
	cost[source+1]=graph[source][source+1];
	for(int i=source+2;i<row;i++){
		cost[i]=graph[source+1][i];
		for(int j=source+1;j<i;j++){
			if(graph[i][j]!=-1 && cost[i]>cost[j]+graph[i][j]){
				cost[i]=cost[j]+graph[i][j];
			}
		}
	}
	return cost[destination];//-cost[source];
}*/

int main(int argc,char* argv[]){
	int fare=minfare(graph,2,1,8,8);
	cout<<"Minimum fare is: "<<fare<<endl;
	return 0;
}
