
all:	mime2-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

mime2-bad: mime2-bad.c
	$(INSTRU_CC) -o mime2-bad mime2-bad.c  -I .

run: mime2-bad
	@/usr/bin/time $(INSTRU_BIN) ./mime2-bad s4.in > $<.output.txt 2> $<.error.txt
