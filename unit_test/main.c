#include "libft.h"
#include <stdio.h>
#include <string.h>

static void test_table_received(char **received, const char **expected, const char *func_calling)
{
    if (received == NULL)
    {
        printf("ERROR [%s] table received is NULL\n", func_calling);
        return;
    }
    size_t tablen = ft_tablen((const char **)received);
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
    char ** table = ft_strsplit(str, caracter);
    test_table_received(table, expected, __func__);
    ft_freetab(&table);
}

static void test_split(const char *str, const char *charset, const char **expected)
{
    char ** table = ft_split(str, charset);
    test_table_received(table, expected, __func__);
    ft_freetab(&table);
}

static void test_split_whitespaces(const char *str, const char **expected)
{
    char ** table = ft_split_whitespaces(str);
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
    test_strsplit("  une table ronde ", ' ', (const char *[]){ "une", "table", "ronde", NULL });
    test_strsplit("unetableronde", ' ', (const char *[]){ "unetableronde", NULL });
    test_strsplit("             ", ' ', (const char *[]){ NULL });
    test_strsplit("", ' ', (const char *[]){ NULL });
    test_strsplit(NULL, ' ', (const char *[]){ NULL });

    printf("*** Tests ft_putstr\n");
    ft_putstr("Test 1\n");
    ft_putstr(NULL);

    printf("*** Tests ft_split\n");
    test_split(" \n\tun \n\tdos \n\ttres, \n\tole !\n", " \n\t", (const char *[]){ "un", "dos", "tres,", "ole", "!", NULL });
    test_split(" \n\t \n\t \n\t \n\t\n", " \n\t", (const char *[]){ NULL });
    test_split("coucou", " \n\t", (const char *[]){ "coucou", NULL });
    test_split("", "abcd", (const char *[]){ NULL });
    test_split(NULL, "abcd", (const char *[]){ NULL });

    printf("*** Tests ft_split_whitespaces\n");
    test_split_whitespaces(" \n\tun \n\tdos \n\ttres, \n\tole !\n", (const char *[]){ "un", "dos", "tres,", "ole", "!", NULL });

    printf("*** Tests ft_str2join\n");
    test_str2join("Hello, ", "What is", " your name ?");
    test_str2join("Hello, ", NULL, " your name ?");
    return 0;
}
