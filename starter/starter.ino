#include <bno055.h>
#include <stdbool.h>
#include <Wire.h>   // used for I2C communication

bool interrupt = 0;   // 1=obstacle, 0=no obstacle

struct bno055_t myBNO;

void setup() {
  //init_Motors();
  //init_IMU();
  
  //interrupts();
}

void loop() {
  
}
/*
 * Set motor pins to idle
 */
bool init_Motors() {
  
}

/*
 * initialize the IMU
 */
bool init_IMU() {
  BNO055_I2C_routine_setup();
  bno055_init(&myBNO);
}

/*
 * initialize proximity sensor
 */
bool init_proximity_sensor() {
  
}

/*
 * initialize pressure sensor
 */
bool init_pressure_sensor() {
  
}

/*
 * reads the IMU data on heading and x,y axis acceleration
 */
void IMU_interrupt_handler() {
  // store heading
  // store acc x, y
}

/*
 * starts the 2 mins automatic self-organize timer
 */
void pressure_sensor_interrupt_handler() {
  // use timer1 for the 2-min countdown timer
}

/*
 * acts as a hardware timer
 */
void timer1_interrupt_handler() {
  
}

/*
 * only enabled when the chair is self-organizing
 */
void proximity_sensor_interrupt_handler() {
  
}

bool self_organize() {
  
}


