#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int Setup = 0,SumVehicles = 0;
float SumMoney = 0;
string adminpassword = "admin",managerpassword = "manager",operatorpassword = "operator";

void managepassword()
{
std::system("cls");
cout << "\n**************************************";
cout << "\n***********MANAGE-PASSWORD************";
cout << "\n**************************************";
int ch;
while(ch != 3)
{
cout << "\n1->View Passwords";
cout << "\n2->Edit Passwords";
cout << "\n3->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
case 1: cout << "\nAdmin : " << adminpassword << "\nManager : " << managerpassword << "\nOperator : " << operatorpassword;break;
case 2:
{
cout << "\nEnter Admin Password : ";
cin >> adminpassword;
cout << "\nEnter Manager Password : ";
cin >> managerpassword;
cout << "\nEnter Operator Password : ";
cin >> operatorpassword;
break;
}
case 3: break;
}
}
}

class tollGate
{
string password;
float cash = 0;
int vehicles = 0;
float car,jeep,truck,bus,trailer,government = 0.0;
public:
void resetCash() {cash = 0.0;}
void resetVehicles() {vehicles = 0.0;}
float showCash() {return cash;}
int showVehicles() {return vehicles;}
void setPassword(string pass) {password = pass;}
bool checkPassword(string pass) {if(pass == password) return true;}
void setCost(float a,float b,float c,float d,float e,float f)
{
car = a;jeep = b;truck = c;bus = d;trailer = e;government = f;
}
void showCost()
{
cout << "\ncar : " << car << " jeep : " << jeep << " truck : " << truck << " bus : " << bus << " trailer : " << trailer << " government : " << government;
}
void taxcollect(int type)
{
switch(type)
{
case 1: cash += car;vehicles++;break;
case 2: cash += jeep;vehicles++;break;
case 3: cash += truck;vehicles++;break;
case 4: cash += bus;vehicles++;break;
case 5: cash += trailer;vehicles++;break;
case 6: cash += government;vehicles++;break;
}
}
};

class tollBooth
{
public:
tollGate gateA,gateB,gateC;
private:
string stationName;
float totalCash = 0;
int totalCar = 0;
public:
void setStationName(string name) {stationName = name;}
string showStationName() {return stationName;}
void resetTotalCash() {totalCash = 0.0;}
void resetTotalVehicles() {totalCar = 0.0;}
float showTotalCash()
{
totalCash = totalCash + gateA.showCash() + gateB.showCash() + gateC.showCash();
return totalCash;
}
int showTotalVehicles()
{
totalCar = totalCar + gateA.showVehicles() + gateB.showVehicles() + gateC.showVehicles();
return totalCar;
}
};

class highway
{
string highwayName;
public:
tollBooth stationA,stationB;
void setHighwayName(string name) {highwayName = name;}
string showHighwayName() {return highwayName;}
};

highway t;

void setup()
{
std::system("cls");
int ch;
do{
string name;
cout << "\n----------Welcome to Toll Tax Program----------";
cout << "\nEnter the Name of the Highway to set up the program : ";
cin >> name;
t.setHighwayName(name);
cout << "\nFor highway " << t.showHighwayName() << " we have an ideal two Stations for entry and exit.";
cout << "\nEach Entry point has 3 booths to pay cash and 3 at exit point to verify.";
cout << "\nSet the data of the toll station.";
cout << "\nEnter name of the Station A : ";
cin >> name;
t.stationA.setStationName(name);
cout << "\nEnter name of the Station B : ";
cin >> name;
t.stationB.setStationName(name);
cout << "\nBy default the booth's names are a,b,c,d,e,f for entry \nwhere a,b,c belong to station A and d,e,f belong to staion B";
cout << "\nVerify the following data -> Highway Name is : " << t.showHighwayName() << " Station A is : " << t.stationA.showStationName() << " Station B is : " << t.stationB.showStationName();

cout << "\nif correct press 1 or press 0 to edit : ";
cin >> ch;
}while(ch != 1);
Setup = 1;
};

void setTax()
{
std::system("cls");
int ch;
do{
float car,jeep,truck,bus,trailer,government;
cout << "\nEnter the Tax for following vehicles...";
cout << "\n1-> Car : ";
cin >> car;
cout << "\n1-> Jeep : ";
cin >> jeep;
cout << "\n1-> Truck : ";
cin >> truck;
cout << "\n1-> Bus : ";
cin >> bus;
cout << "\n1-> Trailer : ";
cin >> trailer;
cout << "\n1-> Government : ";
cin >> government;
t.stationA.gateA.setCost(car,jeep,truck,bus,trailer,government);
t.stationA.gateB.setCost(car,jeep,truck,bus,trailer,government);

t.stationA.gateC.setCost(car,jeep,truck,bus,trailer,government);
t.stationB.gateA.setCost(car,jeep,truck,bus,trailer,government);
t.stationB.gateB.setCost(car,jeep,truck,bus,trailer,government);
t.stationB.gateC.setCost(car,jeep,truck,bus,trailer,government);
cout << "\nYou have entered the following data as your cost :";
t.stationA.gateA.showCost();
cout << "\nif correct press 1 or press 0 to edit : ";
cin >> ch;
}while(ch != 1);
}

void admin()
{
std::system("cls");
string pass;
cout << "\n**************************************";
cout << "\n*************ADMIN-PAGE***************";
cout << "\n**************************************";
cout << "\nEnter Password to continue : ";
cin >> pass;
if(pass == adminpassword)
{
if(Setup != 1)
{
cout << "\nSetup is Not Complete Starting Setup...";
setup();
setTax();
}
else
{
int ch;
while(ch != 4)
{
std::system("cls");
cout << "\n1->EDIT DETAILS";
cout << "\n2->EDIT TAX";
cout << "\n3->EDIT PASSWORDS";
cout << "\n4->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
case 1: setup();break;
case 2: setTax();break;
case 3: managepassword();break;
case 4: break;
}
}

}
}
else
cout << "\n\nWrong Password...";
}

void manager()
{
std::system("cls");
string pass;
cout << "\n**************************************";
cout << "\n************MANAGER-PAGE**************";

cout << "\n**************************************";
cout << "\nEnter Password to continue : ";
cin >> pass;
if(pass == managerpassword)
{
int ch;
while(ch != 4)
{
cout << "\n1->VIEW TOTAL CASH";
cout << "\n2->VIEW TOTAL CAR";
cout << "\n3->SAVE DATA FOR DAY(RESET CASH)";
cout << "\n4->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
case 1:
{
cout << "\nThe Total Cash is : " << t.stationA.showTotalCash() + t.stationB.showTotalCash();
cout << "\nThe Total Cash From Station " << t.stationA.showStationName() << " is : " << t.stationA.showTotalCash()/2;
cout << "\nThe Total Cash From Station " << t.stationB.showStationName() << " is : " << t.stationB.showTotalCash()/2;
cout << "\nThe Total Cash From Station " << t.stationA.showStationName() << " Gate A is : " << t.stationA.gateA.showCash();

cout << "\nThe Total Cash From Station " << t.stationA.showStationName() << " Gate B is : " << t.stationA.gateB.showCash();
cout << "\nThe Total Cash From Station " << t.stationA.showStationName() << " Gate C is : " << t.stationA.gateC.showCash();
cout << "\nThe Total Cash From Station " << t.stationB.showStationName() << " Gate A is : " << t.stationB.gateA.showCash();
cout << "\nThe Total Cash From Station " << t.stationB.showStationName() << " Gate B is : " << t.stationB.gateB.showCash();
cout << "\nThe Total Cash From Station " << t.stationB.showStationName() << " Gate C is : " << t.stationB.gateC.showCash();
break;
}
case 2:
{
cout << "\nThe Total Vehicles is : " << t.stationA.showTotalVehicles() + t.stationB.showTotalVehicles();
cout << "\nThe Total Vehicles From Station " << t.stationA.showStationName() << " is : " << t.stationA.showTotalVehicles()/2;
cout << "\nThe Total Vehicles From Station " << t.stationB.showStationName() << " is : " << t.stationB.showTotalVehicles()/2;
cout << "\nThe Total Vehicles From Station " << t.stationA.showStationName() << " Gate A is : " << t.stationA.gateA.showVehicles();
cout << "\nThe Total Vehicles From Station " << t.stationA.showStationName() << " Gate B is : " << t.stationA.gateB.showVehicles();
cout << "\nThe Total Vehicles From Station " << t.stationA.showStationName() << " Gate C is : " << t.stationA.gateC.showVehicles();
cout << "\nThe Total Vehicles From Station " << t.stationB.showStationName() << " Gate A is : " << t.stationB.gateA.showVehicles();
cout << "\nThe Total Vehicles From Station " << t.stationB.showStationName() << " Gate B is : " << t.stationB.gateB.showVehicles();
cout << "\nThe Total Vehicles From Station " << t.stationB.showStationName() << " Gate C is : " << t.stationB.gateC.showVehicles();
break;
}
case 3:
{
SumMoney = SumMoney + t.stationA.showTotalCash() + t.stationB.showTotalCash();
SumVehicles = SumVehicles + t.stationA.showTotalVehicles() + t.stationB.showTotalVehicles();
t.stationA.resetTotalCash();
t.stationB.resetTotalCash();
t.stationA.gateA.resetCash();
t.stationA.gateB.resetCash();
t.stationA.gateC.resetCash();
t.stationB.gateA.resetCash();
t.stationB.gateB.resetCash();
t.stationB.gateC.resetCash();

t.stationA.resetTotalVehicles();
t.stationB.resetTotalVehicles();
t.stationA.gateA.resetVehicles();
t.stationA.gateB.resetVehicles();
t.stationA.gateC.resetVehicles();
t.stationB.gateA.resetVehicles();
t.stationB.gateB.resetVehicles();
t.stationB.gateC.resetVehicles();
cout << "\n DONE........";
break;
}
case 4: break;
}
}
}
else
cout << "\n\nWrong Password...";
}

void operetor()
{
std::system("cls");
string pass;
cout << "\n**************************************";
cout << "\n************OPERATOR-PAGE*************";
cout << "\n**************************************";
cout << "\nEnter Password to continue : ";
cin >> pass;
if(pass == operatorpassword)
{
int x,y;
cout << "\nStation A-> 1 Station B-> 2";
cout << "\nEnter the Station No. :";
cin >> x;
cout << "\nEnter the Station No. :";
cout << "\nA-> 1 B-> 2 C-> 3";
cout << "\nEnter the booth No. :";
cin >> y;
switch(x)
{
case 1:
{
switch(y)
{
case 1:
{
int ch;
while(ch != 7)
{
std::system("cls");
cout << "\n1->CAR";
cout << "\n2->JEEP";
cout << "\n3->TRUCK";
cout << "\n4->BUS";
cout << "\n5->TRAILER";
cout << "\n6->GOVERNMENT";
cout << "\n7->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
case 1: t.stationA.gateA.taxcollect(1);break;
case 2: t.stationA.gateA.taxcollect(2);break;
case 3: t.stationA.gateA.taxcollect(3);break;
case 4: t.stationA.gateA.taxcollect(4);break;
case 5: t.stationA.gateA.taxcollect(5);break;
case 6: t.stationA.gateA.taxcollect(6);break;
case 7: break;
}
}
break;
}
case 2:
{
int ch;
while(ch != 7)
{
std::system("cls");
cout << "\n1->CAR";
cout << "\n2->JEEP";
cout << "\n3->TRUCK";
cout << "\n4->BUS";
cout << "\n5->TRAILER";
cout << "\n6->GOVERNMENT";
cout << "\n7->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
case 1: t.stationA.gateB.taxcollect(1);break;
case 2: t.stationA.gateB.taxcollect(2);break;
case 3: t.stationA.gateB.taxcollect(3);break;
case 4: t.stationA.gateB.taxcollect(4);break;
case 5: t.stationA.gateB.taxcollect(5);break;
case 6: t.stationA.gateB.taxcollect(6);break;
case 7: break;
}
}
break;
}
case 3:
{
std::system("cls");
int ch;
while(ch != 7)
{
std::system("cls");
cout << "\n1->CAR";
cout << "\n2->JEEP";
cout << "\n3->TRUCK";
cout << "\n4->BUS";
cout << "\n5->TRAILER";
cout << "\n6->GOVERNMENT";
cout << "\n7->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
case 1: t.stationA.gateC.taxcollect(1);break;
case 2: t.stationA.gateC.taxcollect(2);break;
case 3: t.stationA.gateC.taxcollect(3);break;
case 4: t.stationA.gateC.taxcollect(4);break;
case 5: t.stationA.gateC.taxcollect(5);break;
case 6: t.stationA.gateC.taxcollect(6);break;
case 7: break;
}
}
break;
}
}
break;
}
case 2:
{
switch(y)
{
case 1:
{
std::system("cls");
int ch;
while(ch != 7)
{
std::system("cls");
cout << "\n1->CAR";
cout << "\n2->JEEP";
cout << "\n3->TRUCK";
cout << "\n4->BUS";
cout << "\n5->TRAILER";
cout << "\n6->GOVERNMENT";
cout << "\n7->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
case 1: t.stationB.gateA.taxcollect(1);break;
case 2: t.stationB.gateA.taxcollect(2);break;
case 3: t.stationB.gateA.taxcollect(3);break;
case 4: t.stationB.gateA.taxcollect(4);break;
case 5: t.stationB.gateA.taxcollect(5);break;
case 6: t.stationB.gateA.taxcollect(6);break;
case 7: break;
}
}
break;
}
case 2:
{
std::system("cls");
int ch;
while(ch != 7)
{
std::system("cls");
cout << "\n1->CAR";
cout << "\n2->JEEP";
cout << "\n3->TRUCK";
cout << "\n4->BUS";
cout << "\n5->TRAILER";
cout << "\n6->GOVERNMENT";
cout << "\n7->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
std::system("cls");
case 1: t.stationB.gateB.taxcollect(1);break;
case 2: t.stationB.gateB.taxcollect(2);break;
case 3: t.stationB.gateB.taxcollect(3);break;
case 4: t.stationB.gateB.taxcollect(4);break;
case 5: t.stationB.gateB.taxcollect(5);break;
case 6: t.stationB.gateB.taxcollect(6);break;
case 7: break;
}
}
break;
}
case 3:
{
std::system("cls");
int ch;
while(ch != 7)
{
std::system("cls");
cout << "\n1->CAR";
cout << "\n2->JEEP";
cout << "\n3->TRUCK";
cout << "\n4->BUS";
cout << "\n5->TRAILER";
cout << "\n6->GOVERNMENT";
cout << "\n7->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
switch(ch)
{
case 1: t.stationB.gateC.taxcollect(1);break;
case 2: t.stationB.gateC.taxcollect(2);break;
case 3: t.stationB.gateC.taxcollect(3);break;
case 4: t.stationB.gateC.taxcollect(4);break;
case 5: t.stationB.gateC.taxcollect(5);break;
case 6: t.stationB.gateC.taxcollect(6);break;
case 7: break;
}
}
break;
}
}
break;
}
}

}
else
cout << "\n\nWrong Password...";
}

void startup()
{
int ch;
while(ch != 4)
{
std::system("cls");
cout << "\n**************************************";
cout << "\n*************TOLL - TAX***************";
cout << "\n**************************************";
cout << "\n1->LOG-IN as Operator";
cout << "\n2->LOG-IN as Manager";
cout << "\n3->LOG-IN as Admin";
cout << "\n4->EXIT";
cout << "\nEnter your choice : ";
cin >> ch;
if(Setup != 1)
{
cout << "\nSetup is Not Complete LOGGING as Admin to complete it...";
ch = 3;
}
switch(ch)
{
case 1: operetor();break;
case 2: manager();break;
case 3: admin();break;
case 4: break;
}
}
}

int main()
{
startup();

cout << "\npress enter to continue...";
cin.ignore();cin.get();
return 0;
}

