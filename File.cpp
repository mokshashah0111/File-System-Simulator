#include "File.h"

File::File(std::string name) : name(name), content("") {}

void File::write(const std::string& text, bool append) {
    if (append) {
        content += text;
    } else {
        content = text;
    }
}

void File::write_at(int pos, const std::string& text) {
    if (pos > content.length()) {
        content.resize(pos);
    }
    for (int i = 0; i < text.size(); ++i) {
        if (pos + i < content.size()) {
            content[pos + i] = text[i];
        } else {
            content += text[i];
        }
    }
}

std::string File::read() {
    return content;
}

std::string File::read_from(int start, int numChars) {
    if (start >= content.length()) return "";
    return content.substr(start, numChars);
}
