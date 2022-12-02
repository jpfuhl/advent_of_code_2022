#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

const int calculate_points(const std::string& result, const std::string& choice)
{
    int score = 0;

    if (choice == "Rock")
        score += 1;
    else if (choice == "Paper")
        score += 2;
    else if (choice == "Scissors")
        score += 3;

    if (result == "Win")
        score += 6;
    else if (result == "Draw")
        score += 3;

    return score;
}

const std::string play_game(const std::pair<std::string, std::string>& round)
{
    if (round.second == "Lose")
    {
        if (round.first == "Rock")
            return "Scissors";
        else if (round.first == "Paper")
            return "Rock";
        else if (round.first == "Scissors")
            return "Paper";
    }
    else if (round.second == "Win")
    {
        if (round.first == "Rock")
            return "Paper";
        else if (round.first == "Paper")
            return "Scissors";
        else if (round.first == "Scissors")
            return "Rock";
    }
    return round.first;
}

const std::string parse_choice(const std::string& line, int pos)
{
    if (line[pos] == 'A')
        return "Rock";
    else if (line[pos] == 'B')
        return "Paper";
    else if (line[pos] == 'C')
        return "Scissors";
    else if (line[pos] == 'X')
        return "Lose";
    else if (line[pos] == 'Y')
        return "Draw";
    return "Win";
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Please provide: [./exec] [filename]" << std::endl;
        return -1;
    }

    std::ifstream input(argv[1]);
    std::vector<std::pair<std::string, std::string> > history;
    std::pair<std::string, std::string> round;
    std::string choice;
    int elf_score = 0;
    int player_score = 0;
    int i = 1;

    while (!input.eof())
    {
        std::string line;
        std::getline(input, line);

        round = make_pair(parse_choice(line, 0), parse_choice(line, 2));
        choice = play_game(round);
        player_score += calculate_points(round.second, choice);
        history.push_back(round);
        ++i;
    }
    std::cout << "Total Score of Player : " << player_score << " points." << std::endl;

    input.close();
    return 0;
}
