#include <iostream>
#include <vector>
using namespace std;

template <typename ForwardIterator>
size_t prime_sieve(ForwardIterator start, ForwardIterator end)
{
	if (start == end)
		return 0;
	//clear the container with 0
	fill(start, end, 0);
	//mark composites with 1
	for (ForwardIterator prime_it = start + 1; prime_it != end; ++prime_it)
	{
		if (*prime_it == 1)
			continue;
		//determine the prime number represented by this iterator location
		size_t stride = (prime_it - start) + 1;
		//mark all multiples of this prime number up to max
		ForwardIterator mark_it = prime_it;
		while ((end - mark_it) > stride)
		{
			advance(mark_it, stride);
			*mark_it = 1;
		}
	}

	//copy marked primes into container
	ForwardIterator out_it = start;
	for (ForwardIterator it = start + 1; it != end; ++it)
	{
		if (*it == 0)
		{
			*out_it = (it - start) + 1;
			++out_it;
		}
	}
	return out_it - start;
}

//returns the number of consecutive primes
int algorithm(int a, int b, vector<bool> primes)
{
	int length = 0;
	int n = 0;
	while (true)
	{
		int next = (n * n + a * n + b);
		if (next < 2)
		{
			return 1;
		}
		else if (!primes.at(next))
		{
			return length;
		}
		n++;
		length++;
	}
	return length;
}

int main()
{
	char release;

	//creating a list of primes that can be searched through (this is lazy code)
	vector<int> primes(1000000);
	vector<bool> prime_bool(1000001);
	fill(prime_bool.begin(), prime_bool.end(), false);

	size_t count = prime_sieve(primes.begin(), primes.end());

	//removes the elements of the vector that doesn't contain primes
	vector<int>::iterator mark;
	for (mark = primes.begin(); mark != primes.end(); ++mark)
	{
		if (*mark == 1)
		{
			primes.erase(mark, primes.end());
			break;
		}
	}

	//creating all the variables to be used in the calculation of the solution
	int coefficienta, coefficientb;
	int longest = 0, length_curr;
	//marks all the primes in the bool vector which means that looking them up can be done much faster
	for (vector<int>::iterator mark = primes.begin(); mark != primes.end(); mark++)
	{
		prime_bool.at(*mark) = true;
	}

	//the code that will go through all permutations of the problem
	for (int a = -1000; a < 1000; a++)
	{
		cout << "a: " << a << endl;
		//as b must be a prime it makes sense to only go through the possible primes to the solution
		for (vector<int>::iterator b = primes.begin(); *b < 1000; b++)
		{

			length_curr = algorithm(a, *b, prime_bool);

			if (length_curr > longest)
			{
				coefficienta = a;
				coefficientb = *b;
				longest = length_curr;
			}
		}
	}
	cout << "Answers: " << coefficienta << ", " << coefficientb << "\tTherefore the product is: " << coefficientb * coefficienta << endl;
	cout << "With length: " << longest << endl;

	cin >> release;
}