/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_STEM "/stem"
#define HTTP_PATH_STEM (DIRBUILD "/public/logos/stem.png")

__httpd_extern
__httpd_internal
int STEMHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_STEM);
}

__httpd_extern
__httpd_internal
int STEMGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_STEM);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule stemModule = {
	.name = HTTP_URI_STEM,
	.Head = STEMHead,
	.Get = STEMGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
