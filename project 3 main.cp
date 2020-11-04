//
//  main.cpp
//  Project 3
//
//  Created by priyanka borate on 4/19/20.
//  Copyright © 2020 priyanka borate. All rights reserved.
/*
 Name:Priyanka Borate
 Class:CIS -160 C++
 Date: 4-20-2020
 Program Name: PCCC Palace Hotel
 Description: Program that will input the customer’s
 name, room number, and the number of days they
 stayed in the hotel. Factored in the constants of
 room prices, internet cost, tv usage.The Program will
 display the total bill of the customer's hotel room stay.
*/
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
using namespace std;

// Function to accept customer name room number and number of days staying

void setinfo (string &name, int &roomnumber, int &days)
{
// Accepts customer name
cout<<"\n The customer name please: ";
getline (cin,name);

do
{
cout<<"\n 19 for Single room Single bed $99.99"
<<"\n 20-39 for Family room double bed $149.99"
<<"\n 40-50 for Suite $199.99";

// Accepts room number
cout<<"\n Room Number: ";
cin>>roomnumber;

if(roomnumber >= 19 && roomnumber <= 50)
    break;
// Otherwise invalid room number
else
    cout<<"\n Invalid room number. Try again.";
}
while(1);

// Accepts number of days
cout<<"\n Number of days stayed in the Hotel: ";
cin>>days;
}
float setroom(int roomnumber, int days, string &roomtype)
{
float charges;

if(roomnumber == 19)
{
    roomtype = " in a Single Room.";
    charges = days * 99.99f;
}
if(roomnumber >= 20 && roomnumber <= 39)
{
    roomtype = " in a Family room.";
    charges = days * 149.99f;
}
else
{
    roomtype = " in a Suite.";
    charges = days * 199.99f;
}

return charges;
}
float setnet(int days, string &nettype)
{

    char ch;
    int ac;
    float charges;

cout<<"\n Internet Access Requirements: ";
cout<<"\n Internet Accessed (Y/N): ";
cin>>ch;
{
if(ch == 'Y' || ch == 'y')
{
cout<<"\n Access \n 1 - Wired \n 2 - Not-wired (Wireless): ";
cin>>ac;

if(ac == 1)
{

    nettype = "Wired";
    charges = days * 3.95f;
}
else
{
    nettype = "Wireless";
    charges = days * 5.95f;
}
}

else if(ch == 'N' || ch == 'n')
{

    nettype = "No Internet";
    charges = 0.0f;
}
else
    cout<<"\n Invalid choice! Try again.";
    
if(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n')

    return charges;
}
}

float settv(int days, string &tvtype)
{
char ch;

int tv;

float charges;

cout<<"\n TV Access Requirements: ";
do
{
cout<<"\n TV Used (Y/N): ";
cin>>ch;

if(ch == 'Y' || ch == 'y')
{
cout<<"\n TV Usage \n 1 - Basic Channels \n 2 - Cable Channels: ";
cin>>tv;

if(tv == 1)
{

    tvtype = "Basic channels";
    charges = days * 1.95f;
}
else
{

    tvtype = "Cable Channels";
    charges = days * 4.95f;
}
}

else if(ch == 'N' || ch == 'n')
{

    tvtype = "No TV Access";

}

else
    cout<<"\n Invalid choice! Try again.";

if(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n')
    break;
}
    while(1);
    return charges;
}
void getinfo(string name, int days, int roomnumber, float roomcharges, float netcharges, float tvcharges,
string roomtype, string nettype, string tvtype)
{
    float totalCharges, localTax, totalDue;
    totalCharges = (roomcharges + netcharges + tvcharges);
    localTax = totalCharges * .15f;
    totalDue = totalCharges + localTax;
    
    // output
    cout<<"\n\nPCCC Palace Hotel";
    cout<<name<<"Billing Statement";
    cout<<"\n Number of days in hotel: "<<days;
    cout<<"\tin a"<<roomtype;
    
    cout<<"\n Room Charges $"<<fixed<<setprecision(2)<<roomcharges;
    cout<<"\n Internet Charges ("<<nettype<<") $"<<netcharges;
    cout<<"\n Television Charges ("<<tvtype<<") $"<<tvcharges;
    cout<<"\n\n Total Charges $"<<totalCharges;
    cout<<"\n\n Local Taxes $"<<localTax;
    cout<<"\n\n Total Due $"<<totalDue;
    cout<<"\n\nThank you for using PCCC Palace Hotel. Hope to see you again";
}

int main()
   {
    string name;
    string roomtype, nettype, tvtype;
    int days,roomnumber;
    float roomcharges, netcharges, tvcharges;
    setinfo(name,roomnumber,days);
    roomcharges = setroom(roomnumber, days,roomtype);
    netcharges = setnet(days,nettype);
    tvcharges = settv(days,tvtype);
    getinfo(name, days, roomnumber, roomcharges, netcharges, tvcharges, roomtype, nettype, tvtype);
    
    return 0;
}

//********************RESULTS********************************************************

/*
 The customer name please: PRIYANKA BORATE
                                                        
  19 for Single room Single bed $99.99
  20-39 for Family room double bed $149.99
  40-50 for Suite $199.99
  Room Number: 20
                                                                    
  Number of days stayed in the Hotel: 4
                                                                                 
  Internet Access Requirements:
  Internet Accessed (Y/N): Y
                                  
  Access
  1 - Wired
  2 - Not-wired (Wireless): 2
       
  TV Access Requirements:
  TV Used (Y/N): N
                                                                                         
                             PCCC Palace Hotel
 
  PRIYANKA BORATE Billing Statement
  Number of days in hotel: 4                in a Family room
  Room Charges $599.96
  Internet Charges (Wireless) $23.80
  Television Charges (No TV Access) $23.80
                                                              
  Total Charges $647.56
       
  Local Taxes $97.13
       
  Total Due $744.69
       
  Thank you for using PCCC Palace Hotel. Hope to see you again.
                                                                                        
 ...Program finished with exit code 0
 Press ENTER to exit console.
*/
//********************RESULTS********************************************************

