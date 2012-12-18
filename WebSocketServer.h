/*
Websocket-Arduino, a websocket implementation for Arduino
Copyright 2011 Per Ejeklint

Based on previous implementations by
Copyright 2010 Ben Swanson
and
Copyright 2010 Randall Brewer
and
Copyright 2010 Oliver Smith

Some code and concept based off of Webduino library
Copyright 2009 Ben Combee, Ran Talbott

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

-------------
Now based off
http://www.whatwg.org/specs/web-socket-protocol/

- OLD -
Currently based off of "The Web Socket protocol" draft (v 75):
http://tools.ietf.org/html/draft-hixie-thewebsocketprotocol-75
*/


#ifndef WEBSOCKETSERVER_H_
#define WEBSOCKETSERVER_H_

#include <Arduino.h>
#include <Client.h>
#include "ws_string.h"

// CRLF characters to terminate lines/handshakes in headers.
#define CRLF "\r\n"

class Client;

namespace websocket
{
typedef ::Client Socket;

class ServerHandshake
{
public:

    /// @param socket - a connected socket
    /// @param acceptOrigin - origin that the connctions should be accepted from.
    ///                       if empty, then any origin will be accepted.
    ServerHandshake(Socket& socket, String const& acceptOrigin);

    // Perform server part of websocket handshake
    bool run();

private:
    // Discovers if the client's header is requesting an upgrade to a
    // websocket connection.
    bool analyzeRequest();

    // Disconnect user gracefully.
    void disconnect();

private:

    Socket& socket_;
    String acceptOrigin_;
    String origin_;
    String host_;
};

}

#endif
