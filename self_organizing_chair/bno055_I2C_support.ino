#define I2C_BUFFER_LEN 8
#define  BNO055_I2C_BUS_WRITE_ARRAY_INDEX  ((ui8)1)

si8 BNO055_I2C_routine_setup() {
  myBNO.bus_write = BNO055_I2C_bus_write;
  myBNO.bus_read = BNO055_I2C_bus_read;
  myBNO.delay_msec = BNO055_delay_msec;
  myBNO.dev_addr = BNO055_I2C_ADDR1;
  
  return BNO055_INIT_VALUE;
}

/*
 * writes to BNO055 using I2C
 */
si8 BNO055_I2C_bus_write(ui8 dev_addr, ui8 reg_addr, ui8 *reg_data, ui8 cnt) {
  assert(cnt <= 32);    // Wire library limits data to 32 bytes due to internal buffer constraints
  si8 BNO055_iERROR = BNO055_INIT_VALUE;
  ui8 write_data_array[I2C_BUFFER_LEN];
  ui8 reg_data_index = BNO055_INIT_VALUE;

  // for loop below modifies array to hold: register address, byte 1, byte 2, ..., byte (cnt - 1)
  write_data_array[BNO055_INIT_VALUE] = reg_addr;
  for(; reg_data_index < cnt; reg_data_index++) {
    write_data_array[reg_data_index + BNO055_I2C_BUS_WRITE_ARRAY_INDEX] = *(reg_data + reg_data_index);
  }

  Wire.beginTransmission(BNO055_I2C_ADDR1);
  Wire.write(write_data_array, cnt);
  BNO055_iERROR = Wire.endTransmission(true);
  
  return (si8)BNO055_iERROR;
}

/*
 * reads from BNO055 using I2C
 */
si8 BNO055_I2C_bus_read(ui8 dev_addr, ui8 reg_addr, ui8 *reg_data, ui8 cnt) {
  si32 BNO055_iERROR = BNO055_INIT_VALUE;
  ui8 read_data_array[I2C_BUFFER_LEN];
  ui8 reg_data_index = BNO055_INIT_VALUE;

  //read_data_array[BNO055_INIT_VALUE] = reg_addr;

  // write the register address to read
  Wire.beginTransmission(BNO055_I2C_ADDR1);
  Wire.write(reg_addr);
  Wire.endTransmission(false);

  // start reading the data
  Wire.requestFrom(BNO055_I2C_ADDR1, cnt, true);
  while(Wire.available()) { // slave may send less than requested
    read_data_array[reg_data_index] = Wire.read(); // receive a byte
    reg_data_index++;
  }
  
  // copy read-data into the user provided reg_data array
  reg_data_index = BNO055_INIT_VALUE;
  for(; reg_data_index < cnt; reg_data_index++) {
    *(reg_data + reg_data_index) = read_data_array[reg_data_index];
  }
  return BNO055_iERROR;
}

/*
 * delay routine for I2C communication
 */
void BNO055_delay_msec(ui32 msec) {
  
}

