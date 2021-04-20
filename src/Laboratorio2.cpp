#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Distancia.hh"
#include "Punto.hh"
#include "Util.hh"

/**
 * @brief Solicita un entero que corresponde a la cantidad de puntos a ingresar,
 * debe ser mayor a 2.
 *
 * @return int Cantidad de puntos a ingresar.
 */
int solicitarCantidadPuntos() {
  std::string cantidadPuntosStr;  // Entrada del usuario se coloca acá.
  int cantidadPuntos;             // Entero ingresado por el usuario.
  // Se solicita hasta que se cumplan los requerimientos, entero mayor o igual
  // a 2.
  while (true) {
    std::cout << "¿Cuántos puntos va a introducir?: ";
    std::cin >> cantidadPuntosStr;
    if (Util::isInt(cantidadPuntosStr)) {
      cantidadPuntos = std::stoi(cantidadPuntosStr);
      if (cantidadPuntos >= 2) {
        break;  // salir del while cuando se cumplan los requerimientos
      }
      // solicitar un entero mayor o igual a 2.
      std::cout << "Error. La cantidad de puntos debe ser mayor o igual a 2."
                << std::endl;
    } else {
      // solicitar un entero.
      std::cout << "Error. La cantidad de puntos debe ser un entero."
                << std::endl;
    }
  }
  return cantidadPuntos;
}

/**
 * @brief Solicita un punto de la forma x,y, con x y y números en punto
 * flotante.
 *
 * @return Punto* Punto resultante del valor ingresado por el usuario.
 */
Punto* solicitarPunto() {
  std::string puntoStr;  // Entrada por el usuario va acá.
  Punto* punto;          // Punto resultante.
  // Se solicita el punto hasta tener una entrada correcta
  while (true) {
    std::cout << "Digite un punto bi-dimensional de la forma x,y: ";
    std::cin >> puntoStr;
    try {
      punto = new Punto(puntoStr);
      break;  // Salir del while luego de crear el punto.
    } catch (const std::invalid_argument& e) {
      // Informar error al usuario-
      std::cerr << e.what() << std::endl;
    }
  }
  return punto;
}

/**
 * @brief Programa principal.
 *
 * @return int .
 */
int main(void) {
  // Imprimir información.
  std::cout
      << "Este es un programa que le ayudará a calcular la distancia máxima y "
         "mínima entre cualquier par de puntos, entre una lista de puntos."
      << std::endl;
  int cantidadPuntos = solicitarCantidadPuntos();

  std::vector<Punto>* puntos = new std::vector<Punto>();
  // Obtener todos los puntos.
  for (std::size_t n = 0; n < cantidadPuntos; n++) {
    Punto punto = *solicitarPunto();
    puntos->push_back(punto);
  }

  // Obtener todas las distancias.
  int i = 0;
  std::vector<Distancia>* distancias = new std::vector<Distancia>();
  for (auto it = puntos->begin(); it != puntos->end(); ++it, ++i) {
    auto it2 = puntos->begin() + i;
    for (++it2; it2 != puntos->end(); ++it2) {
      distancias->push_back(Distancia(&(*it), &(*it2)));
    }
  }

  // Ordenar el vector de distancias.
  std::sort(distancias->begin(), distancias->end(),
            [](Distancia a, Distancia b) {
              return a.getDistancia() < b.getDistancia();
            });

  // Imprimir distancias máximas.
  i = 0;
  std::cout << "La distancia mínima(" << distancias->begin()->getDistancia()
            << ") se da entre los puntos: ";
  for (auto it = distancias->begin(); it != distancias->end(); ++it) {
    if (it->getDistancia() == distancias->begin()->getDistancia()) {
      if (i > 0) {
        std::cout << ", ";
      }
      it->getA()->printPunto();
      std::cout << " y ";
      it->getB()->printPunto();
      i++;
    }
  }
  std::cout << std::endl;

  // Imprimir distancias mínimas.
  i = 0;
  std::cout << "La distancia máxima(" << distancias->back().getDistancia()
            << ") se da entre los puntos: ";
  for (auto it = distancias->begin(); it != distancias->end(); ++it) {
    if (it->getDistancia() == distancias->back().getDistancia()) {
      if (i > 0) {
        std::cout << ", ";
      }
      it->getA()->printPunto();
      std::cout << " y ";
      it->getB()->printPunto();
      i++;
    }
  }
  std::cout << std::endl;

  return 0;
}
