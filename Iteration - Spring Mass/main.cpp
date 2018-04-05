//2.E. Q3
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double L0, L;
    double s;
    double k;
    double m;
    double fX, fY, fZ;
    double piX, piY, piZ;
    double pfX, pfY, pfZ;
    double riX, riY, riZ;
    double rfX, rfY, rfZ;
    double t, tStep;
    double fg, fs;
    int iterations = 2;
    
    //INPUTS START HERE
    L0 = 0.25; // m
    k = 13; // N/m
    m = 0.078; // kg
    L = 0.285; // m
    //INPUTS END HERE

    //DON'T CHANGE ANYTHING UNDER HERE    
    //initialize some values
    t = 0.1; 
    piX = 0;
    piY = 0;
    piZ = 0;
    riX = 0;
    riY = L;
    riZ = 0;
    fX = 0;
    fZ = 0;
    tStep = t;
    fg = m*(-9.81);
    
    //print given values
    cout << fixed << setprecision(4) << "L0 = " << L0 << "m" << endl;
    cout << fixed << setprecision(4) << "Ks = " << k << "N/m" << endl;
    cout << fixed << setprecision(4) << "m = " << m << "kg" << endl;
    cout << fixed << setprecision(4) << "L = " << L << "m" << endl;
    cout << "--------------------" << endl;
    
    //loop here
    for (int i=0; i<iterations; i++){
    s = L-L0;
    fs = -1*k*s;
    
    fY = fg+fs;
    

    pfY = piY + fY*t;

    

    rfY = riY + (pfY/m)*t;

        
    //prepare for next iteration:
    L = rfY;//0.1025
        

    riY = rfY;
 
        

    piY = pfY;//-0.153375
      
    }
    //print answer
    cout << fixed << setprecision(4) << "rf = <" << rfX << "," << rfY << "," << rfZ << "> m" << endl;
    cout << fixed << setprecision(4) << "pf = <" << pfX << "," << pfY << "," << pfZ << "> kg m/s" << endl;
    return 0;
}