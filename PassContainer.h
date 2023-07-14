#pragma once
#include <string>
#include <fstream>

using std::string;

class PassContainer
{
public:
    PassContainer(string NLink = "Default@gmail.com", string NPassword = "Default123") : Link(NLink), Password(NPassword) {}
    
private:
    string Link{};
    string Password{};

public:
    inline  std::string GetLink() const { return Link; }
    inline std::string GetPassword() const { return Password; }

    inline void SetLink(std::string& NLink) { Link = NLink; }
    inline void SetPassword(std::string& NPassword) { Link = NPassword; }
};