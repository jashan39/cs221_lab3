// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include <sstream>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	setDate(year, monthStr2Num(month), day);
}

bool CDate::isValidDate(int year, int month, int day){
	// TODO you need to fill in the code here        ********
	// comment out the "return false" below 
	// then check the validity of a year, month, and day
	
	return isValidDay(year, month, day);
	
}

bool CDate::isValidDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// comment out "return false" below
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	return isValidDay(year, monthStr2Num(month), day);
	
}

int CDate::monthStr2Num(std::string month){
	// TODO you need to fill in the code here        ********
	if(month == "January")
		return 1;
	if(month == "February")
		return 2;
	if(month == "March")
		return 3;
	if(month == "April")
		return 4;
	if(month == "May")
		return 5;
	if(month == "June")
		return 6;
	if(month == "July")
		return 7;
	if(month == "August")
		return 8;
	if(month == "September")
		return 9;
	if(month == "October")
		return 10;
	if(month == "November")
		return 11;
	if(month == "December")
		return 12;
	
	else
		return 0;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31) || (year < 0)) return false;

	bool valid = false;
	switch (month) {
		case 1: valid = (day<=31); 			break;
		case 3: valid = (day<=31); 			break;
		case 5: valid = (day<=31);			break;
		case 7: valid = (day<=31); break;
		case 8: valid = (day<=31); break;
		case 10: valid = (day<=31); break;
		case 12: valid = (day<=31); break;
			// TODO you need to fill in the code here        ********
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4: valid = (day<=30); break;
		case 6: valid = (day<=30); break;
		case 9: valid = (day<=30); break;
		case 11: valid = (day<=30); break;
			// TODO you need to fill in the code here        ********
		default:
			// TODO you need to fill in the code here        ********
			valid = false;
			 
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	setDate(year, monthStr2Num(month), day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}


