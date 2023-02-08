#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{   // set variable values and created open values
    const double Wage_per_hour = 5.50;
    const double Plan_A_com = 0.10;
    const double Plan_B_com = 0.15;
    double weekly_income;
    double Plan_A;
    double Plan_B;

    //created opening program questions 
    cout << fixed << setprecision(2);
    cout << "Enter the weekly sales amount ";
    cin >> weekly_income;
    cout << endl;
    cout << "Amount of sales $" << weekly_income << endl;
    //basic math for both plans and assigned them to thier own values
    Plan_A = (Wage_per_hour * 40) + (Plan_A_com * weekly_income);
    cout << "plan 1 pays $" << Plan_A << endl;

    Plan_B = Plan_B_com * weekly_income;
    cout << "plan 2 pays $" << Plan_B << endl;
    //if else statement to compare the two plans and project the better of the plans
    if (Plan_A > Plan_B) {
        cout << "Plan 1 is better" << endl;
    }
    else {
        cout << "Plan 2 is better" << endl;
    }
    return (0);
}