/*
Interface for Colloid latency measurement backends
*/

struct backend_config {
    int core;
};

int backend_init(struct backend_config* config);

int backend_destroy();

u64 backend_read_occupancy(int tier);

u64 backend_read_inserts(int tier);
