CFLAGS = -I ./include
LFLAGS = -lrt -lX11 -lGLU -lGL -pthread -lm #-lXrandr

all: burger_dash


burger_dash: burger_dash.cpp log.cpp cmcdaniel.cpp cmcdaniel.h cestes.cpp cestes.h mjimenez.cpp mjimenez.h jbaltazarrob.cpp jbaltazarrob.h
	g++ $(CFLAGS) burger_dash.cpp cmcdaniel.cpp cestes.cpp mjimenez.cpp jbaltazarrob.cpp libggfonts.a -Wall -oburger_dash -lX11 -lGL -lGLU -lm -lc /usr/lib/x86_64-linux-gnu/libopenal.so \
    /usr/lib/x86_64-linux-gnu/libalut.so

clean:
	rm -f burger_dash

