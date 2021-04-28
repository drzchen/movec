
all:	prescan-overflow-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

prescan-overflow-ok: prescan-overflow-ok.c
	gcc -o prescan-overflow-ok prescan-overflow-ok.c

run: prescan-overflow-ok
	./prescan-overflow-ok > $<.output.txt 2> $<.error.txt
