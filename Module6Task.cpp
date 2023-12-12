#include <iostream>
#include <fstream>
#include <iomanip>
#include "Date.h"
#include "Time.h"
using namespace std;

const char* fname = "DateTime.txt";

int main()
{ 
    setlocale(LC_ALL, "Russian");
    /*
    //Module1
    Date* d1 = new Date(11, 12, 2023); // создаем объект даты с перегруженным конструктором по-умолчанию
    Time* t1 = new Time(19, 10, 25); // создаем объект времени с перегруженным конструктором по-умолчанию
    Date* d2 = new Date; // создаем объект даты с конструктором по-умолчанию
    Time* t2 = new Time; // создаем объект времени с конструктором по-умолчанию
    d1->Print();
    t1->Print();
    d2->Set(15, 11, 2014);
    t2->Set(15, 42, 25);
    d1->Read();
    t1->Read();
    d1->Print();
    d2->Print();
    t1->Print();
    t2->Print();
    std::cout << Compare(*t1, *t2) << std::endl;
    std::cout << Compare(*d1, *d2) << std::endl;

    //Module3 Date Constructors/Destructors
    Date d3(3);
    d3.Print();

    Date(14, 5, 2020).Print();

    Date d4 = d3;
    d4.Print();
    d3.Print();

    d1 = d2;
    d1->Print();
    d2->Print();

    d4.~Date();

    //Module3 Time Constructors/Destructors
    Time t3(3);
    t3.Print();

    Time(14, 15, 33).Print();

    Time t4 = t3;
    t4.Print();
    t3.Print();

    t1 = t2;
    t1->Print();
    t2->Print();

    t4.~Time();
    */

    //Module5 Operators overloading
    Date d5;
    cout << "Введите дату (дд/мм/гггг) : ";
    cin >> d5;
    Date d6 = d5;
    if (d6 == d5)
        cout << d6 << " = " << d5 << endl;
    else
        cout << d6 << " != " << d5 << endl;

    cout << "Введите дату (дд/мм/гггг) : ";
    cin >> d6;
    if (d6 < d5)
        cout << d6 << " < " << d5 << endl;
    else if (d6 > d5)
        cout << d6 << " > " << d5 << endl;
    else
        cout << d6 << " = " << d5 << endl;


    Time t5;
    cout << "Введите время (чч/мм/сс) : ";
    cin >> t5;
    Time t6 = t5;
    if (t6 == t5)
        cout << t6 << " = " << t5 << endl;
    else
        cout << t6 << " != " << t5 << endl;

    cout << "Введите время (чч/мм/сс) : ";
    cin >> t6;
    if (t6 < t5)
        cout << t6 << " < " << t5 << endl;
    else if (t6 > t5)
        cout << t6 << " > " << t5 << endl;
    else
        cout << t6 << " = " << t5 << endl;


    //Module6 File I/O Streams
    ofstream w(fname, ios::app); //поток записи в файл
    w.seekp(0, ios::end);
    w << t5 << setw(30) << d5 << endl;
    w << t6 << setw(30) << d6 << endl;
    w.close();

    ifstream r(fname, ios::in); //поток чтения из файла
    char date[100];
    char time[100];
    while (!r.eof())
    {
        r >> time >> date;
        if(time[0] != NULL)
            cout << "Date: " << setw(30) << left << date << "Time: " << time << endl;
    }
    r.close();

    //delete d1, d2, t1, t2; //очищаем память
}
