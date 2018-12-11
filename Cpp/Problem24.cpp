#include <iostream>
using namespace std;

void print(int list[], int length)
	{
	cout << "Current iteration: ";
	for (int i = 0; i < length; i++)
		{
		cout << "\t" << list[i];
		}
	cout << "\n";
	}

int main ()
	{
	int length;
	char release;
	cin >> length;
	int list[length];

	for (int i = 0; i < length; i++)
		{
		list[i] = i;
		cout << "i: " << i << "\tlist[" << i << "]: " << list[i] << endl;
		}
	
	print(list, length);
	cin >> release;
	
	int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 0;
	bool last = false;
	
	do
		{
		count ++;
		last = true;
		initial_comp = length - 2;
		for (initial_comp; initial_comp >= 0; initial_comp--)
			{
			//cout << "list[initial_comp]" << list[initial_comp] << endl;
			if (list[initial_comp] < list[initial_comp + 1])
				{
				last = false;
				break;
				}
			}
		rearrange = initial_comp + 1;
		asc_swapper = length - 1;
		
		while (rearrange < asc_swapper)
			{
			swapper = list[rearrange];
			list[rearrange] = list[asc_swapper];
			list[asc_swapper] = swapper;
			rearrange ++;
			asc_swapper --;
			}
		rearrange = length - 1;
		while (list[rearrange] > list[initial_comp])
			{
			rearrange --;
			}
		rearrange ++;
		swapper = list[initial_comp];
		list[initial_comp] = list[rearrange];
		list[rearrange] = swapper;
		//cout << "Count: " << count << endl;
		//print(list,length);
		//cout << endl;
		if (count > 999996 && count < 1000004)
			{
			cout << "Count: " << count << endl;
			print(list, length);
			cin >> release;
			}
		}
	while (!last);
	cout << "done" << endl;
	
	cin >> release;
	return 0;
	}