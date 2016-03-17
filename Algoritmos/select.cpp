/**
Autor: Daniel Saad Nogueira Nunes
Nome do Problema:
ID do Problema: 
url do Problema: 
Técnica:
Complexidade:
Comentários:
**/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int partition(vector<int>& v,int pivo,int l,int r){
	int k = l;
    for(int i=l;i<=r;i++){
        if(v[i]<=pivo){
            swap(v[k],v[i]);
            k++;
        }
        i++;
    }
    return (k-l); //retornamos a posição do pivo em relação ao inicio
}


int select_k (vector<int>& v,int k,int l,int r){
	if(l>=r){
		return 0;
	}
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << "\n";
	vector<int> medianas;
	int i;
	cout << "Ordenando os subvetores\n" << endl;
	cout << "Medianas = ";
	int s = ceil((double) v.size()/5);
	for(i=0;i<s;i++){
		int begin = 5*i;
		int end =  min((size_t) 5*(i+1),v.size());
		sort(v.begin()+ begin ,v.begin()+end);
		medianas.push_back(v[(begin+end)/2]);
		cout << v[(begin+end)/2] << " ";
	}

	cout << "\n Selecionando a mediana das medianas\n" << endl;
	int med = select_k(medianas,medianas.size()/2,0,medianas.size()-1);
	cout << "Particionando\n" << endl;
	int kth = partition(v,medianas[med],l,r);
	if(kth<k){
		return select_k(v,k-kth,l+kth+1,r);
	}
	else if(k<kth){
		select_k(v,k,l,l+kth-1);
	}
	return kth;
}

int main(){
	std::ios::sync_with_stdio(false);
	vector<int> v = {5,3,1,7,9,2,0,4,6,8};
	int k = 8;
	int pos = select_k(v,k,0,v.size()-1);
	cout << "Posição do " << k << "-esimo = " << pos << "\n";
	cout << "V[pos] = " << v[pos] << "\n";
	return 0;
}