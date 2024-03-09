#include <iostream>
#include "Array.h"

int main() {
    Array<int> arr(5);

    arr.Insert(0, 10);
    arr.Insert(1, 20);
    arr.Insert(2, 30);
    arr.Insert(3, 40);
    arr.Insert(4, 50);

    std::cout << "Array values: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    

    arr.Delete(2);

    std::cout << "Array values after deleting index 2: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Array<int> arr2(3);
    arr2.Insert(0, 60);
    arr2.Insert(1, 70);
    arr2.Insert(2, 80);

    arr.Insert(2, arr2);

    std::cout << (arr == arr2) << std::endl;

    std::cout << "Array values after inserting another array: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.Sort();

    std::cout << "Array values after sorting: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array position : ";
    //std::cout << arr.BinarySearch(10) << std::endl;

    return 0;
}
