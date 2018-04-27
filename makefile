.PHONY:all
all:clientpipe serverpipe
clientpipe:clientpipe.c
	gcc -o $@ $^
serverpipe:serverpipe.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f clientpipe serverpipe
