#include<iostream>

using namespace std;

class Queue{
    private:
        struct QueueNode
        {
            Candidate candidate;
            QueueNode* next;
        };
        
        QueueNode* front;
        QueueNode* rear;
        int numItems;

    public:
    //Constructor
    Queue() : front(nullptr), rear(nullptr), numItems(0) {}

    //Destructor
    ~Queue() {clear();}

    //Destroy Queue
    void enQueue(const Candidate& item){
        QueueNode* newNode = new QueueNode;
        newNode->candidate = item;
        newNode->next = nullptr;

        if(isEmpty()){
            front = newNode;
            rear = newNode;
        } else{
            rear->next = newNode;
            rear = newNode;
        }
        numItems++;
    }

    void deQueue(Candidate& item){
        QueueNode* temp = nullptr;

        if (isEmpty()){
            cout << "The queue is empty.\n";
        } else{
            item = front->candidate;
            temp = front;
            front = front->next;
            delete temp;
            numItems--;
            if(front == nullptr){
                rear = nullptr;
            }
        }
    }

    bool isEmpty() const{
        return numItems == 0;
    }

    void clear(){
        Candidate candidate;
        while (!isEmpty()){
            deQueue(candidate);
        }
    }
};

int main (){

    return 0;
}
