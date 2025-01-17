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
            case 1:  // List contents
                fs.listDirectory();
                break;
            case 2: {  // Create file
                std::string fileName;
                std::cout << "Enter filename to create: ";
                getline(std::cin, fileName);
                fs.create(fileName);
                break;
            }
            case 3: {  // Delete file
                std::string fileName;
                std::cout << "Enter filename to delete: ";
                getline(std::cin, fileName);
                fs.remove(fileName);
                break;
            }
            case 4: {  // Create directory
                std::string dirName;
                std::cout << "Enter directory name to create: ";
                getline(std::cin, dirName);
                fs.mkdir(dirName);
                break;
            }
            case 5: {  // Change directory
                std::string dirName;
                std::cout << "Enter directory name to change to: ";
                getline(std::cin, dirName);
                fs.chDir(dirName);
                break;
            }
            case 6: {  // Move file
                std::string sourcePath, targetPath;
                std::cout << "Enter the full path of the source file: ";
                getline(std::cin, sourcePath);
                std::cout << "Enter the full path of the target file: ";
                getline(std::cin, targetPath);
                fs.move(sourcePath, targetPath);
                break;
            }
            case 7: {  // Write to file
                std::string fileName, text;
                std::cout << "Enter filename to write to: ";
                getline(std::cin, fileName);
                std::cout << "Enter text to write: ";
                getline(std::cin, text);
                File* file = fs.open(fileName, "write");
                if (file) {
                    file->write(text);
                    fs.close(file);
                }
                break;
            }
            case 8: {  // Read from file
                std::string fileName;
                std::cout << "Enter filename to read from: ";
                getline(std::cin, fileName);
                File* file = fs.open(fileName, "read");
                if (file) {
                    std::cout << "File content:\n" << file->read() << std::endl;
                    fs.close(file);
                }
                break;
            }
            case 9: {  // Write at fixed position in file
                std::string fileName;
                int position;
                std::string text;
                std::cout << "Enter filename to write to: ";
                getline(std::cin, fileName);
                std::cout << "Enter the position to start writing at: ";
                std::cin >> position;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
                std::cout << "Enter text to write: ";
                getline(std::cin, text);
                File* file = fs.open(fileName, "write");
                if (file) {
                    file->write_at(position, text);
                    fs.close(file);
                }
                break;
            }
            case 10: {  // Read fixed number of characters from file
                std::string fileName;
                int start, numChars;
                std::cout << "Enter filename to read from: ";
                getline(std::cin, fileName);
                std::cout << "Enter start position: ";
                std::cin >> start;
                std::cout << "Enter number of characters to read: ";
                std::cin >> numChars;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
                File* file = fs.open(fileName, "read");
                if (file) {
                    std::cout << "File content:\n" << file->read_from(start, numChars) << std::endl;
                    fs.close(file);
                }
                break;
            }
            case 11:  // Exit
                fs.saveToFile("filesystem.dat");  // Save current state
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }

        }
    }

    return 0;
}
