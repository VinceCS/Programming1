/*
This program uses nested loops to calculate all gear teeth counts within a specific RPM range that are coprime with the motor gear, ensuring compatible gear ratios based on user input.*/

#include <iostream>
using namespace std;
int main ()
{

int motorteeth;
double motorrpm, lowerrpm, upperrpm; //double value to accept decimal points
cout<<"Enter the number of teeth for the motor-side gear: ";
cin>>motorteeth;
cout<<"Enter the motor's RPM: ";
cin>>motorrpm;
cout<<"Enter the lower bound for the device RPM: ";
cin>>lowerrpm;
cout<<"Enter the upper bound for the device RPM: ";
cin>>upperrpm;

int lowerbound = static_cast<int> ((motorteeth*motorrpm)/upperrpm +1);
int upperbound = static_cast<int> (motorteeth*motorrpm)/lowerrpm; //these two equations calculate the bounds for the teeth, also making it a integer

while (motorteeth < 10 || lowerbound  < 10 || upperbound < 10) //makes sure the value is not less than 10 and it multiplies all of them to keep the ratios the same
{
    int mult;
    cout<<"Enter a multiplier: ";
    cin>>mult;
    motorteeth *= mult;
    lowerbound *= mult;
    upperbound *= mult;
}

int count = 0;

for (int deviceteeth = lowerbound; deviceteeth <= upperbound; ++deviceteeth)
{
    bool iscoprime = true; //we are assuming it is coprime until we are proven false, starting from 2 and ending when it at the values it cant be divided by anymore, keep going
    for (int i = 2; i <= motorteeth && i <deviceteeth; ++i)
        {
            if (motorteeth % i == 0 && deviceteeth % i == 0)
            {
                iscoprime = false;
                break;
            }
        }
    if (iscoprime)
    {
        cout<<deviceteeth<<"\t";
        count++; //using count to get the count each acceptable value
    }
}


if (count == 0)
    {
    cout<<"There were no acceptable values in the given range";
    }
else
    {
    cout<<"You can choose from the above "<<count<< " values";
    }

return 0;
}
