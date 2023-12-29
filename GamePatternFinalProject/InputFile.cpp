#include "InputFile.h"

InputFile::InputFile(string fName): fileName(fName),file(fName)
{
	if (!file.is_open())//check if the file can not be opened, the following message is diplayed
		std::cerr << "Error opening file: " << fileName<<std::endl;
	//cerr does the same thing as cout but its imediatly displayed in the console
}

void InputFile::readFile()
{
	string line;
	// Use a while loop together with the getline() function to read the file line by line
	while (std::getline(file, line)) {
		// Output the text from the file
		std::cout << line<<std::endl;
	}

	// Close the file
	file.close();
}
