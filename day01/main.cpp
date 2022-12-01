#include <iostream>
#include <fstream>
#include <map>
#include <utility>


int main(int argc, char *argv[])
{
    // format for executing program
    if (argc != 2)
    {
        std::cout << "Please provide: [./exec] [filename]" << std::endl;
        return -1;
    }


    // open file
    std::ifstream input(argv[1]);


    // map<calories, ID> elves, so calories will be ordered by insertion;
    std::map<int, int> elves;
    int elf_id = 1;
    int item_calories = 0;
    int sum_calories = 0;


    while (!input.eof())
    {
        std::string buffer;
        getline(input, buffer);

        // empty line means current elf is done counting calories
        if (buffer.length() == 0)
        {
            elves.insert(std::make_pair(sum_calories, elf_id));
            ++elf_id;
            sum_calories = 0;
        }
        else
            sum_calories += std::stoi(buffer);
    }


    // getting the top 3 elves with the most calories
    std::map<int, int>::reverse_iterator rit = elves.rbegin();
    int total_sum_calories = 0;

    for (int i = 1; i < 4; ++i)
    {
        std::cout << i <<".) Elf " << rit->second << " carries " << rit->first << " calories." << std::endl;
        total_sum_calories += rit->first;
        ++rit;
    }
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Total sum : " << total_sum_calories << " calories." << std::endl;


    input.close();
    return 0;
}
