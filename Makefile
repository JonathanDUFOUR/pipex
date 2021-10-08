# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 00:03:10 by jodufour          #+#    #+#              #
#    Updated: 2021/10/08 23:35:22 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	clang -c -o
LINK				=	clang -o
MKDIR				=	mkdir -p
RM					=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME				=	pipex

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	srcs/
OBJ_DIR				=	objs/
INC_DIR				=	
PRV_DIR				=	private/

FT_IO_DIR			=	libft_io/
FT_IO_INC_DIR		=	includes/
FT_IO_INC_DIR		:=	${addprefix ${FT_IO_DIR}, ${FT_IO_INC_DIR}}

FT_MEM_DIR			=	libft_mem/
FT_MEM_INC_DIR		=	includes/
FT_MEM_INC_DIR		:=	${addprefix ${FT_MEM_DIR}, ${FT_MEM_INC_DIR}}

FT_STRING_DIR		=	libft_string/
FT_STRING_INC_DIR	=	includes/
FT_STRING_INC_DIR	:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_MEM_A			=	libft_mem.a
FT_MEM_A			:=	${addprefix ${FT_MEM_DIR}, ${FT_MEM_A}}

FT_STRING_A			=	libft_string.a
FT_STRING_A			:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_A}}

FT_IO_A				=	libft_io.a
FT_IO_A				:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

######################################
#            SOURCE FILES            #
######################################
SRC					=	\
						${addprefix cmd/,				\
							px_cmd_clear.c				\
							px_cmd_name_get.c			\
							px_cmd_path_get.c			\
							px_cmd_print.c				\
						}								\
						${addprefix ctx/,				\
							px_ctx_clear.c				\
							px_ctx_get.c				\
							px_ctx_init.c				\
							px_ctx_print.c				\
						}								\
						main.c							\
						px_command_run.c				\
						px_err_msg.c					\
						px_file_content_get.c			\
						px_multi_close.c				\
						px_multi_fork.c					\
						px_multi_pipe.c					\
						px_path_get.c					\
						px_process_run.c

######################################
#            OBJECT FILES            #
######################################
OBJ					=	${SRC:.c=.o}
OBJ					:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP					=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS				=	-Wall -Wextra #-Werror
CFLAGS				+=	-MMD -MP
CFLAGS				+=	-I${PRV_DIR}
CFLAGS				+=	-I${FT_IO_INC_DIR}
CFLAGS				+=	-I${FT_MEM_INC_DIR}
CFLAGS				+=	-I${FT_STRING_INC_DIR}

LDFLAGS				=	-L${FT_IO_DIR} -lft_io
LDFLAGS				+=	-L${FT_MEM_DIR} -lft_mem
LDFLAGS				+=	-L${FT_STRING_DIR} -lft_string

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ} ${FT_IO_A} ${FT_MEM_A} ${FT_STRING_A}
	${LINK} $@ ${OBJ} ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

${FT_IO_A}:
	${MAKE} ${@F} -C ${@D}

${FT_MEM_A}:
	${MAKE} ${@F} -C ${@D}

${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}
ifeq (${REC}, 1)
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_MEM_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}
endif

re:	fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

.PHONY:	all clean fclean re coffee norm
