#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned int nT = 1; //285;
    unsigned int nP = 1; //165;
    unsigned int nH = 1; //143;
    
    bool answer = false;
    while (!answer)
    {
        unsigned int curT = nT*(nT+1)/2;
        unsigned int curP = nP*(3*nP-1)/2;
        unsigned int curH = nH*(2*nH-1);
        
        if ((curT == curP) && (curT == curH))
        {
            cout<<curP<<": "<<nT<<", "<<nP<<", "<<nH<<endl;
            nP++;
            nT++;
            nH++;
        }
        else if (nT > 1000000)
        {
            cout << "Ending as nT is too big\n";
            break;
        }
        else if ((curT < curP) || (curT<curH))
        {
            nT++;
        }
        else if ((curT > curP) || (curH > curP))
        {
            nP++;
        }
        else if ((curH < curT) || (curH < curP))
        {
            nH++;
        }
        else
        {
            cout << "\nSomethings wrong\n";
            cout<<nT<<": "<<curT<<"\t"<<nP<<": "<<curP<<"\t"<<nH<<": "<<curH<<endl;
        }
    }
}
