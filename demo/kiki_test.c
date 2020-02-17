#include "kiki_api.h"

int main() {

  kiki_handle_t *handle;
  int r = kiki_device_init(&handle);
  printf("Init return: %d\n", r);

  struct kiki_status status;
  kiki_device_get_status(handle, &status);
  printf("Status %d: %s\n", status.status_no, status.status_msg);


  size_t count = 0;
  kiki_count_buffers(handle, &count);
  printf("Count %zu\n", count);

  kiki_device_deinit(handle);

  return 0;
}