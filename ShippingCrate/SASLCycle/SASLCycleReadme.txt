SASLCycle 2012-Jul-04

(c) J Deeth 2012

Put this in your root plugins folder, and it should restart SASL every time an aircraft is loaded (including on sim startup).

One second after aircraft load, it disables SASL. Two seconds after aircraft load, it enables SASL. If it can't find SASL it does nothing. It identifies SASL by plugin signature: "1-sim.sasl".

Source code is available on Github here: https://github.com/JDeeth/SASLCycle
It is a very simple plugin, using only straight SDK functions (no PPL or anything elaborate). Feel free to recompile on other platforms.

Licence:
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