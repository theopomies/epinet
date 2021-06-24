/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** packet
*/

#ifndef PACKET_H_
#define PACKET_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum
{
    PACKET_ERROR = -1,
    PACKET_DONE,
    PACKET_PARTIAL,
    PACKET_END_OF_PACKET,
    PACKET_CORRUPTED,
} packet_status_t;

typedef struct
{
    char *data;
    size_t size;
    size_t read_pos;
} packet_t;

packet_t *packet_create(void);
packet_t *packet_copy(const packet_t *packet);

void packet_destroy(packet_t *packet);

packet_status_t packet_resize(packet_t *packet, size_t size);

packet_status_t packet_append(packet_t *packet, const void *data, size_t size);
packet_status_t packet_read(packet_t *packet, void *data, size_t size);
packet_status_t packet_clear(packet_t *packet);

const void *packet_get_data(const packet_t *packet);
size_t packet_get_data_size(const packet_t *packet);
bool packet_end_of_packet(const packet_t *packet);
bool packet_can_read(const packet_t *packet, size_t size_to_read);

//packet_status_t packet_read_bool(packet_t *packet, bool *);
packet_status_t packet_read_int8(packet_t *packet, int8_t *);
packet_status_t packet_read_uint8(packet_t *packet, uint8_t *);
packet_status_t packet_read_int16(packet_t *packet, int16_t *);
packet_status_t packet_read_uint16(packet_t *packet, uint16_t *);
packet_status_t packet_read_int32(packet_t *packet, int32_t *);
packet_status_t packet_read_uint32(packet_t *packet, uint32_t *);
//packet_status_t packet_read_float(packet_t *packet, float *);
//packet_status_t packet_read_double(packet_t *packet, double *);
packet_status_t packet_read_string(packet_t *packet, char **);
packet_status_t packet_read_string_until(
    packet_t *packet, char **data, const char *delim);

//packet_status_t packet_write_bool(packet_t *packet, bool);
packet_status_t packet_write_int8(packet_t *packet, int8_t);
packet_status_t packet_write_uint8(packet_t *packet, uint8_t);
packet_status_t packet_write_int16(packet_t *packet, int16_t);
packet_status_t packet_write_uint16(packet_t *packet, uint16_t);
packet_status_t packet_write_int32(packet_t *packet, int32_t);
packet_status_t packet_write_uint32(packet_t *packet, uint32_t);
//packet_status_t packet_write_float(packet_t *packet, float);
//packet_status_t packet_write_double(packet_t *packet, double);
packet_status_t packet_write_string(packet_t *packet, const char *);

#endif /* !PACKET_H_ */
