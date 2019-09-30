/**
     *  Program # 2
     *  This program takes in matrix values from a text file, multiplies
     *    two matrices together, and prints the results. Students are not
     *    allowed to alter the header file "p2.h" in any way. They are also
     *    not allowed to use any square brackets "[]".
     *  CS320
     *  Date
     *  @author  Nam Tran cssc0517
     */

#include "p2.h"

int main(int argc, char **argv){
    
    /* Print the title line */
    printf("\nProgram #2, cssc0517, Nam Tran\n\n");

    /* Checking for correct number of arguments */
    if (argc!=2){
        printf("The proper format is p2 theInputfile.\n");
    return 0;
    }
    
    int *matrixA, *matrixB, *matrixC;
    int m, n, p;
    
    read_matrices(&matrixA, &matrixB, &matrixC, &m, &n, &p, *(argv + 1));
    return 0;
}

/* This function reads m, n, and p from the datafile.
    It then allocates the correct amount of memory required for matrices
    A, B, and C.
    Then matrices A and B are filled from the datafile.
    The values for m, n, and p are passed by reference, and are
    thus filled in by this function
    PARAMETERS in order are:
    int **matA      	matrix A
    int **matB      	matrix B
    int **matC      	matrix C
    int *m       	m   The number of rows in matrix A
    int *n       	n   The number of columns in matrix A and
                    	The number of rows in matrix B
    int *p       	p   The number of columns in matrix B
    char *dataFile    The name of the datafile, from the command line
*/
void read_matrices(int **matA, int **matB, int **matC,  int *m, int *n, int *p, char *dataFile){
    /* Creating a file stream */
    FILE *fd = fopen(dataFile,"r");

    /* Scanning for the matrix dimensions */
    fscanf(fd, "%d %d %d", m, n, p);
     
    /* Allocating memory for matrix A */   
    matA = (int**)malloc((*m)*(*n)*sizeof(int*));
    if (matA == NULL){
    	printf("Cannot allocate enough memory for matA!");
	    exit(1);
    }
    
    /* Populating Matrix A with elements */
    int i, j;
    for (i = 0; i < *m; i++){
    	for(j = 0; j < *n; j++){
		    *(matA + i * (*n) + j) = (int*)malloc(sizeof(int));
		    fscanf(fd, "%d", *(matA + i * (*n) + j));
	    }
    }
    
    /* Allocating memory for matrix B */   
    matB = malloc((*n)*(*p)*sizeof(int*));
    if (matB == NULL){
    	printf("Cannot allocate enough memory for matB!");
	    exit(1);
    }
    
    /* Populating Matrix B with elements */
    for (i = 0; i < *n; i++){
    	for(j = 0; j < *p; j++){
		    *(matB + i * (*p) + j) = malloc(sizeof(int));
		    fscanf(fd, "%d", *(matB + i * (*p) + j));
	    }
    }
    
    fclose(fd);
    
    /* Allocating memory for Matrix C */
    *matC = (int*)malloc((*m)*(*p)*sizeof(int));
    if (*matC == NULL){
    	printf("Cannot allocate enough memory for matC!");
	    exit(1);
    }
    
    printf("Matrix A contents:\n");
    print_matrix(*matA, *m, *n);
    
    printf("Matrix B contents:\n");
    print_matrix(*matB, *n, *p);
    
    mult_matrices(*matA, *matB, *matC, *m, *n, *p);
    printf("Matrix A * B is:\n");
    print_matrix(*matC, *m, *p);
    
    free(*matA);
    free(*matB);
    free(*matC);
}


/*  This function prints a matrix.  Rows and columns should be preserved.
    PARAMETERS in order are:
    int *matrix		The matrix to print
    int rows		  The number of rows in the matrix
    int columns		The number of columns in the matrix
    
*/
void print_matrix(int *matrix, int rows, int columns){
	int i;
	int j;
	for (i = 0; i < rows; i++){
		for (j = 0; j < columns; j++){
			printf("%d ", *(matrix + (i*columns + j)*sizeof(int*)));
		}
		printf("\n");
	}
	printf("\n");	
}

/*  The two matrices A and B are multiplied, and matrix C contains the
    result.
    PARAMETERS in order are:
    int *matA    Matrix A
    int *matB    Matrix B
    int *matC    Matrix C
    int m        m
    int n        n
    int p        p
*/
void mult_matrices(int *matA, int *matB, int *matC, int m, int n, int p){
	int i, j, k;
	for(i=0; i < m; i++){
    		for(j=0; j < p; j++) { 
        		*(matC + (i * p + j)*sizeof(int*)) = 0; 
        		for(k=0; k < n; k++){
                  /* C[i][j] += A[i][k] * B[k][j] */
            			*(matC + (i * p + j)*sizeof(int*)) += *(matA + (i*n + k)*sizeof(int*)) * *(matB + (j + k*p)*sizeof(int*));
    			}
		}
	}
}	
