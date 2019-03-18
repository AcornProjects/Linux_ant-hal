###############################################################################
# 
# ANT Stack power library
# 
# Copyright 2019 Leikr
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# 
###############################################################################

LIB_VER = 1.0.0

TARGET_PLATFORM = am335x
LIB_NAME = libantradiopm
LIB_OUTPUT = $(LIB_NAME)_$(TARGET_PLATFORM).so.$(LIB_VER)
BIN_DIR = bin

CFLAGS = -g -c -fPIC -W -Wall -O2 -mcpu=cortex-a8 -Iinc \
         -I../common/inc \

LDFLAGS = -shared -Wl,-soname,$(LIB_OUTPUT)

SRC_FILES := am335x/antradiopm_am335x.c

OBJ_FILES = $(patsubst %.c, $(BIN_DIR)/obj/%.o, $(notdir $(SRC_FILES)))

VPATH = $(dir $(SRC_FILES))

$(LIB_OUTPUT) : build_dir $(OBJ_FILES)
	@echo "[$(CC)] => $(LIB_OUTPUT)"
	@$(CC) $(LDFLAGS) -o $(BIN_DIR)/$(LIB_OUTPUT) $(OBJ_FILES)
	@ln -sf $(LIB_OUTPUT) $(BIN_DIR)/$(LIB_NAME).so

$(BIN_DIR)/obj/%.o : %.c
	@echo "[$(CC)] <= $<"
	@$(CC) $(CFLAGS) $< -o $@

build_dir :
	@mkdir -p $(BIN_DIR)/obj

clean :
	@rm -rf $(BIN_DIR)

