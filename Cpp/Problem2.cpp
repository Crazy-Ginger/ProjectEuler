#include <iostream>
using namespace std;

int main()
	{
	char release;
	int total = 0;
	int fib1 = 2;
	int fib2 = 1;
	int temp;
	while (fib1 < 4000000)
		{
		if (fib1 % 2 ==0)
			{
			total += fib1;
			}
		cout<<fib1<<endl;
		temp = fib1;
		fib1 += fib2;
		fib2 = temp;
		}
	cout <<total<<endl;
	cin >> release;
	return 0;
	}
