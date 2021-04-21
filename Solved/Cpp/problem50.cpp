#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool primeCheck(int numb)
{
    for (int i = 2; i < sqrt(numb) + 2; i++)
    {
        if (numb%i == 0)
        {
            return false;
        }
    }
    return true;
}

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

int main()
{
    int size = 1000000;
    vector <int> primes(size);
    primes = primeSieve(primes);

    unsigned int largLen = 0, curLen, sum, largSum;

    //write displacement algorithm so that after each run it increases the length of the group and then tries that across every prime by iterating across it
    for (unsigned int i = 1; i < primes.size(); i++)
    {
        for (unsigned int j = 0; j < primes.size()-i; j++)
        {
            curLen = i+1;
            sum = 0;
            for (unsigned int k = 0; k <= i; k++)
            {
                //cout << primes.at(j+k) << ", ";
                sum += primes.at(j+k);
            }
            if (curLen > largLen && primeCheck(sum) && sum < size)
            {
                //cout << curSum << endl;
                largLen = curLen;
                largSum = sum;
                cout << "\tcurSum: \033[1;31m" << sum << " " << curLen << "\033[0m\n";
            }
        }
    }
    cout <<"largest list: " << largLen << "\tsum: " << largSum << endl;
    return 0;
}
