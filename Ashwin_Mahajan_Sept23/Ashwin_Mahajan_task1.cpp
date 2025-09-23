#include<iostream>
#include<unordered_set>

// Function for printing the array
void printArr(const int arr[], const int &idx){
    for(int i=0;i<idx;i++){
        std::cout<<arr[i]<<" ";
    }
}

// Function for checking duplicates in array
bool isFound(const int &idx, const int arr[], const int val){
    for(int i=0;i<idx;i++){
        if(arr[i] == val){
            return true;
        }
    }
    return false;
}

// Function for validating and adding the input in array --> Search Using plain array
void validate_input_1(int &idx,int arr[],const char* str){
    int no;
    bool valid = true;
    do{
        std::cout<<str<<idx<<": ";
        std::cin>>no;
        if(no<10 || no>100 || isFound(idx,arr,no)){
            std::cout<<"No is either duplicated or exceeds the range of 10 to 100.... Enter again.."<<std::endl;
            valid = false;
        }
        else{
            arr[idx] = no;
            idx++;
            std::cout<<"Successfull allocation....."<<std::endl; 
            valid = true;
        }
    }while(!valid);
}

// Function for validating and adding the input in array --> Search Using unordered_map array
void validate_input_2(int &idx,int arr[],const char* str, std::unordered_set<int > &set){
    int no;
    bool valid = true; // declaration of set

    do{
        std::cout<<str<<idx<<": ";
        std::cin>>no;
        if(no<10 || no>100 || set.find(no) != set.end()){
            std::cout<<"No is either duplicated or exceeds the range of 10 to 100.... Enter again.."<<std::endl;
            valid = false;
        }
        else{
            arr[idx] = no;
            idx++;
            set.insert(no);
            std::cout<<"Successfull allocation....."<<std::endl; 
            valid = true;
        }
    }while(!valid);
}

int main(){
    
    int arr[20];// Declare the array of size 20
    
    // Approach 1: ---> Using The plain array and searching ---> (TC: O(n) + O(n)) (complexity to search ele + complexity to print ele)
    // int idx = 0; // Current index to add ele
    // while(idx<20){
    //     validate_input_1(idx,arr,"Enter the non-duplicated no between 10 to 100 for index ");
    // } 

    // std::cout<<" The total unique values that user entered are: "<<std::endl;
    // printArr(arr,idx);




    // Approach 2: ----> Using unordered map for efficient time complexity ---> TC(O(1) + O(n));
    std::unordered_set<int> set; // for storing the element 
    int idx = 0; // Current index to add ele
    while(idx<20){
        validate_input_2(idx,arr,"Enter the non-duplicated no between 10 to 100 for index ",set);
    } 

    std::cout<<" The total unique values that user entered are: "<<std::endl;
    printArr(arr,idx);

    return 0;
}