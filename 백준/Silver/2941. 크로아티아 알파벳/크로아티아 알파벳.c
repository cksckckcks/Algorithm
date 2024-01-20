#include<stdio.h>
#include<string.h>

int main(){
  char arr[101];
  
  scanf("%s", arr);
  
  int len = strlen(arr);
  int count = strlen(arr);
 
  for(int i = 0; i < len ; i++){
    if(arr[i] == '=' || arr[i] == '-'){
      count--;
    }
    if(arr[i] == 'd' && arr[i+1] == 'z' && arr[i+2] == '='){
      count--;
    }
    if((arr[i] == 'l' || arr[i] == 'n') && arr[i+1] == 'j'){
      count--;
    }
  }
  printf("%d", count);
  }