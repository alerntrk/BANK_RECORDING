#ifndef BANK_REC_H_INCLUDED
#define BANK_REC_H_INCLUDED
#include <iostream>
#include <fstream>
#include<cstdlib>
#include <string>
using namespace std;
bool isempty=true;
class account{
private:
    string name;
    string surname;
    string ac_no;
    float total_balance;
public:
    void readData();//take input data 
    void writeRec();//write datas to file
    void printData();//print the data in the class
    void showRec();//show the saved data on the console
    void edit();//edit any account in the file
    void Delete();//delete the saved account in th file
};



#endif // BANK_REC_H_INCLUDED
