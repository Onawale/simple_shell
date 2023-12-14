#include "shell.h"

/**
 * main - The entry point for the program
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 if successful or  1 if error occur
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fileDescrip = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fileDescrip)
		: "r" (fileDescrip));

	if (ac == 2)
	{
		fileDescrip = open(av[1], O_RDONLY);
		if (fileDescrip == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fileDescrip;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
