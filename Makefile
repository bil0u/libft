# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upopee <upopee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:42:57 by upopee            #+#    #+#              #
#    Updated: 2018/02/14 00:14:15 by upopee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- VARIABLES --

# Name
NAME = libft.a

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

# Paths
SRC_DIR = sources
INC_DIR = includes
OBJ_DIR = .objects

VPATH =		$(MEMORY_DIR):$(CHAR_DIR):$(STR_DIR):$(WSTR_DIR):$(MATH_DIR):$(FT_PRINTF_DIR):$(LIST_DIR):$(RW_DIR)
INCLUDES =	$(MEMORY_INC) $(CHAR_INC) $(STR_INC) $(WSTR_INC) $(MATH_INC) $(FT_PRINTF_INC) $(LIST_INC) $(RW_INC)
OBJECTS =	$(MEMORY_OBJ) $(CHAR_OBJ) $(STR_OBJ) $(WSTR_OBJ) $(MATH_OBJ) $(FT_PRINTF_OBJ) $(LIST_OBJ) $(RW_OBJ)

# Sources files
MEMORY_DIR = memory/$(SRC_DIR)
MEMORY_INC = -I memory/$(INC_DIR)
MEMORY_SRC = $(patsubst %,$(MEMORY_DIR)/%,$(MEMORY_FILES:=.c))
MEMORY_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(MEMORY_FILES:=.o))
MEMORY_FILES =		ft_memalloc \
					ft_memdel \
					ft_memset \
					ft_revmemset \
					ft_bzero \
					\
					ft_memmove \
					ft_memcpy \
					ft_revmemcpy \
					ft_memccpy \
					ft_revmemccpy \
					ft_memchr \
					ft_revmemchr \
					ft_memcmp \
					ft_revmemcmp \

CHAR_DIR = characters/$(SRC_DIR)
CHAR_INC = -I characters/$(INC_DIR)
CHAR_SRC = $(patsubst %,$(CHAR_DIR)/%,$(CHAR_FILES:=.c))
CHAR_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(CHAR_FILES:=.o))
CHAR_FILES =		ft_isupper \
					ft_islower \
					ft_isalnum \
					ft_isalpha \
					ft_iswhitespace \
					ft_isascii \
					ft_isdigit \
					ft_ishexdigit \
					ft_isprint \
					ft_tolower \
					ft_toupper \

STR_DIR = strings/$(SRC_DIR)
STR_INC = -I strings/$(INC_DIR)
STR_SRC = $(patsubst %,$(STR_DIR)/%,$(STR_FILES:=.c))
STR_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(STR_FILES:=.o))
STR_FILES =			ft_strnew \
					ft_strdel \
					ft_strclr \
					ft_strlen \
					\
					ft_strcmp \
					ft_strncmp \
					ft_strequ \
					ft_strnequ \
					ft_nbwords \
					ft_wordlen \
					\
					ft_striter \
					ft_striteri \
					ft_strmap \
					ft_strmapi \
					\
					ft_strcat \
					ft_strncat \
					ft_strlcat \
					ft_strjoin \
					ft_strtrim \
					ft_strsplit \
					ft_strcpy \
					ft_strncpy \
					ft_strsub \
					ft_strstr \
					ft_strnstr \
					ft_strdup \
					ft_strndup \
					ft_strchr \
					ft_strrchr \
					ft_strtoupper \
					\
					ft_strisnumber \
					ft_strishex \
					\
					ft_nextws \

WSTR_DIR = wide_strings/$(SRC_DIR)
WSTR_INC = -I wide_strings/$(INC_DIR)
WSTR_SRC = $(patsubst %,$(WSTR_DIR)/%,$(WSTR_FILES:=.c))
WSTR_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(WSTR_FILES:=.o))
WSTR_FILES = 		ft_wcharlen \
					ft_wchar_to_str \
					ft_wchar_to_astr \
					\
					ft_wstrnew \
					ft_wstrdel \
					ft_wstrdup \
					ft_wstrncpy \
					ft_wstrlen \
					ft_wstrbyteslen \
					ft_wstr_to_str \
					ft_wstr_to_astr \

MATH_DIR = maths/$(SRC_DIR)
MATH_INC = -I maths/$(INC_DIR)
MATH_SRC = $(patsubst %,$(MATH_DIR)/%,$(MATH_FILES:=.c))
MATH_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(MATH_FILES:=.o))
MATH_FILES =		ft_atoi \
					ft_atoi_base \
					ft_atol \
					ft_atol_base \
					ft_itoa \
					ft_atoimax \
					ft_atoimax_base \
					\
					ft_itoa \
					ft_itoa_base \
					ft_ltoa \
					ft_ltoa_base \
					ft_imaxtoa \
					ft_imaxtoa_base \
					ft_nbrlen_base \
					ft_sqrt \
					ft_sqrt_next \
					ft_power \
					ft_pgcd \
					ft_swap \
					ft_factorl \

FT_PRINTF_DIR = ft_printf/$(SRC_DIR)
FT_PRINTF_INC = -I ft_printf/$(INC_DIR)
FT_PRINTF_SRC = $(patsubst %,$(FT_PRINTF_DIR)/%,$(FT_PRINTF_FILES:=.c))
FT_PRINTF_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(FT_PRINTF_FILES:=.o))
FT_PRINTF_FILES =	ft_printf \
					vararg_utils \
					handle_utils \
					numbers_utils \
					char_utils \
					float_utils_1 \
					float_utils_2 \
					\
					process_functions \
					\
					parse_flags_1 \
					parse_flags_2 \
					parse_width \
					parse_precision \
					parse_length_1 \
					parse_length_2 \
					\
					handle_char \
					handle_str \
					handle_numbers \
					handle_pointer \
					handle_float \
					handle_float_hex \
					handle_float_scientific \
					handle_float_auto \
					handle_others \

LIST_DIR = linked_lists/$(SRC_DIR)
LIST_INC = -I linked_lists/$(INC_DIR)
LIST_SRC = $(patsubst %,$(LIST_DIR)/%,$(LIST_FILES:=.c))
LIST_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(LIST_FILES:=.o))
LIST_FILES =		ft_lstnew \
					ft_lstdel \
					ft_lstdelone \
					ft_lstdelthis \
					ft_delcontent \
					\
					ft_lstadd \
					ft_lstappend \
					ft_lstmerge \
					ft_lstreverse \
					ft_lstiter \
					ft_lstforeach \
					ft_lstforeachif \
					ft_lstmap \
					ft_lstat \
					ft_lstlast \
					ft_lstfind \

RW_DIR = read_write/$(SRC_DIR)
RW_INC = -I read_write/$(INC_DIR)
RW_SRC = $(patsubst %,$(RW_DIR)/%,$(RW_FILES:=.c))
RW_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(RW_FILES:=.o))
RW_FILES =		get_next_line \
					\
					ft_putchar \
					ft_putchar_fd \
					ft_putnchar_fd \
					ft_putstr \
					ft_putstr_fd \
					ft_putendl \
					ft_putendl_fd \
					\
					ft_putwchart \
					ft_putwchart_fd \
					ft_putwstr \
					ft_putwstr_fd \
					ft_putnwstr_fd \
					ft_putnbyteswstr_fd \
					\
					ft_putnbits \
					ft_putnbits_fd \
					ft_putnbytes \
					ft_putnbytes_fd \
					\
					ft_putnbr \
					ft_putnbr_fd \

# Objects

# -- RULES --

all: prep $(NAME)

$(NAME):
	printf "> \e[31;33;1m$(NAME)\e[0m : \e[32mCreating objects\e[0m "
	make obj
	printf "\n"
	printf "> \e[31;33;1m$(NAME)\e[0m : \e[32mCreating Library\e[0m "
	ar rc $(NAME) $(OBJECTS)
	ar -s $(NAME)
	printf "\t\e[37;1m[\e[32;1mDONE\e[0m\e[37;1m]\e[0m\n"

obj: $(OBJECTS)
	echo >> /dev/null

$(OBJ_DIR)/%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
	printf "\e[32m.\e[0m"

clean:
	printf "> \e[31;33;1m$(NAME)\e[0m : \e[31mDeleting objects\e[0m "
	rm -rf $(OBJ_DIR)
	printf "\t\e[37;1m[\e[31;1mX\e[0m\e[37;1m]\e[0m\n"

fclean: clean
	printf "> \e[31;33;1m$(NAME)\e[0m : \e[31mDeleting binary\e[0m "
	rm -f $(NAME)
	printf "\t\e[37;1m[\e[31;1mX\e[0m\e[37;1m]\e[0m\n"

re: fclean all

lib: all clean

prep:
	mkdir -p $(OBJ_DIR)

# This rule allow the library build process to complete even if there are
# files named 'all, clean, fclean, re, lib' in the working directory

.PHONY: all obj clean fclean re lib prep

.SILENT: all obj clean fclean re lib prep $(NAME) $(OBJECTS)
