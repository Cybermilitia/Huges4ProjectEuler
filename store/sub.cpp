#include "../include/sub.hpp"

using namespace std;

vector<int> * sub (vector <int> * first, vector <int> * second){
	
	long unsigned int size=0;
	int elde = 0, cell=0;
	vector<int> * sonuc = new vector<int>;
	vector<int> * birinci = new vector<int>;
	vector<int> * ikinci = new vector<int>;
	
	for(auto it:*first)
		birinci->push_back(it);

	for(auto it:*second)
		ikinci->push_back(it);
	
	int whichgreater = greaterf(birinci, ikinci);
	if(whichgreater == 0){
		sonuc->push_back(0);
		return sonuc;
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
	
	cout << endl;*/
	
	/*Ters çevir ki sonuca kolay olsun.*/	
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
	
	cout << endl;*/
	int ilk, iki;
	if(whichgreater == 1){
		for(long unsigned int i = 0; i <= size; i++){
			ilk = birinci->at(i) + elde;
			iki = ikinci->at(i);
			
			//cout << ilk << " - " << iki << " - " << elde << " = " << endl;
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
			
			sonuc->push_back(cell);
			//cout << "Cell: " << cell << endl;
		}
	}
		
	if(whichgreater == 2){
		for(long unsigned int i = 0; i <= size; i++){
			ilk = ikinci->at(i) + elde;
			iki = birinci->at(i);
			
			//cout << ilk << " - " << iki << " - " << elde << " = " << endl;
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
			
			sonuc->push_back(cell);
			//cout << "Cell: " << cell << endl;
		}
		sonuc->pop_back();
		sonuc->push_back(-1);
	}
	
	reverse(sonuc->begin(), sonuc->end());
	
	delete birinci;
	delete ikinci;
	
	return sonuc;	
}