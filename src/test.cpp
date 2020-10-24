#include "../include/basics.hpp"


using namespace std;

void test(void)
{
	long a = 0;
	long b = 1;
	long c = 1234567899;
	long d = 9999999999;
	long e = 123;
	long f = 98765432100;
	long g = 12345678900;
	long h = -1;
	long i = -123;
	long j = -1234567899;
	long k = -9999999999;
	long l = -98765432100;
	long m = -12345678900;
	
	number &sayi1 = *new number(a); //  0 
	number &sayi2 = *new number(b); //  1 
	number &sayi3 = *new number(c); //  1234567899 
	number &sayi4 = *new number(d); //  9999999999 
	number &sayi5 = *new number(e); //  123 
	number &sayi6 = *new number(f); //  98765432100 
	number &sayi7 = *new number(g); //  12345678900 
	number &sayi8 = *new number(h); //  -1 
	number &sayi9 = *new number(i); //  -123 
	number &sayi10 = *new number(j); //  -1234567899 
	number &sayi11 = *new number(k); //  -9999999999 
	number &sayi12 = *new number(l); //  -98765432100 
	number &sayi13 = *new number(m); //  -12345678900 

	/*Results*/

	cout << "1. sayi: " ;
	sayi1.show();		
	cout << "2. sayi: " ;
	sayi2.show();
	cout << "3. sayi: " ;
	sayi3.show();		
	cout << "4. sayi: " ;
	sayi4.show();
	cout << "5. sayi: " ;
	sayi5.show();		
	cout << "6. sayi: " ;
	sayi6.show();
	cout << "7. sayi: " ;
	sayi7.show();		
	cout << "8. sayi: " ;
	sayi8.show();
	cout << "9. sayi: " ;
	sayi9.show();		
	cout << "10. sayi: " ;
	sayi10.show();
	cout << "11. sayi: " ;
	sayi11.show();		
	cout << "12. sayi: " ;
	sayi12.show();
	cout << "13. sayi: " ;
	sayi13.show();
	
	cout << endl;	
	
	/*Adding test suit*/

	if(sayi1+sayi1 != sayi1){
		cout << "EROOR: a+a != a" << endl;
	}

	if(sayi1+sayi2 != sayi2){
		cout << "EROOR: a+b != b" << endl;
	}

	if(sayi3+sayi2 != number(1234567900)){
		cout << "EROOR: c+b != number(1234567900)" << endl;
	}

	if(sayi4+sayi2 != number(10000000000)){
		cout << "EROOR: d+b != number(10000000000)" << endl;
	}

	if(sayi4+sayi3 != number(11234567898)){
		cout << "EROOR: d+c != number(11,234,567,898)" << endl;
	}

	if(sayi6+sayi7 != number(111111111000)){
		cout << "EROOR: f+g != number(111111111000)" << endl;
	}

	if(sayi1+sayi8 != sayi8){
		cout << "EROOR: a+h != h" << endl;
	}

	if(sayi8+sayi9 != number(-124)){
		cout << "EROOR: h+i != number(-124)" << endl;
	}

	if(sayi9+sayi2 != number(-122)){
		cout << "EROOR: a+a != a" << endl;
	}

	if(sayi10+sayi3 != a){
		cout << "EROOR: j+c != a" << endl;
	}

	if(sayi11+sayi3 != number(-8765432100)){
		cout << "EROOR: k+c != number(-8765432100)" << endl;
	}

	if(sayi11+sayi8 != number(-10000000000) ){
		cout << "EROOR: k+h != number(-10000000000)" << endl;
	}

	if(sayi12+sayi13 != number(-111111111000)){
		cout << "EROOR: l+m != number(-111111111000)" << endl;
	}

	
	delete &sayi1;
	delete &sayi2;
	delete &sayi3;
	delete &sayi4;
	delete &sayi5;
	delete &sayi6;
	delete &sayi7;
	delete &sayi8;
	delete &sayi9;
	delete &sayi10;
	delete &sayi11;
	delete &sayi12;
	delete &sayi13;

	
	return;
}
