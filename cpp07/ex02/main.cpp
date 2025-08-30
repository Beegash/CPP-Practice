#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;

        for (unsigned int i = 0; i < intArray.size(); i++)
        {
            intArray[i] = i * 10;
        }

        std::cout << "Int array elements: ";
        for (unsigned int i = 0; i < intArray.size(); i++)
        {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        Array<int> intArrayCopy(intArray);
        std::cout << "Copied int array elements: ";
        for (unsigned int i = 0; i < intArrayCopy.size(); i++)
        {
            std::cout << intArrayCopy[i] << " ";
        }
        std::cout << std::endl;

        Array<int> intArrayAssign;
        intArrayAssign = intArray;
        std::cout << "Assigned int array elements: ";
        for (unsigned int i = 0; i < intArrayAssign.size(); i++)
        {
            std::cout << intArrayAssign[i] << " ";
        }
        std::cout << std::endl;

        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "C++";

        std::cout << "String array elements: ";
        for (unsigned int i = 0; i < stringArray.size(); i++)
        {
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;

        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        std::cout << "Testing out of bounds access..." << std::endl;
        intArray[10];
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: Out of bounds access!" << std::endl;
    }

    return 0;
}
