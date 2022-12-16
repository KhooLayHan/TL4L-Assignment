#include "State.cpp"

struct Node
{
    int32_t m_Data;
    Node* m_Next;
    Node* m_Previous;
};

// template <typename T>
// class Node
// {
// public:
//     T m_Data;
//     std::unique_ptr<Node> m_Next;

//     Node() = default;
//     Node(T data, std::unique_ptr<Node> next = m_Head) : m_Data(data), m_Next(next) {}

//     void GetData() const { return m_Data; }    
//     void GetNext() const { return &m_Next; }    
    
//     //Node& SetHead() { return m_Head; }    
     
// private:
//     static Node* m_Head;
// };

class LinkedListNode
{

};


//Node* Minimum(Node* a, Node* b) { return (b < a) ? b : a; }

class LinkedList
{
private:
    Node* m_Temp = nullptr;

public:
    LinkedList() 
    {
        FileStream::Write("list constructed\n");
    }

    ~LinkedList()
    {
        delete m_Temp;
        m_Temp = nullptr;
    }

    void AddRear(Node** head, int32_t data)
    {     
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->m_Data = data;
        newNode->m_Next = nullptr;

        if (*head != nullptr)
        {
            
            Node* tempNode = *head;
            
            while (tempNode->m_Next != nullptr)
                tempNode = tempNode->m_Next;
            
            tempNode->m_Next = newNode;

            FileStream::Write("list added " + std::to_string(data) + "\n");
            printf("DDDDD\n");
        }
        else
        {
            *head = newNode;
            FileStream::Write("list added " + std::to_string(data) + "\n");
        }
    }

    int32_t Min(Node* head)
    {
        int32_t minNode = 0;

        if (head != nullptr)
        {
            Node* tempNode = head;
           
            // for (Node* tempNode = head; tempNode->m_Next != nullptr; tempNode = tempNode->m_Next)
            // {
            //     // if (Node* minNode = Minimum(tempNode, tempNode->m_Next))
            //     //     std::cout << minNode->m_Data << "\n";
            while (tempNode->m_Next != nullptr)
            {
                if (tempNode->m_Next->m_Data < tempNode->m_Data)
                {
                    //empNode = tempNode->m_Next;
                    minNode = tempNode->m_Next->m_Data;
                }
                else
                    minNode = tempNode->m_Data;

                tempNode = tempNode->m_Next;
            }
                
            
           // }
        }

        return minNode;
    }

    void Max(Node** head)
    {

    }

    void Delete(Node* head, int32_t data)
    {
        Node* deleteNode = nullptr;
        for (Node* tempNode = head; tempNode->m_Next != nullptr; tempNode = tempNode->m_Next)
        {
            if (tempNode->m_Data == data)
            {
                deleteNode = tempNode;
                tempNode = tempNode->m_Next;
                delete deleteNode;

                FileStream::Write("list deleted " + std::to_string(data) + "\n");

                if (tempNode->m_Next == nullptr)
                    break;
            }
            else
            {
                //std::cout << "list " << tempNode->m_Data << " not found\n";
            }
        }
    }

    void Search(Node* head, int32_t data)
    {
        for (Node* tempNode = head; tempNode->m_Next != nullptr; tempNode = tempNode->m_Next)
        {
            if (tempNode->m_Data != data)
            {
                if (tempNode->m_Data == data)
                {
                    std::cout << "found " << data << "\n";
                    break;
                }

                Search(tempNode, data);
            }
           
        }
        
        std::cout << "not found " << data << "\n";
    }

    void Print(Node* head)
    {
        for (Node* tempNode = head; tempNode != nullptr; tempNode = tempNode->m_Next)
            FileStream::Write(std::to_string(tempNode->m_Data) + " ");
        
        FileStream::Write("\n");
    }
};