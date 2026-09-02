/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_UN "/UN"
#define HTTP_PATH_UN (DIRBUILD "/public/logos/UN.png")

__httpd_extern
__httpd_internal
int UNHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_UN);
}

__httpd_extern
__httpd_internal
int UNGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_UN);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule unModule = {
	.name = HTTP_URI_UN,
	.Head = UNHead,
	.Get = UNGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
