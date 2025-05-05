obj-m+=icc.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules -I .

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean