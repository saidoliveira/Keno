#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "keno.h"
#include <ctime> 
#include <cstdlib>
#include <random>
using namespace std;

int rand_number(){
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(1, 80);

	return round(dis(gen));
}

int main(){

	ifstream file("keno.txt");
	KenoBet Keno;
	int cont = 1;
	int value;
	vector<number_type> numeros;
	vector<number_type> numerosRandoms;
	numerosRandoms.reserve(20);
	
	while(true){
		if(!(file >> value)){
			break;
		}
		if(cont == 1){
			Keno.setCredito(value);
		}else if(cont == 2){
			Keno.setRodadas(value);
		}else if(cont > 2){
			numeros.push_back(value);
		}
		if(!file.eof()){
			cont++;
		}
	}	

	Keno.setApostas(numeros);

	cout <<"Credito do jogador: " << Keno.getCredito() << endl;
	cout <<"Numero de rodadas: " << Keno.getRodadas() << endl;
	cout <<"Numeros apostados: ";
	for(number_type i = 0; i < numeros.size(); i++){
		cout << numeros[i] << " ";
	}
	cout << endl;

	cout << "Numeros sorteados: " << endl;
	for(number_type k = 0; k < Keno.getRodadas(); k++){
		for(number_type j = 0; j < 20; j++){
			numerosRandoms[j] = rand_number();
			cout << numerosRandoms[j] << ' '; 
		}
		cout << endl;
	}

	return 0;
} 
