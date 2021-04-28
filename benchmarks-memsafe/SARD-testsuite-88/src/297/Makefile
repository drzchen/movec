
all:	crackaddr-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

crackaddr-bad: crackaddr-bad.c
	gcc -o crackaddr-bad crackaddr-bad.c

run: crackaddr-bad
	./crackaddr-bad < ./s1.in > $<.output.txt 2> $<.error.txt
