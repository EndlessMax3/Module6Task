#pragma once
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;
//предварительное объ€вление класса и методов сравнени€
class Date;
bool Equal(const Date& d1, const Date& d2); 
bool Less(const Date& d1, const Date& d2);
bool Grater(const Date& d1, const Date& d2);
int Compare(const Date& d1, const Date& d2);

//класс ƒаты
class Date {
	
private:
	int _day;
	int _month;
	int _year;

public:
	void Set(int day, int month, int year);
	void Print();
	void Read();

	int GetDay() const { return _day; }
	int GetMonth() const { return _month; }
	int GetYear() const { return _year; }

	//конструктор по-умолчанию
	Date() : Date(1, 1, 2000)
	{
		cout << "constructor Date()" << endl;
	}

	Date(int day, int month, int year)
		: _day(day), _month(month), _year(year)
	{
		cout << "constructor Date(int,int,int)" << endl;
	}

	//copy constructor
	Date(const Date& d) : Date(d._day, d._month, d._year)
	{
		cout << "construcor Date(const Date&)" << endl;
	}

	//conversion constructor
	explicit Date(int k) : Date(k, k, k+2000)
	{
		cout << "constructor Date(int)" << endl;
	}

	//destructor
	~Date()
	{
		cout << "~Date()" << endl;
	}

	//operator =
	Date& operator =(const Date& d);

	bool Equal(const Date& d1) const
	{
		return ::Equal(*this, d1);
	}

	bool Equal() const
	{
		Date d;
		return ::Equal(*this, d);
	}

	friend bool Equal(const Date& d1, const Date& d2);

	bool Less(const Date& d1) const
	{
		return ::Less(*this, d1);
	}

	bool Less() const
	{
		Date d;
		return ::Less(*this, d);
	}

	friend bool Less(const Date& d1, const Date& d2);

	bool Grater(const Date& d1) const
	{
		return ::Grater(*this, d1);
	}

	bool Grater() const
	{
		Date d(1, 1, 2000);
		return ::Grater(*this, d);
	}

	friend bool Grater(const Date& d1, const Date& d2);

	int Compare() const
	{
		Date d(1, 1, 2000);
		return ::Compare(*this, d);
	}

	friend int Compare(const Date& d1, const Date& d2);
};

bool operator ==(const Date& d1, const Date& d2);
bool operator <(const Date& d1, const Date& d2);
bool operator >(const Date& d1, const Date& d2);
ostream& operator <<(ostream& s, const Date& d);
istream& operator >>(istream& s, Date& d);
