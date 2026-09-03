/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_WHATSAPP "/whatsapp"
#define HTTP_PATH_WHATSAPP (DIRBUILD "/public/logos/whatsapp.png")

__httpd_extern
__httpd_internal
int WhatsAppHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_WHATSAPP);
}

__httpd_extern
__httpd_internal
int WhatsAppGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_WHATSAPP);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule whatsappModule = {
	.name = HTTP_URI_WHATSAPP,
	.Head = WhatsAppHead,
	.Get = WhatsAppGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
