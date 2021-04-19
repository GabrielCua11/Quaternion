#include "statemachine.h"

#include <iostream>

void StateMachine::imprimirEstado() {

    std::cout << "El estado es: " << estado << "\n\n";

}

void StateMachine::imprimirRespuestas() {

    std::cout << "\nLa pregunta es: \n";
    std::cout << pregunta << "";
    std::cout << "\nLas respuestas son: \n";

    int numero = 1;

    for(std::string todas : respuestas) {

        std::cout << "Respuesta #" << numero << ": " << todas << "\n";
        numero++;
    }
    
}

void StateMachine::nuevoMensaje(std::string mensaje) {

    std::string clave1 = "Emitir pregunta:";
    std::string clave2 = "Responder pregunta:";
    std::string clave3 = "Finalizar pregunta";

    switch(estado) {

        case Pregunta:
            if(mensaje.find(clave1) != std::string::npos) { //npos = As a return value, it is usually used to indicate no matches.
                pregunta = mensaje;
                estado = Respuesta;
            }
            break;

        case Respuesta:
            if(mensaje.find(clave2) != std::string::npos) {
                std::string contestacion = mensaje;
                respuestas.push_back(contestacion);
            }
            else if(mensaje.find(clave3) != std::string::npos) {
                imprimirRespuestas();
                respuestas.clear();
                estado = Pregunta;
            }
            break;

        default:
            std::cout << "Error, mal programador \n";
    }

}