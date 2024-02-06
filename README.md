# Matrix-Multiplication
This algorithm multiply two upper triangular matrix that gives in a single array,  and mapping result matrix to single array.


The matrices are stored in the input.txt file. 
The first row indicates the matrix height, 
the second row represents the elements of the first upper triangular matrix, and the third row represents the elements of the second upper triangular matrix.

These matrices are mapped to a 1D array. With this formula (N * i - (i-1)*i/2 + (j-i) for a matrix stored in a 1D array N = matrix height, i = row index , j = column index)

In this algorithm, we take two single arrays and multiply them to obtain another result matrix. This resulting matrix is also mapped to a single array. Finally, we print all matrices to the screen.

Example input file content:
4
1 2 3 4 6 7 8 11 12 16
16 15 14 13 11 10 9 6 5 1

-------------------------------------------------------

A = [(1,2,3,4), (0,6,7,8), (0,0,11,12), (0,0,0,16)] 
     
B = [(16,15,14,13), (0,11,10,9), (0,0,6,5), (0,0,0,1)]

A X B = [(16,37,52,50), (0,66,102,97), (0,0,66,67), (0,0,0,16)]

Example output of the above given matrices in single array form:
16 37 52 50 66 102 97 66 67 16
        
  
