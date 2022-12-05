#include <iostream>
#include <stack>
#include <vector>

class Cargo
{
private:

    std::vector<std::stack<char> > _storage;

public:

    Cargo(std::stack<std::string> raw_storage);
    ~Cargo();

    void move_crates(int moves, int src, int dest);
    void print_message();
    void print_size();

};
