/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_MICROFIREWORKS "/presentations/microfireworks.html "
#define HTTP_PATH_MICROFIREWORKS (DIRBUILD "/http/presentations/microfireworks.html")

__httpd_extern
__httpd_internal
int MicrofireworksHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_MICROFIREWORKS);
}

__httpd_extern
__httpd_internal
int MicrofireworksGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_MICROFIREWORKS);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule microfireworksModule = {
	.name = HTTP_URI_MICROFIREWORKS,
	.Head = MicrofireworksHead,
	.Get = MicrofireworksGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
