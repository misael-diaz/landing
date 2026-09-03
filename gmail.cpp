/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_GMAIL "/gmail"
#define HTTP_PATH_GMAIL (DIRBUILD "/public/logos/gmail.png")

__httpd_extern
__httpd_internal
int GmailHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_GMAIL);
}

__httpd_extern
__httpd_internal
int GmailGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_GMAIL);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule gmailModule = {
	.name = HTTP_URI_GMAIL,
	.Head = GmailHead,
	.Get = GmailGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
