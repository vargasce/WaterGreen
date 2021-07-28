/** Description
 * @Observation : 
 *
 */

#ifndef Humidity_h
#define Humidity_h

#include <Arduino.h>

class Humidity {
  public:
    Humidity( int pin, char* name );
    int getHumidity();
    bool isAlive();
    char getName();
  private:
    int _pin;
    char *_name;
}

#endif
