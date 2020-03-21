#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
	{
	vector <int> triangles(0);
	vector <string> words(0);
	vector <int> values(0);
	char release;
	fstream f_words;
	f_words.open("C:/Coding/Project_Euler/Cpp/Euler_Files/Problem42_words.txt");
	
	for (int i = 1; i < 100 ; i++)
		{
		triangles.push_back(0.5 * i * (i+1));
		}

	string temp_string; 
	if (f_words.is_open())
	{
		while (getline(f_words, temp_string))
		{
			words.push_back(temp_string);
		}
	}

	int temp_value = 0;
	for (int i = 0; i != words.size(); i++)
	{
		for (char c: words.at(i))
		{
			temp_value += (int(c)-64);
		}
		values.push_back(temp_value);
		temp_value = 0;
	}

	if (words.size() != values.size())
	{
		cout << "Something has gone wrong\n";
		cout << "Words length: " << words.size() << "\tValues length: " << values.size() << endl;
		cin >> release;
	}
	
	int numberof = 0;
	for (int i = 0; i != values.size(); i++)
	{
		for (int j = 0; j != triangles.size(); j++)
		{
			if (values.at(i) == triangles.at(j))
			{
				numberof ++;
				break;
			}
		}
	}
	cout << "Number of words: " << words.size() << endl;
	cout << "The answer should be: " << numberof << endl;
	cin >> release;
	return 0;
	}