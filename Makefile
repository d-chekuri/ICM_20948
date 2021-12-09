USERFILE = user_file

obj-m := main.o
 
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	gcc -o $(USERFILE) $(USERFILE).c

kern:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

user:
	gcc -o $(USERFILE) $(USERFILE).c
	 
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	rm user_file
