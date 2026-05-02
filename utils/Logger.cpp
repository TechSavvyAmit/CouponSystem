#include "Logger.h"
#include <fstream>
#include <ctime>

void Logger::log(const std::string &message)
{
    std::ofstream file("logs/app.log", std::ios::app);

    std::time_t now = std::time(nullptr);
    file << std::ctime(&now) << " : " << message << std::endl;
}