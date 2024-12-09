#include "backend_iface.h"
#include <linux/kernel.h>

int backend_init(struct backend_config* config) {
    return 0;
}

int backend_destroy() {
    return 0;
}

u64 backend_read_occupancy(int tier) {
    return 0;
}

u64 backend_read_inserts(int tier) {
    return 0;
}