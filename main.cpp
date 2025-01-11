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

   
    void assignInterviewSlot() {
        if (isEmpty()) {
            cout << "No candidates in the queue to assign an interview slot.\n";
        } else {
            cout << "Interview slot assigned to the first candidate in the queue.\n";
            front->candidate.display();
        }
    }

    int getTotalInterviewees() const {
        return numItems;
    }

      void viewCurrentQueue() const {
        if (isEmpty()) {
            cout << "The queue is empty.\n";
        } else {
            QueueNode* current = front;
            cout << "Current queue of interviewees: \n";
            while (current != nullptr) {
                current->candidate.display();
                current = current->next;
            }
        }
    }

};

  


int main (){

    return 0;
}
