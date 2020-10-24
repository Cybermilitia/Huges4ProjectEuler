#ifndef BASICS_H
#define BASICS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <math.h> 
#include <bits/stdc++.h> 
#include <fstream>

using namespace std;

//extern vector <int> modul;

class number {
	public:
	number();
	number (long);
//	number (number *);
	//~number();
	void negative(void);
	void positive(void);
	void show(void);
	int greaterf (vector<int> &, vector<int> &);
	void operator = (const number&); 
	number& operator - (void); 
	int operator ! (void); 
	int operator > (const number&);
	int operator >= (const number&);
	int operator < (const number&);
	int operator <= (const number&);
	int operator == (const number&);
	int operator != (const number&);
	number & operator + (const number&);
	number & operator - (const number&);
	number & operator * (const number&);
	
	private:
	struct _numb{
		char sign;
		vector <int> numv;
	}numb;
};

void test(void);

#endif