################################################################################
# Variables for the Ardunio.mk file.
ARDMK_DIR      = ../../vendor/arduino-mk
USER_LIB_PATH  = $(realpath ../../lib)
CXXFLAGS       = -pedantic -Wall -Wextra -std=c++11

################################################################################
# ARDUINO_LIBS  = maxbotix

################################################################################
# Bring in various variables.
include ../../mk/vars.mk

################################################################################
# Bring in Ardunio Makefile.
include $(ARDMK_DIR)/Arduino.mk

################################################################################
# Bring in some extra targets.
include ../../mk/targets.mk
