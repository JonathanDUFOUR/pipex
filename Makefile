# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 00:03:10 by jodufour          #+#    #+#              #
#    Updated: 2021/09/26 03:28:54 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC		=	clang -c -o
LINK	=	clang -o
MKDIR	=	mkdir -p
RM		=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME	=	pipex

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR	=	srcs/
OBJ_DIR	=	objs/
INC_DIR	=	
PRV_DIR	=	private/

#######################################
#              LIBRARIES              #
#######################################

######################################
#            SOURCE FILES            #
######################################
SRC		=	\
			${addprefix ctx/,	\
				px_ctx_clear.c	\
				px_ctx_get.c	\
				px_ctx_init.c	\
			}					\
			main.c				\
			px_err_msg.c

######################################
#            OBJECT FILES            #
######################################
OBJ		=	${SRC:.c=.o}
OBJ		:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP		=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS	=	-Wall -Wextra #-Werror
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-I${PRV_DIR}

LDFLAGS	=	

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ}
	${LINK} $@ $^ ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}

re:	fclean all

coffee:
	@echo         '                                              '
	@echo -e '\e[5m                   "   "                      \e[0m'
	@echo -e '\e[5m                  " " " "                     \e[0m'
	@echo -e '\e[5m                 " " " "                      \e[0m'
	@echo         '         _.-==="-"""""-"===-._                '
	@echo         '        |=___   "~"~"~"   ___=|=,.            '
	@echo         '        |    """======="""    |  \\           '
	@echo         '        |                     |   ||          '
	@echo         '        |                     |   ||          '
	@echo         '        |                     |   ||          '
	@echo         '        |                     |   ||          '
	@echo         '        |                     |  //           '
	@echo         '         \                   /=="`            '
	@echo         '          \                 /                 '
	@echo         '           `"--._______.--"`                  '
	@echo         '                                              '

norm:
	@norminette ${SRC_DIR} ${PRV_DIR} | grep 'Error' ; true

.PHONY:	all clean fclean re coffee norm
