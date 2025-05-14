/*This program prints stylized ASCII art of the letters R, O, K, or Y based on a user-defined odd size ≥ 9, and allows repeated input via a menu loop*/

#include <iostream>
using namespace std;
int main ()
{
    char repeat;
do{
    int size;
    cout<<"Welcome to the letter printer.";
    cout<<"\nEnter the size : ";
    cin>>size;
    if (size < 9 || size % 2 == 0)
    {
        cout<<"Invalid size. Enter the size again: ";
        cin>>size;
    }
    char letter;
    cout<<"Enter the letter: ";
    cin>>letter;
    if (letter != 'R' && letter != 'O' && letter != 'K' && letter != 'Y')
    {
        cout<<"Invalid letter: Enter the letter again";
        cin>>letter;
    }
    if (letter == 'Y')
    {
        for (int r = 0; r < size / 2; r++) //Prints out the * for the left side of upper y
        {
            for (int c = 0; c < r; ++c)
            {
                cout<<" ";
            }
            cout<<"*";
        
            for (int c = 0; c < size - 2 * r - 2; ++c) //Prints out the space after the * for the right side
            {
                cout<<" ";
            }
            cout<<"*"; //prints a missing star
            cout<<endl;
        }
    for (int r = 0; r < size / 2; ++r) //Prints out the bottom line of Y
        {
        for (int c = 0; c < size / 2 ; ++c)
            {
                cout<<" ";
            }
            cout<<"*"<<endl;
        }
    }
    if (letter == 'O')
    {
        for (int r = 0; r < size; ++r) //Prints out the O for the rows
        {
            for (int c = 0; c < size; ++c) //Loops the columns
            {
                if (r == 0 || r == size - 1 || c == 0 || c == size - 1) //if the r is any of those it prints a * and if not it prints a space
                    cout<<"*";
                else
                    cout<<" ";
            }
            cout<<endl;
        }
    }
    if (letter == 'K')
    {
        for (int r = 0; r < size; r++)
        {
            cout<<"*"; //Prints the left straight line of K
            for (int c = 0; c < abs(size / 2 - r) - 1 ; c++) //Using absolute value so it will keep putting spaces when it crosses the middle. This line is to tell the program where to put the spaces an
                cout<<"  ";
            if (r != size/2) //Prints the * for the 2 diagonal lines of K
                cout<<" *";
            cout<<endl;
        }
    }
    if (letter == 'R')
    {
        for (int i = 0; i < size; i++) //prints the top row of *
            cout<<"*";
        cout<<endl;
        for (int r = 1; r < size / 2; r++) //prints the left side of the square
        {
                cout<<"*";
                for (int c = 0; c < size - 2; c++) //this prings the inter space of the square
                    cout<<" ";
                cout<<"*"<<endl; //this prints the ending line down
        }
        for (int i = 0; i < size; i++) //bottom flat line of * on the R
        {
            cout<<"*";
        }
        cout<<endl;
        int diagonal = 1; //declares the diagonal which I need to have because I need to increment this as well as add a starting number of 1. Because I need it to start after the middle.
        for (int r = size / 2 + 1; r < size; r++)
        {
            cout<<"*";
            for (int c = 0; c < diagonal; c++)
                cout<<" ";
                cout<<" ";
        
        cout<<"*"<<endl;
        diagonal++;
        }
    }
    cout<<"\nWould you like to continue? (Y or N): ";
    cin>>repeat;
} while (repeat == 'Y');

    return 0;
}
