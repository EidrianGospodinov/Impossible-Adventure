#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;


int main() {

	//char arr[100];

	char sep = ' ';
	int i = 0;
	string arr;
	getline(cin,arr);
	//cin.getline(arr, 100);
	string keyword;
	string desc;
	
	bool iskeyword=true;
	
	while (i <= arr.size())
	{
		if (arr[i] == sep&&iskeyword!=false) {
			iskeyword = false;
		}

		else if ( iskeyword!=false) {
			keyword += arr[i];
			
		}
		else
		{
			desc += arr[i];
		}
		
		i++;
	} 
	cout << keyword << endl;
	if(desc!="")
	cout << desc;



}