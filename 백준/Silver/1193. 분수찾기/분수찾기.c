#include<stdio.h>

int main(){
  int X, i;
  int n = 1;
  
  //1 2 4 7 
  
  scanf("%d", &X);
  
  if(X == 1){
    printf("1/1");
    return 0;
  }
  
  for(i = 1; i < X; i += n++){
   }
  
  if(i > X){
    i -= --n;
  }
  
  if(n % 2 == 0){
    printf("%d/%d", 1 + (X - i), n - (X - i));
  }
  else{
    printf("%d/%d", n - ( X - i), 1 + (X - i));
  }
  
}