#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char **argv)
{
    std::string login;
    std::hash<std::string> hasher;
    size_t resultHash;
    int action;

    std::cout << "Select action (sing up(0) or log in(1)): \n";
    std::cin >> action;
    std::cout << "Enter your login: ";
    std::cin >> login;
    std::cout << "Enter your password: ";
    std::string pas;
    std::cin >> pas;
    resultHash = hasher(pas);
    pas = "                           ";     // clear if it really work and secure
    if (action == 0)
    {
        
        std::ofstream f;
        f.open("base.txt", std::ios::app);
        if (!f.is_open()) 
        {  
            std::cerr << "Error open file for write\n";
            return -1;
        }
        f << login << " " << resultHash << '\n';
        f.close();
    }
    else 
    {
        std::ifstream f;
        f.open("base.txt");
        if (!f.is_open()) 
        {  
            std::cerr << "Error open file for read\n";
            return -1;
        }
        std::string tmpLogin, tmpHash;
        while (tmpLogin != login && !f.eof())
        {
            f >> tmpLogin;
            f >> tmpHash;
        }
        if (tmpLogin == login && std::atoll(tmpHash.c_str()) == resultHash)
        {
            std::cout << "You're welcome!\n";
        }
        else 
        {
            std::cout << "Invalid login or password\n";
        }
        f.close();
    }

    return 0;
}