#include <iostream>
#include <fstream>
#include <string>

class fileOperations
{
private:
    std::string file;
    std::ofstream outputFile;
    bool successfulFileOpen = false;
    int currentPageLine = 0;

public:
    void openfile(std::string filename = "", bool manualInput)
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
        successfulFileOpen = true;
    }
    template <typename T>
    void writeFile(T write)
    {
        if (successfulFileOpen == false)
        {
            std::cout << "must insert file name, or file wasnt opened properly. Cant perform operation" << endl;
            return;
        }
        outputFile << write << std::endl;
    }
    template <typename T>
    T readFile(T readInto, int numOfLinesToRead = 1, bool readAll = false, bool resetCurrentPageLine = false)
    {
        int linesRead = 0;
        if (successfulFileOpen == false)
        {
            std::cout << "must insert file name, or file wasnt opened properly. Cant perform operation" << endl;
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

template <typename T>
void writeFile(T write)
{
}
int main()
{
}