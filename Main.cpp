#include "LinkedList.cpp"

void Begin()
{
private:
    enum class DataStructuresAndAlgorithmsType
    {
        LINKED_LIST = 0,
        SORTED_LINKED_LIST = 1,
        LINKED_STACK = 3,
        BINARY_SEARCH_TREE = 4,
        MAX_SIZE = 5
    };

    using DSA = DataStructuresAndAlgorithmsType;
    std::string m_Name; 

public:
    std::string_view SetModeType(DSA modeType)
    {
        switch (modeType)
        {
            case DSA::LINKED_LIST:
                m_Name = "LinkedList";
                break;
            case DSA::SORTED_LINKED_LIST:
                m_Name = "SortedLinkedList";
                break;
            case DSA::LINKED_STACK:
                m_Name = "LinkedStack";
                break;
            case DSA::BINARY_SEARCH_TREE:
                m_Name = "BinarySearchTree";
                break;
            default:
                m_Name = "None";
                break;
        }

        return m_Name;
    }

    const std::string& GetName() const { return m_Name; }
};

    
}

int GetSomethin()
{
    return 10;
}

void Begin()
{
    //FileStream::Read("./Assignment.txt");

    FileStream filepath("./Assignment_READ.txt");
    filepath.Read();

    if ()
}

int main()
{
    

    // FileStream filepath("./Assignment_READ.txt");
    // filepath.Read();
    
    Node* mainNode = nullptr;
    LinkedList linkedList;
    
    // linkedList.AddRear(&mainNode, 10);
    // linkedList.AddRear(&mainNode, 20);
    // linkedList.AddRear(&mainNode, 100);
    // linkedList.AddRear(&mainNode, 50);

    // linkedList.Print(mainNode);

    // // //std::cout << linkedList.Min(mainNode);
    // linkedList.Delete(mainNode, 20);
    // // //linkedList.Search(mainNode, 20);
    // // //linkedList.Search(mainNode, 100);
    
    // linkedList.Print(mainNode);

    // // Command command;

    // //command.SetCommandId(CommandMode::)
}