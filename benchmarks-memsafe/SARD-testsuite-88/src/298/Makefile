
all:	crackaddr-ok

clean:
	@rm -f *-bad *-ok *.output.txt *.error.txt

crackaddr-ok: crackaddr-ok.c
	gcc -o crackaddr-ok crackaddr-ok.c

run: crackaddr-ok
	./crackaddr-ok < ./s1.in > $<.output.txt 2> $<.error.txt
