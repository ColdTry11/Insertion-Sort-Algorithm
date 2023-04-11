#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Employee.h"

using namespace std;

int main(int argc, char** argv)
{
    //Check for command line error
    if (argc == 1) {
        cout << "You forgot the command line parameter" << endl;
        exit(0);
    }

    //Check for file
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not find file " << argv[1] << endl;
        exit(0);
    }

    //Get how many lines
    string line;
    getline(ifs, line);
    int n = stoi(line);

    //initializing an array
    Employee** employee = new Employee * [n];

    //loop through file
    for (int i = 0; i < n; i++) {
        int age;
        int id;
        int year;
        string name;
        string job;
        string ids;
        string a;
        string y;
        getline(ifs, name, '|');
        getline(ifs, ids, '|');
        getline(ifs, a, '|');
        getline(ifs, job, '|');
        getline(ifs, y);
        id = stoi(ids);
        age = stoi(a);
        year = stoi(y);
        Employee* emp = new Employee(name, id, age, job, year);

        //Add to array
        employee[i] = emp;


    }

    //INSERTION SORT
    int i, j;
    int comparison = 0;
    for (int i = 1; i < n; i++) {
        auto key = employee[i];
        j = i - 1;
        // Move elements of arr[0..i-1],that are greater than key, to one position ahead of their current position
        while (j >= 0 && employee[j]->getID() > key->getID()) {
            comparison++;
            employee[j + 1] = employee[j];
            j = j - 1;
        }
        employee[j + 1] = key;
        for (int k = 0; k < n; k++) {
            cout << employee[k]->getID() << " ";
        }
        cout << endl;
    }
    //Print total comparison
    cout << "It took " << comparison << " comparisons to sort this list." << endl;

}