/*This program reads up to 25 lines of user input as C-strings, reverses each word in every line, and prints the modified text with words reversed but in the original order.*/

#include <iostream> //including libraries and using standard libary names
#include <cstring>
using namespace std;

void printText (char str[][200], int r); //declaring printText function that takes 2d array and rows as parameters
void reverseWord (char start, char end); //declaring a function that takes a start and end of the word

int main ()
{
    int rows = 0; //declares and initializes a counter of rows
    char str [25][200]; //declaring a 2d array of characters
    cout<<"Enter the text: "<<endl; //prompting the user
    for (int i = 0; i<25; i++) //loop for the user to input strings then breaks if the first row is a null terminator
    {
        cin.getline (str[i], 200);
        if (str[i][0] == '\0')
            break;
        rows++;
    }

    cout<<"The reversed worded text is "<<endl; //outputing a message that tells the user that the following text is the reversed words
    
    printText(str, rows); //calls printText function

    return 0;
}

void reverseWord (char *word) //function that reverses the word
{
    int wordLength = strlen (word); //determining the length of the word
    for (int i = 0; i<wordLength / 2; i++) //only needs to run it half because if the first half is flipped the second half is also flipped
    {
        char temp = word[i]; //temp to hold the starting letter
        word[i] = word [wordLength - i - 1]; //length - i to get it to the position the minus 1 because arrays are size - 1
        word[wordLength - i - 1] = temp; //puts temp which is the starting position to the last position
    }
}

void printText (char str[][200], int r) //function that puts the word into the reverseWord function and then prints it
{
    for(int i=0; i<r; i++) //goes over each row
    {
        char *word = strtok(str[i], " "); //inputs each letter into the word variable  and stops it when it reaches the space
        while (word != NULL) //if the word is null it will reverse the word, I am putting not null for my while isn't when it is null there is a new row and the loop is going by row
        {
            reverseWord(word); //reverse the word
            cout<<word<<" "; //puts a space after each revsered word
            word = strtok(NULL, " "); //the null tells strTok to continue putting the letters into the word where it left
        }
        cout<<endl;
    }
}
