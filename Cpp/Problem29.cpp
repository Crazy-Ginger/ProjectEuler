#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool check(double numb, vector <double> numbers)
	{
	for (int i = 0; i < numbers.size(); i++)
		{
		if (numbers[i] == numb)
			{
			return false;
			}
		}
	return true;
	}

int main()
	{
	char release;
	vector <double> numbers;
	for (double i = 2; i <= 100; i++)
		{
		for (double a = 2; a<= 100; a++)
			{
			double temp = pow(i, a);
			if (check(temp, numbers) == true)
				{
				numbers.push_back(temp);
				}
			}
		}
	cout << "Size: " << numbers.size() << endl;
	cin >> release;
	return 0;
	}