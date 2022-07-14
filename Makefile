  1 INCLUDE = $(INCLUDE_NOPI)
  2 LDFLAGS = $(LDFLAGS_NOPI)
  3
  4 INCLUDE_PI := -I ~/include
  5 LDFLAGS_PI := -L ~/lib -lsense -lm
  6 INCLUDE_NOPI :=
  7 LDFLAGS_NOPI := -lncurses
  8
  9 all: clock
 10
 11 clock: main.o display.o
 12     cc -o $@ $^ $(LDFLAGS)
 13
 14 clean:
 15     rm -f *.o clock
 16
 17 run: all
 18     bash clock.sh | ./clock
 19
 20 main.o: main.c display.h
 21     cc -c $<
 22 display.o: display.c display.h
 23     cc -o $@ -c $< $(INCLUDE)