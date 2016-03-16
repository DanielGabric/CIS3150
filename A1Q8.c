#include <stdio.h>
int TestStack(int x[],int top,int n){
    if(top != n)return 0;
    int i;
    /*Checks if a stack is sorted in*/
    /*ascending order from the top*/
    for(i=1;i<=n;++i){
        if(x[i]!=n-i+1){
            return 0;
        }
    }
    return 1;
}

int Pop(int x[], int *top){
    if((*top)==0){
        printf("Empty Stack Error!");
        return -1;
    }
    return x[(*top)--];
}

void Push(int x[],int *top,int v){
    x[++(*top)]=v;
}

int main(){
    int atop=0, a[100];
    Push(a,&atop,5);
    Push(a,&atop,4);
    Push(a,&atop,1);
    Pop(a, &atop);
    Push(a,&atop,3);
    Push(a,&atop,2);
    Push(a,&atop,1);
    if(TestStack(a,atop,5))printf("The stack is sorted!\n");
    return 0;
}