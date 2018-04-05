//3.A Gravitational Force - Q3 FULL - Glex
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 

int main() {
    double mp, ms;
    double rpX, rpY, rpZ;
    double rsX, rsY, rsZ;
    double G = 6.674*pow(10, -11);
    double rpsX, rpsY, rpsZ;
    double rpsHatX, rpsHatY, rpsHatZ;
    double rpsMag;
    double scalar;
    double FgX, FgY, FgZ;
    double FgMag;
    
    //INPUTS START FROM HERE:
    mp = 4*pow(10,24);
    rpX = 5*pow(10,11);
    rpY = -4*pow(10,11);
    rpZ = 0;
    ms = 4*pow(10,30);
    rsX = -6*pow(10,11);
    rsY = 4*pow(10,11);
    rsZ = 0;
    //INPUTS END HERE

    rpsX = rsX-rpX;
    rpsY = rsY-rpY;
    rpsZ = rsZ-rsZ;
    
    cout << scientific << setprecision(3) << "(a) r = <" << rpsX << "," << rpsY << "," << rpsZ << "> m" << endl;
    
    rpsMag = sqrt(pow(rpsX,2) + pow(rpsY,2) + pow(rpsZ,2));
    
    cout << scientific << setprecision(3) << "(b) |r| = " << rpsMag << "m" << endl;
    
    rpsHatX = rpsX/rpsMag;
    rpsHatY = rpsY/rpsMag;
    rpsHatZ = rpsZ/rpsMag;
    
    cout << fixed << setprecision(3) << "(c) rHat = " << rpsHatX << "i," << rpsHatY << "j," << rpsHatZ << "k" << endl;
    
    FgMag = (G)*(mp)*(ms)/(pow(rpsMag,2));
    
    cout << scientific << setprecision(3) << "(d) |Fg on Planet| = " << FgMag << "N" << endl;
    
    cout << scientific << setprecision(3) << "(e) |Fg on Star| = " << FgMag << "N" << endl;

    FgX = FgMag*rpsHatX/pow(10,20);
    FgY = FgMag*rpsHatY/pow(10,20);
    FgZ = FgMag*rpsHatZ/pow(10,20);
    
    cout << fixed << setprecision(3) << "(f) Fg on Planet = " << FgX << "i," << FgY << "j," << FgZ << "k x10^24m" << endl;
    
    FgX*=-1;
    FgY*=-1;
    
    cout << fixed << setprecision(3) << "(g) Fg on Planet = " << FgX << "i," << FgY << "j," << FgZ << "k x10^24m" << endl;
}