/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
*
*    More information about projects PDAControl
*    Mas informacion sobre proyectos PDAControl
*    Blog PDAControl English   http://pdacontrolenglish.blogspot.com.co/   
*    Blog PDAControl Espa?ol   http://pdacontrol.blogspot.com.co/
*    Channel  Youtube          https://www.youtube.com/c/JhonValenciaPDAcontrol/videos   
*
*/
 
 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char *ssid = "1503523";
const char *password = "D2E7D32DBC883";

int n=0;

ESP8266WebServer server ( 80 );

void handleRoot() {
	
	char temp[400];
	int sec = millis() / 1000;
	int min = sec / 60;
	int hr = min / 60;

	snprintf ( temp, 400,

	
/// Code HTML	
	
"<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>ESP8266 Demo</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>WebServer SVG ESP8266!</h1>\
    <p>Uptime: %02d:%02d:%02d</p>\
    <img src=\"/test.svg\" />\
  </body>\
</html>",

   hr, min % 60, sec % 60
	);
	server.send ( 200, "text/html", temp );
	
}

void handleNotFound() {
	String message = "File Not Found\n\n";
	message += "URI: ";
	message += server.uri();
	message += "\nMethod: ";
	message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
	message += "\nArguments: ";
	message += server.args();
	message += "\n";

	for ( uint8_t i = 0; i < server.args(); i++ ) {
		message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
	}

	server.send ( 404, "text/plain", message );

}

void setup ( void ) {


	Serial.begin ( 115200 );
	WiFi.begin ( ssid, password );
	Serial.println ( "" );

	// Wait for connection
	while ( WiFi.status() != WL_CONNECTED ) {
		delay ( 500 );
		Serial.print ( "." );
	}

	Serial.println ( "" );
	Serial.print ( "Connected to " );
	Serial.println ( ssid );
	Serial.print ( "IP address: " );
	Serial.println ( WiFi.localIP() );

	if ( MDNS.begin ( "esp8266" ) ) {
		Serial.println ( "MDNS responder started" );
	}

	server.on ( "/", handleRoot );
	server.on ( "/test.svg", drawGraph );
	server.on ( "/inline", []() {
		server.send ( 100, "text/plain", "this works as well" );
	} );
	server.onNotFound ( handleNotFound );
	server.begin();
	Serial.println ( "HTTP server started" );
}

void loop ( void ) {
	server.handleClient();
}

void drawGraph() {
  String out = "";
char temp[2000];


//File SVG

out += " <svg width=\"580\" height=\"400\" xmlns=\"http://www.w3.org/2000/svg\"> \n"; 
out += " <g>  \n"; 
out += "<title>background</title>  \n"; 
out += "  <rect fill=\"#fff\" id=\"canvas_background\" height=\"402\" width=\"582\" y=\"-1\" x=\"-1\"/>  \n"; 
out += "  <g display=\"none\" overflow=\"visible\" y=\"0\" x=\"0\" height=\"100%\" width=\"100%\" id=\"canvasGrid\">  \n"; 
out += "   <rect fill=\"url(#gridpattern)\" stroke-width=\"0\" y=\"0\" x=\"0\" height=\"100%\" width=\"100%\"/>  \n"; 
out += "  </g>  \n"; 
out += " </g>   \n"; 
out += "<g>  \n"; 
out += "  <title>Layer 1</title>  \n"; 
out += "  <rect stroke=\"#000\" id=\"svg_13\" height=\"363.000022\" width=\"538.999993\" y=\"17.999965\" x=\"24.500007\" stroke-opacity=\"null\" stroke-width=\"2.5\" fill=\"#B8874D\"/> \n"; 
out += "<rect stroke=\"#000\" id=\"svg_11\" height=\"109.000001\" width=\"173\" y=\"124\" x=\"122.5\" fill-opacity=\"null\" stroke-opacity=\"null\" stroke-width=\"6.5\" fill=\"#fff\"/>  \n"; 
out += "<text stroke=\"#000\" transform=\"matrix(5.692307472229004,0,0,2.1818182468414307,-851.6538062095642,-171.36364579200745) \" xml:space=\"preserve\" text-anchor=\"start\" font-family=\"Helvetica, Arial, sans-serif\" font-size=\"24\" id=\"svg_3\" y=\"169\" x=\"181.5\" stroke-opacity=\"null\" stroke-width=\"0\" fill=\"#000000\"/>  \n"; 

//Random value 
  n=random(0, 100); 
  String dato (n, DEC);  
    
out += "<text stroke=\"#000\" transform=\"matrix(0.9548872113227844,0,0,1,7.939850807189941,0) \" xml:space=\"preserve\" text-anchor=\"start\" font-family=\"Helvetica, Arial, sans-serif\" font-size=\"52\" id=\"svg_4\" y=\"197\" x=\"145.629921\" fill-opacity=\"null\" stroke-opacity=\"null\" stroke-width=\"0\" fill=\"#000000\"> "; out += dato ; out += "%</text>  \n"; 
out += "<text xml:space=\"preserve\" text-anchor=\"start\" font-family=\"Helvetica, Arial, sans-serif\" font-size=\"23\" id=\"svg_21\" y=\"58\" x=\"119.5\" stroke-opacity=\"null\" stroke-width=\"0\" stroke=\"#000\" fill=\"#000000\">Random Value ESP8266 </text>  \n"; 
out += "<rect stroke=\"#000\" id=\"svg_24\" height=\"235\" width=\"141.999996\" y=\"90\" x=\"392.5\" stroke-opacity=\"null\" stroke-width=\"16.5\" fill=\"#BBBBBB\"/> \n";
out += "<rect stroke=\"#000\" id=\"svg_16\" height=\"186.999995\" width=\"124\" y=\"128.999995\" x=\"400.499996\" stroke-opacity=\"null\" stroke-width=\"0\" fill=\"#9ACEE6\"/>  \n"; 
out += "</g>  \n"; 
out += "</svg> \n"; 



 
	server.send ( 200, "image/svg+xml", out);
}
