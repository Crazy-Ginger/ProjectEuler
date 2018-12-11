#include <iostream>
#include <math.h>
using namespace std;

int main()
	{
	char release;
	const double value = 600851475143;
	int prime;
	for (double i = (value-300425737571); i > 0; i--)
		{
			if (fmod(value, i)==0)
				{
					prime = i;
					cout<< i<<endl;
					break;
				}
		}	
	cout << prime;
	cin >> release;
	return 0;
	}