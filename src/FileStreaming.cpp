#include <iostream>
#include <fstream>
#include <string>
// todos
// add a option for the user to read files into a hashmap? or read into multiple variables if seperated by like a :
// make a create file option, while also checking for duplicates, asking if user wants overwrite, and if not ask user to change name of file.
// add a benchmark function, this function creates a file, opens file, loads it full of data, and reads data into memory, in each step it benchmarks how long it takes to do each step
namespace ZURA
{

    class fileOperations
    {
    private:
        std::string file;
        std::ofstream outputFile;
        bool successfulFileOpen = false;
        int currentPageLine = 0;

    public:
        void openfile(std::string filename = "", bool manualInput = false)
        {
            if (manualInput == true)
            {
                std::cout << "input file name: ";
                std::cin >> file;
                std::cin.clear();
            }
            else
            {
                file = filename;
            }
            outputFile.open(file);
            if (!outputFile.is_open())
            {
                std::cout << "Failed to open file: " << file;
                return;
            }
            std::cout << "successfully opened file: " << file << std::endl;
            successfulFileOpen = true;
        }
        // todo:add overwriting
        void createFile(std::string fileName)
        {

            std::ifstream fileExists(fileName);
            if (fileExists.is_open())
            {
                std::cout << "File: " << fileName << " already exists." << std::endl;
            }
            else
            {
                std::cout << "Creating file: " << fileName << std::endl;
                std::ofstream createFile(fileName);
            }
        }
        template <typename T>
        void writeFile(T write)
        {
            if (successfulFileOpen == false)
            {
                std::cout << "must insert file name, or file wasnt opened properly. Cant perform operation" << std::endl;
                return;
            }
            outputFile << write << std::endl;
        }
        template <typename T>
        T readFile(T readInto, int numOfLinesToRead = 1, bool readAll = false, bool resetCurrentPageLine = false, int boostCurrentLinesRead = 0)
        {
            if (boostCurrentLinesRead > 0)
            {
                currentPageLine = boostCurrentLinesRead;
            }
            int linesRead = 0;
            if (successfulFileOpen == false)
            {
                std::cout << "must insert file name, or file wasnt opened properly. Cant perform operation" << std::endl;
                return;
            }
            if (resetCurrentPageLine == true)
            {
                currentPageLine = 0;
            }
            if (readAll == false)
            {
                while (linesRead < numOfLinesToRead && std::getline(outputFile, readInto))
                {
                    linesRead++;
                    currentPageLine++;
                }
            }
            else
            {
                while (std::getline(outputFile, readInto))
                    ;
            }
        }
        void closeFile()
        {
            outputFile.close();
        }
    };
}

int main()
{
    ZURA::fileOperations files;
    files.openfile("test.txt", false);
}