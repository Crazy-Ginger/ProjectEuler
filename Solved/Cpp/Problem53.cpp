#include <iostream>
using namespace std;

double factorial(double number)
{
	if (number > 1)
	{
		return number*factorial(number-1);
	}
	else
	{
		return 1;
	}
}

int main()
{
	char release;
	
	int numb_larger = 0;
	
	for (int i = 1; i < 101; i++)
	{
		for (int a = 0; a <= i; a++)
		{
			double current = factorial(i) / (factorial(a)*factorial((i-a)));
			/*if (i > 34)
			{
				cout << " i:" << i << "\ta:" << a << endl;
				cout << "F(i): " << factorial(i) << "\tF(a): " << factorial(a);		
				cout << "\t current: " << current << endl;
				cin >> release;
			}*/
			if (current >= 1000000)
			{	
				numb_larger++;
								
			}
			//cin >> release;
		}
	}
	cout << "Total: " << numb_larger;
	
	
	cin >> release;
	return 0;
}