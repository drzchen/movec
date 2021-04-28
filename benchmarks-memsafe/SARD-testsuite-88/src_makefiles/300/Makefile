
all:	ge-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

ge-ok: ge-ok.c  recipient.c  util.c
	$(INSTRU_CC) -o ge-ok ge-ok.c  recipient.c  util.c -I .

run: ge-ok
	@/usr/bin/time $(INSTRU_BIN) ./ge-ok > $<.output.txt 2> $<.error.txt

