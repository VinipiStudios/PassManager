#include "FileManager.h"
#include "PassContainer.h"
#include <fstream>

using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::endl;

void FileManager::SavePasswords()
{
    ofstream OutFile{};
    OutFile.open(SavePath);
    if (!OutFile.is_open()) return;

    string Link{};
    string Password{};
    
    for (size_t i=0; i<Passwords.size(); i++)
    {
        Link = Encrypt(Passwords[i].GetLink());
        Password = Encrypt(Passwords[i].GetPassword());
        
        OutFile << Link << " " << Password << endl;   
    }   
}

void FileManager::LoadPasswords()
{
    ifstream InFile{};
    InFile.open("Saved.txt");
    if (!InFile.is_open()) return;
    
    string Link{};
    string Password{};
    
    while (InFile >> Link >> Password)
    {
        Link = Decrypt(Link);
        Password = Decrypt(Password);
        Passwords.emplace(Passwords.end(), Link, Password);
    }
}

string FileManager::Encrypt(string S)
{
    return S;
}

string FileManager::Decrypt(string S)
{
    return S;
}
