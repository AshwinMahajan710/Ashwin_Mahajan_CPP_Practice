#include<iostream>
#include<algorithm>

// Quick Sort algorithm 
void quicksort(int* arr, int low, int high){
    if(high<=low) {return;}
    
    int pivot = low;
    int left = low + 1;
    int right = high;

    // While pointers 
    while (left <= right) {
        if (arr[left] > arr[pivot] && arr[right] < arr[pivot]) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
        if (arr[left] <= arr[pivot]) left++;
        if (arr[right] >= arr[pivot]) right--;
    }

    std::swap(arr[pivot], arr[right]);
    pivot = right;

    // Recursive call for sorting low and high ends
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
}

int main(){
    int arr[8]{4,6,2,5,7,9,1,3};
    quicksort(arr, 0 , 7);
    for(int i=0;i<=7;i++){
        std::cout<<arr[i]<<" ";
    }
}