#include<iostream>
using namespace std;
struct Candidate {
    string name;
    int id;
    int age;
    int slot;
    string status;
    Candidate *next;
};

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
        // Assuming candidate has member variables `name` and `id`.
        cout << "Candidate Name: " << front->candidate.name << "\n";
        cout << "Candidate ID: " << front->candidate.id << "\n";
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
            cout << "Candidate Name: " << current->candidate.name << "\n";
            cout << "Candidate ID: " << current->candidate.id << "\n";
            current = current->next;
            }
        }
    }
};

int main() {
    Queue interviewQueue;
    int choice;
    int nextId = 1001; 
    
    do {
        cout << "\n=== Interview Queue Management System ===\n";
        cout << "1. Add New Candidate\n";
        cout << "2. Process Next Candidate\n";
        cout << "3. Assign Interview Slot\n";
        cout << "4. View Current Queue\n";
        cout << "5. View Total Candidates\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                Candidate newCandidate;
                cin.ignore(); 
                
                cout << "Enter candidate name: ";
                getline(cin, newCandidate.name);
                
                newCandidate.id = nextId++;
                cout << "Assigned ID: " << newCandidate.id << endl;
                
                cout << "Enter candidate age: ";
                cin >> newCandidate.age;
                
                do {
                    cout << "Enter preferred slot (1-5): ";
                    cin >> newCandidate.slot;
                    if (newCandidate.slot < 1 || newCandidate.slot > 5) {
                        cout << "Invalid slot! Please enter a number between 1 and 5.\n";
                    }
                } while (newCandidate.slot < 1 || newCandidate.slot > 5);
                
                newCandidate.status = "Waiting";
                newCandidate.next = nullptr;
                
                interviewQueue.enQueue(newCandidate);
                cout << "Candidate added successfully!\n";
                system("cls");
                break;
            }
            
            case 2: {
                Candidate processedCandidate;
                if (!interviewQueue.isEmpty()) {
                    interviewQueue.deQueue(processedCandidate);
                    cout << "Processing candidate:\n";
                    cout << "ID: " << processedCandidate.id << endl;
                    cout << "Name: " << processedCandidate.name << endl;
                    cout << "Age: " << processedCandidate.age << endl;
                    cout << "Slot: " << processedCandidate.slot << endl;
                }
                system("cls");
                break;
            }
            
            case 3: {
                interviewQueue.assignInterviewSlot();
                break;
            }
            
            case 4: {
                interviewQueue.viewCurrentQueue();
                break;
            }
            
            case 5: {
                cout << "Total candidates in queue: " 
                     << interviewQueue.getTotalInterviewees() << endl;
                break;
            }
            
            case 6: {
                cout << "Exiting program. Goodbye!\n";
                break;
            }
            
            default: {
                cout << "Invalid choice! Please try again.\n";
                system("cls");
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
