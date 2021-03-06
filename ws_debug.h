/*
    Arduino-Websocket, a websocket implementation for Arduino
    Copyright 2012, 2013 Ahti Legonkov, Raido Lepp

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#if defined(ARDUINO)
	#include "platform/arduino/ws_debug.h"
#else
	#include "platform/generic/ws_debug.h"
#endif

#if !defined(WEBSOCKET_DEBUG)
	#define WEBSOCKET_DEBUG 0
#endif

#define wsDebug() if (!WEBSOCKET_DEBUG) {} else debug_stream
