// NOTES:
// 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in set then we will have to provide 
//    compare function so that set can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// It store unique elements and they are stored in sorted order (A/D)

#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;

class Person {
    public:
        float age;
        string name;
    bool operator < (const Person &other) const {
        if(name.compare(other.name) == 0) return age<other.age;
        return (name<other.name);
    }
    bool operator > (const Person &other) const {
        if(name.compare(other.name) == 0) return age>other.age;
        return (name>other.name);
    }
};


int main() {
    // set<int> MySet = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    // for(const auto &e: MySet){
    //     cout << e << endl;
    // }
    set<Person, greater<>> People = {{25, "Rupesh"}, {21, "Xavier"}, {22, "John"}, {22, "Xavier"}, {21, "Xavier"}};
    for(const auto &e: People) {
        cout << e.name << "," << e.age <<endl;
    }

    return 0;
}