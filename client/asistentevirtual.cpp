#include "asistentevirtual.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void AsistenteVirtual::imprimirEstado() {

    std::cout << "\nDatos almacenados: " << "\n";

    for(size_t i = 0; i < _indice.size(); i++) {

        std::cout << _indice[i] << ": " << _valor[i] << "\n";
    }
}

void AsistenteVirtual::almacenar(std::string mensaje) {

    size_t n = mensaje.size();
    size_t signo = mensaje.find("->");
    int interno = 0;

    std::string _index = mensaje.substr(0, signo - 1);
    std::string _value = mensaje.substr(signo + 3);

    for(size_t i = 1; i < n ; i++) {

        if(mensaje[i] == '>') {

            interno++;
        }    
    } 

    if(interno != 0 && n > (signo + 3)) {

        size_t c = _indice.size();

        for(size_t i = 0; i < c; i++) {

            if(_indice[i] == _index) {

                _valor[i] = _value;

                std::cout << "El indice almacenado es: <" << _index << ">\n";
                std::cout << "El valor almacenado es: <" << _value << ">\n";

                return;
            }
        }

        _indice.push_back(_index);
        _valor.push_back(_value);

        std::cout << "El indice almacenado es: <" << _index << ">\n";
        std::cout << "El valor almacenado es: <" << _value << ">\n";
    }
}

void AsistenteVirtual::recuperar(std::string palabra){

    size_t c = _indice.size();

    for(size_t i = 0; i < c; i++) {

        if(_indice[i] == palabra) {

            std::cout << "El valor recuperado para <" << palabra << "> es: " << _valor[i] << "\n";
        }
    }
}

void AsistenteVirtual::buscar(std::string palabra){

    size_t c = _indice.size();

    std::vector<std::string> _enumerar;
    std::string iniciales = palabra.substr(0,3);
    std::transform(iniciales.begin(), iniciales.end(), iniciales.begin(), ::tolower);

    for(size_t i = 0; i < c; i++) {

        std::string palabraActual = _indice[i];
        std::string inicialesPalabraActual = palabraActual.substr(0,3);
        std::transform(inicialesPalabraActual.begin(), inicialesPalabraActual.end(), inicialesPalabraActual.begin(), ::tolower);

        if(inicialesPalabraActual == iniciales) {

            if(_enumerar.size() > 0) {

                _enumerar.push_back(",");
                _enumerar.push_back(palabraActual);
            }
            else {

                _enumerar.push_back(palabraActual);
            }
        }
    }

    std::cout << "Palabras similiares a '" << palabra << "': {";

        for(std::string str : _enumerar) {

            std::cout << str;
        }

    std::cout << "}" << "\n";
}

void AsistenteVirtual::ayuda() {

    std::cout << "\nLISTA DE COMANDOS PARA EL ASISTENTE VIRTUAL.\n";
    std::cout << "\n1) .almacenar - 'INDICE' -> 'MENSAJE A GUARDAR'\n";
    std::cout << "Este comando almacena uno o mas mensajes dentro de un indice de interes.\n";
    std::cout << "2) .recuperar - 'INDICE'\n";
    std::cout << "Este comando recupera el/los mensaje/s que se encuentre/n dentro de un indice.\n";
    std::cout << "3) .buscar - 'INDICE'\n";
    std::cout << "Este comando busca entre todos los indices aquellos con algun parecido a la palabra que acompana el comando.\n";
    std::cout << "4) .mostrar\n";
    std::cout << "Este comando muestra todos los indices con sus respectivos mensajes sin excepcion.\n";
}

void AsistenteVirtual::nuevoMensaje(std::string mensaje) {

    size_t _almacenar = mensaje.find(".almacenar -");
    size_t _recuperar = mensaje.find(".recuperar -");
    size_t _buscar = mensaje.find(".buscar -");
    size_t _mostrar = mensaje.find(".mostrar");
    size_t _ayuda = mensaje.find(".ayuda");

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

    else if(_ayuda == 0) {

        ayuda();
    }
} 