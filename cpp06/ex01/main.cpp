#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	std::cout << "Testing Serializer functionality:" << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << std::endl;

	std::cout << "Test 1: Basic serialization" << std::endl;
	std::cout << "---------------------------" << std::endl;
	Data *original = new Data(42, "Test Data");

	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Original data - value: " << original->value
			  << ", name: " << original->name
			  << std::endl;

	uintptr_t serialized = Serializer::serialize(original);
	std::cout << "Serialized value: " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized pointer: " << deserialized << std::endl;
	std::cout << "Deserialized data - value: " << deserialized->value
			  << ", name: " << deserialized->name
			  << std::endl;

	std::cout << "Pointers are equal: " << (original == deserialized ? "true" : "false") << std::endl;

	delete original;
	std::cout << std::endl;

	std::cout << "Test 2: Different data values" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	Data *test2 = new Data(-123, "Another Test");

	std::cout << "Original pointer: " << test2 << std::endl;
	std::cout << "Original data - value: " << test2->value
			  << ", name: " << test2->name
			  << std::endl;

	uintptr_t serialized2 = Serializer::serialize(test2);
	Data *deserialized2 = Serializer::deserialize(serialized2);

	std::cout << "Pointers are equal: " << (test2 == deserialized2 ? "true" : "false") << std::endl;
	std::cout << "Data integrity: " << (test2->value == deserialized2->value && test2->name == deserialized2->name && test2->name.length() == deserialized2->name.length() ? "true" : "false") << std::endl;

	delete test2;
	std::cout << std::endl;

	std::cout << "Test 3: Null pointer test" << std::endl;
	std::cout << "------------------------" << std::endl;
	Data *nullPtr = nullptr;
	uintptr_t serializedNull = Serializer::serialize(nullPtr);
	Data *deserializedNull = Serializer::deserialize(serializedNull);

	std::cout << "Null pointer serialized: " << serializedNull << std::endl;
	std::cout << "Null pointer deserialized: " << deserializedNull << std::endl;
	std::cout << "Null pointers are equal: " << (nullPtr == deserializedNull ? "true" : "false") << std::endl;

	return 0;
}
