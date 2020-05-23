#include<stdio.h>
char a[9]={'1','2','3','4','5','6','7','8','9'};
void show();
void gamename();
void inpsymbol();
void start();
void play();
void check(char,char);
void gamename(){
	printf("\n\t\t\t  TIC TAC TOE GAME \n\n");
}
void show(){
	printf("\t\t\t----|----|----\n");
	printf("\t\t\t %c  | %c  | %c \n",a[0],a[1],a[2]);
	printf("\t\t\t----|----|----\n");
	printf("\t\t\t %c  | %c  | %c \n",a[3],a[4],a[5]);
	printf("\t\t\t----|----|----\n");
	printf("\t\t\t %c  | %c  | %c \n",a[6],a[7],a[8]);
	printf("\t\t\t----|----|----\n");
}
void inpsymbol(){
	printf("\n PLAYER 1 symbol : x ");
	printf("\n PLAYER 2 symbol : 0 ");
}
void start(){
	char pa;
	printf("\n ENTER WHO WILL START THE GAME PLAYER @1 OR PLAYER @2 : \n");
	scanf("%c",&pa);
}
void play(){
	char p,s;
	printf("ENTER POSITION AND SYMBOL FOR THE PLAYER : \n");
	scanf("%c",&p);
	while(getchar()!='\n');
	scanf("%c",&s);
	check(p,s);
}
void check(char P,char S){
	int i;
	for(i=0;i<=8;i++){
		if(a[i]==P){
			a[i]=S;
		}
	}
}
int main(){
	gamename();
	show();
	inpsymbol();
	start();
	play();
	show();
return 0;
}
