/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_YOUTUBE "/youtube"
#define HTTP_PATH_YOUTUBE (DIRBUILD "/public/logos/youtube.png")

__httpd_extern
__httpd_internal
int YoutubeHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_YOUTUBE);
}

__httpd_extern
__httpd_internal
int YoutubeGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_YOUTUBE);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule youtubeModule = {
	.name = HTTP_URI_YOUTUBE,
	.Head = YoutubeHead,
	.Get = YoutubeGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
