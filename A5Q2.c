#include <stdio.h>
#define MAX(a,b) (a>b)?(a):(b)
int N = 8;
int I=0;
int growth[20];
int m[6][14]={{1,2,3,4,5,14,16,17,31},
              {1,2,3,4,5,6,7,8,9},
              {1,2,3,4,5,6,7,8,9,10},
              {1,1,2,2,3,3,4,4,5,5,6,6,7,7},
              {25,27,3,2,15,9,30,21,19,56},
              {59,25,27,3,2,15,9,30,21,19}};
int len[6]= {9,9,10,14,10,10};
long long int c=0;
void generate(int n, int max){
    int i,j,sums[4]={0,m[I][0],0,0};
    if(n >= N){
        for(j=1;j<N;++j)
            sums[growth[j]]+=m[I][j];
        if(sums[1]==sums[2] && sums[2]==sums[3]){
            printf("1");
            for(j=1;j<N;++j)
                printf("%d",growth[j]);
            printf("\n");
        }
    }else{
        for(i=1;i<=3;++i){
            if(i > 1+max)break;
            growth[n]=i;
            generate(n+1,MAX(max,i));
        }
    }
}

int main(){
    int i,j;
    for(i=0;i<6;++i){
        I = i;
        N = len[i];
        printf("{");
        for(j=0;j<N;++j)
            printf("%d, ",m[i][j]);
        printf("}\n");
        generate(1,1);
    }
    return 0;
} 