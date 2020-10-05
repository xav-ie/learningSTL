#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::vector<int> Vec;
    Vec.reserve(32);
    for(int i=0; i<32; i++){
        Vec.push_back(i*2);
        cout << "Size: " << Vec.size() << "; \t Capacity: " << Vec.capacity() << endl;
    }
    return 0;
}