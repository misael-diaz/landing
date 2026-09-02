/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_PUPR "/PUPR"
#define HTTP_PATH_PUPR (DIRBUILD "/public/logos/PUPR.png")

__httpd_extern
__httpd_internal
int PUPRHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_PUPR);
}

__httpd_extern
__httpd_internal
int PUPRGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_PUPR);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule puprModule = {
	.name = HTTP_URI_PUPR,
	.Head = PUPRHead,
	.Get = PUPRGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
