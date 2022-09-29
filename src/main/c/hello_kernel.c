#define MODULE
#include <linux/init.h>
#include <linux/module.h>
int
init_module() {
	printk("<1> Hello, kernel!\n");
	return 0;
}

