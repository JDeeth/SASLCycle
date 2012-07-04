/* SASLCycle.cpp
   (c) Jack Deeth 2012

   Disables and reenables SASL on aircraft load.

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to
  deal in the Software without restriction, including without limitation the
  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
  sell copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions: The above copyright
  notice and this permission notice shall be included in all copies or
  substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.
 */

#define MSG_ADD_DATAREF 0x01000000
#define XPLM200 1

//xplm
#include <XPLMPlugin.h>
#include <XPLMProcessing.h>

//FLCBs
float runOnceAtStartup ( float, float, int, void * );
float onAircraftLoad ( float, float, int, void * );

const char saslSig[] = "Dozer.systime"; //for testing
//const char saslSig[] = "1-sim.sasl"; //signature of SASL plugin
XPLMPluginID saslID = 0;

bool saslFound = 0;

PLUGIN_API int XPluginStart(
        char *        outName,
        char *        outSig,
        char *        outDesc) {

    // Plugin Info
    strcpy(outName, "SASLCycle");
    strcpy(outSig,  "Dozer.SASLCycle");
    strcpy(outDesc, "Disables and re-enables SASL plugin on aircraft load");

    XPLMRegisterFlightLoopCallback(onAircraftLoad, 2.0, NULL);
    XPLMRegisterFlightLoopCallback(runOnceAtStartup, 1.0, NULL);

    return 1;
}


PLUGIN_API void XPluginStop(void) {
    XPLMUnregisterFlightLoopCallback(onAircraftLoad, NULL);
    XPLMUnregisterFlightLoopCallback(runOnceAtStartup, NULL);
}

PLUGIN_API void XPluginDisable(void) {}

PLUGIN_API int XPluginEnable(void) { return 1; }

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID, long msg, void *){
    if (msg == XPLM_MSG_PLANE_LOADED) {
        XPLMSetFlightLoopCallbackInterval(onAircraftLoad, -1, 1, 0);
    }
}

float runOnceAtStartup(float, float, int, void *) {
    saslID = XPLMFindPluginByPath(saslSig);

    if (saslID != XPLM_NO_PLUGIN_ID) {
        saslFound = 1;
    }
    return 0;
}

float onAircraftLoad(float, float, int, void *) {
    if(saslFound) {
        if(XPLMIsPluginEnabled(saslID)) {
            XPLMDisablePlugin(saslID);
            return 1.0; //call again in 1 second
        } else {
            XPLMEnablePlugin(saslID);
            return 0;
        }
    }
    return 0;
}
