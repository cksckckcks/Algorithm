#include <stdio.h>
#include <string.h>
// a = 97 z = 123

int main(){
  char arr[101];
  int arrN[26];
  
  for(int i = 0; i < 27; i++){
    arrN[i] = -1;
  }
  
  scanf("%s", arr);
  
  for(int i = 97; i < 124; i++){
  	for(int j = 0; j < strlen(arr); j++){
  	  if(arr[j] == i){
  	    arrN[i-97] = j;
  	    break;
  	  }
  	}
  }
	for(int i = 0; i < 26; i++){
	  printf("%d ", arrN[i]);
	}
}