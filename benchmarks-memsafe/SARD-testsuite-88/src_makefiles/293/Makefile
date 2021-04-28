
all:	nxt-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

nxt-bad: nxt-bad.c 
	$(INSTRU_CC) -o nxt-bad nxt-bad.c -I . -lresolv

run: nxt-bad
	@/usr/bin/time $(INSTRU_BIN) ./nxt-bad > $<.output.txt 2> $<.error.txt
