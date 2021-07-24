# Compila programas do curso de OpenGL no ambiente Linux
# Substitua nome_do_programa pelo nome do programa ...
# ...que se está trabalhando
#
# Antes das linhas que contém "gcc...", não pode haver espaço em
# branco e sim uma marca de tabulação
#
# Prof. Marco Antonio
#

# Variables
MESA = /softs/Mesa-6.0
INCPATH = -I$(MESA)/include
LIBPATH = -L$(MESA)/lib
LIBS        = -lglut -lGLU -lGL -lm
CFLAGS  = $(INCPATH) -g
LFLAGS  = $(LIBPATH) $(LIBS)

# Main targets
cubos4: cubos4.
    gcc -o cubos4 cubos4.o $(LFLAGS)

# Source targets
cubos4.o: cubos4.c
    gcc -c cubos4.c $(CFLAGS)

# Clean up
clean:
    rm -f *.o *~

realclean: 
    rm -f cubos4