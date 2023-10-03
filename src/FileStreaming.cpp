// for library
#include <iostream>
#include <fstream>
#include <string>
// for testing delete later
#include <vector>
// todos
// add a option for the user to read files into a hashmap? or read into multiple variables if seperated by like a :
// make a create file option, while also checking for duplicates, asking if user wants overwrite, and if not ask user to change name of file.
// add a benchmark function, this function creates a file, opens file, loads it full of data, and reads data into memory, in each step it benchmarks how long it takes to do each step
// create another benchmark, this will be a streaming benchmark grabbing one line of file from one file, one from another file, comparing or sorting then restoring it? not sure but ill figure it out
namespace ZURA
{

    class fileOperations
    {
    private:
        std::string file;
        std::ofstream outputFile;
        bool successfulFileOpen = false;

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
        static void createFile(std::string fileName, bool overwrite = false)
        {
            std::ifstream fileExists(fileName);
            if (fileExists.is_open())
            {
                std::cout << "File: " << fileName << " already exists." << std::endl;
                fileExists.close();
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
        // i think i might simplify this function, make it to where the user will manually track how many lines themselves?
        // or create another readFile, readFileAll, that reads ALL data into variable
        template <typename T>
        /*
        T readFile(int startingLine = 0)
        {
            if (successfulFileOpen == false)
            {
                std::cout << "must insert file name, or file wasnt opened properly. Cant perform operation" << std::endl;
                return;
            }
            while (linesRead < numOfLinesToRead && std::getline(outputFile, readInto))
            {
                linesRead++;
            }
        }*/
        void closeFile()
        {
            outputFile.close();
        }
    };
}

int main()
{
    // std::vector<std::string> testVec;
    // ZURA::fileOperations files;
    // files.openfile("test.txt", false);
    //  files.readFile(testVec, true);
    ZURA::fileOperations::createFile("joemomma.txt", false);
}