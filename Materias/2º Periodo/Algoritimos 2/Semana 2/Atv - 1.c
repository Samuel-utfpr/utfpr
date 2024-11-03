#include <stdio.h>
#include <string.h>

int main(){
	char str[102];
	fgets(str, 102, stdin);
	int tam;
	
	tam=strlen(str);
	
	if (str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
        tam--;
	}
	  for(int i = tam-1; i>=0; i--){
        printf("%c", str[i]);
}

}

