// Formulas For nD Arrays

/*
 * Horner's Rule reduces the number of multiplications down to O(n)
 * 
 * In computing, row-major order and column-major order are methods for storing
 * multidimensional arrays in linear storage such as random access memory.
 * 
 * Column Major Order:
 * 
 * The formula is:
 * LOC (A [J, K]) = Base (A) + w [M (K-1) + (J-1)]
 * 
 * LOC (A [J, K])      is the location of the element in the Jth row and Kth column.
 * Base (A)            is the base address of the array A.
 * w                   is the number of bytes required to store single element of the array A.
 * M                   is the total number of rows in the array.
 * J                   is the row number of the element.
 * K                   is the column number of the element.
 * 
 * Row Major Order:
 * 
 * The formula is: 
 * LOC (A [J, K]) = Base (A) + w [N (J-1) + (K-1)]
 * 
 * LOC (A [J, K])       is the location of the element in the Jth row and Kth column.
 * Base (A)             is the base address of the array A.
 * w                    is the number of bytes required to store single element of the array A.
 * N                    is the total number of columns in the array.
 * J                    is the row number of the element.
 * K                    is the column number of the element.
 */