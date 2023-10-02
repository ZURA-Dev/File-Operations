#include <iostream>
#include <fstream>
#include <string>
// todos
// add a option for the user to read files into a hashmap? or read into multiple variables if seperated by like a :
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

int main()
{
    fileOperations files;
    files.openfile("test.txt", false);
}