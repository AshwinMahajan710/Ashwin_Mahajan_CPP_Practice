
#include<iostream>

// Function to print array
void printArr(int arr[], int size){
    for(int i=0;i<size;i++){
        std::cout<<" "<<arr[i];
    }
}

//  Function to get maximum value from array
int getMaxVal(const int arr[],int size){
    int maxVal = arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>maxVal){maxVal = arr[i];}
    }
    return maxVal;
}

// # Function to get maximum decimal places so that we can run the for loopm over it 
int getMaxDecimalPlaces(const int arr[], int size){
    int maxDecimalPlaces = 0;
    int maxVal = getMaxVal(arr, size);
    while (maxVal!=0)
    {
        maxVal /= 10;
        maxDecimalPlaces++;
    }
    return maxDecimalPlaces;
}


// Bucket sort function
void bucketSort(int arr[], int size){

    int buckets[10][size]{}; // Initializing buckets
    int col_sizes[10]{}; // Will store the col_sizes --> additional array

    int max_decimal_place = getMaxDecimalPlaces(arr,size);
    
    int div_coeff = 1;
    for(int j=0;j<max_decimal_place;j++){
        for(int i=0;i<size;i++){
            int row_idx = (arr[i]/div_coeff)%10;
            buckets[row_idx][col_sizes[row_idx]] = arr[i];
            col_sizes[row_idx]++;
        }
        int k = 0;
        for(int i=0;i<10;i++){
            for(int m=0;m<col_sizes[i];m++){
                arr[k++] = buckets[i][m]; 
            }
            col_sizes[i] = 0;
        }
    div_coeff*=10;
    }
}

// Main function
int main(){

    int size = 8;
    int arr[size]{10,21,34,14,12,12,78,90};

    std::cout<<"\nArray before sorting:";
    printArr(arr,size);
    bucketSort(arr,size);
    std::cout<<"\nArray after sorting:";
    printArr(arr,size);

    return 0;
}
