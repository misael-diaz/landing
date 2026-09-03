/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_UND "/UND"
#define HTTP_PATH_UND (DIRBUILD "/public/logos/UND.png")

__httpd_extern
__httpd_internal
int UNDHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_UND);
}

__httpd_extern
__httpd_internal
int UNDGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_UND);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule undModule = {
	.name = HTTP_URI_UND,
	.Head = UNDHead,
	.Get = UNDGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
