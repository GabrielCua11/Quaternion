#pragma once

#include <string>
#include <vector>

class AsistenteVirtual {

    public:
    void nuevoMensaje(std::string mensaje);
    void imprimirEstado();
    void ayuda();
    void almacenar(std::string mensaje);
    void recuperar(std::string mensaje);
    void buscar(std::string mensaje);

    private:
    std::vector<std::string> _indice;
    std::vector<std::string> _valor;
};