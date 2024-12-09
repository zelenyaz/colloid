obj-m   := colloid-mon.o
KDIR    := /lib/modules/$(shell uname -r)/build
KCONFIG_SCRIPTS := $(KDIR)/scripts/kconfig
PWD := $(shell pwd)

# Default parameters
# Note: do not add whitespace after parameter values
BACKEND ?= icx-native
DEFAULT_TIER ?= local-dram
ALTERNATE_TIER ?= remote-dram

# Frontend
colloid-mon-objs := frontend.o

# Select backend based on parameter
ifeq ($(BACKEND), icx-native)
	colloid-mon-objs += backend/icx-native.o
	ifneq ($(DEFAULT_TIER), local-dram)
    ifneq ($(DEFAULT_TIER), remote-dram)
        $(error Backend $(BACKEND) does not support tier $(DEFAULT_TIER).)
    endif
    endif
	ifneq ($(ALTERNATE_TIER), local-dram)
    ifneq ($(ALTERNATE_TIER), remote-dram)
        $(error Backend $(BACKEND) does not support tier $(ALTERNATE_TIER).)
    endif
    endif
else ifeq ($(BACKEND), clx-native)
	colloid-mon-objs += backend/clx-native.o
	ifneq ($(DEFAULT_TIER), local-dram)
    ifneq ($(DEFAULT_TIER), remote-dram)
        $(error Backend $(BACKEND) does not support tier $(DEFAULT_TIER).)
    endif
    endif
	ifneq ($(ALTERNATE_TIER), local-dram)
    ifneq ($(ALTERNATE_TIER), remote-dram)
        $(error Backend $(BACKEND) does not support tier $(ALTERNATE_TIER).)
    endif
    endif
else
	$(error Invalid backend: $(BACKEND).)
endif

# Configure default tier
ifeq ($(DEFAULT_TIER), local-dram)
EXTRA_CFLAGS += -DCOLLOID_CONFIG_DEFAULT_TIER_LOCAL_DRAM
else ifeq ($(DEFAULT_TIER), remote-dram)
EXTRA_CFLAGS += -DCOLLOID_CONFIG_DEFAULT_TIER_REMOTE_DRAM
else ifeq ($(DEFAULT_TIER), cxl)
EXTRA_CFLAGS += -DCOLLOID_CONFIG_DEFAULT_TIER_CXL
else
$(error Invalide default tier: $(TIER).)
endif

# Configure alternate tier
ifeq ($(ALTERNATE_TIER), local-dram)
EXTRA_CFLAGS += -DCOLLOID_CONFIG_ALTERNATE_TIER_LOCAL_DRAM
else ifeq ($(ALTERNATE_TIER), remote-dram)
EXTRA_CFLAGS += -DCOLLOID_CONFIG_ALTERNATE_TIER_REMOTE_DRAM
else ifeq ($(ALTERNATE_TIER), cxl)
EXTRA_CFLAGS += -DCOLLOID_CONFIG_ALTERNATE_TIER_CXL
else
$(error Invalide alternate tier: $(TIER).)
endif

all: 
	$(MAKE) -C $(KDIR) M=${PWD} SUBDIRS=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=${PWD} SUBDIRS=$(PWD) clean
# rm -f *.ko *.o *.mod *.mod.c modules.order Module.symvers test