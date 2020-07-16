//Ian Maze
//COP2000.0M1
//Double Array Sorting Program

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Snowfall { //Created class called Snowfall
private:
	void assignData(int x[], float y[]); //Function prototype that sorts that data

public:
	void programEnd(); //Function prototype that produces the end lines for the program
	void programStart(); //Function protoype that produces the begininng text
	void getData(int x[], float y[]); //Function prototype that grabs the data
	void showData(int x[], float y[]); //Function prototype that displays the data
};

int main() {
	Snowfall Snow; //Class
	fstream inputFile;
	int days[7]; //Array that stores the dates in Dec
	float feet[7]; //Array that stores inches on each date in Dec
	int counter = 0; //Counter variable for loop that reads in data to both arrays

	
	inputFile.open("decInches.txt");

	while (inputFile >> days[counter] >> feet[counter]) { //Loop that reads file data into both arrays
		counter++;
	}
		Snow.programStart();
		Snow.showData(days, feet);
		Snow.getData(days, feet);
		Snow.programEnd();
	return 0;
}

void Snowfall::programStart() {
	cout << "\n\n-------------------------------------- December Daily Snow Program! -----------------------------------------\n";
	cout << "-------------------------------------------------------------------------------------------------------------";
	cout << "\n\nThis program will read the Decinches txt file and input the data into 2 seven element arrays.\n";
	cout << "Then it will sort the datat from the days in December that had the most and least inches of snow.";

	cout << "\n\nProcessing file.......";

	cout << "\n\nDisplaying data now.....\n\n";
};

void Snowfall::programEnd() {
	cout << "\n\n-------------------------------------------------------------------------------------------------------------\n";
	cout << "-------------------------------------------------------------------------------------------------------------\n\n";
};

void Snowfall::getData(int x[], float y[]) {
	assignData(x, y);
	cout << "\nDisplaying Sorted Data.......\n\n";
	showData(x, y);
};

void Snowfall::showData(int x[], float y[]) { //Function Definition that displays the arrays
	int count = 0;

	cout << "Snow Report  December 12 - 18\n\n";
	cout << "Date   Base\n";


	while (count < 7) {
		cout << " " << x[count] << "    " << y[count] << endl;
		count++;
	}
};

void Snowfall::assignData(int x [], float y[]) { //Function Definition that sorts the arrays
	int tempint = 0;
	float temp = 0;
	bool swap;

	do {
		swap = false;
		for (int count = 0; count < 6; count++) {
			if (y[count] > y[count + 1]) {
				tempint = x[count];
				temp = y[count];
				x[count] = x[count + 1];
				y[count] = y[count + 1];
				x[count + 1] = tempint;
				y[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
};