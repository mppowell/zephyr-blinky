// Include zephyr library, zephyr's device library, and GPIO driver
#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>

// #define GPIO port and pin within that port for readability
#define LED_PORT DT_ALIAS_LED0_GPIOS_CONTROLLER
#define LED	DT_ALIAS_LED0_GPIOS_PIN

// Main code
void main(void)
{
    // Initialize a device structure named gpio_dev
	struct device *gpio_dev;

    // Assign gpio_dev to the gpio port
	gpio_dev = device_get_binding(LED_PORT);
    //Configure the LED pin to be an output
	gpio_pin_configure(dev, LED, GPIO_DIR_OUT);

    // Infinite loop
    for (;;) {
        // Toggle LED pin on and off with 1 second delay (blinky!)
        gpio_pin_write(dev, LED, GPIO_DS_HIGH_POS);
        k_sleep(1000);
        gpio_pin_write(dev, LED, GPIO_DS_LOW_POS);
        k_sleep(1000);
    }
}
