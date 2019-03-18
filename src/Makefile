###############################################################################
# 
# ANT Stack
# 
# Copyright 2012 Dynastream Innovations
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

LIB_VER = 1.9.11

LIB = libantradio.so
BIN_DIR = bin

CFLAGS = -g -c -fPIC -W -Wall -O2 -D_POSIX_SOURCE -mcpu=cortex-a8 \
   -Icommon/inc -Ibluez_hci/inc -Iant_power/inc \
   -DBOARD_ANT_DEVICE_WILINK \
   -DBOARD_ANT_DEVICE_WL12XX \
   -DUSE_EXTERNAL_POWER_LIBRARY

LDFLAGS = -shared -Wl,-soname,$(LIB).$(LIB_VER) -Lant_power/bin -lantradiopm

SRC_FILES := \
  common/ant_utils.c \
  bluez_hci/ant_native_hci.c \
  bluez_hci/ant_rx.c \
  bluez_hci/ant_tx.c \


OBJ_FILES = $(patsubst %.c, $(BIN_DIR)/obj/%.o, $(notdir $(SRC_FILES)))

VPATH = $(dir $(SRC_FILES))

$(LIB).$(LIB_VER) : build_dir $(OBJ_FILES)
	@echo "[$(CC)] => $(LIB).$(LIB_VER)"
	@$(CC) $(LDFLAGS) -o $(BIN_DIR)/$(LIB).$(LIB_VER) $(OBJ_FILES)
	@ln -sf $(LIB).$(LIB_VER) $(BIN_DIR)/$(LIB)

$(BIN_DIR)/obj/%.o : %.c
	@echo "[$(CC)] <= $<"
	@$(CC) $(CFLAGS) $< -o $@

build_dir :
	@mkdir -p $(BIN_DIR)/obj

clean :
	@rm -rf $(BIN_DIR)

