// implementar otp com chave no mesmo tamanho que a mensagem
#include<iostream>
#include<string>
#include<cstdlib> // biblioteca para usar numeros aleatorios
#include <iomanip> // Para manipular saídas, como hexadecimal

// funcao de XOR
// ^ é o operador xor por bit
std::string xor_string(std::string msg1 , std::string msg2){

	std::string msg_xor;
	// passa por todos os caracteres fazendo o xor
	for(int i =0 ; i < msg1.size(); i++){
		msg_xor.push_back(msg1[i] ^ msg2[i]);
	}
	return msg_xor;

}
// funçao para gerar a chave
std::string gera_chave(int tamanho){
	std::string key;
	int random;
	
	srand((unsigned)time(NULL));
	// looping para pegar cada letra por vez
	for(int i = 0 ; i < tamanho ; i++){
		random = rand() % 128; // tamanho da tabela ascii
		key.push_back(static_cast<char>(random));
	}
	return key;
}

// funcao de encriptaçao -> e(k,m) = k XOR m = c
std::string encryption(std::string key, std::string plain_txt){
	
	// criar funçao xor para strings
	std::string cypher_txt = xor_string(key,plain_txt);
	return cypher_txt;
}

// funçao de desencriptaçao -> d(k,c) = k XOR c = m 
std::string decryption(std::string key , std::string cypher_txt){
	 // criar funçao xor pra strings 
	std::string msg = xor_string(key,cypher_txt); 
	return msg;
}

// Função para imprimir a string como hexadecimal , feita pelo gpt
void print_hex(const std::string& data) {
    for (unsigned char c : data) {
        std::cout << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(c) << " ";
    }
    std::cout << std::dec << std::endl; // Retorna ao formato decimal padrão
}

int main(){
	// pegar a mensagem
	std::string msg;
	getline(std::cin,msg);
	std::string c_txt;
	std::string resul;
	
	// pega o tamanho da mensagem
	int tamanho;
	tamanho = msg.size();
	
	// gera uma chave aleatoria com o tamanho da mensagem
	std::string k  = gera_chave(tamanho); // exemplo
	std::cout << "Chave gerada (hexadecimal): ";
   	print_hex(k);
	// chama funcao de encriptacao
	c_txt = encryption(k,msg);
	// printa a saida
	std::cout << "Texto criptografado (hexadecimal): ";
    	print_hex(c_txt);
	// chama funçao de desencriptaçao
	resul = decryption(k,c_txt);
	// printa saida
	std::cout << "Texto (hexadecimal): ";
    	print_hex(resul);
    	std::cout << resul << std::endl;
	

	return 0;
}
