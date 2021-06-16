/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** test_packet
*/

#include <criterion/criterion.h>
#include <packet.h>

Test(packet_append, success)
{
    packet_t *p = packet_create();

    cr_assert(packet_append(p, "Hello", 6) == PACKET_DONE);
    cr_assert(!memcmp(p->data, "Hello", 6));
    cr_assert(packet_append(p, " World", 7) == PACKET_DONE);
    cr_assert(!memcmp(p->data, "Hello\0 World", 13));
    cr_assert(packet_clear(p) == PACKET_DONE);
    cr_assert(packet_append(p, "Cleared", 8) == PACKET_DONE);
    cr_assert(!memcmp(p->data, "Cleared", 8));
    packet_destroy(p);
}

Test(packet_can_read, success)
{
    packet_t *p = packet_create();

    cr_assert(packet_append(p, "Hello", 6) == PACKET_DONE);
    cr_assert(!memcmp(p->data, "Hello", 6));
    cr_assert(packet_can_read(p, 0));
    cr_assert(packet_can_read(p, 1));
    cr_assert(packet_can_read(p, 5));
    cr_assert(packet_can_read(p, 6));
    cr_assert(!packet_can_read(p, 7));
    p->read_pos = 1;
    cr_assert(packet_can_read(p, 5));
    cr_assert(!packet_can_read(p, 6));
    p->read_pos = 5;
    cr_assert(packet_can_read(p, 1));
    cr_assert(!packet_can_read(p, 2));
    packet_destroy(p);
}

Test(packet_can_read, int8)
{
    packet_t *p = packet_create();
    int8_t data = 12;

    cr_assert(packet_read_int8(p, &data) != PACKET_DONE);
    cr_assert(packet_write_int8(p, data) == PACKET_DONE);
    data = 24;
    cr_assert(packet_write_int8(p, data) == PACKET_DONE);
    cr_assert(packet_write_int8(p, data) == PACKET_DONE);
    cr_assert(packet_read_int8(p, &data) == PACKET_DONE);
    cr_assert(data == 12);
    cr_assert(packet_read_int8(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_int8(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_int8(p, &data) != PACKET_DONE);
    data = -120;
    cr_assert(packet_write_int8(p, data) == PACKET_DONE);
    cr_assert(packet_read_int8(p, &data) == PACKET_DONE);
    cr_assert(data == -120);
    packet_destroy(p);
}

Test(packet_can_read, uint8)
{
    packet_t *p = packet_create();
    uint8_t data = 12;

    cr_assert(packet_read_uint8(p, &data) != PACKET_DONE);
    cr_assert(packet_write_int8(p, data) == PACKET_DONE);
    data = 24;
    cr_assert(packet_write_uint8(p, data) == PACKET_DONE);
    cr_assert(packet_write_uint8(p, data) == PACKET_DONE);
    cr_assert(packet_read_uint8(p, &data) == PACKET_DONE);
    cr_assert(data == 12);
    cr_assert(packet_read_uint8(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_uint8(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_uint8(p, &data) != PACKET_DONE);
    packet_destroy(p);
}

Test(packet_can_read, int16)
{
    packet_t *p = packet_create();
    int16_t data = 12;

    cr_assert(packet_read_int16(p, &data) != PACKET_DONE);
    cr_assert(packet_write_int16(p, data) == PACKET_DONE);
    data = 24;
    cr_assert(packet_write_int16(p, data) == PACKET_DONE);
    cr_assert(packet_write_int16(p, data) == PACKET_DONE);
    cr_assert(packet_read_int16(p, &data) == PACKET_DONE);
    cr_assert(data == 12);
    cr_assert(packet_read_int16(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_int16(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_int16(p, &data) != PACKET_DONE);
    data = -120;
    cr_assert(packet_write_int16(p, data) == PACKET_DONE);
    cr_assert(packet_read_int16(p, &data) == PACKET_DONE);
    cr_assert(data == -120);
    packet_destroy(p);
}

Test(packet_can_read, uint16)
{
    packet_t *p = packet_create();
    uint16_t data = 12;

    cr_assert(packet_read_uint16(p, &data) != PACKET_DONE);
    cr_assert(packet_write_uint16(p, data) == PACKET_DONE);
    data = 24;
    cr_assert(packet_write_uint16(p, data) == PACKET_DONE);
    cr_assert(packet_write_uint16(p, data) == PACKET_DONE);
    cr_assert(packet_read_uint16(p, &data) == PACKET_DONE);
    cr_assert(data == 12);
    cr_assert(packet_read_uint16(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_uint16(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_uint16(p, &data) != PACKET_DONE);
    packet_destroy(p);
}

Test(packet_can_read, int32)
{
    int32_t data = 12;
    packet_t *p = packet_create();

    cr_assert(packet_read_int32(p, &data) != PACKET_DONE);
    cr_assert(packet_write_int32(p, data) == PACKET_DONE);
    data = 24;
    cr_assert(packet_write_int32(p, data) == PACKET_DONE);
    cr_assert(packet_write_int32(p, data) == PACKET_DONE);
    cr_assert(packet_read_int32(p, &data) == PACKET_DONE);
    cr_assert(data == 12);
    cr_assert(packet_read_int32(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_int32(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_int32(p, &data) != PACKET_DONE);
    data = -120;
    cr_assert(packet_write_int32(p, data) == PACKET_DONE);
    cr_assert(packet_read_int32(p, &data) == PACKET_DONE);
    cr_assert(data == -120);
    packet_destroy(p);
}

Test(packet_can_read, uint32)
{
    packet_t *p = packet_create();
    uint32_t data = 12;

    cr_assert(packet_read_uint32(p, &data) != PACKET_DONE);
    cr_assert(packet_write_uint32(p, data) == PACKET_DONE);
    data = 24;
    cr_assert(packet_write_uint32(p, data) == PACKET_DONE);
    cr_assert(packet_write_uint32(p, data) == PACKET_DONE);
    cr_assert(packet_read_uint32(p, &data) == PACKET_DONE);
    cr_assert(data == 12);
    cr_assert(packet_read_uint32(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_uint32(p, &data) == PACKET_DONE);
    cr_assert(data == 24);
    cr_assert(packet_read_uint32(p, &data) != PACKET_DONE);
    packet_destroy(p);
}