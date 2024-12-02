/*
    A Cifra de Cesar é uma técnica simples de criptografia onde cada letra de um texto é deslocada por um número fixo de posições no alfabeto.
*/
// implementacao apenas para letras minusculas
#include<iostream>
#include<string>
#define SHIFT 3 // valor usado para percorrer a tabela assci em busca de trocar a letra do plain text
using namespace std;

string encryption(string msg){
    int i;
    string c_msg; // texto cifrado
    char encrypted_char;
    for(i = 0 ; i < msg.size() ; i++){
        encrypted_char = msg[i] + SHIFT;
        if(encrypted_char > 'z'){ // testa se a soma passou do z minusculo em assci
            encrypted_char = encrypted_char - 26; // se passou subtrai pelo quantidade de numeros no alfabeto
        } 
        c_msg += encrypted_char; 
    }
    
    return c_msg;
}

string decryption(string c_msg){
    int i;
    string msg; // texto decifrado
    char decrypted_char;
    for(i = 0 ; i < c_msg.size() ; i++ ){
        decrypted_char = c_msg[i] - SHIFT;
        if(decrypted_char < 'a'){
            decrypted_char = decrypted_char + 26;
        }
        msg += decrypted_char;
    }
    return msg;
}


int main(){
    string text;
    string c_text;
    string msg;
    //pega o texto
    getline(cin , text);
    cout << "---------------------------------" << endl; // separa a entrada da saida
    c_text = encryption(text);
    
    // como string é um vetor de char , isso me da a primeira letra
    cout << c_text << endl;
    cout << "---------------------------------" << endl;
    msg = decryption(c_text);
    cout << msg << endl;
    // funcao para encriptar soma cada posicao da string com uma valor 

    
    return 0;
}