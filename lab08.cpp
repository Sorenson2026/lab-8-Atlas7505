//Daniel Suarez
//3/10/2026

//This is a program that will process a sequence of integer values in the range of 1 through 10 read from the standard input device
// it will display the count, minimum, maximum, and average of the entered values.
#include <iostream>
#include <iomanip> //set precision 
#include <limits>

using namespace std;

int main()

{
	cout << "welcome, This is a program that will process a sequence of integer values in the range of 1 through 10 and will display the count, minimum, maximum, and average of the entered values" << endl;
	char repeat = 'y';

	while (repeat == 'y' || repeat == 'Y') {
		int num; // not initizialized to save the space
		int count = 0; // of how many numbers the user enters
		int sum = 0; // leave at cero since no numbers exist yet
		int smallest_value = numeric_limits<int>::max();
		int biggest_value = numeric_limits<int>::min();
		bool first_input = true;

		while (true)
		{
			if (first_input) {
				cout << "Enter an integer (enter 0 if you want to stop there): ";
			}
			else {
				cout << "Enter another integer (enter 0 if you want to stop there): ";
			}

			// Input validation to see if its an int and also if its in the arange from 0 to 10 
			if (!(cin >> num) || num < 0 || num > 10) {
				cout << "Invalid input. Please enter an integer between 0 and 10." << '\n';
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
				continue;
			}

			// how can the programm stop
			if (num == 0) {
				break;
			}

			// count how many numbers the user has typed in
			count++;

			// keeps adding the numbers to get the avg
			sum += num;
			if (num < smallest_value) smallest_value = num;
			if (num > biggest_value) biggest_value = num;

			first_input = false;
		}

		// Display results if at least one valid number was inpouted
		if (count > 0) {
			double average = static_cast<double>(sum) / count;

			cout << "\nCount\tMin\tMax\tAverage" << endl;
			cout << count << "\t" << smallest_value << "\t" << biggest_value << "\t"
				<< fixed << setprecision(2) << average << endl;
		}
		else {
			cout << "\nNo values were entered before the 0 was sent, please input values before the 0" << endl;
		}

		// Optional requirement: Repeat the sequence
		cout << "\nWould you like to enter another sequence? (y for yes /n for no): ";
		cin >> repeat;
		cout << endl;
	}

	return 0;
}