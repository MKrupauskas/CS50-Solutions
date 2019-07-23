#
# Makefile
#
# CS50 AP
# Leaks
#

leak0: leak0.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o leak0 leak0.c -lcs50 -lm

leak1: leak1.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o leak1 leak1.c -lcs50 -lm

leak2: leak2.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o leak2 leak2.c -lcs50 -lm

leaks: leak0 leak1 leak2

clean:
	rm -f *.o a.out core leak0 leak1 leak2