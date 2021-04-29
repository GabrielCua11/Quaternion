#pragma once

#include "room.h"

class AsistenteVirtual {

    public:
    AsistenteVirtual(Quotient::Room* quo);
    void nuevoMensaje(std::string mensaje);
    void mostrar();
    void ayuda();
    void almacenar(std::string mensaje);
    void recuperar(std::string mensaje);
    void buscar(std::string mensaje);

    private:
    std::vector<std::string> _indice;
    std::vector<std::string> _valor;
    Quotient::Room* _quo;
};