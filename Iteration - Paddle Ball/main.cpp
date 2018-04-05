//Predicting Motion Through Iterations - Paddle Ball Question
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout << "2.E: Q4 Solver - Glex" << endl;
    cout << "--------------------" << endl;
    double m;
    double k;
    double L0;
    double LX, LY, LZ;
    double LHX, LHY, LHZ;
    double LMag;
    double s;
    double piX, piY, piZ;
    double pfX, pfY, pfZ;
    double riX, riY, riZ;
    double rfX, rfY, rfZ;
    double fgX, fgY, fgZ; 
    double fsX, fsY, fsZ;
    double fnetX, fnetY, fnetZ;
    double t;
    int iterations;
    
    //INPUTS HERE
    m = 0.014; // kg
    k = 0.930; // N/M
    L0 = 0.295; // m
    piX = -0.02;
    piY = -0.01;
    piZ = -0.02;
    riX = -0.2;
    riY = -0.61;
    riZ = 0;
    t = 0.1;
    iterations = 1;
    
    //print inputs
    cout << fixed << setprecision(4) << "m = " << m << "kg" << endl;
    cout << fixed << setprecision(4) << "Ks = " << k << "N/m" << endl;
    cout << fixed << setprecision(4) << "L0 = " << L0 << "m" << endl;
    cout << fixed << setprecision(4) << "pi = <" << piX << "," << piY << "," << piZ << "> kg m/s" << endl;
    cout << fixed << setprecision(4) << "ri = <" << riX << "," << riY << "," << riZ << "> m" << endl;
    cout << fixed << setprecision(4) << "tStep = " << t << ", " << iterations << " iteration(s)." << endl;
    cout << "--------------------" << endl;
    
    //calculationing pre-requirements
    fgY = m*(-9.81);
    LX = riX;
    LY = riY;
    LZ = riZ;
    LMag = sqrt(pow(LX, 2) + pow(LY, 2) + pow(LZ, 2));
    s = LMag-L0;
    LHX = LX/LMag;
    LHY = LY/LMag;
    LHZ = LZ/LMag;
    fsX = -1*k*s*LHX;
    fsY = -1*k*s*LHY;
    fsZ = -1*k*s*LHZ;
    fnetX = fgX + fsX;
    fnetY = fgY + fsY;
    fnetZ = fgZ + fsZ;
    
    //calculating main shit
    pfX = piX + fnetX*t;
    pfY = piY + fnetY*t;
    pfZ = piZ + fnetZ*t;
    rfX = riX + (pfX/m)*t;
    rfY = riY + (pfY/m)*t;
    rfZ = riZ + (pfZ/m)*t;
    
    cout << fixed << setprecision(4) << "a.) rf = <" << rfX << "," << rfY << "," << rfZ << "> m" << endl << endl;
        
    //part B here
    t = 0.05;
    iterations = 2;
    
    cout << fixed << setprecision(4) << "tStep = " << t << ", " << iterations << " iteration(s)." << endl;
    cout << "--------------------" << endl;
    for (int i=0; i<iterations; i++){
    //calculationing pre-requirements
    fgY = m*(-9.81);
    LX = riX;
    LY = riY;
    LZ = riZ;
    LMag = sqrt(pow(LX, 2) + pow(LY, 2) + pow(LZ, 2));
    s = LMag-L0;
    LHX = LX/LMag;
    LHY = LY/LMag;
    LHZ = LZ/LMag;
    fsX = -1*k*s*LHX;
    fsY = -1*k*s*LHY;
    fsZ = -1*k*s*LHZ;
    fnetX = fgX + fsX;
    fnetY = fgY + fsY;
    fnetZ = fgZ + fsZ;
    
    //calculating main shit
    pfX = piX + fnetX*t;
    pfY = piY + fnetY*t;
    pfZ = piZ + fnetZ*t;
    rfX = riX + (pfX/m)*t;
    rfY = riY + (pfY/m)*t;
    rfZ = riZ + (pfZ/m)*t;
    
    //prepare for next iteration
    piX = pfX;
    piY = pfY;
    piZ = pfZ;
    riX = rfX;
    riY = rfY;
    riZ = rfZ;
    }
    cout << fixed << setprecision(4) << "b.) rf = <" << rfX << "," << rfY << "," << rfZ << "> m" << endl;
    cout << "--------------------" << endl;
    cout << "c.) The answers are different because these approximations are more accurate for smaller time intervals." << endl;
    cout << "--------------------" << endl;
    return 0;
    }