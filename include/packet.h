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

typedef struct
{
    char *data;
    size_t size;
    size_t read_pos;
    size_t send_pos;
    bool is_valid;
} packet_t;

packet_t *packet_create(void);

packet_t *packet_copy(const packet_t *packet);
void packet_destroy(packet_t *packet);
void packet_append(packet_t *packet, const void *data, size_t sizeInBytes);
void packet_clear(packet_t *packet);
const void *packet_get_data(const packet_t *packet);
size_t packet_get_data_size(const packet_t *packet);
bool packet_end_of_packet(const packet_t *packet);
bool packet_can_read(const packet_t *packet);

bool packet_read_bool(packet_t *packet);
int8_t packet_read_int8(packet_t *packet);
uint8_t packet_read_uint8(packet_t *packet);
int16_t packet_read_int16(packet_t *packet);
uint16_t packet_read_uint16(packet_t *packet);
int32_t packet_read_int32(packet_t *packet);
uint32_t packet_read_uint32(packet_t *packet);
float packet_read_float(packet_t *packet);
double packet_read_double(packet_t *packet);
void packet_read_string(packet_t *packet, char *string);
void packet_read_wide_string(packet_t *packet, wchar_t *string);

void packet_write_bool(packet_t *packet, bool);
void packet_write_int8(packet_t *packet, int8_t);
void packet_write_uint8(packet_t *packet, uint8_t);
void packet_write_int16(packet_t *packet, int16_t);
void packet_write_uint16(packet_t *packet, uint16_t);
void packet_write_int32(packet_t *packet, int32_t);
void packet_write_uint32(packet_t *packet, uint32_t);
void packet_write_float(packet_t *packet, float);
void packet_write_double(packet_t *packet, double);
void packet_write_string(packet_t *packet, const char *string);
void packet_write_wide_string(packet_t *packet, const wchar_t *string);

#endif /* !PACKET_H_ */
