/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_LINKEDIN "/linkedin"
#define HTTP_PATH_LINKEDIN (DIRBUILD "/public/logos/linkedin.png")

__httpd_extern
__httpd_internal
int LinkedinHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_LINKEDIN);
}

__httpd_extern
__httpd_internal
int LinkedinGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_LINKEDIN);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule linkedinModule = {
	.name = HTTP_URI_LINKEDIN,
	.Head = LinkedinHead,
	.Get = LinkedinGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
