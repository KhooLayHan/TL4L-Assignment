#include "LinkedList.cpp"

class Mode
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
    int32_t m_Id; 
    std::string m_Name;

public:
    int32_t SetModeType(DSA modeType)
    {
        switch (modeType)
        {
            case DSA::LINKED_LIST:
                m_Id = 0;
                m_Name = "LinkedList";
                break;
            case DSA::SORTED_LINKED_LIST:
                m_Id = 1;
                m_Name = "SortedLinkedList";
                break;
            case DSA::LINKED_STACK:
                m_Id = 2;
                m_Name = "LinkedStack";
                break;
            case DSA::BINARY_SEARCH_TREE:
                m_Id = 3;
                m_Name = "BinarySearchTree";
                break;
            default:
                m_Id = 4;
                m_Name = "None";
                break;
        }

        return m_Id;
    }

    const std::string& GetName() const { return m_Name; }
};


class Command
{
private:
    enum class CommandMode : int16_t
    {
        CONSTRUCTOR_CALL = 0,
        FUNCTION_CALL = 1
    };

    int32_t m_Id;

public:
    int32_t SetCommandId(CommandMode mode)
    {
        int16_t id = static_cast<int16_t>(mode);

        switch (id)
        {
            case 0:
                m_Id = id;
                break;
            case 1:
                m_Id = id;
                break;
        }

        return m_Id;
    }
};

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
    
    Begin();

    Node* mainNode = nullptr;
    LinkedList linkedList;
    
    linkedList.AddRear(&mainNode, 10);
    linkedList.AddRear(&mainNode, 20);
    linkedList.AddRear(&mainNode, 100);
    linkedList.AddRear(&mainNode, 50);

    linkedList.Print(mainNode);

    // //std::cout << linkedList.Min(mainNode);
    linkedList.Delete(mainNode, 20);
    // //linkedList.Search(mainNode, 20);
    // //linkedList.Search(mainNode, 100);
    
    linkedList.Print(mainNode);

    // Command command;

    //command.SetCommandId(CommandMode::)
}