#include <stdio.h>

int main(){
    int a = 1==1;
    int b = (1==2) + 3;
    if((a<b)==1){
        printf("a<b\n");
    }
    else{
        printf("a>=b\n");
    }
    return 0;
}