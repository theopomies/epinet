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

Test(packet_read, int8)
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

Test(packet_read, uint8)
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

Test(packet_read, int16)
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

Test(packet_read, uint16)
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

Test(packet_read, int32)
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

Test(packet_read, uint32)
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

Test(packet_read, string)
{
    packet_t *p = packet_create();
    char *data = "Hello";

    cr_assert(packet_read_string(p, &data) != PACKET_DONE);
    cr_assert(packet_write_string(p, data) == PACKET_DONE);
    data = "World";
    cr_assert(packet_write_string(p, data) == PACKET_DONE);
    data = "!!!";
    cr_assert(packet_write_string(p, data) == PACKET_DONE);
    cr_assert(packet_read_string(p, &data) == PACKET_DONE);
    cr_assert_str_eq(data, "Hello");
    free(data);
    cr_assert(packet_read_string(p, &data) == PACKET_DONE);
    cr_assert_str_eq(data, "World");
    free(data);
    cr_assert(packet_read_string(p, &data) == PACKET_DONE);
    cr_assert_str_eq(data, "!!!");
    free(data);
    cr_assert(packet_read_string(p, &data) != PACKET_DONE);
    packet_destroy(p);
}

Test(packet_read, string_until)
{
    packet_t *p = packet_create();
    char *data = "Hello";

    cr_assert(packet_read_string_until(p, &data, "\n\t") != PACKET_DONE);
    cr_assert(packet_write_string(p, "Hello\nWorld\t\n\n!!!\t") == PACKET_DONE);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "Hello");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "World");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "!!!");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") != PACKET_DONE);
    packet_destroy(p);
}

Test(packet_read, string_until_front_delim)
{
    packet_t *p = packet_create();
    char *data = "Hello";

    cr_assert(packet_read_string_until(p, &data, "\n\t") != PACKET_DONE);
    cr_assert(packet_write_string(p, "\t\nHello\n!!!") == PACKET_DONE);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "Hello");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "!!!");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") != PACKET_DONE);
    packet_destroy(p);
}

Test(packet_read, string_until_back_delim)
{
    packet_t *p = packet_create();
    char *data = "Hello";

    cr_assert(packet_read_string_until(p, &data, "\n\t") != PACKET_DONE);
    cr_assert(packet_write_string(p, "Hello\n\n!!!\t\t\n") == PACKET_DONE);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "Hello");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "!!!");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") != PACKET_DONE);
    packet_destroy(p);
}

Test(packet_read, string_until_front_back_delim)
{
    packet_t *p = packet_create();
    char *data = "Hello";

    cr_assert(packet_read_string_until(p, &data, "\n\t") != PACKET_DONE);
    cr_assert(packet_write_string(p, "\n\tHello\n\n!!!\t\t\n") == PACKET_DONE);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "Hello");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") == PACKET_DONE);
    cr_assert_str_eq(data, "!!!");
    free(data);
    cr_assert(packet_read_string_until(p, &data, "\n\t") != PACKET_DONE);
    packet_destroy(p);
}

Test(packet_read, multiple_types)
{
    packet_t *p = packet_create();
    char *str = NULL;
    uint8_t ubyte = 42;
    int16_t word = -201;
    uint32_t udword = 843526;

    cr_assert(packet_read_string(p, &str) != PACKET_DONE);
    cr_assert(packet_write_string(p, "Hello") == PACKET_DONE);
    cr_assert(packet_write_uint8(p, 42) == PACKET_DONE);
    cr_assert(packet_read_string(p, &str) == PACKET_DONE);
    cr_assert_str_eq(str, "Hello");
    cr_assert(packet_write_int16(p, -201) == PACKET_DONE);
    cr_assert(packet_write_uint32(p, 51384) == PACKET_DONE);
    cr_assert(packet_read_uint8(p, &ubyte) == PACKET_DONE);
    cr_assert(packet_write_uint8(p, 21) == PACKET_DONE);
    cr_assert(packet_read_int16(p, &word) == PACKET_DONE);
    cr_assert(packet_read_uint32(p, &udword) == PACKET_DONE);
    cr_assert(ubyte == 42 && word == -201 && udword == 51384);
    cr_assert(packet_read_uint8(p, &ubyte) == PACKET_DONE);
    cr_assert(ubyte == 21 && packet_read_string(p, &str) != PACKET_DONE);
    packet_destroy(p);
}