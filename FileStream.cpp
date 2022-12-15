#include "State.cpp"

#include <vector>
class FileStream
{
public:
    FileStream(std::string_view filepath)
        : m_Filepath(filepath)
    {}

    FileStream() : m_Filepath("./Assignment_READ.txt") {}

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

    void Read() //const std::string& filepath = "./Assignment_READ.txt"
    {
        // std::ifstream r_file(m_Filepath, std::ios::in);
        // if (!r_file)
        // {
        //     std::cerr << "GGGG\n";
        //     return; 
        // }

        // while (r_file)
        // {
        //     std::string line;
        //     r_file >> line;
        //     std::cout << line << '\n';

        //     std::stringstream ss;
        //     ss << line;

        //     // for (const auto& word : ss)
        //     // {
        //     //     std::cout << word << "\n";   
        //     // }
        // }

        std::ifstream r_file(m_Filepath, std::ios::in);
        if (!r_file)
        {
            std::cerr << "GGGG\n";
            return; 
        }

        while (r_file)
        {
            std::string line;

            while (std::getline(r_file, line))
            {
                std::size_t offset = 0;
                std::size_t whitespacePos = line.find(" ");

                int row = 0, column = 0;

                while (whitespacePos != std::string::npos)
                {    
                    std::string words[32][5];
                    //std::string word;
                    // for (int i = 0; i != 31; i++) // Total row lines in Assignment_READ
                    // {
                    //     for (int j = 0; j != 5; )
                    // }
                    words[row][column] = line.substr(offset, whitespacePos - offset);
                    //word = line.substr(offset, whitespacePos - offset);
                    std::cout << words[row][column] << " ";
                    //std::cout << word << "\n";
                    column++;

                    if (line == "LinkedList list")
                    {
                        m_DSA.m_Name = "list";
                        m_DSA.m_Command = 
                    }

                    if (word == 'LinkedList' || )

                    offset = ++whitespacePos;
                    whitespacePos = line.find(" ", whitespacePos);
                    
                    if (whitespacePos == std::string::npos)
                    {
                        std::cout << "\n";
                        row++;
                        break;
                    }
                }
            }
        }
    }

    void ReadToMapping()
    {
        
    }

    static void Write(std::string_view value, const std::string& filepath = "./Assignment_WRITE.txt")
    {
        std::ofstream w_file(filepath, std::ios::app | std::ios::out);
        if (!w_file)
        {
            std::cerr << "FFFF\n";
            return; 
        }

        w_file << value;
    } 

    const std::string& GetFilepath() const { return m_Filepath; }
private:
    std::string m_Filepath;

    Command m_CommandState; 

    DSAMapping<Mode::DSA> m_DSA;
};