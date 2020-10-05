#include <iostream> // std::cout, std::endl
#include <iomanip>  // std::setfill, std::setw
#include <array>

const uint64_t DIM_SIZE = 16;
const uint64_t ARRAY_SIZE = DIM_SIZE * DIM_SIZE;

void print_matrix(std::array<uint64_t, ARRAY_SIZE> matrix);
std::array<uint64_t, ARRAY_SIZE> regular_multiply(
    std::array<uint64_t, ARRAY_SIZE> matrixA,
    std::array<uint64_t, ARRAY_SIZE> matrixB);
std::array<uint64_t, ARRAY_SIZE> transpose_matrix(
    std::array<uint64_t, ARRAY_SIZE> matrix);
std::array<uint64_t, ARRAY_SIZE> transpose_multiply(
    std::array<uint64_t, ARRAY_SIZE> matrixA,
    std::array<uint64_t, ARRAY_SIZE> matrixB);

int main()
{
    // create matrixA
    std::array<uint64_t, ARRAY_SIZE> matrixA;
    for (uint64_t i = 0; i < ARRAY_SIZE; i++)
    {
        matrixA.at(i) = i;
    }

    // create matrixB
    std::array<uint64_t, ARRAY_SIZE> matrixB;
    for (uint64_t i = 0; i < ARRAY_SIZE; i++)
    {
        matrixB.at(i) = ARRAY_SIZE - i - 1;
    }

    print_matrix(matrixA);
    print_matrix(transpose_matrix(matrixA));
    // print_matrix(matrixB);


    return 0;
}

/**
 * Print out a 1D array as a matrix
 *
 * @param matrix the 1D array to be printed
 */
void print_matrix(std::array<uint64_t, ARRAY_SIZE> matrix)
{
    for (uint64_t i = 0; i < ARRAY_SIZE; i++)
    {
        // set up so that each number visually takes up at
        // least four spaces
        std::cout << std::setfill(' ') << std::setw(4);
        std::cout << matrix.at(i);
        // newline if end of a row is reached,
        // otherwise add a comma
        if ((i + 1) % DIM_SIZE == 0)
            std::cout << std::endl;
        else
            std::cout << ",";
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
std::array<uint64_t, ARRAY_SIZE> regular_multiply(std::array<uint64_t, ARRAY_SIZE> matrixA,
                                                  std::array<uint64_t, ARRAY_SIZE> matrixB)
{
    std::array<uint64_t, ARRAY_SIZE> resultMatrix;
    for (int i = 0; i < DIM_SIZE; i++)
    {
        for (int j = 0; j < DIM_SIZE; j++)
        {
            for (int k = 0; k < DIM_SIZE; k++)
            {
            }
        }
    }
    return resultMatrix;
}

/**
 * Transpose a matrix
 *
 * @param matrix - the array to be tranposed
 *
 * @return a transposed matrix
 */
std::array<uint64_t, ARRAY_SIZE> transpose_matrix(std::array<uint64_t, ARRAY_SIZE> matrix)
{
    // for each element_i_j, it is only required to move it from
    // (i,j) to (j,i) in the transposed array
    // we first form our resulting matrix as empty
    std::array<uint64_t, ARRAY_SIZE> transposedMatrix;
    for (int i = 0; i < DIM_SIZE; i++)
    {
        for (int j = 0; j < DIM_SIZE; j++)
        {
            transposedMatrix.at(j * DIM_SIZE + i) = matrix.at(i * DIM_SIZE + j);
        }
    }
    return transposedMatrix;
}

/**
 * Multiply 2 matrices with transposition
 *
 * @param matrixA first matrix in the product
 *
 * @param matrixB second matrix in the product, it will be transposed first
 * 
 * @return result of the multiplication
 */
std::array<uint64_t, ARRAY_SIZE> transpose_multiply(std::array<uint64_t, ARRAY_SIZE> matrixA,
                                                    std::array<uint64_t, ARRAY_SIZE> matrixB)
{

    std::array<uint64_t, ARRAY_SIZE> dummyMatrix;
    return dummyMatrix;
}