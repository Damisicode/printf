int _putchar(char c);
int _printf(const char *format, ...);

typedef struct flags
{
	char *type;
	void (*f)();
} flag;
