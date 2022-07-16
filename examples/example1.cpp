#include <iostream>
#include "mincemeat.hpp"

int main() {
	namespace mm = mincemeat;

	std::cout << mm::to_string(mm::sha256("")) << "\n";
	std::cout << "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\n";
}