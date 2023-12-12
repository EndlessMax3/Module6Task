#include "Time.h"

//������ ����, ������, �������
void Time::Set(int hour, int minute, int second)
{
    if (second >= 0 && second <= 59)
        this->_second = second;
    else cout << "Seconds are in wrong range (0 to 59)" << endl;
    if (minute >= 0 && minute <= 59)
        this->_minute = minute;
    else cout << "Minutes are in wrong range (0 to 59)" << endl;
    if (hour >= 0 && hour <= 23)
        this->_hour = hour;
    else cout << "Hours are in wrong range (0 to 23)" << endl;
}

//������� ������ � �������
void Time::Print()
{
    setlocale(LC_ALL, "Russian");
    cout << "�����: " << this->_hour << ':' << this->_minute << ':' << this->_second << endl;
}

//������� ������ � ���������� � �������� ��
void Time::Read()
{
    int second, minute, hour;
    cout << "������� ����: ";
    cin >> hour;
    cout << "������� ������: ";
    cin >> minute;
    cout << "������� �������: ";
    cin >> second;
    Set(hour, minute, second);
}

//������������� ��������=
Time& Time::operator =(const Time& t)
{
    _hour = t._hour;
    _minute = t._minute;
    _second = t._second;
    cout << "operator =(const Time&)" << endl;
    return *this;
}

//�������� �� �������� �������
bool Equal(const Time& t1, const Time& t2)
{
    if ((t1._second == t2._second) && (t1._minute == t2._minute) && (t1._hour == t2._hour)) return 1;
    else return 0;
}

//�������� �����1 ������ �����2
bool Less(const Time& t1, const Time& t2)
{
    if (t1._hour < t2._hour) return 1;
    else if ((t1._hour == t2._hour) && (t1._minute < t2._minute)) return 1;
    else if ((t1._hour == t2._hour) && (t1._minute == t2._minute) && (t1._second < t2._second)) return 1;
    else return 0;
}

//�������� �����1 ������ �����2
bool Grater(const Time& t1, const Time& t2)
{
    if (t1._hour > t2._hour) return 1;
    else if ((t1._hour == t2._hour) && (t1._minute > t2._minute)) return 1;
    else if ((t1._hour == t2._hour) && (t1._minute == t2._minute) && (t1._second > t2._second)) return 1;
    else return 0;
}
// ����� ��������� �������
int Compare(const Time& t1, const Time& t2)
{
    if (Less(t1, t2) == 1) return 0;
    if (Grater(t1, t2) == 1) return 1;
    if (Equal(t1, t2) == 1) return 2;
}

bool operator ==(const Time& t1, const Time& t2)
{
    return (t1.GetSecond() == t2.GetSecond()) && (t1.GetMinute() == t2.GetMinute()) && (t1.GetHour() == t2.GetHour());
}

bool operator <(const Time& t1, const Time& t2)
{
    if (t1.GetHour() < t2.GetHour()) return 1;
    else if ((t1.GetHour() == t2.GetHour()) && (t1.GetMinute() < t2.GetMinute())) return 1;
    else if ((t1.GetHour() == t2.GetHour()) && (t1.GetMinute() == t2.GetMinute()) && (t1.GetSecond() < t2.GetSecond())) return 1;
    else return 0;
}

bool operator >(const Time& t1, const Time& t2)
{
    if (t1.GetHour() > t2.GetHour()) return 1;
    else if ((t1.GetHour() == t2.GetHour()) && (t1.GetMinute() > t2.GetMinute())) return 1;
    else if ((t1.GetHour() == t2.GetHour()) && (t1.GetMinute() == t2.GetMinute()) && (t1.GetSecond() > t2.GetSecond())) return 1;
    else return 0;
}

ostream& operator <<(ostream& s, const Time& t)
{
    s << t.GetHour() << ':' << t.GetMinute() << ':' << t.GetSecond();
    return s;
}

istream& operator >>(istream& s, Time& d)
{
    int hour, minute, second;
    s >> hour;
    s >> minute;
    s >> second;
    d.Set(hour, minute, second);
    return s;
}