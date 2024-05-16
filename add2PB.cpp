#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>

using namespace std;

bool isValidPhoneNumber(const char* phoneNumber) {
    // Check if all characters are digits and if the length is less than or equal to 10
    for (int i = 0; phoneNumber[i] != '\0'; ++i) {
        if (!isdigit(phoneNumber[i])) {
            return false;
        }
    }
    return strlen(phoneNumber) <= 10;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <first name> <last name> <phone number>" << endl;
        return 1;
    }

    if (!isValidPhoneNumber(argv[3])) {
        cerr << "Invalid phone number. It must contain only digits and be less than or equal to 10 digits long." << endl;
        return 1;
    }

    int fd[2];
    if (pipe(fd) == -1) {
        cout << "Failed creating pipe";
        return 1;
    }

    int id = fork();
    if (id == -1) {
        cerr << "Fork failed";
        return 1;
    } else if (id == 0) {
        // Child process
        close(fd[0]); // Close reading end of the pipe
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to the writing end of the pipe
        close(fd[1]); // Close original writing end of the pipe
        // Now stdout is directed to the writing end of the pipe
        // Write the new entry to stdout
        cout << argv[1] << " " << argv[2] << "," << argv[3] << endl;
    } else {
        // Parent process
        // Close writing end of the pipe
        close(fd[1]);
        // Open phonebook.txt for appending
        ofstream phonebook("phonebook.txt", ios::app);
        if (!phonebook) {
            cerr << "Error: Unable to open phonebook.txt" << endl;
            return 1;
        }
        // Read from the reading end of the pipe and write to phonebook.txt
        const int BUFFER_SIZE = 100;
        char buffer[BUFFER_SIZE];
        ssize_t bytesRead;
        while ((bytesRead = read(fd[0], buffer, BUFFER_SIZE)) > 0) {
            phonebook.write(buffer, bytesRead);
        }
        // Close phonebook.txt
        phonebook.close();
        // Wait for the child to finish
        wait(NULL);
    }
    return 0;
}
