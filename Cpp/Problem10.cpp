#include <iostream>
#include <math.h>
using namespace std;

bool check(int numb)
	{
	if (numb <= 1)
		{
		return false;
		}
	if (numb == 2)
		{
		return true;
		}
	if (numb % 2 == 0)
		{
		return false;
		}
	
	int limit;
	limit = static_cast <int> (sqrt(numb) + 1);
	
	for (int i = 3; i <= limit; i += 2)
		{if (numb %i == 0)
			{return false;
		}}
	return true;
	}

unsigned long long finalSum()
	{
	const int Max = 2000000;
	unsigned long long sum = 0;
	for (int i = 2; i < Max; ++i)
		{
		if (check(i))
			{
			sum += i;
			//cout << sum << endl;
			}
		}
	return sum;
	}

int main()
	{
	cout << "The final total is: " << finalSum() << endl;
	
	char release;
	cin >> release;
	return 0;
	}