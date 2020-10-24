#include "../include/basics.hpp"


using namespace std;

int main(void)
{
	long p = 199;
//	long q = 98765432100;
	long q = -99999;
	long r = 1234567899;
	long s = 0;
	
	number &sayi1 = *new number(p);

	number &sayi2 = *new number(q);
	
	number &sayi3 = *new number(r);

	number &sayi4 = *new number(s);
		
	cout << "1. sayi: " ;
	sayi1.show();		
	cout << "2. sayi: " ;
	sayi2.show();
	cout << "3. sayi: " ;
	sayi3.show();		
	cout << "4. sayi: " ;
	sayi4.show();
	
	//sayi1.negative();
/*	sayi2.negative();
	-sayi2;
	
	sayi1.show();		
	sayi2.show();

	sayi1=sayi2;
	-sayi1;
	
	sayi1.show();		
	sayi2.show();
	
	if(sayi1 > sayi2)
		cout << "Ilki" << endl;
	
	if(sayi1 >= sayi2)
		cout << "Ilki ya da esit" << endl;
	else
		cout << "Ikincisi" << endl;
	
	if(sayi1 == sayi2)
		cout << "Esit" << endl;		
	

	
	if(!sayi3)
		cout << " Sifir " << endl;*/

	/*number & toplam = sayi1+sayi3;

	cout << "sayi1 + sayi3= " ;
	toplam.show();
	cout << endl;
	
	number & toplam3 = sayi2+sayi1;

	cout << "sayi2 + sayi1= " ;
	toplam3.show();
	cout << endl;

	number & ciklam = sayi1-sayi3;
	cout << "sayi1 - sayi3 = " ;
	ciklam.show();
	cout << endl;

	number & ciklam2 = sayi3-sayi2;
	cout << "sayi3 - sayi2 = " ;
	ciklam2.show();
	cout << endl;

	number & ciklam3 = sayi1-sayi1;
	cout << "sayi1 - sayi1 = " ;
	ciklam3.show();
	cout << endl;

	number & ciklam4 = sayi4-sayi1;
	cout << "sayi4 - sayi1 = " ;
	ciklam4.show();

	number & toplam2 = sayi2+sayi2;
	cout << "sayi2 + sayi2 = " ;
	toplam2.show();*/

/*	delete &toplam2;
	delete &toplam3;
	delete &ciklam;
	delete &ciklam2;
	delete &ciklam3;
	delete &ciklam4;	
	delete &sayi1;
	delete &sayi2;
	delete &sayi3;
	delete &sayi4;
	delete &toplam;*/
//	delete &ciklam;

	number & carpim1 = sayi1*sayi2;
	cout << "sayi1 * sayi2 = " ;
	carpim1.show();
	cout << endl;

	number & carpim2 = sayi2*sayi3;
	cout << "sayi2 * sayi3 = " ;
	carpim2.show();
	cout << endl;


	number & carpim3 = sayi3*sayi4;
	cout << "sayi3 * sayi4 = " ;
	carpim3.show();
	cout << endl;


	number & carpim4 = sayi1*sayi3;
	cout << "sayi1 * sayi3 = " ;
	carpim4.show();
	cout << endl;
	
	delete &carpim1;
	delete &carpim2;
	delete &carpim3;
	delete &carpim4;
	
	return 0;
}
