/*
 * initialize the IMU
 */
bool init_IMU() {
  BNO055_I2C_routine_setup();
  bno055_init(&myBNO);
  
}

/*
 * reads the IMU data on heading and x,y axis acceleration
 */
void IMU_interrupt_handler() {
  // store heading
  // store acc x, y
}
