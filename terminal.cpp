/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_TERMINAL "/terminal"
#define HTTP_PATH_TERMINAL (DIRBUILD "/public/logos/terminal.png")

__httpd_extern
__httpd_internal
int TerminalHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_TERMINAL);
}

__httpd_extern
__httpd_internal
int TerminalGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_TERMINAL);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule terminalModule = {
	.name = HTTP_URI_TERMINAL,
	.Head = TerminalHead,
	.Get = TerminalGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
