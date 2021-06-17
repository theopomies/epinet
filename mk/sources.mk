##
## EPITECH PROJECT, 2020
## Epinet
## File description:
## Makefile
##

ERROR_DIR	=	error/
ERROR_SRCS	=	get_error.c	\
				set_error.c	\
				epinet_perror.c

SOCKET_SELECTOR_DIR		=	socket_selector/
SOCKET_SELECTOR_SRCS	=	add_socket.c	\
							clear.c	\
							copy.c	\
							create.c	\
							destroy.c	\
							ready.c	\
							remove_socket.c	\
							wait.c

FTP_DIR		=	ftp/
FTP_SRCS	=

HTTP_DIR	=	http/
HTTP_SRCS	=

IP_ADDRESS_DIR	=	ip_address/
IP_ADDRESS_SRCS	=	from_bytes.c	\
					from_integer.c	\
					from_socket.c	\
					from_string.c	\
					get_local_address.c	\
					get_public_address.c	\
					to_integer.c	\
					to_string.c

PACKET_DIR	=	packet/
PACKET_SRCS	=	append.c	\
				can_read.c	\
				clear.c		\
				clone.c		\
				create.c	\
				destroy.c	\
				end_of_packet.c	\
				get_data_size.c	\
				get_data.c	\
				read_int8.c	\
				read_int16.c	\
				read_int32.c	\
				read_string.c	\
				read_string_until.c	\
				read_uint8.c	\
				read_uint16.c	\
				read_uint32.c	\
				read.c	\
				resize.c	\
				write_int8.c	\
				write_int16.c	\
				write_int32.c	\
				write_string.c	\
				write_uint8.c	\
				write_uint16.c	\
				write_uint32.c	\

SOCKET_DIR	=	socket/
SOCKET_SRCS	=	$(TCP_SRCS)	\
				$(UDP_SRCS)	\
				create_empty.c	\
				create.c	\
				destroy.c	\
				get_tcp_socket.c	\
				get_udp_socket.c	\
				is_blocking.c	\
				set_blocking.c	\
				get_status.c

TCP_DIR		=	tcp/
TCP_SRCS	=	$(addprefix $(TCP_LISTENER_DIR), $(TCP_LISTENER_SRCS))	\
				$(addprefix $(TCP_SOCKET_DIR), $(TCP_SOCKET_SRCS))

TCP_LISTENER		=	tcp_listener/
TCP_LISTENER_DIR	=	$(addprefix $(TCP_DIR), $(TCP_LISTENER))
TCP_LISTENER_SRCS	=	accept.c	\
						create.c	\
						listen.c	\
						destroy.c

TCP_SOCKET		=	tcp_socket/
TCP_SOCKET_DIR	=	$(addprefix $(TCP_DIR), $(TCP_SOCKET))
TCP_SOCKET_SRCS	=	connect.c	\
					create_empty.c	\
					create.c	\
					destroy.c	\
					disconnect.c	\
					get_listener.c	\
					get_local_port.c	\
					get_local_address.c	\
					get_remote_address.c	\
					get_remote_port.c	\
					is_blocking.c	\
					receive_packet.c	\
					receive.c	\
					send_packet.c	\
					send_partial.c	\
					send.c	\
					set_blocking.c

UDP_DIR			=	udp/
UDP_SOCKET		=	udp_socket/
UDP_SOCKET_DIR	=	$(addprefix $(UDP_DIR), $(UDP_SOCKET))
UDP_SOCKET_SRCS	=

SRCS		=	$(addprefix $(ERROR_DIR), $(ERROR_SRCS))	\
				$(addprefix $(SOCKET_SELECTOR_DIR), $(SOCKET_SELECTOR_SRCS))	\
				$(addprefix $(FTP_DIR), $(FTP_SRCS))	\
				$(addprefix $(HTTP_DIR), $(HTTP_SRCS))	\
				$(addprefix $(IP_ADDRESS_DIR), $(IP_ADDRESS_SRCS))	\
				$(addprefix $(PACKET_DIR), $(PACKET_SRCS))	\
				$(addprefix $(SOCKET_DIR), $(SOCKET_SRCS))

TESTS_SRCS	=	test_error.c	\
				test_packet.c