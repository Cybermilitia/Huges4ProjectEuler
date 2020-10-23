#include "../include/div.hpp"
#include "../include/mult.hpp"
#include "../include/sub.hpp"
#include "../include/add.hpp"


using namespace std;

vector<int> * divide (vector<int> *first, vector<int> *second) {
	
	//vector<int> *result = new vector<int>;
	
	/*Hangisi daha büyük?*/
	vector<int> *bolen = new vector<int>{};
	vector<int> *bolunen = new vector<int>{};
	vector<int> *bolum = new vector<int>{};
	vector<int> *bolunenkesit = new vector<int>{};
	
	int whichgreater = greaterf(first, second);
	
	if(whichgreater == 0){
		bolum->push_back(1);
		return bolum;
	}
	else if(whichgreater ==1){
		for(auto it:*first)
			bolunen->push_back(it);

		for(auto it:*second)
			bolen->push_back(it);
	}
	else if(whichgreater ==2){
		for(auto it:*first)
			bolen->push_back(it);

		for(auto it:*second)
			bolunen->push_back(it);	
	}
	else
			exit(0);
	
	for(auto it: *bolunen){
		bolunenkesit->push_back(it);
		
		int whichgreater = greaterf(bolunenkesit, bolen);
		
		if(whichgreater == 0){
			bolum->push_back(1);
			for(long unsigned int l=0; l< bolen->size(); l++){
				bolunen->pop_back();
			}
			
			/*GOSTERIM*/
			cout << "Bolunenkesit==bolen: ";
			for(auto it6:*bolunenkesit)
				cout << it6;
			cout << endl;
			
			cout << "Bolen: ";
			for(auto it6:*bolen)
				cout << it6;
			cout << endl;
	
			cout << "Bolunen: ";
			for(auto it6:*bolunen)
				cout << it6;
			cout << endl;
			/*GOSTERIM*/
		}
		else if(whichgreater == 1){
			vector<int> *carpan = new vector<int>{};
			vector<int> *carpanT;
			carpan->push_back(1);
			vector <int> * bir = new vector<int>{};
			bir->push_back(1);
			for(;;){
				
									
					/*GOSTERIM*/
					cout << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					
					cout << "Bolunenkesit > bolen ";
					for(auto it6:*bolunenkesit)
						cout << it6;
					cout << endl;
					
					cout << "Bolen: ";
					for(auto it6:*bolen)
						cout << it6;
					cout << endl;

					cout << "Bolunen: ";
					for(auto it6:*bolunen)
						cout << it6;
					cout << endl;
					/*GOSTERIM*/
					
					cout << "Carpan ONCE: ";
					for(auto it6:*carpan)
						cout << it6;
					cout << endl;
					
					reverse(carpan->begin(),carpan->end());
					carpan->pop_back();
					reverse(carpan->begin(),carpan->end());

					cout << "Carpan Ara: ";
					for(auto it6:*carpan)
						cout << it6;
					cout << endl;					
					
				carpanT=add(carpan,bir);
				
				carpan->clear();
				for(auto it10: *carpanT)
					carpan->push_back(it10);
				
				vector<int> *carpim;
				carpim = multiplication(carpan,bolen);
				
					cout << "carpim: ";
					for(auto it6:*carpim)
						cout << it6;
					cout << endl;				
				
				int whichgreater1 = greaterf(bolunenkesit, carpim);
				
				if( whichgreater1 == 0){
					for(auto itb: *carpan)
						bolum->push_back(itb);
					for(long unsigned int m=0; m< bolunenkesit->size(); m++){
						bolunen->pop_back();
					}
					bolunenkesit->clear();
					break;
				}
				
				
				else if(whichgreater1 == 1){
					continue;
				}
				
				
				else if(whichgreater1 == 2){	
					cout << ">2" << endl;

					vector<int> *cell = sub(carpan, bir);
					for(auto it4: *cell)
						bolum->push_back(it4);
					
					for(auto it9: *bolum)
						cout << "bolum: " << it9 << endl;
					
					cout << "Bir cikarttik" << endl;
					
					for(auto it9: *cell)
						cout << "carpan -1: " << it9 << endl;

					for(auto it9: *bolen)
						cout << "bolen: " << it9 << endl;
					
					bolunenkesit->clear();
					vector <int> *cell2 = multiplication(cell, bolen);
					vector <int> * cell3{} /**cell2T{}*/;
					
					for(auto it9: *cell2)
						cout << "Carpim: " << it9 << endl;
					
					for(auto it9: *bolunen)
						cout << "bolunen: " << it9 << endl;
					

					for(long unsigned int o=0; o< cell2->size(); o++)
					{
					    cout << "For: " << bolunen->at(o) << endl;
						cell3->push_back(bolunen->at(o));
						bolunen->pop_back();
					}
					
					for(auto it9: *cell2)
						cout << "Carpim: " << it9 << endl;
					
					cout << "Cikanlari cell3 diye küçük bir vektore yazdik." << endl;

					vector <int> * cell4 = sub(cell3,cell2);					
					vector <int> * bolunenT{};
					for(auto it5: *cell4){
						bolunenT->push_back(it5);
					}					
					
					cout << "Gecici bolunen yarattik." << endl;

					for(auto it5: *bolunen){
						bolunenT->push_back(it5);
					}
					
					bolunen->clear();
					
					cout << "Eski boluneni sildik" << endl;

					
					for(auto it5: *bolunenT)
						bolunen->push_back(it5);
										
					//delete cell2;
					cout << "yeni bolunen: ";
					for(auto it6:*bolunen)
						cout << it6;
					cout << endl;
					break;
				}
			}
			delete carpan;
			delete bir;
		}
		else
			continue;
	}
	
	
	delete bolen;
	delete bolunen;
	delete bolunenkesit;
	
	return bolum;
}