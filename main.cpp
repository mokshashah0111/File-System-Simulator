#include <iostream>
#include <limits>
#include "FileSystem.h"

FileSystem fs;
int main() {
    fs.loadFromFile("filesystem.dat");

    int choice;
    while (true) {
        std::cout << "\n--- File System Menu ---\n";
        std::cout << "1. List Directory Contents\n";
        std::cout << "2. Create New File\n";
        std::cout << "3. Delete File\n";
        std::cout << "4. Create New Directory\n";
        std::cout << "5. Change Directory\n";
        std::cout << "6. Move File\n";
        std::cout << "7. Write to File\n";
        std::cout << "8. Read from File\n";
        std::cout << "9. Write at fixed position in file\n";
        std::cout << "10. Read fixed number of characters from file\n";
        std::cout << "11. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            // Add cases for each option similar to your current main function
        }
    }

    return 0;
}
