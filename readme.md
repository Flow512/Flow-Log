# FlowLog - Console Logging Library

FlowLog is a simple console logging library for C++ that provides easy-to-use functions for logging messages with different log levels and colors.

## Features

- Allocate console.
- Report log with coloured titles.
- Print Titles for log.
- Log with arguments.
- Log text align.
- Set custom colors for log messages.
- Console title manipulation.
- Clear console log with optional delay.
- Line spacer.

## Example

```cpp
#include "FlowLog.h"

void init()
{
	//Initialize console
	Console console("Debug win");


	//Print title
	console.Title(_CYAN, 1, "Im Title");


	//Print log type log in white
	console.LogEx(1, "Log1 true 0x%x", 0xdeadbeef);				console.Log(1, " <");		//Where it ends
	console.LogEx(0, "Log1 false 0x%x", 0xdeadbeef);			console.Log(1, " <");


	//Line spacer
	console.LineSpacer(3);


	//Print log type coloured log
	console.Log(_MAGENTA, 1, "Log2 true 0x%x", 0xdeadbeef);			console.Log(1, " <");
	console.Log(_MAGENTA, 0, "Log2 false 0x%x", 0xdeadbeef);		console.Log(1, " <");



	//Line spacer
	console.LineSpacer(3);



	//Print log type with title
	console.LogWT(INFO_, true, "Log3", "true 0x%x", 0xdeadbeef);		console.Log(1, " <");
	console.LogWT(INFO_, false, "Log3", "false 0x%x", 0xdeadbeef);		console.Log(1, " <");

	console::LineSpacer(3);


	//Print log type report
	console.Report(INFO_, 1, 1, "true 0x%x", 0xdeadbeef);			console.Log(1, " <");
	console.Report(WARNING_, 1, 1, "true 0x%x", 0xdeadbeef);		console.Log(1, " <");
	console.Report(ERROR_, 1, 1, "true 0x%x", 0xdeadbeef);			console.Log(1, " <");



	//Line spacer
	console.LineSpacer(3);



	//Print log type report
	console.Report(INFO_, false, 1, "false 0x%x", 0xdeadbeef);		console.Log(1, " <");
	console.Report(WARNING_, false, 1, "false 0x%x", 0xdeadbeef);		console.Log(1, " <");
	console.Report(ERROR_, false, 1, "false 0x%x", 0xdeadbeef);		console.Log(1, " <");



	//Line spacer
	console.LineSpacer(3);



	//set console title
	console.SetConTitle("Test");



	//set print colour
	console.SetColour(_GREEN);



	//Print log type 1
	console.Log(1, "Set console title to Test");



	//clear log 10sec
	console.ClearLog(10000);

	//Destroy Console
	console.Destroy();
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
		init();

	return NULL;
}

```

## output
![image](https://github.com/Flow512/Flow-Log/blob/main/img/image.png?raw=true)

## License
This project is licensed under the MIT License - see the LICENSE.md file for details.

## Contribution
Feel free to contribute or report issues.
