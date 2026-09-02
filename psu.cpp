/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_PSU "/PSU"
#define HTTP_PATH_PSU (DIRBUILD "/public/logos/PSU.png")

__httpd_extern
__httpd_internal
int PSUHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_PSU);
}

__httpd_extern
__httpd_internal
int PSUGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_PSU);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule psuModule = {
	.name = HTTP_URI_PSU,
	.Head = PSUHead,
	.Get = PSUGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
