#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Function to convert a character to its octal representation
static string toOctal(unsigned char c) {
	int charCode = static_cast<int>(c);
	string octalString = "";
	for (int i = 0; i < 3; ++i) { // Each character takes up to 3 octal digits
		octalString = to_string(charCode % 8) + octalString;
		charCode /= 8;
	}
	return octalString;
}

int main() {
	string input;

	// Input 8 characters
	cout << "Enter 8 characters: ";
	getline(cin, input);

	// Check for correct input
	if (input.length() != 8) {
		cerr << "Error: Not 8 characters entered." << endl;
		return 1;
	}


	string transformedInput = input; // Create a copy for transformation

	// Transform characters
	for (int i = 0; i < 8; ++i) {
		unsigned char& c = (unsigned char&)transformedInput[i]; // Get a reference to the character for modification as unsigned char
		int charCode = static_cast<int>(c); // Get the character code

		if (charCode % 2 == 0)
			// Even character code: replace the least significant bit with 1
			c = static_cast<unsigned char>(charCode | 0x01); // 0x01 = 00000001 (1 in the least significant bit)
		else
			// Odd character code: replace the two least significant bits with 0
			c = static_cast<unsigned char>(charCode & ~0x03); // 0x03 = 00000011 (11 in the least significant bits)
	}

	// Output results
	cout << "Original sequence: " << input << endl;
	cout << "Transformed sequence: " << transformedInput << endl;

	cout << "Original sequence (octal representation): ";
	for (char c : input) {
		cout << toOctal((unsigned char)c) << " "; // Cast char to unsigned char for toOctal
	}
	cout << endl;

	cout << "Transformed sequence (octal representation): ";
	for (char c : transformedInput) {
		cout << toOctal((unsigned char)c) << " "; // Cast char to unsigned char for toOctal
	}
	cout << endl;

	return 0;
}