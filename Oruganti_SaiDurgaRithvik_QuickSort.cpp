#include <iostream>
#include <cmath>
#include <random>



int partition(int array[], int low, int high){
    int pivot = array[high], val = low - 1;
    for (int i = low; i < high; ++i){
        if (array[i] <= pivot){
            ++val;

            int tmp = array[i];
            array[i] = array[val];
            array[val] = tmp;
        }
    }

    int tmp = array[high];
    array[high] = array[val+1];
    array[val+1] = tmp;

    return ++val;

}

void sort(int array[], int low, int high){

    if(low < high){
        sort(array, low, partition(array, low, high) - 1);
        sort(array, partition(array, low, high) - 1, high);
    }
}

int main(int argc, char** argv)
{
    int array[] = {3,1,5,12,37,33,11};
    int size = sizeof(array)/sizeof(int);
    
    for (auto i: array)
        std::cout << i << " ";
    std::cout << std::endl;

    sort(array, 0, size-1);

    for (auto i: array)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}