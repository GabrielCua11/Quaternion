#include "asistentevirtual.h"
#include "room.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

AsistenteVirtual::AsistenteVirtual(Quotient::Room* quo) : _quo(quo) {}
void AsistenteVirtual::imprimirEstado() {

    std::cout << "Datos dentro de StateMachine: " << "\n";
    for (size_t i = 0; i < _indice.size(); i++) {
        std::cout << _indice[i] << ": " << _valor[i] << "\n";
    }

}


void AsistenteVirtual::almacenar(std::string mensaje){


size_t n = mensaje.size();
size_t signo = mensaje.find("->");
int interno = 0;
std::string _index = mensaje.substr(0,signo-1);
std::string _value = mensaje.substr(signo+3);

 for (int i=1;  i<n ; i++) {
    if (mensaje[i] == '>') {
        interno++;
        }    
        } 
if (interno != 0 && n>(signo+3)) {

size_t c = _indice.size();
for (int i = 0; i < c; i++) {

    if (_indice[i] == _index) {
        _valor[i] = _value;
        return;
    }

}

_indice.push_back(_index);
_valor.push_back(_value);

std::cout << "indice almacenado: <" << _index << ">\n";

std::cout << "valor almacenado: <" << _value << ">\n";
return;
    }

}


void AsistenteVirtual::recuperar(std::string palabra){


size_t c = _indice.size();
std::string valor_buscado;

for (int i = 0; i<c; i++) {

    if (_indice[i] == palabra) {
        valor_buscado = _valor[i];
    }
}

std::cout << "El valor recuperado para <" << palabra << "> es: " << valor_buscado << "\n";

}

void AsistenteVirtual::buscar(std::string palabra){

size_t c = _indice.size();
std::vector<std::string> _enumerar = {};
std::string iniciales = palabra.substr(0,3);
std::transform(iniciales.begin(), iniciales.end(), iniciales.begin(), ::tolower);
for (int i = 0; i<c; i++) {
    std::string palabra_actual = _indice[i];
    std::string iniciales_palabra_actual = palabra_actual.substr(0,3);
    std::transform(iniciales_palabra_actual.begin(), iniciales_palabra_actual.end(), iniciales_palabra_actual.begin(), ::tolower);
    if (iniciales_palabra_actual == iniciales) {

        if (_enumerar.size() >= 1) {
        _enumerar.push_back(",");
        _enumerar.push_back(palabra_actual);
        }

        else {
        _enumerar.push_back(palabra_actual);
        }
    }
}
std::cout << "Palabras similiares a '" << palabra << "': {";
    for (std::string str: _enumerar) {
        std::cout << str ;
     }
std::cout << "}" << "\n";


}


void AsistenteVirtual::nuevoMensaje(std::string mensaje) {
   
    size_t _almacenar = mensaje.find(".almacenar -");
    size_t _recuperar = mensaje.find(".recuperar -");
    size_t _buscar = mensaje.find(".buscar -");
    size_t _mostrar = mensaje.find(".mostrar");

    if(_almacenar == 0) {
        almacenar(mensaje.substr(13));
    }

    else if(_recuperar == 0) {
        recuperar(mensaje.substr(13));
    }

    else if(_buscar == 0) {
        buscar(mensaje.substr(10));
    }

    else if(_mostrar == 0) {
        imprimirEstado();
    }

 }