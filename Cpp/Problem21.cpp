#include <iostream>
#include <vector>
using namespace std;

bool check(int numb, vector <int> list)
	{
	for (int i = 0; i < list.size(); i++)
		{
		if (numb == list[i])
			{
			return true;
			}
		}
	return false;
	}


int factSum(int numb)
	{
	int sum = 0;
	//cout << "Factors of " << numb << ": {";
	for (int i = numb / 2 + 1; i > 0; i--)
		{
		if (numb % i == 0)
			{
			//cout << i << ", ";
			sum += i;
			}
		}
	//cout << "}\tSum: " << sum << endl;
	return sum;
	}


int main ()
	{
	char proceed;
	vector <int> amicable;
	int s_ifactors = 0, s_jfactors = 0;

	for (int i = 10001; i > 3; i--)
		{
		s_ifactors = factSum(i);
		s_jfactors = factSum(s_ifactors);
			
		//cout <<"i: " << i << "\tI-fact: " << s_ifactors << "\tJ-fact: " << s_jfactors;
		
		if (s_jfactors == 1 || s_jfactors == s_ifactors)
			{
			//cout << "\tSame number";
			}
		else if (check(s_jfactors, amicable) || check(s_ifactors, amicable))
			{
			//cout << "\tDone before";
			}
		else if (s_jfactors == i)
			{
			amicable.push_back(i);
			amicable.push_back(s_ifactors);
			//cout << "\tAmicable!";
			//cin >> proceed;
			}
	//cout << endl << endl;
	}

	int sum = 0;
	cout << "Amicable size: " << amicable.size() << endl;
	cout << "Number: ";
	for (int i = 0; i < amicable.size(); i++)
		{
		cout << amicable[i] << ", "; 
		sum += amicable[i];
		}
	cout << "\nSum: " << sum << endl;
	
	char release;
	cin >> release;
	return 0;
	}
