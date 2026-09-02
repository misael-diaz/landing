/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_ICMM "/ICMM"
#define HTTP_PATH_ICMM (DIRBUILD "/public/logos/ICMM.png")

__httpd_extern
__httpd_internal
int ICMMHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_ICMM);
}

__httpd_extern
__httpd_internal
int ICMMGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_ICMM);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule icmmModule = {
	.name = HTTP_URI_ICMM,
	.Head = ICMMHead,
	.Get = ICMMGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
