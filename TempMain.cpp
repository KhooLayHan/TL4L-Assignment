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

// A similar assert macro, with additional utility to print a custom-made message
#define ASSERT(expression, message) { if (!(expression)) { std::cerr << message << ", FILE: " << __FILE__ << ", LINE: " << __LINE__; std::abort(); } }

class FileStream
{
public:
    FileStream(std::string_view filepath)
        : m_Filepath(filepath)
    {}

    FileStream() : m_Filepath("./Assignment_READ_TEST.txt") {}

    // static void Read(const std::string& filepath = "./Assignment_READ.txt")
    // {
    //     std::ifstream r_file(filepath, std::ios::in);
    //     if (!r_file)
    //     {
    //         std::cerr << "GGGG\n";
    //         return; 
    //     }

    //     while (r_file)
    //     {
    //         std::string line;

    //         while (std::getline(r_file, line))
    //         {
    //             std::size_t offset = 0;
    //             std::size_t whitespacePos = line.find(" ");

    //             while (whitespacePos != std::string::npos)
    //             {
    //                 std::string word = line.substr(offset, whitespacePos - offset);
    //                 std::cout << word << "\n";

    //                 offset = ++whitespacePos;
    //                 whitespacePos = line.find(" ", whitespacePos);
                    
    //                 if (whitespacePos == std::string::npos)
    //                     break;
    //             }
    //         }
    //     }
    // }

    // static void ReadLine(const std::string& filepath = "./Assignment_READ.txt")
    // {
    //     std::ifstream r_file(filepath, std::ios::in);
    //     if (!r_file)
    //     {
    //         std::cerr << "HHHHH\n";
    //         return;
    //     }

    //     std::string line;
    //     m_Line = line;
    //     std::getline(r_file, line);
    //     std::cout << line << "\n";  
    // }

    std::string ReadLine(const std::string& filepath, int32_t lineNumber)
    {
        std::ifstream r_file(m_Filepath, std::ios::in);
        // if (!r_file)
        // {
        //     std::cerr << "HHHHH\n";
        //     exit(-1);
        // }

        ASSERT(r_file, "FileNotFoundError: r_file couldn't be found.");
        ASSERT(lineNumber >= 1, "LineNotFoundError: lineNumber couldn't be found.");

        std::string line;
        int32_t currentLine = 0;
                
        m_LineNumber = lineNumber;

        while (r_file)
        {   
            currentLine++;
            std::getline(r_file, line);
            
            if (currentLine == lineNumber)
                break;
        }

        

        return line;  
    }

    std::string ReadNextLine(int32_t lineNumber = 2, const std::string& filepath = "./Assignment_READ.txt")
    {
        std::ifstream r_file(m_Filepath, std::ios::in);

        ASSERT(r_file, "FileNotFoundError: r_file does not exist");
        ASSERT(lineNumber >= 1, "LineNotFoundError: lineNumber doesn't exist");
        
        std::string line;
        int32_t currentLine = 0;
                
        //m_LineNumber = lineNumber;

        while (r_file)
        {   
            currentLine++;
            std::getline(r_file, line);
           
            if (currentLine == lineNumber)
                break;
        }

        return line;  
    }

    std::vector<std::string> Read() //const std::string& filepath = "./Assignment_READ.txt"
    {
        std::ifstream r_file(m_Filepath, std::ios::in);
        
        ASSERT(r_file, "FileNotFoundError: r_file couldn't be found.");

        constexpr int16_t SIZE_RESERVAL = 50;
        std::vector<std::string> lines;
        lines.reserve(SIZE_RESERVAL);

        std::string line;

        while (r_file)
        {
            while (std::getline(r_file, line))
            {
                if (lines.size() >= lines.capacity())
                    lines.resize(SIZE_RESERVAL + lines.size());

                lines.push_back(line);  
            }
        }

        return lines;

        // std::ifstream r_file(m_Filepath, std::ios::in);
        // if (!r_file)
        // {
        //     std::cerr << "GGGG\n";
        //     return; 
        // }

        // while (r_file)
        // {
        //     std::string line;

        //     while (std::getline(r_file, line))
        //     {
        //         std::size_t offset = 0;
        //         std::size_t whitespacePos = line.find(" ");

        //         int row = 0, column = 0;

        //         while (whitespacePos != std::string::npos)
        //         {    
        //             std::string words[32][5];
        //             //std::string word;
        //             // for (int i = 0; i != 31; i++) // Total row lines in Assignment_READ
        //             // {
        //             //     for (int j = 0; j != 5; )
        //             // }
        //             words[row][column] = line.substr(offset, whitespacePos - offset);
        //             //word = line.substr(offset, whitespacePos - offset);
        //             std::cout << words[row][column] << " ";
        //             //std::cout << word << "\n";
        //             column++;

        //             // if (line == "LinkedList list")
        //             // {
        //             //     m_DSA.m_Name = "list";
        //             //     m_DSA.m_Command = 
        //             // }

        //             // if (word == 'LinkedList' || )

        //             offset = ++whitespacePos;
        //             whitespacePos = line.find(" ", whitespacePos);
                    
        //             if (whitespacePos == std::string::npos)
        //             {
        //                 std::cout << "\n";
        //                 row++;
        //                 break;
        //             }
        //         }
        //     }
        // }
    }

    static void Write(std::string_view value, const std::string& filepath = "./Assignment_WRITE.txt")
    {
        std::ofstream w_file(filepath, std::ios::out | std::ios::app);
        if (!w_file)
        {
            std::cerr << "FFFF\n";
            return; 
        }
        
        w_file << value;
    } 

    const std::string& GetFilepath() const { return m_Filepath; }
    const std::string& GetCurrentLine() const { return m_Line; }
    const std::string& GetCurrentWord() const { return m_Word; }
    
    int32_t GetCurrentLineNumber() const { return m_LineNumber; }
  
    //int32_t GetCursorPosition() const { return m_CursorPosition; } 

private:
    std::string m_Filepath;
    std::string m_Line = "";
    std::string m_Word = "";

    std::fstream file;

    int32_t m_LineNumber;
};

// struct EnvironmentImpl
// {  
//     std::string m_Id;
//     std::string m_ClassName;
//     std::string m_Name;
//     std::vector<std::string> m_Command;
//     std::vector<int32_t> m_Value;
// };

struct DataStructureAndAlgorithms
{  
    std::string m_Id;
    std::string m_ClassName;
    std::string m_Name;
    std::vector<std::string> m_Command;
    std::vector<int32_t> m_Value;
};

class Environment
{
public:
    ~Environment()
    {
        int j = 0;

        for (int i = 0; i != m_DSA.size(); i++)
        {
            std::cout << "\n" << m_DSA[j].m_Id << ", " << m_DSA[j].m_ClassName
                << m_DSA[j].m_Name << m_DSA[j].m_Command[i] << m_DSA[j].m_Value[i]; 
        }
    }

    enum class DataStructuresAndAlgorithmsType : int16_t
    {
        LINKED_LIST = 1,
        SORTED_LINKED_LIST = 2,
        LINKED_STACK = 3,
        BINARY_SEARCH_TREE = 4
    };

    using DSA = DataStructuresAndAlgorithmsType;

    enum class CommandMode : int16_t
    {
        ADD_FUNCTION_CALL = 1,
        DELETE_FUNCTION_CALL = 2,
        SEARCH_FUNCTION_CALL = 3,
        MIN_FUNCTION_CALL = 4,
        MAX_FUNCTION_CALL = 5,
        INORDER_FUNCTION_CALL = 6,
        PRINT_FUNCTION_CALL = 7
    };

public:
    void SetDsaEnvironment(DSA modeType, const std::string& name = "???")
    {
        m_DSA[environmentIndex].m_Name = name;
        
        switch (modeType)
        {
            case DSA::LINKED_LIST:
                m_DSA[environmentIndex].m_ClassName = "LinkedList";
                m_DSA[environmentIndex].m_Id = "1";
                break;
            case DSA::SORTED_LINKED_LIST:
                m_DSA[environmentIndex].m_ClassName = "SortedLinkedList";
                m_DSA[environmentIndex].m_Id = "2";
                break;
            case DSA::LINKED_STACK:
                m_DSA[environmentIndex].m_ClassName = "LinkedStack";
                m_DSA[environmentIndex].m_Id = "3";
                break;
            case DSA::BINARY_SEARCH_TREE:
                m_DSA[environmentIndex].m_ClassName = "BinarySearchTree";
                m_DSA[environmentIndex].m_Id = "4"; 
                break;
            default:
                m_DSA[environmentIndex].m_ClassName = "None";
                m_DSA[environmentIndex].m_Id = "-1";
                break;
        }
    }

    void SetDsaEnvironmentCommand(CommandMode mode, int32_t value = 0)
    {        
        m_DSA[environmentIndex].m_Value.push_back(value);

        switch (mode)
        {
            case CommandMode::ADD_FUNCTION_CALL:
                m_DSA[environmentIndex].m_Command.push_back("add");
                m_DSA[environmentIndex].m_Id += "1"; 
                break;
            case CommandMode::DELETE_FUNCTION_CALL:
                m_DSA[environmentIndex].m_Command.push_back("delete");
                m_DSA[environmentIndex].m_Id += "2"; 
                break;
            case CommandMode::SEARCH_FUNCTION_CALL:
                m_DSA[environmentIndex].m_Command.push_back("search");
                m_DSA[environmentIndex].m_Id += "3"; 
                break;
            case CommandMode::MIN_FUNCTION_CALL:
                m_DSA[environmentIndex].m_Command.push_back("min");
                m_DSA[environmentIndex].m_Id += "4"; 
                break;
            case CommandMode::MAX_FUNCTION_CALL:
                m_DSA[environmentIndex].m_Command.push_back("max");
                m_DSA[environmentIndex].m_Id += "5"; 
                break;
            case CommandMode::INORDER_FUNCTION_CALL:
                m_DSA[environmentIndex].m_Command.push_back("inorder");
                m_DSA[environmentIndex].m_Id += "6"; 
                break;
            case CommandMode::PRINT_FUNCTION_CALL:
                m_DSA[environmentIndex].m_Command.push_back("print");
                m_DSA[environmentIndex].m_Id += "7"; 
                break;
        }
        
        // std::cout << std::right << "\n" << m_DSA[environmentIndex].m_Id << ", " << m_DSA[environmentIndex].m_ClassName << ", "
        //     << m_DSA[environmentIndex].m_Name << ", " << m_DSA[environmentIndex].m_Command[commandIndex] << ", "<< m_DSA[environmentIndex].m_Value[commandIndex]; 

        if (m_DSA[environmentIndex].m_Command[commandIndex] == "print" ||
            m_DSA[environmentIndex].m_Command[commandIndex] == "inorder")
        {
            environmentIndex++;
            commandIndex = 0;
        }
        else
            commandIndex++;
    }

    const std::string&  GetId()         const { return m_DSA[environmentIndex].m_Id; }
    const std::string&  GetClassName()  const { return m_DSA[environmentIndex].m_ClassName; }
    const std::string&  GetName()       const { return m_DSA[environmentIndex].m_Name; }
    const std::string&  GetCommand()    const { return m_DSA[environmentIndex].m_Command[commandIndex]; }
    const int32_t       GetValue()      const { return m_DSA[environmentIndex].m_Value[commandIndex]; }

private:
    std::array<DataStructureAndAlgorithms, 4> m_DSA; 
    
    int32_t environmentIndex = 0;
    int32_t commandIndex = 0;
};