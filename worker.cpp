#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;
class Date {
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    Date() : Date(1, 2, 2000) {};
    void print() {
        cout << day << "." << month << "." << year << "\n";
    }
    void setDay(int d) {
        day = d;
    }
    void setMonth(int m) {
        month = m;
    }
    void setYear(int y) {
        year = y;
    }

    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
};

 class Worker {
    char* name;
    char* job;

    int moneys;
    int size;

    Date start;

public:
    explicit Worker(const char* Uname, const char* Ujob, int money, const Date& start) :start{ start } {

        name = new char[strlen(Uname) + 1];
        strcpy(name, Uname);

        job = new char[strlen(Ujob) + 1];
        strcpy(job, Ujob);

        moneys = money;

    }
    Date getStart()const {

        return start;
    }
    void setName(const char* Uname) {
        delete[] name;

        name = new char[strlen(Uname) + 1];
        strcpy(name, Uname);
    }
    void setJob(const char* Ujob) {
        delete[] job;
        job = new char[strlen(Ujob) + 1];
        strcpy(job, Ujob);
    }

    void setMoney(int money) {
        moneys = money;
    }

    void print(const Worker* a, int size, int i) {
        cout << "Имя: " << a[i].name << endl;
        cout << "Должность: " << a[i].job << endl;
        cout << "Дата поступления: "; a[i].getStart().print();
    }

    void sortYear(const Worker* a,int size,int st) {
        cout << "Работники со стажем " << st << "+ :\n";
        for (int i = 0; i < size; i++) {
            if ((2023 - a[i].getStart().getYear()) > st) {
                cout << a[i].name << "\n";
            }
        }
    }
    
    void sortMoney(const Worker* a, int size, int money) {
        cout << "Работники у котороых зп больше " << money << ":\n";
        for (int i = 0; i < size; i++) {
            if (a[i].moneys > money) {
                cout << a[i].name << "\n";
            }
        }
    }

    void sortJob(const Worker* a, int size, const char* Jjob) {
        cout << "Работники с должностью " << Jjob << ":\n";
        for (int i = 0; i < size; i++) {
            if (strstr(a[i].job, Jjob)) {
                 cout << a[i].name << "\n";
            }
        }
    }

    ~Worker() {
        cout << job << " - " << name << " ушёл с работы\n";
        if (name) {
            delete[]name;
        }

        if (job) {
            delete[] job;
        }
    }
};

int main() {

    setlocale(0, "");
    srand(time(NULL));
    //const char* Uname, const char* Ujob,int money,int d,int m,int y
    Worker workers[4] = { Worker{"Вася","Бригадир",30000,{10,2,2008}},
                          Worker{"Серёга","Дворник",20000,{6,3,1998}},
                          Worker{"Данил","Писарь подполковника",40000,{5,4,2012}},
                          Worker{"Александр","Дворник",30000,{8,12,2020}}
    };
    workers->print(workers,4,2);
    cout << "\n\n";

    workers->sortMoney(workers, 4, 20000);
    cout << "\n\n";

    workers->sortJob(workers, 4, "Дворник");
    cout << "\n\n";

    workers->sortYear(workers, 4, 6);
    cout << "\n\n";
}
