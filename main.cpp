#include<iostream>
#include <vector>

#include"merge_sort.h"

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> example {9,3,2,8,1,7,3,4,6,5};
    vector<int> sorted;

    cout << "Example: ";
    for (unsigned int i = 0; i < example.size(); i++) {
        cout << " " << example[i] << " ";
    }
    cout << endl;

    sorted = sort(example);
    cout << "Sorted: ";
    for (unsigned int i = 0; i < sorted.size(); i++) {
        cout << " " << sorted[i] << " ";
    }
    cout << endl;
    cout << "Merge sort complete\n";    

    return 0;
}