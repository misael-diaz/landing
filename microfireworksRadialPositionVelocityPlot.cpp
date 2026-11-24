/*

hydrogen

Copyright (C) 2026 Misael Díaz-Maldonado

This file is released under the GNU General Public License version 2 only
as published by the Free Software Foundation.

*/

#include "http.hpp"

#define HTTP_URI_MICROFIREWORKS_RADIAL_POSITION_VELOCITY_PLOT "/microfireworks/microfireworks-radial-position-velocity.png"
#define HTTP_PATH_MICROFIREWORKS_RADIAL_POSITION_VELOCITY_PLOT (DIRBUILD "/public/presentations/microfireworks/microfireworks-radial-position-velocity.png")

__httpd_extern
__httpd_internal
int MicrofireworksRadialPositionVelocityPlotHead(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondHeadFile(DataResponse, HTTP_PATH_MICROFIREWORKS_RADIAL_POSITION_VELOCITY_PLOT);
}

__httpd_extern
__httpd_internal
int MicrofireworksRadialPositionVelocityPlotGet(
        struct HttpResponse * const DataResponse,
        struct HttpRequest const * const DataRequest __attribute__((unused))
) {
        return HttpRespondGetFile(DataResponse, HTTP_PATH_MICROFIREWORKS_RADIAL_POSITION_VELOCITY_PLOT);
}

// NOTE: not going to include stddef.h just for NULL, we can use zero instead
struct HttpModule microfireworksRadialPositionVelocityPlotModule = {
	.name = HTTP_URI_MICROFIREWORKS_RADIAL_POSITION_VELOCITY_PLOT,
	.Head = MicrofireworksRadialPositionVelocityPlotHead,
	.Get = MicrofireworksRadialPositionVelocityPlotGet,
	.Put = 0,
	.Post = 0,
	.Delete = 0
};
