/*	O programa tem como objetivo testar a segurança do otp
	p/ isso mostramos que se usarmos a mesma chave p/ encriptar mais de 
	uma mensagem , se o atacante tiver acesso a pelo menos duas mensagens ele obtem 
	informaçao sobre a mensagem
*/
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
	// srand declarado na main p/ garantir que os nums gerados sejam independentes
	srand((unsigned)time(NULL));

	std::string msg1;
	std::string msg2;
	
	getline(std::cin , msg1);
	getline(std::cin , msg2);
	
	// testa se as duas mensagens tem o mesmo tamanho
	if(msg1.size()!= msg2.size()){
		std::cerr << "As mensagens nao podem ter tamanhos diferentes \n";
		return 1;
	}
	std::string key1 = gera_chave(msg1.size());
	std::string key2 = gera_chave(msg2.size());
	
	std::cout << "Chave 1 gerada (hexadecimal)" << std::endl;
	print_hex(key1);
	std::cout << "Chave 2 gerada (hexadecimal)" << std::endl;
	print_hex(key2);
	
	// testa fragilidade encriptando 2 msg com a mesma key
	std::string c_txt1 = encryption(key1,msg1); // E(k1,m1) = k1 XOR m1
	std::string c_txt2 = encryption(key1,msg2); // E(k1,m2) = k1 XOR m2
	// c1 XOR c2 = (k1 XOR m1) XOR (k1 XOR m2) = m1 XOR m2 		
	
	std::cout << "Texto 1 criptografado (hexadecimal)" << std::endl;
	print_hex(c_txt1);
	std::cout << "Texto 2 criptografado (hexadecimal)" << std::endl;
	print_hex(c_txt2);
	
	// c1 XOR c2
	std::string c_xor = xor_string(c_txt1 , c_txt2);
	std::cout << "Xor dos textos criptografados (hexadecimal)" << std::endl;
	print_hex(c_xor);
	// m1 XOR m2
	std::string m_xor = xor_string(msg1,msg2);
	std::cout << "Xor dos textos (hexadecimal)" << std::endl;
	print_hex(m_xor);
	
	return 0;
}
