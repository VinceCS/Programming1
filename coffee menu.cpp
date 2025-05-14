/*This program takes the user's input by using a switch statement and calculates coffee prices by using arithmetic operations.*/

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{

char size;
double x,y,z;
int oz;

cout<<fixed<<setprecision(2); //decimal point
cout<<"These are the coffee sizes: Tiny, Small, Medium, Large, Extra Large, Catering Tote."<<endl; 
cout<<"These are the number of corresponding ounces: 6,10,16,22,30,64." <<endl;
cout<<"These are the reference letters: T,S,M,L,X,C."<<endl; //these are all the menu
cout<<"Enter the reference letter of the coffee size you want: "<<endl; //prompting the user
cin>>size;

switch (size) //switch statement for ounces and what they want
    {
    case 'T':
        cout<<"Selected Tiny"<<endl;
        oz = 6;
        break;
    case 'S':
        cout<<"Selected Small"<<endl;
        oz = 10;
        break;
    case 'M':
        cout<<"Selected Medium"<<endl;
        oz = 16;
        break;
    case 'L':
        cout<<"Selected Large"<<endl;
        oz = 22;
        break;
    case 'X':
        cout<<"Selected Extra Large"<<endl;
        oz = 30;
        break;
    case 'C':
        cout<<"Selected Catering Tote"<<endl;
        oz = 64;
        break;
    default:
        cout<<"Error: You did not enter a reference letter."<<endl;
        return 1;
    }
cout<<"Enter the amount it would cost to make 1 gallon of that drink: "<<endl; //prompt the user
cin>>x; //user input
y= x/128*oz; //calculation
z = y*1.25;
cout<<"The cost to make this drink is: "<<z<<endl;
    return 0;
}
