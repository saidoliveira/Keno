#ifndef KENO_H
#define KENO_H

using number_type = unsigned short int; //<! data type for a keno hit.

class randomNumber{
public:
	int randomNumberGenerator(int min, int max){
		return (rand() % max + min);
	}
};

class KenoBet{
	private:
		float credito;                    //<!The player's wage.
		number_type rodadas;         	  //<!The player's rounds.
		std::vector<number_type> apostas; //<!The player's bet.

	public:
		float getCredito();
		void setCredito(float x);
		number_type getRodadas();
		void setRodadas(number_type x);
		void setApostas(std::vector<number_type> &apostas);

		bool verificaNumero(number_type num);
		bool verificaCredito(float apostaDada);

		
};

float KenoBet::getCredito(){
	return credito;
}
void KenoBet::setCredito(float x){
	credito = x;
}
number_type KenoBet::getRodadas(){
	return rodadas;
}
void KenoBet::setRodadas(number_type x){
	rodadas = x;
}

void KenoBet::setApostas(std::vector<number_type> &apostas){}

bool KenoBet::verificaNumero(number_type num){
	for(int i = 0; i < apostas.size(); i++){
		if(apostas[i] == num){
			return false;
		}
	}
	return true;
}

bool verificaCredito(float credito){
	return credito > 0;
}

void reset(void){
	credito = 0;
}

#endif