CURR_DIR := $(shell pwd)
INC_DIR := $(CURR_DIR)/include
SRC_DIR := $(CURR_DIR)/src
TEST_SRC_DIR := $(CURR_DIR)/test
BUILD_DIR := $(CURR_DIR)/build

GCC=gcc
AR=ar
CFLAGS= -g -Wall -I$(SRC_DIR) -I$(INC_DIR)
