/*This program simulates a Pokémon battle by reading Pokémon data and attack information from files, calculating damage, and determining which Pokémon are still healthy*/

#include<iostream> //including libraries
#include<fstream>
#include<cstring>
using namespace std;
struct Move //making move struct
{
    char name[50];
    int moveDamage;
};

struct Pokemon //making pokemon struct
{
    char name[50];
    char type[50];
    int hitPoints;
    int defenceRating;
    bool isAwake;
    char moveName[50];
};

int main()
{
    int M, N, K; //declaring integers I will be using
    ifstream poke;
    poke.open("pokemon.txt"); //allowing input into pokemon.txt
    poke>>M; //inputs the M amount of moves
    Move* moves = new Move[M]; //the dynamic array called moves has M structs
    poke.ignore(); //ignores new line
    for (int i = 0; i<M; i++) //inputs name and damage
    {
        poke.getline(moves[i].name, 50, '\t');
        poke>>moves[i].moveDamage;
        poke.ignore();
    }
    poke>>N; //same thing as above
    Pokemon* pokemons = new Pokemon[N];
    poke.ignore();
    for (int i = 0; i<N; i++) //inputting the other struct information now
    {
        poke.getline(pokemons[i].name, 50, '\t');
        poke.getline(pokemons[i].type, 50, '\t');
        poke>>pokemons[i].hitPoints;
        poke.ignore();
        poke>>pokemons[i].defenceRating;
        poke.ignore();
        poke.getline(pokemons[i].moveName, 50);
        pokemons[i].isAwake=true;
    }
    poke.close(); 
    ifstream sess;
    sess.open("session.txt"); //allowing input from session.txt
    sess>>K;
    string attacker, move, target;
    int attackRating;
    for(int i = 0; i<K; i++) //K amount of attacks in the loop
    { 
        sess>>attacker>>move>>target>>attackRating; //inputing attacker and its target
        int attackerIndex = -1, targetIndex = -1, moveIndex = -1; //in case we don't find it so initalize to -1
        for(int j = 0; j<N; j++)
        {
            if(strcmp(pokemons[j].name, attacker.c_str()) == 0) //finding where the attacker and target is at
                attackerIndex = j;
            if(strcmp(pokemons[j].name, target.c_str()) == 0)
                targetIndex = j;
        }
        for (int k = 0; k<M; k++) //find out where the move is
        {
            if(strcmp(moves[k].name, move.c_str()) == 0)
                moveIndex = k;
        }
        if (strcmp(pokemons[attackerIndex].moveName, moves[moveIndex].name) == 0 && attackRating >= pokemons[targetIndex].defenceRating) //loop to see if the attack makes the target faint and shoots out a message
        {
            pokemons[targetIndex].hitPoints -= moves[moveIndex].moveDamage;
            if (pokemons[targetIndex].hitPoints <= 0)
            {
                pokemons[targetIndex].isAwake = false;
            }
        }
    }
    sess.close();
    ofstream healthy;
    healthy.open("healthy.txt"); //prints all healthy pokemon to healthy.txt
    for (int i = 0; i<N; i++)
    {
        if (pokemons[i].isAwake == true)
            healthy<<pokemons[i].name<<" "<<pokemons[i].hitPoints<<endl;
    }
    healthy.close();
    delete[] moves;
    delete[] pokemons;
    return 0;
}
