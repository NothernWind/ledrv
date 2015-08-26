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
	printk(KERN_NOTICE "gpio_init\n");
	led.gpio = gpio_pin;
	led.flags = GPIOF_OUT_INIT_LOW;
	led.label = "LED";
	
	
	
	return 0;
}

static void __exit GPIO26_exit(void)
{
	gpio_deinit();
}

module_init(GPIO26_init);
module_exit(GPIO26_exit);