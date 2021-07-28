/** Descripcion
 * @Observations : Implementacion de humidity, esta libreria es utilizada para
 * solucionar y desacoplar codigo de esta maenra aplicar clean code utilizando
 * funciones puras.
 */

#include <Arduino.h>
#include <humidity.h>

/** CONSTRUCTOR HUMIDITY
 * @Observations : constructor de modulo de humedad
 * @param pin : int => numero de pin asignado para modulo
 * @param name : pointer => puntero con el nombre de modulo, solo 3 
 * (humedad01, humedad02, humedad03) son la cantiad maxima soportada
 */
Humidity::Humidity( int pin, char *name ){
  pinMode( pin, INPUT );
  _pin = pin;
  _name = &name;
}

/** GET HUMIDITY
 * @Observations : retorna valor numerico con la humedad obtenida del modulo.
 * @returns valueHumidity : int => valor obtenido por el modulo.
 */
int Humidity::getHumidity(){
  return analogRead( _pin );
}


/** IS ALIVE
 * @Observations : verificamos si el modulo esta respondiendo de manera correcta.
 * @returns ( true or false ) : boolean => retona valor booleano.
 */
bool Humidity::isAlive(){
  int humedad = analogRead( _pin );
  bool alive = false;
  if( humedad < 500 ){
    alive = true;
  }

  return alive;
}

/** GET NAME
 * @Observations : retornamos el nombre del modulo de instancia.
 * @returns _name : String => returna valor _name.
 */
char Humidity::getName(){
  return _name;
}
