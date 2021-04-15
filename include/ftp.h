/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** ftp
*/

#ifndef ftp_H_
#define ftp_H_

#include <stdbool.h>
#include <stddef.h>

#include <ip_address.h>
#include <timeout.h>

typedef struct
{
} ftp_t;

typedef struct
{
} ftp_listing_response_t;

typedef struct
{
} ftp_directory_response_t;

typedef enum
{
    FTP_BINARY,
    FTP_ASCII,
    FTP_EBCDIC
} ftp_traner_mode_t;

typedef enum
{
    // 1xx: the requested action is being initiated,
    // expect another reply before proceeding with a new command
    FTP_RESTART_MARKER_REPLY = 110,
    FTP_SERVICE_READY_SOON = 120,
    FTP_DATA_CONNECTION_ALREADY_OPENED = 125,
    FTP_OPENING_DATA_CONNECTON = 150,

    // 2xx: the requested action has been succesully completed
    FTP_OK = 200,
    FTP_POINTLESS_COMMAND = 202,
    FTP_SYSTEM_STATUS = 211,
    FTP_DIRECTORY_STATUS = 212,
    FTP_FILE_STATUS = 213,
    FTP_HELP_MESSAGE = 214,
    FTP_SYSTEM_TYPE = 215,
    FTP_SERVICE_READY = 220,
    FTP_CLOSING_CONNECTION = 221,
    FTP_DATA_CONNECTION_OPENED = 225,
    FTP_CLOSING_DATA_CONNECTION = 226,
    FTP_ENTERING_PASSIVE_MODE = 227,
    FTP_LOGGED_IN = 230,
    FTP_FILE_ACTION_OK = 250,
    FTP_DIRECTORY_OK = 257,

    // 3xx: the command has been accepted, but the requested action
    // is dormant, pending receipt of further information
    FTP_NEED_PASSWORD = 331,
    FTP_NEED_ACCOUNT_TO_LOG_IN = 332,
    FTP_NEED_INFORMATION = 350,

    // 4xx: the command was not accepted and the requested action did not take
    // place, but the error condition is temporary and the action may be
    // requested again
    FTP_SERVICE_UNAVAILABLE = 421,
    FTP_DATA_CONNECTION_UNAVAILABLE = 425,
    FTP_TRANER_ABORTED = 426,
    FTP_FILE_ACTION_ABORTED = 450,
    FTP_LOCAL_ERROR = 451,
    FTP_INSUFFICIENT_STORAGE_SPACE = 452,

    // 5xx: the command was not accepted and
    // the requested action did not take place
    FTP_COMMAND_UNKNOWN = 500,
    FTP_PARAMETERS_UNKNOWN = 501,
    FTP_COMMAND_NOT_IMPLEMENTED = 502,
    FTP_BAD_COMMAND_SEQUENCE = 503,
    FTP_PARAMETER_NOT_IMPLEMENTED = 504,
    FTP_NOT_LOGGED_IN = 530,
    FTP_NEED_ACCOUNT_TO_STORE = 532,
    FTP_FILE_UNAVAILABE = 550,
    FTP_PAGE_TYPE_UNKNOWN = 551,
    FTP_NOT_ENOUGH_MEMORY = 552,
    FTP_FILENAME_NOT_ALLOWED = 553,

    // 6xx: replies regarding confidentiality and integrity
    FTP_INTEGRITY_PROTECTED = 631,
    FTP_CONFIDENTIALITY_INTEGRITY_PROTECTED = 632,
    FTP_CONFIDENTIALITY_PROTECTED = 633,

    // 10xx: error codes
    FTP_CONNECTION_RESET = 1001,
    FTP_CANNOT_CONNECT,
    FTP_CANNOT_CONNECT_REFUSED,
    FTP_DIRECTORY_NOT_EMPTY,
    FTP_SERVER_FULL
} ftp_status_t;

typedef struct
{
    ftp_status_t status;
    char *message;
} ftp_response_t;

void ftp_listing_response_destroy(ftp_listing_response_t *ftp_listing_response);
bool ftp_listing_response_is_ok(
    const ftp_listing_response_t *ftp_listing_response);
ftp_status_t ftp_listing_response_get_status(
    const ftp_listing_response_t *ftp_listing_response);
const char *ftp_listing_response_get_message(
    const ftp_listing_response_t *ftp_listing_response);
size_t ftp_listing_response_get_count(
    const ftp_listing_response_t *ftp_listing_response);
const char *ftp_listing_response_get_name(
    const ftp_listing_response_t *ftp_listing_response, size_t index);

void ftp_directory_response_destroy(
    ftp_directory_response_t *ftp_directory_response);
bool ftp_directory_response_is_ok(
    const ftp_directory_response_t *ftp_directory_response);
ftp_status_t ftp_directory_response_get_status(
    const ftp_directory_response_t *ftp_directory_response);
const char *ftp_directory_response_get_message(
    const ftp_directory_response_t *ftp_directory_response);
const char *ftp_directory_response_get_directory(
    const ftp_directory_response_t *ftp_directory_response);

void ftp_response_destroy(ftp_response_t *ftp_response);
bool ftp_response_is_ok(const ftp_response_t *ftp_response);
ftp_status_t ftp_response_get_status(const ftp_response_t *ftp_response);
const char *ftp_response_get_message(const ftp_response_t *ftp_response);

ftp_t *ftp_create(void);
void ftp_destroy(ftp_t *ftp);

ftp_response_t *ftp_connect(
    ftp_t *ftp, ip_address_t server, unsigned short port, timeout_t timeout);
ftp_response_t *ftp_login_anonymous(ftp_t *ftp);
ftp_response_t *ftp_login(ftp_t *ftp, const char *name, const char *password);
ftp_response_t *ftp_disconnect(ftp_t *ftp);
ftp_response_t *ftp_keep_alive(ftp_t *ftp);
ftp_directory_response_t *ftp_get_working_directory(ftp_t *ftp);
ftp_listing_response_t *ftp_get_directory_listing(
    ftp_t *ftp, const char *directory);
ftp_response_t *ftp_change_directory(ftp_t *ftp, const char *directory);
ftp_response_t *ftp_parent_directory(ftp_t *ftp);
ftp_response_t *ftp_create_directory(ftp_t *ftp, const char *name);
ftp_response_t *ftp_delete_directory(ftp_t *ftp, const char *name);
ftp_response_t *ftp_rename_file(
    ftp_t *ftp, const char *file, const char *new_name);
ftp_response_t *ftp_delete_file(ftp_t *ftp, const char *name);
ftp_response_t *ftp_download(ftp_t *ftp, const char *remote_file,
    const char *localPath, ftp_traner_mode_t mode);
ftp_response_t *ftp_upload(ftp_t *ftp, const char *local_file,
    const char *remotePath, ftp_traner_mode_t mode);
ftp_response_t *ftp_send_command(
    ftp_t *ftp, const char *command, const char *parameter);

#endif /* !ftp_H_ */
