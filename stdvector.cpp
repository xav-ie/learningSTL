// NOTES:
// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

// ELEMENT ACCESS
// at(), [], front(), back(), data()

// MODIFIERS:
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declarations
    std::vector<int> arr1;
    std::vector<int> arr2 (5,20);
    std::vector<int> arr3 = {1,2,3,4,5}; 
    std::vector<int> arr4 {1,2,3,4}; 

    arr3.at(0) = arr4.at(3);
    arr2[3] = 111;
    arr2.push_back(99);
    for(int i=0; i<arr2.size(); i++)
        cout<<i<<": "<<arr2.at(i)<<"\n";
    
    return 0;
}