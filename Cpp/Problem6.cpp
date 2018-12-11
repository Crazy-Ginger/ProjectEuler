#include <iostream>
using namespace std;

int main()
	{
	int powtotal = 0;
	int powsum = 0;
	int hundsum = 0;
	int temp = 0;
	for (int i = 0; i < 101; i++)
		{
		hundsum += i;

		temp = i*i;
		powtotal += temp;
		}
	
	powsum = (hundsum * hundsum);
	cout << powtotal << "\t" << hundsum << "\t" << powsum << endl;
	int diff = powsum - powtotal;
	cout << diff << endl;
	char release;
	cin >> release;
	return 0;
	}