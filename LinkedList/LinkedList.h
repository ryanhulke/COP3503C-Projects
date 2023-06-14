using namespace std;
template <typename T>
class LinkedList {
    struct Node {
        T data;
        Node* previous;
        Node* next;
        Node(T data, Node* previous, Node* next) {
            this->data = data;
            this->previous = previous;
            this->next = next;
        }
    };
private:
    unsigned int nodeCount = 0;
    Node* ptrToHead;
    Node* ptrToTail;
public:
    LinkedList() {
        ptrToHead = nullptr;
        ptrToTail = nullptr;
    }
    void AddHead(const T& head) {
        //Node temp = *ptrToHead;
        Node* newHead = new Node(head, this->ptrToHead, nullptr);   // passes the ptr to the old head as the next in line now
        ptrToHead->next = newHead;
        this->ptrToHead = newHead;
        nodeCount++;
    }
    void AddNodesHead(T* data, unsigned int count) {
        for (unsigned int i = count; i > 0; i--) { //  starts at last index to maintain the order
            this->AddHead(data[i - 1]);
        }
    }
    void AddTail(const T& tail) {
        Node* newTail = new Node(tail, nullptr, this->ptrToTail);
        this->ptrToTail = newTail;
        nodeCount++;
    }
    void AddNodesTail(T* data, unsigned int count) {
        for (unsigned int i = 0; i < count; i++) {
            this->AddTail(data[i]);
        }
    }
    unsigned int NodeCount() const {
        return nodeCount;
    }
    void PrintForward()const {
        Node* ptr = ptrToHead;
        while (ptr->next != nullptr) {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    void PrintReverse()const {
        Node* ptr = ptrToTail;
        cout << "hi" << endl;
        while (ptr->previous != nullptr) {
            cout << ptr->data << endl;
            ptr = ptr->previous;
        }
    }
};