#pragma once

#include "string"
#include "vector"

enum Estado { // Enum nos perimte crear la lista de estados.
    Pregunta,
    Respuesta
};

class StateMachine
{
    public:
    void imprimirEstado();
    void nuevoMensaje(std::string mensaje);
    void imprimirRespuestas();

    private:
    Estado estado = Pregunta;
    std::string pregunta = "Nada";
    std::vector <std::string> respuestas;
};