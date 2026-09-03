/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_GITHUB "/github"
#define HTTP_PATH_GITHUB (DIRBUILD "/public/logos/github.png")

__httpd_extern
__httpd_internal
int GithubHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_GITHUB);
}

__httpd_extern
__httpd_internal
int GithubGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_GITHUB);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule githubModule = {
	.name = HTTP_URI_GITHUB,
	.Head = GithubHead,
	.Get = GithubGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
