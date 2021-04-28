
all:	mime1-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

mime1-ok: mime1-ok.c main.c
	$(INSTRU_CC) -o mime1-ok mime1-ok.c main.c -I .

run: mime1-ok
	@/usr/bin/time $(INSTRU_BIN) ./mime1-ok s3.in > $<.output.txt 2> $<.error.txt
