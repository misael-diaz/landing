/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_NEXTJS "/NextJS"
#define HTTP_PATH_NEXTJS (DIRBUILD "/public/logos/NextJS.png")

__httpd_extern
__httpd_internal
int NEXTJSHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_NEXTJS);
}

__httpd_extern
__httpd_internal
int NEXTJSGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_NEXTJS);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule nextjsModule = {
	.name = HTTP_URI_NEXTJS,
	.Head = NEXTJSHead,
	.Get = NEXTJSGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
