
#include "../include/ft_ping.h"
#include "../CUnit/CUnit.h"

void get_opt_test(void)
{
    uint32_t count;
    uint8_t flag;

    const char *test_cases[] = {
        "random",   "",             "-random",  "- random",     "--random",
        "-v",       "-?",           "-",        "-v?",          "-v -?",
        "-v-?",     "-vvvvvvvv",    "-v v",     "-v -v",        "-vvrandomvv",
        "-vv??vvv?v",   NULL
    };
    int expected_results[] = {
        -3,         -3,             1,          1,              1,
        -1,         -1,             -3,        -1,              2,
        2,          -1,             2,          2,              3,
        -1,         -3
    };
    bool expected_Vflag[] = {
        0,          0,              0,          0,              0,
        1,          0,              0,          1,              1,
        1,          1,              1,          1,              1,
        1,          0
    };
    bool expected_Hflag[] = {
        0,          0,              0,          0,              0,
        0,          1,              0,          1,              0,
        0,          0,              0,          0,              0,
        1,          0
    };
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    dprintf(1, ORANGE"~~~~~~~~~~~~~~~~~~~~~~~~~~~ get_opt TESTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"DEFAULT);
    
    flag = 0;
    count = 0;
    for (int i = 0; i < num_tests; i++)
    {
        count += try(test_cases[i],NULL,        set_int(get_opt(&flag, test_cases[i])), set_int(expected_results[i]));
        try         (test_cases[i],"V flag",    set_bool(flag & FLAG_V),                set_bool(expected_Vflag[i]));
        try         (test_cases[i],"H flag",    set_bool(flag & FLAG_H),                set_bool(expected_Hflag[i]));
        flag = 0;
    }
    results(count);
}


void is_opt_test(void)
{
    uint32_t count;

    dprintf(1, ORANGE"~~~~~~~~~~~~~~~~~~~~~~~~~~~ is_opt TESTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"DEFAULT);
    count = 0;
    //			TEST_CASE		RECEIVED						EXPECTED
    count += try("NULL", NULL,		set_bool(is_opt(NULL)),			set_bool(false));
    count += try("<>", NULL,		set_bool(is_opt("")),			set_bool(false));
    count += try("<random>", NULL,	set_bool(is_opt("random")),		set_bool(false));
    count += try("<->", NULL,	    set_bool(is_opt("-")),	        set_bool(false));
    count += try("<-random>", NULL,	set_bool(is_opt("-random")),	set_bool(true));

    results(count);
}

void is_dest_test(void)
{
    uint32_t count;
	struct addrinfo *res;

    dprintf(1, ORANGE"~~~~~~~~~~~~~~~~~~~~~~~~~~~ is_dest TESTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"DEFAULT);
    count = 0;
    //			TEST_CASE		RECEIVED						EXPECTED
    count += try("NULL", NULL,		    set_bool(is_dest(NULL, &res)),			set_bool(false));
    count += try("", NULL,		        set_bool(is_dest("", &res)),			set_bool(false));
    count += try("google.com", NULL,    set_bool(is_dest("google.com", &res)),	set_bool(true));
    count += try("8.8.8.8", NULL,		set_bool(is_dest("8.8.8.8", &res)),	    set_bool(true));
    count += try("random", NULL,		set_bool(is_dest("random", &res)),	    set_bool(false));
    

    results(count);
}
