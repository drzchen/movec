
all:	ttflag-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

ttflag-bad:  my-main.c ttflag-bad.c
	$(INSTRU_CC) -o ttflag-bad my-main.c ttflag-bad.c -I .

run: ttflag-bad
	@/usr/bin/time $(INSTRU_BIN) ./ttflag-bad -d 4294967200-100 > $<.output.txt 2> $<.error.txt

