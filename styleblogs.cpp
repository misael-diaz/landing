/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_STYLE_BLOGS "/blogs/style-blogs.css"
#define HTTP_PATH_STYLE_BLOGS (DIRBUILD "/http/blogs/style-blogs.css")

__httpd_extern
__httpd_internal
int StyleBlogsHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_STYLE_BLOGS);
}

__httpd_extern
__httpd_internal
int StyleBlogsGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_STYLE_BLOGS);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule styleblogsModule = {
	.name = HTTP_URI_STYLE_BLOGS,
	.Head = StyleBlogsHead,
	.Get = StyleBlogsGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
