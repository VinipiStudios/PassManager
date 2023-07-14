#pragma once
#include <vector>
#include <string>

using std::string;
using std::vector;

class FileManager
{
public:
    FileManager(string NSavePath = "Saved.txt") : SavePath(NSavePath) {}
    void SavePasswords();
    void LoadPasswords();
    string Encrypt(string S);
    string Decrypt(string S);
    
private:
    string SavePath{"Saved.txt"};
    std::vector<class PassContainer> Passwords{};

public:
    std::vector<PassContainer> GetPasswords() const { return Passwords; }
};
