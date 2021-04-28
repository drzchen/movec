
all:	crackaddr-ok

clean:
	@rm -f *-bad *-ok *.output.txt *.error.txt

crackaddr-ok: crackaddr-ok.c
	$(INSTRU_CC) -o crackaddr-ok crackaddr-ok.c

run: crackaddr-ok
	@/usr/bin/time $(INSTRU_BIN) ./crackaddr-ok < ./s1.in > $<.output.txt 2> $<.error.txt
