#include "kiki_api.h"
#include <sys/types.h>

int kiki_device_init(kiki_handle_t **dev){}
/* de-initialize the device after use */
void kiki_device_deinit(kiki_handle_t *dev){}

/* utility functions to implement */
int kiki_device_fileno(kiki_handle_t *dev){}
int kiki_device_get_status(kiki_handle_t *dev, struct kiki_status *out){}
int kiki_device_clear_buffers(kiki_handle_t *dev){}

int kiki_count_buffers(kiki_handle_t *dev, size_t *amount){}
int kiki_list_buffers(kiki_handle_t *dev, kiki_buffer_handle_t ***buffers){}
void kiki_buffer_list_free(kiki_buffer_handle_t **buffers){}
int kiki_new_buffer(kiki_handle_t *dev, size_t size, kiki_buffer_handle_t **buffer){}

unsigned long kiki_buffer_id(kiki_buffer_handle_t *buffer){}
int kiki_buffer_size(kiki_buffer_handle_t *buffer, size_t *out){}
int kiki_buffer_inspect(kiki_buffer_handle_t *buffer, struct kiki_buffer_info *info){}

ssize_t kiki_write_buffer(kiki_buffer_handle_t *buffer, const char *data, size_t length){}
ssize_t kiki_read_buffer(kiki_buffer_handle_t *buffer, char *data, size_t length){}

int kiki_save_buffer(kiki_buffer_handle_t *buffer, FILE *output){}
int kiki_load_buffer(kiki_handle_t *dev, kiki_buffer_handle_t **out, FILE *input) {}