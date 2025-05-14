/* This program takes a matrix input from the user, prints it, and calculates the sums of its upper and lower triangles using nested loops and conditionals based on row and column indices*/

#include <iostream>
using namespace std;

const int ROWCAP = 100; //global constant for rowcap
const int COLCAP = 100; //global constant for colcap

void initializeMatrix (double matrix[ROWCAP][COLCAP], int &rows, int &cols); //function to initalize the matrix, using references because we need to actually change the rows and columns

void printMatrix (double matrix [ROWCAP][COLCAP], int rows, int cols); //function to print

void printSums (double matrix [ROWCAP][COLCAP], int rows, int cols); //function to print sums

int main ()
{
    double  matrix[ROWCAP][COLCAP];
    int rows, cols;
    initializeMatrix(matrix, rows, cols); //declaring and initalizing the matrix
    cout<<"You entered: "; //helping the user see what they put
    printMatrix (matrix, rows, cols); //prints matrix
    printSums (matrix, rows, cols); //prints sum
    return 0;
}

void initializeMatrix (double matrix[ROWCAP][COLCAP], int &rows, int &cols)
{
    cout<<"Enter the number of rows: "; //prompts the user
    cin>>rows; //stores value
    cout<<"Enter the number of columns: "; //prompts the user
    cin>>cols; //stores value
    cout<<"Enter the matrix: "; //prompts the user
    for (int i=0; i<rows; i++) //loop for rows
    {
        for (int j=0; j<cols; j++) //loop for columns
        {
            cin>>matrix[i][j]; //inputting the numbers for i rows and j cols
        }
    }
}

void printMatrix (double matrix [ROWCAP][COLCAP], int rows, int cols)
{
    for (int i = 0; i < rows; i++) //rows loop
    {
        for (int j = 0; j < cols; j++) //col loop
            cout<<matrix[i][j]<<"\t"; //printing it
        cout<<endl; //seperating cols and rows
    }
}

 void printSums (double matrix [ROWCAP][COLCAP], int rows, int cols)
 {
    double upperSum = 0; //declare and initalize upper up
    double lowerSum = 0; //declare and initalize lower sum
    for (int i = 0; i < rows; i++) //rows loops
    {
        for (int j = 0; j < cols; j++) //cols loop
        {
            if (j >= i) //upper triangle sum, this works becuase the triangle is always has a higher col index than row
                upperSum += matrix[i][j];
            if (j <= i) //lower triangle sum, same thing but reverse
                lowerSum += matrix[i][j];
        }
    }
    cout<<"Upper triangle sum: "<<upperSum<<endl; //Printing the upper sum
    cout<<"Lower triangle sum: "<<lowerSum<<endl; //Printing the lower sum
 }
