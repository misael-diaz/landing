/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_LINUXMINTUPDATE "/blogs/disabling-linuxmint-update-notifications.html "
#define HTTP_PATH_LINUXMINTUPDATE (DIRBUILD "/http/blogs/disabling-linuxmint-update-notifications.html")

__httpd_extern
__httpd_internal
int LinuxMintUpdateHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_LINUXMINTUPDATE);
}

__httpd_extern
__httpd_internal
int LinuxMintUpdateGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_LINUXMINTUPDATE);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule linuxmintupdateModule = {
	.name = HTTP_URI_LINUXMINTUPDATE,
	.Head = LinuxMintUpdateHead,
	.Get = LinuxMintUpdateGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
