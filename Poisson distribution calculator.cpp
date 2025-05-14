/*This program calculates the probability of receiving fewer customers than expected using the Poisson distribution formula, and determines whether performance is under optimum based on that probability*/

#include<iostream>
#include<iomanip> //including for set precision
#include<cmath> //including cmath for pow
using namespace std;

double factorial (int x); //declaring the function
double sum (int lambda, int x); //declaring the other function

int main ()
{
    int expectedcust, actualcust; //inputs for user and for the function
    double probability; //because probability isn't a integer I use double
    cout<<"Enter the expected number of customers: "; //prompts user
    cin>>expectedcust;
    do //do while it isnt a negative
    {
    cout<<fixed<<setprecision(4); //sets to 4 places after the decimal
    cout<<"Enter the actual number of customers : "; //prompts user
    cin>>actualcust;
    if (actualcust <0) //leaves program if it is <0 which is negative
        break;
    probability = sum(expectedcust, actualcust);
    cout<<"Probability of less than " <<actualcust<< " customers was "<<probability<<endl;
    if (probability < 0.5) //if it is less than 0.5 cout under optimum performance
        cout<<"Under optimum performance"<<endl;
    }
    while (actualcust > 0);
    return 0;
}

double factorial (int x)
{
    double result = 1;
    for (int i = 1; i<=x; i++)
    {
        result *= i; //keeps mutiplying until it is x which is what a factorial is
    }
    return result;
}

double sum (int lambda, int x)
{
    double formula, totalsum = 0.0000, e=2.71828;
    for (int i = 0; i<=x; i++)
    {
        formula  = pow(e,-lambda)*(pow (lambda, i)/factorial(i)); //possion function
        totalsum += formula;
    }
    return totalsum; //returning the sum of it
}
