#include "Rucksack.hpp"
#include <vector>

int convert_item(const char& item)
{
    int priority;
    if (islower(item))
        priority = static_cast<int>(item) - 96;
    else if (isupper(item))
        priority = static_cast<int>(item) - 38;
    return priority;
}

char find_item_in_group(const std::vector<std::string>& lines, const std::vector<int>& lengths)
{
    char tmp;
    for (int i = 0; i < lengths[0]; ++i)
    {
        for (int j = 0; j < lengths[1]; ++j)
        {
            if (lines[0][i] == lines[1][j])
            {
                for (int k = 0; k < lengths[2]; ++k)
                {
                    if (lines[0][i] == lines[2][k])
                    {
                        tmp = lines[0][i];
                        i = lengths[0];
                        j = lengths[1];
                        break;
                    }
                }
            }
        }
    }
    return tmp;
}

int main()
{
{
    // PART 1
    std::ifstream input("input.txt");
    int priority_sum = 0;
    int index = 1;

    while (!input.eof())
    {
        std::string line;
        std::getline(input, line);

        Rucksack rucksack(line, index);
        priority_sum += rucksack.get_priority();
        ++index;
    }
    std::cout << "ITEM : Priority sum is " << priority_sum << "." << std::endl;
    input.close();
}
{
    // PART 2
    std::ifstream input("input.txt");
    int priority_sum = 0;
    int index = 1;
    
    while (!input.eof())
    {
        {
            std::vector<std::string> lines;
            std::vector<int> lengths;

            for (int i = 0; i < 3; ++i)
            {
                std::string line;
                std::getline(input, line);
                Rucksack rucksack(line, index);

                lines.push_back(rucksack.get_line());
                lengths.push_back(rucksack.get_length());
                ++index;
            }

            char tmp = find_item_in_group(lines, lengths);
            priority_sum += convert_item(tmp);
        }
    }
    std::cout << "GROUP : Priority sum is " << priority_sum << "." << std::endl;
    input.close();
}
    return 0;
}
