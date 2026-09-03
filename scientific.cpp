/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_SCIENTIFIC "/scientific"
#define HTTP_PATH_SCIENTIFIC (DIRBUILD "/public/logos/scientific.png")

__httpd_extern
__httpd_internal
int ScientificHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_SCIENTIFIC);
}

__httpd_extern
__httpd_internal
int ScientificGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_SCIENTIFIC);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule scientificModule = {
	.name = HTTP_URI_SCIENTIFIC,
	.Head = ScientificHead,
	.Get = ScientificGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
