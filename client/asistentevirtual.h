#pragma once

#include "room.h"

#include <string>
#include <vector>

class AsistenteVirtual {

    public:
    AsistenteVirtual(Quotient::Room* quo);
    void imprimirEstado();
    void nuevoMensaje(std::string mensaje);
    void almacenar(std::string mensaje);
    void recuperar(std::string mensaje);
    void buscar(std::string mensaje);

    private:
    std::vector<std::string> _indice;
    std::vector<std::string> _valor;
    Quotient::Room* _quo;
};