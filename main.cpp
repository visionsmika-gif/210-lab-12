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

	if (!inputFile) {
		cout << "ERROR: Unable to open " << FILE_NAME << ". Please ensure that the file is in the same directory as the program.\n";
		return 1;
	}

	// Read the file into the array
	for (int i = 0; i < SIZE; ++i) {
		if (!(inputFile >> prices[i])) {
			cout << "ERROR: There was an error reading " << FILE_NAME << ". Please check that the file is in the proper format.\n";
		}
	}

	inputFile.close();

	return 0;
}