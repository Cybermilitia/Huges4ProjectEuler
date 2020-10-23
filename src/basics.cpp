#include "../include/basics.hpp"

using namespace std;

/*Default Constructor*/
number::number(){
	numb.numv.push_back(1);
	numb.sign ='+';
}

/*Big number constructor*/
number::number(long n){
	bool negativesign = false;
	if(n < 0){
		n*=-1;
		negativesign = true;
	}
		for(;;){
		int digit = fmod(n,10);
		numb.numv.push_back(digit);
		n = (n - digit)/10;
		if (n == 0)
			break;
	}
	
	reverse(numb.numv.begin(), numb.numv.end());
	numb.sign = '+';
	
	if((numb.numv.size() == 1) && (numb.numv.at(0) == 0))
		numb.sign = ' ';
	
	if (negativesign == true)
		numb.sign = '-';
		
	}

/*Default Constructore by number*/
/*return'de this ile döneceksek, number cinsinden bir class yaratmak için default constructor arıyor.
  number'la yapılan bir default constructor yoksa, en benzeyenine gidiyor ve long'la number arasında 
  problem ortaya çıkıyor.
  EDIT: fonsiyon return değeri olarak "number & fonksiyon" ve return değerinde de "*this" yaparak bu problemi aştık.
https://stackoverflow.com/questions/6919330/return-this-in-c
******************************************
you can't return anything from a void-returning function.

There are three ways to return something which provides access to the current object: by pointer, by reference, and by value.

class myclass {
public:
   // Return by pointer needs const and non-const versions
         myclass* ReturnPointerToCurrentObject()       { return this; }
   const myclass* ReturnPointerToCurrentObject() const { return this; }

   // Return by reference needs const and non-const versions
         myclass& ReturnReferenceToCurrentObject()       { return *this; }
   const myclass& ReturnReferenceToCurrentObject() const { return *this; }

   // Return by value only needs one version.
   myclass ReturnCopyOfCurrentObject() const { return *this; }
};
As indicated, each of the three ways returns the current object in slightly different form. Which one you use depends upon which form you need.
*******************************************

number::number(number *n){
	for (auto it: n->numb.numv)
		this->numb.numv.push_back(it);
	
	this->numb.sign = n->numb.sign;
}*/

int number::greaterf (vector<int> &first, vector<int> &second) {

/*Hangisi daha büyük, hangisini hangisinden cikaracagiz?*/
	if(first.size() == second.size()){
		int j=first.size()-2;
		for(long unsigned int i=0; i <= (first.size()-1) ; i++){
			if(first.at(i) > second.at(i)){
				return 1;
			}
			else if(first.at(i) < second.at(i)){
				return 2;
			}
			else{
				j--;
				continue;
			}				
		}
		if (j == -2){
			return 0;
		}
	}
	else if(first.size() > second.size())
		return 1;
	else
		return 2;	
	
	return -1;
}

/*Negative*/
void number::negative(){

	numb.sign ='-';
	
	if((numb.numv.size() == 1) && (numb.numv.at(0) == 0))
		numb.sign = ' ';
	
	return;
}

/*Positive*/
void number::positive(){
	
	numb.sign ='+';
	
	if((numb.numv.size() == 1) && (numb.numv.at(0) == 0))
		numb.sign = ' ';
	
	return;
}

/*Show*/
void number::show(){
	cout << numb.sign;

	for (auto it: numb.numv)
		cout << it;
	cout << endl;
	return;
}

/* = overloading*/
void number::operator = (const number& second) { 

	this->numb.sign = second.numb.sign;
	
	this->numb.numv.clear();
	
	for (auto it: second.numb.numv)
		this->numb.numv.push_back(it);

	return;
}

/* > overloading*/
int number::operator > (const number& second) { 
       
	/*Hangisi daha büyük, hangisini hangisine böleceğiz?*/
	
	/*Ilk arguman, yani > işaretinin solundaki eleman this-> ile gösterilir. 
	"Bu" objedir. Ama pointerdır.
	İkincisi ise argüman olarak overload fonksiyonuna gelir.*/

	if((this->numb.sign) == ' ' && (second.numb.sign == '-'))
		return 1;
	if((this->numb.sign) == '-' && (second.numb.sign == ' '))
		return 0;

	if((this->numb.sign) == '+' && (second.numb.sign == ' '))
		return 1;
	if((this->numb.sign) == ' ' && (second.numb.sign == '+'))
		return 0;
	
	if((this->numb.sign) == ' ' && (second.numb.sign == ' '))
		return 0;
	
	if((this->numb.sign) == '+' && (second.numb.sign == '-'))
		return 1;
	if((this->numb.sign) == '-' && (second.numb.sign == '+'))
		return 0;
	if((this->numb.sign) == '+' && (second.numb.sign == '+'))
	{
	
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 1;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 0;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 0;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 1;
		else
			return 0;	
		
		return -1;
	}
	
	else {
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 0;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 1;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 0;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 0;
		else
			return 1;	
		
		return -1;
	}
}

/* >= overloading*/
int number::operator >= (const number& second) { 
       
	/*Hangisi daha büyük, hangisini hangisine böleceğiz?*/
	
	/*Ilk arguman, yani > işaretinin solundaki eleman this-> ile gösterilir. 
	"Bu" objedir. Ama pointerdır.
	İkincisi ise argüman olarak overload fonksiyonuna gelir.*/


	if((this->numb.sign) == ' ' && (second.numb.sign == '-'))
		return 1;
	if((this->numb.sign) == '-' && (second.numb.sign == ' '))
		return 0;
	
	if((this->numb.sign) == '+' && (second.numb.sign == ' '))
		return 1;
	if((this->numb.sign) == ' ' && (second.numb.sign == '+'))
		return 0;
		
	if((this->numb.sign) == ' ' && (second.numb.sign == ' '))
		return 1;
		
	if((this->numb.sign) == '+' && (second.numb.sign == '-'))
		return 1;
	if((this->numb.sign) == '-' && (second.numb.sign == '+'))
		return 0;
	if((this->numb.sign) == '+' && (second.numb.sign == '+'))
	{
	
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 1;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 0;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 1;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 1;
		else
			return 0;	
		
		return -1;
	}
	
	else {
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 0;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 1;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 1;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 0;
		else
			return 1;	
		
		return -1;
	}
}

/* < overloading*/
int number::operator < (const number& second) { 
       
	/*Hangisi daha büyük, hangisini hangisine böleceğiz?*/
	
	/*Ilk arguman, yani > işaretinin solundaki eleman this-> ile gösterilir. 
	"Bu" objedir. Ama pointerdır.
	İkincisi ise argüman olarak overload fonksiyonuna gelir.*/

	if((this->numb.sign) == ' ' && (second.numb.sign == '-'))
		return 0;
	if((this->numb.sign) == '-' && (second.numb.sign == ' '))
		return 1;

	if((this->numb.sign) == '+' && (second.numb.sign == ' '))
		return 0;
	if((this->numb.sign) == ' ' && (second.numb.sign == '+'))
		return 1;
	
	if((this->numb.sign) == ' ' && (second.numb.sign == ' '))
		return 0;
	
	if((this->numb.sign) == '+' && (second.numb.sign == '-'))
		return 0;
	if((this->numb.sign) == '-' && (second.numb.sign == '+'))
		return 1;
	if((this->numb.sign) == '+' && (second.numb.sign == '+'))
	{
	
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 0;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 1;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 0;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 0;
		else
			return 1;	
		
		return -1;
	}
	
	else {
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 1;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 0;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 0;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 1;
		else
			return 0;	
		
		return -1;
	}
}

/* <= overloading*/
int number::operator <= (const number& second) { 
       
	/*Hangisi daha büyük, hangisini hangisine böleceğiz?*/
	
	/*Ilk arguman, yani > işaretinin solundaki eleman this-> ile gösterilir. 
	"Bu" objedir. Ama pointerdır.
	İkincisi ise argüman olarak overload fonksiyonuna gelir.*/

	if((this->numb.sign) == ' ' && (second.numb.sign == '-'))
		return 0;
	if((this->numb.sign) == '-' && (second.numb.sign == ' '))
		return 1;

	if((this->numb.sign) == '+' && (second.numb.sign == ' '))
		return 0;
	if((this->numb.sign) == ' ' && (second.numb.sign == '+'))
		return 1;
	
	if((this->numb.sign) == ' ' && (second.numb.sign == ' '))
		return 0;
	
	if((this->numb.sign) == '+' && (second.numb.sign == '-'))
		return 0;
	if((this->numb.sign) == '-' && (second.numb.sign == '+'))
		return 1;
	if((this->numb.sign) == '+' && (second.numb.sign == '+'))
	{
	
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 0;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 1;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 1;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 0;
		else
			return 1;	
		
		return -1;
	}
	
	else {
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 1;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 0;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 1;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 1;
		else
			return 0;	
		
		return -1;
	}
}

/*== overloading*/
int number::operator == (const number& second) { 

	if((this->numb.sign) == ' ' && (second.numb.sign == '-'))
		return 0;
	if((this->numb.sign) == '-' && (second.numb.sign == ' '))
		return 0;
	
	if((this->numb.sign) == '+' && (second.numb.sign == ' '))
		return 0;
	if((this->numb.sign) == ' ' && (second.numb.sign == '+'))
		return 0;
		
	if((this->numb.sign) == ' ' && (second.numb.sign == ' '))
		return 1;
		
	if((this->numb.sign) == '+' && (second.numb.sign == '-'))
		return 0;
	if((this->numb.sign) == '-' && (second.numb.sign == '+'))
		return 0;

	if((this->numb.sign) == '+' && (second.numb.sign == '+'))
	{
	
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 0;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 0;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 1;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 0;
		else
			return 0;	
		
		return -1;
	}
	
	else {
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 0;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 0;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 1;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 0;
		else
			return 0;	
		
		return -1;
	}
}

/*!= overloading*/
int number::operator != (const number& second) { 

	if((this->numb.sign) == ' ' && (second.numb.sign == '-'))
		return 1;
	if((this->numb.sign) == '-' && (second.numb.sign == ' '))
		return 1;
	
	if((this->numb.sign) == '+' && (second.numb.sign == ' '))
		return 1;
	if((this->numb.sign) == ' ' && (second.numb.sign == '+'))
		return 1;
		
	if((this->numb.sign) == ' ' && (second.numb.sign == ' '))
		return 0;
		
	if((this->numb.sign) == '+' && (second.numb.sign == '-'))
		return 1;
	if((this->numb.sign) == '-' && (second.numb.sign == '+'))
		return 1;

	if((this->numb.sign) == '+' && (second.numb.sign == '+'))
	{
	
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 1;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 1;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 0;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 1;
		else
			return 1;	
		
		return -1;
	}
	
	else {
		if(this->numb.numv.size() == second.numb.numv.size()){
			int j=this->numb.numv.size()-2;
			for(long unsigned int i=0; i <= (this->numb.numv.size()-1) ; i++){
				if(this->numb.numv.at(i) > second.numb.numv.at(i)){
					return 1;
				}
				else if(this->numb.numv.at(i) < second.numb.numv.at(i)){
					return 1;
				}
				else{
					j--;
					continue;
				}				
			}
			if (j == -2){
				return 0;
			}
		}
		else if(this->numb.numv.size() > second.numb.numv.size())
			return 1;
		else
			return 1;	
		
		return -1;
	}
}

/* - overloading*/
number & number::operator - (void){
	if (this->numb.sign == '-')
		this->numb.sign = '+';
	else if (this->numb.sign == '+')
		this->numb.sign = '-';
	
	return *this;
}

/* ! overloading*/
int number::operator ! (void){
	if (this->numb.sign == ' ')
		return 1;
	return 0;
}

/* a+b overloading*/
number & number::operator + (const number& n){
	number & first = *new number();
	first.numb.numv.clear();
	
	for(auto it:this->numb.numv)
		first.numb.numv.push_back(it);
	
	first.numb.sign = this->numb.sign;
	
	number & second = *new number();
	second.numb.numv.clear();
	
	for(auto it:n.numb.numv)
		second.numb.numv.push_back(it);
	
	second.numb.sign = n.numb.sign;	
	
	if((first.numb.sign) == '+' && (second.numb.sign == '-')){
		number &result = (first - (-second));
		delete &first;
		delete &second;
		return result;
	}
	if((first.numb.sign) == '-' && (second.numb.sign == '+')){
		number &result = (second - -first);
		delete &first;
		delete &second;
		return result;
	}
	if((first.numb.sign) == '-' && (second.numb.sign == '-')){
		number &result = -(-first + -second);
		delete &first;
		delete &second;
		return result;
	}

	long unsigned int size=0;
	int sum=0, elde = 0, cell=0;
	vector<int> & toplam = *new vector<int>;
	vector<int> & birinci = *new vector<int>;
	vector<int> & ikinci = *new vector<int>;
	number &toplamnumber = *new number();
	for(auto it: first.numb.numv)
		birinci.push_back(it);

	for(auto it: second.numb.numv)
		ikinci.push_back(it);
	
	if (birinci.size() > ikinci.size()){
		size= birinci.size();
	}
	else{
		size= ikinci.size();
	}

	reverse(birinci.begin(), birinci.end());
	reverse(ikinci.begin(), ikinci.end());
	
	/*İki vektörün boyutlarını eşitle*/
	for(long unsigned int i= birinci.size(); i<size; i ++)
		birinci.push_back(0);
	
	for(long unsigned int i= ikinci.size(); i<size; i ++)
		ikinci.push_back(0);
	
	for(long unsigned int i = 0; i < size; i++){
		sum = birinci.at(i) + ikinci.at(i) + elde;
		cell = sum%10;
		toplam.push_back(cell);
		//cout << "Birinci: " << birinci.at(i) << " Ikinci: "<< ikinci.at(i) << " Elde: " << elde << " Toplam: "<< sum << " Cell: " << cell << endl;
		if((sum - cell)/10){
				elde = 1;
		}
		else{
			elde = 0;
		}
	}
	if(elde)
		toplam.push_back(1);
	
	reverse(toplam.begin(), toplam.end());

	toplamnumber.numb.numv.clear();
	
	for(auto it: toplam)
		toplamnumber.numb.numv.push_back(it);
	
	if((toplamnumber.numb.numv.size() == 1) && (toplamnumber.numb.numv.at(0) == 0))
		toplamnumber.numb.sign = ' ';
	else
		toplamnumber.numb.sign = '+';
	
	delete &birinci;
	delete &ikinci;
	delete &toplam;	
	delete &first;
	delete &second;
	return toplamnumber;
	
}

/* a-b overloading*/
number & number::operator - (const number& n){

	number & first = *new number();
	first.numb.numv.clear();
	
	for(auto it:this->numb.numv)
		first.numb.numv.push_back(it);
	
	first.numb.sign = this->numb.sign;
	
	number & second = *new number();
	second.numb.numv.clear();
	
	for(auto it:n.numb.numv)
		second.numb.numv.push_back(it);
	
	second.numb.sign = n.numb.sign;	

	if((first.numb.sign) == '+' && (second.numb.sign == '-')){
		number &result = first + -second;
		delete &first;
		delete &second;
		return result;
	}
	if((first.numb.sign) == '-' && (second.numb.sign == '+')){
		number &result = -(second + -first);
		delete &first;
		delete &second;
		return result;
	}
	if((first.numb.sign) == '-' && (second.numb.sign == '-')){
		number &result = (-second - -first);
		delete &first;
		delete &second;
		return result;
	}
	
	long unsigned int size=0;
	int elde = 0, cell=0, ilk = 0, iki = 0;
	vector<int> & birinci = *new vector<int>;
	vector<int> & ikinci = *new vector<int>;
	number &sonuc = *new number();
	sonuc.numb.numv.clear();
	number &toplamnumber = *new number();
	vector<int> &firstly = first.numb.numv;
	vector<int> &secondly = second.numb.numv;
	int whichgreater = greaterf(firstly,secondly);
	/*Eger ikisi esitse 0 don*/
	if(whichgreater == 0){
		sonuc.numb.numv.push_back(0);
		toplamnumber.numb.numv.clear();
		for(auto it: sonuc.numb.numv)
			toplamnumber.numb.numv.push_back(it);

		toplamnumber.numb.sign = ' ';
		delete &birinci;
		delete &ikinci;
		delete &sonuc;	
		delete &first;
		delete &second;
		return toplamnumber;
	}
	/*Eger ilki buyukse normal cikarma islemi yap.*/
	else if(whichgreater == 1){
		for(auto it: first.numb.numv)
			birinci.push_back(it);

		for(auto it: second.numb.numv)
			ikinci.push_back(it);
		toplamnumber.numb.sign = '+';
	}
	/*Eger ikincisi buyukse negatif sonuc.*/
	else if(whichgreater == 2){
		for(auto it: second.numb.numv)
			birinci.push_back(it);

		for(auto it: first.numb.numv)
			ikinci.push_back(it);
		toplamnumber.numb.sign = '-';
	}
	else
		exit(0);

	/*İki vektörün boyutlarını eşitle*/
	if (birinci.size() > ikinci.size()){
		size= birinci.size();
	}
	else{
		size= ikinci.size();
	}

	reverse(birinci.begin(), birinci.end());
	reverse(ikinci.begin(), ikinci.end());
	
	for(long unsigned int i= birinci.size(); i<size; i ++)
		birinci.push_back(0);
	
	for(long unsigned int i= ikinci.size(); i<size; i ++)
		ikinci.push_back(0);
	
	/*Cikarma islemi*/

	for(long unsigned int i = 0; i < size; i++){
			ilk = birinci.at(i) + elde;
			iki = ikinci.at(i);
						
			if(ilk < iki){
				cell = (ilk+ 10 - iki);
				elde = -1;
			}
			else if (ilk > iki){
				cell = ilk - iki;
				elde = 0;
			}
			else{
				cell = 0;
				elde = 0;
			}
			sonuc.numb.numv.push_back(cell);
	}

	
	/*Bastaki sifirlari temizlemek lazım*/
	for(;sonuc.numb.numv.back() == 0;)
		sonuc.numb.numv.pop_back();
	
	reverse(sonuc.numb.numv.begin(), sonuc.numb.numv.end());

	toplamnumber.numb.numv.clear();
	
	for(auto it: sonuc.numb.numv)
		toplamnumber.numb.numv.push_back(it);
	
	delete &birinci;
	delete &ikinci;
	delete &sonuc;	
	delete &first;
	delete &second;
	return toplamnumber;
	
}