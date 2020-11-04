//  main.cpp
//  PROJECT 4
//  Created by priyanka borate on 2/18/20.
//  Copyright © 2020 priyanka borate. All rights reserved.
/*
 Name:Priyanka Borate
 Class:CIS- 160
 Date:2-19-20
 Program Name:CASWELL CATERING
 Description:This program gives an output of the total bill of catering event, based on inputs. The inputs are adult count, child count,adult cost, the dessert cost,room cost and the dessert count. The deposit, taxes and tips are also factored in.

 */
#include <iostream>
#include <fstream>

using namespace std;

//declaring

int main (int argc, char const * argv[]) {
int inputcontract, salary_eachemplo, i=1, pl;
int amount, cost, profloss, electrician, plumber, roofer, landscaper, salary, materials;
int costwood, concrete, costwindows, costdoors, sheetrock, spackle;
int total_amt = 0, total_cost = 0, total_profloss = 0, total_elec = 0, total_plumb=0;
int total_roof = 0, total_landsc = 0, total_materialcost = 0, total_sal = 0;

//open file
ofstream myfile;
myfile.open("contracts.txt");


cout << "To accept a new contract press 1: To exit, press 0: ";
cin >> inputcontract;

while (inputcontract) {
    cout << "Contract #" << i << endl;
    cout << "Enter amount of contract: ";
    cin  >> amount; total_amt += amount;
    cost = 0;

    cout << "Enter amount paid to subcontractors: \n";
    cout << "Electrician = ";
    cin >> electrician;
    cost += electrician;
    total_elec += electrician;
    cout << "Plumber = "; cin >> plumber; cost += plumber; total_plumb += plumber;
    cout << "Roofer = "; cin >> roofer; cost += roofer; total_roof += roofer;
    cout << "Landscaper = "; cin >> landscaper; cost += landscaper; total_landsc += landscaper;

    cout << "Enter the internal salaries paid to each employee. To stop, press 0 = ";
    cin >> salary_eachemplo;
    salary = 0;

while (salary_eachemplo) {
    salary = salary + salary_eachemplo;
    
    cout << "Enter the internal salaries paid to each employee. To stop, press 0 = ";
    cin >> salary_eachemplo;
}

    cost += salary;
    total_sal += salary;

cout << "Enter cost of materials paid by company\n";
cout << "Wood = ";
cin >> costwood;
cout << "Concrete = ";
cin >> concrete;
cout << "Windows = ";
cin >> costwindows;
cout << "Doors = ";
cin >> costdoors;
cout << "Sheetrock = ";
cin >> sheetrock;
cout << "Spackle = ";
cin >> spackle;

    materials = costwood + concrete + costwindows + costdoors + sheetrock + spackle;
    cost += materials;
    total_materialcost += materials;
    total_cost += cost;
    cout << "\nFor contract #" << i << endl;

  if (amount > cost) {
    profloss = amount-cost; pl = 1;
    total_profloss += profloss;
    cout << "Profit = " << profloss << endl;
}
   else {
    profloss = cost-amount; pl = 0;
    total_profloss -= profloss;
    cout << "Loss = " << profloss << endl;
}

    myfile << "Contract #" << i << "\n";
    myfile << "Amount = " << amount << "\n";
    myfile << "Cost = " << cost << "\n";
    
 if (pl) {
     myfile << "Profit/Loss = +" << profloss << "\n";
    
    }
    
 else {
     myfile << "Profit/Loss = -" << profloss << "\n";
    
    }
    
    
    cout << "\n\n To accept a new contract press 1, OR exit press 0: ";
    cin >> inputcontract;
    i++;
    
    }
    
    myfile << "Total electrical cost = " << total_elec << "\n";
    myfile << "Total plumbing cost = " << total_plumb << "\n";
    myfile << "Total roofing cost = " << total_roof << "\n";
    myfile << "Total landscaping cost = " << total_landsc << "\n";
    myfile << "Total materials cost = " << total_materialcost << "\n";
    myfile << "Total salaries cost = " << total_sal << "\n";
    myfile << "\n";
    
    myfile << "Total amount of all contracts = " << total_amt << "\n";
    myfile << "Total cost of all contracts = " << total_cost << "\n";
    myfile << "Total profit/loss of all contracts = " << total_profloss << "\n";
    
    myfile.close();
    
    return 0;
}

