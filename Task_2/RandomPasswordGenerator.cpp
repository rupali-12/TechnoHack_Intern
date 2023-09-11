// Task-2: create a program to generate a random password os user defined length

#include <bits/stdc++.h>
using namespace std;
class Password
{
private:
    string charSet = "qwertyuioplmkjnbhgvfcdxsazMNBVCXZLPOKIJUHYGTFRDESAQW1365247890!@#$^%&(*_+?><=-)";
    int length;

public:
    Password(int len)
    {
        length = len;
    }
    string generatePassword()
    {
        // get size of character set
        int charSetSize = charSet.length();

        // Seed the random number generator with the current time
        srand(static_cast<unsigned>(time(nullptr)));

        // Initialize an empty Password
        string password = "";

        // Generate a random password
        for (int i = 0; i < length; i++)
        {
            int randomIndex = rand() % charSetSize;
            password += charSet[randomIndex];
        }
        return password;
    }
};
int main()
{
    int length;
    cout << "Enter the length of the password: ";
    cin >> length;
    if (length <= 0)
    {
        cout << "Invalid password length. Please enter a positive number." << endl;
    }
    else
    {
        Password pass(length);
        string password = pass.generatePassword();
        cout << "Generated Password: " << password << endl;
    }
    return 0;
}