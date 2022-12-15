#include "FileStream.cpp"

// Sample
// {
//     "LinkedList": {
//         "name": "list",
//         "command": "add",
//         "value": 10
//     }
// }

template <typename Mode>
struct DSAMapping
{   
    std::string m_Name;
    std::string m_Command;
    int32_t m_Value;
};

class Mode
{
public:
    enum class DataStructuresAndAlgorithmsType
    {
        LINKED_LIST = 0,
        SORTED_LINKED_LIST = 1,
        LINKED_STACK = 2,
        BINARY_SEARCH_TREE = 3,
    };

    using DSA = DataStructuresAndAlgorithmsType;

public:
    void SetModeType(DSA modeType)
    {
        switch (modeType)
        {
            case DSA::LINKED_LIST:
                m_Name = "LinkedList";
                m_Id = 0;
                break;
            case DSA::SORTED_LINKED_LIST:
                m_Name = "SortedLinkedList";
                m_Id = 1;
                break;
            case DSA::LINKED_STACK:
                m_Name = "LinkedStack";
                m_Id = 2;
                break;
            case DSA::BINARY_SEARCH_TREE:
                m_Name = "BinarySearchTree";
                m_Id = 3; 
                break;
            default:
                m_Name = "None";
                m_Id = -1;
                break;
        }

        //return m_Name;
    }

    void CheckMode()
    {
        std::string line = m_Filepath.ReadLine("./Assignment_READ.txt");
        
        if (line == "LinkedList list")
        {
            std::cout << m_Name << " " << m_Id << "\n";
            SetModeType(DSA::LINKED_LIST);
        }
        else if (line == "SortedLinkedList sortedList")
        {
            SetModeType(DSA::SORTED_LINKED_LIST);
        }
        else if (line == "LinkedStack stack")
        {
            SetModeType(DSA::LINKED_STACK);
        }
        else if (line == "BinarySearchTree bst")
        {
            SetModeType(DSA::BINARY_SEARCH_TREE);
        }
    }

    const std::string& GetName() const { return m_Name; }
    const int32_t GetId() const { return m_Id; }

private:
    std::string m_Name; 
    int32_t m_Id;

    FileStream m_Filepath;
};

class Command
{
public:
    enum class CommandMode : int16_t
    {
        CONSTRUCTOR_CALL = 0,
        FUNCTION_CALL = 1
    };

    void SetCommandId(CommandMode mode)
    {
        switch (mode)
        {
            case CommandMode::CONSTRUCTOR_CALL:
                m_Id = 0;
                break;
            case CommandMode::FUNCTION_CALL:
                m_Id = 1;
                break;
        }
    }

private:
    int32_t m_Id;
};