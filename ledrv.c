#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>

static int led_gpio_pin = 26;
//module_param(led_gpio_pin, int, 0755);
static struct gpio led;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kaljan");
MODULE_DESCRIPTION("LED Driver. LED connected to GPIO26");

static int __init GPIO26_init(void)
{
	int gprq;
	printk(KERN_NOTICE "gpio_init\n");
	led.gpio = led_gpio_pin;
	led.flags = GPIOF_OUT_INIT_LOW;
	led.label = "Blue LED";
	
	if (!gpio_is_valid(led_gpio_pin)) {
		printk(KERN_ALERT " GPIO number %d not valid.\n", led_gpio_pin);
		return -1;
	}
	
	gprq = gpio_request(led_gpio_pin,"Blue LED");
	
	if (gprq) {
		printk(KERN_ALERT "Gpio request failed.\n");
		return -2;
    }
	
	printk(KERN_NOTICE "Set GPIO26 direction output\n");
	gpio_direction_output(led_gpio_pin, 0);
	printk(KERN_NOTICE "LED On\n");
	gpio_set_value(led_gpio_pin, 1);
	
	return 0;
}

static void __exit GPIO26_exit(void)
{
	printk(KERN_NOTICE "LED Off\n");
	gpio_set_value(led_gpio_pin, 0);
	gpio_free(led.gpio);
	printk(KERN_NOTICE "ldrv module exit\n");
}

module_init(GPIO26_init);
module_exit(GPIO26_exit);
