/*This program takes user-entered numbers, flips each digit (swapping 6 and 9), adds the flipped number to the original, and calculates the average of these flipped sums using loops and a custom function.*/

#include <iostream>
using namespace std;
int flipsum (int num); //making the flipsum function

int main ()
{
    int num, count = 0, totalflippedsum = 0, flippedsum; //declaring variables to use, as well as setting some of them to 0 because it needs to start at 0
    double average;
    do //do while loop if the num is not 0
    {
        cout<<"Enter the numbers (0 to stop):"<<endl; //prompts the user
        cin>>num;
        if (num !=0)
        {
            cout<<"The flipped sum of "<<num<< " is "<<flipsum (num)<<endl; //shows the user the flip sum
            flippedsum = flipsum(num); //getting the flip sum so it can add to the total
            totalflippedsum+=flippedsum; //adding to the total in updates
            count++; //keeping track of the amount of times this loop has ran so it can divide by it later
        }
        else if (count==0) //what to do if the first number the user inputs is 0 as the first number
        {
            cout<<"No valid data was entered"<<endl;
            return 0;
        }

    }while (num != 0);
    if (count > 0) //so divide by 0 doesn't happen
    {   
        average = totalflippedsum/count; //finding average
        cout<<"The average flipped sum is " <<average<<endl; //statement for the user to see
    }

    return 0;
}

int flipsum (int num)
{
    int flippednum = 0; //declaring the flipped number, starting it at 0
    int originalnum = num; //doing this to add to the "flipped num" to find the sum, because we will be changing num throughout the loop we have to use this variable
    while (num > 0) //loop to find the flipped number
    {
        int digit = num%10; //modulus 10 because 10 get rid of the digits execpt for the last one
        if (digit == 9) //if the digit is 9 it flips to 6
            digit = 6;
        else if (digit == 6) //if the digit is 6 it flips to 9
            digit = 9;
        flippednum = flippednum * 10 + digit; //this keeps track of the total the flipped number
        num = num/10; //divides by 10 for a new number to rerun in the loop
    }
    int sum = flippednum + originalnum; //finds the sum

    return sum; //returning the sum
}
