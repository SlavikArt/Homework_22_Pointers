#include <iostream>
using namespace std;

void First();

void Second();

void Third();

void addColumn(int** arr, int rows, int cols, int index);

void delColumn(int** arr, int rows, int cols, int index);

bool isCorrectNumber(string phone);

int main()
{
	First();
	cout << "\n";
	Second();
	cout << "\n";
	Third();
}

void First()
{
	srand(time(0));

	int rows = 5;
	int cols = 3;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}

	cout << "Add Column:\n\n";
	cout << "Array Before:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

	addColumn(arr, rows, cols, 1);
	cols++;

	cout << "\nArray After:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void Second()
{
	srand(time(0));

	int rows = 5;
	int cols = 3;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}

	cout << "Del Column:\n\n";
	cout << "Array Before:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

	delColumn(arr, rows, cols, 1);
	cols--;

	cout << "\nArray After:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void Third()
{
	int choice = 0;
	int count = 1;
	int data = 2;

	string** db = new string * [count];

	for (int i = 0; i < data; i++)
	{
		db[i] = new string[data];
	}

	string name = "";
	string phone = "0";

	do
	{
		cout << "DB: What do you want to do?\n\n";
		cout << "1. Add new data to DB.\n";
		cout << "2. Search data in DB.\n";
		cout << "3. View all data in DB.\n";
		cout << "4. Exit.\n\n";

		cin >> choice;

		if (choice == 1)
		{
			name = "";
			phone = "";

			while (true)
			{
				cout << "Enter new name: ";
				cin >> name;
				cout << "Enter new phone (+380...): ";
				cin >> phone;

				if ((phone[0] == '+') && isCorrectNumber(phone) && (name != ""))
				{
					break;
				}
			}
			db[count - 1][0] = name;
			db[count - 1][1] = phone;

			count++;
			cout << "Added: " << name << ", " << phone << "\n\n";
		}
		else if (choice == 2)
		{
			int search_choice = 0;

			cout << "You want to search by:\n";
			cout << "1 - Name\n";
			cout << "2 - Phone\n";
			cout << "Please, enter (1 or 2): ";

			while (true)
			{
				cin >> search_choice;
				if ((search_choice == 1) || (search_choice == 2))
				{
					break;
				}
			}
			
			if (search_choice == 1)
			{
				bool found = false;

				do
				{
					string search_name = "";
					
					cout << "Write name: ";
					cin >> search_name;

					for (int i = 0; i < count - 1; i++)
					{
						if (search_name == db[i][0])
						{
							found = true;
							cout << "I found it!\n";
							cout << db[i][0] << ": " << db[i][1] << "\n";
						}
					}
				} while (!found);
				
			}
			else if (search_choice == 2)
			{
				bool found = false;

				do
				{
					string search_phone = "";

					cout << "Write phone (full or not): ";
					cin >> search_phone;

					for (int i = 0; i < count - 1; i++)
					{
						int cnt = 0;

						for (int j = 0; j < search_phone.size(); j++)
						{
							if (db[i][1][j] == search_phone[j])
							{
								cnt++;
							}
							if (cnt == 5)
							{
								cout << db[i][0] << ": " << db[i][1] << "\n";
								break;
							}
						}
					}
				} while (!found);
			}
		}
		else if (choice == 3)
		{
			for (int i = 0; i < count - 1; i++) 
			{
				cout << db[i][0] << ": " << db[i][1] << "\n";
			}
			cout << "That's all!\n";
		}
	} while (choice != 4);

	for (int i = 0; i < count; i++) 
	{
		delete[] db[i];
	}
	delete[] db;
}

void addColumn(int** arr, int rows, int cols, int index) {
	for (int i = 0; i < rows; i++)
	{
		int temp = 0;
		int* newRow = new int[cols + 1];

		for (int j = 0; j < cols; j++)
		{
			if (j == index)
			{
				newRow[temp] = 0;
				temp++;
			}

			newRow[temp] = arr[i][j];
			temp++;
		}

		delete[] arr[i];
		arr[i] = newRow;
	}
}

void delColumn(int** arr, int rows, int cols, int index) {
	for (int i = 0; i < rows; i++)
	{
		int temp = 0;
		int* newRow = new int[cols - 1];

		for (int j = 0; j < cols; j++)
		{
			if (j != index)
			{
				newRow[temp] = arr[i][j];
				temp++;
			}
		}

		delete[] arr[i];
		arr[i] = newRow;
	}
}

bool isCorrectNumber(string phone)
{
	string nums = "+0123456789";
	bool cor = false;

	for (int i = 0; i < phone.size(); i++)
	{
		cor = false;
		for (int j = 0; j < nums.size(); j++)
		{
			if (phone[i] == nums[j])
			{
				cor = true;
				break;
			}
		}
		if (!cor)
		{
			return false;
		}
	}
	return true;
}