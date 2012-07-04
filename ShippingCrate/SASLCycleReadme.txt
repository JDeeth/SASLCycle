
	Dozer's Aircraft Switcher

	v0.12

	26/June/2012

Hello,

This is Dozer's Aircraft Switcher, a plugin for quickly switching between up to eight aircraft. By using this package, you accept the disclaimer below. I hope you find this useful!

This plugin is only compiled for Windows at present, but the source code is available on Github. If you'd like to compile this for Mac or Linux and include the file in this package, please let me know. The repository is here:
https://github.com/JDeeth/AircraftSwitcher

J Deeth

[Installation]
Put the files into your <X-Plane>/Resources/Plugins/folder. They should be located like this:
/Resources/Plugins/AircraftSwitcher/win.xpl
/Resources/Plugins/AircraftSwitcher.ini

You may need the "Microsoft Visual C++ 2010 Redistributable Package (x86)". If the plugin does not work at first, you can download this package from here:
http://www.microsoft.com/en-us/download/details.aspx?id=5555
Run the installer and this should cause the plugin to work.

[Configuration]
Edit AircraftSwitcher.ini to use the paths of the aircraft you'd like to load.
The aircraft are loaded using these custom commands:
Dozer/AircraftSwitcher/load_aircraft_1 to _8

[Notes]
This plugin uses the XPLMSetUsersAircraft function from the SDK to load/reload an aircraft. It does not also reposition the aircraft on the nearest runway, unlike loading a new aircraft from the menu. So if you're flying at 350kts at 32,000ft in a 737 and switch to a glider, you'll find yourself in a glider doing 350kts at 32,000ft and very quickly losing a wing. Options to also reset to the runway, or to pass the speed as a ratio of Vne rather than an absolute value, could be added if people want it.

Generally, if XPLMSetUsersAircraft gets bad input, it will throw a useful error box (which often holds a hint as to why the input was bad) and give you the CirrusJet instead.

This plugin has been thrown together very quickly and NOT thoroughly tested. It seems to work on Windows XP and X-Plane 9.70 - I have no capacity to test any other combination of systems. Use it at your own risk!

[Contact information]
Please PM me with feedback via the x-plane.org forums.
Source code is on github here: https://github.com/JDeeth/AircraftSwitcher

[Changelog]
v0.12 2012/June/29
Recompiled with MSVC instead of MinGW to avoid needing all the MinGW .dll files.

v0.11 2012/June/26
Added mingw32-gcc .dll files to package

v0.10 2012/June/25
Initial version.

[Acknowledgements]
Thanks to:
Sandy Barbour and Ben Supnik for the X-Plane SDK
Philipp Muenzell for the PPL toolset
X-Plane.org for hosting the forums and file library
the X-Plane user community for providing inspiration and motivation for me to make cool stuff!

[Disclaimer and copyright]
Copyright (c) Jack Deeth <2012>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
