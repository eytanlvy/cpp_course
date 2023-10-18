#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	srand(time(nullptr));
	int x { rand()%100 };
	int y { rand()%100 };
	
	int result = x + y + 1;

	while (result != x + y) {
		std::cout << x << " + " << y << " = "; // Type a number and press enter
		std::cin >> result; // Get user input from the keyboard
		std::cout << "You entered: " << result << std::endl; // Display the input value*
		if (result == x + y) {
			std::cout << "Good job!" << std::endl;
		} else {
			std::cout << "Try again!" << std::endl;
		}
	}

}