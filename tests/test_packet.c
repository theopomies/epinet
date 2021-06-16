/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** test_packet
*/

#include <criterion/criterion.h>
#include <packet.h>

Test(packet_append, success_1)
{
    packet_t *p = packet_create();

    cr_assert(packet_append(p, "Hello", 6) == PACKET_DONE);
    cr_assert(!memcmp(p->data, "Hello", 6));
    cr_assert(packet_append(p, " World", 7) == PACKET_DONE);
    cr_assert(!memcmp(p->data, "Hello\0 World", 13));
    packet_destroy(p);
}