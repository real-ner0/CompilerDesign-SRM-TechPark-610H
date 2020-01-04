/**
        *  15CS314J - Compiler Design Lab : Exercise 1. Lab 610, TechPark, SRM IST.
        *  Text Editor for understanding basic file R/W operations.
        *  Coded by Shubham aka ner0, 4th Jan 2020
        *  https://www.github.com/real-ner0
**/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <string>


using namespace std;


void create_file();
void write_to_file();
void read_file();
void delete_file();


int main(void)
{
    fflush(stdin);
    fflush(stdout);

    short int option;   /// Choose the user action.

    do                          /// Prints the main menu.
    {
        cout << "\n\n\t\t" << "*** Text Editor ***" << endl;
        cout << "\n\n\n\t" << " 1. Create a file. " << endl;
        cout << "\n\t" << " 2. Write or append to a file. " << endl;
        cout << "\n\t" << " 3. Read from a file. " << endl;
        cout << "\n\t" << " 4. Delete the file. " << endl;
        cout << "\n\t" << " 5. Close the editor. " << endl;

        cout << "\n\n\t\t" << "Enter your choice number: ";

        cin >> option;


    /// Goto the user action.

    switch(option)
    {
    case 1:
        create_file();
        break;

    case 2:
        write_to_file();
        break;

    case 3:
        read_file();
        break;

    case 4:
        delete_file();
        break;

    default:
        exit(0);                /// First exit status code : 0
    }

    } while(option != 5);
    return 0;
}

void create_file()
{
    cout << "\n\n\t" << "Enter the file name of file <file_name.extension>: ";
    string file_name;
    cin >> file_name;

    fstream user_file;
    user_file.open(file_name, ios::out);        /// ios::out Open file for output operations.

    if(!user_file)
        cout << "\n\t Failed to generate file!" << endl;
    else
        cout << "\n\t File Generated!" << endl;

    cout << "\n\t Sending back to main menu...\n" << endl;
    user_file.close();
}

void write_to_file()
{
    string file_name;
    cout << "\n\t Enter the file name to open : ";
    cin >> file_name;
    fstream user_file;
    user_file.open(file_name, ios::out | ios::in | ios::app);

    string user_text;
    cout << "\n\n\t Start Entering your text. Enter /exit to close" << endl;

    if(user_file.good())                        /// Checks if there's error in opening file
    {
        while(1)
        {
            getline(cin, user_text);
            if(user_text == "/exit")
                break;
            else
                user_file << user_text << endl;
        }

        cout << "\n\n\t Data Written to the file" << endl;
        cout << "\nSending you back to the main menu..." << endl;

        user_file.close();
    }
    else
        {
            cout << "\n\t WTF...?" << endl;
            exit(1);                                            /// Second exit status code : 1
        }
}

void read_file()
{
    string file_name;
    string data;
    cout << "\n\t Enter file name to read <file_name.extension> : ";
    cin >> file_name;

    ifstream user_file;

    user_file.open(file_name);

    if(user_file.good())
    {
        while (getline(user_file, data))
        {
            cout << data << endl;
        }

        cout << "\n\t End of the file..." << endl;
        cout << "\n\t Sending you back to the main menu..." << endl;
    }
    else
    {
        cout << "WTF...?" << endl;
        exit(2);                                    /// Third exit status code : 2
    }
}

void delete_file()
{
    cout << "\n\t FILE CANNOT BE RESTORED !!!" << endl;
    cout << "\n\t Enter the file name to delete <file_name.extension>: ";
    string file_name;
    cin >> file_name;
    const char* f = file_name.c_str();                                      /// Needs string module. Converts string to const char*

    if(remove(f))                                                                      /// int remove(const char*)
        cout << "\n\t Failed to delete the file...!" << endl;
    else
        cout << "\n\t File Deleted...!" << endl;
}
