#include <iostream>
using namespace std;

int main()
{
char leave;
int length; 
cin >> length;
int total = 0;
for (int i = 0; i < length; i++)
	{
	if (i%3==0 && i%5==0)
		{
		total += i;
		}
	else
	if (i%5==0)
		{
		total += i;
		}
	else
	if (i%3==0)
		{
		total += i;
		}
	}
cout <<total<<endl;
cin >> leave;
return 0;
}
