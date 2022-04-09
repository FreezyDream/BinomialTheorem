#include<iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int n;
double a,b,result;
string formula;

double binomialTheorem(double a, double b, int n)
{
    double result = 1;
    if(n == 0)
        return result;
    if(a+b == 0)
        return result-1;
    if(n < 0)
        return (1/((a+b)*binomialTheorem(a,b,abs(n+1))));
    return (a+b)*binomialTheorem(a,b,n-1);
}

string binomialFormula(double a, double b, int n)
{
    ostringstream ss1,ss2;
    ss1 << a;
    ss2 << b;
    string x = ss1.str();
    string y = ss2.str();
    bool ifNegative = false;
    string formula = "";
    if(n == 0)
        return "1";
    if(n < 0)
    {
        ifNegative = true;
        formula += "1 / (";
        n = abs(n);
    }
    int xPower = n-1;
    int yPower = 1;
    if(n == 1)
    {
        formula += x + " + " + y;
        if(ifNegative)
            formula += ")";
        return formula;
    }
    formula += x + "^" + to_string(n) + " + ";
    int arrPowers[n+1];
    int arrTempPowers[n];
    for(int i = 0; i < n; i++)
    {
        arrPowers[i] = 0;
        arrTempPowers[i] = 0;
    }
    arrPowers[n] = 0;
    arrTempPowers[n/2] = 1;
    if(n%2 == 0)
        arrTempPowers[n/2-1] = 1;
    for(int i = 0; i < (n/2)+(n%2); i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            if(j == 0)
                arrPowers[j] = arrTempPowers[j];
            else if(j == n)
                arrPowers[j] = arrTempPowers[j-1];
            else
                arrPowers[j] = arrTempPowers[j] + arrTempPowers[j-1];
        }
        for(int j = 0; j < n; j++)
        {
            arrTempPowers[j] = arrPowers[j] + arrPowers[j+1];
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(yPower == 1 && xPower == 1)
            formula += to_string(arrPowers[i]) + "(" + x + "*" + y + ")" + " + ";
        else if(yPower == 1)
            formula += to_string(arrPowers[i]) + "(" + x + "^" + to_string(xPower) + "*" + y + ")" + " + ";
        else if(xPower == 1)
            formula += to_string(arrPowers[i]) + "(" + x + "*" + y + "^" + to_string(yPower) + ")" + " + ";
        else
            formula += to_string(arrPowers[i]) + "(" + x + "^" + to_string(xPower) + "*" + y + "^" + to_string(yPower) + ")" + " + ";
        xPower--;
        yPower++;
    }
    formula += y + "^" + to_string(n);
    if(ifNegative)
        formula += ")";
    return formula;
}

main()
{
    cout << "=========================================================================" << endl;
    cout << "This program is using Binomial Theorem to expand the polynomial (a + b)^n" << endl;
    cout << "=========================================================================" << endl;
    cout << "What is your first number: ";
    cin >> a;
    while (cin.fail())
    {
        cout << "Wrong input. Please enter proper one double number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "What is your first number: ";
        cin >> a;
    }
    cout << "What is your second number: ";
    cin >> b;
    while (cin.fail())
    {
        cout << "Wrong input. Please enter proper one double number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "What is your second number: ";
        cin >> b;
    }
    cout << "How many times do you want them to multiply: ";
    cin >> n;
    while (cin.fail())
    {
        cout << "Wrong input. Please enter proper one integer number" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "How many times do you want them to multiply: ";
        cin >> n;
    }
    cout << "=========================================================================" << endl;
    formula = binomialFormula(a,b,n);
    cout << "Your formula is: " << formula << endl;
    result = binomialTheorem(a,b,n);
    cout << "Your result is: " << result << endl;
    cout << "=========================================================================" << endl;
    cout << "Thank you for using this program" << endl;
    cout << "=========================================================================" << endl;
}
