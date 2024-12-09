obj-m   := colloid-mon.o
KDIR    := /lib/modules/$(shell uname -r)/build
KCONFIG_SCRIPTS := $(KDIR)/scripts/kconfig
PWD := $(shell pwd)

# Default parameters
# Note: do not add whitespace after parameter values
BACKEND ?= icx-native

# Frontend
colloid-mon-objs := frontend.o

# Select backend based on parameter
ifeq ($(BACKEND), icx-native)
colloid-mon-objs += backend/icx-native.o
else ifeq ($(BACKEND), clx-native)
colloid-mon-objs += backend/clx-native.o
else
$(error Invalid backend: $(BACKEND). Supported values are: icx-native, clx-native.)
endif

all: 
	$(MAKE) -C $(KDIR) M=${PWD} SUBDIRS=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=${PWD} SUBDIRS=$(PWD) clean
# rm -f *.ko *.o *.mod *.mod.c modules.order Module.symvers test