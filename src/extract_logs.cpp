#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void extractLogsByDate(const std::string& logFile, const std::string& date, const std::string& outputDir) {
    if (date.empty()) {
        std::cerr << "Please provide a date in YYYY-MM-DD format." << std::endl;
        return;
    }

    std::filesystem::path outputPath = outputDir;
    outputPath /= "output_" + date + ".txt"; // Append filename to the directory

    // Ensure output directory exists
    if (!std::filesystem::exists(outputDir)) {
        std::filesystem::create_directories(outputDir);
    }

    std::ifstream logF(logFile);
    std::ofstream outF(outputPath);

    if (!logF.is_open()) {
        std::cerr << "Error: Unable to open log file: " << logFile << std::endl;
        return;
    }
    if (!outF.is_open()) {
        std::cerr << "Error: Unable to create output file: " << outputPath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(logF, line)) {
        if (line.rfind(date, 0) == 0) { // Check if line starts with the date
            outF << line << std::endl;
        }
    }

    std::cout << "✅ Log entries for " << date << " saved to: " << outputPath << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <YYYY-MM-DD>" << std::endl;
        return 1;
    }

    std::string date = argv[1];
    std::string logFile = "../logs_2024.log"; // Change to actual log file path
    std::string outputDir = "../output/output_2024-12-01.txt"; // Change to actual output directory

    extractLogsByDate(logFile, date, outputDir);
    return 0;
}
