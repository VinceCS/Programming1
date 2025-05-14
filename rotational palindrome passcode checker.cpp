/*This program checks multiple user-input strings to determine if any are palindromes or become palindromes when rotated, and then prints all such valid "passcodes."*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;
bool isPalindrome (char str[]);
void rotateRight (char str[]);
bool checkPalin (char str[]);
string checkPasscodes (char str[][500], int num);

int main()
{
    char str[500][500];
    int count = 0;
    cout<<"Enter the strings: ";
    for (int i = 0; i<500; i++)
    {
        cin.getline (str[i], 500);
        if(str[i][0] == '\0')
            break;
        count++;
    }
 
    string palin = checkPasscodes(str,  count);
    cout<<"The palindromes passcodes are: \n"<<palin;


    return 0;
}

bool isPalindrome (char str[])
{
    int left = 0, right = strlen(str) - 1;

    while (left < right)
    {
        while (!isalnum(str[left]) && left < right) //skipping non alpha numeric characters on the left
            left++; //incrrements if it is not alpha numeric
        while (!isalnum(str[right]) && left < right) //same as left function but increments the opposite way
            right--;
        if (tolower(str[left]) != tolower(str[right])) //this is the part that acutally checks if the characters are equal
            return false; 
        left++;
        right--;
    }
    return true;
}

void rotateRight (char str[]) //function to rotate the string
{
    int length = strlen(str); //declares length and initializes length to strlen
    if (length == 0)  //returns if there is no characters
        return;
    char last  = str[length-1]; //makes last = to the last character before the loop starts
    for (int i = length - 1; i > 0; i--) //puts the character before i in i
        str[i] = str[i-1];
    str[0] = last; //makes str of 0 = to the character we put in last
}

bool checkPalin (char str[])
{
    int n = strlen(str);
    if (n == 0) //if it is 0 then it is already false
        return false;
    if (isPalindrome(str)) //checking if it is a palindrome before we loop it
        return true;
    for (int i = 1; i < n; i++) //runs until the string is true unless the string doesn't return true then it is false, only needs to loop 1 less than the length so i=1 and i<n works
    {
        rotateRight(str);
        if (isPalindrome(str))
            return true;
    }
    return false;
}

string checkPasscodes (char str[][500], int num)
{
    string word; //declaring word, which is the string that it will go to
    for (int i = 0; i < num; i++) //checks if it is a palindrome then if it is it puts it in the word and returns the word
    {
        if (checkPalin(str[i]))
        {
            word += str[i];
            word += "\n";
        }
    }
    return word;
}
