#include<stdio.h>

int findMinCost(int arr[20][20],int n1);

int main(){


    int n, m, cost[20][20];

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            cost[i][j]=0;
        }
    }

    scanf(" %d",&n);
    scanf(" %d",&m);

    int i=0, j=0, k=0;
    for(int a=0; a<m; a++){
        scanf("%d %d %d", &i, &j, &k);
        cost[i][j]=k;
        cost[j][i]=k;
    }

    printf("MIN COST = %d",findMinCost(cost, n));
    return 0;
}



int findMinCost(int arr[20][20],int n1){
    int minCost=0, min=1000, keeper[10];

    for(int i=0; i<10; i++) keeper[i]=-1;

    for(int i=0; i<n1; i++){
        if(keeper[i]==0) continue;
        for(int j=0; j<n1; j++){
            if(arr[i][j]==0) continue;

            if(arr[i][j]<min){
                min=arr[i][j];
            }
        }
        for(int k=0; k<n1; k++){
            if(arr[i][k]==min){
                keeper[k]=0;
                minCost+=min;
                break;
            }
        }
    }

    return minCost;
}
