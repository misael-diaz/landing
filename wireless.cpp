/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_WIRELESS "/blogs/wireless-networking-linux"
#define HTTP_PATH_WIRELESS (DIRBUILD "/http/blogs/wireless-networking-linux.html")

__httpd_extern
__httpd_internal
int WirelessHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_WIRELESS);
}

__httpd_extern
__httpd_internal
int WirelessGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_WIRELESS);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule wirelessModule = {
	.name = HTTP_URI_WIRELESS,
	.Head = WirelessHead,
	.Get = WirelessGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
