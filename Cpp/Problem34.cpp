#include <iostream>
using namespace std;

unsigned int factorial(int numb)
	{
	if (numb == 0)
		{
		return 1;
		}
	return numb * factorial(numb-1);
	}


int converter(int numb)
	{
	double sum = 0;
	auto genConv = to_string(numb);
	for (int i = 0; i < genConv.size(); i++)
		{
		auto temp_str = genConv.substr(i,1);
		auto temp_numb = stoi(temp_str, nullptr, 10);
		sum += factorial(temp_numb);
		}
	return sum;
	}


int main()
	{
	char release;
	double sum = 0;
	for (int i = 3; i < 100000; i++)
		{
		if (i == converter(i))
			{
			sum += i;
			}
		}
	cout << "Sum: " << sum << endl;
	
	cin >> release;
	return 0;
	}