// Samuel Nerayo
// c3500
// file: wunzip.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

// Parses a digit character into a number
//uint8_t parse_digit(char c) {
   // return c - '0';
//}

int main(int argc, char* argv[]) {

    FILE *fileName; // Opening file
    fileName = fopen(argv[1], "r");
    // check if argv is 1 then print out the fileName
    if (argc == 1) {
        cout <<"wunzip: file1 [file2 ...]\n";
        exit(1); // exit
     // check if file can open
    } else if (fileName == nullptr) {
        cout <<"Cannot open file\n";
        exit(1);
    }
    // Reading file
    int count = 0;
    char c;
    //string line;
    while (fread((char*)&count, sizeof(int), 1, fileName) == 1) {
        fread(&c, sizeof(char), 1, fileName);
        for (int i = 0; i <= count; i++) {
            cout << c;
        }
    }

    // Close the file that was opened
    fclose(fileName);
    return 0;
}

/* NOTES */
/*
 * I had so many problems with this file and unfortunatelly some commands are not working;
 * This file gave hard time and decided to take the late days hopping I would fix the errors
 * yet still won't work
 */
