#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char **argv)
{
    std::string login;
    std::string password = "12345";
    std::hash<std::string> hash_pass;

    size_t res = hash_pass(password);

    std::cout << "Your hash: " << res << std::endl;

    return 0;
}