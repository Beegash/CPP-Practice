#include "SedReplace.hpp"

void SedReplace::replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
    if (s1.empty() || s2.empty())
    {
        std::cerr << "Error: Strings are empty" << std::endl;
        return;
    }
    if (s1 == s2)
    {
        std::cerr << "Strings are identical." << std::endl;
        return;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Cannot create output file " << outputFilename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t searchPosition = 0;

        while ((searchPosition = line.find(s1, searchPosition)) != std::string::npos)
        {
            line.erase(searchPosition, s1.length());
            line.insert(searchPosition, s2);
            searchPosition += s2.length();
        }
        outputFile << line;
        if (!inputFile.eof())
        {
            outputFile << std::endl;
        }
    }
    inputFile.close();
    outputFile.close();
}
