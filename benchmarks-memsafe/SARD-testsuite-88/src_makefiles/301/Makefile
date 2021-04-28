
all:	mime1-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

mime1-bad: mime1-bad.c main.c 
	$(INSTRU_CC) -o mime1-bad mime1-bad.c main.c -I .

run: mime1-bad
	@/usr/bin/time $(INSTRU_BIN) ./mime1-bad s3.in > $<.output.txt 2> $<.error.txt
