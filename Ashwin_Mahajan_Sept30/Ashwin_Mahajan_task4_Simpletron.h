// Simpletron class

#ifndef SIMPLETRON_H
#define SIMPLETRON_H

class Simpletron{
    private:
        long accumulator; // special register in which information will be put before calculations
        int memory[100]; // signed int in which information will be stored in the form of words. And this words are  referenced location no
        int program_counter; // keep track of which program executing

    public:
        Simpletron();// construtor
        void loadPrograms();// take user input of programs and then store it in memory
        void executeOp(); // execute programs until no program left in memory
};

# endif