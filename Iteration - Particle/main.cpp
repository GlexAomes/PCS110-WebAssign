//Predicting Motion Through Iterations
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //variables
    double m;
    double riX,riY,riZ;
    double rfX,rfY,rfZ;
    double viX,viY,viZ;
    double vfX,vfY, vfZ;
    double fX, fY, fZ;
    double piX,piY,piZ;
    double pfX,pfY,pfZ;
    double t;
    double tStep;
    int iterations;
    
    //inputs
    m = 0.20;
    riX = 0;
    riY = 2;
    riZ = 0;
    viX = 4;
    viY = 3.5;
    viZ = 0;
    t = 0.05;
    tStep = t;
    iterations = 3;
    fX = 0;
    fY = m*(-9.81);
    fZ = 0;
    piX = m*viX;
    piY = m*viY;
    piZ = m*viZ;
    
    cout << fixed << setprecision(2) << "m = " << m << "kg"<< endl;
    cout << fixed << setprecision(2) << "r = " << "<" << riX << "," << riY << "," << riZ << "> m" << endl;
    cout << fixed << setprecision(2) << "v = <" << viX << "," << viY << "," << viZ << "> m/s" << endl << endl;
    
    //loop here
    for (int i = 0; i < iterations; i++){
        //update momentum
        pfX = piX + fX*t;
        pfY = piY + fY*t;
        pfZ = piZ + fZ*t;
        //update velocity
        vfX = pfX/m;
        vfY = pfY/m;
        vfZ = pfZ/m;
        //update position
        rfX = riX + vfX*t;
        rfY = riY + vfY*t;
        rfZ = riZ + vfZ*t;
        
        //print values
        cout << fixed << setprecision(2) << "---t=" << tStep << "s---" << endl;
        cout << fixed << setprecision(2) << "r = " << "<" << rfX << "," << rfY << "," << rfZ << "> m" << endl;
        cout << fixed << setprecision(2) << "v = <" << vfX << "," << vfY << "," << vfZ << "> m/s" << endl;
        
        //next iteration
        riX = rfX;
        riY = rfY;
        riZ = rfZ;
        piX = pfX;
        piY = pfY;
        piZ = pfZ;
        tStep += t;
    }
        return 0;
}