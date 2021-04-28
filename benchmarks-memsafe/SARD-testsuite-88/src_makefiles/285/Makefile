
all:	call-realpath-bad

clean:	
	@rm -f *-bad *.output.txt *.error.txt

call-realpath-bad: call-realpath-bad.c realpath-2.4.2.c
	$(INSTRU_CC) -o call-realpath-bad call-realpath-bad.c realpath-2.4.2.c

run: call-realpath-bad
	@/usr/bin/time $(INSTRU_BIN) ./call-realpath-bad /aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa > $<.output.txt 2> $<.error.txt

