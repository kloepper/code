include Makerules

# List of .cc files that are not scratch programs.
NOT_EXEC := link_error
EXEC := $(filter-out $(NOT_EXEC:=.cc), $(wildcard *.cc))
EXEC := $(EXEC:.cc=)
DEPS := $(EXEC:=.d) $(NOT_EXEC:=.d)

EXTRA_CLEAN_FILES := 

.PHONY: all
.PHONY: cln 
.PHONY: clean
all: $(EXEC)
cln: ; rm -f $(EXEC) *.o *.s *.csv
clean: cln ; rm -f *.d $(EXTRA_CLEAN_FILES)

net: CXXFLAGS += -std=c++11

# If a make goal is specified on the command line then build and run scratch 
# program.
ifneq ($(filter $(EXEC), $(MAKECMDGOALS)),)
$(MAKECMDGOALS) : $(MAKECMDGOALS:=.bin) ; ./$(@:.exec=) ; touch $(@:.exec=)
endif

ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEPS)
endif
