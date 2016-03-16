#include <stdio.h>
#include <stdlib.h>
int algorithm[16];
int check[3]={12,60,360};
int m[16][7]={{},
              {2,1,2},
              {2,3,4},
              {2,5,6},
              {4,3,4,5,6},
              {4,3,4,5,6},
              {4,1,2,5,6},
              {4,1,2,5,6},
              {4,1,2,3,4},
              {4,1,2,3,4},
              {6,1,2,3,4,5,6},
              {6,1,2,3,4,5,6},
              {6,1,2,3,4,5,6},
              {6,1,2,3,4,5,6},
              {6,1,2,3,4,5,6},
              {6,1,2,3,4,5,6}};
int configurations[360][6];
int counter=0;
int A[100],B[100],C[100],atop=0,btop=0,ctop=0,counter1=0;
int totCounter=0;
int N;

void Push(int x[], int *top, int v){
    x[++(*top)]=v;
}

void InitializeStacks(int config[]){
    int i;
    int numStack=0;
    btop=0;
    ctop=0;
    atop=0;
    for(i=0;i<N;++i){
        if(numStack==0){
            if(config[i]==0){
                numStack++;
            }else{
                Push(A,&atop,config[i]);
            }
        }else if(numStack == 1){
            if(config[i]==0){
                numStack++;
            }else{
                Push(B,&btop,config[i]);
            }
        }else{
            Push(C,&ctop,config[i]);
        }
    }
}

void RunAlgorithm(int algo[16]){
    if(btop==0 && ctop==0){
        Move(algo[1]);
    }else if(atop == 0 && ctop==0){
        Move(algo[2]);
    }else if(atop == 0 && btop == 0){
        Move(algo[3]);
    }else if(atop == 0 && B[btop] < C[ctop]){
        Move(algo[4]);
    }else if(atop == 0 && B[btop] > C[ctop]){
        Move(algo[5]);
    }else if(btop == 0 && A[atop] < C[ctop]){
        Move(algo[6]);
    }else if(btop == 0 && A[atop] > C[ctop]){
        Move(algo[7]);
    }else if(ctop == 0 && A[atop] < B[btop]){
        Move(algo[8]);
    }else if(ctop == 0 && A[atop] > B[btop]){
        Move(algo[9]);
    }else if(A[atop] < B[btop] && B[btop] < C[ctop]){
        Move(algo[10]);
    }else if(A[atop] < C[ctop] && B[btop] > C[ctop]){
        Move(algo[11]);
    }else if(A[atop] > B[btop] && A[atop] < C[ctop]){
        Move(algo[12]);
    }else if(A[atop] > C[ctop] && C[ctop] > B[btop]){
        Move(algo[13]);
    }else if(C[ctop] < A[atop] && A[atop] < B[btop]){
        Move(algo[14]);
    }else if(C[ctop] < B[btop] && B[btop] < A[atop]){
        Move(algo[15]);
    }
}

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

void PrintStack(int x[],int top){
    int i;
    for(i=top;i>=1;--i) printf("%d\n",x[i]);
}

int Pop(int x[],int *top){
    if((*top)==0){
        printf("Empty Stack Error!\n");
        return 0;
    }
    return x[(*top)--];
}

int Move(int m) {
    int v;
    
    if (m == 1 || m == 2) v = Pop(A,&atop);
    if (m == 3 || m == 4) v = Pop(B,&btop);
    if (m == 5 || m == 6) v = Pop(C,&ctop);
    
    if (v == 0) { printf("Error: move from empty stack\n"); return 0; }
    
    if (m == 3 || m == 5) Push(A,&atop,v);
    if (m == 1 || m == 6) Push(B,&btop,v);
    if (m == 2 || m == 4) Push(C,&ctop,v);
    return 1;
}

int generate(int n){
    int i,start,end,k,j;
    if(n>15){
        int a[N],j,firstFlag = 0;
        a[0]=a[1]=0;
        for(i=2;i<N;++i)
            a[i]=i-1;
        for(j=0;j<check[N-4];++j){
            int counter =0;
            InitializeStacks(configurations[j]);
            int flag = 0;
            while(counter <= check[N-4]){
                if(TestStack(A,atop,N-2)){
                    flag = 1;
                    break;
                }
                RunAlgorithm(algorithm);
                counter++;
            }
            if(!flag){
              firstFlag = 1;
              break;
            }
        }
        if(!firstFlag)
            counter1++;
        totCounter++;
    }else{
        for(i=1;i<=m[n][0];++i){
            algorithm[n]=m[n][i];
            generate(n+1);
        }
    }
}

int stack[10];
int visited[30];
void generate1(int n){
    int i,j;
    if(n>=N){
        for(j=0;j<N;++j)configurations[counter][j]=stack[j];
        counter++;
    }else{

        for(i=0;i<=N-2;++i){
            if(visited[i]){
                stack[n]=i;
                --visited[i];
                generate1(n+1);
                ++visited[i];
            }
        }
    }
}

int main(){
    int i;
    N = 4+2;
    visited[0]=2;
    for(i=1;i<=N;++i)visited[i]=1;
    generate1(0);
    generate(1);
    printf("%d\n",counter1);
    return 0;
}