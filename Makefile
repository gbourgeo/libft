# **************************************************************************** #
#                                                                              #
#                                                        :::   ::::::::        #
#   Makefile                                           :+:    :+:   :+:        #
#                                                    +:+ +:+         +:+       #
#   By: gbourgeo <gbourgeo@student.42.fr>        +#+  +:+      +#+             #
#                                                +#+#+#+#+#+   +#+             #
#   Created: 2013/11/20 18:41:05 by gbourgeo          #+#   #+#                #
#   Updated: 2020/11/18 20:05:42 by gbourgeo         ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = srcs/
SRC = ft_atoi.c ft_atol_base.c ft_atol.c ft_itoa_base.c ft_itoa.c             \
	ft_ltoa_base.c ft_ltoa.c ft_pow.c ft_toupper.c ft_tolower.c               \
	ft_bzero.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c   \
	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c            \
	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c           \
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c          \
	ft_split.c ft_split_whitespaces.c ft_str2join.c ft_strcdup.c              \
	ft_strcharset.c ft_stricpy.c ft_strndup.c ft_strrcdup.c ft_freestr.c      \
	ft_freetab.c ft_split_whitespaces.c ft_strtoupper.c ft_wstrlen.c          \
	get_next_line.c                                                           \
	ft_tabdup.c ft_tablen.c ft_tabdel.c                                       \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c          \
	ft_iswhitespace.c                                                         \
	ft_lstadd.c ft_lstaddend.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c        \
	ft_lstmap.c ft_lstnew.c ft_lstswap.c                                      \
	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c            \
	ft_memdel.c ft_memmove.c ft_memset.c                                      \
	ft_putbits.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c    \
	ft_putnbr_fd.c  ft_putnbr.c ft_putstr_fd.c ft_putstr.c  ft_puttab_fd.c    \
	ft_puttab.c ft_puttabc_fd.c ft_puttabc.c

PRINTF_DIR = ft_printf/
PRINTF_SRC = ft_printf.c
FPRINTF_SRC = ft_fprintf.c
DPRINTF_SRC = ft_dprintf.c
SPRINTF_SRC = ft_sprintf.c
SNPRINTF_SRC = ft_snprintf.c
VPRINTF_SRC = ft_vprintf.c
VDPRINTF_SRC = ft_vdprintf.c
PRINTF_BASE = pf_conversion_specifiers.c \
			pf_conversion_writers.c      \
			pf_conversion.c              \
			pf_data.c                    \
			pf_modifiers_parser.c        \
			pf_output.c                  \
			pf_parameter_table.c         \
			pf_routine.c                 \
			pf_specifiers_parser.c       \
			pf_wide_char.c
PRINTF_CONVERTERS_DIR = converters/
PRINTF_CONVERTERS = pf_c_big.c      \
			pf_c_small.c            \
			pf_di.c                 \
			pf_n.c                  \
			pf_o.c                  \
			pf_p.c                  \
			pf_s_big.c              \
			pf_s_small.c            \
			pf_u.c                  \
			pf_unhandled.c          \
			pf_x.c


UNIT_TESTS_DIR = unit_test/
UNIT_TEST_SRC = main.c

OBJ_DIR = obj/
OBJ_SRC	 = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(PRINTF_SRC:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(PRINTF_BASE:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(PRINTF_CONVERTERS:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(FPRINTF_SRC:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(DPRINTF_SRC:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(SPRINTF_SRC:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(SNPRINTF_SRC:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(VPRINTF_SRC:.c=.o))
OBJ_SRC += $(addprefix $(OBJ_DIR), $(VDPRINTF_SRC:.c=.o))
OBJ_UNIT_TEST = $(addprefix $(OBJ_DIR), $(UNIT_TEST_SRC:.c=.o))

DEPENDS = $(OBJ_SRC:.o=.d)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I $(INCLUDE_DIR)

INCLUDE_DIR = includes/

.PHONY: start clean fclean re test debug end

all: start $(NAME) end

start:
	@/bin/echo -n '[LIBFT] Compilation '
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_SRC) $(OBJ_PRINTF)
	@ar rc $@ $^
	@ranlib $@

# Include all .d files
-include $(DEPENDS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -MMD -o $@ -c $< $(INCLUDES) $(ENV)
	@/bin/echo -n "."

$(OBJ_DIR)%.o: $(PRINTF_DIR)%.c
	$(CC) $(CFLAGS) -MMD -o $@ -c $< $(INCLUDES) $(ENV)
	@/bin/echo -n "."

$(OBJ_DIR)%.o: $(PRINTF_DIR)$(PRINTF_CONVERTERS_DIR)%.c
	$(CC) $(CFLAGS) -MMD -o $@ -c $< $(INCLUDES) $(ENV)
	@/bin/echo -n "."

end:
	@/bin/echo " $(NAME)"

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@/bin/echo "[LIBFT] Objects erased."

fclean: clean
	@/bin/rm -f $(NAME) ./test
	@/bin/echo "[LIBFT] Librairy erased."

re: fclean all

$(OBJ_DIR)%.o: $(UNIT_TESTS_DIR)%.c
	$(CC) -o $@ -c $< $(INCLUDES)

test: all $(OBJ_UNIT_TEST)
	$(CC) $(CFLAGS) -o $@ $(OBJ_UNIT_TEST) -L. -lft

debug: ENV = -DPRINTF_DEBUG
debug: CFLAGS += -g -O0
debug: re
