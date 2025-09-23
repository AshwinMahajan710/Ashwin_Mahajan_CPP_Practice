#include<iostream>

// Special function which will set 3 modes as off
void setModeOff(bool &val1, bool &val2, bool &val3){
    val1 = false;
    val2 = false;
    val3 = false;
}

// For moving right
void moveRight(bool arr[20][20], const int& row_idx, int& col_idx, const int val, const bool write){
    int update_idx = (col_idx + val) < 20 ? (col_idx + val) : 19;
    if(write){
        for(int i = col_idx; i<= update_idx ; i++){
            arr[row_idx][i] = true;
        }
        col_idx = update_idx;
    }
    else{
        col_idx = update_idx;
    }
}

/*
    For moving left
*/
void moveLeft(bool arr[20][20], const int& row_idx, int& col_idx, const int val, const bool write){
    int update_idx = (col_idx - val) < 0 ? 0 : (col_idx-val);
    if(write){
        for(int i = col_idx; i>= update_idx ; i--){
            arr[row_idx][i] = true;
        }
        col_idx = update_idx;
    }
    else{
        col_idx = update_idx;
    }
}

// for moving up
void moveUp(bool arr[20][20], int& row_idx, const int& col_idx, const int val, const bool write){
    int update_idx = (row_idx - val) < 0 ? 0 : (row_idx-val);
    if(write){
        for(int i = row_idx; i>= update_idx ; i--){
            arr[i][col_idx] = true;
        }
        row_idx = update_idx;
    }
    else{
        row_idx = update_idx;
    }
}


// For moving down
void moveDown(bool arr[20][20], int& row_idx, const int& col_idx, const int val, const bool write){
    int update_idx = (row_idx + val) < 20 ? (row_idx + val) : 19;
    if(write){
        for(int i = row_idx; i<= update_idx ; i++){
            arr[i][col_idx] = true;
        }
        row_idx = update_idx;
    }
    else{
        row_idx = update_idx;
    }
}

// To print the array
void printArray(bool arr[20][20]){
    for(int i = 0; i<20; i++){
        for(int j = 0; j<20; j++){
            std::cout << (arr[i][j] ? "*" : " ");
        }
        std::cout << "\n";   // ✅ move to next row
    }   
}


int main(){

    bool arr [20][20]{}; // Set all the elements as false

    int ch;
    bool writeMode = false; // sets want to write or not
    int curr_row = 0;
    int curr_col = 0;

    // Defines direction to move
    bool left = false; 
    bool right = false; 
    bool up = false; 
    bool down = false;  

    std::cout<<"* * * * * * * * * * * * * * * * * * * * Turtle game * * * * * * * * * * * * * * * * * * * * "<<std::endl;
    do
    { 

        std::cout<<"\n1. Pen Up .. "<<std::endl;
        std::cout<<"2. Pen down .. "<<std::endl;
        std::cout<<"3. Turn right .. "<<std::endl;
        std::cout<<"4. Turn left .. "<<std::endl;
        std::cout<<"5. Turn Up .. "<<std::endl;
        std::cout<<"6. Turn Down .. "<<std::endl;
        std::cout<<"7. Move forward .. "<<std::endl;
        std::cout<<"8. Print Array .. "<<std::endl;
        std::cout<<"9. Get position .. "<<std::endl;
        std::cout<<"10. Exit .. "<<std::endl;

        std::cout<<"Enter your choice: ";
        std::cin>>ch;

        switch (ch)
        {
            case 1:{
                writeMode = false;
                std::cout<<"\n Pens is UP...."<<std::endl;
                break;
            }
                
            case 2:{
                writeMode = true;
                std::cout<<"\n Pens is Down....Writemode on.."<<std::endl;
                break;
            }
            
            case 3:{
                setModeOff(up,down,left);
                right = true;
                std::cout<<"\n Direction set to right...."<<std::endl;
                break;
            }

            case 4:{
                setModeOff(up,down,right);
                left = true;
                std::cout<<"\n Direction set to left...."<<std::endl;
                break;
            }
            
            case 5:{
                setModeOff(right,down,left);
                up = true;
                std::cout<<"\n Direction set to up...."<<std::endl;
                break;
            }
            
            case 6:{
                setModeOff(right,up,left);
                down = true;
                std::cout<<"\n Direction set to Down...."<<std::endl;
                break;
            }
                
            case 7:{
                int value ;
                std::cout<<"Enter the value to move: "<<std::endl;
                std::cin>>value;
                if(right == true) {
                    moveRight(arr, curr_row, curr_col, value, writeMode);
                }
                else if(left == true) {
                    moveLeft(arr, curr_row, curr_col, value, writeMode);
                }
                else if(up == true) {
                    moveUp(arr, curr_row, curr_col, value, writeMode);
                }
                else {
                    moveDown(arr, curr_row, curr_col, value, writeMode);
                }
                break;
            }

            case 8:{
                printArray(arr);
                break;
            }

            case 9:{
                std::cout<<"Current position is "<<curr_row<<" "<<curr_col<<std::endl;
                break;
            }

            case 10:{
                std::cout<<"Thank you dor playing the game...."<<std::endl;
                return 0;
            }

            default :{
                std::cout<<"Wrong choice .... Enter again..."<<std::endl;
            }
        }

    }while(true);
    

    return 0;
}