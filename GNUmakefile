################################################################################
# Variables for the Ardunio.mk file.
ARDMK_DIR = vendor/arduino-mk

################################################################################
# Bring in various variables.
include mk/vars.mk

################################################################################
.PHONEY: all clean upload monitor

################################################################################
all:
	$(MAKE) -C src $@

################################################################################
clean:
	$(MAKE) -C src $@

################################################################################
upload:
	$(MAKE) -C src $@

################################################################################
monitor:
	@ echo "C-a C-x (to exit picocom)"
	picocom -r -b $(MONITOR_BAUDRATE) $(MONITOR_PORT)
