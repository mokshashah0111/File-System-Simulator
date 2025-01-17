#include "FileSystem.h"

void serialize(std::ostream& out, Directory* dir, const std::string& path) {
    for (auto& filePair : dir->files) {
        out << "F " << path + "/" + filePair.first << " " << filePair.second->content.size() << " " << filePair.second->content << "\n";
    }
    for (auto& dirPair : dir->directories) {
        out << "D " << path + "/" + dirPair.first << "\n";
        serialize(out, dirPair.second.get(), path + "/" + dirPair.first);
    }
}

void deserialize(std::istream& in) {
    std::string line;
    while (getline(in, line)) {
        std::istringstream iss(line);
        char type;
        std::string path, content;
        size_t contentSize;
        iss >> type >> path;
        switch (type) {
            case 'F':
                iss >> contentSize;
                content.resize(contentSize);
                iss.read(&content[0], contentSize); // Directly read into the string
                createFileAtPath(path, content);
                break;
            case 'D':
                mkdirAtPath(path);
                break;
        }
    }
}
    void createFileAtPath(const std::string& fullPath, const std::string& content) {
    size_t lastSlashPos = fullPath.find_last_of('/');
    std::string path = fullPath.substr(0, lastSlashPos);
    std::string fileName = fullPath.substr(lastSlashPos + 1);
    Directory* dir = navigateToPath(path);
    if (dir) {
        if (dir->files.find(fileName) == dir->files.end()) {
            dir->files[fileName] = std::make_unique<File>(fileName);
            dir->files[fileName]->content = content;
        }
    }
}

void mkdirAtPath(const std::string& fullPath) {
    navigateToPath(fullPath, true);
}

Directory* FileSystem::getRoot() const {
    return root.get();
}

Directory* navigateToPath(const std::string& path, bool create = false) {
    std::istringstream iss(path);
    std::string part;
    Directory* dir = fs.getRoot();
    while (getline(iss, part, '/')) {
        if (part.empty()) continue;
        if (dir->directories.find(part) == dir->directories.end()) {
            if (create) {
                dir->directories[part] = std::make_unique<Directory>(part);
            } else {
                return nullptr; // Path does not exist
            }
        }
        dir = dir->directories[part].get();
    }
        return dir;
}


