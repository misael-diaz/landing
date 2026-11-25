/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_POINTER "/cursor/pointer.png "
#define HTTP_PATH_POINTER (DIRBUILD "/public/cursor/pointer.png")

__httpd_extern
__httpd_internal
int PointerHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_POINTER);
}

__httpd_extern
__httpd_internal
int PointerGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_POINTER);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule pointerModule = {
	.name = HTTP_URI_POINTER,
	.Head = PointerHead,
	.Get = PointerGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
