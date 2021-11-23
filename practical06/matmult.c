
/*******************************************************
 *                 Week 6 practical
 *               Matrix Multiplication
********************************************************/

// Multiples two matrices A and B
void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]) {

    int i,j,k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < q; j++)
        {
            // For every element i,j of C get the dot product of the i'th row in A and j'th
            // column in B
            for (k = 0; k < p; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}