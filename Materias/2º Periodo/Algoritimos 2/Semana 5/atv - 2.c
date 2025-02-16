#include <stdio.h>
#include <string.h>

void* achar (void *p, char* frase){
  int inicio = *(int*)p;
  int fim = strlen(frase);
  int i;
  for(i=inicio; i<fim; i++){
    char c=*(frase+i);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    p = frase+i;
    return p;
  }
  }
  i--;
  p = frase+i;
  return p;
}