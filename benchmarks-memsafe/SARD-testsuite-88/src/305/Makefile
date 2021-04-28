
all:	prescan-overflow-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

prescan-overflow-bad: prescan-overflow-bad.c
	gcc -o prescan-overflow-bad prescan-overflow-bad.c

run: prescan-overflow-bad
	./prescan-overflow-bad > $<.output.txt 2> $<.error.txt
