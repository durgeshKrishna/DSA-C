#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int top=-1;
char s[50];
void push(char data){
	s[++top]=data;
}
char pop()
{
	return s[top--];
}
bool isempty(){
	return top==-1;
}
void main(){
int i,len;
char str[50];
printf("\nINPUT :");	
scanf("%s",str);
len=strlen(str);
printf("\nOUTPUT:");
for(i=0;i<len;i++){
	if(str[i]=='.')
	{
		while(!isempty()){
			printf("%c",pop());
		}
		printf(".");
		
	}
	else
	   push(str[i]);
	}	
    while(!isempty()){
    	printf("%c",pop());
    	
	}	
}
