#include <iostream>

void print_array(int *array, int size){
    for(int i=0; i < size; i++){
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

int main(){
    const int SIZE = 5;
    int count = 0;
    int arr[SIZE];

    for(int i=0; i < SIZE; i++){
        if(std::cin >> arr[i]){ count++; }
        else{ break; }
    }

    print_array(arr, count);

    return 0;
}
