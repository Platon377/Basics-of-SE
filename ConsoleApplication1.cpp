#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
using namespace std;

int n;
double a, b, h;

void importantText() {
    cout << "While inputing the values you should keep the following features in mind, otherwise, the wrong output pressumably will be calculated" << endl;
    cout << "1. \t If you enter some values, the program will try to convert them, so that they match appropriate standart" << endl;
    cout << "2. \t If you enter some letters, all digits after them will be ingored" << endl;
    cout << "3. \t If you enter some leading zeroes, they will be ignored and only meaning digits will be saved" << endl;
    cout << "----------------------------------" << "\n" << endl;
}
//this functions inputs and checks, whether input is valid
double enterVerifyValue(string f) {
    while (true) {
        string k;

        cout << "Enter value of " + f << endl;
        string warning;
        if (f == "a") warning = "It should be double";
        else if (f == "b") warning = "It should be double and bigger than or equal to a (>=a)";
        else if (f == "h") warning = "It should be double and bigger than 0 (>0)";
        else if (f == "n") warning = "It should be int and bigger than 7 (>7)";
        //cout << warning << endl;
        

        cin >> k;
        double v;

        try {
            v = stod(k);

            if (f == "b" && v < a) cout << "The value of " + f + " shoud be biger than or equal to a (>=a)" << endl;
            else if (f == "h" && v <= 0) cout << "The value of " + f + " shoud be biger than 0 (>0)" << endl;
            else if (f == "n" && (v <= 7 || v!=int(v))) cout << "The value of " + f + " shoud be biger than 7 (>7)" << endl;
            else {
                cout << setprecision(15) << "In the calculations for " + f + " will be used value " << v << endl;
                cout << "----------------------------------" << "\n" << endl;
                return v;
                break;
            }
            

        }        
        catch (const invalid_argument& e) { cout << "Enter something that contains leading digits" << endl; }
        catch (const out_of_range& e) {cout << "This value is approxiamting the smallest possible double, enter another number." << endl; }
        cout << "----------------------------------" << "\n" << endl;

        
    }
}


//this functions calculates the value of the current x
void findValue(double x, int n) {

    double y = 0;

    if (x < 3) {
        y = 0;
        for (int i = 2; i <= n - 5; i++) {
            for (int j = 0; j <= n; j++) {
                y += 2 * i + double(x * x) / (j + 2) - j;
            }
        }
        y = 5 * x - 2 - y;
    }
    else {
        double s = 1, p = 1;
        for (int j = 0; j <= n + 4; j++) {
            p *= (4 * x - j);
        }

        for (int j = -4; j <= n + 2; j++) {
            s += 1.0 / (x - 2 * j);
        }

        y += p + x * s;
    }
    cout << setw(10) << setfill(' ') << "x = " << x << "; \t y = " << y << ";" << endl;

}

int main()
{
    importantText();
    a = enterVerifyValue("a");
    b = enterVerifyValue("b");
    h = enterVerifyValue("h");
    n = enterVerifyValue("n");


    for (double x = a; x <= b; x += h) {
        findValue(x, n);
    }
    
    return 0;

}
