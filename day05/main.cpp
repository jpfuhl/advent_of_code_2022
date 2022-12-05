#include <iostream>
#include <fstream>
#include <stack>

#include "Cargo.hpp"

int main()
{
    std::ifstream file("input.txt");

    std::stack<std::string> raw_storage;
    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);
        raw_storage.push(line);
        if (line.length() == 0)
            break;
    }

    Cargo cargo(raw_storage);
    cargo.print_size();

    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);
        cargo.print_message();
        std::cout << line << std::endl;

        line.erase(line.find("move "), 5);
        line.erase(line.find("from "), 5);
        line.erase(line.find("to "), 3);

        std::cout << "segf" << std::endl;
        int move = std::stoi(line.substr(0, line.find(" ")));
        int src = std::stoi(line.substr(line.find(" ") + 1, line.rfind(" ") - 1));
        int dest = std::stoi(line.substr(line.rfind(" ") + 1, line.length()));
        std::cout << "segf" << std::endl;


        std::cout << move << src << dest << std::endl;
        cargo.move_crates(move, src - 1, dest - 1);
        cargo.print_size();
    }

    cargo.print_message();
    file.close();
    return 0;
}
