#include "InputFile.h"

list<Location*>InputFile::allLocations;//define static member

//consructor
InputFile::InputFile(string fName): file(fName)
{
	if (!file.is_open())//check if the file can not be opened, the following message is diplayed
		std::cerr << "Error opening file: " << fName<<std::endl;
	//cerr does the same thing as cout but its imediatly displayed in the console
	numberOfLocation = 1;
}


//read file and process data
void InputFile::readFile()
{
	
	
	// Use a while loop together with the getline() function to read the file line by line
	while (std::getline(file, line)) {
		// Output the text from the file
		if (line.empty()) {
			newBlock = true;
			//keyword = " ";
			
			
		}
		
		//std::npos is what std:: find return instead of false/-1
		if (line.find("Item:") != std::string::npos) {
			keyword = "Item";
			name=line.substr(6);
		}
		else if (line.find("Location:") != std::string::npos) {
			keyword = "Location";
			numberOfLocation=stoi(line.substr(10));
		}


		if(newBlock == false) {//every time there is an empty line the newblock is true
			//indicationg that we are moving from one block to another
			
			if (keyword == "Item") {
				setInput();//the input is for description and contents 
				
				if (line.find("Keys:") != std::string::npos) {

					temp = line.substr(6);
					keyItem=findItem(temp);
					
				}
				
				
			}
			else if (keyword == "Location") {
				if (line.find("Name:") != std::string::npos) {

					name = line.substr(6);
				

				}else
				{
				setInput();//the input is for description and contents 
				string direction;
				int charNum = 0;
				
				charNum = line.find_first_of(" ");//get the postion of the first empty space on the line
				direction = line.substr(0, charNum);//get a substring from the begining to the empty space
				if (searchDirection(direction))
				{
					
					if (line.find_first_of(",") != -1) {
						keyItemsMap.insert({ direction, findItem(line.substr(charNum + 4)) });

					}
					else
						keyItemsMap.insert({ direction,nullptr });

					connectionsMap.insert({ direction,stoi(line.substr(charNum + 1,1)) });
				}
				}

			}
			
		}
		else//now that we have an empty line we are processing the input
		{
			if (name != " ") {//if the name is empty then there is nothing to process

				if (keyword == "Item")
					processInputItem();

				else if (keyword == "Location")
					processInputLocation();
			}

			clearVariables();//when we are done clear the variables
		}

		


	}

	// Close the file
	file.close();
	processInputLocation();//the process is happening when we excit the block.
	//so we end up not processing the last location
}


Item* InputFile::findItem(string temp)//the function checks if item we search for excist in the game
{
	for (auto i : allItems)
	{
		if (i->getName() == temp) {
			return i;
		}
	}
	return nullptr;
}

void InputFile::setInput()//set the description and contents wheb the keyword in the line mathces with keyword
{
	if (line.find("Description:") != std::string::npos) {

		description = line.substr(13);//not a magic number it comes from the length of Description: plus 2 so we skip the empty space
		//and get the right follow up
	}
	else if (line.find("Contents:") != std::string::npos) {

		temp = line.substr(10);//same logic as above
		
		string tempItem;
		int i = 0;
		while (temp[i] != '\0') {

			if (temp[i] == ',') {
				contents.push_back(findItem(tempItem));
				tempItem = "";
				i += 2;
			}
			tempItem += temp[i];

			i++;
		}
		
		contents.push_back(findItem(tempItem));

	}
}



bool InputFile::searchDirection(string direction)//check if the direction is valid
{
	for(string i: listOfDirections)
		if (i == direction) {
			return true;
		}
	return false;
}

void InputFile::processInputItem()//process all the collected data from the block and call the constructor for item
{
	Item* item;
	if (contents.empty()) {//if the contents is empty then the item is not derrieved by the container

		 item = new Item(name, description);
	}
	else {// the item has contents meaning its a container
		 item = new Container(name, description, keyItem, contents);
	}

	
	//if (item != nullptr)
	allItems.push_back(item);//stores all the items in the game
}

void InputFile::processInputLocation()//process all the data in the block and call construction for location
{
	Location* location = new Location(numberOfLocation, name, description, 
		contents,keyItemsMap,connectionsMap);
	if (numberOfLocation == 1)//if the number of location is one thats the default location
		Player::changeLocation(location);
	allLocations.push_back(location);//stores all locations in the game
}

void InputFile::clearVariables()//clear all the variables once we are out of the input block
{
	newBlock = false;
	name = " ";
	description = " ";
	contents.clear();
	keyItem = nullptr;
	keyItemsMap.clear();
	connectionsMap.clear();
	
}
