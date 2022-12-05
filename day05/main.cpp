#include <iostream>
#include <fstream>
#include <vector>

#include "Cargo.hpp"

int main()
{
    std::ifstream file("input.txt");

    std::vector<std::string> raw_storage;
    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);
        raw_storage.push_back(line);
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

        line.erase(line.find("move "), 5);
        line.erase(line.find("from "), 5);
        line.erase(line.find("to "), 3);

        int move = std::stoi(line.substr(0, line.find(" ")));
        int src = std::stoi(line.substr(line.find(" ") + 1, line.rfind(" ") - 1));
        int dest = std::stoi(line.substr(line.rfind(" ") + 1, line.length()));

        std::cout << move << src << dest << std::endl;
        cargo.move_crates_9001(move, src - 1, dest - 1);
        cargo.print_size();
        cargo.print_stack();
    }

    cargo.print_message();
    file.close();
    return 0;
}
