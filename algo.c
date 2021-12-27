#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


// void bellman_ford(int** arr)
// {
//    int i, j, k;
//     for (k = 0; k < n; k++)
//     {
//         for (i = 0; i < n; i++)
//         {
//             for (j = 0; j < n; j++)
//             {
//                 if(i!=j){
                
//                 if (arr[i][j] == 0)
//                 {
//                    arr[i][j] = 1000;
//                 }
//                 arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
//             }
//             }
//         }
//     }
// }
#define n 10
#define maxint 1000
int matrix[n][n];
void shortestPath(int i, int j)
{
    if (matrix[i][j] != 0&&matrix[i][j]!=maxint)
    {
        printf("%d\n", matrix[i][j]);
    }
    else
    {
        printf("-1\n");
    }
}
void bellman_ford(int **matrix,int b)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if(i!=j){
                
                if (matrix[i][j] == 0)
                {
                    matrix[i][j] = maxint;
                }
                if(matrix[i][j] > matrix[i][k]+matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k]+matrix[k][j];
                }
              }
            }
        }
    }
}
int createMatrix(pnode *head)
{
    pnode p =*head;
    int sum = 0;
    while (p)
    {
        sum ++;
        p = p->next;
    }
    int **matrix = (int**)malloc(sizeof(int)*sum*sum);
    for (int i = 0; i < sum; i++)
    {
        for (int j = 0; j < sum; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            int w = findWbySrc(head, i, j);
            if (w!= -1)
            {
                matrix[i][j] = findWbySrc(head,i,j);
            }
            else
            {
                matrix[i][j] = maxint;
            }
        }

    }
    printf("%d----",matrix[1][2]);
    // bellman_ford(matrix,1);
    
}





