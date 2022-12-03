#include "Rucksack.hpp"

Rucksack::Rucksack(const std::string& line, const int& index)
: _index(index),
  _line(line),
  _line_length(_line.length()),
  _compartment_length(_line_length / 2),
  _compartment1(_line.substr(0, _compartment_length)),
  _compartment2(_line.substr(_compartment_length, _line_length)),
  _item_type(_find_item_type()),
  _priority(convert_item(_item_type))
{
    // std::cout << "RUCKSACK " << _index << std::endl;
    // std::cout << "Comp1 : " << _compartment1 << std::endl;
    // std::cout << "Comp2 : " << _compartment2 << std::endl;
    // std::cout << "Length : " << _compartment_length << std::endl;
    // std::cout << "Item : " << _item_type << std::endl;
    // std::cout << "Prio : " << _priority << std::endl;
    // std::cout << std::endl;
}

Rucksack::~Rucksack() {}

const char Rucksack::_find_item_type() const
{
    char match;

    for (int i = 0; i < _compartment_length; ++i)
    {
        for (int j = 0; j < _compartment_length; ++j)
        {
            if (_compartment1[i] == _compartment2[j])
            {
                match = _compartment1[i];
                i = _compartment_length;
                break;
            }
        }
    }
    return match;
}

const int Rucksack::convert_item(const char& item) const
{
    int priority;
    if (islower(item))
        priority = static_cast<int>(item) - 96;
    else if (isupper(item))
        priority = static_cast<int>(item) - 38;
    return priority;
}

const int Rucksack::get_priority() const
{ return _priority; }

const std::string& Rucksack::get_line() const
{ return _line; }

const int& Rucksack::get_length() const
{ return _line_length; }
