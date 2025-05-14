/* This program allows the user to manage a dynamic array by inserting, removing, printing, shifting, or sorting elements using a menu-driven switch statement.*/

#include <iostream>
using namespace std;

const int capacity = 100;

void initializeArray(double arr[], int &size); //declaring all the functions we need to use, I used &size for the sizes we will change. So it works on the actual value we are changing not a copy.
void printArray (const double arr[], int size);
void insertAfter (double arr[], double insert, double after, int &size);
void removeLast (double arr[], int &size, double remove);
void alternateShift (double arr[], int size);
void sort(double arr[], int size);
int main ()
{
    double arr[capacity]; //double arr size of capacity
    int size = 0; //declaring size, so you can change it dynamically, otherwise
    initializeArray(arr, size); //calling the function to do the array
    int choice; //declaring a variable so the user can choose
    do //do until it is 6
    {
        cout<< "1. Insert an element \n"<<"2. Remove an element \n"<<"3. Print the array \n"<<"4. Shift the elements \n"<<"5. Sort the array \n"<<"6. Exit \n";
        cout<<"Enter your option: "; //prompting user
        cin>>choice; //letting user choose
        switch (choice) //switch statement for all the functions
        {
            case 1:
            {
                double  number, after; //declaring variables to use
                cout<<"Enter the number: "; 
                cin>>number;
                cout<<"Enter the number to be inserted after: ";
                cin>>after;
                insertAfter(arr, number, after, size); //using the declared varibles for the function
                cout<<"Element Inserted."<<endl;
                break;
            }
            case 2:
            {
                double number; //same thing as case 1
                cout<<"Enter the element to be removed: ";
                cin>>number;
                removeLast (arr, size, number);
                cout<<"Element deleted."<<endl;
                break;
            }
            case 3:
            {
                printArray (arr, size); //printing the array function
                break;
            }
            case 4:
            {
                alternateShift (arr,size); //shifting the array
                cout<<"Elements shifted."<<endl;
                break;
            }
            case 5:
            {
                sort(arr,size); //sorting array
                cout<<"Array sorted."<<endl;
                break;
            }
            case 6:
            {
                cout<<"Goodbye!"<<endl; //goodbye message
                break;
            }
            default:
                cout<<"Invalid Choice"<<endl; //if the user inputs a wrong number
        }
    }while (choice != 6);

    return 0;

}

void initializeArray(double arr[], int &size) //the actual function
{
    cout<<"Enter the number of elements you want to enter (Max 100): ";
    cin>>size;
    cout<<"Enter "<<size<< " numbers"<<endl;
    for(int i = 0; i<size; i++) //loops the from 0 to size the user puts asking what values to user for each index of the array
    {
        cin>>arr[i];
    }
}

void printArray(const double arr[], int size)
{
    cout<<"The array is: "<<endl;
    for(int i = 0; i<size; i++) //printing for each index of the array
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void insertAfter (double arr[], double insert, double after, int &size)
{
    for (int i = size - 1; i >= 0; --i) //going backwards to find what to insert the number after
    {
        if (arr[i] == after) //if arr[i] is the number we are looking for we slide all the numbers to the right and plop the number we want into it as well as increasing the size
        {
            for (int j = size; j > i + 1; j--)
                arr[j] = arr[j-1];
            arr[i+1] = insert;
            size++;
        }
    }
}

void removeLast (double arr[], int &size, double remove) 
{
    for (int i = size - 1; i >= 0; i--) //if we find the one we want to remove by moving backwards, so it will be error free
    {
        if (arr[i] == remove) //we set j+1 to the new j and make the array smaller, break when done so we don't have to do more work
        {
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j+1];
            }
            size--;
            break;
        }
    }
}

void alternateShift (double arr[], int size)
{
    if (size >= 3) //if size is > than 3
    {
        double firstEven = arr[0]; //first even
        double secondEven = arr[2]; //second even
        for(int i=0; i<size;i+=4) //trying to wrap and move left 4
        {
            if(i+2<size)
                arr[i] = arr[i+4];
            else if (i == size - 4)
                arr[i] = firstEven;
            else if (i==size-8)
                arr[i] = secondEven;
        }
        double lastOdd = arr[size - 1 - (size%2)];
        for (int i = size-3 + (size%2); i>=1; i-=2)
        {
            arr[i+2] = arr[i];
        }
        arr[1] = lastOdd;
    }
}

void sort (double arr[], int size) //sorting based on selection sort algorithm 
{
    for (int i = 0; i<size-1; i++) //loop until size - 1 because by the time it hits size it is already sorted
    {
        int posMin = i; //holds the smallest element
        for (int j = i+1; j<size; j++) //iterates through the unsorted array
        {
            if (arr[j] < arr[posMin])
                posMin = j; //updates the new smallest
        }
        if (posMin != i) //finds a smaller number at a unsorted position then swaps it
        {
            int temp = arr[i];
            arr[i] = arr[posMin];
            arr[posMin] = temp;
        }
    }
}
