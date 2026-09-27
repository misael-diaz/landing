/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_BLOGS "/presentations "
#define HTTP_PATH_BLOGS (DIRBUILD "/http/presentations/index.html")

__httpd_extern
__httpd_internal
int PresentationsHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_BLOGS);
}

__httpd_extern
__httpd_internal
int PresentationsGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_BLOGS);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule presentationsModule = {
	.name = HTTP_URI_BLOGS,
	.Head = PresentationsHead,
	.Get = PresentationsGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
