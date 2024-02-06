
#include <stdio.h>
#include <stdlib.h>

/*
The formula N * i - (i-1)*i/2 + (j-i) for a matrix stored in a 1D array
is adapted from a Stack Overflow discussion.

Source:
Stack Overflow. (2016, Jan 15). "Multiplying upper triangular matrix stored in 1D array - Algorithm."
URL: https://stackoverflow.com/questions/34804216/multiplying-upper-triangular-matrix-stored-in-1d-array-alogrithm
*/

void multiplyUpperTriangularMatrices(int n, int *A, int *B, int *C) {   // multiply upper triangular matrices function
    int i;
    int j;
    int k;                               
    
    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
            int value = 0;
            for (k = i; k <= j; ++k) {      // Multiply algorithm for upper triangular matrices
                value += A[n * i - (i-1)*i/2 + (k-i)] *  B[n * k - (k-1)*k/2 + (j-k)];         // value variable for store the sum of values, I use the reference for this line
            }
            C[n * i - (i-1)*i/2 + (j-i)] = value;        // assign value to C matrix
        }
    } 
}

void printResult(int n, int *A, int *B, int *C)            // print result function
{
    int i, j, k;
    int lenght;
    lenght = n*(n+1)/2;
    i = 0;
    printf("***** row major 1d form for the A, B and C matrixes C = AxB *****\n\n");
    printf("A: ");
    for(i=0; i<lenght; i++)         //print the 1d array of A matrix         
    {
            printf("%d ", A[i]);    
    }
    printf("\n\n");
    
    printf("B: ");
    for(i=0; i<lenght; i++)         //print the 1d array of B matrix       
    {
            printf("%d ", B[i]); 
    }
    printf("\n\n");
    
    printf("C: ");
    for(i=0; i<lenght; i++)         //print the 1d array of C matrix       
    {
            printf("%d ", C[i]); 
    }
    printf("\n\n");
    
    printf("***** 3d form for the result matrix C *****\n\n");
    k = 0; 
    for (i = 0; i < n; i++)         //print the 2d array of C matrix / result matrix      
    {       
        for(j=0; j<i; j++)
        {
                 printf("0\t");
        }
        for (j=0; j < n-i; j++) {
            printf("%d\t", C[k]); 
            k++;
        }
        
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");       // open input.txt for read matrix data
    if(file == NULL)                            // if statement for any error happen while opening file
    {
            printf("error occured while opening file\n");
    }
    
    int n;
    fscanf(file, "%d", &n);                      // read N value from file
    int sayi;
    
    int *A = (int *)malloc(n * (n + 1) / 2 * sizeof(int));       // memory allocate for matrices
    int *B = (int *)malloc(n * (n + 1) / 2 * sizeof(int));
    int *C = (int *)malloc(n * n * sizeof(int));
    
    int i;
    int j;
    int lenght;
    
    lenght = n*(n+1)/2;        // 1d array lenght
    for(i = 0; i<lenght; i++)
    {
          fscanf(file, "%d", &A[i]);       // read A matrix
    }
    printf("\n");
    for(i = 0; i<lenght; i++){
          fscanf(file, "%d", &B[i]);       // read B matrix
    }

    fclose(file);            // close the file 
    
    multiplyUpperTriangularMatrices(n, A, B, C);   // function that multiply A and B matrices from their 1d array
    printResult(n, A, B, C);                       // function for printing A, B, C matrices 1d form and C matrix 2d form
    
    getch();
    return 0;
}
