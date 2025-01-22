
#include "../include/ft_ping.h"

#define I_MASK  0xFFFF
#define J_SHIFT 16

#define PRINT_VALUE(x) _Generic((x), \
    int: print_int, \
    float: print_float, \
    double: print_double, \
    char: print_char, \
    char *: print_string, \
    _Bool: print_bool, \
    default: print_unknown \
)(x)

int try(char *test, void *rec, void *exp);
void results(uint32_t result);

void print_int(int x) {
    dprintf(1, "%d", x);
}

void print_float(float x) {
    dprintf(1, "%.2f", x);
}

void print_double(double x) {
    dprintf(1, "%.2lf", x);
}

void print_char(char x) {
    dprintf(1, "%c", x);
}

void print_string(char *x) {
    if (!x)
        dprintf(1, "NULL");
    else if (!x[0])
        dprintf(1, "empty string");
    else
        dprintf(1, "%s", x);
}

void print_bool(bool x) {
    dprintf(1, x ? "true" : "false");
}

void print_unknown(void *x) {
    dprintf(1, BLUE"\nUnknown type for value <%p>. Please add a type handler in the PRINT_VALUE macro to properly print this type.\n"DEFAULT, x); 
}

void is_opt_test(void)
{
    uint32_t count = 0;

    //			TEST_CASE		RECEIVED						EXPECTED
    count += try("NULL",		(void *)is_opt(NULL),			(void *)false);
    count += try("<>",			(void *)is_opt(""),				(void *)false);
    count += try("<random>",	(void *)is_opt("random"),		(void *)false);
    count += try("<-random>",	(void *)is_opt("-random"),		(void *)true);

    results(count);
}

int try(char *test, void *rec, void *exp)
{
    uint32_t count = 1;

    if (rec == exp)
        return count;

    dprintf(1, "\n\033[1;31m[FAILED]\033[0m "); // Bold Red
    dprintf(1, "\033[1;37mTest:\033[0m \"%s\"\n", test); // White

    dprintf(1, "  🔹 Expected: ");
    PRINT_VALUE(exp);
    dprintf(1, "\n");

    dprintf(1, "  🔸 Received: ");
    PRINT_VALUE(rec);
    dprintf(1, "\n");

    count += (1 << J_SHIFT);
    return count;
}

void results(uint32_t result)
{
	uint16_t passed = (result & I_MASK) - ((result >> J_SHIFT) & I_MASK);
    uint16_t total  = result & I_MASK;
    uint16_t failed = (result >> J_SHIFT) & I_MASK;

	dprintf(1, "\n\033[1;34m[TEST RESULTS]\033[0m"); // Bold Blue Header
    dprintf(1, "\t\t✅ Passed: %u", passed);
    dprintf(1, "\t❌ Failed: %u", failed);
    dprintf(1, "\t📊 Total:  %u\n", total);
}

int main(void)
{
    is_opt_test();
    return 0;
}
