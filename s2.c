#include<stdio.h>

int findMinCost(int arr[20][20], int n);

int main(){


    int n, m, cost[20][20];

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            cost[i][j]=0;
        }
    }

    scanf(" %d",&n);
    scanf(" %d",&m);

    int p=0, q=0, r=0;
    for(int a=0; a<m; a++){
        scanf("%d %d %d", &p, &q, &r);
        cost[p][q]=r;
        cost[q][p]=r;
    }
    printf("***COST=%d***", findMinCost(cost, n));
    return 0;
}

int findMinCost(int arr[20][20], int n){
    int count=0, city=0, min=1000, minCost=0, visited[20];
    for(int q=0; q<n; q++) visited[q]=-1;
    while(count==n){
        visited[city]=0;
        for(int j=0; j<n; j++){
            if (arr[city][j]==0||visited[j]==0) continue;
            if (arr[city][j]<min){
                min=arr[city][j];
            }
        }
        
        for(int k=0; k<n; k++){
            if (arr[city][k]==min){
                count++;
                minCost+=min;
                city=k;
                min=1000;
            }
        }
        if(count==n-1){
            minCost+=arr[city][0];
            break;
        }
    }
    return minCost;

}

