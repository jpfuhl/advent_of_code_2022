#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

int main()
{
    std::ifstream file("input.txt");
    int n_marker = 14;

    std::string line;
    std::getline(file, line);
    std::string::iterator it = line.begin();

    int pos = 0;
    int size = 0;
    for (; it != line.end() - (n_marker + 1); ++it)
    {
        for (int i = 0; i < n_marker; ++i)
            std::cout << *(it + i);
        std::cout << "\t";

        std::set<char> message(it, it + n_marker);
        std::set<char>::iterator set_it = message.begin();
        size = message.size();

        for (; set_it != message.end(); ++set_it)
            std::cout << *set_it;
        std::cout << "\tsize : " << message.size() << "\t pos : "<< pos << std::endl;
    
        if (size == n_marker)
            break;

        ++pos;
    }
    std::cout << "Marker after : " << pos + n_marker << std::endl;

    file.close();
    return 0;
}
