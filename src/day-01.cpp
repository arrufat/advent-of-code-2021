#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

auto main([[maybe_unused]] const int argc, [[maybe_unused]] const char** argv) -> int
try
{
    std::ifstream fin("data/day-01/input");
    std::vector<int> report;
    for (std::string line; std::getline(fin, line);)
        report.push_back(std::stoi(line));

    const auto part1 = [](std::vector<int> report)
    {
        std::adjacent_difference(report.begin(), report.end(), report.begin());
        const auto n_inc =
            std::count_if(report.begin() + 1, report.end(), [](const auto e) { return e > 0; });
        std::cout << n_inc << std::endl;
    };

    const auto part2 = [](std::vector<int> report)
    {
        std::vector<int> sums;
        for (size_t i = 0; i < report.size() - 2; ++i)
        {
            sums.push_back(report[i] + report[i + 1] + report[i + 2]);
        }
        std::adjacent_difference(sums.begin(), sums.end(), sums.begin());
        const auto n_inc =
            std::count_if(sums.begin() + 1, sums.end(), [](const auto e) { return e > 0; });
        std::cout << n_inc << std::endl;
    };

    part1(report);
    part2(report);

    return EXIT_SUCCESS;
}
catch (const std::exception& e)
{
    std::cout << e.what() << std::endl;
}
