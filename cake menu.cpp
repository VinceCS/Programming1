/* This program takes the user's input of four cake radii and slice counts, calculates the volume per slice using arithmetic operations, and orders the cakes by volume using conditional statements.
 */

#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
    cout << fixed << setprecision (4); //sets the decimal to 4
    double a,b,c,d;
    cout<<"Input the radii of 4 cakes: "<<endl;
    cin>>a>>b>>c>>d;

    int s,ss,sss,ssss;
    cout<<"Input the slices for each cake: "<<endl;
    cin>>s>>ss>>sss>>ssss;

    double vol1, vol2, vol3, vol4;
    vol1 = ((4.0/3)*3.14*a*a*a)/s;
    vol2 = ((4.0/3)*3.14*b*b*b)/ss;
    vol3 = ((4.0/3)*3.14*c*c*c)/sss;
    vol4 = ((4.0/3)*3.14*d*d*d)/ssss;

    if (vol1 == vol4 && vol2 == vol4 && vol3 == vol4) //checks the volumes to see if they are all equal
        {
        cout << "Error: You have inputted the same volume for all 4 cakes." << endl;
        }
    else
    {
        if (vol1 <= vol2 && vol1 <= vol3 && vol1<= vol4) //checks the first number
            {
            cout<< "Cake 1: " << vol1 << endl;
            if (vol2 <= vol3 && vol2 <= vol4) //the second number
                {
                cout<<"Cake 2: " <<vol2 <<endl;
                if (vol3 <= vol4) //third
                    {
                    cout<< "Cake 3: " << vol3 <<endl;
                    cout<< "Cake 4: " << vol4 <<endl;
                    }
                else //has to be this one if there so you can just be a else
                    {
                    cout<<"Cake 4: "<< vol4 <<endl<<"Cake 3: "<< vol3<< endl;
                    }
                }
            else if (vol3 <= vol2 && vol3 <= vol4) //another condtion to test the number
                {
                cout<< "Cake 3: " <<vol3<< endl;
                    if (vol2 <= vol4)
                    {
                    cout<<"Cake 2: "<< vol2 <<endl;
                    cout<<"Cake 4: "<< vol4 <<endl;
                    }
                else
                    {
                    cout<<"Cake 4: "<< vol4 <<endl;
                    cout<<"Cake 2: "<< vol2 <<endl;
                    }
                }
            else //has to be this if it isn't the other options
                {
                cout << "Cake4: " << vol4 << endl;
                if (vol2 <= vol3)
                    {
                    cout<<"Cake 2: "<< vol2 <<endl;
                    cout<<"Cake 3: "<< vol3 <<endl;
                    }
                else
                    {
                    cout<<"Cake 3: "<< vol3 <<endl;
                    cout<<"Cake 2: "<< vol2 <<endl;
                    }
                }
            }
        if (vol2 <= vol1 && vol2 <= vol3 && vol2<= vol4) //rinse and repeat
            {
            cout<< "Cake 2: " << vol2 << endl;
            if (vol1 <= vol3 && vol1 <= vol4)
                {
                cout<< "Cake 1: " << vol1 << endl;
                if (vol3 <= vol4)
                    {
                    cout<< "Cake 3: " << vol3 <<endl;
                    cout<< "Cake 4: " << vol4 <<endl;
                    }
                else
                    {
                    cout<<"Cake 4: " << vol3 << endl <<"Cake 3: "<< vol4<< endl;
                    }
                }
            if (vol3 <= vol1 && vol3 <= vol4)
                {
                cout<< "Cake 3: " <<vol3<< endl;
                if (vol1 <= vol4)
                    {
                    cout<<"Cake 1: "<< vol1 <<endl;
                    cout<<"Cake 4: "<< vol4 <<endl;
                    }
                else
                    {
                    cout<<"Cake 4: "<< vol4 <<endl;
                    cout<<"Cake 1: "<< vol1 <<endl;
                    }
                }
            if (vol4 <= vol1 && vol4 <= vol2 && vol4 <= vol3)
                {
                cout << "Cake4: " << vol4 << endl;
                if (vol1 <= vol3)
                    {
                    cout<<"Cake 1: "<< vol1 <<endl;
                    cout<<"Cake 3: "<< vol3 <<endl;
                    }
                else
                    {
                    cout<<"Cake 3: "<< vol3 <<endl;
                    cout<<"Cake 1: "<< vol1 <<endl;
                    }
                }
            }
        if (vol3 <= vol1 && vol3 <= vol2 && vol3<= vol4)
            {
            cout<< "Cake 3: " << vol3 << endl;
            if (vol1 <= vol2 && vol1 <= vol4)
                {
                cout<< "Cake 1: " << vol1 << endl;
                if (vol2 <= vol4)
                    {
                    cout<< "Cake 2: " << vol2 <<endl;
                    cout<< "Cake 4: " << vol4 <<endl;
                    }
                else
                    {
                    cout<<"Cake 4: "<< vol4 << endl << "Cake 2: " << vol2 << endl;
                    }
                }
            if (vol2 <= vol1 && vol2 <= vol4)
                {
                cout<< "Cake 2: " << vol2 << endl;
                if (vol1 <= vol4)
                    {
                    cout<< "Cake 1: " << vol1 <<endl;
                    cout<< "Cake 4: " << vol4 <<endl;
                    }
                else
                    {
                    cout<<"Cake 4: "<< vol4 <<endl<<"Cake 1: "<< vol1<< endl;
                    }
                }
            else
                {
                cout << "Cake 4: " << vol4 << endl;
                if (vol1 <= vol2)
                    {
                    cout <<"Cake 1: " << vol1<<endl;
                    cout <<"Cake 2: " << vol2<<endl;
                    }
                else
                    {
                    cout<<"Cake 2: "<< vol2 <<endl<<"Cake 1: "<< vol1<< endl;
                    }
                }
            }
        if (vol4 <= vol1 && vol4 <= vol2 && vol4 <= vol3)
            {
            cout<< "Cake 4: " << vol4 << endl;
            if (vol1 <= vol2 && vol1 <= vol3)
                {
                cout<< "Cake 1: " << vol1 << endl;
                if (vol2 <= vol3)
                    {
                    cout<< "Cake 2: " << vol2 <<endl;
                    cout<< "Cake 3: " << vol3 <<endl;
                    }
                else
                    {
                    cout<<"Cake 3: "<< vol3 <<endl<<"Cake 2: "<< vol2<< endl;
                    }
                }
            else if (vol2 <= vol1 && vol2 <= vol3)
                {
                cout<< "Cake 2: " << vol2 << endl;
                if (vol1 <= vol3)
                    {
                    cout<< "Cake 1: " << vol1 <<endl;
                    cout<< "Cake 3: " << vol3 <<endl;
                    }
                else
                    {
                    cout<<"Cake 3: "<< vol3 <<endl<<"Cake 1: "<< vol1<< endl;
                    }
                }
            else
                {
                cout << "Cake 3: " << vol3 << endl;
                if (vol1 <= vol2)
                    {
                    cout <<"Cake 1: " << vol1<<endl;
                    cout<< "Cake 2: " << vol2 <<endl;
                    }
                else
                    {
                    cout<<"Cake 2: "<< vol2 <<endl<<"Cake 1: "<< vol1<< endl;
                    }
                }
            }
    }
return 0;
}
