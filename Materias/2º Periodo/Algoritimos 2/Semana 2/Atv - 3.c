#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char str1[102] str2[102];
	scanf("%[ˆ\n]s", str1);
	scanf(" %[ˆ\n]s", str2);
	
	int igual = strlen(str1) == strlen(str2);
	if(igual){
	
		for(int i=0; igual>0 && str1[i] != '\0'; i++){
			igual = toupper(str1[i]) == toupper(str2[i]);
		}
	}
	if(igual){
		printf("As frases sao iguais");
	}
	else{
		printf("As frases sao diferentes");
	}
	
	




