#include <iostream>
using namespace std;

int main()
	{
	//2, 3, 5, 7, 11, 13, 17, 19
	bool found = false;
	long iterate = 4849845;
	while (found == false)
		{
		if (iterate%16 == 0 && iterate%19==0 && iterate%18==0 && iterate%20==0 && iterate%15==0 && iterate%17==0)
			{
			cout << iterate << endl;
			if (iterate%7==0 && iterate%11==0 && iterate%13==0)
				{			
				cout << iterate << endl;
				found = true;
				}
			}
			
		iterate +=1;
		}
	char release;
	cin >> release;
	}