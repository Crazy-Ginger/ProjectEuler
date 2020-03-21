#include <iostream>
#include <vector>
using namespace std;

int factorSum(int numb)
	{
	int sum = 0;
	for (int i = 1; i < numb/2 + 1; i++)
		{
		if (numb % i == 0)
			{
			sum += i;
			}
		}
	
	return sum;
	}


int main ()
	{
	char release;
	vector <long> abundant(1, 12);
	int largest = 0;
	//28123
	for (int i = 13; i < 28124; i++)
		{
		if (factorSum(i) > i)
			{
			abundant.push_back(i);
			largest = i;		
			}
		}
	cout << "Number of abundant: " << abundant.size() << endl;
	cout << "Largest: " << largest << "\tlargest x 2: " << largest*2 << endl;
	bool numbers[largest*2];
	cout << "Numbers: " << sizeof(numbers) << endl;

	for (int i = 0; i < (largest*2)+1; i++)
		{
		numbers[i] = true;
		}
	cout << "Initial marking\n";
	cout << abundant[0] + abundant[0] << endl;
	
	for (int i = 0; i < abundant.size()-1; i++)
		{
		for (int a = 0; a < abundant.size()-1; a++)
			{
			//cout << "Marking: " << abundant[i] + abundant[a] << endl;
			numbers[abundant[i] + abundant[a]] = false;
			//cout << endl;
			}
		}
	cout << "All numbers marked\n";
	cin >> release;
	int sum = 0;
	for (int i = 0; i < 28123; i++)
		{
		if (numbers[i] == true)
			{
			sum += i;
			cout << "Sum: " << sum << endl;
			}
		}
	cout << "Sum: " << sum << endl;
	
	cin >> release;
	return 0;
	}