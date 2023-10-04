// for library
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
// for testing delete later
#include <vector>
// todos
// add a option for the user to read files into a hashmap? or read into multiple variables if seperated by like a :
// make a create file option, while also checking for duplicates, asking if user wants overwrite, and if not ask user to change name of file.
// add a benchmark function, this function creates a file, opens file, loads it full of data, and reads data into memory, in each step it benchmarks how long it takes to do each step
// create another benchmark, this will be a streaming benchmark grabbing one line of file from one file, one from another file, comparing or sorting then restoring it? not sure but ill figure it out

// add a delete file operation
// add a rename file operation
namespace ZURA
{

    class fileOperations
    {
    private:
        std::string file; // this isnt initialzied so i initialized it with the constructor, other way is just doing std::string file = std::string();
        std::fstream File;
        bool successfulFileOpen = false;
        int fileLines = 0;

    public:
        fileOperations() : file() {}
        fileOperations(std::string openFile)
            : file(openFile) // Initialize the 'file' member in the member initializer list
        {
            openfile(file); // Call the 'openfile' member function after initializing 'file'
        }
        ~fileOperations()
        {
            if (File.is_open())
            {
                File.close();
            }
        }
        void openfile(std::string filename = "", bool manualInput = false /*for inputting file name in terminal*/)
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
            File.open(file);
            if (!File.is_open())
            {
                std::cout << "Failed to open file: " << file;
                return;
            }
            std::cout << "successfully opened file: " << file << std::endl;
            successfulFileOpen = true;
        }
        // todo:add overwriting
        // this file should only be called IN STATIC CONTEXT THROUGH SCOPES, aka why the name has a prefix of s_
        template <typename T>
        fileOperations &operator<<(T &data)
        {
            if (File.is_open())
            {
                File << data;
            }
            else
            {
                cout << "Error writing to file, make sure file is open." << endl;
                return;
            }
        }
        template <typename T>
        fileOperations &operator>>(T &data)
        {
            readFileAll(data);
        }
        // i think i might simplify this function, make it to where the user will manually track how many lines themselves?
        // or create another readFile, readFileAll, that reads ALL data into variable

        // this is only really meant for vectors, lists, and others with a push_back()
        // need to make this a little bit easier to use widely, maybe operator override and use a stream operator
        template <typename T>
        void readFileAll(T &container)
        {
            std::string temp;
            if (successfulFileOpen == false)
            {
                std::cout << "must insert file name, or file wasnt opened properly. Cant perform operation" << std::endl;
                return;
            }
            while (std::getline(File, temp))
            {
                container.push_back(temp);
            }
        }

        void closeFile()
        {
            File.close();
        }
        // STATICS, statics with s_ should not be used with a object.
        static void s_createFile(std::string fileName, bool overwrite = false)
        {
            std::fstream fileExists(fileName);
            if (fileExists.is_open())
            {
                std::cout << "File: " << fileName << " already exists." << std::endl;
                fileExists.close();
                if (overwrite)
                {
                    std::cout << "Overwriting File: " << fileName << std::endl;
                    std::ofstream createFile(fileName);
                }
            }
            else
            {
                std::cout << "Creating file: " << fileName << std::endl;
                std::ofstream createFile(fileName);
            }
        }
        // add better error codes for when file fails to delete
        //  idk why im using a C library for this but whatever might fix later but this works for now lleoeoeoeleleol
        static void s_deleteFile(const char *deleteFile)
        {
            if (std::remove(deleteFile) == 0)
            {
                std::cout << "File: " << deleteFile << " deleted successfully!" << std::endl;
            }
            else
            {
                std::cout << "Error deleting file" << deleteFile << std::endl;
                return;
            }
        }
    };
}

int main()
{
    // std::vector<std::string> testVec;
    /*
    std::vector<std::string> testvec;
    ZURA::fileOperations files;
    files.openfile("joemomma.txt");
    files.readFileAll(testvec);
    std::cout << testvec[0];
    */
    ZURA::fileOperations::s_deleteFile("joemomma.txt");
}