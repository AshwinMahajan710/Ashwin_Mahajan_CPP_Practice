#include"Ashwin_Mahajan_task3_global.h"

// Definition of values swap
void exchange(double* ad1, double* ad2){
    double temp = *ad1;
    *ad1 = *ad2;
    *ad2 = temp;
}

// Definition for poly function
int Poly(int val){
    return (val*val);
}

// definition of evaluate function
int evaluate(int val,int(*Poly)(int)){
    return (val + Poly(val));
}
