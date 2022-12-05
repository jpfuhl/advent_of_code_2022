#include <iostream>
#include <vector>
#include <stack>

class Cargo
{
private:

    std::vector<std::vector<char> > _storage;

public:

    Cargo(std::vector<std::string> raw_storage);
    ~Cargo();

    void move_crates_9000(int moves, int src, int dest);
    void move_crates_9001(int moves, int src, int dest);
    void print_message();
    void print_size();
    void print_stack();

};
