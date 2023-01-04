#include "LinkedList.cpp"

#include <tuple>

// struct Helper
// {
//     std::string first;
//     int32_t second;
// };

// std::tuple<std::string, int32_t> SplitIntoWords(const std::string& line)
// {
//     std::stringstream ss(line);
//     std::string firstWord, secondWord, thirdWord;

//     ss >> firstWord >> secondWord >> thirdWord;
//     std::cout << firstWord << " " << secondWord << " " << thirdWord << "\n";

//     int32_t value;
//     if (!thirdWord.empty())
//         value = std::stoi(thirdWord);    

//     return { secondWord, value };
// };

// Sample
// {
//     "LinkedList": {
//         "name": "list",
//         "command": "add",
//         "value": 10
//     }
// }




    // Mode() = delete;
    // Mode(const Mode&) = delete;
    // Mode(Mode&&) = delete;
    // Mode operator=(const Mode&) = delete;

// private:
//     std::string m_ModeName; 
//     int32_t m_ModeId;


// class Command : public State
// {
// public:
    

// private:
//     int32_t m_Id;
// };

class EnvironmentIdBuilder : public Environment
{
public:
    std::vector<DataStructureAndAlgorithms> GetEnvironmentComponents()
    {
        std::vector<DataStructureAndAlgorithms> components;

        for (int row = 0; row != m_Environment.GetSize(); ++row)
        {
            components.push_back({ m_Environment.GetDsa(row) });
        }

        return components;
    }

    void ParseFileIntoWordComponents()
    {
        std::vector<std::string> lines = m_Filepath.Read();

        std::string firstWord, secondWord, thirdWord;
        std::stringstream ss;
        
        for (int i = 0; !lines.empty(); i++)
        {
            if (lines.empty())
            {
                std::cout << lines[i].back() ;
                break;
            }
            
            ss << lines[i];
            ss >> firstWord >> secondWord >> thirdWord;
            
            if (firstWord == "LinkedList" || firstWord == "SortedLinkedList" || 
                firstWord == "LinkedStack" || firstWord == "BinarySearchTree")
                ActivateEnvironment(firstWord, secondWord);
            else
                ActivateEnvironmentCommand(firstWord, secondWord, std::stoi(thirdWord));

            ss.clear();
            
            // if (secondWord == "print" || secondWord == "inorder") // Assuming both two commands will only be read and write once.
            //     break;
        }
    }

    void ActivateEnvironmentCommand(const std::string& name, const std::string& command, int32_t value)
    {
        if (command == "add")
        {
            m_Environment.SetDsaEnvironmentCommand(Environment::CommandMode::ADD_FUNCTION_CALL, value);
        }
        else if (command == "min")
        {
            m_Environment.SetDsaEnvironmentCommand(Environment::CommandMode::MIN_FUNCTION_CALL);
        }
        else if (command == "max")
        {
            m_Environment.SetDsaEnvironmentCommand(Environment::CommandMode::MAX_FUNCTION_CALL);
        }
        else if (command == "delete")
        {
            m_Environment.SetDsaEnvironmentCommand(Environment::CommandMode::DELETE_FUNCTION_CALL, value);
        }
        else if (command == "search")
        {
            m_Environment.SetDsaEnvironmentCommand(Environment::CommandMode::SEARCH_FUNCTION_CALL, value);
        }
        else if (command == "print")
        {
            m_Environment.SetDsaEnvironmentCommand(Environment::CommandMode::PRINT_FUNCTION_CALL); 
        }
        else if (command == "inorder")
        {
            m_Environment.SetDsaEnvironmentCommand(Environment::CommandMode::INORDER_FUNCTION_CALL);
        }
    }

    void ActivateEnvironment(const std::string& className, const std::string& name)
    {
        if (className == "LinkedList")
        {
            m_Environment.SetDsaEnvironment(Environment::DSA::LINKED_LIST, name);
            //std::cout << m_TypeName << " " << m_TypeId << " "<< m_TypeClassName << "\n";
        }
        else if (className == "SortedLinkedList")
        {
            m_Environment.SetDsaEnvironment(Environment::DSA::SORTED_LINKED_LIST, name);
        }
        else if (className == "LinkedStack")
        {
            m_Environment.SetDsaEnvironment(Environment::DSA::LINKED_STACK, name);
        }
        else if (className == "BinarySearchTree")
        {
            m_Environment.SetDsaEnvironment(Environment::DSA::BINARY_SEARCH_TREE, name);
        }
    }

    void SetState()
    {
        std::vector<std::string> lines = m_Filepath.Read();

        int32_t wordCountPerLine = 0;
        
        
        // std::cout << lines << '\n';

        // int32_t wordCountPerLine = 0;

        std::string first_word, second_word, third_word;
        std::stringstream ss;
        
        for (int i = 0; i != 10; i++)
        {
            ss << lines[i];
            ss >> first_word >> second_word >> third_word;
            //std::cout << lines[i] << "\n";
            if (third_word == "")
            {
                wordCountPerLine = 2;
                ActivateEnvironment(first_word, second_word);
            }
            else
            {
                wordCountPerLine = 3;
                ActivateEnvironmentCommand(first_word, second_word, std::stoi(third_word));
            }

            ss.clear();

            // while (ss >> first_word)
            // {
            //     wordCountPerLine++;

            //     if (wordCountPerLine == 3)

            // }
        }


        // while (!lines.empty())
        // {   
        //     ss >> first_word >> second_word >> third_word;
            
        // }
        

        // std::cout << first_word << second_word << third_word << '\n';
    }

    // void ActivateEnvironmentCommand(const std::string& name, const std::string& command, int32_t value)
    // {
    //     if (command == "add")
    //     {
    //         m_Environment.SetCommandMode(Environment::CommandMode::ADD_FUNCTION_CALL, value);
            
    //         switch (m_Environment.GetTypeId())
    //         {
    //             case 1:
    //                 LinkedList::AddRear(&mainNode, value);
    //                 break;
    //             case 2:
    //                 break;
    //             case 3:
    //                 break;
    //             case 4:
    //                 break;
    //         }
    //     }
    //     else if (command == "min")
    //     {
    //         m_Environment.SetCommandMode(Environment::CommandMode::MIN_FUNCTION_CALL);
            
    //     }
    //     else if (command == "max")
    //     {
    //         m_Environment.SetCommandMode(Environment::CommandMode::MAX_FUNCTION_CALL);
    //     }
    //     else if (command == "delete")
    //     {
    //         m_Environment.SetCommandMode(Environment::CommandMode::DELETE_FUNCTION_CALL, value);
    //     }
    //     else if (command == "search")
    //     {
    //         m_Environment.SetCommandMode(Environment::CommandMode::SEARCH_FUNCTION_CALL, value);
    //     }
    //     else if (command == "print")
    //     {
    //         m_Environment.SetCommandMode(Environment::CommandMode::PRINT_FUNCTION_CALL); 
    //     }
    //     else if (command == "inorder")
    //     {
    //         m_Environment.SetCommandMode(Environment::CommandMode::INORDER_FUNCTION_CALL);
    //     }
    // }

    // void ActivateEnvironment(const std::string& first, const std::string& second)
    // {
    //     if (first == "LinkedList")
    //     {
    //         m_Environment.SetDsaMode(Environment::DSA::LINKED_LIST, second);
    //         //std::cout << m_TypeName << " " << m_TypeId << " "<< m_TypeClassName << "\n";
    //     }
    //     else if (first == "SortedLinkedList")
    //     {
    //         m_Environment.SetDsaMode(Environment::DSA::SORTED_LINKED_LIST, second);
    //     }
    //     else if (first == "LinkedStack")
    //     {
    //         m_Environment.SetDsaMode(Environment::DSA::LINKED_STACK, second);
    //     }
    //     else if (first == "BinarySearchTree")
    //     {
    //         m_Environment.SetDsaMode(Environment::DSA::BINARY_SEARCH_TREE, second);
    //     }
    // }

    // void CheckState()
    // {
    //     std::string line = m_Filepath.ReadLine("./Assignment_READ.txt", 1);
        
    //     std::cout << line << "\n";

    //     std::stringstream ss(line);
    //     std::string first_word, second_word, third_word;

    //     ss >> first_word >> second_word >> third_word;
    //     //std::cout << first_word << " " << second_word << " " << third_word << "\n";

    //     bool lineChecker = line == (first_word + " " + second_word + " ");

    //     if (first_word == "LinkedList" && lineChecker)
    //     {
    //         SetDsaMode(DSA::LINKED_LIST, second_word);
    //         //std::cout << m_TypeName << " " << m_TypeId << " "<< m_TypeClassName << "\n";
            
    //         ActivateLinkedListState();
    //     }
    //     else if (first_word == "SortedLinkedList sortedList ")
    //     {
    //         SetDsaMode(DSA::SORTED_LINKED_LIST, second_word);
    //     }
    //     else if (first_word == "LinkedStack stack ")
    //     {
    //         SetDsaMode(DSA::LINKED_STACK, second_word);
    //     }
    //     else if (first_word == "BinarySearchTree bst ")
    //     {
    //         SetDsaMode(DSA::BINARY_SEARCH_TREE, second_word);
    //     }
    // }

protected:
    // void ActivateLinkedListState()
    // {
    //         int i = 0;
    //     while (!m_State)
    //     {
    //         // 1. set cursor pointer to move to \n
    //         // 2. read line and get data, and retrieve it for setCommandMode();
    //         // 3. Pass the values to related data (DSAMapping, etc.)

    //         // std::vector<std::string> gg;
    //         // gg.push_back(line);
    //         // std::cout << gg[i++] << "\n";

    //         std::vector<std::string> lines = m_Filepath.Read();
            
    //         std::cout << lines[0] << "\n";

    //         //std::string line = m_Filepath.ReadNextLine(lineNumberOffset + 1); // 1 as the starting line for LinkedList
            
    //         for (int i = 0; !lines.empty(); i++)
    //         {
    //             std::stringstream ss(lines[i]);
    //             std::string firstWord, secondWord, thirdWord;

    //             ss >> firstWord >> secondWord >> thirdWord;
    //             std::cout << firstWord << " " << secondWord << " " << thirdWord << "\n";

    //             int32_t value;
    //             if (!thirdWord.empty())
    //                 value = std::stoi(thirdWord);    

    //             // auto [command, value] = SplitIntoWords(lines[i]); 
    //             ExecuteCommand(secondWord, value);

    //             if (secondWord == "print" || secondWord == "inorder")
    //                 break;
    //         }

    //         m_State = true;
    //     }
    // }

    // void ExecuteCommand(const std::string& command, int32_t value)
    // {
    //     if (command == "add")
    //     {
    //         SetCommandMode(CommandMode::ADD_FUNCTION_CALL, value);
    //         //std::cout << m_CommandId << " " << m_CommandName << " " << m_CommandValue << "\n";
    //     }
    //     else if (command == "min")
    //     {
    //         SetCommandMode(CommandMode::MIN_FUNCTION_CALL);
    //     }
    //     else if (command == "max")
    //     {
    //         SetCommandMode(CommandMode::MAX_FUNCTION_CALL);
    //     }
    //     else if (command == "delete")
    //     {
    //         SetCommandMode(CommandMode::DELETE_FUNCTION_CALL, value);
    //     }
    //     else if (command == "search")
    //     {
    //         SetCommandMode(CommandMode::SEARCH_FUNCTION_CALL, value);
    //     }
    //     else if (command == "print")
    //     {
    //         SetCommandMode(CommandMode::PRINT_FUNCTION_CALL); 
    //     }
    //     else if (command == "inorder")
    //     {
    //         SetCommandMode(CommandMode::INORDER_FUNCTION_CALL);
    //     }
    // }

private:
    Environment m_Environment;

    FileStream m_Filepath;
    //DSAMapping m_Dsa;

    const std::string filepath = "./Assignment_READ.txt";

    bool m_State = false;
    int32_t lineNumberOffset = 1;

    Node* mainNode = nullptr;

    std::vector<int32_t> m_EnvironmentIdBuilder;
};
