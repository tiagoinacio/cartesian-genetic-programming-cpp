#include "test/to_vec.h"

std::vector<unsigned int> toVec(const int arr[], const size_t size) {
    std::vector<unsigned int> vec;

    for (int i = 0; i < size; i++) {
        vec.push_back(arr[i]);
    }

    return vec;
}
