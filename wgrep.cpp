// Samuel Nerayo
// c3500
// file: wgrep.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;
int main(int argc, char *argv[])
{

    // Check to see if user gave the right search term and fileName
    if (argc == 2) {
        // case only search term provided: take user input as stack
        string term = argv[1];
        do {
            string line;
            cin >> line;
            if (strstr(line.c_str(), term.c_str()) != nullptr)
            {
                // Output the line to the console
                cout << line << endl;
            }
        } while (cin >> term);

    }
    if (argc == 1)
    {
        cout << "wgrep: searchterm [file ...]" << endl;
        exit(1);
    }
    // Open the file
    ifstream fileName(argv[2]);
    // Check if file can be opend
    if(!fileName)
    {
        //print out the following statement if file can't be opened
        cout << "wgrep: Cannot open file" << endl;
        exit(1);
    }
    // Store each line in a buffer
    char buffer[1000];
    // Read line by line
    while (fileName.getline(buffer, sizeof(buffer)))
    {
        // check if search term is in the line
        if (strstr(buffer, argv[1]) != nullptr)
        {
            // Output the line to the console
            cout << buffer << endl;
        }
    }
    // Close file
    fileName.close();

    return 0;
}
