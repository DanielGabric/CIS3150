#include <stdio.h>
int A[100],B[100],C[100],atop=0,btop=0,ctop=0;

int TestStack(int x[],int top, int n){
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

int Pop(int x[],int *top){
    if((*top)==0){
        printf("Empty Stack Error!\n");
        return 0;
    }
    return x[(*top)--];
}

void Push(int x[], int *top, int v){
    x[++(*top)]=v;
}

int Move(int m){
    int element;
    if(m==1){
        element = Pop(A,&atop);
        if(!element)return 0;
        Push(B,&btop,element);
    }else if(m==2){
        element = Pop(A,&atop);
        if(!element)return 0;
        Push(C,&ctop,element);
    }else if(m==3){
        element = Pop(B,&btop);
        if(!element)return 0;
        Push(A,&atop,element);
    }else if(m==4){
        element = Pop(B,&btop);
        if(!element)return 0;
        Push(C,&ctop,element);
    }else if(m==5){
        element = Pop(C,&ctop);
        if(!element)return 0;
        Push(A,&atop,element);
    }else if(m==6){
        element = Pop(C,&ctop);
        if(!element)return 0;
        Push(B,&btop,element);
    }else{
        return 0;
    }
    return element;
}

int main(){
    Pop(A, &atop);
    Push(A, &atop, 5);
    Push(A, &atop, 4);
    Push(A, &atop, 1);
    Pop(A, &atop);
    Push(A, &atop, 3);
    Push(A, &atop, 2);
    Push(A, &atop, 1);
    if(TestStack(A,atop,5)) printf("The stack is sorted!\n");
    Move(1);
    Move(4);
    Move(5);
    if(TestStack(A,atop,5)) printf("The stack is sorted!\n");
    return 0;
}