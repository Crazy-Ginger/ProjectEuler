#include <iostream>
#include <string>
using namespace std;

string reverser(string forw)
	{
	string Rev;
	
	for (int i = forw.size(); i >= 0; i--)
		{
		Rev += forw.substr(i,1);
		}
	return Rev;
	}

int main()
	{
	
	int largest = 0;
	//limits 10000 & 998001
	for (int i = 999; i > 100 ; i--)
		{
		for (int a = 999; a > 100; a--)
			{
			int current = a*i;
			
			auto forw = to_string(current);

			if (forw == reverser(forw))
				{
				cout << current << endl;
				if (current > largest)
					{
					largest = current;
					}
				}
			}
		}
	cout << largest << endl;
	char release;
	cin >> release;
	return 0;
	}
