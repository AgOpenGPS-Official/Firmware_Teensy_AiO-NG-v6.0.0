// SPDX-FileCopyrightText: 2024 Cesanta Software Limited
// SPDX-License-Identifier: GPL-2.0-only or commercial
// Generated by Mongoose Wizard, https://mongoose.ws/wizard/

// Include your device-specific headers, and edit functions below
// #include "hal.h"

#include "Arduino.h"
#include "mongoose_glue.h"

static struct settings s_settings = {"edit & save me", 1, 123.12345, false, 10, false, 1, 192, 168, 5, 126, "AiO GUI v5.12"};

void glue_init(void) {
  //MG_DEBUG(("Custom init done"));
}

// save
static uint64_t s_action_timeout_save;  // Time when save ends
bool glue_check_save(void) {
  return s_action_timeout_save > mg_now(); // Return true if save is in progress
}
void glue_start_save(void) {
  s_action_timeout_save = mg_now() + 1000; // Start save, finish after 1 second
  MG_DEBUG(("s_setting: %s,%d,%d,%d,%d,%d,%d", s_settings.fversion, s_settings.bd_ip1, s_settings.bd_ip2, s_settings.bd_ip3, s_settings.bd_ip4 ,s_settings.gps_sync, s_settings.gps_pass));
  save_config();
}

// reboot
static uint64_t s_action_timeout_reboot;  // Time when reboot ends
bool glue_check_reboot(void) {
  return s_action_timeout_reboot > mg_now(); // Return true if reboot is in progress
}
void glue_start_reboot(void) {
  s_action_timeout_reboot = mg_now() + 1000; // Start reboot, finish after 1 second
  SCB_AIRCR = 0x05FA0004;   // Teensy Reboot
}

// firmware_update
void  *glue_ota_begin_firmware_update(char *file_name, size_t total_size) {
  bool ok = mg_ota_begin(total_size);
  MG_DEBUG(("%s size %lu, ok: %d", file_name, total_size, ok));
  return ok ? (void *) 1 : NULL;
}
bool  glue_ota_end_firmware_update(void *context) {
  bool ok = mg_ota_end();
  MG_DEBUG(("ctx: %p, success: %d", context, ok));
  return ok;
}
bool  glue_ota_write_firmware_update(void *context, void *buf, size_t len) {
  MG_DEBUG(("ctx: %p %p/%lu", context, buf, len));
  return mg_ota_write(buf, len);
}

void glue_get_settings(struct settings *data) {
  *data = s_settings;  // Sync with your device
}
void glue_set_settings(struct settings *data) {
  s_settings = *data; // Sync with your device
}