//Predicting Motion Through Iterations Soccer Ball Question
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double m;
    double viX, viY, viZ;
    double vfX, vfY, vfZ;
    double impulse;
    double f, fX, fY, fZ;
    double t;
    int iterations = 3;
    double riX, riY, riZ;
    double rfX, rfY, rfZ;
    double piX, piY, piZ;
    double pfX, pfY, pfZ;
    double theta;
    double fT;
    
    //inputs:
    m = 0.35;
    viX = 0;
    viY = 0;
    viZ = 1.8;
    impulse = -1.7;
    f = 0.3;
    t = 0.5;
    
    
    piX = impulse;
    piY = 0;
    piZ = m*viZ;
    riX = 0;
    riY = 0;
    riZ = 0;
    theta = atan(abs(piZ/piX)) * (180/M_PI);
    fX = f*cos(theta *(M_PI/180));
    fY = 0;
    fZ = -1*f*sin(theta *(M_PI/180));
    fX *=0.5;
    fY *=0.5;
    fZ *=0.5;             
    //loop here
    cout << fixed << setprecision(3) << "m = " << m << " kg" << endl;
    cout << fixed << setprecision(3) << "vi = <" << viX << "," << viY << "," << viZ << "> m/s" << endl;
    cout << fixed << setprecision(3) << "J = " << impulse << " Ns" << endl;
    cout << fixed << setprecision(3) << "F = " << f << " N" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < iterations; i++){
        pfX = piX + fX;
        pfY = piY + fY;
        pfZ = piZ + fZ;
        rfX = riX + (pfX/m)*t;
        rfY = riY + (pfY/m)*t;
        rfZ = riZ + (pfZ/m)*t;
        //setup next iteration
        piX = pfX;
        piY = pfY;
        piZ = pfZ;
        riX = rfX;
        riY = rfY;             
        riZ = rfZ;    
    }
    cout << fixed << setprecision(3) << "rf = <" << rfX << "," << rfY << "," << rfZ << "> m" << endl;
}