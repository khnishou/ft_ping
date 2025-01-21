
#include "../include/ft_ping.h"

int main(int argc, char const *argv[])
{
	t_data	data;
	if (parser(&data, argc, argv))
		return (1); // check create later an error handler "ft_error"
	return 0;
}
