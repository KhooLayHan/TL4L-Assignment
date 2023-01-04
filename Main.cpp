// Headers Files 
#include <array>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <thread>
#include <sstream>
#include <string>
#include <vector>

// A similar assert macro, with additional utility to print a custom-made message.
// __FILE__ and __LINE__ are C++'s built-in macros.
// __FILE__ returns the file directory of where the error is located, while __LINE__ returns the line number of the error location.
#define ASSERT(expression, message) { if (!(expression)) { std::cerr << message << ", FILE: " << __FILE__ << ", LINE: " << __LINE__; std::abort(); } }

#include "State.cpp"

// A simple Timer class that calculates duration when the program starts and when it ends.
struct Timer
{
    // using namespace std::literals::chrono_literals;

    // Uses the built-in std::chrono library to track clock timings and time utilities. 
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double> duration;

    Timer() 
    { 
        start = std::chrono::high_resolution_clock::now(); 
    }
    
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();

        duration = end - start;
        float durationMicroseconds = duration.count() * 1000.0f;

        std::cout << "Timer took " << durationMicroseconds << "ms. " << std::endl;
    }
};

// struct Node
// {
//     int32_t m_Data;
//     Node* m_Next;
// };

// class FileStream
// {
// public:
//     FileStream(std::string_view r_filepath, std::string_view w_filepath)
//         : m_ReadFilepath(r_filepath), m_WriteFilepath(w_filepath)
//     {}

//     FileStream()
//         : m_ReadFilepath("./Assignment_READ_TEST.txt"), m_WriteFilepath("./Assignment_WRITE.txt")
//     {}

//     std::string ReadLine(const std::string& filepath, int32_t lineNumber)
//     {
//         std::ifstream r_file(m_ReadFilepath, std::ios::in);
//         // if (!r_file)
//         // {
//         //     std::cerr << "HHHHH\n";
//         //     exit(-1);
//         // }

//         ASSERT(r_file, "Error: r_file couldn't be found");
//         ASSERT(lineNumber >= 1, "Error: value of lineNumber is less than 1");

//         std::string line;
//         int32_t currentLine = 0;
                
//         m_LineNumber = lineNumber;

//         while (r_file)
//         {   
//             currentLine++;
//             std::getline(r_file, line);
            
//             if (currentLine == lineNumber)
//                 break;
//         }

//         return line;  
//     }

//     std::vector<std::string> Read() //const std::string& filepath = "./Assignment_READ.txt"
//     {
//         std::ifstream r_file(m_ReadFilepath, std::ios::in);
        
//         ASSERT(r_file, "Error: r_file couldn't be found");

//         constexpr int16_t SIZE_RESERVAL = 50;
//         std::vector<std::string> lines;
//         lines.reserve(SIZE_RESERVAL);

//         std::string line;

//         while (r_file)
//         {
//             while (std::getline(r_file, line))
//             {
//                 if (lines.size() >= lines.capacity())
//                     lines.resize(SIZE_RESERVAL + lines.size());

//                 lines.push_back(line);  
//             }
//         }

//         return lines;
//     }

//     static void Write(std::string_view value, const std::string& filepath = "./Assignment_WRITE.txt")
//     {
//         std::ofstream w_file(filepath, std::ios::out | std::ios::app);
        
//         ASSERT(w_file, "Error: w_file couldn't be found");
        
//         w_file << value;
//     } 
    
//     void Write(std::string_view value)
//     {
//         std::ofstream w_file(m_WriteFilepath, std::ios::out | std::ios::app);
        
//         ASSERT(w_file, "Error: w_file couldn't be found");
        
//         w_file << value;
//     } 

//     const std::string& GetReadFilepath() const { return m_ReadFilepath; }
//     const std::string& GetWriteFilepath() const { return m_WriteFilepath; }
    
//     int32_t GetCurrentLineNumber() const { return m_LineNumber; }
    
//     int32_t GetTotalLineNumberCount() const 
//     { 
//         int32_t lineCount;

//         return 1;
//     }

// private:
//     std::string m_ReadFilepath;
//     std::string m_WriteFilepath;
//     int32_t m_LineNumber;
// };

class SortedLinkedList { // Prepared by: Ng Jun Xuan
private:
    Node* head;
    std::string m_Name;

public:
    SortedLinkedList(const std::string& name)
        : m_Name(name)
    {
        head = nullptr;
        FileStream::Write(m_Name + " constructed\n");
    }

    ~SortedLinkedList()
    {
        delete head;
        head = nullptr;
    }

    void Add(int32_t data)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->m_Data = data;

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->m_Data < data) {
          prev = current;
          current = current->m_Next;
        }

        newNode->m_Next = current;
        if (prev) {
          prev->m_Next = newNode;
        } else {
          head = newNode;
        }
        FileStream::Write(m_Name + " added " + std::to_string(data) + "\n");
    }

    void Delete(int32_t data)
    {
        if (check_empty()) {
            FileStream::Write(m_Name + " is empty\n");
            throw (m_Name + " is empty");
        }
        
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->m_Data != data) {
            prev = temp;
            temp = temp->m_Next;
        }

        if (temp == nullptr) {
            FileStream::Write("data not found\n");
        } else {
            if (prev == nullptr) {
                head = head->m_Next;
            } else {
                prev->m_Next = temp->m_Next;
            }

            delete temp;
            FileStream::Write(m_Name + " deleted " + std::to_string(data) + "\n");
        }

    }

    void Print()
    {
        for (Node* tempNode = head; tempNode != nullptr; tempNode = tempNode->m_Next){
            FileStream::Write(std::to_string(tempNode->m_Data) + " ");
        }
        FileStream::Write("\n");
    }

    bool check_empty() {
        return head == nullptr;
    }
};

class LinkedStack // Prepared by: Yap Chun Wei
{
    private:    
        Node *top;
        std::string m_Name; 

    public:
        LinkedStack(const std::string& name)
            : m_Name(name)
        {
            top = nullptr;
            FileStream::Write(m_Name + " constructed\n");
        }

        bool empty()
        {
            if (top == nullptr)
            {   
                return true;
            }
            else
            {
                return false;
            }
        }

        void push(int x)
        {
            Node* temp;
            temp = new Node;
            temp->m_Data = x;

            if (top == nullptr)
            {
                top = temp;
                top->m_Next = nullptr; 

                FileStream::Write(m_Name + " added " + std::to_string(x) + "\n");
                //cout<<"Stack added "<<x<<endl;//print the pushed number (for reference)
            }
            else
            {
                temp->m_Next = top;
                top = temp;

                FileStream::Write(m_Name + " added " + std::to_string(x) + "\n");
                //cout<<"Stack added "<<x<<endl;//print the pushed number (for reference)
            }
        }

        int pop()
        {
            int x;
            Node *temp;

            if(!empty())
            {
                x = top->m_Data;
                temp = top;
                top = top->m_Next;
                delete temp;

                FileStream::Write(m_Name + " deleted " + std::to_string(x) + "\n");
                //cout<<"Stack deleted "<<x<<endl;//print the poped number (for reference)

                return x;
            }
            else
            {
                FileStream::Write(m_Name + " is empty!!\n");
                exit(0);
            }
        }

        void print()
        {
            while(top != nullptr)
            {
                //cout<<top->data<<" ";
                FileStream::Write(std::to_string(top->m_Data) + " ");

                top = top->m_Next;
            }

            FileStream::Write("\n");
        }
};

class BinarySearchTree // Prepared by: Nico Lee Guang Yang
{
    private:
        struct tree
        {
            int data;
            tree *left;
            tree *right;
        };

        tree* root;
        std::string m_Name;

    public:
        BinarySearchTree(const std::string& name)
            : m_Name(name)
        {
            FileStream::Write(m_Name + " constructed\n");
            root = nullptr;
        }

        tree* addNode(int number) {
            tree* newNode = new tree;
            newNode->data = number;
            newNode->right = newNode->left = nullptr;
            return newNode;
        }
        
        bool treeEmpty()
        {
            return root == nullptr;
        }

        void addValue(int val)
        {
            root = insertNode(root,val);
        }

        tree* insertNode(tree* node, int val)
        {
            if (node == nullptr)
            {
                node = addNode(val);
                FileStream::Write(m_Name + " added " + std::to_string(val) + "\n");
            }
            else if (val <= node->data)
            {
                node->left = insertNode(node->left, val);
            }
            else
            {
                node->right = insertNode(node->right, val);
            }

            return node;
        }

        void deleteRoot(int datas)
        {
            FileStream::Write(m_Name + " deleted " + std::to_string(root->data) + "\n");
            root = deleteNode(root, datas);
        }

        tree* deleteNode(tree *roots, int dataS)
        {
            if(roots == nullptr)
            {
                return roots;
            }
            else if(dataS < roots->data)
            {
                roots->left = deleteNode(roots->left,dataS);
            }
            else if(dataS > roots->data)
            {
                roots->right = deleteNode(roots->right,dataS);
            }
            else
            {
                if (roots->left == nullptr && roots->right == nullptr)
                {
                    delete roots;
                    return roots = nullptr;
                }
                else if (roots->left == nullptr)
                {
                    tree *temp = roots;
                    roots = roots->right;
                    delete temp;
                }
                else if (roots->right == nullptr)
                {
                    tree *temp = roots;
                    roots = roots->left;
                    delete temp;
                }
                else
                {
                    tree* temp = findMax(roots->right);
                    roots->data = temp->data;
                    roots->right = deleteNode(roots->right,temp->data);
                }
            }
        
            return roots;
        }

        tree* findMax(tree *root)
        {
            while (root->right)
            {
                root = root->right;
            }
            return root;
        }
        
        void inorder(tree* n)
        {
            if (!n)
                return;
            
            inorder( n->left );
            FileStream::Write(std::to_string(n->data) + " ");
            inorder( n->right);
        }

        void callInorder()
        {
            inorder(root);
            FileStream::Write("\n");
        }
};
class Program
{
public:
    static void SetUpDefaults()
    {
        
    }

    static void Run()
    {

    }
};

void Begin()
{
    Timer timer;

   
   

    // Run();

    
}

int main()
{
    //Begin();   

    // LinkedStack ls("stk");
    // ls.push(11);
    // ls.push(777);
    // ls.push(55);
    // ls.push(22);
    // ls.pop();
    // ls.print();

    // SortedLinkedList sll("sll");
    // sll.Add(80);
    // sll.Add(20);
    // sll.Add(1000);
    // sll.Add(50);
    // sll.Delete(1000);
    // sll.Print();

    // EnvironmentIdBuilder id;
    // id.ParseFileIntoWordComponents();

    // FileStream filepath("./Assignment_READ.txt");
    // filepath.Read();
    
    //Timer timer;

    // Node* mainNode = nullptr;
    // LinkedList linkedList;
    
    // linkedList.AddRear(&mainNode, 10);
    // linkedList.AddRear(&mainNode, 20);
    // linkedList.AddRear(&mainNode, 100);
    // linkedList.AddRear(&mainNode, 50);

    // linkedList.Print(mainNode);

    // // // //std::cout << linkedList.Min(mainNode);
    // linkedList.Delete(mainNode, 20);
    // // // // //linkedList.Search(mainNode, 20);
    // // // // //linkedList.Search(mainNode, 100);
    
    // linkedList.Print(mainNode);

    // // Command command;

    // //command.SetCommandId(CommandMode::)

    BinarySearchTree bst("binSearchTree");
    bst.addValue(30);
    bst.addValue(50);
    bst.addValue(20);
    bst.addValue(10);
    bst.deleteRoot(30);
    bst.callInorder();
}