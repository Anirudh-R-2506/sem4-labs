#include <stdio.h>

#define INF 16777216
#define NV 4

void printMatrix(int dist[][NV]){
    for (int i = 0; i < NV; i++) {
        for (int j = 0; j < NV; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floyd(int dist[][NV]){
    int i,j,k;

    for (k=0; k<NV; k++){
        for (i=0; i<NV; i++){
            for (j=0; j<NV; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printMatrix(dist);
}

int main(){
    int graph[NV][NV] = { { 0, 15, 12, 10 },
                        { INF, 0, 13, 17 },
                        { 6, INF, 0, 10 },
                        { INF, INF, INF, 0 } };

    floyd(graph);
    return 0;
}

//TIME COMPLEXITY: O(N^3)