
#pragma once


#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

#include "lib.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define FLAG_V		(1 << 0)
#define FLAG_H		(1 << 1)
// #define FLAG_ERR	(1 << 2)

// ./ft_ping	[opt]	<destination>
typedef struct s_data
{
	uint8_t		opt;
	char		*dest;
}	t_data;

// parser
bool is_opt(char const *arg);
int get_opt(uint8_t *opt, char const *arg);
bool parser(t_data *data, int argc, char const **argv);
