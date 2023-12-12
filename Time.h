#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;
//предварительное объявление класса и методов сравнения
class Time;
bool Equal(const Time& t1, const Time& t2);
bool Less(const Time& t1, const Time& t2);
bool Grater(const Time& t1, const Time& t2);
int Compare(const Time& t1, const Time& t2);

//класс времени
class Time {

private:
	int _second;
	int _minute;
	int _hour;

public:
	void Set(int hour, int minute, int second);
	void Print();
	void Read();

	int GetSecond() const { return _second; }
	int GetMinute() const { return _minute; }
	int GetHour() const { return _hour; }

	//конструктор по-умолчанию
	Time() : Time(0, 0, 0)
	{
		cout << "constructor Time()" << endl;
	}

	Time(int hour, int minute, int second)
		: _hour(hour), _minute(minute), _second(second)
	{
		cout << "constructor Time(int,int,int)" << endl;
	}

	//copy constructor
	Time(const Time& t) : Time(t._hour, t._minute, t._second)
	{
		cout << "construcor Time(const Time&)" << endl;
	}

	//conversion constructor
	explicit Time(int k) : Time(k, k, k)
	{
		cout << "constructor Time(int)" << endl;
	}

	//destructor
	~Time()
	{
		cout << "~Time()" << endl;
	}

	//operator =
	Time& operator =(const Time& d);

	bool Equal(const Time& t1) const
	{
		return ::Equal(*this, t1);
	}

	bool Equal() const
	{
		Time t(1, 1, 2000);
		return ::Equal(*this, t);
	}

	friend bool Equal(const Time& t1, const Time& t2);

	bool Less(const Time& t1) const
	{
		return ::Less(*this, t1);
	}

	bool Less() const
	{
		Time t(1, 1, 2000);
		return ::Less(*this, t);
	}

	friend bool Less(const Time& t1, const Time& t2);

	bool Grater(const Time& t1) const
	{
		return ::Grater(*this, t1);
	}

	bool Grater() const
	{
		Time t(1, 1, 2000);
		return ::Grater(*this, t);
	}

	friend bool Grater(const Time& t1, const Time& d2);

	int Compare(const Time& t1) const
	{
		return ::Compare(*this, t1);
	}

	int Compare() const
	{
		Time t(1, 1, 2000);
		return ::Compare(*this, t);
	}

	friend int Compare(const Time& t1, const Time& d2);
};

bool operator ==(const Time& t1, const Time& t2);
bool operator <(const Time& d1, const Time& t2);
bool operator >(const Time& d1, const Time& t2);
ostream& operator <<(ostream& s, const Time& t);
istream& operator >>(istream& s, Time& t);

