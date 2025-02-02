
#include "../include/ft_ping.h"



bool is_opt(char const *arg)
{	
	return ((arg && arg[0] && arg[0] == '-' && arg[1]));
}

int get_opt(uint8_t *opt, char const *arg)
{	
	int it;

	it = 0;
	if (!is_opt(arg))
		return (-3);
	if (!arg[1])
		return (0);
	while (++it && arg && arg[it])
	{
		if (arg[it] == 'v')
			*opt |= FLAG_V;
		else if (arg[it] == '?')
			*opt |= FLAG_H;
		else
			return (it);
	}
	return (-1);
}

bool parser(t_data *data, int argc, char const **argv)
{
	(void) data; // check remove later
	uint8_t	flag;
	int it;
	int	jt;

	it = 0;
	flag = 0;
	while (argv[++it] && it < argc)
	{
		jt = -1;
		if (!is_opt(argv[it]))
			dprintf(2, "<%s> [%d]\n", argv[it], test); // check create a function that add the string into a lst or hanle it by itself
		}
		else
		{
			jt = get_opt(&flag, argv[it]);
			if (jt != -1)
			{
				dprintf(2, "\nping: invalid option -- '%c'\n", argv[it][jt]); // check create an error handler at the specific [it][ij] 
				return (true);
			}
		}	
	}
	// data->opt = flag;
	return (false);
}
