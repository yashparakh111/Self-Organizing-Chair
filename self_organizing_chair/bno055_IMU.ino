/*
 * initialize the IMU
 */
bool init_IMU() {
  int init_status = 0;
  
  init_status += BNO055_I2C_routine_setup();
  init_status += bno055_init(&myBNO);
  init_status += bno055_set_operation_mode(BNO055_OPERATION_MODE_M4G);
  delay(7); // delay to ensure correct operation mode gets set
  init_status += bno055_set_accel_range(BNO055_ACCEL_RANGE_2G);
  init_status += bno055_set_euler_unit(BNO055_EULER_UNIT_DEG);
  init_status += bno055_set_accel_unit(BNO055_ACCEL_UNIT_MSQ);
  setup_BNO_interrupt();
  
  return init_status;
}

/*
 * setup anymotion interrupt on the BNO
 */
bool setup_BNO_interrupt() {
  int init_status = 0;
  
  init_status += bno055_set_intr_accel_any_motion(BNO055_BIT_ENABLE);   // enable the anymotion interrupt
  init_status += bno055_set_intr_mask_accel_any_motion(BNO055_BIT_ENABLE);  // route the interrupt to INT pin
  init_status += bno055_set_accel_any_motion_thres(BNO055_BIT_ENABLE);
  init_status += bno055_set_accel_any_motion_durn(0x02);    // 3 samples above threshold
  init_status += bno055_set_accel_any_motion_no_motion_axis_enable(BNO055_ACCEL_ANY_MOTION_NO_MOTION_X_AXIS, BNO055_BIT_ENABLE);    // enable interrupt on x-axis
  init_status += bno055_set_accel_any_motion_no_motion_axis_enable(BNO055_ACCEL_ANY_MOTION_NO_MOTION_Y_AXIS, BNO055_BIT_ENABLE);    // enable interrupt on y-axis
  init_status += bno055_set_accel_any_motion_no_motion_axis_enable(BNO055_ACCEL_ANY_MOTION_NO_MOTION_Z_AXIS, BNO055_BIT_DISABLE);    // disable interrupt on z-axis
  
  return init_status;
}

/*
 * reads the IMU data on heading and x,y axis acceleration
 */
void IMU_interrupt_handler() {
  // store heading
  // store acc x, y
}
