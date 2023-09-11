oFile(const string &filename) const
    {
        ofstream outFile(filename);

        if (!outFile)
        {
            cout << "Error: Unable to open the file for writing." << endl;
            return;
        }

        for (const Task &task : tasks)
        {
            outFile << task.getTitle() << "," << task.getDueDate() << "," << task.getNote() << endl;
        }

        cout << "To-do list saved to " << filename << "." << endl;
    }