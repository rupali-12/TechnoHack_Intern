// Task-3: Create a program that allow user to manage files and folders on their computers
// start command-> cd "d:\TechnoHack\Task_3\" ; if ($?) { g++ -std=c++17 FileManager.cpp -o FileManager } ; if ($?) { .\FileManager }         // To compile code with support c++17

#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

class FileSystem
{
public:
    void listAllFiles() const
    {
        for (const auto &entry : fs::directory_iterator("."))
        {
            if (fs::is_regular_file(entry))
            {
                cout << "File: " << entry.path().filename() << endl;
            }
        }
    }
    void listAllDirectories()
    {
        for (const auto &entry : fs::directory_iterator("."))
        {
            if (fs::is_directory(entry))
            {
                cout << "Directory: " << entry.path().filename() << endl;
            }
        }
    }
    void createFileInDirectory(const string &dirname, const string &filename) const
    {
        string fullPath = dirname + "/" + filename;
        ofstream file(fullPath);
        if (file)
        {
            cout << "File created successfully." << endl;
        }
        else
        {
            cout << "Failed to create file." << endl;
        }
    }
    void createDirectory(const string &dirname) const
    {
        if (fs::create_directory(dirname))
        {
            cout << "Directory created successfully." << endl;
        }
        else
        {
            cout << "Failed to create directory." << endl;
        }
    }
    void deleteFileFromDirectory(const string &filename) const
    {
        if (fs::remove(filename))
        {
            cout << "File deleted successfully." << endl;
        }
        else
        {
            cout << "Failed to delete file." << endl;
        }
    }
    void deleteDirectory(const string &dirname) const
    {
        if (fs::remove_all(dirname))
        {
            cout << "Directory deleted successfully." << endl;
        }
        else
        {
            cout << "Failed to delete directory." << endl;
        }
    }
};
int main()
{
    int choice;
    FileSystem filemanager;
    while (true)
    {
        cout << "\nOptions:" << endl;
        cout << "1. Create a file in the current directory." << endl;
        cout << "2. Create a directory." << endl;
        cout << "3. List all files in a directory." << endl;
        cout << "4. List all directories." << endl;
        cout << "5. Delete a file from the current directory." << endl;
        cout << "6. Delete a directory." << endl;
        cout << "7. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string fName, dirname;
            cout << "Enter directory name: ";
            cin >> dirname;

            cout << "\nEnter filename: ";
            cin >> fName;
            filemanager.createFileInDirectory(dirname, fName);
            break;
        }
        case 2:
        {
            string dirname;
            cout << "Enter directory name: ";
            cin >> dirname;
            filemanager.createDirectory(dirname);
            break;
        }
        case 3:
        {
            filemanager.listAllFiles();
            break;
        }
        case 4:
        {
            filemanager.listAllDirectories();
            break;
        }
        case 5:
        {
            string filename;
            cout << "Enter the filename to delete: ";
            cin >> filename;
            filemanager.deleteFileFromDirectory(filename);
            break;
        }
        case 6:
        {
            string dirname;
            cout << "Enter the directory name to delete: ";
            cin >> dirname;
            filemanager.deleteDirectory(dirname);
            break;
        }
        case 7:
        {
            cout << "GoodByee, See Yaa..!!" << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid Choice, Please try again and make a valid choice." << endl;
        }
        }
    }
    return 0;
}