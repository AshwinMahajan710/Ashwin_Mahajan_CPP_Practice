#ifndef ACTUATOR_H
#define ACTUATOR_H

#include<string>

class Actuator{
    private:
        int id;
        std::string state;
        int responseTime;

    public:
        Actuator(int id, std::string state, int responseTime);
        void triggerAction();

        // Get status
        std::string getStatus() const;

        // printInfo for actuator
        void printInfo() const;
};

#endif