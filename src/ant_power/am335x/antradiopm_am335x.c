/*
 * ANT Stack power library
 *
 * Copyright 2019 Leikr
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
 #include "antradio_power.h"

#include "ant_log.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

static int enabled_status = 0;

int ant_enable(void)
{
   int ret = -1;
   ANT_FUNC_START();

   if (ant_is_enabled() == 1) { // Already running (re-enable)
      return 0;
   }
   ret = system("hciconfig hci0 up");
   if (ret < 0) {
      ANT_ERROR("hciconfig hci0 up failed: %s", strerror(errno));
      goto out;
   }
   sleep(1);
   ret = system("hciconfig hci0 noscan");
   if (ret < 0) {
      ANT_ERROR("hciconfig hci0 noscan failed: %s", strerror(errno));
      goto out;
   }
   
   enabled_status = 1;
   
out:
   ANT_FUNC_END();
   return ret;
}

int ant_disable(void)
{
   int ret = -1;
   ANT_FUNC_START();

   if (ant_is_enabled() == 0) { // Not running (re-disable)
      return 0;
   }
   ret = system("hciconfig hci0 down");
   if (ret < 0) {
      ANT_ERROR("hciconfig hci0 down failed: %s", strerror(errno));
      goto out;
   }
   
   enabled_status = 0;

out:
   ANT_FUNC_END();
   return ret;
}

int ant_is_enabled(void)
{
   return enabled_status;
}
