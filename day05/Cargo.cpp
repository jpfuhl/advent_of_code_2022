#include "Cargo.hpp"

Cargo::Cargo(std::vector<std::string> raw_storage)
: _storage()
{
    _storage.reserve(9);
    for (int i = 0; i < 9; ++i)
        _storage.push_back(std::vector<char>());

    std::cout << std::endl << "-- CARGO STORAGE --";
    while (!raw_storage.empty())
    {
        int id = 0;
        std::string line = raw_storage.back();
        int length = line.length();
        for (int pos = 0; pos < length; pos += 4)
        {
            char crate = line[pos + 1];
            if (isdigit(crate))
                break;
            std::cout << "[" << crate << "] ";
            _storage[id].push_back(crate);
            ++id;
        }
        raw_storage.pop_back();
        std::cout << std::endl;
    }

    std::vector<std::vector<char> >::iterator it = _storage.begin();
    for (; it != _storage.end(); ++it)
    {
        while (it->back() == ' ')
            it->pop_back();
    }
    std::cout << std::endl;
}


Cargo::~Cargo() {}


void Cargo::move_crates_9000(int moves, int src, int dest)
{
    for (int i = 0; i < moves; ++i)
    {
        char crate = _storage[src].back();
        _storage[src].pop_back();
        _storage[dest].push_back(crate);
    }
}


void Cargo::move_crates_9001(int moves, int src, int dest)
{
    std::stack<char> tmp;

    for (int i = 0; i < moves; ++i)
    {
        char crate = _storage[src].back();
        tmp.push(crate);
        _storage[src].pop_back();
    }

    while (!tmp.empty())
    {
        char crate = tmp.top();
        _storage[dest].push_back(crate);
        tmp.pop();
    }
}


void Cargo::print_message()
{
    std::vector<std::vector<char> >::iterator it = _storage.begin();

    for (; it != _storage.end(); ++it)
    {
        if (it->size() != 0)
            std::cout << it->back();
        else
            std::cout << "_";
    }
    std::cout << std::endl;
}


void Cargo::print_size()
{
    std::vector<std::vector<char> >::iterator it = _storage.begin();

    for (; it != _storage.end(); ++it)
        std::cout << it->size() << " ";
    std::cout << std::endl;
}

void Cargo::print_stack()
{
    std::vector<std::vector<char> >::iterator it = _storage.begin();

    for (; it != _storage.end(); ++it)
    {
        std::vector<char>::iterator stack_it = it->begin();
        
        for (; stack_it != it->end(); ++stack_it)
            std::cout << *stack_it << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
