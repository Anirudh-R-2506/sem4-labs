#include <stdio.h>
#include <stdlib.h>

void main() {
	int v,x,i,j;
	printf("Enter the number of vertices ");
	scanf("%d",&v);
	int ** adjMat = (int **) calloc(v,sizeof(int *)); 
	for(i=0;i<v;i++) {
		adjMat[i] = (int *) calloc(v,sizeof(int));
	}

	for(i=0;i<v;i++) {
		for(j=0;j<v;j++) {
			if (i==j) 
				adjMat[i][i] = 0;
			else {
				if (adjMat[i][j] != 1 && adjMat[i][j] != -1) {
					printf("Is vertex %d connected to vertex %d ? Type 1 if yes, 0 if no ", (i+1), (j+1));
					scanf("%d",&x);
					if (x == 1) {
						adjMat[i][j] = 1;
						adjMat[j][i] = 1;
					}
					else {
						adjMat[i][j] = -1;
						adjMat[j][i] = -1;
					}
				}
			}
		}
	}
	printf("Adjacency Lists:\n");
	for(i=0;i<v;i++){
        printf("Vertex %d -> ", i+1);
        for(j=0;j<v;j++) {
			if (adjMat[i][j] == 1)
				printf("Vertex %d -> ", j+1);
		}
		printf("\n");
    }
	printf("\nAdjacency Matrix is:\n");
	for(i=0;i<v;i++) {
		for(j=0;j<v;j++) {
			if (adjMat[i][j] == -1)
				adjMat[i][j] = 0;
			printf("%d ", adjMat[i][j]);
		}
		printf("\n");
	}
}
