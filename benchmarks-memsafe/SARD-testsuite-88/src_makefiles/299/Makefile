
all:	ge-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

ge-bad: ge-bad.c  recipient.c  util.c
	$(INSTRU_CC) -o ge-bad ge-bad.c  recipient.c  util.c -I .

run: ge-bad
	@/usr/bin/time $(INSTRU_BIN) ./ge-bad > $<.output.txt 2> $<.error.txt
