// Samuel Nerayo
// c3500
// file: wzip.cpp
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc == 1) { // Check if at least one file is given in command line argument
        cout << "Wzip file1[file2...]\n";
        exit(1);
    }
    // get source file name
    string src_file = argv[1];

    // get destination file name
    string dst_file = argv[3];

    // create a new file to write on it
    ofstream MyFile(dst_file);

    // open destination file
    ifstream fileName(src_file, ios_base::in | ios::binary); // Open file in binary mode
    if (!fileName.is_open()) { // Check if file was opened
        cout << "Wzip: cannot open file\n";
        exit(1);
    }


    char current = 0; // Initialize current character to null character
    int count = 0; // Initialize count to 0
    char c;

    while (fileName.get(c)) { // read char from file
        if(c == current){ // char same as previous ?
            count++;
            continue;
        } else if (count == 2147483647) { // Check for overflow using max value represented using 32-bit int
            cout << count << current;
            current = 0;
            count = 0;
        } else { // After printing count and current, and update current character and count
            MyFile << count << current;
            current = c;
            count = 1;
        }
        if (count > 0) { // print count and current if count > 0
            MyFile << count << current;
        }
    }

    fileName.close(); // Close the file
    MyFile.close();

    return 0;
}
