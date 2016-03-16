#include <stdio.h>
int numberOfStacks = 3,N,visited[30];
int generate(int n,int stack[]){
    int i;
    if(n>=N+numberOfStacks-1){
        for(i=0;i<N+numberOfStacks-1;++i)printf("%d",stack[i]);
        printf("\n");
    }else{
        for(i=0;i<=N;++i){
            if(visited[i]){
                stack[n]=i;
                --visited[i];
                generate(n+1,stack);
                ++visited[i];
            }
        }
    }
}
int main(){
    printf("Enter a N: ");
    scanf("%d",&N);
    int i;
    visited[0]=numberOfStacks-1;
    for(i=1;i<=N;++i)visited[i]=1;
    int stack[N+numberOfStacks-1];
    generate(0,stack);
    return 0;
}