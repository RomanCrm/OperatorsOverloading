//	—оздайте класс Date, который будет содержать информацию о дате(день, мес€ц, год).
//	— помощью механизма перегрузки операторов, определите операцию разности двух дат(результат в виде количества дней между датами),
//	а также операцию увеличени€ даты на определенное количество дней.


#include<iostream>
using namespace std;

class Date
{
private:

	int year;
	int month;
	int day;

	int res;

public:

	Date();
	Date(int year, int month, int day);
	~Date();

	int GetYear()
	{
		return year;
	}
	int GetMonth()
	{
		return month;
	}
	int GetDay()
	{
		return day;
	}

	int GetRes()
	{
		return res;
	}

	void SetYear()
	{
		this->year = year;
	}
	void SetMonth()
	{
		this->month = month;
	}
	void SetDay()
	{
		this->day = day;
	}

	void SetRes()
	{
		this->res = res;
	}

	Date operator-(const Date &n)
	{
		Date tmp;
		tmp.year = year - n.year;
		return tmp;
	}
	
	void SetEnter(int year, int month, int day)
	{
		int year, month, day;

		cout << "Enter dates: \n" << endl;
		cin >> year >> month >> day;
		for (int i = 0; i < month; i++)
		{
			if ((year / 4 == 0 && year % 100 == 0) || (year / 400 == 0)) // высокосный
			{
				year = 366;
				month = 29 - month;
			}
			else
			{
				year = 356;
			}
			if (month == 1 && month == 3 && month == 5 && month == 7 && month == 8 && month == 10 && month == 12)
			{
				month = 31-month;
			}
			else if (month == 4 && month == 6 && month == 9 && month == 11)
			{
				month = 30-month;
			}
			else if (month == 2)
			{
				month = 28-month;
			}
			else
			{
				cout << "ERROR" << endl;
			}
			res = day + month + year;
		}
	}

	void Show()
	{
		cout << "Year - " << year << ", month - " << month << ", day - " << day << endl;
	}

};

Date::Date()
{}
Date::Date(int year, int month, int day)
{
	year = year;
	month = month;
	day = day;
}
Date::~Date()
{}

void main()
{
	setlocale(LC_ALL,"rus");

	int year, month, day;
	int year1, month1, day1;

	cout << "Enter dates: \n" << endl;
	cin >> year >> month >> day;
	cin >> year1 >> month1 >> day1;

	Date A;
	A.SetEnter(year, month, day);
	A.Show();

	Date B;
	B.SetEnter(year, month, day);
	B.Show(); 

	Date C = B - A;
	C.Show();

	system("pause");
}