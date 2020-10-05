// NOTES:
// 1. std::array is a container that encapsulates fixed size arrays.
// 2. array size is needed at compile time.
// 3. Assign by value is actually by value.
// 4. Access Elements:
//    a. at()
//    b. []
//    c. front()
//    d. back()
//    e. data() // gives access to the underlying array

#include <iostream>
#include <array>

using namespace std;

int main() {
    // Declare
    std::array<int, 5> myarray;
    cout << &myarray << "\n";
    // Initialization
    std::array<int, 5> myarray2 = {1, 2, 3, 4, 5}; // initializer list
    std::array<int, 5> myarray3 {1, 2, 3, 4, 5}; // not valid anymore
    cout << myarray3[0] << endl;
    cout << myarray2[0] << "\n";
    // Assign using initializer list
    std::array<int, 5> myarray4;
    myarray4.fill(4);


    return 0;



}