#include "HX711.h"

/*
 * initialize pressure sensor
 */
bool init_pressure_sensor() {
  
}

/*
 * starts the 2 mins automatic self-organize timer
 */
void pressure_sensor_interrupt_handler() {
  // use timer1 for the 2-min countdown timer
}

#define DOUT 3
#define CLK  2

HX711 scale(DOUT, CLK);

/*
 * initialize pressure sensor
 */
bool init_pressure_sensor() {
  
}

/*
 * starts the 2 mins automatic self-organize timer
 */
void pressure_sensor_interrupt_handler() {
  // use timer1 for the 2-min countdown timer
}

void setup() {
  Serial.begin(9600);
  scale.set_scale();
  scale.tare();
  // put your setup code here, to run once:
  
}

void loop() {
  Serial.print(scale.get_units(), 3);
  // put your main code here, to run repeatedly:

}
