#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    string id, name;
    double salary;
public:
    Employee(string i, string n, double s) {
        id = i; name = n; salary = s;
    }
    string getId() { return id; }
    virtual double calculateSalary() = 0;
    virtual void display() = 0;
};
class Manager : public Employee {
public:
    Manager(string i, string n, double s) : Employee(i,n,s) {}
double calculateSalary() {
        double bonus = (salary > 50000) ? 5000 : 0;
        return salary + salary * 0.20 + bonus;
}
void display() {
        cout << name << " (Manager) - Salary: "
             << calculateSalary() << endl;
}
};
class Developer : public Employee {
    int experience;
public:
    Developer(string i, string n, double s, int e) : Employee(i,n,s) {
        experience = e;
    }
 double calculateSalary() {
        double rate = 0.10 + 0.02 * experience;
        if (rate > 0.15) rate = 0.15;
        return salary + salary * rate;
    }

    void display() {
        cout << name << " (Developer) - Salary: "
             << calculateSalary() << endl;
    }
};

int main() {
    Employee* e[30];
    int count = 0, choice;

    do {
        cout << "\n1.Add  2.Salary Slip  3.Display All  4.Total  5.Exit\n";
        cin >> choice;

        if (choice == 1) {
            int type;
            string id, name;
            double salary;

            cout << "Type (1-Manager, 2-Developer): ";
            cin >> type;
            cout << "ID Name Salary: ";
            cin >> id >> name >> salary;

            if (type == 1)
                e[count++] = new Manager(id,name,salary);
            else if (type == 2) {
                int exp;
                cout << "Experience: ";
                cin >> exp;
                e[count++] = new Developer(id,name,salary,exp);
            }
        }
        else if (choice == 2) {
            string id;
            cout << "Enter ID: ";
            cin >> id;
            for (int i=0; i<count; i++)
                if (e[i]->getId() == id) e[i]->display();
        }
        else if (choice == 3) {
            for (int i=0; i<count; i++) e[i]->display();
        }
        else if (choice == 4) {
            double total = 0;
            for (int i=0; i<count; i++)
                total += e[i]->calculateSalary();
            cout << "Total Payroll: " << total << endl;
        }
    } while (choice != 5);

    for (int i=0; i<count; i++) delete e[i];
    return 0;
}
