# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 01:43:02 by bloisel           #+#    #+#              #
#    Updated: 2024/03/05 17:47:42 by bloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFTNAME = libft.a

CFLAGS =  
DEBUG = -g -O0


SRCS = srcs/main.c \
	   srcs/input.c \
	   srcs/s.quote.c \
	   srcs/utils.c

OBJS = $(SRCS:.c=.o)

LIBFTPATH = lib/

all: header $(NAME)

header: 
	@echo "    __  ________   ___________ __  __________    __ "
	@echo "   /  |/  /  _/ | / /  _/ ___// / / / ____/ /   / / "
	@echo "  / /|_/ // //  |/ // / \__ \/ /_/ / __/ / /   / /   "
	@echo " / /  / // // /|  // / ___/ / __  / /___/ /___/ /___ "
	@echo "/_/  /_/___/_/ |_/___//____/_/ /_/_____/_____/_____/ "
	@echo "                                                   	"
	@echo	"+++-++-++-++-++-++-++-+ +-+ +-++-++-++-++-++-++-+"
	@echo "|a||y||a||s||s||a||y||e| |x| |b||l||o||i||s||e||l|"
	@echo "+-++-++-++-++-++-++-++-+ +-+ +-++-++-++-++-++-++-+"

	
.c.o:
	@echo "\033[0m${_BOLD}${_BLUE}.C to > .O :${_YELLOW} ${<:.c=.o} ${_END}"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 


$(NAME): $(OBJS)
	@echo	"${_BOLD}${_BLUE}Make de : ${_BOLD}${_YELLOW}$(NAME) $(LIBFNAME) ${_END}"
	@make -C $(LIBFTPATH)
	@echo	"${_BOLD}${_GREEN}Done 🙈${_END}"
	@echo "${_BOLD}${_BLUE}Depacement des *.a to ./${_END}"
	@mv $(LIBFTPATH)$(LIBFTNAME) ./
	@echo "${_BOLD}${_GREEN}Done 🙈${_END}"
	@echo "${_BOLD}${_BLUE}Comilation ...${_END}"
	@${CC} ${CFLAGS} $(OBJS) $(LIBFTNAME) -o $(NAME) -lreadline
	@echo "${_BOLD}${_GREEN}Done 🙈${_END}"

clean: header
	@echo "${_BOLD}${_RED}rm *.o${_END}"
	@rm -rf *.o
	@echo "${_BOLD}${_GREEN}Done${_END}"

fclean: header clean
	@echo "${_BOLD}${_RED}fclean de : ${_YELLOW}libft ${_END}"
	@make fclean -C $(LIBFTPATH)
	@echo "${_BOLD}${_GREEN}Done 🦊${_END}"
	@echo "${_BOLD}${_RED}rm de : ${_YELLOW} $(LIBFTNAME) $(OBJS) $(NAME) ${_END}"
	@rm -rf $(LIBFTNAME) $(OBJS) $(NAME)
	@echo	"${_BOLD}${_GREEN}Done 🦊${_END}"
	@echo "${_PURPLE}\033[3mIt Seems ... This is going great 👍"

fclean_all: clean
	rm -rf $(LIBFTNAME) $(OBJS) $(NAME)

re: fclean all

ree: fclean all

# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m
