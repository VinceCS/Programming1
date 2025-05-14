/*This program finds and prints all even palindrome numbers with a user-specified number of digits that are also divisible by a given factor, using number reversal and condition checks.*/
 
 #include <iostream>
 using namespace std;

int reversenum (int num);

void printPalin (int numdigits, int factors); //a void functions because it isn't returning anything
void printPalin (int numdigits, int factors) //the function
{
    int start = 1; 
    for (int i = 1; i<numdigits; i++) //loop to find the starting range
        start *= 10; //so if the user puts 6 the starting would be 100000
    int end = start * 10 -1; //finding the ending range, if the user puts in 6 it would end at 999999
    for (int i = start; i<=end; i++) //loop to print the palindromic numbers
    {
        if (i%2==0 && i % factors == 0 && i == reversenum(i)) // has to be even, divisible by the factor, and equal to the flipnum function (I named it reverse)
            cout<<i<<endl; //printing the numbers
    }
}

int main()
 {
    int digits, factor; //declares the variables to be used in the function
    cout<<"Enter the number of digits: "; //prompting the user
    cin>>digits;
    if (digits < 1 || digits > 9) //if the user inputs a wrong digit
        cout<<"The number is not in the expected range (1-9)"<<endl;
    cout<<"Enter the factor: "; //prompting user
    cin>>factor;
    if (factor < 2) //if the user inputs the wrong factor
        cout<<"The number is not in the expected range (2 or higher)."<<endl;
    if (digits > 1 && digits < 9 && factor > 2) //matching the output :3
        cout<<"The even "<<digits<<" digit palindrome numbers that are the multiples of " << factor << " are: "<< endl;
    printPalin(digits, factor); //calling the function to cout all the numbers


    return 0;
 }

int reversenum (int num) //the same function as my flip sum but just getting the flipped number instead of making it a sum of the original number and the new flipped number
{
    int flippednum = 0; //equal to 0 because starting point
    while (num > 0) //loop until num runs out because it is a integer and I am dividing by 10
    {
        int digit = num %10; //modulus to find last digit
        flippednum = flippednum*10+digit; //adding the digit to the flipped num saving the value
        num = num/10; //making a new num to rerun into the loop
    }
    return flippednum; //returning the number
}
