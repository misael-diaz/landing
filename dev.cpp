/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_DEV "/DEV"
#define HTTP_PATH_DEV (DIRBUILD "/public/logos/DEV.png")

__httpd_extern
__httpd_internal
int DEVHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_DEV);
}

__httpd_extern
__httpd_internal
int DEVGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_DEV);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule devModule = {
	.name = HTTP_URI_DEV,
	.Head = DEVHead,
	.Get = DEVGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
