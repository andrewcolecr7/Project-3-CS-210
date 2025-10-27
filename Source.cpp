//Project 3, 10/18/25, Andrew Cole

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Class to search for Items in list
class StoreItems
{
public: //creating public functions
	void Menu();
	void FindItem(string inputWord);
	ifstream file;
	void PrintList();
	void Border();
	void PrintHistogram();
	void CreateFile();
private: //private variables
	string tempItem;
	int stringCompared = -1;
	int itemCount = 0;
	vector <string> foundItems;
	vector <int> itemQuantity;

};

//used to print my border between queries

void StoreItems::Border() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

//function for searching for items
void StoreItems::FindItem(string inputWord) {
	file.open("CS210_Project_Three_Input_File.txt");
	while (!file.eof()) {
		file >> tempItem;
		stringCompared = inputWord.compare(tempItem);
		if (stringCompared == 0) {
			itemCount += 1;
		}
	}
	file.close();
	foundItems.push_back(inputWord);
	itemQuantity.push_back(itemCount);
	cout << "" << endl;
	cout << inputWord << " were found " << itemCount << " times." << endl;
	cout << "" << endl;
	itemCount = 0;
}

//Creating the Corner Grocer menu function and inputting the possible choices.
void StoreItems::Menu() {
	cout << "Corner Grocer Menu:" << endl;
	cout << "Option 1: Search list for groceries" << endl;
	cout << "Option 2: Print search list" << endl;
	cout << "Option 3: Print search list histogram" << endl;
	cout << "Option 4: Quit the program" << endl;
	cout << "Please enter the number of the option you wish to use:" << endl;

}

//Used to print all searches and results
void StoreItems::PrintList() {
	int i = 0;
	Border();
	for (i = 0; i < foundItems.size(); ++i) {
		cout << foundItems[i] << " " << itemQuantity[i] << endl;
	}
	Border();
}

//Used to print all searches and results as histogram
void StoreItems::PrintHistogram() {
	int i = 0;
	int j = 0;
	Border();
	for (i = 0; i < foundItems.size(); ++i) {
		cout << foundItems[i] << " ";

		for (j = 0; j < itemQuantity[i]; ++j) {
			cout << "*";
		}
		cout << "" << endl;
	}
	Border();
}

//creates file with search results
void StoreItems::CreateFile() {
	int i = 0;
	ofstream file("frequency.dat");
	for (i = 0; i < foundItems.size(); ++i) {
		file << foundItems[i] << " " << itemQuantity[i] << endl;
	}
	file.close();

}

int main() {
	//variables + objects
	string userInputWord;
	int userInput = 0;
	StoreItems objectOne;

	//loop after a succesful option
	while (userInput != 4) {
		objectOne.Menu();
		cin >> userInput;

		//loop for input validation
		while (!cin) {
			cout << "Invalid input! Please enter an integer." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> userInput;
		}

		//if-else statements
		if (userInput == 1) {
			userInput = 0;
			cin.clear();
			cout << "What item would you like to search for?" << endl;
			cin >> userInputWord;
			objectOne.FindItem(userInputWord);
		}
		else if (userInput == 2) {
			objectOne.PrintList();
			userInput = 0;
		}
		else if (userInput == 3) {
			objectOne.PrintHistogram();
			userInput = 0;
		}
		else if (userInput == 4) {
			cout << "You have chosen to end the program." << endl;
		}
		else {
			cout << "Invalid selection" << endl;
			cin.clear();
			userInput = 0;
		}
	}

	//exit message and creating the file
	cout << "Application closed and your data file has been created." << endl;
	objectOne.CreateFile();

	return 0;
}
