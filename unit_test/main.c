#include "ft_printf.h"
#include "ft_snprintf.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

static int test_returned_values(
    const char *format,
    int         ret_expe,
    int         ret_recv,
    const char *buff_expe,
    const char *buff_recv)
{
    int ret = 0;
    if (ret_expe != ret_recv)
    {
        printf("ERROR: return value from test (%s) :\n"
               "\tExpected: %d\n"
               "\tReceived: %d\n",
               format,
               ret_expe,
               ret_recv);
        ret = 1;
    }
    if (strcmp(buff_expe, buff_recv) != 0)
    {
        printf("ERROR: buffer value from test (%s) :\n"
               "\tExpected: \"%s\"\n"
               "\tReceived: \"%s\"\n",
               format,
               buff_expe,
               buff_recv);
        ret = 1;
    }
    return ret;
}

static int test_expression(const char *format, long value)
{
    char exp_buff[1024];
    char rec_buff[1024];
    int  exp_ret = snprintf(exp_buff, sizeof(exp_buff), format, value);
    int  rec_ret = ft_snprintf(rec_buff, sizeof(rec_buff), format, value);

    return test_returned_values(format, exp_ret, rec_ret, exp_buff, rec_buff);
}

static int test_width(const char *format, long width, long value)
{
    char exp_buff[1024];
    char rec_buff[1024];
    int  exp_ret = snprintf(exp_buff, sizeof(exp_buff), format, width, value);
    int  rec_ret = ft_snprintf(rec_buff, sizeof(rec_buff), format, width, value);

    return test_returned_values(format, exp_ret, rec_ret, exp_buff, rec_buff);
}

static void test_table_received(char **received, const char **expected, const char *func_calling)
{
    if (received == NULL)
    {
        printf("ERROR [%s] table received is NULL\n", func_calling);
        return;
    }
    size_t tablen = ft_tablen((const char **) received);
    size_t explen = ft_tablen(expected);
    if (tablen != explen)
    {
        printf("ERROR [%s] tables length different:\n", func_calling);
        printf("\tReceived: %zu\n", tablen);
        printf("\tExpected: %zu\n", explen);
    }
    size_t iter = 0;
    while (received[iter] != NULL && expected[iter] != NULL)
    {
        if (ft_strcmp(received[iter], expected[iter]) != 0)
        {
            printf("ERROR [%s] fields #%zu are different:\n", func_calling, iter);
            printf("\tReceived: %s\n", received[iter]);
            printf("\tExpected: %s\n", expected[iter]);
        }
        iter++;
    }
}

static void test_string_received(char *received, const char *expected, size_t len, const char *func_calling)
{
    if (ft_strncmp(received, expected, len) != 0)
    {
        printf("ERROR [%s] strings are different (ft_strncmp)\n", func_calling);
        printf("\tReceived: %s\n", received);
        printf("\tExpected: %s\n", expected);
    }
    if (strncmp(received, expected, len) != 0)
    {
        printf("ERROR [%s] strings are different (strncmp)\n", func_calling);
        printf("\tReceived: %s\n", received);
        printf("\tExpected: %s\n", expected);
    }
}

/********************************************************************************
 * DEBUT DES TEST
 ********************************************************************************/
static void test_strsplit(const char *str, char caracter, const char **expected)
{
    char **table = ft_strsplit(str, caracter);
    test_table_received(table, expected, __func__);
    ft_freetab(&table);
}

static void test_split(const char *str, const char *charset, const char **expected)
{
    char **table = ft_split(str, charset);
    test_table_received(table, expected, __func__);
    ft_freetab(&table);
}

static void test_split_whitespaces(const char *str, const char **expected)
{
    char **table = ft_split_whitespaces(str);
    test_table_received(table, expected, __func__);
    ft_freetab(&table);
}

static void test_str2join(const char *str1, const char *str2, const char *str3)
{
    char *str = ft_str2join(str1, str2, str3);
    if (str == NULL)
    {
        printf("%s: ERROR string received is NULL\n", __func__);
        return;
    }
    size_t len1 = ft_strlen(str1);
    test_string_received(str, str1, len1, __func__);
    size_t len2 = ft_strlen(str2);
    test_string_received(str + len1, str2, len2, __func__);
    size_t len3 = ft_strlen(str3);
    test_string_received(str + len1 + len2, str3, len3, __func__);
    ft_freestr(&str);
}

int main(void)
{
    printf("********* Starting unit testing the LIBFT *********\n");

    printf("*** Tests ft_strsplit\n");
    test_strsplit("  une table ronde ", ' ', (const char *[]) { "une", "table", "ronde", NULL });
    test_strsplit("unetableronde", ' ', (const char *[]) { "unetableronde", NULL });
    test_strsplit("             ", ' ', (const char *[]) { NULL });
    test_strsplit("", ' ', (const char *[]) { NULL });
    test_strsplit(NULL, ' ', (const char *[]) { NULL });

    printf("*** Tests ft_putstr\n");
    ft_putstr("Test 1\n");
    ft_putstr(NULL);

    printf("*** Tests ft_split\n");
    test_split(" \n\tun \n\tdos \n\ttres, \n\tole !\n", " \n\t", (const char *[]) { "un", "dos", "tres,", "ole", "!", NULL });
    test_split(" \n\t \n\t \n\t \n\t\n", " \n\t", (const char *[]) { NULL });
    test_split("coucou", " \n\t", (const char *[]) { "coucou", NULL });
    test_split("", "abcd", (const char *[]) { NULL });
    test_split(NULL, "abcd", (const char *[]) { NULL });

    printf("*** Tests ft_split_whitespaces\n");
    test_split_whitespaces(" \n\tun \n\tdos \n\ttres, \n\tole !\n", (const char *[]) { "un", "dos", "tres,", "ole", "!", NULL });

    printf("*** Tests ft_str2join\n");
    test_str2join("Hello, ", "What is", " your name ?");
    test_str2join("Hello, ", NULL, " your name ?");

    printf("*** Tests ft_printf\n");

    printf("Expected: %..d.\n", -216);
    ft_printf("Received: %..d.\n", -216);

    printf("Expected: %10.5d.\n", -216);
    ft_printf("Received: %10.5d.\n", -216);
    printf("Expected: %010.5d.\n", -216);
    ft_printf("Received: %010.5d.\n", -216);
    printf("Expected: %07d.\n", -54);
    ft_printf("Received: %07d.\n", -54);
    printf("Expected: %02.3d.\n", -54);
    ft_printf("Received: %02.3d.\n", -54);
    printf("Expected: %.*d.\n", -10, 12345);
    ft_printf("Received: %.*d.\n", -10, 12345);
    printf("Expected: %.*d.\n", -5, 12345);
    ft_printf("Received: %.*d.\n", -5, 12345);
    printf("Expected: %.*d.\n", -1, 12345);
    ft_printf("Received: %.*d.\n", -1, 12345);
    printf("Expected: %.*d.\n", -1, 0);
    ft_printf("Received: %.*d.\n", -1, 0);
    printf("Expected: %.*s.\n", -3, (char *) 0);
    ft_printf("Received: %.*s.\n", -3, (char *) 0);
    printf("Expected: %.*s.\n", -1, (char *) 0);
    ft_printf("Received: %.*s.\n", -1, (char *) 0);
    printf("Expected: %.*s.\n", 0, (char *) 0);
    ft_printf("Received: %.*s.\n", 0, (char *) 0);
    printf("Expected:%*s.\n", -32, "abc");
    ft_printf("Received:%*s.\n", -32, "abc");
    printf("Expected:%-*s.\n", -32, "abc");
    ft_printf("Received:%-*s.\n", -32, "abc");
    printf("Expected:%*s.\n", -3, "hello");
    ft_printf("Received:%*s.\n", -3, "hello");
    printf("Expected:%-*.*s.\n", -7, -3, "yolo");
    ft_printf("Received:%-*.*s.\n", -7, -3, "yolo");
    printf("Expected:%*i.\n", -4, 94827);
    ft_printf("Received:%*i.\n", -4, 94827);
    printf("Expected:%*i.\n", -14, 94827);
    ft_printf("Received:%*i.\n", -14, 94827);
    printf("Expected:%0*i.\n", -7, -54);
    ft_printf("Received:%0*i.\n", -7, -54);
    printf("Expected: %#x.\n", 125);
    ft_printf("Received: %#x.\n", 125);
    ft_printf("Received: %#x.\n", 125);
    printf("Expected: %-#10.5x.\n", 125);
    ft_printf("Received: %-#10.5x.\n", 125);
    printf("Expected: %#10.5x.\n", 125);
    ft_printf("Received: %#10.5x.\n", 125);
    printf("Expected: %x.\n", 4294967295u);
    ft_printf("Received: %x.\n", 4294967295u);
    printf("Expected: %lls.\n", "hello");
    ft_printf("Received: %lls.\n", "hello");
    printf("%.7s.\n", "hello");
    ft_printf("%.7s.\n", "hello");
    printf("%.3s.\n", "hello");
    ft_printf("%.3s.\n", "hello");
    printf("%.*i.\n", -6, -3);
    ft_printf("%.*i.\n", -6, -3);

    for (int i = -300; i < 300; i++)
    {
        if (test_expression("%o", i) != 0)
        {
            return 1;
        }
    }
    test_expression("%o", INT16_MIN);
    test_expression("%o", INT16_MAX);
    test_expression("%o", INT32_MIN);
    test_expression("%o", INT32_MAX);
    test_expression("%o", INT64_MIN);
    test_expression("%o", INT64_MAX);

    test_expression("%-1o", 1);
    char format[32];
    for (long width = INT16_MIN; width < INT16_MAX; width++)
    {
        snprintf(format, sizeof(format), "%%%do", width);
        if (test_width(format, width, 1) != 0)
        {
            return 1;
        }
    }
    test_expression("%-2147483647o", 1);
    test_expression("%-2147483647o", -1);
    return 0;
}
