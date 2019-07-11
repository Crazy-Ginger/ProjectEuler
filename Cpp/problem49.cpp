#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <bool> primeCheck(10001);

vector<int> primeSieve(vector <int> vect)
{
    vector<int>::iterator start = vect.begin();
    vector<int>::iterator end = vect.end();
    if (start == end)
    {
        cout << "No numbers\n";
    }
    else
    {
        //clear the container with 0
        fill(start, end, 0);
        //mark composites with 1 by finding primes and then multiplying them and marking the multiples
        for (vector<int>::iterator checker = start + 1; checker != end; ++checker)
        {
            if (*checker == 1)
            {
                continue;
            }
            //determine the prime number represented by this iterator location
            int stride = (checker - start) + 1;
            //mark all multiples of this prime number up to max
            vector<int>::iterator marker = checker;
            while ((end - marker) > stride)
            {
                //moves marker along the value of stride and assigns marker's value to 1
                advance(marker, stride);
                *marker = 1;
            }
        }

        //copy marked primes into container
        vector<int>::iterator out_it = start;
        for (vector<int>::iterator it = start + 1; it != end; ++it)
        {
            //finds the primes as they are marked with 0
            if (*it == 0)
            {
                //moves the primes towards the front of the list
                *out_it = (it - start) + 1;
                ++out_it;
            }
        }
    }

    //removes the elements of the vector that doesn't contain primes
    vector<int>::iterator mark;
    for (mark = vect.begin(); mark != vect.end(); ++mark)
    {
            if (*mark == 1)
            {
                    vect.erase(mark, vect.end());
                    break;
            }
    }

    //checks for an error that allows 0 to be the last element in the array of vectors
    if (*(--vect.end()) == 0)
    {
            vect.erase(--vect.end());
    }

    return vect;
}

unsigned int factorial(int numb)
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

int appender(string word, vector<int> &pointers)
{

	string newOrder = "";
	for (unsigned int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
    return stoi(newOrder);
}

vector <int> Permuter(string word)
{
    vector <int> perPrimes;
    perPrimes.push_back(stoi(word));
	vector<int> pointers;
	int length = word.size();
    string charCheck = word.substr(word.size()-1, 1);

	for (int i = 0; i < length; i++)
	{
		pointers.push_back(i);
	}
	
	unsigned int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;

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

		while (pointers.at(rearrange) > pointers.at(initial_comp))
		{
			rearrange--;
		}

		rearrange++;
		swapper = pointers.at(initial_comp);
		pointers.at(initial_comp) = pointers.at(rearrange);
		pointers.at(rearrange) = swapper;
        
        int temp = appender(word, pointers);
        string lastChar = to_string(temp);
        lastChar = lastChar.substr(lastChar.length()-1, 1);

		if ((primeCheck.at(temp)) && (charCheck == lastChar))
        {
            perPrimes.push_back(temp);
        }

	}
    return perPrimes;
}


int main()
{
    vector <int> primes(10000);
    primes = primeSieve(primes);

    fill(primeCheck.begin(), primeCheck.end(), false);
    for (vector<int>::iterator mark=primes.begin();mark!=primes.end();mark++)
    {
        primeCheck.at(*mark) = true;
    }
    
    vector<vector<int>> perPrimes;
    for (vector<int>::iterator i = primes.begin(); i!=primes.end();i++)
    {
        vector <int> dupes = Permuter(to_string(*i));
        //cout << *i << ": " << temp.size() << endl;
        if (dupes.at(0) >= 1000)
        {
            vector <int> uniq;
            uniq.push_back(dupes.at(0));

            for (unsigned int j=0; j< dupes.size(); j++)
            {
                bool push = true;
                for (unsigned int k=0;k< uniq.size(); k++)
                {
                    if ((dupes.at(j) == uniq.at(k)) || ((to_string(dupes.at(j))).length() < 4))
                    {
                        push = false;
                    }
                }
                if (push)
                {
                    uniq.push_back(dupes.at(j));
                }
            }
            if (uniq.size() > 2 && uniq.at(0) < 5000)
            {
                sort(uniq.begin(), uniq.end());
                perPrimes.push_back(uniq);
            }
        }
    }

    //cout << "numb of primePers: " << perPrimes.size() << endl;

    //prints the list of lists
    //for (unsigned int i = 0; i < perPrimes.size(); i++)
    //{
        //cout << "Next:\n";
        //for (unsigned int j = 0; j < perPrimes.at(i).size(); j++)
        //{
            //cout << perPrimes.at(i).at(j) << endl;
        //}
        //cout << endl;
    //}

    //final piece of code needed to find linear funciton in each list in the bigger list. Not sure how to do that just yet
    for (unsigned int base=0; base<perPrimes.size(); base++)
    {
        int diff, lastDiff = 0;
        for (unsigned int i = 0; i < perPrimes.at(base).size()-1; i++)
        {
            lastDiff = 0;
            //cout << "i: " << i  << endl;
            for (unsigned int j = i+1; j < perPrimes.at(base).size(); j++)
            {
                diff = perPrimes.at(base).at(j) - perPrimes.at(base).at(i);
                if (diff == lastDiff*2)
                {
                    cout << "at i: " << perPrimes.at(base).at(i) << "\t" << perPrimes.at(base).at(j-1) << "\t" << perPrimes.at(base).at(j) << endl;
                }
                lastDiff = diff;
            }
        }
    }
    return 0;
}
