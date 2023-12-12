#include "Date.h"

//задать день, месяц и год
void Date::Set(int day, int month, int year) 
{
    if (day >= 1 && day <= 31)
        this->_day = day;
    else cout << "Day are in wrong range (1 to 31)" << endl;
    if (month >= 1 && month <= 12)
        this->_month = month;
    else cout << "Month are in wrong range (1 to 12)" << endl;
    if (year >= 1900 && year <= 2100)
        this->_year = year;
    else cout << "Year are in wrong range (1900 to 2100)" << endl;
}

//вывести данные в консоль
void Date::Print()
{
    setlocale(LC_ALL, "Russian");
    cout << "Дата: " << this->_day << '.' << this->_month << '.' << this->_year << endl;
}

//считать данные с клавиатуры и записать их
void Date::Read()
{
    int day, month, year;
    cout << "Введите день: ";
    cin >> day;
    cout << "Введите месяц: ";
    cin >> month;
    cout << "Введите год: ";
    cin >> year;
    Set(day, month, year);
}

//перегруженный оператор=
Date& Date::operator =(const Date& d)
{
    _day = d._day;
    _month = d._month;
    _year = d._year;
    cout << "operator =(const Date&)" << endl;
    return *this;
}

//проверка на равность дат
bool Equal(const Date& d1, const Date& d2)
{
    if ((d1._day == d2._day) && (d1._month == d2._month) && (d1._year == d2._year)) return 1;
    else return 0;
}

//проверка дата1 меньше дата2
bool Less(const Date& d1, const Date& d2)
{
    if (d1._year < d2._year) return 1;
    else if ((d1._year == d2._year) && (d1._month < d2._month)) return 1;
    else if ((d1._year == d2._year) && (d1._month == d2._month) && (d1._day < d2._day)) return 1;
    else return 0;
}
//проверка дата1 больше дата2
bool Grater(const Date& d1, const Date& d2)
{
    if (d1._year > d2._year) return 1;
    else if ((d1._year == d2._year) && (d1._month > d2._month)) return 1;
    else if ((d1._year == d2._year) && (d1._month == d2._month) && (d1._day > d2._day)) return 1;
    else return 0;
}
//метод сравнения дат
int Compare(const Date& d1, const Date& d2)
{
    if (Less(d1, d2) == 1) return 0;
    if (Grater(d1, d2) == 1) return 1;
    if (Equal(d1, d2) == 1) return 2;
}

bool operator ==(const Date& d1, const Date& d2)
{
    return (d1.GetDay() == d2.GetDay()) && (d1.GetMonth() == d2.GetMonth()) && (d1.GetYear() == d2.GetYear());
}

bool operator <(const Date& d1, const Date& d2)
{
    if (d1.GetYear() < d2.GetYear()) return 1;
    else if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() < d2.GetMonth())) return 1;
    else if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() == d2.GetMonth()) && (d1.GetDay() < d2.GetDay())) return 1;
    else return 0;
}

bool operator >(const Date& d1, const Date& d2)
{
    if (d1.GetYear() > d2.GetYear()) return 1;
    else if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() > d2.GetMonth())) return 1;
    else if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() == d2.GetMonth()) && (d1.GetDay() > d2.GetDay())) return 1;
    else return 0;
}

ostream& operator <<(ostream& s, const Date& d)
{
    s << d.GetDay() << '.' << d.GetMonth() << '.' << d.GetYear();
    return s;
}

istream& operator >>(istream& s, Date& d)
{
    int day, month, year;
    s >> day;
    s >> month;
    s >> year;
    d.Set(day, month, year);
    return s;
}