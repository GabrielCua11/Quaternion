#include "asistentevirtual.h"
#include "room.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

AsistenteVirtual::AsistenteVirtual(Quotient::Room* quo) : _quo(quo) {}

void AsistenteVirtual::imprimirEstado() {

    _quo->postHtmlText("Datos almacenados:", "<h2 style=\"color:red;\"> Datos almacenados: </h2>");

    for(size_t i = 0; i < _indice.size(); i++) {

        std::stringstream ss;
        ss << "- " << _indice[i] << ": " << _valor[i];
        std::string msg = ss.str();
        _quo->postHtmlText(QString::fromStdString(msg), QString::fromStdString("<h3>" + msg + "</h3>"));
    }
}

void AsistenteVirtual::almacenar(std::string mensaje) {

    size_t n = mensaje.size();
    size_t signo = mensaje.find("->");
    int interno = 0;

    std::string _index = mensaje.substr(0, signo - 1);
    std::string _value = mensaje.substr(signo + 3);

    for(size_t i = 1; i < n; i++) {

        if(mensaje[i] == '>') {

            interno++;
        }
    }

    if(interno != 0 && n > (signo + 3)) {

        size_t c = _indice.size();

        for(size_t i = 0; i < c; i++) {

            if(_indice[i] == _index) {

                _valor[i] = _value;

                return;
            }
        }

        _indice.push_back(_index);
        _valor.push_back(_value);
    }
}

void AsistenteVirtual::recuperar(std::string palabra) {

    size_t c = _indice.size();

    for(size_t i = 0; i < c; i++) {

        if(_indice[i] == palabra) {

            std::stringstream ss;
            ss << "El mensaje recuperado para '" << palabra << "' es: " << _valor[i] << "\n";
            std::string msg = ss.str();
            _quo->postHtmlText(QString::fromStdString(msg), QString::fromStdString("<h2>" + msg + "</h2>"));

            return;
        }
    }

    std::stringstream ss2;
    ss2 << "No existe el indice enviado.\n";
    std::string msg2 = ss2.str();
    _quo->postHtmlText(QString::fromStdString(msg2), QString::fromStdString("<h2>" + msg2 + "</h2>"));
}

void AsistenteVirtual::buscar(std::string palabra){

    size_t c = _indice.size();

    std::vector<std::string> _enumerar;
    std::string copia = palabra;
    std::transform(copia.begin(), copia.end(), copia.begin(), ::tolower);

    int tamano = palabra.size();

    for(size_t i = 0; i < c; i++) {

        std::string palabraActual = _indice[i];
        std::string copiaPalabraActual = palabraActual.substr(0, tamano);
        std::transform(copiaPalabraActual.begin(), copiaPalabraActual.end(), copiaPalabraActual.begin(), ::tolower);

        if(copia == copiaPalabraActual) {

            _enumerar.push_back(palabraActual);
        }
    }

    std::stringstream ss;
    ss << "Indices similiares a '" << palabra << "':";
    std::string msg = ss.str();
    _quo->postHtmlText(QString::fromStdString(msg), QString::fromStdString("<h2>" + msg + "</h2>"));

    for(std::string str : _enumerar) {

        std::stringstream ss2;
        ss2 << "- " << str << "\n";
        std::string msg2 = ss2.str();
        _quo->postHtmlText(QString::fromStdString(msg2), QString::fromStdString("<h3>" + msg2 + "</h3>"));
    }
}

void AsistenteVirtual::ayuda() {

    _quo->postHtmlText("Lista de comandos para el asistente virtual:", "<h2> Lista de comandos para el asistente virtual: </h2>");
    _quo->postHtmlText(" .almacenar - 'INDICE' -> 'MENSAJE A GUARDAR'. Almacena un mensaje dentro del indice indicado", "<h3> .almacenar - 'INDICE' -> 'MENSAJE A GUARDAR'. Almacena un mensaje dentro del indice indicado </h3>");
    _quo->postHtmlText(" .recuperar - 'INDICE' . Recupera el mensaje que se encuentre dentro del indice.", "<h3> .recuperar - 'INDICE' . Recupera el mensaje que se encuentre dentro del indice. </h3>");
    _quo->postHtmlText(" .buscar - 'INDICE' . Busca todos los indices parecidos a la palabra enviada", "<h3> .buscar - 'INDICE' . Busca todos los indices parecidos a la palabra enviada </h3>");
    _quo->postHtmlText(" .mostrar . Muestra todos los indices con su respectivo mensaje", "<h3> .mostrar . Muestra todos los indices con su respectivo mensaje </h3>");
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