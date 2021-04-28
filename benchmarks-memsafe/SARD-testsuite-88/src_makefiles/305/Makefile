
all:	prescan-overflow-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

prescan-overflow-bad: prescan-overflow-bad.c
	$(INSTRU_CC) -o prescan-overflow-bad prescan-overflow-bad.c

run: prescan-overflow-bad
	@/usr/bin/time $(INSTRU_BIN) ./prescan-overflow-bad > $<.output.txt 2> $<.error.txt
