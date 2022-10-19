#include "main.h"
#include <unistd.h>

/**
 * Prints stdout
 * return: 0
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
