#include "main.h"

/**
 * main - Shell entry points
 * @argc: argument count
 * @argv: argument variable
 * Return: 0 Always success
 */

int main(int argc, char *argv[])
{
	UNUSED(argc);
	run_shell(argv[0]);
	return (0);
}
