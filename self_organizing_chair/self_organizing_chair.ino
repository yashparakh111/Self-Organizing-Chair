#include <bno055.h>   // contains BNO055 support data
#include <stdbool.h>
#include <assert.h>
#include <Wire.h>   // I2C communication

#define ON_BOARD_LED_PIN 13

#define IMU_INT_PIN
#define PROXIMITY_INT_PIN
#define LOAD_INT_PIN

// interrupt priorities from highest to lowest: 21 (INT0), 20(INT1), 19(INT2), 18(INT3), 2(INT4), 3(INT5)

// variables shared with interrupts must be declared volatile because the CPU might assume the variable value is in a process register which might no be the case.
volatile bool obstacle = 0;   // 1 = obstacle, 0 = no obstacle

struct bno055_t myBNO;  // BNO055 device
int16_t bno055_euler_h;   // current chair heading/yaw

/*
 * hardware timer
 */
void timer1_interrupt_handler() {
  
}

void setup() {
  init_Motors();
  init_IMU();
  init_communication();
  init_pressure_sensor();
  interrupts();
}

/*
 * initialize communication
 */
void init_communication() {
  Wire.begin();
}

void loop() {
  
}

/*
 * Enters self-organizing mode.
 * Return: whether self-organize was successful.
 */
bool self_organize() {
  
}

void sleepNow(void) {
    // Set pin 2 as interrupt and attach handler:
    attachInterrupt(/*add interrupt pin*/, uCWakeUpInt, LOW);
    delay(100);
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    digitalWrite(ONE_BOARD_LED_PIN, LOW);
    sleep_mode();

    // resume here after waking up
    sleep_disable();
    digitalWrite(ON_BOARD_LED_PIN,HIGH);   // turn LED on to indicate awake
}

void uC_wakeUp_interrupt(void)
{
    detachInterrupt(0);
}
