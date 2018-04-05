//3.C - Electric Forces Q4 Solver - Glex
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double m1, m2;
    double q1, q2;
    double r1X, r1Y, r1Z;
    double r2X, r2Y, r2Z;
    double G = 6.674*pow(10, -11);
    double k = 8.99*pow(10,9);
    double rX, rY, rZ;
    double rMag;
    double rHatX, rHatY, rHatZ;
    double FgMag;
    double FgX, FgY, FgZ;
    double FeMag;
    double FeX, FeY, FeZ;
    double ratio;
    
    //INPUTS START HERE:
    m1 = 2*pow(10,-3);
    m2 = m1; //m1 = m2
    q1 = -5*pow(10,-9);
    r1X = 40*pow(10,-2);
    r1Y = -20*pow(10,-2);
    r1Z = 0*pow(10,-2); //I think this is always 0
    q2 = -5*pow(10,-9);
    r2X = -30*pow(10,-2);
    r2Y = 30*pow(10,-2);
    r2Z = 0*pow(10,-2); //I think this is always 0
    //INPUTS END HERE
    
    //print inputs
    cout << scientific << setprecision(3) << "m1 = m2 = " << m1 << " kg" << endl;
    cout << scientific << setprecision(3) << "q1 = " << q1 << " C" << endl;
    cout << scientific << setprecision(3) << "r1 = <" << r1X << "," << r1Y << "," << r1Z << "> m" << endl;
    cout << scientific << setprecision(3) << "q2 = " << q2 << " C" << endl;
    cout << scientific << setprecision(3) << "r2 = <" << r2X << "," << r2Y << "," << r2Z << "> m" << endl;
    cout << "--------------------------------" << endl;
    
    //calculate and solve
    
    rX = r2X-r1X;
    rY = r2Y-r1Y;
    rZ = r2Z-r1Z;
    
    cout << fixed << setprecision(3) << "a.) r = <" << rX << "," << rY << "," << rZ << "> m" << endl << endl;
    
    rMag = sqrt(pow(rX,2)+pow(rY,2)+pow(rZ,2));
    
    cout << fixed << setprecision(3) << "    r = " << rMag << " m" << endl << endl;
    
    rHatX = rX/rMag;
    rHatY = rY/rMag;
    rHatZ = rZ/rMag;
    
    cout << fixed << setprecision(3) << "    rHat = <" << rHatX << "," << rHatY << "," << rHatZ << ">" << endl << endl;
    
    FgMag = (G)*(m1)*(m2)/pow(rMag,2);
    
    cout << scientific << setprecision(3) << "    |Fgrav on q2| = " << FgMag << " N" << endl << endl;

    FgX = -1*FgMag*rHatX;
    FgY = -1*FgMag*rHatY;
    FgZ = FgMag*rHatZ;
    
    cout << scientific << setprecision(3) << "    Fgrav on q2 = <" << FgX << "," << FgY << "," << FgZ << "> N" << endl << endl;

    FeMag = (k)*(q1)*(q2)/pow(rMag,2);
    
    cout << scientific << setprecision(3) << "    q1q2/4πε0 = " << FeMag << " N" << endl << endl;

    FeX = FeMag*rHatX;
    FeY = FeMag*rHatY;
    FeZ = FeMag*rHatZ;
    
    cout << scientific << setprecision(3) << "    Felectic on q2 = <" << FeX << "," << FeY << "," << FeZ << "> N" << endl << endl;

    ratio = FeMag/FgMag;
    
    cout << scientific << setprecision(3) << "b.) |Felectric|/|Fgrav| = " << ratio << endl << endl;
    
    cout << scientific << setprecision(3) << "c.) |Felectric|/|Fgrav| = " << ratio << endl;
}