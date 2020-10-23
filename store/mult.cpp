#include "../include/mult.hpp"

using namespace std;

vector<int> * multiplication (vector<int> * number1, vector<int> * number2) {
	
	vector <int> result{};
	/*vector <int> *numera = new vector<int>;
	vector <int> *numerb = new vector<int>;*/
	
	/*sumresult->bir şey olarak kullanabilmek için heapten alıyorum.*/
	vector <int> * sumresult = new vector<int>;
			
	/*Most critical point is here.*/
	vector <vector <int>> results;
	
	int cell=0, remain=0, last=0;
	int j=0, sum=0, sumcell = 0, sumremain = 0;
	
	reverse(number1->begin(),number1->end());
	reverse(number2->begin(),number2->end());
			
	//cout << "Multiplication" << endl;
	/*Çarpımlar yapılır ve ham sonuçları iki boyutlu bir matrise yazılır. 
	Yazılırken çarpımda ortaya çıkabilecek ikinci basamak bir sonraki çarpıma eklenir.
	1203x456 = ((6.3-elde var,6.0,6.2-elde var,6.1),(5.3-elde var,5.0,5.2-elde var,5.1),(4.3-elde var,4.0,4.2,4.1))
	                     1203
						  456
						x
						------
						 7218
                        60150
                       481200
                      +-------
                       548568					  
	*/
	int count=0;
	int zero=0;
	for(auto it1: *number1){
		/*İkincisinden itibaren her bir adımda bir sıfır eklenir.
		Böylece her çarpımdan sonra bir sola kayma sağlanır*/
		/*Sola kaydırma bloğu - Başladı.*/	
		for(int check=zero;check >0;check --)
		{
			result.push_back(0);
		}
			zero++;
		/*Sola kaydırma bloğu - Bitti.*/	
		for(auto it2: *number2){
			count ++;
			cell = it1*it2 + remain;
			last = cell%10;
			result.push_back(last);
			remain = (cell - last)/10;	
			//cout << "it1: " << it1 << " it2: " << it2 << " rmain: " << remain << " cell: " << cell << " last: " << last << endl;
		}	

		if(remain != 0)
			result.push_back(remain);
		
		remain = 0;

		/*Most critical point is here.*/
		results.push_back(vector<int>{});

		for(auto it: result){
			results[j].push_back(it);
		}
		result.clear();
		j++;
	}
		//cout << "Düzeltme" << endl;
	
	/*Gelenleri değiştirmemeliyiz.*/
	reverse(number1->begin(),number1->end());
	reverse(number2->begin(),number2->end());
	
	/*İki boyutlu matrisin tüm matrisleri toplama düzgün yapılsın diye aynı boyuta getirilir.*/
	int mer=0;
	for(auto it4: results){
		
		for(long unsigned int a=0; a < results.back().size()-it4.size(); a++)
		{
			results[mer].push_back(0);
		}
		mer ++;
	}
	
		mer=0;

/*	for(auto it4: results){
		for(long unsigned int a=0; a < it4.size(); a++)
		{
			cout << results[mer].at(a);
		}
		cout << endl;
		mer ++;
	}*/
//	cout << "Vektörler duzeltildi" << endl;
	/*Her bir vektörün aynı indisli elemanını toplayıp, digite yerleştirip, artanı bir sonraki haneyle toplama*/
	for(long unsigned int g =0; g < results[0].size(); g++){
		
		for(long unsigned int f=0; f < results.size(); f++)	{
			sum = sum + results[f][g] + sumremain;
			sumremain = 0;
		}

		sumcell = sum%10;
//		cout << "Toplam: " << sum << endl;

		sumresult->push_back(sumcell);
		sumremain = (sum - sumcell)/10;
		sum = 0;
	}
//		cout << "Multiplication 3" << endl;

	if(sumremain != 0)
		sumresult->push_back(sumremain);

	
	reverse(sumresult->begin(), sumresult->end());

	return sumresult;
}
