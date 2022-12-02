#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

#define ELF 0
#define PLAYER 1
#define DRAW 2


const int calculate_points(const std::string& round, const int& winner, bool is_elf)
{
    int score = 0;

    if (round == "Rock")
        score += 1;
    else if (round == "Paper")
        score += 2;
    else if (round == "Scissors")
        score += 3;

    if (winner == ELF && is_elf)
        score += 6;
    else if (winner == PLAYER && !is_elf)
        score += 6;
    else if (winner == DRAW)
        score += 3;

    return score;
}

const int play_game(const std::pair<std::string, std::string>& round)
{
    if (round.first != round.second)
    {
        if (round.first == "Scissors")
        {
            if (round.second == "Paper")
                return ELF;
            else
                return PLAYER;
        }

        else if (round.first == "Rock")
        {
            if (round.second == "Scissors")
                return ELF;
            else
                return PLAYER;
        }

        else if (round.first == "Paper")
        {
            if (round.second == "Rock")
                return ELF;
            else
                return PLAYER;
        }
    }
    return DRAW;
}

const std::string parse_choice(const std::string& line, int pos)
{
    if (line[pos] == 'A' || line[pos] == 'X')
        return "Rock";
    else if (line[pos] == 'B' || line[pos] == 'Y')
        return "Paper";
    return "Scissors";
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
    int winner;
    int elf_score = 0;
    int player_score = 0;
    int i = 1;

    while (!input.eof())
    {
        std::string line;
        std::getline(input, line);

        round = make_pair(parse_choice(line, 0), parse_choice(line, 2));
        winner = play_game(round);
        elf_score += calculate_points(round.first, winner, true);
        player_score += calculate_points(round.second, winner, false);
        history.push_back(round);
        ++i;
    }
    std::cout << "Total Score of Elf : " << elf_score << " points." << std::endl;
    std::cout << "Total Score of Player : " << player_score << " points." << std::endl;

    input.close();
    return 0;
}
