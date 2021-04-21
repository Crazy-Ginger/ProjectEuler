#include <iostream>
#include <vector>
using namespace std;

bool PrimeTest(int prime, vector <int> primes)
	{
	for (int i = 0; i < primes.size(); i++)
		{
		//cout << "Primes:" << primes.at(i) << endl;
		if (prime % primes.at(i) == 0)
			{
			return false;
			break;
			}
		}
	return true;
	}

int main()
	{
	char waste;
	int primeNumb = 0;
	int prime = 2;
	vector <int> primes (0);
	while (primeNumb < 10002)
		{
		if (PrimeTest(prime, primes) == true)
			{
			primeNumb += 1;
			primes.push_back(prime);
			cout << "primeNumb: " <<primeNumb << "\t" << "Prime: " << prime << endl;
			//cin >> waste;
			}
		prime += 1;
		}
	char release;
	cin >> release;
	return 0;
	}