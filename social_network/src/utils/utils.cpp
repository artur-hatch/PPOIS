#include "utils.hpp"

std::string Utils::GetTimeNow()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%H:%M %d.%m.%Y");
    return oss.str();
}

void Utils::PauseTerminal()
{
    std::cout << "Press Enter two times to continue..." << std::endl;
    if (std::cin.fail()) {
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.sync();
    std::cin.get();
}

std::string Utils::GenerateId(std::string const & str1, std::string const & str2)
{
    std::hash<std::string> stringHasher;
    
    std::size_t hash1 = stringHasher(str1);
    std::size_t hash2 = stringHasher(str2);

    std::size_t combinedHash = hash1 ^ (hash2 << 1);

    return std::to_string(combinedHash);
}

std::string Utils::GetInput()
{
    std::string input;
    std::getline(std::cin, input);

    if (std::cin.fail()) {
        std::cerr << "Error when reading input." << std::endl;
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        return "";
    }

    return input;
}

int Utils::SafeStringToInt(const std::string& str) {
    std::istringstream iss(str);
    int number;
    char leftover;

    if (!(iss >> number) || (iss >> leftover)) {
        return -1;
    }
    return number;
}