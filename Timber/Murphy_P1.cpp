//----------------------------------------------------------------------------
// EGR 126 ELI Fall 2017
//----------------------------------------------------------------------------
// Student Name : Rich MURPHY
// Assignment : Project 1
// Submission Date : 9/24/17
// Complier Info : MacOS, Xcode
// Purpose : This program computes the area reforested given some initial conditions from the user.
//----------------------------------------------------------------------------

#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()

{
    // These are our variables.
    string Forest_Name;
    double Desired_Area_Refor;
    double Beg_Unharvested(0);
    double Refor_rate;
    double Reforested_Area(0);
    int Menu_Sel;
    
    cout << "========================================" << endl;
    cout << " Timber Resources Software" << endl;
    cout << " Version 1.0 " << endl;
    cout << "========================================" << endl << endl;
    
    // We get the user to input values for each variable.
    cout << "Please enter a forest name: ";
    cin>> Forest_Name;
    cout << "Please enter the area to be reforested (in acres): ";
    cin>> Desired_Area_Refor;
    cout << "Please enter the area left unharvested at the beginning of the year (in acres): ";
    cin>> Beg_Unharvested;
    cout << "Please enter the annual reforestation rate (as a decimal): ";
    cin>> Refor_rate;
    cout << endl << endl;
    
    // We display to the user what they entered.
    cout << " You entered " << endl;
    cout << "---------------------------------------" << endl;
    cout << " Forest Name: ";
    cout << Forest_Name << endl;
    cout << " Area to be Reforested: ";
    cout << Desired_Area_Refor << endl;
    cout << " Area left unharvested at beginning of year: ";
    cout << Beg_Unharvested << endl;
    cout << " Reforestration rate per year: ";
    cout << Refor_rate*100 << "%" << endl;
    cout << endl;
  
    do
    {
        // We ask the user what they'd like to do.
        cout << "What would you like to do?" << endl;
        cout << "======================================"<< endl;
        cout << "Option 1 Forestation Table (25 Years)" << endl;
        cout << "Option 2 Reforestation Calculator" << endl;
        cout << "Option 3 Exit" << endl;
        cout << "======================================" << endl;
        cout << endl;
        cin >> Menu_Sel;
        
            if (Menu_Sel==1) // This produces a table of 25 years worth of growth.
            {
            cout<<"Years\tTotal Forested Acres"<<endl;
                Reforested_Area = Beg_Unharvested;
                for(int i=0; i<25 ;i++)
                {
                    Reforested_Area = Reforested_Area + (Reforested_Area*Refor_rate);
                    cout<<i+1<<"\t\t"<<Reforested_Area<<endl;
                    cout << endl;
                }
            }
        
            else if (Menu_Sel == 2) // This computes the number of years needed to reforest to the deisred level given the entered growth rate and how many acres you have to start with. A general solution to this problem is to take the log(Desired_Area_Refor/Beg_Unharvested) / log(1+Refor_Rate). This is the solution to solving for the exponent in the equation: Beg_Unharvested*(1+Refor_Rate)^n = Desired_Area_Refor where "n" is a number of years.
            {
                cout << "It will take " << log10(Desired_Area_Refor/Beg_Unharvested)/log10(1+Refor_rate)<< " years to reforest " << Desired_Area_Refor << " acres if we start out with " << Beg_Unharvested << " acres and it grows at a rate of " << Refor_rate*100 << "% per year.";
                cout << endl << endl;
            }
        
            else if (Menu_Sel == 3) // Our messaage upon exiting to the user.
            {
                cout << "===============================================================" << endl;
                cout << "Thank You For Using Timber Resources Software, Have A Nice Day!" << endl;
                cout << "===============================================================" << endl;
                cout << endl;
            }
        
            else if (Menu_Sel != 3) // Error message if an invalid menu entry is made.
            {
                cout << "Oops Invalid Entry, Please Try Again" << endl;
                cout << endl;
            }
        
    } while (Menu_Sel != 3);
    
    return 0;
}
