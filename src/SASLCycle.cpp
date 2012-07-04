#define MSG_ADD_DATAREF 0x01000000
#define XPLM200 1

//xplm
#include <XPLMPlugin.h>
#include <XPLMUtilities.h>
#include <XPLMPlanes.h>

PLUGIN_API int XPluginStart(
        char *        outName,
        char *        outSig,
        char *        outDesc) {

    // Plugin Info
    strcpy(outName, "SASLCycle");
    strcpy(outSig,  "Dozer.SASLCycle");
    strcpy(outDesc, "Disables and re-enables SASL plugin on aircraft load");

    return 1;
}


PLUGIN_API void XPluginStop(void) {
}

PLUGIN_API void XPluginDisable(void) {}

PLUGIN_API int XPluginEnable(void) { return 1; }

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID, long, void *) {}

