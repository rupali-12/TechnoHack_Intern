// // Task-1: Create a program that allows the user to create and manage a to do list
#include <bits/stdc++.h>

using namespace std;

class Task
{
private:
    string title;
    string dueDate;
    string note;

public:
    Task(const string &title, const string &dueDate, const string &note = "")
        : title(title), dueDate(dueDate), note(note) {}

    const string &getTitle() const
    {
        return title;
    }

    const string &getDueDate() const
    {
        return dueDate;
    }

    const string &getNote() const
    {
        return note;
    }

    void setNote(const string &newNote)
    {
        note = newNote;
    }
};
class TodoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const string &title, const string &dueDate, const string &note = "")
    {
        Task task(title, dueDate, note);
        tasks.push_back(task);
        cout << "Task added to the to-do list." << endl;
    }

    void removeTask(int taskNumber)
    {
        if (taskNumber >= 1 && taskNumber <= tasks.size())
        {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed from the to-do list." << endl;
        }
        else
        {
            cout << "Invalid task number." << endl;
        }
    }

    void editTaskNote(int taskNumber, const string &newNote)
    {
        if (taskNumber >= 1 && taskNumber <= tasks.size())
        {
            tasks[taskNumber - 1].setNote(newNote);
            cout << "Note for task '" << tasks[taskNumber - 1].getTitle() << "' updated." << endl;
        }
        else
        {
            cout << "Invalid task number." << endl;
        }
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            cout << "The to-do list is empty." << endl;
        }
        else
        {
            cout << "To-Do List:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i)
            {
                cout << i + 1 << ". Title: " << tasks[i].getTitle() << ", Due Date: " << tasks[i].getDueDate() << endl;
                cout << "   Note: " << tasks[i].getNote() << endl;
            }
        }
    }

    void saveToFile(const string &filename) const
    {
        ofstream outFile(filename);

        if (!outFile)
        {
            cout << "Error: Unable to open the file for writing." << endl;
            return;
        }

        for (const Task &task : tasks)
        {
            outFile << task.getTitle() << ","
                    << task.getDueDate() << ","
                    << task.getNote() << endl;
        }

        cout << "To-do list saved to " << filename << "." << endl;
    }

    void loadFromFile(const string &filename)
    {
        ifstream inFile(filename);

        if (!inFile)
        {
            cout << "Error: Unable to open the file for reading." << endl;
            return;
        }

        tasks.clear();
        string line;

        while (getline(inFile, line))
        {
            size_t firstCommaPos = line.find(',');
            size_t secondCommaPos = line.find(',', firstCommaPos + 1);

            if (firstCommaPos != string::npos && secondCommaPos != string::npos)
            {
                string title = line.substr(0, firstCommaPos);
                string dueDate = line.substr(firstCommaPos + 1, secondCommaPos - firstCommaPos - 1);
                string note = line.substr(secondCommaPos + 1);
                Task task(title, dueDate, note);
                tasks.push_back(task);
            }
        }

        cout << "To-do list loaded from " << filename << "." << endl;
    }
};

int main()
{
    TodoList todoList;
    string filename = "todo_list.txt";

    todoList.loadFromFile(filename); // Load the to-do list from a file
    // todoList.viewTasks();
    while (true)
    {
        cout << "\nOptions:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Edit Task Note" << endl;
        cout << "4. View Tasks" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, dueDate, note;
            cout << "Enter task title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter due date (YYYY-MM-DD): ";
            cin >> dueDate;
            cin.ignore();
            cout << "Enter a note for the task: ";
            getline(cin, note);
            todoList.addTask(title, dueDate, note);
            break;
        }
        case 2:
        {
            int taskNumber;
            cout << "Enter the task number to remove: ";
            cin >> taskNumber;
            todoList.removeTask(taskNumber);
            break;
        }
        case 3:
        {
            int taskNumber;
            cout << "Enter the task number to edit the note: ";
            cin >> taskNumber;
            string newNote;
            cin.ignore();
            cout << "Enter the new note for the task: ";
            getline(cin, newNote);
            todoList.editTaskNote(taskNumber, newNote);
            break;
        }
        case 4:
            todoList.viewTasks();
            break;
        case 5:
            todoList.saveToFile(filename); // Save the to-do list to a file
            break;
        case 6:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}