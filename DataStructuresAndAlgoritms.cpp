// #include "FileStream.cpp"

// struct DSAMapping
// {   
//     std::string name;
//     std::string command;
//     int32_t value;
// };
// class State
// {
// protected:
//     enum class DataStructuresAndAlgorithmsType : int16_t
//     {
//         LINKED_LIST = 0,
//         SORTED_LINKED_LIST = 1,
//         LINKED_STACK = 2,
//         BINARY_SEARCH_TREE = 3
//     };

//     using DSA = DataStructuresAndAlgorithmsType;

//     enum class CommandMode : int16_t
//     {
//         CONSTRUCTOR_CALL = 0,
//         ADD_FUNCTION_CALL = 1,
//         DELETE_FUNCTION_CALL = 2,
//         SEARCH_FUNCTION_CALL = 3,
//         MIN_FUNCTION_CALL = 4,
//         MAX_FUNCTION_CALL = 5,
//         INORDER_FUNCTION_CALL = 6,
//         PRINT_FUNCTION_CALL = 7
//     };

//     std::string m_TypeName;
//     std::string m_TypeClassName;
//     int32_t m_TypeId;

//     std::string m_CommandName;
//     int32_t m_CommandId;
//     int32_t m_CommandValue;

//     void SetDsaMode(DSA modeType, std::string_view name = " ")
//     {
//         m_TypeName = name;
//         m_Dsa.name = m_TypeName;

//         switch (modeType)
//         {
//             case DSA::LINKED_LIST:
//                 m_TypeClassName = "LinkedList";
//                 m_TypeId = 0;
//                 break;
//             case DSA::SORTED_LINKED_LIST:
//                 m_TypeClassName = "SortedLinkedList";
//                 m_TypeId = 1;
//                 break;
//             case DSA::LINKED_STACK:
//                 m_TypeClassName = "LinkedStack";
//                 m_TypeId = 2;
//                 break;
//             case DSA::BINARY_SEARCH_TREE:
//                 m_TypeClassName = "BinarySearchTree";
//                 m_TypeId = 3; 
//                 break;
//             default:
//                 m_TypeClassName = "None";
//                 m_TypeId = -1;
//                 break;
//         }

//         //return m_Name;
//     }

//     void SetCommandMode(CommandMode mode, int32_t value = 0)
//     {        
//         // m_CommandName = name;
//         // m_Dsa.command = m_CommandName;

//         m_CommandValue = value;
//         m_Dsa.value = m_CommandValue;

//         switch (mode)
//         {
//             case CommandMode::CONSTRUCTOR_CALL:
//                 m_CommandId = 0;
//                 m_CommandName = "constructor";
//                 break;
//             case CommandMode::ADD_FUNCTION_CALL:
//                 m_CommandId = 1;
//                 m_CommandName = "add";
//                 m_Dsa.command = m_CommandName;
//                 break;
//         }
//     }

// public:
//     DSAMapping m_Dsa;

//     const std::string& GetTypeName() const { return m_TypeName; }
//     const int32_t GetTypeId() const { return m_TypeId; }
//     const int32_t GetCommandId() const { return m_CommandId; }
// };