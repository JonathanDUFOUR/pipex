# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 00:03:10 by jodufour          #+#    #+#              #
#    Updated: 2022/10/29 07:23:54 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	clang
LINK				=	clang
MKDIR				=	mkdir -p
RM					=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME				=	pipex.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	srcs
OBJ_DIR				=	objs
PRV_DIR				=	private

FT_IO_DIR			=	libft_io
FT_IO_INC_DIR		=	include
FT_IO_INC_DIR		:=	${addprefix ${FT_IO_DIR}/, ${FT_IO_INC_DIR}}

FT_STRING_DIR		=	libft_string
FT_STRING_INC_DIR	=	include
FT_STRING_INC_DIR	:=	${addprefix ${FT_STRING_DIR}/, ${FT_STRING_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A				=	libft_io.a
FT_IO_A				:=	${addprefix ${FT_IO_DIR}/, ${FT_IO_A}}

FT_STRING_A			=	libft_string.a
FT_STRING_A			:=	${addprefix ${FT_STRING_DIR}/, ${FT_STRING_A}}

######################################
#            SOURCE FILES            #
######################################
SRC					=	\
						${addprefix pid/,			\
							${addprefix lst/,		\
								pid_lst_add_back.c	\
								pid_lst_clear.c		\
								pid_lst_push_back.c	\
								pid_lst_wait.c		\
							}						\
							pid_new.c				\
							pid_wait.c				\
						}							\
						get_env.c					\
						main.c						\
						pipeline_iterative.c		\
						pipeline_recursive.c		\
						redirect.c					\
						run.c						\
						str3join.c

######################################
#            OBJECT FILES            #
######################################
OBJ					=	${SRC:.c=.o}
OBJ					:=	${addprefix ${OBJ_DIR}/, ${OBJ}}

DEP					=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS				=	-c
CFLAGS				+=	-Wall -Wextra -Werror
CFLAGS				+=	-MMD -MP
CFLAGS				+=	-I${PRV_DIR}
CFLAGS				+=	-I${FT_IO_INC_DIR}
CFLAGS				+=	-I${FT_STRING_INC_DIR}

LDFLAGS				=	-L${FT_IO_DIR} -lft_io
LDFLAGS				+=	-L${FT_STRING_DIR} -lft_string

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
.PHONY: all clean fclean re fre

${NAME}: ${OBJ} ${FT_IO_A} ${FT_STRING_A}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKDIR} ${@D}
	${CC} $< ${CFLAGS} ${OUTPUT_OPTION}

${FT_IO_A} ${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}

re: clean all

fre: fclean all

-include ${HOME}/Templates/mk_files/coffee.mk
-include ${HOME}/Templates/mk_files/norm.mk
