// Question 3: Command Queue – Linked Execution Engine

#include<iostream>

using namespace std;

// Command class
class Command{
    public:
        string name;
        int duration;
        Command(string name, int duration){
            this->name = name;
            this->duration = duration;
        }
};

// CommandNode class
class CommandNode{
    public:
        Command* cmd;
        CommandNode* next;
        CommandNode(Command* c){
            this->cmd = c;
            this->next = nullptr;
        }
};

// ### Global Function ###
// Print commands from start to end
void printQueue(CommandNode* head){
    cout<<"Current Queue: "<<endl;
    while(head != nullptr){
        cout<<"Command: "<<head->cmd->name<<"   Execution time: "<<head->cmd->duration<<"s"<<endl;
        head = head->next;
    }
};

// ### Global Function ###
// Print commands from specific reference pointer to end
void advanceQueue(CommandNode*& current){
    if(current!=nullptr){
        current = current->next;
    }
};

// Command Executor class
class CommandExecutor{
    public:
        void run(Command &c){
            cout<<"Executing Command: "<<c.name<<"   Execution Time: "<<c.duration<<"s"<<endl;
        }
};

// CommandQueue class
class CommandQueue{
    private:
        CommandNode* head;
    
    public:
        CommandQueue(){
            head = nullptr;
        }

        void enqueue(Command* c){
            CommandNode* newNode = new CommandNode(c);
            if(head==nullptr){
                head = newNode;
            }
            else{
                CommandNode* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;   
            }
        }

        void executeNext(CommandNode*& current){
            if(current==nullptr){
                cout<<"Queue is empty"<<endl;
                return;
            }
            CommandExecutor executor;
            executor.run(*current->cmd);
            advanceQueue(current);
        }

        void executeAll() {
            CommandNode* current = head;
            while (current!=nullptr) {
                executeNext(current);
            }
        }   

        void clear(){
            CommandNode* temp = head;
            while (head != nullptr) {
                CommandNode* toDelete = head;
                head = head->next;
                delete toDelete->cmd;
                delete toDelete;
            }
            head = nullptr;
        }

        CommandNode* getHead(){
            return head;
        }

};

int main(){
    Command* c1 = new Command("Start Motor", 100);
    Command* c2 = new Command("Open Valve", 50);
    Command* c3 = new Command("Stop Motor", 80);

    CommandExecutor executor;
    CommandQueue queue;

    queue.enqueue(c1);
    queue.enqueue(c2);
    queue.enqueue(c3);

    queue.executeAll();

    CommandNode* head = queue.getHead();
    printQueue(head);

    queue.executeNext(head);

    return 0;
}