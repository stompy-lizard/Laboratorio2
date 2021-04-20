#include "Distancia.hh"

#include <cmath>
#include <iostream>

#include "Punto.hh"

Distancia::Distancia(Punto* a, Punto* b) {
  // Asigna puntos y calcula distancia entre los puntos.
  this->setA(a);
  this->setB(b);
  this->calcularDistancia();
}

Distancia::~Distancia() { return; }

void Distancia::setA(Punto* a) { this->a = a; }

void Distancia::setB(Punto* b) { this->b = b; }

void Distancia::setDistancia(float distancia) { this->distancia = distancia; }

Punto* Distancia::getA() { return this->a; }

Punto* Distancia::getB() { return this->b; }

float Distancia::getDistancia() { return this->distancia; }

void Distancia::calcularDistancia() {
  float difX = fabs(this->a->getX() - this->b->getX());
  float difY = fabs(this->a->getY() - this->b->getY());
  // Cálculo y asignación de la distancia entre dos puntos según el Teorema de
  // Pitágoras.
  this->setDistancia(sqrt(difX * difX + difY * difY));
}

std::string Distancia::getDistanciaStr() {
  return "Distancia entre " + this->getA()->getPuntoStr() + " y " +
         this->getB()->getPuntoStr() + ": " +
         std::to_string(this->getDistancia());
}

void Distancia::printDistancia() {
  std::cout << "Distancia entre (" << this->getA()->getX() << ", "
            << this->getA()->getY() << ") y (" << this->getB()->getX() << ", "
            << this->getB()->getY() << "): " << this->getDistancia();
}
