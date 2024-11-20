#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
using namespace std;

int n;
double a, b, h;

void instructionsText() {
    cout << endl;
    cout << "While inputing the values you should keep the following features in mind, otherwise, the wrong output pressumably will be calculated" << endl;
    cout << "1. \t If you enter some values, the program will try to convert them, so that they match appropriate standart" << endl;
    cout << "2. \t If you enter some letters, all digits after them will be ingored" << endl;
    cout << "3. \t If you enter some leading zeroes, they will be ignored and only meaning digits will be saved" << endl;
    cout << "----------------------------------" << "\n" << endl;
}

//this functions checks, whether input is valid
bool verifyValue(string k, string f) {

        double v;

        if (k == "") {
            return false;
        }

        try {
            v = stod(k);

            if (f == "b" && v < a) throw string("The value of " + f + " shoud be biger than or equal to a (>=a) \n");
            else if (f == "h" && v <= 0) throw string("The value of " + f + " shoud be biger than 0 (>0) \n");
            else if (f == "n" && (v <= 7 || v!=int(v))) throw string("The value of " + f + " shoud be biger than 7 (>7) \n");
            else {
                cout << setprecision(15) << "In the calculations for " + f + " will be used value " << v << "\n" << endl;
                cout << "----------------------------------" << "\n" << endl;
                return true;
            }
            

        }       
        catch (string ex) { cout << ex << endl; }
        catch (const invalid_argument& e) { cout << "Enter something that contains leading digits \n" << endl; }
        catch (const out_of_range& e) {cout << "This value is approxiamting the smallest possible double, enter another number. \n" << endl; }
        catch (...) { cout << "Undefined error\n" << endl; }
        cout << "----------------------------------" << "\n" << endl;
        return false;
}
//this function inputs values
double readValue(string f) {

    string k="";
    //cin >> k;

    string warning;

    while (verifyValue(k, f) != true) {

        
        if (f == "a") warning = "It should be double";
        else if (f == "b") warning = "It should be double and bigger than or equal to a (>=a)";
        else if (f == "h") warning = "It should be double and bigger than 0 (>0)";
        else if (f == "n") warning = "It should be int and bigger than 7 (>7)";
        cout << "Enter value of " + f + ". " << warning << endl;

        string t;
        cin >> t;
        k = t;

    }

    double v = stod(k);
    return v;

}

//this functions calculates the value of the current x
double findValue(double x, int n) {

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
        double s = 0, p = 1;
        for (int j = 0; j <= n + 4; j++) {
            p *= (4 * x - j);
        }

        for (int j = -4; j <= n + 2; j++) {
            s += 1.0 / x - 2 * j;
        }

        y += p + x * s;
    }
    return y;
    

}

int main()
{

    instructionsText();
    a = readValue("a");
    b = readValue("b");
    h = readValue("h");
    n = readValue("n");


    for (double x = a; x <= b; x += h) {
        cout << setw(10) << setfill(' ') << "x = " << x << "; \t y = " << findValue(x, n) << ";" << endl;
        
    }
    
    return 0;

}
