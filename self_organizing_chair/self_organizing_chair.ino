#include <bno055.h>   // contains BNO055 support data
#include <stdbool.h>
#include <assert.h>
#include <Wire.h>   // I2C communication

bool interrupt = 0;   // 1=obstacle, 0=no obstacle
struct bno055_t myBNO;

/*
 * initialize communication
 */
void init_communication() {
  Wire.begin();
}

/*
 * hardware timer
 */
void timer1_interrupt_handler() {
  
}

void setup() {
  //init_Motors();
  //init_IMU();
  //init_communication();
  //interrupts();
}

void loop() {
  
}

/*
 * Enters self-organizing mode.
 * Return: whether self-organize was successful.
 */
bool self_organize() {
  
}


