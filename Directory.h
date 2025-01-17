#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <map>
#include <string>
#include <memory>
#include "File.h"

class Directory {
public:
    std::string name;
    std::map<std::string, std::unique_ptr<File>> files;
    std::map<std::string, std::unique_ptr<Directory>> directories;

    Directory(std::string name);
};

#endif // DIRECTORY_H
