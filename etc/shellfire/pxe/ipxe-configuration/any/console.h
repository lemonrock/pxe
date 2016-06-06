// This file is part of pxe. It is subject to the licence terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/pxe/master/COPYRIGHT. No part of pxe, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2014-2015 The developers of pxe. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/pxe/master/COPYRIGHT.


// Enable serial console
//#define CONSOLE_SERIAL

// Enable encrypted syslog console
//#define CONSOLE_SYSLOGS
//#define LOG_LEVEL LOG_ALL

// Display DEBUG level log messages on the console
#undef LOG_LEVEL
#define LOG_LEVEL LOG_ALL
#undef CONSOLE_PCBIOS
#define CONSOLE_PCBIOS CONSOLE_USAGE_ALL
