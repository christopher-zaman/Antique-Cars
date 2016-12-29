#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//create a class
class cars {
public:
	string Model;
	double MPG;
	double horsePower;
	string origin;
};

//Load File Function
void LoadFile(cars data[], int&count)
{
	ifstream f("C:\\Users\\christopherzaman\\Desktop\\cars.txt");
	if (f.good())
	{
		while (!f.eof())
		{
			f >> data[count].Model;
			f >> data[count].MPG;
			f >> data[count].horsePower;
			f >> data[count].origin;
			count++;
		}
	}
	f.close();
}

//Search Car Function
void searchCar(cars data[], int count)
{
	cout << "Required Min. MPG: " << endl;
	double minMPG;
	cin >> minMPG;

	cout << "Required Min. Horsepower: " << endl;
	double minHorsePower;
	cin >> minHorsePower;

	for (int i = 0; i < count; i++)
	{
		if (data[i].MPG >= minMPG && data[i].horsePower >= minHorsePower)
		{
			cout << data[i].Model << endl;
		}
	}
}

// Best and Worst Green Cars
void bestAndWorst(cars data[], int count)
{
	double lowest = 999;
	double highest = 0;
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		if (data[i].MPG > highest)
		{
			highest = data[i].MPG;
		}
		sum += data[i].MPG;

		if (data[i].MPG < lowest)
		{
			lowest = data[i].MPG;
		}
	}
	double avg = sum / count;
	cout << "Avg. MPG of all cars is : " << avg << endl;
	cout << "Greenest car is: " << highest << endl;
	cout << "Worst car is: " << lowest << endl;
}

// Inventory by Origin
void origin(cars data[], int count)
{
	cout << "Enter Origin" << endl;
	string userOrigin;
	cin >> userOrigin;

	double originSum = 0;
	for (int i = 0; i < count; i++)
	{
		if (userOrigin == data[i].origin)
		{
			originSum++;
		}
	}
	cout << "We have " << originSum << " " << userOrigin << " cars in the inventory." << endl;
}

// Report All
void reportAll(cars data[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i].Model << " " << data[i].MPG << " " << data[i].horsePower << " " << data[i].origin << " " << endl;
	}
}

int main()
{
	//Create an array of type class
	cars data[500];
	int count = 0;

	//Read the file
	LoadFile(data, count);

	while (true)
	{
		cout << "Antique Car search" << endl;
		cout << "==================" << endl;
		cout << "1- Search Car" << endl;
		cout << "2- Green Best/Worst Report" << endl;
		cout << "3- Car origin Report" << endl;
		cout << "0- Exit" << endl;
		cout << "Make a choice:" << endl;
		int choice;
		cin >> choice;

		//Search Car
		if (choice == 1)
		{
			searchCar(data, count);
		}

		// Avg, best and worst green cars
		else if (choice == 2)
		{
			bestAndWorst(data, count);
		}

		// Inverntory by Origin
		else if (choice == 3)
		{
			origin(data, count);
		}

		//Report All
		else if (choice == 4)
		{
			reportAll(data, count);
		}

		//Break
		else if (choice == 0)
		{
			cout << "Thank you for using Antique Car Search" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}