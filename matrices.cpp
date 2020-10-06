#include <iostream> // std::cout, std::endl
#include <iomanip>  // std::setfill, std::setw
#include <array>
#include <chrono>
#include <stdlib.h>

const uint64_t DIM_SIZE = 1024;
const uint64_t ARRAY_SIZE = DIM_SIZE * DIM_SIZE;
const int INT_SIZE = 8;

void print_matrix(uint64_t* matrix);

void regular_multiply(
    uint64_t* matrixA,
    uint64_t* matrixB,
    uint64_t* resultMatrix);

void transpose_matrix(
    uint64_t* matrix,
    uint64_t* transposedMatrix);

void transpose_multiply(
    uint64_t* matrixA,
    uint64_t* matrixB,
    uint64_t* resultMatrix);
    
bool isEqual(
  uint64_t* matrixC,
  uint64_t* matrixCTranspose);

int main()
{
    // create matrixA
    uint64_t* matrixA = (uint64_t*) malloc(INT_SIZE * ARRAY_SIZE);
    for (uint64_t i = 0; i < ARRAY_SIZE; i++)
    {
        matrixA[i] = i;
    }

    // create matrixB
    uint64_t* matrixB = (uint64_t*) malloc(INT_SIZE * ARRAY_SIZE);
    for (uint64_t i = 0; i < ARRAY_SIZE; i++)
    {
        matrixB[i] = ARRAY_SIZE - i - 1;
    }
    
    // matrixC is the result of regular matrix multiplication
    uint64_t* matrixC = (uint64_t*) malloc(INT_SIZE * ARRAY_SIZE);
    auto regularStart = std::chrono::high_resolution_clock::now();
    regular_multiply(matrixA, matrixB, matrixC);
    auto regularEnd = std::chrono::high_resolution_clock::now(); 
    auto regularDuration = 
      std::chrono::duration_cast<std::chrono::milliseconds>(regularEnd - regularStart).count();

    std::cout << "Time elapsed for normal multiplation: " << regularDuration << " milliseconds" << std::endl;

    // matrixCTranspose is the result of transposing B first and 
    // then multiplying it with matrix A
    uint64_t* matrixBT = (uint64_t*) malloc(INT_SIZE * ARRAY_SIZE);
    transpose_matrix(matrixB, matrixBT);
    auto transposeStart = std::chrono::high_resolution_clock::now();
    uint64_t* matrixCTranspose = (uint64_t*) malloc(INT_SIZE * ARRAY_SIZE);
    transpose_multiply(matrixA, matrixBT, matrixCTranspose);
    auto transposeEnd = std::chrono::high_resolution_clock::now();

    auto transposeDuration = 
      std::chrono::duration_cast<std::chrono::milliseconds>(transposeEnd - transposeStart).count();

    std::cout << "Time elapsed for tranpose multiplation: " << transposeDuration << " milliseconds" << std::endl;

    // check the matrixC and matrixCTranspose are identical
    std::cout << "Are matrixC and matrixCTranspose equal? => "
              << std::boolalpha
              << isEqual(matrixC, matrixCTranspose) << std::endl;

    return 0;
}

/**
 * Print out a 1D array as a matrix
 *
 * @param matrix the 1D array to be printed
 */
void print_matrix(uint64_t* matrix)
{
    for (uint64_t i = 0; i < ARRAY_SIZE; i++)
    {
        // set up so that each number visually takes up at
        // least four spaces
        std::cout << std::setfill(' ') << std::setw(4);
        std::cout << matrix[i];
        // newline if end of a row is reached,
        // otherwise add a comma
        if ((i + 1) % DIM_SIZE == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Multiply 2 matrices without transposition
 *
 * @param matrixA first matrix in the product
 *
 * @param matrixB second matrix in the product
 * 
 * @return result of the multiplication
 */
void regular_multiply(uint64_t* matrixA,
                      uint64_t* matrixB,
                      uint64_t* resultMatrix)
{
  for (int i = 0; i < DIM_SIZE; i++)
  {
    for (int j = 0; j < DIM_SIZE; j++)
    {
      // must intialize result array to 0
      resultMatrix[i * DIM_SIZE + j] = 0;                    
      for (int k = 0; k < DIM_SIZE; k++)
      {
        resultMatrix[i * DIM_SIZE + j] += 
                        matrixA[i * DIM_SIZE + k] *  
                        matrixB[k * DIM_SIZE + j];
      }
    }
  }
}

/**
 * Transpose a matrix
 *
 * @param matrix - the array to be tranposed
 *
 * @return a transposed matrix
 */
void transpose_matrix(uint64_t* matrix,
                      uint64_t* tranposedMatrix)
{
    // for each element_i_j, it is only required to move it from
    // (i,j) to (j,i) in the transposed array
    // we first form our resulting matrix as empty
    for (int i = 0; i < DIM_SIZE; i++)
    {
        for (int j = 0; j < DIM_SIZE; j++)
        {
            tranposedMatrix[j * DIM_SIZE + i] = matrix[i * DIM_SIZE + j];
        }
    }
}

/**
 * Multiply 2 matrices assuming the second matrix is already transposed
 *
 * @param matrixA first matrix in the product
 *
 * @param matrixB second matrix in the product (already transposed)
 * 
 * @return result of the multiplication
 */
void transpose_multiply(uint64_t* matrixA, uint64_t* matrixB, uint64_t* resultMatrix) {
  // std::array<uint64_t, ARRAY_SIZE> resultMatrix;
  for (int i = 0; i < DIM_SIZE; i++)
  {
    for (int j = 0; j < DIM_SIZE; j++)
    {
      // must intialize result array to 0
      resultMatrix[i * DIM_SIZE + j] = 0;                    
      for (int k = 0; k < DIM_SIZE; k++)
      {
        resultMatrix[i * DIM_SIZE + j] += 
                        matrixA[i * DIM_SIZE + k] *  
                        matrixB[j * DIM_SIZE + k];
      }
    }
  }
  // return resultMatrix;
}

/**
 * Check that two matrices are equal
 *
 * @param matrixA one matrix
 *
 * @param matrixB second matrix
 * 
 * @return bool true if they are identical in values
 */
bool isEqual(uint64_t* matrixA,
             uint64_t* matrixB) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (matrixA[i] != matrixB[i]) return false;
  }
  return true;
}