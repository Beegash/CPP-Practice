#ifndef SEDREPLACE_HPP
#define SEDREPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class SedReplace
{
public:
    static void replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2);
};

#endif
