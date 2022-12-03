#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Rucksack
{
private:

    // Rucksack
    const int             _index;
    const std::string     _line;
    const int             _line_length;

    // Compartments
    const int             _compartment_length;
    const std::string     _compartment1;
    const std::string     _compartment2;

    // Rearrangement
    const char            _item_type;
    const int             _priority;

public:

    Rucksack(const std::string& line, const int& index);
    ~Rucksack();

    const int           convert_item(const char& item) const;
    const int           get_priority() const;
    const std::string&  get_line() const;
    const int&          get_length() const;

private:

    const char          _find_item_type() const;

};
