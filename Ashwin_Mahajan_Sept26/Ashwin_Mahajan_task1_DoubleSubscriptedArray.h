// 11.7 (Overloading the Parentheses Operator) One nice example of overloading the function call
// operator () is to allow another form of double-array subscripting popular in some programming
// languages. Instead of saying
// chessBoard[ row ][ column ]
// for an array of objects, overload the function call operator to allow the alternate form
// chessBoard( row, column )
// Create a class DoubleSubscriptedArray that has similar features to class Array in Figs. 11.6–
// 11.7. At construction time, the class should be able to create an array of any number of rows and
// any number of columns. The class should supply operator() to perform double-subscripting operations. For example, in a 3-by-5 DoubleSubscriptedArray called a, the user could write a(1, 3) to
// access the element at row 1 and column 3. Remember that operator() can receive any number of
// arguments. The underlying representation of the double-subscripted array should be a single-subscripted array of integers with rows * columns number of elements. Function operator() should
// perform the proper pointer arithmetic to access each element of the array. There should be two versions of operator()—one that returns int & (so that an element of a DoubleSubscriptedArray can
// be used as an lvalue) and one that returns const int & . The class should also provide the following
// operators: ==, !=, =, << (for outputting the array in row and column format) and >> (for inputting
// the entire array contents).

#ifndef DOUBLE_SUBSCRIPTED_ARRAY_H
#define DOUBLE_SUBSCRIPTED_ARRAY_H
#include<iostream>

class DoubleSubscriptedArray{
    private:
        int rows, col; // size of rows and cols
        int * ptr; // pointer to 2d array
    
    public: 
        DoubleSubscriptedArray(int , int); // constructor
        friend std::ostream& operator<<(std::ostream& out, DoubleSubscriptedArray& arr);// friend function to << print 
        friend std::istream& operator>>(std::istream& in, DoubleSubscriptedArray& arr); // friend function to input mat
        bool operator==(DoubleSubscriptedArray& other); // for checking equlity
        int& operator()(int ,int ); // subscript operator to get desired row and col 
        const int& operator()(int ,int ) const; // subscript operator to get desired row and col 
        ~DoubleSubscriptedArray();

};  

#endif
