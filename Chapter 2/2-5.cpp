#include <stdio.h>

int bsearch_recursive(int *array, int key, int left, int right) {
    int middle = (right+left)/2;
    if (left == right) {
        return middle;
    }
    if (left >= right) {
        return -1;
    }
    if (array[middle]==key) {
        return middle;
    }
    if (left == middle || right==middle) {
        return -1;
    }
    int left_search = bsearch_recursive(array, key, left, middle);
    int right_search = bsearch_recursive(array, key, middle, right);
    return left_search > right_search ? left_search : right_search;
}

int bsearch(int *array, int key, int num) {
    return bsearch_recursive(array, key, 0, num);
}

int main() {
    int test_arr_size = 7;
    int test_array[7] = {0, 1, 2, 3, 4, 5, 6};
    for (int i =-1; i< 8; i++) {
        printf("The key %d was found at index %d\n", i, bsearch(test_array, i, test_arr_size));
    }    
    return 1;
}