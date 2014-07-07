##
## Makefile for test in /home/tang_j/malloc
## 
## Made by Jean Luc TANG
## Login   <tang_j@epitech.net>
## 
## Started on  Mon Jan 27 16:22:36 2014 Jean Luc TANG
## Last update Sun Apr  6 13:14:58 2014 Jean Luc TANG
##

CXX		=	g++

RM		=	rm -f

NAME		=	nibbler

NAME_NCURSES	=	lib_nibbler_ncurses.so

NAME_XLIB	=	lib_nibbler_xlib.so

NAME_SDL	=	lib_nibbler_sdl.so

CXXFLAGS	+=	-Wall -Werror -Wextra
CXXFLAGS	+=	-fPIC

LDFLAGS 	+=

SRCS_NCURSES	=	NCurses.cpp \
			Exception.cpp

OBJS_NCURSES	= 	$(SRCS_NCURSES:.cpp=.o)

SRCS_XLIB	=	Xlib.cpp \
			Exception.cpp

OBJS_XLIB	= 	$(SRCS_XLIB:.cpp=.o)

SRCS_SDL	=	SDL.cpp \
			Exception.cpp

OBJS_SDL	= 	$(SRCS_SDL:.cpp=.o)

SRCS		=	main.cpp \
			Snake.cpp \
			Body.cpp \
			Food.cpp \
			Exception.cpp \
			LoadGraph.cpp

OBJS		= 	$(SRCS:.cpp=.o)

all:	 		$(NAME) $(NAME_NCURSES) $(NAME_XLIB) $(NAME_SDL)

$(NAME):		$(OBJS)
			$(CXX) $(LDFLAGS) -ldl -o $(NAME) $(OBJS)

$(NAME_NCURSES):	$(OBJS_NCURSES)
			$(CXX) $(LDFLAGS) -shared -lncurses -o $(NAME_NCURSES) $(OBJS_NCURSES)

$(NAME_XLIB):		$(OBJS_XLIB)
			$(CXX) $(LDFLAGS) -shared -lX11 -o $(NAME_XLIB) $(OBJS_XLIB)

$(NAME_SDL):		$(OBJS_SDL)
			$(CXX) $(LDFLAGS) -shared -lSDL -lSDLmain -lSDL_image -o $(NAME_SDL) $(OBJS_SDL)

clean:
			$(RM) $(OBJS) $(OBJS_NCURSES) $(OBJS_XLIB) $(OBJS_SDL)

fclean:			clean
			$(RM) $(NAME) $(NAME_NCURSES) $(NAME_XLIB) $(NAME_SDL)

re: 			fclean all

.PHONY:			all clean fclean re
