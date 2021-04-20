#ifndef CLASS_DISTANCIA
#define CLASS_DISTANCIA

#include <string>

#include "Punto.hh"

/**
 * @brief Un dato de distancia entre dos puntos.
 *
 */
class Distancia {
 private:
  /**
   * @brief Punto a.
   *
   */
  Punto* a;

  /**
   * @brief Punto b.
   *
   */
  Punto* b;

  /**
   * @brief Valor de la distancia entre los puntos a y b.
   *
   */
  float distancia;

  /**
   * @brief Asigna el valor de la distancia.
   *
   * @param float La distancia entre a y b.
   */
  void setDistancia(float distancia);

  /**
   * @brief Obtiene la distancia entre a y b y la coloca en la propiedad
   * distancia del objeto.
   */
  void calcularDistancia();

 public:
  /**
   * @brief Destructor de un dato de distancia.
   *
   */
  ~Distancia();

  Distancia(Punto* a, Punto* b);

  /**
   * @brief Obtiene el punto A.
   *
   * @return Punto* Punto A.
   */
  Punto* getA(void);

  /**
   * @brief Obtiene el punto B.
   *
   * @return Punto* Punto B.
   */
  Punto* getB(void);

  /**
   * @brief Obtiene la distancia entre a y b.
   *
   * @return float Distancia entre a y b.
   */
  float getDistancia(void);

  /**
   * @brief Asigna el punto A.
   *
   * @param Punto* Punto A.
   */
  void setA(Punto* a);

  /**
   * @brief Asigna el punto B.
   *
   * @param Punto* Punto B.
   */
  void setB(Punto* b);

  /**
   * @brief Obtiene una representación de una distancia.
   *
   * @return std::string Representacion en texto de la distancia.
   */
  std::string getDistanciaStr();

  /**
   * @brief Imprime una representación de una distancia. Se usa para evitar
   * puntos decimales indeseados.
   *
   */
  void printDistancia();
};

#endif
