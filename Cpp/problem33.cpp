#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector <int> numers, denoms;
    for (float numerator = 10; numerator < 100; numerator++)
    {
        for (float denominator = 10; denominator < 100; denominator++)
        {
            if (!(denominator==numerator))
            {
                string strNum = to_string((int)numerator);
                string strDen = to_string((int)denominator);

                for (unsigned int i = 0; i < strNum.length(); i++)
                {
                    for (unsigned int j = 0; j < strDen.length(); j++)
                    {
                        if ((strNum.at(i)==strDen.at(j)) && !(strNum.at(i) == '0' || strDen.at(j)=='0'))
                        {
                            string tempNum = strNum;
                            string tempDen = strDen;
                            const float fltNum = stof(tempNum.erase(i, 1));
                            const float fltDen = stof(tempDen.erase(j,1));
                            if (fltNum < fltDen)
                            {
                                if (fltNum/fltDen == numerator/denominator)
                                {
                                    numers.push_back(numerator);
                                    denoms.push_back(denominator);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Numbers of sols: " << numers.size() << endl;
    for (unsigned int i = 0; i < numers.size(); i++)
    {
        cout << i << ": " << numers.at(i) << "\t" << denoms.at(i) << endl;
    }

    return 0;
}
