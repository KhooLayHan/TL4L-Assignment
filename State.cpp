#include "UtilityHeaders.cpp"

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
        LINKED_STACK = 3,
        BINARY_SEARCH_TREE = 4,
        MAX_SIZE = 5
    };

    using DSA = DataStructuresAndAlgorithmsType;

protected:
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

private:
    std::string m_Name; 
};

class Command
{
public:
    enum class CommandMode : int16_t
    {
        CONSTRUCTOR_CALL = 0,
        FUNCTION_CALL = 1
    };

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

private:
    int32_t m_Id;
};