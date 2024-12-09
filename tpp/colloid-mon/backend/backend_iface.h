#ifndef COLLOID_BACKEND_IFACE_H
#define COLLOID_BACKEND_IFACE_H
/*
Interface for Colloid latency measurement backends
*/

#include <linux/types.h>

struct backend_config {
    int core;
};

int backend_init(struct backend_config* config);

int backend_destroy(void);

u64 backend_read_occupancy(int tier);

u64 backend_read_inserts(int tier);

#endif // COLLOID_BACKEND_IFACE_H
