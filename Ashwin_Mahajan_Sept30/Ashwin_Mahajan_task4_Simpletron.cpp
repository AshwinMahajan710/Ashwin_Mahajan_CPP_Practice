#include<iostream>
#include"Ashwin_Mahajan_task4_Simpletron.h"
#include<cstdlib>

// Main declarations

const int READ = 10; // read word from keyboard to particular location in memory
const int WRITE = 11; // from memory to computer screen

const int LOAD = 20; // load to accumulator
const int STORE = 21;  // store word from accumulator to particular memory location

const int ADD = 30; // add words in accumulator
const int SUBTRACT = 31; // same with subtracy and other op
const int DIVIDE = 32; 
const int MULTIPLY = 33;

const int BRANCH = 40;  // branch means this will call out particular memory block
const int BRANCHNEG = 41; // branch only if accumulator is -ve
const int BRANCHZERO = 42; // branch only if accumulator is 0
const int HALT = 43; // terminate program

// constructor
Simpletron:: Simpletron(){
    for(int i=1;i<100;i++){ memory[i] = 0; }
    accumulator = 0;
    program_counter = 0;
}

void Simpletron::loadPrograms(){
    std::cout<<"Enter program instructions one by one (-999999 to terminate): "<<std::endl;
    int instruction;
    int counter = 0;
    while (true){
        std::cout<<counter<<" ? ";
        std::cin>>instruction;
        if(instruction==(-999999)) {break;}
        memory[counter++] = instruction;
    }
}

void Simpletron::executeOp(){
    while (true)
    {
        int op = memory[program_counter++];
        int memory_loc = abs(op%100);
        int instruction = abs(op/100);
        
        switch (instruction)
        {
            case READ:{
                std::cout<<"READ OPERATION: \nEnter Word: "<<std::endl;
                std::cin>>memory[memory_loc];
                std::cout<<"Operation performed successfully...value stored at location "<<memory_loc<<std::endl;
                break;
            }

            case WRITE:{
                std::cout<<"Write Operation: \nWord at memory location "<<memory_loc<<" is: "<<memory[memory_loc]<<std::endl;
                break;
            }
        
            case LOAD:{
                accumulator = memory[memory_loc];
                std::cout<<"Word at "<<memory_loc<<" loaded into accumulator successfully...."<<std::endl;
                break;
            }

            case STORE:{
                memory[memory_loc] = accumulator;
                std::cout<<"Value in accumulator stored in memory at location "<<memory_loc<<" successfully..."<<std::endl;
                break;
            }

            case ADD:{
                accumulator += memory[memory_loc];
                std::cout<<"Accumulator updated but results not written in memory.... "<<std::endl;
                break;
            }

            case SUBTRACT:{
                accumulator -= memory[memory_loc];
                std::cout<<"Accumulator updated but results not written in memory.... "<<std::endl;
                break;
            }

            case DIVIDE:{
                if(memory[memory_loc]!=0){
                    accumulator /= memory[memory_loc];
                    std::cout<<"Accumulator updated but results not written in memory.... "<<std::endl;
                }
                else{
                    std::cout<<"Cannot divide by 0.."<<std::endl;
                }
                break;
            }

            case MULTIPLY:{
                accumulator *= memory[memory_loc];
                std::cout<<"Accumulator updated but results not written in memory.... "<<std::endl;
                break;
            }

            case BRANCH:{
                std::cout<<"Program counter branced successfully to memory location: "<<memory_loc<<std::endl;
                program_counter = memory_loc;
                break;
            }

            case BRANCHNEG:{
                if(accumulator < 0){
                    std::cout<<"Program counter branced successfully to memory location: "<<memory_loc<<" as accumulator is -ve...."<<std::endl;
                    program_counter = memory_loc;
                }
                else{
                    std::cout<<"As accumulator +ve operation not branched..."<<std::endl;
                }
                break;
            }
            
            case BRANCHZERO:{
                    if(accumulator == 0){
                    std::cout<<"Program counter branced successfully to memory location: "<<memory_loc<<" as accumulator is 0...."<<std::endl;
                    program_counter = memory_loc;
                }
                else{
                    std::cout<<"As accumulator is not 0 operation not branched..."<<std::endl;
                }
                break;              
            }

            case HALT:{
                std::cout<<"\n Program Terminated Successfully....."<<std::endl;
                return ;
            }
                
            default:{
                std::cout<<"\nInvalid code..."<<std::endl;
                break;
            }
        }
        
        // condition if program counter goes out of range;
        if (program_counter < 0 || program_counter >= 100) {
            std::cout << "\n*** Program counter out of bounds. Execution terminated. ***" << std::endl;
            return;
        }
    }
}