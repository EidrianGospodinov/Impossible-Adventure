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
	string keyword;
	bool newBlock = false;
	// Use a while loop together with the getline() function to read the file line by line
	while (std::getline(file, line)) {
		// Output the text from the file
		if (line.empty()) {
			newBlock = true;
			keyword = " ";
			
			std:: cout << "1111111111111111";
		}
		/*std::cout << line<<std::endl;*/
		/*std::istringstream iss(line);
		iss >> keyword;*/

		if (line.find("Item:") != std::string::npos) {
			keyword = "Item";
			name=line.substr(5);
		}
		else if (line.find("Location:") != std::string::npos) {
			keyword = "Location";
			processInputLocation(line.substr(9));
		}
		if(newBlock == false) {
			string temp;
			if (keyword == "Item") {
				if (line.find("Description:") != std::string::npos) {
					
					description=line.substr(12);
				}
				if (line.find("Contents:") != std::string::npos) {

					temp = line.substr(9);
					string tempItem;
					int i = 0;
					while (temp[i] != '\0') {
						if (temp[i] == ',') {
							contents.push_back(findItem(tempItem));
							tempItem = " ";
							i++;
						}
						tempItem += temp[i];

						i++;
					}
					
				}
				if (line.find("Keys:") != std::string::npos) {

					temp = line.substr(5);
					keyItem=findItem(temp);
					
				}
				
				
			}
			else if (keyword == "Location") {

			}
			
		}
		else
		{
			processInputItem(" ");
			clearVariables();
		}

		


	}

	// Close the file
	file.close();
}

void InputFile::processInputItem(string s)
{
	Item* item;
	if (!contents.empty()) {

		 item = new Item(name, description);
	}
	else {
		 item = new Container(name, description, keyItem, contents);
	}

	std::cout << std::endl;
	/*std::cout<<item->getName();
	std::cout<<item->getDescription();*/
	std::cout << std:: endl;
	//if (item != nullptr)
	allItems.push_back(item);
}

Item* InputFile::findItem(string temp)
{
	for (auto i : allItems)
	{
		if (i->getName() == temp) {
			return i;
		}
	}
	return nullptr;
}
















void InputFile::processInputLocation(string s)
{
	//std::cout<<s;
}

void InputFile::clearVariables()
{
	name = " ";
	description = " ";
	contents.clear();
	keyItem = nullptr;
}
