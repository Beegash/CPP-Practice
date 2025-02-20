#include "SedReplace.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }
    SedReplace::replaceInFile(argv[1], argv[2], argv[3]);
    return 0;
}
