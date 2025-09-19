// Program that exercises STD::array functions
// Real-world simulation of something
// Requirements: use STD::array, have external data file with at least 30 elements, read the data into array, use a large variety of array member functions

#include <iostream>
#include <array>
#include <fstream>

using namespace std;

int main() {
	const int SIZE = 30;
	array<double, SIZE> prices;
	const string FILE_NAME = "prices.txt";
	ifstream inputFile(FILE_NAME);

	// Ensure that the file is open
	if (!inputFile) {
		cout << "ERROR: Unable to open " << FILE_NAME << ". Please ensure that the file is in the same directory as the program.\n";
		return 1;
	}
	// Read the file into the array
	for (int i = 0; i < SIZE; ++i) {
		if (!(inputFile >> prices[i])) {
			cout << "ERROR: There was an error reading " << FILE_NAME << ". Please check that the file is in the proper format.\n";
			return 1;
		}
	}
	inputFile.close();

	// Use size() member function
	cout << "The inventory contains a list of " << prices.size() << " prices.\n";

	// Use empty() member function
	cout << "The price list is " << (prices.empty() ? "empty" : "not empty") << ".\n";

	// Use front() and back() member functions
	cout << "The price of the first item is $" << prices.front() << ".\n";
	cout << "The price of the last item is $" << prices.back() << ".\n";

	// Find the maximum, minimum, and sum of the array
	cout << "The most expensive item costs $" << *max_element(prices.begin(), prices.end()) << ".\n";
	cout << "The cheapest item costs $" << *min_element(prices.begin(), prices.end()) << ".\n";

	return 0;
}