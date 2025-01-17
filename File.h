#ifndef FILE_H
#define FILE_H

#include <string>

class File {
public:
    std::string name;
    std::string content;

    File(std::string name);

    void write(const std::string& text, bool append = true);
    void write_at(int pos, const std::string& text);
    std::string read();
    std::string read_from(int start, int numChars);
};

#endif // FILE_H
