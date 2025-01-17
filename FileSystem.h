#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include "Directory.h"

class FileSystem {
private:
    Directory* currentDir;
    std::stack<Directory*> dirStack;
    std::unique_ptr<Directory> root;

    void serialize(std::ostream& out, Directory* dir, const std::string& path);
    void deserialize(std::istream& in);
    void createFileAtPath(const std::string& fullPath, const std::string& content);
    void mkdirAtPath(const std::string& fullPath);
    Directory* navigateToPath(const std::string& path, bool create = false);

public:
    FileSystem();
    ~FileSystem();
    
    Directory* getRoot() const;
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    void create(const std::string& fName);
    void remove(const std::string& fName);
    void mkdir(const std::string& dirName);
    void chDir(const std::string& dirName);
    void move(const std::string& sourcePath, std::string& targetPath);
    File* open(const std::string& fName, const std::string& mode);
    void close(File* file);
    void listDirectory();
};

#endif // FILESYSTEM_H
