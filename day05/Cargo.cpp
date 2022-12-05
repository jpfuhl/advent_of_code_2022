#include "Cargo.hpp"

Cargo::Cargo(std::stack<std::string> raw_storage)
: _storage()
{
    _storage.reserve(9);
    for (int i = 0; i < 9; ++i)
        _storage.push_back(std::stack<char>());

    std::cout << std::endl << "-- CARGO STORAGE --";
    while (!raw_storage.empty())
    {
        int id = 0;
        std::string line = raw_storage.top();
        int length = line.length();
        for (int pos = 0; pos < length; pos += 4)
        {
            char crate = line[pos + 1];
            if (isdigit(crate))
                break;
            std::cout << "[" << crate << "] ";
            _storage[id].push(crate);
            ++id;
        }
        raw_storage.pop();
        std::cout << std::endl;
    }

    std::vector<std::stack<char> >::iterator it = _storage.begin();
    for (; it != _storage.end(); ++it)
    {
        while (it->top() == ' ')
            it->pop();
    }
    std::cout << std::endl;
}


Cargo::~Cargo() {}


void Cargo::move_crates(int moves, int src, int dest)
{
    for (int i = 0; i < moves; ++i)
    {
        char crate = _storage[src].top();
        _storage[src].pop();
        _storage[dest].push(crate);
    }
}


void Cargo::print_message()
{
    std::vector<std::stack<char> >::iterator it = _storage.begin();

    for (; it != _storage.end(); ++it)
    {
        if (it->size() != 0)
            std::cout << it->top();
        else
            std::cout << "_";
    }
    std::cout << std::endl;
}


void Cargo::print_size()
{
    std::vector<std::stack<char> >::iterator it = _storage.begin();

    for (; it != _storage.end(); ++it)
        std::cout << it->size() << " ";
    std::cout << std::endl;
}
