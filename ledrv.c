#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>

static int gpio_pin = 26;
static int gpio_value = 1;
module_param(gpio_pin, int, 0755);
static struct gpio led;

MODULE_LICENSE("BSD");
MODULE_AUTHOR("Kaljan");
MODULE_DESCRIPTION("LED Driver. LED connected to GPIO26");
MODULE_SUPPORT_DEVICE("BlueLED");

static int __init GPIO26_init(void)
{
	int gpqr;
	printk(KERN_NOTICE "gpio_init\n");
	led.gpio = gpio_pin;
	led.flags = GPIOF_OUT_INIT_LOW;
	led.label = "Blue LED";
	
	if (!gpio_is_valid(gpio_pin)) {
		printk(KERN_ALERT " GPIO number %d not valid.\n", gpio_pin);
		return -1;
	}
	
	gprq = gpio_request(gpio_pin,"Blue LED");
	
	if (ret) {
		printk(KERN_ALERT "Gpio request failed.\n");
		return -2;
    }
	
	printk(KERN_NOTICE "Set GPIO26 direction output\n");
	gpio_direction_output(gpio_pin, 0);
	printk(KERN_NOTICE "LED On\n");
	gpio_set_value(gpio_pin, gpio_value);
	
	return 0;
}

static void __exit GPIO26_exit(void)
{
	printk(KERN_NOTICE "LED Off\n");
	gpio_set_value(gpio_pin, 0);
	gpio_free(led.gpio);
	printk(KERN_NOTICE "ldrv module exit\n");
}

module_init(GPIO26_init);
module_exit(GPIO26_exit);
