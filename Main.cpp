#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "FileManager.h"
#include "PassContainer.h"

using std::cout;
using std::cin;
using std::endl;

void DisplayPasswords();
void DisplayMenu();
char GetSelection();
void SwitchSelection();
void AddPassword();
void RemovePassword();

FileManager Manager{};
int LinkWidth{30};
int PassWidth{30};
int TotalWidth{LinkWidth + PassWidth};
char Selection{};

int main()
{
    Manager.LoadPasswords(); // Initialize
    
    while (Selection != 'Q')
    {
        DisplayMenu();
        Selection = GetSelection();
        SwitchSelection();
    }
    
    Manager.SavePasswords(); // Save
    return 0;
}

void DisplayMenu()
{
    cout << endl << std::setfill('-') << std::setw(TotalWidth) << ""  << std::setfill(' ') << endl;
    cout << "1- Display passwords\n";
    cout << "2- Add password\n";
    cout << "3- Remove password\n";
    cout << "Q- Quit\n";
    cout << std::setfill('-') << std::setw(TotalWidth) << ""  << std::setfill(' ') << endl;
}

char GetSelection()
{
    char c{};
    cout << "What's your selection? ";
    cin >> c;
    cout << std::setfill('-') << std::setw(TotalWidth) << ""  << std::setfill(' ') << endl << endl;
    c = std::toupper(c);
    return c;
}

void SwitchSelection()
{
    switch(Selection)
    {
    case '1':
        DisplayPasswords();
        break;
    case '2':
        // TODO Add password
        cout << "Selection 2\n";
        break;
    case '3':
        cout << "Selection 3\n";
        // TODO Remove passsword
        break;
    }
}

void DisplayPasswords()
{
    if (Manager.GetPasswords().size() == 0)
    {
        cout << "**There are no passwords yet**\n";
        return;
    }
    
    cout << std::left << std::setw(LinkWidth) << "Email/Username" << std::right << std::setw(PassWidth) << "Password\n";
    cout << std::setfill('-') << std::setw(TotalWidth) << "\n" << std::setfill(' ');
    
    for (auto password : Manager.GetPasswords())
    {
        cout << std::left << std::setw(LinkWidth) << password.GetLink() << std::right << std::setw(PassWidth) << password.GetPassword() << "\n";
    }
}

void AddPassword()
{
    // TODO
}

void RemovePassword()
{
    // TODO
}