#include <iostream>
#include <math.h>
#include <typeinfo>
using namespace std;

int seperator(int numb)
	{
	char release;
	double sum = 0;
	auto genConv = to_string(numb);
	for (int i = 0; i < genConv.size(); i++)
		{
		auto temp_str = genConv.substr(i,1);
		auto temp_numb = stoi(temp_str, nullptr, 10);
		sum += pow(temp_numb, 5);
		}
	return sum;
	}

int main()
	{
	char release;
	int sum = 0;
	int largest;
	for (int i = 2; i < 200000; i++)
		{
		if (i == seperator(i))
			{
			sum += i;
			largest = i;
			}
		}	
	cout << "Sum: " << sum << endl;
	cout << "Largest: " << largest << endl;

	cin >> release;
	return 0;
	}