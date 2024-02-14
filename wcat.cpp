// Samuel Nerayo
// c3500
// file: wcat.cpp
#include <iostream>
//#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 1 ) {
        cout << "Wcat file[file....]\\n";
        exit(1); // exit the program
    }

    for(int i = 1; i < argc; i++) {

        string fileName = argv[i];
        fstream in(fileName.c_str());

        if (fileName.empty()) { // If file is empty
            cout << "Eroor \n";
            exit(1); // Terminate program
        }
        ifstream checkFile(fileName); // if file can't be opened
        if(!checkFile.is_open()) {
            cout << "wcat: cannot open file\n";
            exit(1); // Terminate program
        }

        // Reading file.txt completely using
        // END OF FILE eof() method
        while (!in.eof()) {
            // string to extract line from
            // file.txt
            string text;

            // extracting line from file.txt
            getline(in, text);

            // Writing the extracted line in
            cout << text << endl;
        }
    }

    // Close the file
    //fileName.close();


    return 0;
}
