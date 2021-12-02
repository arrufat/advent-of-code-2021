#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto main([[maybe_unused]] const int argc, [[maybe_unused]] const char** argv) -> int
try
{

    const auto part1 = []()
    {
        std::ifstream fin("data/day-02/input");
        int pos_x = 0, pos_y = 0;
        for (std::string line; std::getline(fin, line);)
        {
            std::istringstream sin(line);
            std::string direction;
            int amount;
            sin >> direction >> amount;
            if (direction == "up")
                pos_y -= amount;
            if (direction == "down")
                pos_y += amount;
            if (direction == "forward")
                pos_x += amount;
        }
        std::cout << pos_x * pos_y << std::endl;
    };

    const auto part2 = []()
    {
        std::ifstream fin("data/day-02/input");
        int pos_x = 0, pos_y = 0, aim = 0;
        for (std::string line; std::getline(fin, line);)
        {
            std::istringstream sin(line);
            std::string direction;
            int amount;
            sin >> direction >> amount;
            if (direction == "up")
            {
                aim -= amount;
            }
            if (direction == "down")
            {
                aim += amount;
            }
            if (direction == "forward")
            {
                pos_x += amount;
                pos_y += amount * aim;
            }
        }
        std::cout << pos_x * pos_y << std::endl;
    };

    part1();
    part2();
    return EXIT_SUCCESS;
}
catch (const std::exception& e)
{
    std::cout << e.what() << std::endl;
}
