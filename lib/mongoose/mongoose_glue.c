// SPDX-FileCopyrightText: 2024 Cesanta Software Limited
// SPDX-License-Identifier: GPL-2.0-only or commercial
// Generated by Mongoose Wizard, https://mongoose.ws/wizard/

// Include your device-specific headers, and edit functions below
// #include "hal.h"

#include "mongoose_glue.h"

void glue_init(void) {
  MG_DEBUG(("Custom init done"));
}

// reboot
static uint64_t s_action_timeout_reboot;  // Time when reboot ends
bool glue_check_reboot(void) {
  return s_action_timeout_reboot > mg_now(); // Return true if reboot is in progress
}
void glue_start_reboot(void) {
  s_action_timeout_reboot = mg_now() + 1000; // Start reboot, finish after 1 second
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

// file_upload
void  *glue_file_open_file_upload(char *file_name, size_t total_size) {
  char path[128], *p = NULL;
  FILE *fp = NULL;
  if ((p = strrchr(file_name, '/')) == NULL) p = file_name;
  mg_snprintf(path, sizeof(path), "/tmp/%s", p);
#if MG_ENABLE_POSIX_FS
  fp = fopen(path, "w+b");
#endif
  MG_DEBUG(("opening [%s] size %lu, fp %p", path, total_size, fp));
  return fp;
}
bool  glue_file_close_file_upload(void *fp) {
  MG_DEBUG(("closing %p", fp));
#if MG_ENABLE_POSIX_FS
  return fclose((FILE *) fp) == 0;
#else
  return false;
#endif
}
bool  glue_file_write_file_upload(void *fp, void *buf, size_t len) {
  MG_DEBUG(("writing fp %p %p %lu bytes", fp, buf, len));
#if MG_ENABLE_POSIX_FS
  return fwrite(buf, 1, len, (FILE *) fp) == len;
#else
  return false;
#endif
}

static struct settings s_settings = {"edit & save me", 1, false, 10, false, 1, 123.12345, 192, 168, 5, 5.21};
void glue_get_settings(struct settings *data) {
  *data = s_settings;  // Sync with your device
}
void glue_set_settings(struct settings *data) {
  s_settings = *data; // Sync with your device
}