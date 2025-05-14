/*This program simulates a simplified Space Invaders game, allowing the user to place cannons and ships on a grid, and then simulates shooting and ship movement until either the defenders or invaders win*/

#include<iostream> //including libraries
using namespace std;
char** createGrid (int rows, int cols); //declaring the functions
void printGrid (char** arr, int rows); 
void deleteGrid (char** grid, int rows);
void playGame (char** arr, int rows, int cols, int shots);
int main()
{
    int rows, cols, shots; //declaring variables to used
    cout<<"Enter the number of rows in the grid: "; //prompting the user and using user input
    cin>>rows;
    cout<<"Enter the number of columns in the grid: ";
    cin>>cols;
    cout<<"Enter the number of shots per cannon for this level: ";
    cin>>shots;

    char** grid = createGrid(rows,cols); //call to create grid
    playGame(grid, rows, cols, shots); //call to play game
    deleteGrid (grid, rows); //delete the dynamic array
    return 0;
}

char** createGrid (int rows, int cols)
{
    char** arr = new char*[rows]; //creating dynamic array and filling it with .'s
    for(int i=0; i<rows; i++)
    {
        arr[i]=new char [cols];
        for (int j = 0; j<cols; j++)
            arr[i][j] = '.';
    }
    int cannons, posC, ships, x, y;
    char SP, junk;
    cout<<"Enter the number of cannons: "; //taking in number of cannons and putting them in position
    cin>>cannons;
    for(int i = 0; i<cannons; i++)
    {
        cout<<"Enter the locations of the cannons: ";
        cin>>posC;
        arr[rows-1][posC] = 'C';
    }
    cout<<"Enter the number of ships: "; //taking in number of ships and their shield points, putting the values we don't need into junk
    cin>>ships;
    cout<<"Enter the coordinates of the ships, and their shield points (x,y),SP:"<<endl;
    for(int i = 0; i<ships; i++)
    {
        cin>>junk;
        cin>>x;
        cin>>junk;
        cin>>y;
        cin>>junk;
        cin>>junk;
        cin>>SP;
        arr[x][y] = SP;
    }
    return arr;
}

void printGrid (char** arr, int rows) //printing the grid
{
    for(int i = 0; i<rows; i++)
    {
        for(int j=0; arr[i][j]!='\0'; j++)
            cout<<arr[i][j];
        cout<<endl;
    }
}

void deleteGrid (char** grid, int rows) //delete function for the dynamic, deleting row by row the deleting the grid
{
    for (int i = 0; i<rows; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
}

void playGame (char** arr, int rows, int cols, int shots) //play game
{
    int gameCount = 0; //counting the games to input into the round count
    do //do until something breaks it
    {
        int countCan = 0, countShip = 0, numShots, x, y; //creating variables
        char junk;
        for (int i = 0; i<cols; i++) //counting the cannons
        {
            if (arr[rows-1][i]=='C')
                countCan++;
        }
        for (int i = 0; i<rows-1; i++) //counting the ships
            for(int j=0; j<cols; j++)
                if(arr[i][j]!='.' && arr[i][j] != 'C')
                    countShip++;
        if (countShip == 0) //if win break
        {
            cout<<"Defenders win"<<endl;
            break;
        }
        if (countCan == 0)
        {
            cout<<"Space Invaders Win"<<endl;
            break;
        }
        for (int j = 0; j<cols; j++)
        {
            if(arr[rows-1][j] > '0' && arr[rows-2][j] <= '9')
            {
                cout<<"Space Invaders Win"<<endl;
                break;
            }
        }
        if (gameCount == 0)
            cout<<"Game at the start"<<endl;
        else
            cout<<"Game after round "<<gameCount<<endl;
        printGrid(arr, rows); //printing grid for user to see
        cout<<"Enter the coordinates for "<<shots<<" shots: "; //taking in user inputted shots as well as putting useless info in junk
        for (int i = 0; i<shots; i++)
        {
            cin>>junk;
            cin>>x;
            cin>>junk;
            cin>>y;
            cin>>junk;
            if (arr[x][y] > '0' && arr[x][y] <= '9')
            {
                arr[x][y]--; //de incrementing if the shots hit
                if(arr[x][y] == '0')
                    arr[x][y] = '.';
            }
        }
        for(int i = rows - 2; i>=0; i--) //shifting it down
        {
            for(int j = 0; j<cols; j++)
            {
                if (arr[i][j] > '0' && arr[i][j] <= '9')
                {
                        arr[i+1][j] = arr[i][j];
                        arr[i][j] = '.';
                }
            }
        }
        printGrid(arr, rows);
        gameCount++;
    }
    while (true);
}
