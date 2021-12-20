#include<iostream>
#include<vector>

std::vector<int> merge(std::vector<int> left_collection, std::vector<int> right_collection) {
    std::vector<int> merged_collection;
    int next_element;

    // If both collections still have elements in them, compare the elements and move the larger element to the back of merged collection
    while((left_collection.size()) && (right_collection.size())) {
       if (left_collection[0] < right_collection[0]) {
           next_element = left_collection[0];
           merged_collection.push_back(next_element);
           left_collection.erase(left_collection.begin());
       } else {
           next_element = right_collection[0];
           merged_collection.push_back(next_element);
           right_collection.erase(right_collection.begin());
       }
    }
    
    // If only one of the collections has element remaining, push it to the end of merged collection
    while(left_collection.size()) {
        next_element = left_collection[0];
        merged_collection.push_back(next_element);
        left_collection.erase(left_collection.begin());
    }
    while(right_collection.size()) {
        next_element = right_collection[0];
        merged_collection.push_back(next_element);
        right_collection.erase(right_collection.begin());
    }
 
    // return the combined sorted collection
    return merged_collection;
}

std::vector<int> sort(std::vector<int> unsorted_collection) {
    int pivot = unsorted_collection.size() / 2;

    std::vector<int> left_collection_unsorted;
    std::vector<int> right_collection_unsorted;

    std::vector<int> left_collection_sorted;
    std::vector<int> right_collection_sorted; 

    std::vector<int> sorted_collection;

    // If only one item is in the collection it is sorted and ready to be merged, return it
    if (unsorted_collection.size() < 2) {
        return unsorted_collection;
    }



    // Divide the unsorted collection into two halves
    for (unsigned int i = 0; i < pivot; i++) {
        left_collection_unsorted.push_back(unsorted_collection[i]);
    }
    for (unsigned int i = pivot; i < unsorted_collection.size(); i++) {
        right_collection_unsorted.push_back(unsorted_collection[i]);
    }

    // Call sort recursively on both collections until all elements are sorted
    left_collection_sorted = sort(left_collection_unsorted);
    right_collection_sorted = sort(right_collection_unsorted);

    sorted_collection = merge(left_collection_sorted, right_collection_sorted);
    return sorted_collection;    
}