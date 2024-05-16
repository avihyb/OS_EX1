#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <name>" << endl;
        return 1;
    }

    // Concatenate the command to search for the name in phonebook.txt
    string command = "cat phonebook.txt | grep -i '^" + string(argv[1]) + "' | awk -F',' '{print $2}' | tr -d ' '";

    // Open a pipe to execute the command and read its output
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Error: Unable to open pipe" << endl;
        return 1;
    }

    // Buffer to store the output
    char buffer[100];
    // Read the output from the pipe
    if (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        // Remove newline character if present
        char* newline = strchr(buffer, '\n');
        if (newline) *newline = '\0';
        // Output the phone number
        cout << "Phone number: " << buffer << endl;
    } else {
        cout << "Name not found" << endl;
    }

    // Close the pipe
    pclose(pipe);

    return 0;
}
