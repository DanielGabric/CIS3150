#include <stdio.h>
int main(){
    int transition[5][2]={{2,1},{2,3},{4,1},{2,5},{5,5}};
    int currentState = 1;
    int acceptState = 5;
    char input = getchar();
    while(input=='a'||input=='b'){
        /*Changing current state according 
          to input and last state*/
        currentState=transition[currentState-1][input-'a'];
        input = getchar();
    }
    /*Checks if we are currently in the accept state*/
    if(currentState==acceptState){
        printf("The string belongs to L\n");
    }else{
        printf("The string does not belong to L\n");
    }
    return 0;
}