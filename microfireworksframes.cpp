/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_MICROFIREWORKSFRAMES "/microfireworks/microfireworksframes.png"
#define HTTP_PATH_MICROFIREWORKSFRAMES (DIRBUILD "/public/presentations/microfireworks/microfireworksframes.png")

__httpd_extern
__httpd_internal
int MicrofireworksFramesHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_MICROFIREWORKSFRAMES);
}

__httpd_extern
__httpd_internal
int MicrofireworksFramesGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_MICROFIREWORKSFRAMES);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule microfireworksframesModule = {
	.name = HTTP_URI_MICROFIREWORKSFRAMES,
	.Head = MicrofireworksFramesHead,
	.Get = MicrofireworksFramesGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
