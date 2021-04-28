
all:	mime2-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

mime2-ok: mime2-ok.c
	$(INSTRU_CC) -o mime2-ok mime2-ok.c  -I .

run: mime2-ok
	@/usr/bin/time $(INSTRU_BIN) ./mime2-ok s4.in > $<.output.txt 2> $<.error.txt
