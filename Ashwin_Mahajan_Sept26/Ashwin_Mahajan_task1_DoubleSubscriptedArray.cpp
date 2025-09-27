#include"Ashwin_Mahajan_task1_DoubleSubscriptedArray.h"
#include<stdexcept>

// Default constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(int rows, int col){
    this->ptr = new int [rows*col];
    this->col = col;
    this->rows = rows;
}

// Frined function to print the matrix 
std::ostream& operator<<(std::ostream& out, DoubleSubscriptedArray& arr){
    int n_cols = 0;
    for(int i=0;i<arr.rows * arr.col;i++){
        out<<arr.ptr[i]<<" ";
        n_cols++;
        if(n_cols==arr.col){
            std::cout<<std::endl;
            n_cols = 0;
        }
    }
    out<<std::endl;
    return out;
}

// Overloading operator to get input
std::istream& operator>>(std::istream& in, DoubleSubscriptedArray& arr) {
    std::cout << "Enter " << arr.rows << "x" << arr.col << " matrix elements:" << std::endl;
    for (int i = 0; i < arr.rows * arr.col; i++) {
        in >> arr.ptr[i];
    }
    return in;
}

// Compare arrays return true if same else false
bool DoubleSubscriptedArray::operator==(DoubleSubscriptedArray&  other){
    if(this->rows != other.rows || this->col != other.col) {return false;} // rows and columns no not match return false
    for(int i=0;i<rows*col;i++){
        if(this->ptr[i] != other.ptr[i]){
            return false;
        }
    }
    // Both arrays are equal 
    return true;
}

// subscript operator to get the elements in arr as refererence but modifyable
int& DoubleSubscriptedArray:: operator()(int i,int j){
    if((i>=0 && i<rows) && (j>=0 && j<col)){
        return ptr[(i*col) + j];
    }
    else {throw std::out_of_range("The arguments passed are out of range of array...");}
}

// Return reference which is not modifyable
const int& DoubleSubscriptedArray::operator() (int i, int j)const{
    if((i>=0 && i<rows) && (j>=col && j<col)){
        return ptr[i*col + j];
    }
    else {throw std::out_of_range("The arguments passed are out of range of array...");}
}

// Destructor
DoubleSubscriptedArray::~DoubleSubscriptedArray(){
    delete[] ptr;
}