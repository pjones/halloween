################################################################################
# Random, helpful targets.  Needs vars.mk.

################################################################################
serial:
	@ echo "C-a C-x (to exit picocom)"
	picocom -r -b $(MONITOR_BAUDRATE) $(MONITOR_PORT)
