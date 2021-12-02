/**
  * @File:     date.h
  * @Author:   D. Ginhac (dginhac@u-bourgogne.fr)
  * @Date:     Fall 2021
  * @Course:   C++ Programming / Esirem 3A Informatique Electronique Robotique
  * @Summary:  Methods - Helpers functions
  */



#ifndef DATE_H
#define DATE_H
#include <iostream>
class Date {
public:
   Date(int month=1, int day=1, int year=2020);
   int month() const;
   int day() const;
   int year() const;
   void updateMonth(int month);
   void updateDay(int day);
   void updateYear(int year);
   void next();
   void back();
private:
   int _month;
   int _day;
   int _year;
   
};

bool isDate(int month, int day, int year);
int getDaysInMonth(int month);
int dayOfYear(Date d);
std::string toString(Date d);

   bool operator == (const Date&, const Date&); // comparison operators
   bool operator != (const Date&, const Date&);
   bool operator < (const Date&, const Date&);
   bool operator > (const Date&, const Date&);
   bool operator <= (const Date&, const Date&);
   bool operator >= (const Date&, const Date&);

   Date operator + (const Date& date, const int days); // date + integer
   Date operator + (const int days, const Date& date); // integer + date
   Date operator - (const Date& date, const int days); // date - integer

   Date operator ++ (Date& date); // prefix increment: ++date
   Date operator -- (Date& date); // prefix decrement: --date
   Date operator ++ (Date& date, int); // use int paramater for postfix increment: date++
   Date operator -- (Date& date, int); // use int paramater for postfix decrement: date--
   std::ostream& operator<<(std::ostream& os, const Date& date);
#endif

