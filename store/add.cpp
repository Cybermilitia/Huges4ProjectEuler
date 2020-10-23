#include "../include/add.hpp"

using namespace std;

vector<int> * add (vector <int> * first, vector <int> * second){
	
	long unsigned int size=0;
	int sum=0, elde = 0, cell=0;
	vector<int> * toplam = new vector<int>;
	vector<int> * birinci = new vector<int>;
	vector<int> * ikinci = new vector<int>;
	
	for(auto it:*first)
		birinci->push_back(it);

	for(auto it:*second)
		ikinci->push_back(it);
	
	int whichgreater = greaterf(birinci, ikinci);
	if(whichgreater == 0){
		size = birinci->size();
	}
	else if(whichgreater ==1){
		size = birinci->size();
	}
	else if(whichgreater ==2){
		size = ikinci->size();
	}
	else{
			exit(0);
	}
	
/*	for(auto it: *birinci)
		cout << it;
	
	cout << endl;
	
	for(auto it: *ikinci)
		cout << it;
	
	cout << endl;
*/	
	/*Ters çevir ki toplama kolay olsun.*/	
	reverse(birinci->begin(), birinci->end());
	reverse(ikinci->begin(), ikinci->end());
	
	/*İki vektörün boyutlarını eşitle*/
	for(long unsigned int i= birinci->size(); i<=size; i ++)
		birinci->push_back(0);
	
	for(long unsigned int i= ikinci->size(); i<=size; i ++)
		ikinci->push_back(0);
	
/*	cout << "Boyutlardan sonra" << endl;
	for(auto it: *birinci)
		cout << it;
	
	cout << endl;
	
	for(auto it: *ikinci)
		cout << it;
	
	cout << endl;
	
*/	

	
	
	
	for(long unsigned int i = 0; i <= size; i++){
		//cout << birinci->at(i) << " + " << ikinci->at(i) << " + " << elde << " = " << endl;
		sum = birinci->at(i) + ikinci->at(i) + elde;
		cell = sum%10;
		toplam->push_back(cell);
		//cout << "Cell: " << cell << endl;
		if((sum - cell)/10){
				elde = 1;
		}
		else{
			elde = 0;
		}
	}
	if(elde)
		toplam->push_back(1);
	
	cout << "TOPLAMA: " <<  endl;
		for(auto it: *toplam)
		cout << it;
	
	cout << endl;
	
	reverse(toplam->begin(), toplam->end());
	toplam->pop_back();
	
	delete birinci;
	delete ikinci;
	
	return toplam;	
}