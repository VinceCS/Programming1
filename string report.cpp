/*This program analyzes a user-input string (ending with #) and reports the number of whitespace characters, hexadecimal digits, and alphabet characters that appear in both uppercase and lowercase forms.*/

#include <iostream> //including the 3 libraries
#include <cctype>
#include <string>
using namespace std;
int spaceCount (string str); //declaring my 3 functions
int digitCount (string str);
int caseMatchCount (string str);

int main()
{
    string str; //declaring str variable
    do //do until something breaks it
    {
        cout<<"Enter the string: "; //prompts the user
        getline (cin, str, '#'); //letting the user put a string with spaces
        cin.ignore (999999999999, '\n'); //clearing the input buffer so you can put another thing in string
        if (str == "Done") //break if the string is done
            break;
        
        cout<<"Number of whitespace characters: "<<spaceCount(str)<<endl; //calls the functions
        cout<<"Number of hexadecimal digits: "<<digitCount(str)<<endl;
        cout<<"Number of matched characters: "<<caseMatchCount(str)<<endl;
    
    } while (true);
    return 0;
}

int spaceCount (string str)
{
    int count = 0; //count is 0
    for (char ch : str) //char ch : str counts every character in the string
        if (ch  == ' ')
            count++; //adds to count whenever there is a white space
    return count; //returns count
}

int digitCount (string str)
{
    int count = 0; //count is starting at 0
    for (char ch : str) //loop for every character in the string
        if (isxdigit(ch)) //if it is a hexadigit add 1 to count
            count++;
    return count; //return count
}


int caseMatchCount (string str)
{
    int lowercaseCount[26] = {0}; //array to count if a lower case letter is used for each lowercase letter
    int uppercaseCount[26] = {0}; //same but for upper case
    int count = 0; //count starting at 0
    for (char ch : str) //loop for every character
    {
        if (isalpha(ch) && islower(ch)) //if it is a chararcter and is lowercased, substract the value of a to get to the right part of the array
            lowercaseCount[ch - 'a'] = 1; // a is 97, 97-97 is 0, 0 is where a is stored
        else if (isalpha(ch) && isupper(ch)) //loop but for upper case
            uppercaseCount[ch - 'A'] = 1; //same as the one above
    }
    for (int i = 0; i<26; i++) //goes through all the array for both
    {
        if (lowercaseCount[i] == 1 && uppercaseCount[i] == 1) //if they both are used in the string count adds by 1
            count++;
    }
    return count; //return count
}
