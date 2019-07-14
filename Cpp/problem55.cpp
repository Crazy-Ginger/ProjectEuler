#include <iostream>
#include <string>
#include <cstdint>
#include <sstream>
using namespace std;

uint64_t reverser(uint64_t i)
{
    string numb = to_string(i);
    string reversed;
    for (int i = numb.size(); i>= 0; i--)
    {
        reversed += numb.substr(i, 1);
    }
    //cout << "reversed: " << reversed << endl;
    istringstream converter(reversed);
    uint64_t temp;
    converter >> temp;
    return temp;
}

bool palCheck(unsigned long long i)
{
    string numb = to_string(i);

    string firHalf = "";
    for (unsigned int i = 0; i < numb.size()/2; i++)
    {
        firHalf += numb.substr(i,1);
    }
    string lasHalf = "";
    for (unsigned int i = numb.size(); i > numb.size()/2; i--)
    {
        lasHalf += numb.substr(i, 1);
    }
    if (lasHalf.size() < firHalf.size())
    {
        lasHalf += numb.substr(numb.size()/2, 1);
    }

    if (firHalf == lasHalf)
    {
        return true;
    }
    return false;
}


unsigned int cycles(unsigned long long i)
{
    unsigned int cycles = 0;
    while (cycles <= 50)
    {
        //cout << cycles << endl;
        if ((cycles != 0) && palCheck(i))
        {
            //cout << "escaped\n";
            return cycles;
        }
        i = i+reverser(i);
        cycles++;
    }
    return 100;
}


int main()
{
    unsigned int total = 0;
    for (unsigned long long i = 10; i <=10000; i++)
    {
        //cout << "i: " << i << endl;
        if (cycles(i) >= 51)
        {
            cout << "i: " << i << endl;
            total++;
        }
        //cout << endl;
    }
    cout << "total: " << total << endl;
    return 0;
}
