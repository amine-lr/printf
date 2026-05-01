#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
 
/* =============================================
**  COLORS for terminal output
** ============================================= */
#define RESET   "\033[0m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define BOLD    "\033[1m"
 
static void	print_section(const char *title)
{
	printf("\n" CYAN "══════════════════════════════════════\n");
	printf("  %s\n", title);
	printf("══════════════════════════════════════\n" RESET);
}
 
static void	print_case(const char *desc)
{
	printf(YELLOW "\n  ▶ %s\n" RESET, desc);
}
 
/*
** Each test prints:
**   [printf]    -> result + return value
**   [ft_printf] -> result + return value
** You compare them visually.
*/
 
int	main(void)
{
	int		ret_orig;
	int		ret_ft;
	void	*null_ptr = NULL;
 
	printf(BOLD "\n╔══════════════════════════════════════╗\n");
	printf("║      ft_printf  TEST  SUITE          ║\n");
	printf("╚══════════════════════════════════════╝\n" RESET);
 
	/* ─────────────────────────────────────────── */
	print_section("%c  — Character");
	/* ─────────────────────────────────────────── */
 
	print_case("Regular character 'A'");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%c\n", 'A');
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%c\n", 'A');
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Character '0' (digit zero)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%c\n", '0');
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%c\n", '0');
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("NULL character '\\0' (edge case — only 1 char printed, NOT end of output)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%c\n", '\0');
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%c\n", '\0');
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Space character ' '");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%c\n", ' ');
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%c\n", ' ');
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("%s  — String");
	/* ─────────────────────────────────────────── */
 
	print_case("Normal string");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%s\n", "Hello, 42!");
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%s\n", "Hello, 42!");
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Empty string \"\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%s\n", "");
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%s\n", "");
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("NULL string (undefined behavior in real printf → many implement as \"(null)\")");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%s\n", (char *)NULL);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%s\n", (char *)NULL);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Long string (100 chars)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%s\n",
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%s\n",
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("%p  — Pointer");
	/* ─────────────────────────────────────────── */
 
	print_case("Valid pointer (address of a local var)");
	int x = 42;
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%p\n", (void *)&x);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%p\n", (void *)&x);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("NULL pointer (0x0)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%p\n", null_ptr);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%p\n", null_ptr);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Pointer to a string literal");
	const char *str = "test";
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%p\n", (void *)str);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%p\n", (void *)str);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("%d  — Signed decimal integer");
	/* ─────────────────────────────────────────── */
 
	print_case("Zero");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%d\n", 0);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%d\n", 0);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Positive number");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%d\n", 42);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%d\n", 42);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Negative number");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%d\n", -42);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%d\n", -42);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("INT_MAX (2147483647)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%d\n", INT_MAX);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%d\n", INT_MAX);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("INT_MIN (-2147483648) — DANGER: negating it overflows!");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%d\n", INT_MIN);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%d\n", INT_MIN);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("-1");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%d\n", -1);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%d\n", -1);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("%i  — Signed integer (same as %d)");
	/* ─────────────────────────────────────────── */
 
	print_case("42 via %%i");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%i\n", 42);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%i\n", 42);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("-42 via %%i");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%i\n", -42);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%i\n", -42);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("INT_MIN via %%i");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%i\n", INT_MIN);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%i\n", INT_MIN);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("%u  — Unsigned decimal");
	/* ─────────────────────────────────────────── */
 
	print_case("Zero");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%u\n", 0u);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%u\n", 0u);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("42");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%u\n", 42u);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%u\n", 42u);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("UINT_MAX (4294967295)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%u\n", UINT_MAX);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%u\n", UINT_MAX);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("-1 cast to unsigned (wraps to UINT_MAX)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%u\n", (unsigned int)-1);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%u\n", (unsigned int)-1);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("INT_MIN cast to unsigned");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%u\n", (unsigned int)INT_MIN);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%u\n", (unsigned int)INT_MIN);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("%x  — Hexadecimal lowercase");
	/* ─────────────────────────────────────────── */
 
	print_case("Zero → \"0\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%x\n", 0);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%x\n", 0);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("255 → \"ff\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%x\n", 255);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%x\n", 255);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("4294967295 (UINT_MAX) → \"ffffffff\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%x\n", UINT_MAX);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%x\n", UINT_MAX);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("-1 cast to unsigned → \"ffffffff\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%x\n", (unsigned int)-1);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%x\n", (unsigned int)-1);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("16 → \"10\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%x\n", 16);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%x\n", 16);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("%X  — Hexadecimal uppercase");
	/* ─────────────────────────────────────────── */
 
	print_case("255 → \"FF\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%X\n", 255);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%X\n", 255);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("UINT_MAX → \"FFFFFFFF\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%X\n", UINT_MAX);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%X\n", UINT_MAX);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Zero → \"0\"");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%X\n", 0);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%X\n", 0);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("%%  — Literal percent sign");
	/* ─────────────────────────────────────────── */
 
	print_case("Single %%");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%%\n");
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%%\n");
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("100%%");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("100%%\n");
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("100%%\n");
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("RETURN VALUE checks");
	/* ─────────────────────────────────────────── */
 
	print_case("Return value of a simple string");
	ret_orig = printf("hello");
	printf("\n");
	ret_ft = ft_printf("hello");
	printf("\n");
	printf("ret: orig=%d  ft=%d  (expected 5)\n", ret_orig, ret_ft);
 
	print_case("Return value of empty format string");
	ret_orig = printf("");
	ret_ft   = ft_printf("");
	printf("ret: orig=%d  ft=%d  (expected 0)\n", ret_orig, ret_ft);
 
	print_case("Return value with %%c null char (should be 1 for the char + \\n = 2)");
	ret_orig = printf("%c\n", '\0');
	ret_ft   = ft_printf("%c\n", '\0');
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("MIXED format strings");
	/* ─────────────────────────────────────────── */
 
	print_case("Multiple conversions in one call");
	printf    (GREEN "[printf]    " RESET);
	ret_orig = printf("char=%c str=%s dec=%d hex=%x ptr=%p\n",
		'Z', "42", -7, 255, (void *)&x);
	printf    (RED   "[ft_printf] " RESET);
	ret_ft   = ft_printf("char=%c str=%s dec=%d hex=%x ptr=%p\n",
		'Z', "42", -7, 255, (void *)&x);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("No conversion specifier (plain text)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("just text\n");
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("just text\n");
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Consecutive %% signs");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%%%%\n");
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%%%%\n");
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Mix of %%d and %%u around boundaries");
	printf    (GREEN "[printf]    " RESET);
	ret_orig = printf("INT_MAX=%d INT_MIN=%d UINT_MAX=%u\n",
		INT_MAX, INT_MIN, UINT_MAX);
	printf    (RED   "[ft_printf] " RESET);
	ret_ft   = ft_printf("INT_MAX=%d INT_MIN=%d UINT_MAX=%u\n",
		INT_MAX, INT_MIN, UINT_MAX);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	/* ─────────────────────────────────────────── */
	print_section("EDGE CASES that commonly break ft_printf");
	/* ─────────────────────────────────────────── */
 
	print_case("%%d with INT_MIN (the -2147483648 case)");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%d\n", INT_MIN);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%d\n", INT_MIN);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("%%u with value 0");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%u\n", 0);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%u\n", 0);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("%%x with value 0");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%x\n", 0);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%x\n", 0);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("%%X with value 0");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%X\n", 0);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%X\n", 0);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("%%p with NULL (many implementations print \"(nil)\" or \"0x0\")");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%p\n", (void *)0);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%p\n", (void *)0);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("%%s with NULL");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("%s\n", (char *)NULL);
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("%s\n", (char *)NULL);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	print_case("Only a newline");
	printf    (GREEN "[printf]    " RESET); ret_orig = printf("\n");
	printf    (RED   "[ft_printf] " RESET); ret_ft   = ft_printf("\n");
	printf("ret: orig=%d  ft=%d  (expected 1)\n", ret_orig, ret_ft);
 
	print_case("Multiple args same specifier back to back");
	printf    (GREEN "[printf]    " RESET);
	ret_orig = printf("%d%d%d\n", 1, 2, 3);
	printf    (RED   "[ft_printf] " RESET);
	ret_ft   = ft_printf("%d%d%d\n", 1, 2, 3);
	printf("ret: orig=%d  ft=%d\n", ret_orig, ret_ft);
 
	printf(BOLD "\n══════════════════════════════════════\n");
	printf("  END OF TESTS\n");
	printf("══════════════════════════════════════\n\n" RESET);
 
	return (0);
}