/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_CVE "/blogs/computer-vision-engine.html "
#define HTTP_PATH_CVE (DIRBUILD "/http/blogs/computer-vision-engine.html")

__httpd_extern
__httpd_internal
int ComputerVisionEngineHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_CVE);
}

__httpd_extern
__httpd_internal
int ComputerVisionEngineGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_CVE);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule computervisionengineModule = {
	.name = HTTP_URI_CVE,
	.Head = ComputerVisionEngineHead,
	.Get = ComputerVisionEngineGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
