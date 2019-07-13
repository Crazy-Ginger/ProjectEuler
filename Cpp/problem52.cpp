#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    unsigned int i = 1;
    bool solved = false;
    while (!solved)
    {
        string numb = to_string(i);
        sort(numb.begin(), numb.end());
        cout << "i: " << i << "\t: " << numb;
        bool passed = true;
        for (unsigned int j = 2; j<=6; j++)
        {
            string temp = to_string(i*j);
            sort(temp.begin(), temp.end());
            cout << endl;
            if (!(temp == numb))
            {
                passed = false;
                break;
            }
            else
            {
                cout << "passed: " << j << ": " << i*j << endl;
            }
        }
        if (passed)
        {
            solved = true;
        }
        i++;
        
    }
    return 0;
}
