INCLUDE = $(INCLUDE_NOPI)
LDFLAGS = $(LDFLAGS_NOPI)

INCLUDE_PI := -I ~/include
LDFLAGS_PI := -L ~/lib -lsense -lm
INCLUDE_NOPI :=
LDFLAGS_NOPI := -lncurses

all: clock

clock: main.o display.o
    cc -o $@ $^ $(LDFLAGS)

clean:
    rm -f *.o clock

run: all
    bash clock.sh | ./clock

main.o: main.c display.h
    cc -c $<
display.o: display.c display.h
    cc -o $@ -c $< $(INCLUDE)