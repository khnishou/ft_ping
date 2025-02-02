
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

bool is_dest(const char *arg, struct addrinfo **res)
{
	struct addrinfo hints;

	memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_RAW;
	return (getaddrinfo(arg, NULL, &hints, res) == 0);
}

int get_dest(const char *arg)
{
	struct addrinfo *res;
    char ip_str[INET6_ADDRSTRLEN];
    void *addr;

	if (!is_dest(arg, &res))
		return (1);
    if (res->ai_family == AF_INET)
    {
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
        addr = &(ipv4->sin_addr);
    }
    else
    {
        struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)res->ai_addr;
        addr = &(ipv6->sin6_addr);
    }

    inet_ntop(res->ai_family, addr, ip_str, sizeof(ip_str));
    printf("Resolved IP: %s\n", ip_str);
    freeaddrinfo(res);
    return 0;
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
		{
			int test = get_dest(argv[it]);
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
