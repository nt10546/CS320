# Program #3, Nam Tran
# This program reads two matrices, A and B, from a text file, multiplies
#   them and stores in matrix C. Then prints the contents of all
#   three formatted matrices.
# The program must contain exactly four functions:
#   1. main()
#   2. read_matrices(A, B)
#   3. mult_matrices(A,B,C)
#   4. print_matrix(arr)
# The program may not use the built-in array module
# The program can only import sys

import sys

# This function begins execution of program.
# Verify data input filename provided on command line: len(sys.argv)
# If error, output message for user
# and quit, using sys.exit()
#
# Declare A, B, call read_matrices to initialize A, B, and store
# return value as C
#
# Print A and B contents
#
# Call mult_matrices
#
# Print result contents
def main():
    # Printing title lines
    print("Program #3, Nam Tran\n")

    # Testing for correct number of arguments, and file existence
    try:
        if (len(sys.argv) != 2):
            print("The correct format is python3 p3.py dataFileName")
            sys.exit()
        open(sys.argv[1])
    except FileNotFoundError:
        print("The file \'" + sys.argv[1] + "\' was not found!")
        sys.exit()

    # Initializing empty arrays
    A = []
    B = []
    C = []

    C = read_matrices(A, B)

    # Printing contents of matrices A, B, and C
    print("Matrix A contents:")
    print_matrix(A)
    print("Matrix B contents:")
    print_matrix(B)
    print("Matrix C contents:")
    print_matrix(mult_matrices(A,B,C))
    
    
# This function reads m, n, and p from the datafile.
# Then matrices A and B are filled from the datafile.
# Matrix C is then allocated size m x p.
# The values for m, n, and p are local values filled in by this function
# PARAMETERS in order are:
# list matrix A
# list matrix B
#
def read_matrices(A, B):
    # Reading contents from the file without newlines into a holding list
    holdingList = []
    with open(sys.argv[1], "r") as f:
        holdingList = f.read().splitlines()

    # Grabbing values of m, n, and p
    m = int(holdingList[0])
    n = int(holdingList[1])
    p = int(holdingList[2])

    # Populating matrix A with values
    for i in range(m):
        A.append(holdingList[i+3].split())
        
    # Populating matrix B with values
    for i in range(n):
        B.append(holdingList[i+3+m].split())
        
    # Populating matrix C with size m x p with 0s
    C = [[0 for i in range(p)] for j in range(m)]

    return C

# The two matrices A and B are multiplied, and matrix C contains the
# result.
# PARAMETERS in order are:
# list Matrix A
# list Matrix B
# list Matrix C (all zeros at this point)
def mult_matrices(A,B,C):
    for i in range(len(A)):
        for j in range(len(C[0])):
            for k in range(len(A[0])):
                C[i][j] += int(A[i][k]) * int(B[k][j])

    return C

# This function prints a matrix. Rows and columns should be preserved.
# PARAMETERS in order are:
# list The matrix to print
def print_matrix(arr):
    for rows in arr:
        for columns in rows:
            print(columns, end = " ")
        print("")
    print("")

main()
