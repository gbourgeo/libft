#include "ft_printf.h"
#include <errno.h>
#include <float.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#define FTPF_LDBL_BYTE5(x) ((short *)(&x))[4]

static void test_onearg(const char *format, long arg)
{
    int ret = 0;

    printf("[%-8s %4ld] Expected : ", format, arg);
    ret = printf(format, arg);
    printf(" | return value: %d", ret);
    (void) fflush(stdout);
    if (ret < 0)
    {
        perror(" :");
    }
    else
    {
        printf("\n");
    }
    printf("[%-8s %4ld] Received : ", format, arg);
    (void) fflush(stdout);
    ret = ft_printf(format, arg);
    printf(" | return value: %d\n", ret);
}

static void test_twoargs(const char *format, long arg_1, long arg_2)
{
    int ret = 0;

    printf("[%-8s %4ld %4ld] Expected : ", format, arg_1, arg_2);
    ret = printf(format, arg_1, arg_2);
    printf(" | return value: %d", ret);
    (void) fflush(stdout);
    if (ret < 0)
    {
        perror(" :");
    }
    else
    {
        printf("\n");
    }
    printf("[%-8s %4ld %4ld] Received : ", format, arg_1, arg_2);
    (void) fflush(stdout);
    ret = ft_printf(format, arg_1, arg_2);
    printf(" | return value: %d\n", ret);
}

static void test_threeargs(const char *format, int arg_1, int arg_2, int arg_3)
{
    int ret = 0;

    printf("[%-8s] Expected : ", format);
    ret = printf(format, arg_1, arg_2, arg_3);
    printf(" | return value: %d", ret);
    (void) fflush(stdout);
    if (ret < 0)
    {
        perror(" :");
    }
    else
    {
        printf("\n");
    }
    printf("[%-8s] Received : ", format);
    (void) fflush(stdout);
    ret = ft_printf(format, arg_1, arg_2, arg_3);
    printf(" | return value: %d\n", ret);
}

static void test_fiveargs(const char *format, int arg_1, int arg_2, int arg_3, int arg_4, int arg_5)
{
    int ret = 0;

    printf("[%-8s] Expected : ", format);
    ret = printf(format, arg_1, arg_2, arg_3, arg_4, arg_5);
    printf(" | return value: %d", ret);
    (void) fflush(stdout);
    if (ret < 0)
    {
        perror(" :");
    }
    else
    {
        printf("\n");
    }
    printf("[%-8s] Received : ", format);
    (void) fflush(stdout);
    ret = ft_printf(format, arg_1, arg_2, arg_3, arg_4, arg_5);
    printf(" | return value: %d\n", ret);
}

static void test_onearg_wstr(const char *format, const wchar_t *arg)
{
    int ret = 0;

    printf("[%-8s] Expected : ", format);
    ret = printf(format, arg);
    printf(" | return value: %d", ret);
    (void) fflush(stdout);
    if (ret < 0)
    {
        perror(" :");
    }
    else
    {
        printf("\n");
    }
    printf("[%-8s] Received : ", format);
    (void) fflush(stdout);
    ret = ft_printf(format, arg);
    printf(" | return value: %d\n", ret);
}

int main(void)
{
    setlocale(LC_ALL, "");
    int ret = 0;

    ret += printf("%..d\n", 42);
    ret += printf("%##x\n", 42);
    ret += printf("%*.*s\n", 15, 3, "hello world");
    ret += printf("%hd\n", 65535);
    ret += printf("%hhd\n", 65535);
    ret += printf("%hhhd\n", 65535);
    // ret += printf("%*.* %s %d\n", 3, 1, 12, "hello world", 7);

    printf("Test %%o cases:\n");
    ret += printf("%-8s: %o\n", "%o", 0);
    ret += printf("%-8s: %#o\n", "%#o", 0);
    ret += printf("%-8s: %0o\n", "%0o", 0);
    ret += printf("%-8s: %0o\n", "%0o", 9);
    ret += printf("%-8s: %.0o\n", "%.0o", 0);
    ret += printf("%-8s: %.0o\n", "%.0o", 9);
    ret += printf("%-8s: %.1o\n", "%.1o", 0);
    ret += printf("%-8s: %#.1o\n", "%#.1o", 0);
    ret += printf("%-8s: %.2o\n", "%.2o", 0);
    ret += printf("%-8s: %#.2o\n", "%#.2o", 0);
    ret += printf("%-8s: %o\n", "%o", 19);
    ret += printf("%-8s: %#o\n", "%#o", 19);
    ret += printf("%-8s: %.2o\n", "%.2o", 19);
    ret += printf("%-8s: %#.2o\n", "%#.2o", 19);
    ret += printf("%-8s: %.5o\n", "%.5o", 19);
    ret += printf("%-8s: %#.5o\n", "%#.5o", 19);
    ret += printf("%-8s: %10.2o\n", "%10.2o", 19);
    ret += printf("%-8s: %#10.2o\n", "%#10.2o", 19);
    ret += printf("%-8s: %10.5o\n", "%10.5o", 19);
    ret += printf("%-8s: %#10.5o\n", "%#10.5o", 19);
    ret += printf("%-8s: %010.5o\n", "%010.5o", 19);
    ret += printf("%-8s: %#010.5o\n", "%#010.5o", 19);
    ret += printf("%-8s: %10.05o\n", "%10.05o", 19);
    ret += printf("%-8s: %#10.05o\n", "%#10.05o", 19);

    printf("Test %%i cases:\n");
    ret += printf("%i\n", 0);
    ret += printf("%#i\n", 0);
    ret += printf("%i\n", 19);
    ret += printf("%#i\n", 19);
    ret += printf("%.2i\n", 19);
    ret += printf("%#.2i\n", 19);
    ret += printf("%.5i\n", 19);
    ret += printf("%#.5i\n", 19);
    ret += printf("%10.2i\n", 19);
    ret += printf("%#10.2i\n", 19);
    ret += printf("%10.5i\n", 19);
    ret += printf("%#10.5i\n", 19);

    printf("Test %%x cases:\n");
    test_onearg("%x", 0);
    test_onearg("%#x", 0);
    test_onearg("%0x", 0);
    test_onearg("%.0x", 0);
    test_onearg("%.1x", 0);
    test_onearg("%#.1x", 0);
    test_onearg("%.2x", 0);
    test_onearg("%#.2x", 0);
    test_onearg("%0x", 19);
    test_onearg("%.0x", 19);
    test_onearg("%x", 19);
    test_onearg("%#x", 19);
    test_onearg("%#5x", 65535);
    test_onearg("%.2x", 19);
    test_onearg("%#.2x", 19);
    test_onearg("%.5x", 19);
    test_onearg("%#.5x", 19);
    test_onearg("%10.2x", 19);
    test_onearg("%#10.2x", 19);
    test_onearg("%10.5x", 19);
    test_onearg("%#10.5x", 19);
    test_onearg("%010.5x", 19);
    test_onearg("%#010.5x", 19);
    test_onearg("%10.05x", 19);
    test_onearg("%#10.05x", 19);

    printf("Test %%p cases:\n");
    test_onearg("%.0p", 0);

    printf("Test modifiers:\n");
    test_onearg("%jx", 19);
    test_onearg("%jjjjjjx", 19);
    test_twoargs("%h*d", 12, 1);
    test_twoargs("%*hd", 12, 1);
    test_onearg("%w", 19);
    test_onearg("%jw", 19);

    test_onearg("Begining of ft_printf", 0);
    test_onearg("int: %d <-", 42);
    test_onearg("int: %d <-", -42);
    test_twoargs("int: %*d <-", 4, 42);
    test_onearg("not a conversion: %w", 42);
    test_onearg("not a conversion: %jw", 42);
    test_threeargs("int: %*.*d <-", 9, 6, 42);
    test_onearg("%7d", 42);
    test_onearg("%.0d", 0);
    test_onearg("%5.0d", 0);
    test_twoargs("%.*d", -2, 0);
    test_twoargs("%.*s", -2, (long) "coucou");
    test_onearg("%%", 0);
    test_onearg("%-05%", 0);
    test_onearg("%-05d", 42);
    test_onearg("%08.5i", 34);
    test_onearg("%010.5i", -216);
    test_onearg("%7X", 33);
    test_onearg("%#.0o", 0);
    test_onearg("%#.1o", 0);
    test_onearg("%#.2o", 0);
    test_onearg("%#.0o", 5);
    test_onearg("%#.1o", 5);
    test_onearg("%.5o", 21);
    test_onearg("%.05o", 21);
    test_onearg("%05o", 43);
    test_onearg("%#.5o", 21);
    test_onearg("%C", L'à');
    test_onearg("%C", 255);
    test_onearg("%C", 256);
    test_onearg("%s", (long) "abcd");
    test_onearg_wstr("%ls", L"@@");
    test_onearg_wstr("%ls", L"àà");
    test_onearg_wstr("%ls", L"aa");
    test_onearg_wstr("%ls", NULL);
    test_onearg("%s", (long) "à");
    test_onearg("%w", 0);
    test_onearg("%0$", 0);
    test_onearg("%1$", 0);
    test_onearg("%0$d", 0);
    test_twoargs("%-2$d", 0, 10);
    test_twoargs("%c%c", ' ', '!');
    test_fiveargs("%5$d %2$d %d", 1, 2, 3, 4, 5);
    test_threeargs("%i %i %1$i %i %i", 1, 2, 3);
    test_twoargs("%2$d", 0, 10);
    test_twoargs("DEBUT %7w %7s FIN", (long) "test_1", (long) "test_2");
    return 0;
}
