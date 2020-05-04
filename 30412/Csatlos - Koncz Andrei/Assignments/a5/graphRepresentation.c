//
// Created by csatl on 4/5/2020.
//
#include <stdlib.h>

#include "graphRepresentation.h"

void readFromAdjMatrix(FILE *f) {
    int n;
    fscanf(f, "%d", &n);
    nrOfVertexes = n;
    int i, j;
    adjMatrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        *(adjMatrix + i) = (int *) malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    fclose(f);
}

void readFromList(FILE *f)
{
    int n;
    fscanf(f, "%d", &n);
    fgetc(f);
    nrOfVertexes = n;
    adjMatrix = (int **) calloc(n,n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(adjMatrix + i) = (int *) calloc(n,n * sizeof(int));
    }
    char s[100];
    int j;
    for(int i= 0; i<n; i++)
    {
        fgets(s,100,f);
        char *p = strtok(s," ");
        while(p)
        {
            j = atoi(p);
            adjMatrix[i][j-1] = 1;
            p = strtok(NULL," ");
        }
        printf("%s",s);
    }
    /*
    int i, j;
    adjMatrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        *(adjMatrix + i) = (int *) malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);*/
    fclose(f);
}

void printAdjMatrix() {
    int i, j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i = 0; i < nrOfVertexes; i++) {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < nrOfVertexes; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < nrOfVertexes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}


int getNumberOfNeighborsOfVertex(int v) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = 0;
        int i;
        for (i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    } else {
        return 0;
    }
}

int *getAllNeighborsOfVertex(int v) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int i, j = 0;
        for (i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                neighbors[j] = i;
                j++;
            }
        }
        return neighbors;
    } else {
        return NULL;
    }
}