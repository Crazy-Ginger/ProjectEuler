#include <iostream>
#include <vector>
#include <string>
using namespace std;


int factorial(int numb)
{
	if (numb > 1)
	{
		return numb * factorial(numb - 1);
	}
	else
	{
		return 1;
	}
}

bool checker(string word)
{
    int primes[] = {2,3,5,7,11,13,17};

    for (unsigned int i = 1; (i+2) < word.length(); i++)
    {
        unsigned int current = stoi(word.substr(i, 3));
        if (current % primes[i-1] != 0)
        {
            return false;
        }
    }
    cout << "adding: " << word << endl;
    return true;
}

string appender(string word, vector<int> &pointers)
{
	string newOrder = "";
	for (unsigned int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
	//cout << newOrder << endl;
    return newOrder;
}

vector<long> Permuter(string word)
{
    vector <long> toReturn;
	vector<int> pointers;
	int length = word.size();

	//fills the array defined above
	for (int i = 0; i < length + 1; i++)
	{
		pointers.push_back(i);
	}

	int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;
	

	for (count++; count <= factorial(length); ++count)
	{
		initial_comp = length - 2;
		
        while (pointers.at(initial_comp) > 0)
        {
            if (pointers.at(initial_comp) < pointers.at(initial_comp+1))
            {
                break;
            }
            else
            {
                initial_comp--;
            }
        }
        rearrange = initial_comp + 1;
		asc_swapper = length - 1;

		while (rearrange < asc_swapper)
		{
			swapper = pointers.at(rearrange);
			pointers.at(rearrange) = pointers.at(asc_swapper);
			pointers.at(asc_swapper) = swapper;
			rearrange++;
			asc_swapper--;
		}
		rearrange = length - 1;

		//selects the numbers the need to be swapped
		while (pointers.at(rearrange) > pointers.at(initial_comp))
		{
			rearrange--;
		}

		//swaps the largest number at the back with the number in fron of it
		rearrange++;
		swapper = pointers.at(initial_comp);
		pointers.at(initial_comp) = pointers.at(rearrange);
		pointers.at(rearrange) = swapper;

        string newOrder = appender(word, pointers);

        if (checker(newOrder))
        {
            //cout << "Just about to convert to int\n";
            unsigned long toPush = stol(newOrder);
            //cout << "Converted just about to push\n";
            toReturn.push_back(toPush);
            //cout << "just pushed it\n";
        }
        

	}
    return toReturn;
}

int main()
{
    vector <long> numbs;
    numbs = Permuter(to_string(1234567890));
    cout << numbs.size() << endl;
    long long sum = 0;
    for (vector<long>::iterator i=numbs.begin();i!=numbs.end();i++)
    {
        sum+= *i;
    }
    cout <<"Sum: " << sum << endl;
    return 0;
}
